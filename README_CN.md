[English version](https://github.com/PerformanC/ReZygisk/blob/main/README.md)

# ReZygisk

ReZygisk 从 ZygiskNext 分叉而来，是一个 Zygisk 的独立实现，为 KernelSU、Magisk（除内置外）和 APatch（测试阶段）提供 Zygisk API 支持。

其目的是使用 C 语言现代化的重写代码（从 C++ 和 Rust），从而更高效、更快速地实现 Zygisk API，并采用更宽松的开源许可证。

> [!NOTE]
> 此模块还在测试阶段；确保仅安装发布版本的 .zip。
>
> 虽然您可以从 [Actions](https://github.com/PerformanC/ReZygisk/actions) 页面安装 .zip，但是这是您的个人决定，因为您的设备可能会进入 Bootloop。

## 为什么？

最新版本的 ZygiskNext 是闭源的，仅由其开发人员们保留全部代码。这不仅阻止了我们对项目的贡献，而且也无法审计代码，这是一个重大的安全问题，因为 ZygiskNext 是一个以超级用户（root）权限运行的模块，可以访问整个系统。

ZygiskNext 的开发者们在安卓社区享有盛誉，也备受信任。但是，这不意味着代码没有恶意或者漏洞。我们（PerformanC）理解他们有理由不开源代码，但我们相信开源是更好的选择。

## 优点

- 开源（永远）
- 更好的独立隐藏

## 依赖

| 工具          | 简介                               |
|---------------|------------------------------------|
| `rustc`       | The Rust compiler                  |
| `Android NDK` | Native Development Kit for Android |

### Rust 依赖

| 依赖             | 简介                                                  |
|------------------|-------------------------------------------------------|
| `android_logger` | Logger for Android platform                           |
| `anyhow`         | Error handling library                                |
| `bitflags`       | Macro to generate structures for bitwise operations   |
| `const_format`   | Compile-time string formatting                        |
| `futures`        | Abstractions for asynchronous programming             |
| `konst`          | Compile-time constant evaluation                      |
| `lazy_static`    | Macro for declaring lazily evaluated static variables |
| `libc`           | FFI bindings to native C libraries                    |
| `log`            | Logging facade                                        |
| `memfd`          | Memory file descriptor utilities                      |
| `num_enum`       | Derive macros to convert between numbers and enums    |
| `passfd`         | Passing file descriptors over Unix sockets            |
| `proc-maps`      | Parse and analyze process memory maps                 |

### C++ 依赖

| 依赖    | 简介                        |
|---------|-----------------------------|
| `lsplt` | Simple PLT Hook for Android |

## 用法

目前正在编写中。（敬请期待）

## 安装

目前没有可用的发布版本。（敬请期待）

## 翻译

目前，我们还没有集成翻译平台，但您可以向 [add/webui](https://github.com/PerformanC/ReZygisk/tree/add/webui) 分支贡献。请不要忘记在 [TRANSLATOR.md](https://github.com/PerformanC/ReZygisk/blob/add/webui/TRANSLATOR.md) 中添加您的 GitHub 简介，以便人们可以看到您的贡献。

## 支持

如果您有任何与 ReZygisk 或者其他 PerformanC 项目相关的问题，请随时加入以下任意群组：

- Discord 社区: [PerformanC](https://discord.gg/uPveNfTuCJ)
- ReZygisk Telegram 群组: [@rezygiskchat](https://t.me/rezygiskchat)
- PerformanC Telegram 群组: [@performancorg](https://t.me/performancorg)

## 贡献

你必须遵守 PerformanC 的 [贡献指南](https://github.com/PerformanC/contributing) ，才能为 ReZygisk 做出贡献。请遵循其安全政策、行为准则和语法标准。

## 开源许可证

ReZygisk 的旧的 ZygiskNext 部分采用 GPL 许可证，但是重写的代码将采用 BSD 2-Clause 许可证。您可以在 [Open Source Initiative](https://opensource.org/licenses/BSD-2-Clause) 上了解更多信息。
