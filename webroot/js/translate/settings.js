export function translateSettingsPage(new_translations) {
  document.getElementById('panel_settings_header').innerHTML = new_translations.page.settings.header

  /* INFO: Change font option */
  document.getElementById('sys_font_option_title').innerHTML = new_translations.page.settings.font.header
  document.getElementById('sys_font_option_desc').innerHTML = new_translations.page.settings.font.description
  
  /* INFO: Change font option */
  document.getElementById('sys_theme_option_title').innerHTML = new_translations.page.settings.theme.header
  document.getElementById('sys_theme_option_desc').innerHTML = new_translations.page.settings.theme.description

  /* INFO: Change font option */
  document.getElementById('sys_lang_option_title').innerHTML = new_translations.page.settings.language.header
  document.getElementById('sys_lang_option_desc').innerHTML = new_translations.page.settings.language.description

  /* INFO: Change font option */
  document.getElementById('sys_errorh_title').innerHTML = new_translations.page.settings.logs.header
  document.getElementById('sys_errorh_desc').innerHTML = new_translations.page.settings.logs.description
}