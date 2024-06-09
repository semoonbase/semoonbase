load(
    "@platformio_rules//platformio:platformio.bzl",
    "platformio_library",
)

platformio_library(
    name = "avr",
    src = "core.cpp",
    hdr = "core.h",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "native",
    srcs = [
        "src/core.cpp",
        "src/gpio.cpp",
        "src/key.cpp",
    ],
    hdrs = [
        "src/core.h",
        "src/gpio.h",
        "src/key.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//projects/mockkey",
    ],
)
