import { cc, ptr } from "bun:ffi"
import waylandCore from "../native/wayland-core.c" with { type: "file" }

const { symbols } = cc({
    source: waylandCore,
    library: ["wayland-client", "pixman-1"],
    include: [
        "/usr/include/pixman-1",
        "/usr/include/wlroots-0.20",
        "/usr/include/wayland",
    ],
    symbols: {
        hello: {
            args: ["ptr"],
            returns: "ptr",
        },
        wl_get_api: {
            args: [],
            returns: "ptr",
        },
    },
    define: {
        WLR_USE_UNSTABLE: "",
    },
})

export default symbols
