#include "pico/stdlib.h"

#define BTN_PIN 3
#define DEBOUNCE_THRESHOLD 100 // microseconds

bool btn_state = false;
uint64_t last_ts = 0;

void pin_rise_callback () {
  btn_state = gpio_get(BTN_PIN) != 0;
  keep_last_ts();
}

void keep_last_ts () {
  uint64_t at = get_absolute_time();
  last_ts = to_us_since_boot(at);
}

uint64_t get_last_elapsed () {
  uint64_t at = get_absolute_time();
  return to_us_since_boot(at) - last_ts;
}

void main () {
  stdio_usb_init();
  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_down(BTN_PIN);
  gpio_set_irq_enabled_with_callback(BTN_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &pin_rise_callback);

  bool prev_btn_state = true;
  while (true) {
    if(get_last_elapsed() > DEBOUNCE_THRESHOLD && btn_state != prev_btn_state) {
      prev_btn_state = btn_state;
      printf("STATE: %d\n", btn_state);
    }
  }
}
