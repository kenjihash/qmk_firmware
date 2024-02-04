/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _SYM,
  _NAV,
  _NUM
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
#define OS_SHFT OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_CMD OSM(MOD_LGUI)
#define SYM_SPC LT(LA_SYM, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   ;  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  NAV | SHFT | SHFT |  SYM |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   _______, _______, KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   _______, _______, KC_H,   KC_J,    KC_K,    KC_L,   KC_QUOT,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   _______, _______, KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SCLN,
    _______, _______, _______, _______, LA_NAV, OS_SHFT, OS_SHFT, SYM_SPC, _______,  _______, _______, _______
),

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |  ESC |   [  |   {  |   (  |   `  |      |      |   ~  |   )  |   }  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   -  |   *  |   =  |   _  |   $  |      |      |   #  | GUI  | ALT  | CTRL | SHFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   +  |   |  |   @  |   /  |   %  |      |      |   ^  |   \  |   &  |   ?  |   !  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  NUM |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_GRV,  _______, _______, KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, _______,
    KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  _______, _______, KC_HASH, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
    KC_PLUS, KC_PIPE, KC_AT,   KC_SLSH, KC_PERC, _______, _______, KC_CIRC, KC_BSLS, KC_AMPR, KC_QUES, KC_EXLM,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |  ESC | Mute | Vol- | Vol+ |      |      |      | Tab  | End  | Home | Bksp | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHFT | CTRL | ALT  | GUI  |      |      |      | Left | Down | Up   | Right| Entr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CWORD | Prev |PlyPas| Next |      |      |      |      |Pg Dn |Pg Up |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | NUM  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_TAB,  KC_END,  KC_HOME, KC_BSPC, KC_DEL,
    OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
    KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHFT | CTRL | ALT  | GUI  |  F11 |      |      |  F12 | GUI  | ALT  | CTRL | SHFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  |  F10 |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_ortho_4x12(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,  KC_6,    KC_7,   KC_8,    KC_9,    KC_0,
    OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_F11,  _______, _______,  KC_F12,  OS_CMD, OS_ALT,  OS_CTRL, OS_SHFT,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______,  KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}
