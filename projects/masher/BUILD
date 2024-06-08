load(
    "@platformio_rules//platformio:platformio.bzl",
    "platformio_project",
)

platformio_project(
    name = "masher",
    board = "leonardo",
    src = "src/main.cc",
    framework = "arduino",
    platform = "atmelavr",
    deps = [
        "//projects/masher/lib/core:core",
    ],
    lib_deps = ["Keyboard"],
    visibility = ["//visibility:public"],
)