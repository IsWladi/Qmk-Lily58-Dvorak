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
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_C));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case PASTE: //Macro en la que dejamos pulsadas las teclas
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_V));
      } else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case NVIM_VB: //nvim modo visual bloque
      if (record->event.pressed){
        // Cuando se pulsa la tecla con el keycode seleccionado
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_V));
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

      case BUSCADOR:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_SPC));
        return true;
      }else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case NVIM_EMMET:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_Y));
        clear_keyboard();
        SEND_STRING(SS_TAP(X_COMM));

        return true;
      }else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case TERM_DUPLI: // ctrl shift d duplicar terminarl(abrir nueva pestaña)
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_D));

        return true;
      }else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case TERM_CLOSE: // ctrl shift w cerrar terminal(cerrar pestaña actual o la terminar si solo hay una)
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_TAP(X_W));

        return true;
      }else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;

      case TERM_TAB: // ctrl tab cambiarse de terminal
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB));

        return true;
      }else {
        // Cuando la tecla es liberada
        clear_keyboard();
      }
      break;
    }
    return true;
}
