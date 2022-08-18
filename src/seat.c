#include "../inc/seat.h"

void wl_keyboard_keymap(void *data, struct wl_keyboard *wl_keyboard, uint32_t format, int32_t fd, uint32_t size) {
  char *map_shm = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
  xkb_keymap = xkb_keymap_new_from_string(xkb_context, map_shm, XKB_KEYMAP_FORMAT_TEXT_V1, XKB_KEYMAP_COMPILE_NO_FLAGS);
  munmap(map_shm, size);
  close(fd);
  xkb_state = xkb_state_new(xkb_keymap);
}

void wl_keyboard_key(void *data, struct wl_keyboard *wl_keyboard, uint32_t serial, uint32_t time, uint32_t _key, uint32_t state) {
  key(_key + 8, state);
}

void wl_keyboard_modifiers(void *data, struct wl_keyboard *wl_keyboard, uint32_t serial, uint32_t mods_depressed, uint32_t mods_latched, uint32_t mods_locked, uint32_t group) {
  xkb_state_update_mask(xkb_state, mods_depressed, mods_latched, mods_locked, 0, 0, group);
}

void seatCap(void *data, struct wl_seat *wl_seat, uint32_t caps) {
  if (keyboard == NULL && caps & 2) {
    keyboard = wl_seat_get_keyboard(seat);
    wl_keyboard_add_listener(keyboard, &kbListener, NULL);
  }
}
