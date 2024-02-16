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

#include "oneshot.h"

enum planck_layers {
  _QWERTY,
  _SYM,
  _NAV,
  _NUM
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};


enum keycodes {
  // Custom oneshot mod implementation with no timers.
  OS_SHFT = SAFE_RANGE,
  OS_CTRL,
  OS_ALT,
  OS_CMD,
};

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
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
    CAPSWRD, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

/* Number
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHFT | CTRL | ALT  | GUI  |  F11 |      |      |  F12 | GUI  | ALT  | CTRL | SHFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_ortho_4x12(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,  KC_6,    KC_7,   KC_8,    KC_9,    KC_0,
    OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  KC_F11,  _______, _______,  KC_F12,  OS_CMD, OS_ALT,  OS_CTRL, OS_SHFT,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______,  KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};


bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}
