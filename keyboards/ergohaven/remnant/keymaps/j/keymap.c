#include QMK_KEYBOARD_H

#define _DVORAK 0
#define _BOTH 1

#define APP_A   LSG(KC_A)
#define APP_S   LSG(KC_S)
#define APP_D   LSG(KC_D)
#define APP_F   LSG(KC_F)
#define APP_X   LSG(KC_X)
#define APP_C   LSG(KC_C)
#define APP_V   LSG(KC_V)

#define L_SHDV   MO(_SDVORAK)
#define L_BOTH   MO(_BOTH)
#define L_MMOV   MO(_MOUSE_MOV)
#define M_LEFT   KC_MS_BTN1
#define M_RIGHT  KC_MS_BTN2
#define RGB_MF   RGB_MODE_FORWARD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_5x6(
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                       KC_NO,   KC_NO,                                               KC_EQL,  KC_RBRC,
                                L_BOTH,  KC_SPC,  KC_LSFT,         KC_RGUI, KC_ENT,  KC_RALT
  ),
  [_BOTH] = LAYOUT_5x6(
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,           KC_NO,   M_LEFT,  KC_MS_U, M_RIGHT,  KC_NO,   KC_NO,
     RGB_MF,  KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT,KC_NO,           KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R,  KC_BSPC, KC_NO,
     RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_NO,   KC_NO,           KC_NO,   KC_NO,   KC_WH_U, KC_NO,    KC_NO,   QK_BOOT,
                       RGB_VAD, RGB_VAI,                                             KC_WH_D, KC_NO,
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
      [_DVORAK] = LAYOUT_5x6(
         KC_DLR,  KC_AMPR, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN,         KC_EQL,  KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM,
         KC_ESC,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,            KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
         KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,            KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
         KC_LCTL, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,            KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_NO,
                           KC_LGUI, KC_BSLS,                                             KC_AT,   KC_HASH,
                                    L_BOTH,  KC_SPC,  L_SHDV,          KC_RALT, KC_ENT,  KC_NO
      ),
      [_SDVORAK] = LAYOUT_5x6(
         KC_TILD, KC_PERC, KC_7,    KC_5,    KC_3,    KC_1,            KC_9,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,
         KC_NO,   KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,            KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
         KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,            KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
         KC_LCTL, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,            KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_NO,
                           KC_LGUI, KC_BSLS,                                             KC_CIRC, KC_GRV,
                                    KC_NO,   KC_SPC,  KC_NO,           KC_NO,   KC_ENT,  KC_NO
      ),
      [10] = LAYOUT_5x6(
         KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
         KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
         KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
         KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,            KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
                         KC_NO, KC_NO,                                              KC_NO, KC_NO,
                                        KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO
      )
*/
