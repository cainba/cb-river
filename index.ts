import { cc } from "bun:ffi";
import waylandCore from "./src/native/wayland-core.c" with { type: "file" };
const { symbols } = cc({
    source: "src/native/wayland-core.c",
    library: [
        "wlroots-0.20/wlr/types/wlr_compositor.h",
        "wayland-client-protocol.h",
        "wayland-client.h",
    ],
    symbols: {
        hello: {
            args: ["napi_env"],
            returns: "napi_value",
        },
    },
    define: {
        WLR_USE_UNSTABLE: "",
    },
});

symbols.hello();
