#include <stdint.h>

typedef int (*wl_add_fn)(int, int);

struct wl_api {
    int32_t version;
    wl_add_fn add;
};

static int wl_add_impl(int a, int b) {
    return a + b;
}

static const struct wl_api WL_API_INSTANCE = {
    1,
    wl_add_impl,
};

__attribute__((visibility("default"))) const struct wl_api* wl_get_api(void) {
    return &WL_API_INSTANCE;
}
