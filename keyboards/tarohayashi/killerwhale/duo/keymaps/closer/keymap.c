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

// タップ/ホールドの状態
typedef enum {
    STATE_IDLE,       // 待機中
    STATE_PRESSING,   // 押下中（タップ/ホールド判定待ち）
    STATE_HELD,       // ホールド確定
    STATE_TAP_READY,  // タップ確定（リピート待ち）
    STATE_REPEATING   // リピート中
} tap_hold_state_t;

// カスタムタップ/ホールド用の構造体
typedef struct {
    tap_hold_state_t state;    // 現在の状態
    bool is_pressed;           // キーが物理的に押されているか
    uint16_t press_timer;      // キー押下時刻
    uint16_t action_timer;     // アクション用タイマー（リピートなど）
    uint16_t release_timer;    // キー離し時刻
    uint16_t keycode;          // 送信するキーコード
} custom_tap_hold_t;

// 各キーの状態
static custom_tap_hold_t esc_f1_state = {0};
static custom_tap_hold_t bspc_f12_state = {0};

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
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
        KC_CTAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,
        KC_LSFT, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,
                 KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,
                        KC_LALT,
        // 側面スイッチ
        KC_GUIE, KC_LOWER,
        // 十字キーorジョイスティック           // ジョイスティックスイッチ
        KC_W, KC_S, KC_A, KC_D,      L_CHMOD,
        // 追加スイッチ                         // トグルスイッチ
        XXXXXXX, KC_GLB,                        KC_ONOFF,

        // 右手
        // 天面スイッチ
        KC_F7, KC_F8, KC_F9,   KC_F10, KC_F11,   KC_F12,
        KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,     KC_MQUOT,
        KC_H,  KC_J,  KC_K,    KC_L,   KC_MSCLN, KC_RSFT,
        KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                               KC_RALT,

        // 側面スイッチ
        KC_UPPER, KC_GUIH,
        // 十字キーorジョイスティック            // ジョイスティックスイッチ
        KC_UP, KC_DOWN, KC_LEFT, KC_RIGHT,       R_CHMOD,
        // 追加スイッチ                          // トグルスイッチ
        XXXXXXX, KC_SETNG,                     KC_OFFON
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
        _______,   _______, _______, _______, _______, _______,
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
        _______, _______, _______, _______, _______, _______,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
        KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
        KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS,
                                   _______,
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

// タップキーの修飾（Ctrl+ESC → Tab変換）
static uint16_t get_modified_tap_key(uint16_t tap_key) {
    if (tap_key == KC_ESC && (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)))) {
        return KC_TAB;
    }
    return tap_key;
}

// キーが離されている場合の共通処理
static inline void transition_to_idle_if_released(custom_tap_hold_t *state) {
    if (!state->is_pressed) {
        state->state = STATE_IDLE;
    }
}

// ホールド確定への遷移
static void try_transition_to_held(custom_tap_hold_t *state, uint16_t hold_key) {
    if (timer_elapsed(state->press_timer) > TAPPING_TERM) {
        state->state = STATE_HELD;
        state->keycode = hold_key;
        register_code(hold_key);
    }
}

// リピート処理の実行
static void try_start_or_continue_repeat(custom_tap_hold_t *state, uint16_t repeat_delay) {
    if (timer_elapsed(state->action_timer) > repeat_delay) {
        if (state->state == STATE_TAP_READY) {
            state->state = STATE_REPEATING;
        }
        tap_code(state->keycode);
        state->action_timer = timer_read();
    }
}

