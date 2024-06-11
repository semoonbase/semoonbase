cc_library(
    name = "mockard",
    srcs = [
        "Arduino.cpp",
        "Keyboard.cpp",
    ],
    hdrs = [
        "Arduino.h",
        "Keyboard.h",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        ":keyboard",
    ],
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
