#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"

#include "closer.h"

// レイヤー名
enum layer_number {
    BASE = 0,
    ONOFF, OFFON, ONON,  // トグルスイッチで変更するレイヤー
    LOWER, UPPER, HYPER, // 長押しで変更するレイヤー
    MOUSE, SETTINGS      // 自動マウスレイヤー切り替えや設定用のレイヤー
};

#define KC_CTAB LCTL_T(KC_TAB)
#define KC_GUIE LGUI_T(KC_LNG2)
#define KC_GUIH LGUI_T(KC_LNG1)
#define KC_SQUOT RSFT_T(KC_QUOTE)
#define KC_LOWER LT(LOWER, KC_SPC)
#define KC_UPPER LT(UPPER, KC_ENT)
#define KC_ONOFF MO(ONOFF)
#define KC_OFFON MO(OFFON)
#define KC_SETNG MO(SETTINGS)
#define KC_MSCLN LT(MOUSE, KC_SCLN)
#define KC_MQUOT LT(MOUSE, KC_QUOTE)

// キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_ESC,  KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
        KC_CTAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,
        KC_LSFT, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,
                 KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,
                        KC_LALT,
        // 側面スイッチ
        KC_GUIE, KC_LOWER,
        // 十字キーorジョイスティック           // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,      L_CHMOD,
        // 追加スイッチ                         // トグルスイッチ
        KC_CAPS, KC_GLB,                        KC_ONOFF,

        // 右手
        // 天面スイッチ
        KC_F7, KC_F8, KC_F9,   KC_F10, KC_F11,   KC_F12,
        KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,     KC_BSPC,
        KC_H,  KC_J,  KC_K,    KC_L,   KC_MSCLN, KC_RSFT,
        KC_N,  KC_M,  KC_COMM, KC_DOT, KC_MQUOT,
                               KC_SLSH,

        // 側面スイッチ
        KC_UPPER, KC_GUIH,
        // 十字キーorジョイスティック            // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,       R_CHMOD,
        // 追加スイッチ                          // トグルスイッチ
        KC_LAL KC_SETNG,                       KC_OFFON
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
        _______, _______, _______, _______,      _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                        _______,
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
        _______, _______, _______, _______,      _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                        _______
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
        _______, _______, _______, _______,      _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                        _______,
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
        _______, _______, _______, _______,      _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                        _______
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
        _______, _______, _______, _______,      _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                        _______,
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
        _______, _______, _______, _______,      _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                        _______
    ),
    [LOWER] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        _______, _______, _______, _______, KC_MPLY, KC_MFFD,
                 _______, _______, _______, _______, _______,
                          _______,

        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,    _______,
        // 追加スイッチ                          // トグルスイッチ
        _______, _______,                        _______,
        // 右手
        // 天面スイッチ
        KC_F19,  KC_F20,  KC_F21,  KC_F22,   KC_F23,  KC_F24,
        KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    _______,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        _______, _______, _______, _______,  _______,
                                   _______,

        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,        _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                          _______
    ),
    [UPPER] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_F1,   _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
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
        _______, _______, _______, _______, _______, KC_F12,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
        KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_GRV,
                                   KC_BSLS,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック              // ジョイスティックスイッチ
        _______, _______, _______, _______,        _______,
        // 追加スイッチ                            // トグルスイッチ
        _______, _______,                          _______
    ),
    [HYPER] = LAYOUT(
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
        _______, MS_BTN1, MS_BTN2, MOD_SCRL,_______, _______,
        _______, MS_BTN3, _______, _______, QK_USER_4,
                                   _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                              // トグルスイッチ
        _______, _______,                            _______
    ),
    [SETTINGS] = LAYOUT(
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
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, ONOFF, OFFON, ONON);
    if (layer_state_cmp(state, ONON)) {
        state &= ~(1UL << ONOFF);
        state &= ~(1UL << OFFON);
    }

    state = update_tri_layer_state(state, LOWER, UPPER, HYPER);
    if (layer_state_cmp(state, HYPER)) {
        state &= ~(1UL << LOWER);
        state &= ~(1UL << UPPER);
    }

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(HYPER)) {
        if (record->event.pressed) {
            add_mods(MOD_HYPR);
        } else {
            del_mods(MOD_HYPR);
        }
    }

    switch (keycode) {
        // Modified Keycodes
        case KC_ESC:
            return process_record_altered(KC_LCTL, KC_ESC, KC_TAB, record);
    }
    return true;
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB)),
    },
    [ONOFF] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB)),
    },
    [OFFON] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB)),
    },
    [ONON] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB)),
    },
    [LOWER] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(RGUI(KC_PLUS), RGUI(KC_MINS)),
    },
    [UPPER] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_MNXT, KC_MPRV),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_VOLU, KC_VOLD),
    },
    [HYPER] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_MNXT, KC_MPRV),
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
    [SETTINGS] =   {
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(UG_HUEU, UG_HUED),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(R_SPD_I, R_SPD_D),
    },
};
