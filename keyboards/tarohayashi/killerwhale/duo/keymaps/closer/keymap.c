#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"

#include "closer.h"

// レイヤー名
enum layer_number {
    BASE = 0,
    ONOFF, OFFON, ONON,                  // トグルスイッチで変更するレイヤー
    LOWER, UPPER, ADJUST,                // 長押しで変更するレイヤー
    MOUSE, BALL_SETTINGS, LIGHT_SETTINGS // 自動マウスレイヤー切り替えや設定用のレイヤー
};

enum custom_keycodes {
    UMC_1 = QK_USER_26,
    UMC_2,
    UMC_3,
    UMC_4,
    UMC_5,
    UMC_6,
    UMC_7,
    UMC_8,
    UMC_9,
    UMC_10,
    UMC_11,
    UMC_12
};

#define KC_CTAB LCTL_T(KC_TAB)
#define KC_GUIE LGUI_T(KC_LNG2)
#define KC_GUIH LGUI_T(KC_LNG1)
#define KC_LOWER LT(LOWER, KC_SPC)
#define KC_UPPER LT(UPPER, KC_ENT)
#define KC_ONOFF MO(ONOFF)
#define KC_OFFON MO(OFFON)
#define KC_BALL MO(BALL_SETTINGS)
#define KC_LIGHT MO(LIGHT_SETTINGS)
#define KC_MSCLN LT(MOUSE, KC_SCLN)

// キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,
        KC_CTAB, KC_A,   KC_S,    KC_D,    KC_F,     KC_G,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,
                 UMC_1,  KC_BALL, KC_LALT, KC_GUIE,  KC_LOWER,
                         UMC_2,
        // 側面スイッチ
        UMC_3, UMC_4,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         L_CHMOD,
        // 追加スイッチ                            // トグルスイッチ
        UMC_5, UMC_6,                              KC_ONOFF,

        // 右手
        // 天面スイッチ
        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,      KC_BSPC,
        KC_H,     KC_J,     KC_K,     KC_L,     KC_MSCLN,  KC_QUOT,
        KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_RSFT,
        KC_UPPER, KC_GUIH,  KC_RALT,  KC_LIGHT, UMC_12,
                                      UMC_11,
        // 側面スイッチ
        UMC_9, UMC_10,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,         R_CHMOD,
        // 追加スイッチ                            // トグルスイッチ
        UMC_7, UMC_8,                              KC_OFFON
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
        _______, _______,                            _______
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
        KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    _______,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______,  KC_F12,
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
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
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
        _______, _______,                            _______,
        // 右手
        // 天面スイッチ
        _______, _______, _______, _______, _______, _______,
        _______, KC_MS_BTN1, KC_MS_BTN2, MOD_SCRL, _______, _______,
        JS_2,    JS_3,    _______, _______, _______, _______,
        JS_0,    JS_1,    _______, _______, QK_USER_4,
                                   _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
        _______, _______,                            _______
    ),
    [BALL_SETTINGS] = LAYOUT(
        // 左手
        // 天面スイッチ
        XXXXXXX,    XXXXXXX, XXXXXXX, QK_USER_14, _______, L_CHMOD,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,    L_SPD_I, XXXXXXX,
        AUTO_MOUSE, XXXXXXX, XXXXXXX, L_ANG_D,    L_INV,   L_ANG_I,
                    XXXXXXX, XXXXXXX, XXXXXXX,    L_SPD_D, XXXXXXX,
                             INV_SCRL,
        // 側面スイッチ
        XXXXXXX, XXXXXXX,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                              // トグルスイッチ
        XXXXXXX, INV_SCRL,                           _______,
        // 右手
        // 天面スイッチ
        R_CHMOD, _______, QK_USER_14, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, R_SPD_I, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
        R_ANG_D, R_INV,   R_ANG_I,    XXXXXXX, XXXXXXX, AUTO_MOUSE,
        XXXXXXX, R_SPD_D, XXXXXXX,    XXXXXXX, XXXXXXX,
                                      INV_SCRL,
        // 側面スイッチ
        XXXXXXX, XXXXXXX,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                              // トグルスイッチ
        XXXXXXX, XXXXXXX,                            _______
    ),
    [LIGHT_SETTINGS] = LAYOUT(
        // 左手
        // 天面スイッチ
        XXXXXXX, XXXXXXX, XXXXXXX,  UG_NEXT, UG_PREV, _______,
        XXXXXXX, UG_SPDU, UG_VALU,  UG_SATU, UG_HUEU, UG_TOGG,
        OLED_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 UG_SPDD, UG_VALD,  UG_SATD, UG_HUED, XXXXXXX,
                          QK_USER_15,
        // 側面スイッチ
        UG_NEXT, UG_PREV,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                              // トグルスイッチ
        XXXXXXX, XXXXXXX,                            _______,
        // 右手
        // 天面スイッチ
        _______, UG_NEXT, UG_PREV, XXXXXXX, XXXXXXX, XXXXXXX,
        UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, OLED_MOD,
        XXXXXXX, UG_HUED, UG_SATD, UG_VALD, UG_SPDD,
                                   QK_USER_15,
        // 側面スイッチ
        UG_PREV, UG_NEXT,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                              // トグルスイッチ
        XXXXXXX, XXXXXXX,                            _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, ONOFF, OFFON, ONON);
    state = update_tri_layer_state(state, LOWER, UPPER, ADJUST);
    return state;
}

