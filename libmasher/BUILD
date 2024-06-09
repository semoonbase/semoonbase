load(
    "@platformio_rules//platformio:platformio.bzl",
    "platformio_library",
)

platformio_library(
    name = "gpio-avr",
    src = "gpio.cpp",
    hdr = "gpio.h",
    visibility = ["//visibility:public"],
)

platformio_library(
    name = "key-avr",
    src = "key.cpp",
    hdr = "key.h",
    visibility = ["//visibility:public"],
)

platformio_library(
    name = "avr",
    src = "core.cpp",
    hdr = "core.h",
    visibility = ["//visibility:public"],
    deps = [
        ":gpio-avr",
        ":key-avr",
    ],
)

cc_library(
    name = "native",
    srcs = [
        "core.cpp",
        "gpio.cpp",
        "key.cpp",
    ],
    hdrs = [
        "core.h",
        "gpio.h",
        "key.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//mockkey",
    ],
)
