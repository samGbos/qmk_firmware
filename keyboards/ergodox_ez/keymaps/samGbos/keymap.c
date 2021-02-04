#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    LINUX, // default layer
    SYMB, // symbols
    NUM, // numbers
    FUNC,  // func keys
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

// Stuff to try:
// Semi-colon to toggle numbers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |   6  |           |   5  |   6  |   7  |   8  |   9  |   0  |  Backsp|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   Y  |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  Enter |
 * |--------+------+------+------+------+------| Equal|           | Minus|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | FUNC |      |      | Alt  | Cmd  |                                       | Left | Down |  Up  | Right|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F4   | F3   |       | F7   | F8   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | F2   |       | F6   |        |      |
 *                                 | Space| Lead |------|       |------|  '     | SYMB |
 *                                 |      |      | F1   |       | F5   |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,   KC_1,   KC_2,  KC_3,          KC_4,           KC_5,  KC_6,          KC_5,      KC_6,  KC_7,     KC_8,     KC_9,    KC_0,      KC_BSPACE,
  KC_TAB,   KC_Q,   KC_W,  KC_E,          KC_R,           KC_T,  KC_Y,          KC_TRNS,   KC_Y,  KC_U,     KC_I,     KC_O,    KC_P,      KC_BSLS,
  KC_LCTRL, KC_A,   KC_S,  KC_D,          KC_F,           KC_G,                            KC_H,  KC_J,     KC_K,     KC_L,    KC_SCLN,   KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,  KC_C,          KC_V,           KC_B,  LT(NUM, KC_EQL),        KC_MINUS,  KC_N,  KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,   KC_RSFT,
  MO(FUNC), KC_NO,  KC_NO, KC_LALT,       KC_LCMD,                                                KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT,  KC_NO,
                                                 KC_F4, KC_F3,    KC_F7, KC_F8,
                                                        KC_F2,    KC_F6,
                                             KC_SPC, KC_LSFT, KC_F1,    KC_F5, KC_QUOT, MO(SYMB)
),
/* Keymap 1: linux
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |     |       |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |  Cmd | Alt  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[LINUX] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS,
  KC_CAPS, KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_LCMD,  KC_LALT,  KC_LCTRL,                                      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
                                                 KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,
                                                        KC_TRNS,    KC_TRNS,
                                       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   _  |   {  |   }  |   `  |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   +  |   =  |   (  |   )  |   -  |------|           |------|   0  |   +  |   =  |   -  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |   [  |   ]  |      |      |           |      |   0  |   1  |   <  |   >  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |   0  |   0  |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRC,     KC_PERCENT, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_UNDS, KC_LCBR, KC_RCBR, KC_GRV,  KC_TRNS,     KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
  KC_TRNS, KC_PLUS, KC_EQL,  KC_LPRN, KC_RPRN, KC_MINUS,                      KC_TRNS, KC_PLUS, KC_EQL,  KC_MINUS,KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,     KC_TRNS, KC_0,    KC_1,    KC_LT,   KC_GT,   KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_0,    KC_0,    KC_0,    KC_TRNS,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Numbers
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   0  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|   0  |   4  |   5  |   6  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   0  |   1  |   2  |   3  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |   0  |   0  |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUM] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_0,    KC_0,    KC_0,    KC_TRNS,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Function keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |Bright|           |  Vol |      |  F7  |  F8  |  F9  |      |        |
 * |--------+------+------+------+------+------|  Up  |           |  Up  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  F4  |  F5  |  F6  |      |        |
 * |--------+------+------+------+------+------|Bright|           |  Vol |------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Down |           | Down |      |  F1  |  F2  |  F3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F12 |  F11 |       |  F15 | F16  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  F10 |       |  F14 |      |      |
 *                                 |      |      |------|       |------|      | Calc |
 *                                 |      |      |  F9  |       |  F13 |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FUNC] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_BRIU,     KC_VOLU, KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID,     KC_VOLD, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_TRNS, KC_TRNS,
  KC_TRNS, TG(LINUX), KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_CALC
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_FOUR_KEYS(KC_P, KC_D, KC_I, KC_S) {
        SEND_STRING("from powerdash.systems.models import *\n");
    }
    SEQ_FOUR_KEYS(KC_P, KC_D, KC_I, KC_C) {
        SEND_STRING("from powerdash.channeldata.models import *\n");
    }
    SEQ_FOUR_KEYS(KC_G, KC_P, KC_D, KC_I) {
        SEND_STRING("https://github.com/powerdash/powerweb/issues");
    }
    SEQ_THREE_KEYS(KC_G, KC_F, KC_R) {
        SEND_STRING("https://feedreader.com/online/#/welcome/?action=login");
    }
  }
}
