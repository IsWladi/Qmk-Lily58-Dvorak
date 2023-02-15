    switch (keycode) {
      case LT(0,KC_N):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_SCLN); // Intercept hold function to send Ñ
                return false;
            }
            return true; // Return true for normal processing of tap keycode

      case WT:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r"));
        _delay_ms(500);
        SEND_STRING("wt" SS_TAP(X_ENTER));
        return true;
      }
      break;          

      case RECORTE: //Macro en la que dejamos pulsadas las teclas
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) SS_DOWN(X_S));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case COPY: //Macro en la que dejamos pulsadas las teclas
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_C));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case PASTE: //Macro en la que dejamos pulsadas las teclas
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_DOWN(X_LCTRL) SS_DOWN(X_V));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case CLOSE: //Macro en la que dejamos pulsadas las teclas
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_F4));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case MAX: //Macro en la que dejamos pulsadas las teclas
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_UP));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;
     
      case MIN: //Macro en la que dejamos pulsadas las teclas
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_DOWN));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case DESK: //Macro en la que dejamos pulsadas las teclas
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_D));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case MAYUS: 
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_CAPS));
        rgblight_toggle();
        rgblight_increase_hue();
        rgblight_decrease_hue();
        return true;
      }
      break;

      case BUSCADOR:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_SPC));
        return true;
      }else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case CHROME:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_NAVEGAR)) {
          layer_off(_NAVEGAR);
          SEND_STRING(SS_TAP(X_NUMLOCK));
        } else {
          layer_on(_NAVEGAR);
          SEND_STRING(SS_TAP(X_NUMLOCK));
        }
        return true;
      }
      break;
    }
    return true;
}
