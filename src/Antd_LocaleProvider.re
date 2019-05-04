

open React;

[@react.component] [@bs.module]
external make: (
   ~locale: Antd_Locale.t=?,
   ~children: element=?,
    unit
) => element = "antd/lib/locale-provider"