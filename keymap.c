#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

extern uint8_t is_master;

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _HIGHER,
    _ADJUST,
    _NUMPAD,
};

// Tap Dance definitions
enum {
    TD_INTE,
    TD_EXCLA,
    TD_NN,
    TD_PS,
    TD_LEFT_K,
    TD_RIGHT_K,
    TD_PSCREN,
    TD_TILDE,
    TD_DOTS,
    TD_MINT,
    TD_BIGT,
    TD_SIM1,
    TD_SIM2,
    TD_SIM4,
    TD_SIM5,
    TD_SIM8,
    TD_SIM9,
    TD_SIM10,
    TD_SIM12,
};

// Creamos nuestros keycodes personalizados
enum custom_keycodes {
  RECORTE = SAFE_RANGE,
  MAX,
  MIN,
  DESK,
  CLOSE, 
  WT,
  COPY,
  PASTE,
};

void ts_action_SIMB(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_LALT("227"));
    } else if (state->count == 2) {
        SEND_STRING(SS_LALT("251"));
    }
    reset_tap_dance(state);
}
void ts_action_LEFT_PAR_BRA(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_LSFT(SS_TAP(X_8)));
    } else if (state->count == 2) {
        SEND_STRING(SS_TAP(X_QUOTE));
    } else {
        SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)));
    }
    reset_tap_dance(state);
}
void ts_action_RIGHT_PAR_BRA(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_LSFT(SS_TAP(X_9)));
    } else if (state->count == 2) {
        SEND_STRING(SS_TAP(X_NUHS));
    } else {
        SEND_STRING(SS_LSFT(SS_TAP(X_NUHS)));
    }
    reset_tap_dance(state);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_INTE]    = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_UNDS), // ¿?
    [TD_EXCLA]    = ACTION_TAP_DANCE_DOUBLE(S(KC_EQUAL), S(KC_1)), // ¡!
    [TD_PSCREN]   = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_PSCR), // ´ Print_screen
    [TD_NN]       = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_SCLN), // n ñ
    [TD_TILDE]    = ACTION_TAP_DANCE_DOUBLE(S(KC_2), KC_MINS), // " '
    [TD_DOTS]     = ACTION_TAP_DANCE_DOUBLE(S(KC_DOT), S(KC_COMM)), // : ;
    [TD_MINT]     = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_NUBS), // , <
    [TD_BIGT]     = ACTION_TAP_DANCE_DOUBLE(KC_DOT, S(KC_NUBS)), // . >
    [TD_SIM1]     = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_PSLS), // * /
    [TD_SIM2]     = ACTION_TAP_DANCE_DOUBLE(S(KC_6), KC_GRV), // & |
    [TD_SIM4]     = ACTION_TAP_DANCE_DOUBLE(KC_PERC, RALT(KC_QUOT)), // % ^
    [TD_SIM5]     = ACTION_TAP_DANCE_DOUBLE(S(KC_SLSH), RALT(KC_RBRC)), // _  ~
    
    [TD_SIM8]     = ACTION_TAP_DANCE_DOUBLE(S(KC_0),  RALT(KC_Q)), // = @
    [TD_SIM9]     = ACTION_TAP_DANCE_DOUBLE(S(KC_3), S(KC_4)), // # $
    [TD_SIM10]    = ACTION_TAP_DANCE_DOUBLE(RALT(KC_NUHS), RALT(KC_MINS)), // ` BACKSLASH
    [TD_SIM12]    = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PMNS), // + -

    
    [TD_LEFT_K]   = ACTION_TAP_DANCE_FN(ts_action_LEFT_PAR_BRA), // ( { [ 
    [TD_RIGHT_K]  = ACTION_TAP_DANCE_FN(ts_action_RIGHT_PAR_BRA), // ) } ]
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,---------------------------------------------------.                    ,------------------------------------------------------.
     * |DEL             |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ´ PScren         |
     * |----------------+------+------+------+------+------|                    |------+------+------+------+------+-------------------|
     * |  BMayus        |  '"  |  ,<  |  .>  |   P  |   Y  |                    |   F  |   G  |   C  |   H  |   L  |  RShift / BMayus  |
     * |----------------+------+------+------+------+------|                    |------+------+------+------+------+-------------------|
     * |TAB  LSHIFT      |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   R  |   T  |  NÑ  |   S  |  BackSP           |
     * |----------------+------+------+------+------+------|  ({[  |    |  ]})  |------+------+------+------+------+-------------------|
     * |LCTRL           |  :;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |  RCTRL            |
     * `---------------------------------------------------/       /     \      \------------------------------------------------------'
     *                             | LAlt | LGUI |LOWER Space  | /ESC  / \PRNT AVANZADO \  |HIGHER Enter| ESC  |ADJUST|
     *                             |      |      |      |/       /         \      \ |      |      |      |
     *                             `----------------------------'           '------''--------------------'
     */


    [_QWERTY] = LAYOUT( \
    KC_DEL,            KC_1,           KC_2,           KC_3,           KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,         KC_0,    TD(TD_PSCREN), \
    KC_CAPS,           TD(TD_TILDE),   TD(TD_MINT),    TD(TD_BIGT),    KC_P,    KC_Y,                                  KC_F,    KC_G,    KC_C,    KC_H,         KC_L,    RSFT_T(KC_CAPS), \
    LSFT_T(KC_TAB),    KC_A,           KC_O,           KC_E, LT(_NUMPAD,KC_U),     KC_I,                                  KC_D,    KC_R,    KC_T,    TD(TD_NN),    KC_S,    KC_BSPC, \
    KC_LCTRL,          TD(TD_DOTS),    KC_Q,           KC_J,           KC_K,    KC_X, TD(TD_LEFT_K),   TD(TD_RIGHT_K), KC_B,    KC_M,    KC_W,    KC_V,         KC_Z,    KC_RCTRL, \
                                                   KC_LALT, KC_LGUI, LT(_LOWER,KC_SPC), KC_ESC,                       RECORTE, LT(_HIGHER,KC_ENT), KC_ESC, KC_RGUI \
                                                   ),
    /* LOWER
     * ,---------------------------------------------------.                    ,------------------------------------------------------.
     * |DEL             |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |  <<  | PLAY |  >>  |  BackSP           |
     * |----------------+------+------+------+------+------|                    |------+------+------+------+------+-------------------|
     * |LShift / BMayus |  F6  |  F7  |  F8  |  F9  | F10  |                    |      |      |      |      |      |  VOL+             |
     * |----------------+------+------+------+------+------|                    |------+------+------+------+------+-------------------|
     * |TAB             | F11  | F12  | C    | P    | F13  |-------.    ,-------|  *\/ |  ¿?  |  &|  |  %^  |  _~  |  Mute             |
     * |----------------+------+------+------+------+------|  ({[  |    |  ]})  |------+------+------+------+------+-------------------|
     * |LCTRL           |      |      |      |      |      |-------|    |-------|CUENTA1|CUENTA2|CUENTA3|CUENTA4    |      |  VOL-             |
     * `---------------------------------------------------/       /     \      \------------------------------------------------------'
     *                             | LAlt | LGUI |LOWER | /Space  /       \Enter \  |HIGHER| ESC  | RGUI |
     *                             |      |      |      |/       /         \      \ |      |      |      |
     *                             `----------------------------'           '------''--------------------'
     */

    [_LOWER] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                     XXXXXXX,     XXXXXXX,     KC_MPRV,     KC_MPLY,     KC_MNXT,     KC_BSPC,\
    _______, KC_F6,   KC_F7,   KC_LALT,   KC_TAB,   KC_F10,                                    XXXXXXX,    XXXXXXX,     XXXXXXX,     XXXXXXX, XXXXXXX,     KC_AUDIO_VOL_UP, \
    _______, KC_F11,  KC_F12,  COPY,  PASTE,  KC_F13,                                       TD(TD_SIM1), TD(TD_INTE), TD(TD_SIM2), TD(TD_SIM4), TD(TD_SIM5), KC_AUDIO_MUTE, \
    _______, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,                 XXXXXXX, XXXXXXX,       XXXXXXX,        XXXXXXX,       XXXXXXX,        XXXXXXX,     KC_AUDIO_VOL_DOWN, \
                               _______, _______, _______, _______,                          _______, _______, _______, _______\
    ),

    /* HIGHER
     * ,---------------------------------------------------.                    ,------------------------------------------------------.
     * |DEL             |      |      |      |      |      |                    |      |  UP  |      |      |      |  BackSP           |
    
     * |LShift / BMayus | HOME |PagUP |PScren|      |      |                    | LEFT | DOWN |RIGHT |   7  |  8   |  9                |
     * |----------------+------+------+------+------+------|                    |------+------+------+------+------+-------------------|
     * |TAB             |  =@  |  #$  |  `\  |  ¡!  |  +-  |-------.    ,-------|   %  |   /  |  *   |   4  |  5   |  6                |
     * |----------------+------+------+------+------+------|  ({[  |    |  ]})  |------+------+------+------+------+-------------------|
     * |LCTRL           |  DEL | SUPR |  END |PAG UP|      |-------|    |-------|   -  |   +  |      |   1  |  2   |  3                |
     * `---------------------------------------------------/       /     \      \------------------------------------------------------'
     *                             | LAlt | LGUI |LOWER | /Space  /       \Enter \  |   0  |   .  |   =  |
     *                             |      |      |      |/       /         \      \ |      |      |      |
     *                             `----------------------------'           '------''--------------------'
     */

    [_HIGHER] = LAYOUT( \
    XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX,        XXXXXXX,       XXXXXXX,                             XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, \
    _______, KC_HOME,       KC_PGUP,       KC_PSCR,        XXXXXXX,         XXXXXXX,                           DESK,    MAX,       MIN,     CLOSE,   WT,      XXXXXXX, \
    _______, TD(TD_SIM8),   TD(TD_SIM9),   TD(TD_SIM10),   TD(TD_EXCLA),  TD(TD_SIM12),                        XXXXXXX,  KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT,    _______, \
    _______, KC_DEL,        KC_DEL,        KC_PGUP,         KC_PGDN,       KC_LCTRL,       XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX, \
                                                            _______, _______, XXXXXXX,  XXXXXXX,      XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX \
    ),

    /* ADJUST
     * ,---------------------------------------------------.                    ,------------------------------------------------------.
     * |DEL             |      |      |      |      |      |                    |      |      |      |      |      |  BackSP           |
     * |----------------+------+------+------+------+------|                    |------+------+------+------+------+-------------------|
     * |LShift / BMayus |      |      |      |      | TOG  |                    |      |      |      |      |      |                   |
     * |----------------+------+------+------+------+------|                    |------+------+------+------+------+-------------------|
     * |TAB             |  HUI |  SAI |  VAI |  SPI | MOD  |-------.    ,-------|      |      |      |      |      |  RESET            |
     * |----------------+------+------+------+------+------|  ({[  |    |  ]})  |------+------+------+------+------+-------------------|
     * |LCTRL           |  HUD |  SAD |  VAD |  SPD |      |-------|    |-------|      |      |      |      |      |                   |
     * `---------------------------------------------------/       /     \      \------------------------------------------------------'
     *                             | LAlt | LGUI |LOWER | /Space  /       \Enter \  |HIGHER| ESC  | RGUI |
     *                             |      |      |      |/       /         \      \ |      |      |      |
     *                             `----------------------------'           '------''--------------------'
     */

    [_ADJUST] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MODE_PLAIN, RGB_TOG,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, \
    XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    [_NUMPAD] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,KC_KP_7,KC_KP_8,KC_KP_9, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,KC_KP_4,KC_KP_5,KC_KP_6, XXXXXXX, _______, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_1,KC_KP_2,KC_KP_3, XXXXXXX, XXXXXXX,\
                                XXXXXXX, XXXXXXX, KC_SPC, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX \
    )
    };

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _HIGHER, _ADJUST);
}

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return true;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        #ifdef OLED_ENABLE
            set_keylog(keycode, record);
        #endif
    }
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


    }
    return true;
}
