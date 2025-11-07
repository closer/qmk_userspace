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
    register_code16 (tap_hold->tap_keycode);
  }
}

void tap_dance_tap_hold_reset (tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;
  if (tap_hold->is_held) {
    unregister_code16 (tap_hold->hold_keycode);
    tap_hold->is_held = false;
  } else {
    unregister_code16 (tap_hold->tap_keycode);
  }
}
