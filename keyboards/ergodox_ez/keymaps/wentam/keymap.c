#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // main (dvorak) layer
#define SYMB 1 // symbols/numpad
#define FKEY 2 // f-keys
#define MOUSE 3 // mouse movement
#define ARROW 4 // arrow keys
#define QWERT 5  // qwerty layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Main dvorak layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `/~   |  1/! |  2/@ |  3/# |  4/$ |  5/% |QWERT |           |LFKEY |  6/^ |  7/& |  8\* |  9/( |  0/) |Bckspace|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |  '\" |  ,/< |  ./> |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|LARROW|           |LMOUSE|------+------+------+------+------+--------|
 * | Esc    |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |  Enter |
 * |--------+------+------+------+------+------| LSYMB|           | LSYMB|------+------+------+------+------+--------|
 * | LShift |  ;   |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Ctrl |LARROW|      |  alt |                                       |  -/_ |  =   | PrtSc| ScrLk| Pause|
 *   `----------------------------------'                                      `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       |Pgup  |        |      |
 *                                 | Space| Super|------|       |------|        | F12  |
 *                                 |      |      | End  |       | Pgdown        |      |
 *                                 `--------------------'       `----------------------'
 *
 * Thoughts:
 * n-key rollover?
 * numlock status indicator?
 * adjust mouse sensitivity settings
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_GRAVE,      KC_1,        KC_2,      KC_3,   KC_4,   KC_5,   TG(QWERT),
        KC_TAB,        KC_QUOTE,    KC_COMMA,  KC_DOT, KC_P,   KC_Y,   MO(ARROW),
        KC_ESC,        KC_A,        KC_O,      KC_E,   KC_U,   KC_I,
	KC_LSFT,       KC_SCLN,  KC_Q,      KC_J,   KC_K,   KC_X,   MO(SYMB),
        KC_LCTL,      KC_LCTL,    MO(ARROW),   KC_TRNS,KC_LALT,

                                               KC_TRNS,      KC_TRNS,
                                                              KC_HOME,
                                               KC_SPC,KC_LGUI,KC_END ,

        // right hand
        MO(FKEY),    KC_6,     KC_7,      KC_8,    KC_9,    KC_0,   KC_BSPC,
        MO(MOUSE),  KC_F,     KC_G,      KC_C,    KC_R,    KC_L,    KC_SLASH,
                    KC_D,     KC_H,      KC_T,    KC_N,    KC_S,    KC_ENTER,
        MO(SYMB),   KC_B,     KC_M,      KC_W,    KC_V,    KC_Z,    KC_RSFT,
                              KC_MINUS,     KC_EQUAL,KC_TRNS, KC_TRNS, KC_TRNS,


             KC_TRNS,        KC_TRNS,
             KC_PGUP,
             KC_PGDN,KC_TRNS,KC_F12
    ),

/* Qwerty layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `/~   |  1/! |  2/@ |  3/# |  4/$ |  5/% |      |           |      |  6/^ |  7/& |  8\* |  9/( |  0/) |Bckspace|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   /,?  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  Enter |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   B  |   V  |      |           |      |   N  |   M  |  </, |  >/. |  /,? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Ctrl |LARROW|      |  alt |                                       |  -/_ |  =   | PrtSc| ScrLk| Pause|
 *   `----------------------------------'                                      `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       |Pgup  |        |      |
 *                                 | Space| Super|------|       |------|        | F12  |
 *                                 |      |      | End  |       | Pgdown        |      |
 *                                 `--------------------'       `----------------------'
 *
 */
