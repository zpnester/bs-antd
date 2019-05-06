open React;

type locale;

[@bs.module] external ar_EG: locale = "antd/lib/locale-provider/ar_EG";
[@bs.module] external bg_BG: locale = "antd/lib/locale-provider/bg_BG";
[@bs.module] external ca_ES: locale = "antd/lib/locale-provider/ca_ES";
[@bs.module] external cs_CZ: locale = "antd/lib/locale-provider/cs_CZ";
[@bs.module] external da_DK: locale = "antd/lib/locale-provider/da_DK";
[@bs.module] external de_DE: locale = "antd/lib/locale-provider/de_DE";
[@bs.module] external el_GR: locale = "antd/lib/locale-provider/el_GR";
[@bs.module] external en_GB: locale = "antd/lib/locale-provider/en_GB";
[@bs.module] external en_US: locale = "antd/lib/locale-provider/en_US";
[@bs.module] external es_ES: locale = "antd/lib/locale-provider/es_ES";
[@bs.module] external et_EE: locale = "antd/lib/locale-provider/et_EE";
[@bs.module] external fa_IR: locale = "antd/lib/locale-provider/fa_IR";
[@bs.module] external fi_FI: locale = "antd/lib/locale-provider/fi_FI";
[@bs.module] external fr_BE: locale = "antd/lib/locale-provider/fr_BE";
[@bs.module] external fr_FR: locale = "antd/lib/locale-provider/fr_FR";
[@bs.module] external he_IL: locale = "antd/lib/locale-provider/he_IL";
[@bs.module] external hi_IN: locale = "antd/lib/locale-provider/hi_IN";
[@bs.module] external hu_HU: locale = "antd/lib/locale-provider/hu_HU";
[@bs.module] external id_ID: locale = "antd/lib/locale-provider/id_ID";
[@bs.module] external is_IS: locale = "antd/lib/locale-provider/is_IS";
[@bs.module] external it_IT: locale = "antd/lib/locale-provider/it_IT";
[@bs.module] external ja_JP: locale = "antd/lib/locale-provider/ja_JP";
[@bs.module] external kn_IN: locale = "antd/lib/locale-provider/kn_IN";
[@bs.module] external ko_KR: locale = "antd/lib/locale-provider/ko_KR";
[@bs.module] external ku_IQ: locale = "antd/lib/locale-provider/ku_IQ";
[@bs.module] external mn_MN: locale = "antd/lib/locale-provider/mn_MN";
[@bs.module] external nb_NO: locale = "antd/lib/locale-provider/nb_NO";
[@bs.module] external ne_NP: locale = "antd/lib/locale-provider/ne-NP";
[@bs.module] external nl_BE: locale = "antd/lib/locale-provider/nl_BE";
[@bs.module] external nl_NL: locale = "antd/lib/locale-provider/nl_NL";
[@bs.module] external pl_PL: locale = "antd/lib/locale-provider/pl_PL";
[@bs.module] external pt_BR: locale = "antd/lib/locale-provider/pt_BR";
[@bs.module] external pt_PT: locale = "antd/lib/locale-provider/pt_PT";
[@bs.module] external ru_RU: locale = "antd/lib/locale-provider/ru_RU";
[@bs.module] external sk_SK: locale = "antd/lib/locale-provider/sk_SK";
[@bs.module] external sl_SI: locale = "antd/lib/locale-provider/sl_SI";
[@bs.module] external sr_RS: locale = "antd/lib/locale-provider/sr_RS";
[@bs.module] external sv_SE: locale = "antd/lib/locale-provider/sv_SE";
[@bs.module] external th_TH: locale = "antd/lib/locale-provider/th_TH";
[@bs.module] external tr_TR: locale = "antd/lib/locale-provider/tr_TR";
[@bs.module] external uk_UA: locale = "antd/lib/locale-provider/uk_UA";
[@bs.module] external vi_VN: locale = "antd/lib/locale-provider/vi_VN";
[@bs.module] external zh_CN: locale = "antd/lib/locale-provider/zh_CN";
[@bs.module] external zh_TW: locale = "antd/lib/locale-provider/zh_TW";

[@react.component] [@bs.module]
external make: (~locale: locale=?, ~children: element=?, unit) => element =
  "antd/lib/locale-provider";