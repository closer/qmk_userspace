#pragma once

#include "tap_dances.h"

enum {
  TD_GUIH = 0,
  SPCCMDT
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_GUIH] = ACTION_TAP_DANCE_MOD_DOUBLE(KC_LGUI, KC_LNG2, KC_LNG1),
  [SPCCMDT] = ACTION_TAP_DANCE_TRIPLE(KC_SPC, KC_COMM, KC_DOT)
};
