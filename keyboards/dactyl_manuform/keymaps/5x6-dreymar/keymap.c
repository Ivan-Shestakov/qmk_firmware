#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _QWERTY 1
#define _MOVE   2
#define _SYM    3
#define _FN     4

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// The main idea of this layout is to check whether I can get used to 4x5 layout of the Dactyl Manuform (even though 
// I've built 5x6 version) S
// After trying it for several weeks, apparently I can! So now I'm adding back the numbers row and the outermost column 
// to the mapping.
// As well as QWERTY layout as an toggle'able option
const uint16_t  PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base (COLEMAK)
 * Note the usage of modifiers on the home row
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * |      |      |      |      |      |      |                             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |   q  |   w  |   f  |   p  |   g  |                             |   j  |   l  |   u  |   y  |   '  |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |   a  |   r  |   s  |   t  |   d  |                             |   h  |   n  |   e  |   i  |   o  |      |
 * |      |  Alt |      |      | Ctrl |      |                             |      | Ctrl |      |      |  Alt |      |
 * |------+------+------+------+------+------|                             |------|------+------+------+------+------|
 * |      |   z  |   x  |   c  |   v  |   b  |                             |   k  |   m  |   ,  |   .  |   /  |      |
 * |      | Shft |      |      |      |      |                             |      |      |      |      | Shft |      |
 * '------+------+------+------+-------------,                             ,-------------+------+------+------+------'
 *               |      | LWIN |                                                         |Insert|   ;  |
 *               '------+------'-------------'                             '-------------'------+------'
 *                             | Space| Enter|                             |BckSpc| Del  |
 *                             | _SYM | Shift|                             |Shift | _SYM |
 *                             '------+------'                             '------+------'
 *                                           '------+------' '------+------'
 *                                           | Esc  | Tab  | | Tab  | Esc  |
 *                                           | _MOVE| GUI  | | GUI  |_MOVE |
 *                                           '------+------' '------+------'
 *                                           | _FN  |  ~   | |  ~   |  _FN |
 *                                           '------+------' '------+------'
 */
      	      
[_COLEMAK] = KEYMAP_5x6(
  // left hand
   KC_ESC ,  KC_1,  KC_2,  KC_3,  KC_4, KC_5,
   KC_TAB,   KC_Q,      KC_W,     KC_F,     KC_P,    KC_G,
   KC_LSHIFT,   LALT_T(KC_A),      KC_R,     KC_S,     CTL_T(KC_T),    KC_D,
   KC_LCTL,   SFT_T(KC_Z),KC_X,    KC_C,     KC_V,    KC_B,
                       KC_LALT,  KC_LWIN, 
                               	             LT(_SYM, KC_SPC), SFT_T(KC_ENT), 
                                                       LT(_MOVE, KC_ESC), GUI_T(KC_TAB), 
                                                       MO(_FN), KC_TILD,
        // right hand
                    KC_6,   KC_7,  KC_8,  KC_9,  KC_0,     KC_BSPC,
                    KC_J,   KC_L,      KC_U,     KC_Y,    KC_QUOT,     KC_ENTER,
                    KC_H,   RCTL_T(KC_N), KC_E,  KC_I,  RALT_T(KC_O),  KC_RSFT,
		                KC_K,   KC_M,    KC_COMM, KC_DOT, RSFT_T(KC_SLSH), KC_RCTL,
                                       KC_INS, KC_SCLN,
        SFT_T(KC_BSPC), LT(_SYM, KC_DEL), 
  GUI_T(KC_TAB), LT(_MOVE, KC_ESC),
  KC_TILD, MO(_FN)),

[_QWERTY] = KEYMAP_5x6(
  // left hand
   KC_ESC,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5, 
   KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,
   KC_LSFT,    KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
   KC_LCTL, SFT_T(KC_Z),    KC_X,    KC_C,   KC_V,   KC_B,
                       KC_LALT,  KC_LWIN, 
                               	             LT(_SYM, KC_SPC), SFT_T(KC_ENT), 
                                                       LT(_MOVE, KC_ESC), GUI_T(KC_TAB), 
                                                       MO(_FN), KC_TILD,
        // right hand
                     KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPACE,
                     KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_ENTER,
                     KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_RSFT, 
                     KC_N,    KC_M,   KC_COMM, KC_DOT,  SFT_T(KC_SLSH), KC_RCTL,
                                       KC_INS, KC_SCLN,
        SFT_T(KC_BSPC), LT(_SYM, KC_DEL), 
  GUI_T(KC_TAB), LT(_MOVE, KC_ESC),
  KC_TILD, MO(_FN)),
        
/* _SYM
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * |      |      |      |      |      |      |                             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |   |  |   !  |   {  |   }  |   @  |                             |   +  |   7  |   8  |   9  |   ^  |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |   &  |   #  |   (  |   )  |   $  |                             |   =  |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------|                             |------|------+------+------+------+------|
 * |      |   ;  |   %  |   [  |   ]  |   \  |                             |   -  |   1  |   2  |   3  |   /  |      |
 * '------+------+------+------+-------------,                             ,-------------+------+------+------+------'
 *               |   `  |PrntSc|                                                         |   0  |   .  |
 *               '------+------'-------------'                             '-------------'------+------'
 *                             | Space| Enter|                             |BckSpc| Del  |
 *                             | _SYM | Shift|                             |Shift | _SYM |
 *                             '------+------'                             '------+------'
 *                                           '------+------' '------+------'
 *                                           | Esc  | Tab  | |  Tab |  Esc |
 *                                           | _MOVE|      | |      |_MOVE |
 *                                           '------+------' '------+------'
 *                                           | _FN  |  ~   | |   ~  |  _FN |
 *                                           '------+------' '------+------'
 *   
 */
