//
// Original from https://github.com/LSPosed/NativeDetector/blob/master/app/src/main/jni/solist.cpp
//
#pragma once

#include <string>
#include "elf_util.h"

namespace SoList  {
  class SoInfo {
    public:
      #ifdef __LP64__
        inline static size_t solist_next_offset = 0x30;
        constexpr static size_t solist_realpath_offset = 0x1a8;
      #else
        inline static size_t solist_next_offset = 0xa4;
        constexpr static size_t solist_realpath_offset = 0x174;
      #endif

      inline static const char *(*get_realpath_sym)(SoInfo *) = NULL;
      inline static const char *(*get_soname_sym)(SoInfo *) = NULL;

      inline SoInfo *get_next() {
        return *(SoInfo **) ((uintptr_t) this + solist_next_offset);
      }

      inline const char *get_path() {
        if (get_realpath_sym) return get_realpath_sym(this);

        return ((std::string *) ((uintptr_t) this + solist_realpath_offset))->c_str();
      }

      inline const char *get_name() {
        if (get_soname_sym) return get_soname_sym(this);

        return ((std::string *) ((uintptr_t) this + solist_realpath_offset - sizeof(void *)))->c_str();
      }

      void nullify_name() {
        const char **name = (const char**)get_soname_sym(this);

        static const char *empty_string = "";
        *name = reinterpret_cast<const char *>(&empty_string);
      }

      void nullify_path() {
        const char **name = (const char**)get_realpath_sym(this);

        static const char *empty_string = "";
        *name = reinterpret_cast<const char *>(&empty_string);
      }
  };

  static SoInfo *solist = NULL;
  static SoInfo *somain = NULL;

  template<typename T>
  inline T *getStaticPointer(const SandHook::ElfImg &linker, const char *name) {
    auto *addr = reinterpret_cast<T **>(linker.getSymbAddress(name));

    return addr == NULL ? NULL : *addr;
  }

  static void NullifySoName(const char* target_name) {
    for (auto *iter = solist; iter; iter = iter->get_next()) {
      if (iter->get_name() && iter->get_path() && strstr(iter->get_path(), target_name)) {
        iter->nullify_path();
        LOGI("Cleared SOList entry for %s", target_name);
      }
    }

    for (auto *iter = somain; iter; iter = iter->get_next()) {
      if (iter->get_name() && iter->get_path() && strstr(iter->get_path(), target_name)) {
        iter->nullify_path();

        break;
      }
    }
  }

  static bool Initialize() {
    SandHook::ElfImg linker("/linker");

    /* INFO: Since Android 15, the symbol names for the linker have a suffix,
                this makes it impossible to hardcode the symbol names. To allow
                this to work on all versions, we need to iterate over the loaded
                symbols and find the correct ones.

        See #63 for more information.
    */

    std::string_view solist_sym_name = linker.findSymbolNameByPrefix("__dl__ZL6solist");
    if (solist_sym_name.empty()) return false;

    /* INFO: The size isn't a magic number, it's the size for the string: .llvm.7690929523238822858 */
    char llvm_sufix[25 + 1];

    if (solist_sym_name.length() != strlen("__dl__ZL6solist")) {
      strncpy(llvm_sufix, solist_sym_name.data() + strlen("__dl__ZL6solist"), sizeof(llvm_sufix));
    } else {
      llvm_sufix[0] = '\0';
    }

    solist = getStaticPointer<SoInfo>(linker, solist_sym_name.data());
    if (solist == NULL) return false;

    char somain_sym_name[sizeof("__dl__ZL6somain") + sizeof(llvm_sufix)];
    snprintf(somain_sym_name, sizeof(somain_sym_name), "__dl__ZL6somain%s", llvm_sufix);

    char vsdo_sym_name[sizeof("__dl__ZL4vdso") + sizeof(llvm_sufix)];
    snprintf(vsdo_sym_name, sizeof(vsdo_sym_name), "__dl__ZL4vdso%s", llvm_sufix);

    somain = getStaticPointer<SoInfo>(linker, somain_sym_name);
    if (somain == NULL) return false;

    auto vsdo = getStaticPointer<SoInfo>(linker, vsdo_sym_name);

    SoInfo::get_realpath_sym = reinterpret_cast<decltype(SoInfo::get_realpath_sym)>(linker.getSymbAddress("__dl__ZNK6soinfo12get_realpathEv"));
    SoInfo::get_soname_sym = reinterpret_cast<decltype(SoInfo::get_soname_sym)>(linker.getSymbAddress("__dl__ZNK6soinfo10get_sonameEv"));

    for (size_t i = 0; i < 1024 / sizeof(void *); i++) {
      auto *possible_next = *(void **) ((uintptr_t) solist + i * sizeof(void *));
      if (possible_next == somain || (vsdo != NULL && possible_next == vsdo)) {
        SoInfo::solist_next_offset = i * sizeof(void *);

        break;
      }
    }

    return (SoInfo::get_realpath_sym != NULL && SoInfo::get_soname_sym != NULL);
  }
}
