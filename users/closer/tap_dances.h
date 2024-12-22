#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

typedef struct
{
  uint16_t kc1;
  uint16_t kc2;
  uint16_t kc3;
} tap_dance_triple_t;

#define ACTION_TAP_DANCE_TRIPLE(kc1, kc2, kc3) { \
    .fn = { tap_dance_triple_on_each_tap, tap_dance_triple_finished, tap_dance_triple_reset }, \
    .user_data = (void *)&((tap_dance_triple_t) { kc1, kc2, kc3 }),  \
  }

#define ACTION_TAP_DANCE_MOD_DOUBLE(kc1, kc2, kc3) { \
    .fn = { tap_dance_mod_pair_on_each_tap, tap_dance_mod_pair_finished, tap_dance_mod_pair_reset }, \
    .user_data = (void *)&((tap_dance_triple_t) { kc1, kc2, kc3 }),  \
  }


void tap_dance_triple_on_each_tap (tap_dance_state_t *state, void *user_data);
void tap_dance_triple_finished (tap_dance_state_t *state, void *user_data);
void tap_dance_triple_reset (tap_dance_state_t *state, void *user_data);

void tap_dance_mod_pair_on_each_tap (tap_dance_state_t *state, void *user_data);
void tap_dance_mod_pair_finished (tap_dance_state_t *state, void *user_data);
void tap_dance_mod_pair_reset (tap_dance_state_t *state, void *user_data);
