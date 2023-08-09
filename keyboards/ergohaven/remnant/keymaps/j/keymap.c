#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _BOTH 1
#define _GAMING1 2
#define _GAMING2 3
#define _GAMING3 4

#define L_BOTH   MO(_BOTH)
#define LT_GAM   TG(_GAMING1)
#define L_GAM2   MO(_GAMING2)
#define L_GAM3   MO(_GAMING3)

#define M_LEFT   KC_MS_BTN1
#define M_RIGHT  KC_MS_BTN2
#define RGB_MF   RGB_MODE_FORWARD

enum custom_keycodes {
    MYKEY = SAFE_RANGE,
};

// Toggle KC_P5 key
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MYKEY:
        if (record->event.pressed) {
            static bool is_toggled;
            is_toggled ^= 1;
            if (is_toggled) {
                register_code(KC_P5);
            } else {
                unregister_code(KC_P5);
            }
        }
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_5x6(
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS,
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC,
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_BSLS,
                       KC_NO,   KC_NO,                                               KC_EQL,  KC_RBRC,
                                L_BOTH,  KC_SPC,  KC_LSFT,         KC_RGUI, KC_ENT,  KC_RALT
  ),
  [_BOTH] = LAYOUT_5x6(
     LT_GAM,  KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,           KC_NO,   M_LEFT,  KC_MS_U, M_RIGHT,  KC_NO,   KC_NO,
     RGB_MF,  KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT,KC_NO,           KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R,  KC_BSPC, KC_NO,
     RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_WH_U, KC_NO,    KC_NO,   QK_BOOT,
                       RGB_VAD, RGB_VAI,                                             KC_WH_D, KC_NO,
                                KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO
  ),
  [_GAMING1] = LAYOUT_5x6(
     KC_NO,   KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
     KC_ESC,  KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,            KC_NO,   KC_MPLY, KC_MNXT, KC_MPRV,  KC_MSTP, KC_NO,
     KC_TAB,  KC_G,    KC_A,    KC_S,    KC_D,    KC_F,            KC_NO,   KC_NO,   MYKEY,   KC_NO,    KC_NO,   KC_NO,
     KC_LCTL, KC_LALT, KC_X,    KC_C,    KC_V,    KC_B,            KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
                       KC_N,    KC_H,                                                KC_NO,   KC_NO,
                                L_GAM2,  KC_SPC,  KC_LSFT,         KC_NO,   KC_NO,   KC_NO
  ),
  [_GAMING2] = LAYOUT_5x6(
     KC_NO,   KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
     KC_NO,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,            KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
     KC_NO,   L_GAM3,  KC_J,    KC_K,    KC_L,    KC_SCLN,         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
     KC_LCTL, KC_LALT, KC_M,    KC_COMM, KC_DOT,  KC_SLSH,         KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
                       KC_P0,   KC_Z,                                                KC_NO,   KC_NO,
                                KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   LT_GAM
  ),
  [_GAMING3] = LAYOUT_5x6(
     KC_NO,   KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
     KC_NO,   KC_NO,   KC_P1,   KC_P2,   KC_P3,   KC_P4,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
     KC_NO,   KC_NO,   KC_INS,  KC_END,  KC_HOME, KC_DEL,          KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
     KC_NO,   KC_NO,   KC_P5,   KC_P6,   KC_P7,   KC_P8,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
                       KC_NO,   KC_NO,                                               KC_NO,   KC_NO,
                                KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO
  )
};

/*
      [_QWERTY] = LAYOUT_5x6(
         KC_GRV,  KC_1, KC_2, KC_3, KC_4, KC_5,                         KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS,
         KC_ESC,  KC_Q, KC_W, KC_E, KC_R, KC_T,                         KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_EQL,
         KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G,                         KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
         KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                         KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLASH,
                        KC_LGUI, KC_BSPC,                                            KC_LBRC, KC_RBRC,
                                   KC_LCTL, LOWER, KC_SPC,              KC_ENT, RAISE, KC_RALT
      ),
      [10] = LAYOUT_5x6(
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
                       KC_NO,   KC_NO,                                               KC_NO,   KC_NO,
                                KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO
      )
*/
