    switch (keycode) {
      case LT(0,KC_N):
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_SCLN); // Intercept hold function to send Ñ
                return false;
            }
            return true; // Return true for normal processing of tap keycode

      case WT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_T));
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
          // Comprueba si la iluminación está apagada antes de alternar
          if (!rgblight_is_enabled()) {
              rgblight_enable(); // Enciende la iluminación si está apagada
              rgblight_increase_hue(); // Opcional: ajusta el tono al encender
          } else {
              rgblight_disable(); // Apaga la iluminación si está encendida
          }
          SEND_STRING(SS_TAP(X_CAPS)); // Envia la señal de bloqueo de mayúsculas
      }
      return true;
      break;
    }
    return true;
}
