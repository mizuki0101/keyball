/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// macro define
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  LANG_CHANGE,
  SHIFT_END,
  SHIFT_HOME,
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//   case LANG_CHANGE:
//     if (record->event.pressed) {
//       register_code(KC_LALT);
//       tap_code(KC_GRAVE);
//       unregister_code(KC_LALT);
//     } else {
//             // when keycode QMKBEST is released
//         }
//     break;
//   case QMKURL:
//         if (record->event.pressed) {
//             // when keycode QMKURL is pressed
//             SEND_STRING("https://qmk.fm/\n");
//         } else {
//             // when keycode QMKURL is released
//         }
//         break;
//   }
//   return true;
// };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LANG_CHANGE:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LALT("`"));
        } else {
            // when keycode QMKBEST is released
        }
        break;

    // case SHIFT_END:
    //     if (record->event.pressed) {
    //         // when keycode QMKURL is pressed
    //       register_code(KC_LSFT);
    //       tap_code(KC_END);
    //     } else {
    //         // when keycode QMKURL is released
    //       unregister_code(KC_LSFT);
    //     }
    //     break;

    // case SHIFT_HOME:
    //     if (record->event.pressed) {
    //         // when keycode QMKURL is pressed
    //         SEND_STRING(SS_LSFT(KC_HOME));
    //     } else {
    //         // when keycode QMKURL is released
    //     }
    //     break;
    }
    return true;
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    C_S_T(KC_Q)     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , C_S_T(KC_P)     ,
    LCTL_T(KC_A)     , C_S_T(KC_S)     , KC_D     , LT(3,KC_F)     , KC_G     ,                            KC_H     , LALT_T(KC_J)     , KC_K     , C_S_T(KC_L)     ,LCTL_T(KC_BSPC)  ,
    LSFT_T(KC_Z)     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , LT(3,KC_M)     , KC_BTN1  , KC_BTN2   , KC_COMMA  ,
    KC_LCTL  , KC_LALT  , KC_LGUI  ,LT(1,KC_TAB),LT(2,KC_SPC),LT(3,KC_ESCAPE), (LANG_CHANGE)  , KC_ENT  , _______  ,_______,_______, LSFT_T(KC_DOT)
  ),

  [1] = LAYOUT_universal(
    S(KC_1)    , S(KC_2)    ,  S(KC_3)   , S(KC_4)    , S(KC_5)  ,                            S(KC_6)      , S(KC_7)       , S(KC_8)    , S(KC_9)    , S(KC_0)   ,
    S(KC_LBRC)    , S(KC_RBRC)  , KC_BACKSLASH  , KC_MINUS , KC_EQUAL  ,              KC_QUOTE     , KC_SEMICOLON  , KC_SLASH  , KC_LBRC  , KC_RBRC  ,
    S(KC_GRAVE), KC_GRAVE ,S(KC_BACKSLASH)   , S(KC_MINUS)  ,S(KC_EQUAL),                     S(KC_QUOTE)  , S(KC_SEMICOLON)   , S(KC_COMMA)  , S(KC_DOT)  , S(KC_SLASH)   ,
    _______  , _______   , _______  , _______  , _______  , _______  ,      _______    , _______    , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    C_S_T(CPI_D1K)   , CPI_D100     , CPI_I100     , CPI_I1K     , _______  ,                 S(KC_8)  , KC_7  , KC_8  , KC_9  , KC_MINUS  ,
    KC_LCTL  , _______     , _______     , KC_BTN3     , _______  ,                            KC_SLASH , KC_4  , KC_5  , KC_6  , S(KC_EQUAL)  ,
    AML_TO  , _______     , _______     , _______    , _______  ,                              KC_0     , KC_1  , KC_2  , KC_3  , KC_EQUAL  ,
    _______   , _______     , _______   , _______   , _______   , _______  ,      S(KC_SEMICOLON)  , KC_DOT  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    KC_F11  , KC_F12 , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______ , _______ ,
    KC_F6   , KC_F7  , LSFT_T(KC_F8)  , KC_F9  , KC_F10 ,                          KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT  , _______  ,
    KC_F1   , KC_F2  , KC_F3  , KC_F4  , KC_F5 ,                                   KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END  , _______ ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , KC_BTN1  , KC_BTN3  , KC_BTN2  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);

        // checks highest layer other than target layer
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 3:
            // remove_auto_mouse_target must be called to adjust state *before* setting enable
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            break;
        default:
            set_auto_mouse_enable(false);
            break;
    }
    
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif


#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif

// #ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
//     switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
//         case 3:
//             state = remove_auto_mouse_layer(state, false);
//             set_auto_mouse_enable(false);
//             break;
//         default:
//             set_auto_mouse_enable(true);
//             break;
//     }
//     #endif

#ifdef COMBO_ENABLE
const uint16_t PROGMEM esc_combo1[] = {LALT_T(KC_J), KC_K, COMBO_END};
const uint16_t PROGMEM del_combo2[] = {KC_L, LCTL_T(KC_BSPC), COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo1, KC_ESC),
    COMBO(del_combo2, KC_DEL),
};
#endif
