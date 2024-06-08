load(
    "@platformio_rules//platformio:platformio.bzl",
    "platformio_library",
)

platformio_library(
    name = "core",
    hdr = "core.h",
    src = "core.cpp",
    deps = [
        "//projects/masher/lib/key:key",
        "//projects/masher/lib/gpio:gpio"
    ],
    visibility = ["//visibility:public"],
)