[QWERT] = LAYOUT_ergodox(
        // left hand
        KC_GRAVE,      KC_1,        KC_2,      KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TAB,        KC_Q,        KC_W,      KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_ESC,        KC_A,        KC_S,      KC_D,   KC_F,   KC_G,
        KC_LSFT,       KC_Z,        KC_X,      KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_LCTL,       KC_LCTL,    MO(ARROW),   KC_TRNS,KC_LALT,

                                               KC_TRNS,      KC_TRNS,
                                                              KC_HOME,
                                               KC_SPC,KC_LGUI,KC_END ,

        // right hand
        KC_TRNS,    KC_6,     KC_7,      KC_8,    KC_9,    KC_0,   KC_BSPC,
        KC_TRNS,  KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    KC_SLASH,
                    KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENTER,
        KC_TRNS,   KC_N,     KC_M,      KC_COMMA,    KC_DOT,    KC_SLASH,    KC_RSFT,
                              KC_MINUS,     KC_EQUAL,KC_TRNS, KC_TRNS, KC_TRNS,


             KC_TRNS,        KC_TRNS,
             KC_PGUP,
             KC_PGDN,KC_TRNS,KC_F12
    ),


/* Symbol/numpad Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |      |      |      |      |      |      |           |      |      |      |      |      |   -  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    \    |   !  |   @  |   {  |   }  |   |  |      |           |      |Numloc|   7  |   8  |   9  |   +  |   \    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Esc   |   #  |   $  |   (  |   )  |   `  |------|           |------|      |   4  |   5  |   6  |      |   *    |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Lshift |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      |   1  |   2  |   3  | enter|   /    |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |   +  |   =  |                                       |      |    0 |   .  |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|Insert|       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |Delete|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_BSLS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_ESC,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_LSFT,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          KC_TRNS,KC_TRNS ,KC_TRNS,KC_PLUS,KC_EQUAL,
                                       RGB_MOD,KC_TRNS,
                                               KC_INSERT,
                               RGB_VAD,RGB_VAI,KC_DELETE,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_KP_MINUS,  KC_TRNS,
       KC_TRNS, KC_NUM_LOCK,   KC_P7,   KC_P8,  KC_P9,  KC_KP_PLUS, KC_BSLS,
                KC_TRNS, KC_P4,   KC_P5,    KC_P6,    KC_TRNS, KC_KP_ASTERISK,
       KC_TRNS, KC_TRNS, KC_P1,   KC_P2,    KC_P3,    KC_KP_ENTER, KC_KP_SLASH,
                         KC_TRNS,KC_P0,  KC_KP_DOT,    KC_TRNS,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* F-key Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FKEY] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_BSLS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_ESC,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_LSFT,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
          KC_TRNS,KC_EQUAL,KC_PLUS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_INSERT,
                                               KC_DELETE,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_NUM_LOCK,   KC_P7,   KC_P8,  KC_P9,  KC_KP_PLUS, KC_F12,
                KC_TRNS, KC_P4,   KC_P5,    KC_P6,    KC_KP_MINUS, KC_KP_ASTERISK,
       KC_TRNS, KC_TRNS, KC_P1,   KC_P2,    KC_P3,    KC_KP_ENTER, KC_KP_SLASH,
                         KC_TRNS,KC_KP_DOT,  KC_P0,    KC_KP_ENTER,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Mouse layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOUSE] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Arrows layer
 * Vim arrow keys + normal arrow key shape on left and right sides
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   ^  |      |      |      |      |           |      |      |      |   ^  |      |   >  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   <  |   v  |   >  |      |      |------|           |------|      |   <  |   v  |   >  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   <  |   >  |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARROW] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_RIGHT,KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_RIGHT,KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS, KC_RIGHT, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
     ergodox_led_all_set( 5 );
//#ifdef RGBLIGHT_COLOR_LAYER_0
//  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
//#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

bool led_update_user(led_t led_state) {
    if (led_state.num_lock) {
        ergodox_right_led_1_off();
    } else {
        ergodox_right_led_1_on();
    }
    return true;
}

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
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        //ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        //ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        //ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        //ergodox_right_led_1_on();
        //ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        //ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        //ergodox_right_led_2_on();
        //ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        //ergodox_right_led_1_on();
        //ergodox_right_led_2_on();
        //ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
