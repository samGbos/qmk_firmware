#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,      // default layer
    STARCRAFT, // swaps space + cmd
    SYMB,      // symbols
    NUM,       // numbers
    FUNC,      // "fn" layer: F-keys, media, nav cluster, layer toggles
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
 *   |Fn/Glb|      |      | Alt  | Cmd  |                                       | Left | Down |  Up  | Right|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F4   | F3   |       | F7   | F8   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | F2   |       | F6   |        |      |
 *                                 | Space|Shift |------|       |------|  '     | SYMB |
 *                                 |      |      | F1   |       | F5   |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,   KC_1,   KC_2,  KC_3,          KC_4,           KC_5,  KC_6,          KC_5,      KC_6,  KC_7,     KC_8,     KC_9,    KC_0,      KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,  KC_E,          KC_R,           KC_T,  KC_Y,          KC_TRNS,   KC_Y,  KC_U,     KC_I,     KC_O,    KC_P,      KC_BSLS,
  KC_LCTL, KC_A,   KC_S,  KC_D,          KC_F,           KC_G,                            KC_H,  KC_J,     KC_K,     KC_L,    KC_SCLN,   KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,  KC_C,          KC_V,           KC_B,  LT(NUM, KC_EQL),        KC_MINUS,  KC_N,  KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,   KC_RSFT,
  LT(FUNC, KC_NO), KC_NO, KC_NO, KC_LALT,       KC_LCMD,                                                KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT,  KC_NO,
                                                 KC_F4, KC_F3,    KC_F7, KC_F8,
                                                        KC_F2,    KC_F6,
                                             KC_SPC, KC_LSFT, KC_F1,    KC_F5, KC_QUOT, MO(SYMB)
),
/* Keymap 1: Starcraft
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
 *   |Fn/Glb|      |      | Alt  | Spc  |                                       | Left | Down |  Up  | Right|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F4   | F3   |       | F7   | F8   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | F2   |       | F6   |        |      |
 *                                 | Cmd  |Shift |------|       |------|  '     | SYMB |
 *                                 |      |      | F1   |       | F5   |        |      |
 *                                 `--------------------'       `----------------------'
 */
[STARCRAFT] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,      KC_TRNS,   KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS,
  KC_CAPS, KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,                        KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,     KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_SPC,                                      KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
                                                 KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,
                                                        KC_TRNS,    KC_TRNS,
                                       KC_LCMD, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   _  |   {  |   }  |   `  |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   +  |   =  |   (  |   )  |   -  |------|           |------|   +  |   +  |   %  |   -  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |   [  |   ]  |      |      |           |      |   -  |   1  |   <  |   >  |      |        |
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
  KC_TRNS, KC_PLUS, KC_EQL,  KC_LPRN, KC_RPRN, KC_MINUS,                      KC_PLUS, KC_PLUS, KC_PERCENT,  KC_MINUS,KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,     KC_TRNS, KC_MINUS,    KC_1,    KC_LT,   KC_GT,   KC_TRNS, KC_TRNS,
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
 * |         |      |      |      |      |      |------|           |------|   +  |   4  |   5  |   6  |   *  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   -  |   1  |   2  |   3  |   /  |        |
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
  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                      KC_PLUS, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_MINUS,    KC_1,    KC_2,    KC_3,    KC_SLSH, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_0,    KC_0,    KC_0,    KC_TRNS,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Fn layer (hold the bottom-left key)
 *
 * Mimics a Mac keyboard's fn key: fn+arrows = Home/PgDn/PgUp/End, fn+backspace = forward delete.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |  F10 |  F11 |  F12 |      |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |Bright|           |  Vol |      |  F7  |  F8  |  F9  |      |        |
 * |--------+------+------+------+------+------|  Up  |           |  Up  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  F4  |  F5  |  F6  |      | Play   |
 * |--------+------+------+------+------+------|Bright|           |  Vol |------+------+------+------+------+--------|
 * |        |      |      |      |      |      | Down |           | Down |      |  F1  |  F2  |  F3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |  TG  |      |      |                                       | Home | PgDn | PgUp | End  |      |
 *   |      |      |  SC  |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      | Calc |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FUNC] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_DEL,
  KC_TRNS, KC_TRNS, KC_TRNS, MS_UP,   KC_TRNS, KC_TRNS, KC_BRIU,     KC_VOLU, KC_TRNS, KC_F7,  KC_F8,  KC_F9,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_F4,  KC_F5,  KC_F6,  KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID,     KC_VOLD, KC_TRNS, KC_F1,  KC_F2,  KC_F3,  KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, TG(STARCRAFT), KC_TRNS, KC_TRNS,                                  KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_CALC
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Bottom-left key: tap = Apple Globe key, hold = Fn layer.
    // The Globe key is the standard HID consumer usage 0x029D, which macOS
    // treats as Globe/fn. The hold half is handled by QMK as a normal layer-tap.
    case LT(FUNC, KC_NO):
      if (record->tap.count) {
        host_consumer_send(record->event.pressed ? AC_NEXT_KEYBOARD_LAYOUT_SELECT : 0);
        return false;
      }
      return true;
  }

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
// The three LEDs show the active layer.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (get_highest_layer(state)) {
    case STARCRAFT:
      ergodox_right_led_1_on();
      break;
    case SYMB:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case NUM:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case FUNC:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }

  return state;
};