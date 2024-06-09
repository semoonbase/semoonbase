load(
    "@platformio_rules//platformio:platformio.bzl",
    "platformio_library",
)

platformio_library(
    name = "avr",
    hdr = "core.h",
    src = "core.cpp",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "native",
    hdrs = ["src/core.h", "src/gpio.h", "src/key.h"],
    srcs = ["src/core.cpp", "src/gpio.cpp", "src/key.cpp"],
    deps = [
        "//projects/mockkey:mockkey",
    ],
    visibility = ["//visibility:public"],
)