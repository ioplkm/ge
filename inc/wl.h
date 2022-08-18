#include <string.h>

#include <wayland-client.h>
#include <xkbcommon/xkbcommon.h>

#include "xdg-shell.h"
#include "shm.h"

#define width 1920
#define height 1080
int stride = width * 4;
int size = width * 4 * height;

int fd;
uint32_t *data;

struct wl_display *wl_display;
struct wl_registry *wl_registry;
struct wl_shm *wl_shm;
struct wl_shm_pool *pool;
struct wl_buffer *buffer;
struct wl_compositor *wl_compositor;
struct wl_surface *wl_surface;
struct xdg_wm_base *xdg_wm_base;
struct xdg_surface *xdg_surface;
struct xdg_toplevel *xdg_toplevel;
struct wl_callback *callback;

extern struct wl_seat *seat;
extern struct wl_seat_listener seatListener;
extern struct xkb_context *xkb_context;

void bufRelease(void *data, struct wl_buffer *wl_buffer);

struct wl_buffer_listener bufListener = {bufRelease};

void surfaceConf(void *data, struct xdg_surface *xdg_surface, uint32_t serial);

struct xdg_surface_listener surfaceListener = {surfaceConf};

void xdgPing(void *data, struct xdg_wm_base *xdg_wm_base, uint32_t serial);

struct xdg_wm_base_listener xdgListener = {xdgPing};

void regAdd(void *data, struct wl_registry *wl_registry, uint32_t name, const char *interface, uint32_t version);

void regDel(void *data, struct wl_registry *wl_registry, uint32_t name);

struct wl_registry_listener regListener = {regAdd, regDel};

struct wl_callback_listener surfaceFrameListener;

void surfaceCallback(void *data, struct wl_callback *callback, uint32_t time);

struct wl_callback_listener surfaceFrameListener = {surfaceCallback};

uint32_t *init();

void end();
