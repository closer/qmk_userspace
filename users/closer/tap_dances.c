#include "tap_dances.h"

#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"

void tap_dance_triple_on_each_tap (tap_dance_state_t *state, void *user_data) {
  tap_dance_triple_t *triple = (tap_dance_triple_t *)user_data;

  if (state->count == 3) {
    register_code16 (triple->kc3);
    state->finished = true;
  }
}

void tap_dance_triple_finished (tap_dance_state_t *state, void *user_data) {
  tap_dance_triple_t *triple = (tap_dance_triple_t *)user_data;

  if (state->count == 1) {
    register_code16 (triple->kc1);
  } else if (state->count == 2) {
    register_code16 (triple->kc2);
  } else if (state->count == 3) {
    register_code16 (triple->kc3);
  }
}

void tap_dance_triple_reset (tap_dance_state_t *state, void *user_data) {
  tap_dance_triple_t *triple = (tap_dance_triple_t *)user_data;

  if (state->count == 1) {
    unregister_code16 (triple->kc1);
  } else if (state->count == 2) {
    unregister_code16 (triple->kc2);
  } else if (state->count == 3) {
    unregister_code16 (triple->kc3);
  }
}

void tap_dance_mod_pair_on_each_tap (tap_dance_state_t *state, void *user_data) {
  tap_dance_triple_t *triple = (tap_dance_triple_t *)user_data;

  if (state->count == 2) {
    unregister_code16 (triple->kc1);
    register_code16 (triple->kc3);
    state->finished = true;
    return;
  }

  register_code16 (triple->kc1);
}

void tap_dance_mod_pair_finished (tap_dance_state_t *state, void *user_data) {
  tap_dance_triple_t *triple = (tap_dance_triple_t *)user_data;

  if (!state->pressed) {
    unregister_code16 (triple->kc1);
    if (state->count == 1) {
      register_code16 (triple->kc2);
    } else if (state->count == 2) {
      register_code16 (triple->kc3);
    }
  }
}

void tap_dance_mod_pair_reset (tap_dance_state_t *state, void *user_data) {
  tap_dance_triple_t *triple = (tap_dance_triple_t *)user_data;

  unregister_code16 (triple->kc1);

  if (state->count == 1) {
    unregister_code16 (triple->kc2);
  } else if (state->count == 2) {
    unregister_code16 (triple->kc3);
  }
}

void tap_dance_tap_hold_finished (tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
  if (state->pressed) {
    // 長押し
    tap_hold->is_held = true;
    register_code16 (tap_hold->hold_keycode);
  } else {
    // タップ
    tap_hold->is_held = false;
    // Ctrl+Escapeの場合はTabを送信
    if (tap_hold->tap_keycode == KC_ESC && (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))) {
      tap_hold->pressed_keycode = KC_TAB;
      register_code16 (KC_TAB);
    } else {
      tap_hold->pressed_keycode = tap_hold->tap_keycode;
      register_code16 (tap_hold->tap_keycode);
    }
  }
}

void tap_dance_tap_hold_reset (tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
  if (tap_hold->is_held) {
    unregister_code16 (tap_hold->hold_keycode);
    tap_hold->is_held = false;
  } else {
    unregister_code16 (tap_hold->pressed_keycode);
  }
}

// タップ優先版: 2回目以降のタップを検出したら即座にタップキーを送る
void tap_dance_tap_hold_prefer_tap_on_each_tap (tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  // 2回目以降のタップは即座にタップキーを送信して終了
  if (state->count >= 2) {
    tap_hold->is_held = false;
    tap_hold->pressed_keycode = tap_hold->tap_keycode;
    register_code16 (tap_hold->tap_keycode);
    state->finished = true;
  }
}

void tap_dance_tap_hold_prefer_tap_finished (tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  // 2回目以降のタップは on_each_tap で処理済み
  if (state->count >= 2) {
    return;
  }

  // 1回目のみ：長押しならホールドキー、タップならタップキー
  if (state->pressed) {
    // 長押し
    tap_hold->is_held = true;
    register_code16 (tap_hold->hold_keycode);
  } else {
    // タップ
    tap_hold->is_held = false;
    // Ctrl+Escapeの場合はTabを送信
    if (tap_hold->tap_keycode == KC_ESC && (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))) {
      tap_hold->pressed_keycode = KC_TAB;
      register_code16 (KC_TAB);
    } else {
      tap_hold->pressed_keycode = tap_hold->tap_keycode;
      register_code16 (tap_hold->tap_keycode);
    }
  }
}
