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
    TD_CORCHETES_K,
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
  BUSCADOR,
  MAYUS,
  MAX,
  MIN,
  DESK,
  CLOSE,
  WT,
  COPY,
  PASTE,
  NVIM_VB,
  NVIM_EMMET,
  TERM_DUPLI,
  TERM_CLOSE,
  TERM_TAB,
  WIN_ZOOM,

};

void ts_action_SIMB(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_LALT("227"));
    } else if (state->count == 2) {
        SEND_STRING(SS_LALT("251"));
    }
    reset_tap_dance(state);
}
void ts_action_LEFT_PAR_BRA(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_LSFT(SS_TAP(X_8)));
    } else if (state->count == 2) {
        SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)));
    }
    reset_tap_dance(state);
}
void ts_action_RIGHT_PAR_BRA(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_LSFT(SS_TAP(X_9)));
    } else if (state->count == 2) {
        SEND_STRING(SS_LSFT(SS_TAP(X_NUHS)));
    }
    reset_tap_dance(state);
}

void ts_action_corchetes(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(SS_TAP(X_QUOTE));
    } else if (state->count == 2) {
        SEND_STRING(SS_TAP(X_NUHS));
    }
    reset_tap_dance(state);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_INTE]    = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_UNDS), // ¿?
    [TD_EXCLA]    = ACTION_TAP_DANCE_DOUBLE(S(KC_EQUAL), S(KC_1)), // ¡!
    [TD_PSCREN]   = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_PSCR), // ´ Print_screen
    [TD_NN]       = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_SCLN), // n ñ
    [TD_TILDE]    = ACTION_TAP_DANCE_DOUBLE(S(KC_2), KC_MINS), // " '
    [TD_DOTS]     = ACTION_TAP_DANCE_DOUBLE(S(KC_DOT), S(KC_COMM)), // : ;
    [TD_MINT]     = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_NUBS), // , <
    [TD_BIGT]     = ACTION_TAP_DANCE_DOUBLE(KC_DOT, S(KC_NUBS)), // . >
    [TD_SIM1]     = ACTION_TAP_DANCE_DOUBLE(KC_PSLS, KC_PAST), // / *
    [TD_SIM2]     = ACTION_TAP_DANCE_DOUBLE(S(KC_6), KC_GRV), // & |
    [TD_SIM4]     = ACTION_TAP_DANCE_DOUBLE(KC_PERC, S(KC_3)), // % #
    [TD_SIM5]     = ACTION_TAP_DANCE_DOUBLE(S(KC_SLSH), RALT(KC_RBRC)), // _  ~

    [TD_SIM8]     = ACTION_TAP_DANCE_DOUBLE(S(KC_0),  RALT(KC_Q)), // = @
    [TD_SIM9]     = ACTION_TAP_DANCE_DOUBLE(RALT(KC_QUOT), S(KC_4)), //^ $
    [TD_SIM10]    = ACTION_TAP_DANCE_DOUBLE(RALT(KC_NUHS), RALT(KC_MINS)), // ` BACKSLASH
    [TD_SIM12]    = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PMNS), // + -

    [TD_LEFT_K]   = ACTION_TAP_DANCE_FN(ts_action_LEFT_PAR_BRA), // ( { [ 
    [TD_RIGHT_K]  = ACTION_TAP_DANCE_FN(ts_action_RIGHT_PAR_BRA), // ) } ]
    [TD_CORCHETES_K]  = ACTION_TAP_DANCE_FN(ts_action_corchetes), // {}
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,---------------------------------------------------.                    ,------------------------------------------------------.
     * |DEL             |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ´ PScren         |
     * |----------------+------+------+------+------+------|                    |------+------+------+------+------+-------------------|
     * |  BMayus        |  '"  |  ,<  |  .>  |   P  |   Y  |                    |   F  |   G  |   C  |   H  |   L  |  RShift / BMayus  |
     * |----------------+------+------+------+------+------|                    |------+------+------+------+------+-------------------|
     * |TAB  LSHIFT      |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   R  |   T  |  NÑ  |   S  |  BackSP           |
     * |----------------+------+------+------+------+------|  ([{  |    |  }])  |------+------+------+------+------+-------------------|
     * |LCTRL           |  :;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |  RCTRL            |
     * `---------------------------------------------------/       /     \      \------------------------------------------------------'
     *                             | LAlt | LGUI |LOWER Space  | /ESC  / \PRNT AVANZADO \  |HIGHER Enter| ESC  |ADJUST|
     *                             |      |      |      |/       /         \      \ |      |      |      |
     *                             `----------------------------'           '------''--------------------'
     */


    [_QWERTY] = LAYOUT( \
    KC_DEL,         KC_1,           KC_2,           KC_3,           KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,         KC_0,   RECORTE, \
    MAYUS,          TD(TD_TILDE),   TD(TD_MINT),    TD(TD_BIGT),    KC_P,    KC_Y,                                  KC_F,    KC_G,    KC_C,    KC_H,         KC_L,    LSFT_T(KC_LBRC), \
    LSFT_T(KC_TAB), KC_A,           KC_O,           KC_E, LT(_NUMPAD,KC_U),  KC_I,                                  KC_D,    KC_R,    KC_T,    TD(TD_NN),    KC_S,    KC_BSPC, \
    KC_LCTL,       TD(TD_DOTS),    KC_Q,           KC_J,           KC_K,    KC_X, TD(TD_LEFT_K),   TD(TD_RIGHT_K), KC_B,    KC_M,    KC_W,    KC_V,         KC_Z,    KC_RGUI, \
                                          KC_LALT, NVIM_EMMET, LT(_LOWER,KC_SPC), LALT_T(KC_ESC),   LCTL_T(KC_COMM), LT(_HIGHER,KC_ENT), TD(TD_CORCHETES_K), NVIM_VB \
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
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                     XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_MPLY,     KC_MNXT,     KC_BSPC,\
    _______, KC_F6,   KC_F7,   KC_LALT,   KC_TAB,   KC_F10,                                 XXXXXXX,    TERM_TAB, TERM_DUPLI,    TERM_CLOSE, XXXXXXX,     KC_AUDIO_VOL_UP, \
    _______, KC_PGDN, KC_PGUP, COPY,  PASTE,  KC_F13,                                       TD(TD_SIM1),TD(TD_INTE),TD(TD_SIM2),TD(TD_SIM4), TD(TD_SIM5), KC_AUDIO_MUTE, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                 XXXXXXX,XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,XXXXXXX, KC_AUDIO_VOL_DOWN, \
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
    _______, KC_HOME,       KC_PGUP,       KC_PSCR,        XXXXXXX,         XXXXXXX,                           DESK,    MAX,       MIN,     CLOSE,   WT,      WIN_ZOOM, \
    _______, TD(TD_SIM8),   TD(TD_SIM9),   TD(TD_SIM10),   TD(TD_EXCLA),  TD(TD_SIM12),                        BUSCADOR,KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT,    _______, \
    _______, KC_DEL,        KC_DEL,        KC_PGUP,         KC_PGDN,       KC_LCTL,       XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,     XXXXXXX, \
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
    XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_REBOOT, \
    XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    [_NUMPAD] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,                   XXXXXXX,KC_7,KC_8,KC_9, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_0,KC_4,KC_5,KC_6, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, KC_1,KC_2,KC_3, XXXXXXX, XXXXXXX,\
                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX \
    ),

    };

#include "oled.c"
#include "macros.c"
