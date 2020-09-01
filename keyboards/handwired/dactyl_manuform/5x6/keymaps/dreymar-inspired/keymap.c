/*
a Colemak layout for the dactyl manuform 5x6 keyboard, with movement layer heavily inspired by Dreymar's Extend layer
https://forum.colemak.com/topic/2014-extend-extra-extreme/#p16698
*/

#include QMK_KEYBOARD_H


#define _BASE 0
#define _MOVE 1
#define _SYM 2
#define _FUN 3

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// shortcuts for mod-tap
#define LA(kc) MT(MOD_LALT, kc)
#define RA(kc) MT(MOD_RALT, kc)
#define LS(kc) MT(MOD_LSFT, kc)
#define RS(kc) MT(MOD_RSFT, kc)
#define LC(kc) MT(MOD_LCTL, kc)
#define RC(kc) MT(MOD_RCTL, kc)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* _BASE (COLEMAK)
 * note the usage of modifiers on the home row
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * | esc  |  1   |   2  |   3  |   4  |   5  |                             |   6  |   7  |   8  |  9   |   0  |  ⌫   |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * | tab  |   q  |   w  |   f  |   p  |   g  |                             |   j  |   l  |   u  |   y  |   '  | ent  |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * | shft |   a  |   r  |   s  |   t  |   d  |                             |   h  |   n  |   e  |   i  |   o  | shft |
 * |      |  alt |      |      | ctrl |      |                             |      | ctrl |      |      |  alt |      |
 * |------+------+------+------+------+------|                             |------|------+------+------+------+------|
 * | ctrl |   z  |   x  |   c  |   v  |   b  |                             |   k  |   m  |   ,  |   .  |   /  | ctrl |
 * |      | shft |      |      |      |      |                             |      |      |      |      | shft |      |
 * '------+------+------+------+-------------,                             ,-------------+------+------+------+------'
 *               |  alt | lwin |                                                         |insert|   ;  |
 *               '------+------'-------------'                             '-------------'------+------'
 *                             | space| enter|                             |bckspc| del  |
 *                             | _sym | shift|                             |shift | _sym |
 *                             '------+------'                             '------+------'
 *                                           '------+------' '------+------'
 *                                           | esc  | tab  | | tab  | esc  |
 *                                           | _move| gui  | | gui  |_move |
 *                                           '------+------' '------+------'
 *                                           | _fn  |  ~   | |  ~   |  _fn |
 *                                           '------+------' '------+------'
 */
  [_BASE] = LAYOUT_5x6(
   KC_ESC , KC_1    , KC_2  , KC_3 , KC_4   , KC_5 ,                       KC_6,  KC_7    , KC_8   ,   KC_9,  KC_0    , KC_BSPC,
   KC_TAB , KC_Q    , KC_W  , KC_F , KC_P   , KC_G ,                       KC_J,  KC_L    , KC_U   ,   KC_Y,  KC_QUOT , KC_ENT,
   KC_LSFT, LA(KC_A), KC_R  , KC_S ,LC(KC_T), KC_D ,                       KC_H,  RC(KC_N), KC_E   ,   KC_I,  RA(KC_O), KC_RSFT,
   KC_LCTL, LS(KC_Z), KC_X  , KC_C , KC_V   , KC_B ,   		               KC_K,  KC_M    , KC_COMM, KC_DOT,RS(KC_SLSH),KC_RCTL,
                      KC_LALT,  KC_LWIN,                                          KC_INS, KC_SCLN,
                               	LT(_SYM, KC_SPC), SFT_T(KC_ENT),    SFT_T(KC_BSPC), LT(_SYM, KC_DEL),
                                LT(_MOVE, KC_ESC), GUI_T(KC_TAB),   GUI_T(KC_TAB), LT(_MOVE, KC_ESC),
                                MO(_FUN), KC_TILD,                  KC_TILD, MO(_FUN)),
 /* _MOVE
 * a movement layer inspired by Dreymar's bag of keyboard tricks (from Colemak forum)
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * |      |      |      |      |      |      |                             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |      | PScr | WhUP | MsUP | WhDN | WhUP |                             |   ⤒  | Home |   ↑  | End  | Del  |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      | BTN3 |MsLEFT| MsDN |MsRIGHT| GUI |                             |   ⤓  |   ←  |   ↓  |   →  | Bsp  |      |
 * |------+------+------+------+------+------|                             |------|------+------+------+------+------|
 * |      | BTN1 | BTN5 | BTN2 |  BTN3| WhDN |                             | Caps |      |Insert| Tab  |      |      |
 * '------+------+------+------+-------------,                             ,-------------+------+------+------+------'
 *               |   `  |      |                                                         |      |      |
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
  [_MOVE] = LAYOUT_5x6(
   _______,_______,_______,_______,_______,_______,                        _______, _______,_______,_______,_______,_______,
   _______,KC_PSCR,KC_WH_U,KC_MS_U,KC_WH_D,_______,                        KC_PGUP,KC_HOME , KC_UP ,KC_END ,KC_END ,_______,
   _______,KC_BTN3,KC_MS_L,KC_MS_D,KC_MS_R,KC_LGUI,                        KC_PGDN,KC_LEFT,KC_DOWN,KC_RIGHT,KC_BSPC,_______,
   _______,KC_BTN1,KC_BTN5,KC_BTN2,KC_BTN3,_______,                        KC_CAPS,_______, KC_INS , KC_TAB,_______,_______,
                   KC_GRV ,_______,                                                                 _______,_______,
                          LT(_SYM,KC_SPC),SFT_T(KC_ENT),            SFT_T(KC_BSPC),LT(_SYM,KC_DEL),
                                       _______,_______,             _______,_______,
                                       MO(_FUN),_______,            _______,MO(_FUN)),

 /* _SYM - a symbol layer, uses pairs of various brackets on left half and NumPad numbers on right half
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * |      |      |      |      |      |      |                             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |   |  |   !  |   {  |   }  |   @  |                             |   +  |   7  |   8  |   9  |   ^  |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |   &  |   #  |   (  |   )  |   $  |                             |   =  |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------|                             |------|------+------+------+------+------|
 * |      |   ;  |   %  |   [  |   ]  |   \  |                             |   -  |   1  |   2  |   3  |   /  |      |
 * '------+------+------+------+-------------,                             ,-------------+------+------+------+------'
 *               |   `  |      |                                                         |   0  |   .  |
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
    [_SYM] = LAYOUT_5x6(
   _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
   _______,KC_PIPE,KC_EXLM,KC_LCBR,KC_RCBR, KC_AT ,                        KC_PLUS, KC_7  , KC_8  , KC_9  ,KC_CIRC,_______,
   _______,KC_AMPR,KC_HASH,KC_LPRN,KC_RPRN,KC_DLR ,                        KC_EQL , KC_4  , KC_5  , KC_6  ,KC_ASTR,_______,
   _______,KC_SCLN,KC_PERC,KC_LBRC,KC_RBRC,KC_BSLS,                        KC_MINS, KC_1  , KC_2  , KC_3  ,KC_SLSH,_______,
           KC_GRV ,_______,                                                                         KC_0  , KC_DOT,
                           LT(_SYM, KC_SPC), SFT_T(KC_ENT),         SFT_T(KC_BSPC), LT(_SYM, KC_DEL),
                                           _______,_______,         _______,_______,
                                          MO(_FUN),_______,         _______,MO(_FUN)),
 /* _FUN
 * ,-----------------------------------------,                             ,-----------------------------------------,
 * |      |      |      |      |      |      |                             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |   F4 |      |                             |   🔇 |  🔉  |   🔊  |  ⏮️  |   ⏯️  |  ⏭️  |
 * |------+------+------+------+------+------|                             |-------------+------+------+------+------|
 * |      |   F5 |  F6  |  F7  |   F8 |      |                             |   🖩  |  📧  |  🖳  |  🏡  |Pr.Scr|      |
 * |------+------+------+------+------+------|                             |------|------+------+------+------+------|
 * |      |   F9 |   F10| F11  |  F12 |      |                             |      |      |      |      |ScrlLk|      |
 * '------+------+------+------+-------------,                             ,-------------+------+------+------+------'
 *               |   `  | Tab  |                                                         |   -  |   ;  |
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
    [_FUN] = LAYOUT_5x6(
   _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
   _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 ,_______,                        KC_MUTE,KC_VOLD,KC_VOLU,KC_MPRV,KC_MPLY,KC_MNXT,
   _______, KC_F5 , KC_F6 , KC_F7 , KC_F8 ,_______,                        KC_CALC,KC_MAIL,KC_MYCM,KC_WHOM,KC_PSCR,_______,
   _______, KC_F9 , KC_F10, KC_F11, KC_F12,_______,                        _______,_______,_______, _______,KC_SCROLLLOCK,_______,
                    KC_GRV, KC_TAB,                                                        KC_MINS, KC_SCLN,
                        LT(_SYM, KC_SPC), SFT_T(KC_ENT),            SFT_T(KC_BSPC), LT(_SYM, KC_DEL),
                                        _______,_______,            _______,_______,
                                        MO(_FUN), RESET,            RESET, MO(_FUN)),
};
