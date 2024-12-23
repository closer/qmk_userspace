#pragma once

#include "tap_dances.h"

enum {
  TD_GUIH = 0,
  SPCCMDT
};

#define KC_GUIH TD(TD_GUIH)

tap_dance_action_t tap_dance_actions[] = {
  [TD_GUIH] = ACTION_TAP_DANCE_MOD_DOUBLE(KC_LGUI, KC_LNG2, KC_LNG1),
  [SPCCMDT] = ACTION_TAP_DANCE_TRIPLE(KC_SPC, KC_COMM, KC_DOT)
};

// Tapping Term Per Key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // IMEの切り替え
    case KC_GUIH:
      return 200;
    default:
      return TAPPING_TERM;
  }
}
