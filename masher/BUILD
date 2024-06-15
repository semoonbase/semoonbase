load(
    "@platformio_rules//platformio:platformio.bzl",
    "platformio_library",
    "platformio_project",
)

platformio_project(
    name = "masher",
    src = "src/main.cc",
    board = "leonardo",
    framework = "arduino",
    lib_deps = [
        "Keyboard",
    ],
    platform = "atmelavr",
    visibility = ["//visibility:public"],
    deps = [
        ":core",
        ":gpio",
        ":key",
    ],
)

platformio_library(
    name = "core",
    src = "src/core.cc",
    hdr = "src/core.h",
    visibility = ["//visibility:public"],
)

platformio_library(
    name = "gpio",
    src = "src/gpio.cc",
    hdr = "src/gpio.h",
    visibility = ["//visibility:public"],
)

platformio_library(
    name = "key",
    src = "src/key.cc",
    hdr = "src/key.h",
    visibility = ["//visibility:public"],
)

cc_library(
    name = "libmasher",
    srcs = glob(
        ["src/*.cc"],
        exclude = ["src/main.cc"],
    ),
    hdrs = glob(["src/*.h"]),
    includes = ["src"],
    visibility = ["//visibility:public"],
    deps = [
        "//mockard",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "key-test",
    size = "small",
    srcs = [
        "src/key.cc",
    ],
    defines = [
        "UNIT_TEST",
    ],
    deps = [
        ":libmasher",
        "//mockard",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "gpio-test",
    size = "small",
    srcs = [
        "src/gpio.cc",
    ],
    defines = [
        "UNIT_TEST",
    ],
    deps = [
        ":libmasher",
        "//mockard",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "core-test",
    size = "small",
    srcs = [
        "src/core.cc",
    ],
    defines = [
        "UNIT_TEST",
    ],
    deps = [
        ":libmasher",
        "//mockard",
        "@com_google_googletest//:gtest_main",
    ],
)
