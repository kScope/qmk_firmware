/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"
#include "keymap_extras/keymap_italian.h"
//#include "quantum.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _UTILS,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  UTILS,

  MK_TILDE,
  MK_BQUOT,
  MK_PWD,

  MK_LAMBDA,
  MK_LAMBDAVAR,
  MK_CURRFLD,
  MK_PARFLD,
  BACKLIT,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

enum {
  TD_Z_LESSTHAN = 0,
  TD_X_GREATTHAN
};

#define RTAB    LT(_LOWER, KC_TAB)
#define ENTUTL  LT(_UTILS, KC_ENT)
#define LSHFLT   MT(MOD_LSFT, IT_LESS)
#define LSHFGT   MT(MOD_LSFT, IT_MORE)
#define RSHFMN   MT(MOD_RSFT, IT_MINS)
#define TAPZLT   TD(TD_Z_LESSTHAN)
#define TAPXGT   TD(TD_X_GREATTHAN)



#define TILDE   MK_TILDE         // ~ macro
#define BQUOT   MK_BQUOT         // ` macro
#define CTRLAD  LALT(LCTL(KC_DEL))  // ctrl+alt+del
#define PWD     MK_PWD           // password macro
#define LMBD    MK_LAMBDA
#define LMBDV   MK_LAMBDAVAR
#define CFLD    MK_CURRFLD
#define PFLD    MK_PARFLD
#define MREC1   DYN_REC_START1
#define MSTOP1  DYN_REC_STOP
#define MPLAY   DYN_MACRO_PLAY1
/*
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_Z_LESSTHAN] = ACTION_TAP_DANCE_DOUBLE(IT_Z, IT_LESS),
  [TD_X_GREATTHAN] = ACTION_TAP_DANCE_DOUBLE(IT_X, LSFT(IT_LESS))
};
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  |  <   |Lower |    Space    |Raise |  /   | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,    IT_Q,     IT_W,     IT_E,     IT_R,    IT_T,    IT_Y,    IT_U,    IT_I,     KC_O,     KC_P,    	KC_BSPC },
  {RTAB,      IT_A,     IT_S,     IT_D,     IT_F,    IT_G,    IT_H,    IT_J,    IT_K,     KC_L,     IT_PLUS, 	ENTUTL  },
  {LSHFLT, 	  IT_Z,     IT_X,     IT_C,     IT_V,    IT_B,    IT_N,    IT_M,    IT_COMM,  IT_DOT,   KC_UP, 	  RSHFMN },
  //{LSHFLT, 	  TAPZLT,     TAPXGT,     IT_C,     IT_V,    IT_B,    IT_N,    IT_M,    IT_COMM,  IT_DOT,   KC_UP, 	  RSHFMN },
  {KC_LCTL,   KC_LGUI,  KC_LALT,  IT_LESS,  LOWER,   KC_SPC,  KC_SPC,  RAISE, 	IT_SLSH,  KC_LEFT,  KC_DOWN,  KC_RGHT }
},


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |  F1  |  F2  |  F3  |  F4  |  Ins | Home |  PgU |   7  |   8  |   9  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F5  |  F6  |  F7  |  F8  |  Del | End  |  PgD |   4  |   5  |   6  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |  Nlk |      |      |   1  |   2  |   3  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |   0  | Home |   .  | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_INS,      KC_HOME,  KC_PGUP,  KC_P7,   KC_P8,    KC_P9,   _______},
  {_______, KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_DEL,      KC_END,   KC_PGDN,  KC_P4,   KC_P5,    KC_P6,   _______},
  {_______, KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_NUMLOCK,  _______,  _______,  KC_P1,   KC_P2,    KC_P3,   _______},
  {_______, _______,  _______,  _______,  _______,  _______,     _______,  _______,  KC_P0,   KC_HOME,  IT_DOT,  KC_END}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  \   |  7   |  8   |  9   |  #   |      |      |      |   '  |  @   |  ì   | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  4   |  5   |  6   |  ~   |      |      |      |      |      |  [   |  ]   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  `   |      |      |      |      |      |  (   |  )   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  0   |  .   |      |      |             |      |  à   |  è   |  ò   |  ù   |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {IT_BKSL,   KC_7,     KC_8,     KC_9,     IT_SHRP,  _______,  _______,  _______, IT_APOS,   IT_AT,    IT_IACC,  KC_DEL},
  {_______,   KC_4,     KC_5,     KC_6,     TILDE,    _______,  _______,  _______, _______,   _______,  IT_LBRC,  IT_RBRC},
  {KC_LSHIFT, IT_LESS,  IT_MORE,  KC_3,     BQUOT,    _______,  _______,  _______, _______,   _______,  IT_LPRN,  IT_RPRN},
  {_______,   KC_0,     IT_DOT,   _______,  _______,  _______,  _______,  _______, IT_AACC,   IT_EACC,  IT_OACC,  IT_UACC}
},

/* Utils layer
 * ,-----------------------------------------------------------------------------------.
 * | Pwd  |  !   |  "   |  £   |  $   |  %   |  &   |  /   |  (   |  )   |  =   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  $   |  %   |  &   |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  =>  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |C+A+D |      |      |      |      |             |      |      | ../  |  ./  | x => |
 * `-----------------------------------------------------------------------------------'
 */