// altered
bool altered_pressed = false;
bool process_record_altered(uint mod_key, uint16_t keycode, uint16_t alter_key, keyrecord_t *record) {
    if (record->event.pressed) {
        if (get_mods() & MOD_BIT(mod_key)) {
            register_code(alter_key);
            altered_pressed = true;
            return false;
        }
    } else {
        if (altered_pressed) {
            unregister_code(alter_key);
            altered_pressed = false;
            return false;
        }
    }
    return true;
}

// Macros
#define MACRO_NONE 0

const uint16_t PROGMEM macros[] = {
    [UMC_1] = MACRO_NONE,
    [UMC_2] = LCA(KC_R),
    [UMC_3] = LCA(KC_LEFT),
    [UMC_4] = LCA(KC_F),
    [UMC_5] = LCA(KC_RIGHT),
    [UMC_6] = MEH(KC_F),
    [UMC_7] = MACRO_NONE,
    [UMC_8] = MACRO_NONE,
    [UMC_9] = MACRO_NONE,
    [UMC_10] = MACRO_NONE,
    [UMC_11] = MACRO_NONE,
    [UMC_12] = MACRO_NONE,
};

bool process_record_user_macro(uint16_t keycode, keyrecord_t *record) {
    keycode = macros[keycode];
    if (keycode == MACRO_NONE) {
        return false;
    }
    if (record->event.pressed) {
        tap_code16(keycode);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Modified Keycodes
        case KC_ESC:
            return process_record_altered(KC_LCTL, KC_ESC, KC_TAB, record);

        // Macro Keycodes
        case UMC_1 ... UMC_12:
            return process_record_user_macro(keycode, record);
    }
    return true;
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLL, MS_WHLR),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
    },
    [ONOFF] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLL, MS_WHLR),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
    },
    [OFFON] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLL, MS_WHLR),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
    },
    [ONON] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLL, MS_WHLR),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
    },
    [LOWER] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(RGUI(KC_PLUS), RGUI(KC_MINS)),
    },
    [UPPER] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(LCA(KC_EQL), LCA(KC_MINS)),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(RGUI(KC_PLUS), RGUI(KC_MINS)),
    },
    [ADJUST] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(LCA(KC_EQL), LCA(KC_MINS)),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(RGUI(KC_PLUS), RGUI(KC_MINS)),
    },
    [MOUSE] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLL, MS_WHLR),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(MS_WHLU, MS_WHLD),
    },
    [LIGHT_SETTINGS] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(UG_HUEU, UG_HUED),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(UG_HUEU, UG_HUED),
    },
};
