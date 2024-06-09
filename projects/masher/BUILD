load(
    "@platformio_rules//platformio:platformio.bzl",
    "platformio_project",
)

platformio_project(
    name = "masher",
    src = "src/main.cc",
    board = "leonardo",
    framework = "arduino",
    lib_deps = ["Keyboard"],
    platform = "atmelavr",
    visibility = ["//visibility:public"],
    deps = [
        "//projects/libmasher:avr",
    ],
)
