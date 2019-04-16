#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
* ,----------------------------------,                             ,----------------------------------,
*|   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
*|------+------+------+------+------|                             |-------------+------+------+------|
*|   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
*|------+------+------+------+------|                             |------|------+------+------+------|
*|   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
*|------+------+------+-------------,                             ,-------------+------+------+------,
*       |  [   |   ]  |                                                         |   -  |   =  |
*       '------+------'-------------'                             '-------------'------+------'
*                     | ESC  |  BS  |                             | SPACE|ENTER |
*                     |  +   |   +  |                             |  +   |  +   |
*                     | SHIFT| CTRL |                             | ALT  |SHIFT |
*                     '------+------'                             '------+------'
*                                   '------+------' '------+------'
*                                   | TAB  | HOME | | END  | DEL  |
*                                   '------+------' '------+------'
*                                   | Raise| `/~  | | GUI  | Lower|
*                                   '------+------' '------+------'
 */

[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, \
  KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_QUOT, \
              KC_LBRC, KC_RBRC,                                                   KC_MINS, KC_EQL,                   \
                                      SFT_ESC, CTL_BSPC,  ALT_SPC, SFT_ENT,                                          \
                                      KC_TAB,  KC_HOME,   KC_END,  KC_DEL,                                           \
                                      RAISE,   KC_GRV,    KC_LGUI, LOWER
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      | TAB  |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |SHFTAB| mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |   «  |  ||  |   »  |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |TAKEN |      | |      |      |
 *                                    '------+------' '------+------'
 */

[_RAISE] = LAYOUT( \
  ____,KC_TAB, KC_MU, ____,  ____,                          KC_VOLU, ____,    KC_UP,   ____,     KC_PGUP,   \
  LSFT(KC_TAB), KC_ML, KC_MD, KC_MR, ____,                          KC_MUTE, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, \
  ____, KC_MEDIA_PREV_TRACK,  KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_NEXT_TRACK,  ____,                          KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,   \
        ____,  ____,                                                          KC_MB1,  KC_MB2,              \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____,                                                 \
                                   ____, ____,  ____, ____                                                  \
),
/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * | F1   | F2   | F3   | F4   | F5   |                             |      |  7   |  8   |  9   |  -   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * | F6   | F7   | F8   | F9   | F10  |                             |      |  4   |  5   |  6   |  +   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             |      |  1   |  2   |  3   |ENTER |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |  0   |  .   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |TAKEN |
 *                                    '------+------' '------+------'
 */

[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                  ____,    KC_7,     KC_8,    KC_9,    KC_KP_MINUS,  \
  KC_F6,   KC_F7,  KC_F8,   KC_F9,  KC_F10,                 ____,    KC_4,     KC_5,    KC_6,    KC_KP_PLUS,\
  ____, ____,  ____,  ____,  ____,                          ____,    KC_1,     KC_2,    KC_3,    KC_ENT, \
           KC_F11, KC_F12,                                                     KC_0,    KC_KP_DOT,        \
                                   ____, ____,  ____, ____,                                               \
                                   ____, ____,  ____, ____,                                               \
                                   ____, ____,  ____, ____                                                \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
