#ifndef KBD_H
#define KBD_H

#include <unistd.h>
#include <sys/mman.h>
#include <wayland-client.h>
#include <xkbcommon/xkbcommon.h>
struct wl_seat *seat;
struct wl_keyboard *keyboard;
struct xkb_state *xkb_state;
struct xkb_context *xkb_context;
struct xkb_keymap *xkb_keymap;

void wl_keyboard_keymap(void *data, struct wl_keyboard *wl_keyboard, uint32_t format, int32_t fd, uint32_t size);

void wl_keyboard_enter(void *data, struct wl_keyboard *wl_keyboard, uint32_t serial, struct wl_surface *surface, struct wl_array *keys) { }

void key(uint32_t key, uint8_t state);

void wl_keyboard_key(void *data, struct wl_keyboard *wl_keyboard, uint32_t serial, uint32_t time, uint32_t key, uint32_t state);

void wl_keyboard_leave(void *data, struct wl_keyboard *wl_keyboard, uint32_t serial, struct wl_surface *surface) {}

void wl_keyboard_modifiers(void *data, struct wl_keyboard *wl_keyboard, uint32_t serial, uint32_t mods_depressed, uint32_t mods_latched, uint32_t mods_locked, uint32_t group);

void wl_keyboard_repeat_info(void *data, struct wl_keyboard *wl_keyboard, int32_t rate, int32_t delay) { }

struct wl_keyboard_listener kbListener = {wl_keyboard_keymap, wl_keyboard_enter, wl_keyboard_leave, wl_keyboard_key, wl_keyboard_modifiers, wl_keyboard_repeat_info};

void seatCap(void *data, struct wl_seat *wl_seat, uint32_t caps);

void seatName(void *data, struct wl_seat *wl_seat, const char *name) {}

struct wl_seat_listener seatListener = {seatCap, seatName};

#endif
