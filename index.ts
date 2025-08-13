import { cc } from "bun:ffi";
import waylandCore from "./src/native/wayland-core.c" with { type: "file" };
const { symbols } = cc({
    source: "src/native/wayland-core.c",
    library: ["wayland-client", "pixman-1"],
    include: [
        "/usr/include/pixman-1",
        "/usr/include/wlroots-0.20",
        "/usr/include/wayland",
    ],
    symbols: {
        hello: {
            args: ["napi_env"],
            returns: "napi_value",
        },
        wl_get_api: {
            args: [],
            returns: "ptr",
        },
    },
    define: {
        WLR_USE_UNSTABLE: "",
    },
});

symbols.hello();
