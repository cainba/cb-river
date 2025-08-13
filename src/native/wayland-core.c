#include <node/js_native_api.h>
#include <node/js_native_api_types.h>
#include <node/node_api.h>
#include <stdint.h>

#define WLR_USE_UNSTABLE
#include <pixman-1/pixman.h>
#include <wayland-client.h>
#include <wayland-client-protocol.h>
#include <wlroots-0.20/wlr/types/wlr_compositor.h>

typedef int (*wl_add_fn)(int, int);
typedef struct wl_display* (*wl_connect_fn)(const char*);
typedef void (*wl_disconnect_fn)(struct wl_display*);
typedef struct wl_registry* (*wl_get_registry_fn)(struct wl_display*);

struct wl_api {
    int32_t version;
    wl_add_fn add;
    wl_connect_fn connect;
    wl_disconnect_fn disconnect;
    wl_get_registry_fn get_registry;
};

static int wl_add_impl(int a, int b) {
    return a + b;
}

static struct wl_display* wl_connect_impl(const char* name) {
    return wl_display_connect(name);
}

static void wl_disconnect_impl(struct wl_display* display) {
    wl_display_disconnect(display);
}

static struct wl_registry* wl_get_registry_impl(struct wl_display* display) {
    return wl_display_get_registry(display);
}

static const struct wl_api WL_API_INSTANCE = {
    1,
    wl_add_impl,
    wl_connect_impl,
    wl_disconnect_impl,
    wl_get_registry_impl,
};

__attribute__((visibility("default"))) const struct wl_api* wl_get_api(void) {
    return &WL_API_INSTANCE;
}

napi_value hello(napi_env env) {
    napi_value result;
    napi_create_object(env, &result);
    return result;
}
