cc_library(
    name = "mockard",
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        ":arduino",
        ":keyboard",
    ],
)

cc_library(
    name = "arduino",
    srcs = [
        "Arduino.cpp",
    ],
    hdrs = [
        "Arduino.h",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "keyboard",
    srcs = [
        "Keyboard.cpp",
    ],
    hdrs = [
        "Keyboard.h",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
)
