licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_package",
)

envoy_package()

envoy_cc_library(
    name = "vpp_socket_lib",
    srcs = ["vpp_socket.cc"],
    hdrs = ["vpp_socket.h"],
    deps = [
        "//include/envoy/network:transport_socket_interface",
        "//source/common/common:assert_lib",
        "//source/common/common:empty_string",
        "//source/common/common:logger_lib",
        "//source/common/http:headers_lib",
        "@envoy_api//envoy/api/v2/core:base_cc",
    ],
)
