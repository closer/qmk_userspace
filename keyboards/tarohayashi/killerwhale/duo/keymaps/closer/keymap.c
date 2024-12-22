#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"

#include "closer.h"

// レイヤー名
enum layer_number {
    BASE = 0,
    LOWER, UPPER, ADJUST,                // 長押しで変更するレイヤー
    ONOFF, OFFON, ONON,                  // トグルスイッチで変更するレイヤー
    MOUSE, BALL_SETTINGS, LIGHT_SETTINGS // 自動マウスレイヤー切り替えや設定用のレイヤー
};

enum custom_keycodes {
    C_LOWER = QK_USER,
    C_UPPER,
    C_LTGL,
    C_RTGL,
    C_BALL,
    C_LIGHT,
    MACR01,
    MACR02,
    MACR03,
    MACR04,
    MACR05,
    MACR06,
    MACR07,
    MACR08,
    MACR09,
    MACR10,
    MACR11,
    MACR12,
};

#define KC_GUIH TD(TD_GUIH)

// キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_ESC,        KC_Q,   KC_W,   KC_E,    KC_R,     KC_T,
        CTL_T(KC_TAB), KC_A,   KC_S,   KC_D,    KC_F,     KC_H,
        KC_LSFT,       KC_Z,   KC_X,   KC_C,    KC_V,     KC_B,
                       MACR01, C_BALL, KC_LALT, KC_GUIH,  LT(LOWER, KC_SPC),
                               MACR02,
        // 側面スイッチ
        MACR03, MACR04,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         L_CHMOD,
        // 追加スイッチ                            // トグルスイッチ
        MACR05, MACR06,                            C_LTGL,

        // 右手
        // 天面スイッチ
        KC_Y,              KC_U,     KC_I,     KC_O,    KC_P,                KC_BSPC,
        KC_H,              KC_J,     KC_K,     KC_L,    MT(MOUSE, KC_SCLN),  KC_QUOT,
        KC_N,              KC_M,     KC_M,     KC_COMM, KC_SLSH,             KC_RSFT,
        LT(UPPER, KC_ENT), KC_RGUI,  KC_RALT,  C_LIGHT, MACR12,
                                               MACR11,
        // 側面スイッチ
        MACR09, MACR10,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         R_CHMOD,
        // 追加スイッチ                            // トグルスイッチ
        MACR07, MACR08,                            C_RTGL
    ),
    [LOWER] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        _______, _______, _______, _______, KC_MPLY, KC_MFFD,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,        _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                          _______,
        // 右手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_F12,
                                   KC_F11,
        // 側面スイッチ
        KC_F9,   KC_F10,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,        _______,
        // 追加スイッチ                            // トグルスイッチ
        KC_F7,   KC_F8,                            _______
    ),
    [UPPER] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 KC_F1,   _______, _______, _______, _______,
                          KC_F2,
        // 側面スイッチ
        KC_F3,   KC_F4,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,        _______,
        // 追加スイッチ                            // トグルスイッチ
        KC_F5,   KC_F6,                            _______,
        // 右手
        // 天面スイッチ
        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
        KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
        _______, _______, _______, _______, _______,
                                   _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______
    ),
    [ADJUST] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______,
        // 右手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                   _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______
    ),
    [ONOFF] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______,
        // 右手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                   _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______
    ),
    [OFFON] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______,
        // 右手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                   _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______
    ),
    [ONON] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______,
        // 右手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                   _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______
    ),
    [MOUSE] = LAYOUT(
        // 左手
        // 天面スイッチ
        _______, _______, _______, _______, _______,    _______,
        _______, _______, MOD_SCRL, KC_MS_BTN2, KC_MS_BTN1, _______,
        _______, _______, _______, _______, _______,    _______,
                 QK_USER_4, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______,
        // 右手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, KC_MS_BTN1, KC_MS_BTN2, MOD_SCRL, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, QK_USER_4,
                                   _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                            _______
    ),
    [BALL_SETTINGS] = LAYOUT(
        // 左手
        // 天面スイッチ
        XXXXXXX,    XXXXXXX, XXXXXXX, QK_USER_14, _______, L_CHMOD,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, L_SPD_I, XXXXXXX,
        AUTO_MOUSE, XXXXXXX, XXXXXXX, L_ANG_D, L_INV,   L_ANG_I,
                    XXXXXXX, XXXXXXX,XXXXXXX, L_SPD_D, XXXXXXX,
                             INV_SCRL,
        // 側面スイッチ
        XXXXXXX, XXXXXXX,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                            // トグルスイッチ
        XXXXXXX, INV_SCRL,                           XXXXXXX,
        // 右手
        // 天面スイッチ
        R_CHMOD, _______, QK_USER_14, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, R_SPD_I,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        R_ANG_D, R_INV,   R_ANG_I, XXXXXXX, XXXXXXX, AUTO_MOUSE,
        XXXXXXX, R_SPD_D,   XXXXXXX, XXXXXXX, XXXXXXX,
                                     INV_SCRL,
        // 側面スイッチ
        XXXXXXX, XXXXXXX,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                            // トグルスイッチ
        XXXXXXX, XXXXXXX,                            XXXXXXX
    ),
    [LIGHT_SETTINGS] = LAYOUT(
        // 左手
        // 天面スイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, UG_NEXT, UG_PREV, _______,
        XXXXXXX, UG_SPDU, UG_VALU, UG_SATU, UG_HUEU, UG_TOGG,
        OLED_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 UG_SPDD, UG_VALD, UG_SATD, UG_HUED, XXXXXXX,
                          QK_USER_15,
        // 側面スイッチ
        UG_NEXT, UG_PREV,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                            // トグルスイッチ
        XXXXXXX, XXXXXXX,                            XXXXXXX,
        // 右手
        // 天面スイッチ
        _______, UG_NEXT, UG_PREV, XXXXXXX, XXXXXXX, XXXXXXX,
        UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OLED_MOD,
        XXXXXXX, UG_HUED, UG_SATD, UG_VALD, UG_SPDD,
                                   QK_USER_15,
        // 側面スイッチ
        UG_PREV, UG_NEXT,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                            // トグルスイッチ
        XXXXXXX, XXXXXXX,                            XXXXXXX
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC:
            if (record->event.pressed) {
                if (get_mods() == MOD_BIT(KC_LCTL)) {
                    register_code(KC_TAB);
                }
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        case C_LOWER:
            if (record->event.pressed) {
                layer_on(LOWER);
                update_tri_layer(LOWER, UPPER, ADJUST);
            } else {
                layer_off(LOWER);
                update_tri_layer(LOWER, UPPER, ADJUST);
            }
            break;
        case C_UPPER:
            if (record->event.pressed) {
                layer_on(UPPER);
                update_tri_layer(LOWER, UPPER, ADJUST);
            } else {
                layer_off(UPPER);
                update_tri_layer(LOWER, UPPER, ADJUST);
            }
            break;
        case C_LTGL:
            if (record->event.pressed) {
                layer_on(ONOFF);
                update_tri_layer(ONOFF, OFFON, ONON);
            } else {
                layer_off(ONOFF);
                update_tri_layer(ONOFF, OFFON, ONON);
            }
            break;
        case C_RTGL:
            if (record->event.pressed) {
                layer_on(OFFON);
                update_tri_layer(ONOFF, OFFON, ONON);
            } else {
                layer_off(OFFON);
                update_tri_layer(ONOFF, OFFON, ONON);
            }
            break;
        case C_BALL:
            if (record->event.pressed) {
                layer_on(BALL_SETTINGS);
            } else {
                layer_off(BALL_SETTINGS);
            }
            break;
        case C_LIGHT:
            if (record->event.pressed) {
                layer_on(LIGHT_SETTINGS);
            } else {
                layer_off(LIGHT_SETTINGS);
            }
            break;
        case MACR01:
            if (record->event.pressed) {
                SEND_STRING("macro01");
            }
            break;
        case MACR02:
            if (record->event.pressed) {
                SEND_STRING("macro02");
            }
            break;
        case MACR03:
            if (record->event.pressed) {
                SEND_STRING("macro03");
            }
            break;
        case MACR04:
            if (record->event.pressed) {
                SEND_STRING("macro04");
            }
            break;
        case MACR05:
            if (record->event.pressed) {
                SEND_STRING("macro05");
            }
            break;
        case MACR06:
            if (record->event.pressed) {
                SEND_STRING("macro06");
            }
            break;
        case MACR07:
            if (record->event.pressed) {
                SEND_STRING("macro07");
            }
            break;
        case MACR08:
            if (record->event.pressed) {
                SEND_STRING("macro08");
            }
            break;
        case MACR09:
            if (record->event.pressed) {
                SEND_STRING("macro09");
            }
            break;
        case MACR10:
            if (record->event.pressed) {
                SEND_STRING("macro10");
            }
            break;
        case MACR11:
            if (record->event.pressed) {
                SEND_STRING("macro11");
            }
            break;
        case MACR12:
            if (record->event.pressed) {
                SEND_STRING("macro12");
            }
            break;
    }
    return true;
}