[_SYM] = KEYMAP_5x6(
  // left hand
  _______, _______, _______, _______, _______, _______,
  _______,  KC_PIPE, KC_EXLM, KC_LCBR, KC_RCBR, KC_AT,
  _______,  KC_AMPR, KC_HASH, KC_LPRN, KC_RPRN, KC_DLR,
  _______,  KC_SCLN, KC_PERC, KC_LBRC, KC_RBRC, KC_BSLS,
            KC_GRV,  KC_RPRN, 
                               	             LT(_SYM, KC_SPC), SFT_T(KC_ENT), 
                                                       _______, _______, 
                                                       MO(_FN), _______,
        // right hand
        _______, _______, _______, _______, _______,_______,
                     KC_PLUS, KC_7, KC_8, KC_9, KC_CIRC,_______,
                     KC_EQL,  KC_4, KC_5, KC_6, KC_ASTR,_______,
                     KC_MINS, KC_1, KC_2, KC_3, KC_SLSH,_______,
                                       KC_0, KC_DOT,
        SFT_T(KC_BSPC), LT(_SYM, KC_DEL), 
  _______, _______,
  _______, MO(_FN)),
/* _MOVE
 * a movement layer inspired by Dreymar's bag of keyboard tricks (from Colemak forum)
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * |      |      |      |      |      |      |                             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      | PScr | WhUP | MsUP | WhDN | WhUP |                             |   ⤒  | Home |   ↑  | End  | Del  |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      | BTN3 |MsLEFT| MsDN |MsRIGHT| GUI |                             |   ⤓  |   ←  |   ↓  |   →  | Bsp |      |
 * |------+------+------+------+------+------|                             |------|------+------+------+------+------|
 * |      | BTN1 | BTN5 | BTN2 |  BTN3| WhDN |                             | Caps |      |Insert| Tab  |      |      |
 * '------+------+------+------+-------------,                             ,-------------+------+------+------+------'
 *               |   `  | Tab  |                                                         |      |      |
 *               '------+------'-------------'                             '-------------'------+------'
 *                             | Space| Enter|                             |BckSpc| Del  |
 *                             | _SYM | Shift|                             |Shift | _SYM |
 *                             '------+------'                             '------+------'
 *                                           '------+------' '------+------'
 *                                           | Esc  | Tab  | |  Tab |  Esc |
 *                                           | _MOVE|      | |      |_MOVE |
 *                                           '------+------' '------+------'
 *                                           | _FN  |  ~   | |   ~  |  _FN |
 *                                           '------+------' '------+------'
 */
 [_MOVE] = KEYMAP_5x6(
  // left hand
  _______, _______, _______, _______, _______, _______,
  _______, KC_PSCR,   KC_WH_U, KC_MS_U, KC_WH_D,  KC_WH_U,
  _______, KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R,  KC_LGUI,
  _______, KC_BTN1, KC_BTN5, KC_BTN2, KC_BTN3,  KC_WH_D,
            KC_GRV,  KC_TAB, 
                               	             LT(_SYM, KC_SPC), SFT_T(KC_ENT), 
                                                       _______, _______, 
                                                       MO(_FN), _______,
        // right hand
                    _______, _______, _______, _______, _______, _______,
                     KC_PGUP, KC_HOME, KC_UP, KC_END, KC_DEL, _______,
                     KC_PGDN, KC_LEFT, KC_DOWN,   KC_RIGHT, KC_BSPC, _______,
                     KC_CAPS, _______,  KC_INS,  KC_TAB,  _______, _______,
                                       _______, _______,
        SFT_T(KC_BSPC), LT(_SYM, KC_DEL),
  _______, _______,
  _______, MO(_FN)),
[_FN] = KEYMAP_5x6(
  // left hand
  _______, _______, _______, _______, _______, _______,
   _______, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_WH_U,
   _______, KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_LGUI,
   _______, KC_F9, KC_F10,  KC_F11, KC_F12, KC_WH_D,
            KC_GRV,  KC_TAB, 
                               	             LT(_SYM, KC_SPC), SFT_T(KC_ENT), 
                                                       TO(_QWERTY), TO(_COLEMAK), 
                                                       MO(_FN), RESET,
        // right hand
                    _______, _______, _______, _______, _______, _______,
                     _______, _______, _______, _______, _______, _______,
                     KC_CALC, KC_MAIL, KC_MYCM, KC_WHOM, KC_PSCR, _______,
                     _______, _______, _______, _______, KC_SCROLLLOCK, _______,
                                       KC_MINS, KC_SCLN,
        SFT_T(KC_BSPC), LT(_SYM, KC_DEL),
  TO(_COLEMAK), TO(_QWERTY),
  RESET, MO(_FN)),
};



void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