// 状態マシン処理（汎用）
static void update_tap_hold_state(custom_tap_hold_t *state, uint16_t tap_key, uint16_t hold_key) {
    switch (state->state) {
        case STATE_IDLE:
        case STATE_HELD:
            // 何もしない
            break;

        case STATE_PRESSING:
            if (state->is_pressed) {
                try_transition_to_held(state, hold_key);
            }
            break;

        case STATE_TAP_READY:
            if (state->is_pressed) {
                try_start_or_continue_repeat(state, KEY_REPEAT_DELAY);
            } else {
                transition_to_idle_if_released(state);
            }
            break;

        case STATE_REPEATING:
            if (state->is_pressed) {
                try_start_or_continue_repeat(state, KEY_REPEAT_INTERVAL);
            } else {
                transition_to_idle_if_released(state);
            }
            break;
    }
}

// 連打継続の判定
static bool should_continue_tapping(const custom_tap_hold_t *state, uint16_t current_time) {
    return state->release_timer > 0 &&
           (current_time - state->release_timer) < TAP_CONTINUE_THRESHOLD &&
           (state->state == STATE_TAP_READY || state->state == STATE_IDLE);
}

// キー押下時の状態初期化（連打継続の場合）
static void init_tap_continuation(custom_tap_hold_t *state, uint16_t current_time) {
    state->state = STATE_TAP_READY;
    state->press_timer = current_time;
    state->action_timer = current_time;
    // keycodeは保持（Tabの場合はTabのまま）

    // 連打中は即座にタップを送信
    tap_code(state->keycode);
}

// キー押下時の状態初期化（新規セッションの場合）
static void init_new_tap_session(custom_tap_hold_t *state, uint16_t current_time) {
    state->state = STATE_PRESSING;
    state->press_timer = current_time;
    state->action_timer = 0;
    state->keycode = 0;
}

// キー押下時の処理
static void handle_key_press(custom_tap_hold_t *state) {
    state->is_pressed = true;
    uint16_t current_time = timer_read();

    if (should_continue_tapping(state, current_time)) {
        init_tap_continuation(state, current_time);
    } else {
        init_new_tap_session(state, current_time);
    }
    state->release_timer = 0;
}

// タップ完了時の処理
static void handle_tap_completion(custom_tap_hold_t *state, uint16_t tap_key, uint16_t current_time) {
    uint16_t modified_key = get_modified_tap_key(tap_key);
    tap_code(modified_key);

    state->state = STATE_TAP_READY;
    state->keycode = modified_key;
    state->action_timer = current_time;
}

// ホールド解放時の処理
static void handle_hold_release(custom_tap_hold_t *state) {
    unregister_code(state->keycode);
    state->state = STATE_IDLE;
}

// キー解放時の処理
static void handle_key_release(custom_tap_hold_t *state, uint16_t tap_key) {
    state->is_pressed = false;
    uint16_t current_time = timer_read();

    switch (state->state) {
        case STATE_PRESSING:
            handle_tap_completion(state, tap_key, current_time);
            break;

        case STATE_HELD:
            handle_hold_release(state);
            break;

        case STATE_TAP_READY:
        case STATE_REPEATING:
            // 連打継続のため状態は保持（update_tap_hold_stateでIDLEに遷移）
            break;

        default:
            state->state = STATE_IDLE;
            break;
    }

    state->release_timer = current_time;
}

// タップ/ホールド処理（汎用）
static bool process_tap_hold_key(custom_tap_hold_t *state, uint16_t tap_key, uint16_t hold_key, keyrecord_t *record) {
    if (record->event.pressed) {
        handle_key_press(state);
    } else {
        handle_key_release(state, tap_key);
    }
    return false;
}

void matrix_scan_user(void) {
    // 各キーの状態更新
    update_tap_hold_state(&esc_f1_state, KC_ESC, KC_F1);
    update_tap_hold_state(&bspc_f12_state, KC_BSPC, KC_F12);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F1:
            return process_tap_hold_key(&esc_f1_state, KC_ESC, KC_F1, record);

        case KC_F12:
            return process_tap_hold_key(&bspc_f12_state, KC_BSPC, KC_F12, record);
    }

    if (layer_state_is(HYPER)) {
        if (record->event.pressed) {
            add_mods(MOD_HYPR);
        } else {
            del_mods(MOD_HYPR);
        }
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