[_UTILS] = {
  {_______,       IT_EXLM,   IT_DQOT,    IT_STRL,  IT_DLR,   IT_PERC,  IT_AMPR,  IT_SLSH,  IT_LPRN,  IT_RPRN,  IT_EQL,   _______  },
  {_______,    IT_DLR,    IT_PERC,    IT_AMPR,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  },
  {_______,    _______,   _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  LMBD  },
  { CTRLAD,    _______,   _______,    _______,  _______,  _______,  _______,  _______,  _______,  PFLD,     CFLD,     LMBDV  }
},


[_ADJUST] = {
  {    PWD,    _______,   _______,    _______,    MREC1,  _______,  _______,  _______,  _______,  _______,    MPLAY,  _______  },
  {_______,    _______,    MSTOP1,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  },
  {_______,    _______,   _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  },
  {BACKLIT,    _______,   _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  }
}

};




// forza il numlock sempre attivo
void led_set_keymap(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    register_code(KC_NUMLOCK);
    unregister_code(KC_NUMLOCK);
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_record_dynamic_macro(keycode, record)) {
      return false;
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case UTILS:
     if (record->event.pressed) {
        layer_on(_UTILS);
      } else {
        layer_off(_UTILS);
      }
      return false;
      break;

    case MK_TILDE:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_TAP(X_KP_1));
        SEND_STRING(SS_TAP(X_KP_2));
        SEND_STRING(SS_TAP(X_KP_6));
        SEND_STRING(SS_UP(X_LALT));
      }
      return true;
      break;

    case MK_BQUOT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_RALT));
        SEND_STRING(SS_TAP(X_KP_9));
        SEND_STRING(SS_TAP(X_KP_6));
        SEND_STRING(SS_UP(X_RALT));
      }
      return true;
      break;

    case MK_PWD:
      if (record->event.pressed) {
        // Put here your password if you hate yourself
      }
      return true;
      break;

    case MK_LAMBDA:
      if (record->event.pressed) {
        SEND_STRING(" ");
        SEND_STRING(SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_TAP(X_0));
        SEND_STRING(SS_TAP(X_NONUS_BSLASH));
        SEND_STRING(SS_UP(X_LSHIFT));
        SEND_STRING(" ");
      }
      return true;
      break;

    case MK_LAMBDAVAR:
      if (record->event.pressed) {
        SEND_STRING(" x ");
        SEND_STRING(SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_TAP(X_0));
        SEND_STRING(SS_TAP(X_NONUS_BSLASH));
        SEND_STRING(SS_UP(X_LSHIFT));
        SEND_STRING(" ");
      }
      return true;
      break;

    case MK_CURRFLD:
      if (record->event.pressed) {
        SEND_STRING(".");
        SEND_STRING(SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_TAP(X_7));
        SEND_STRING(SS_UP(X_LSHIFT));
      }
      return true;
      break;

    case MK_PARFLD:
      if (record->event.pressed) {
        SEND_STRING("..");
        SEND_STRING(SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_TAP(X_7));
        SEND_STRING(SS_UP(X_LSHIFT));
      }
      return true;
      break;

    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
  }
  return true;
}
