{
  "targets": [
    {
      "target_name": "tree_sitter_magma_binding",
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "src"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      "defines": [
        "NAPI_DISABLE_CPP_EXCEPTIONS",
      ],
      "sources": [
        "bindings/node/binding.cc",
        "src/parser.c",
        "src/scanner.c",
      ],
      "conditions": [
        ["OS!='win'", {
          "cflags_c": [
            "-std=c99",
          ]
        }],
        ["OS=='win'", {
          "cflags_c": [
            "/std:c99",
          ]
        }],
      ],
      "cflags": [
        "-Wall",
        "-Wextra",
        "-Wno-unused-parameter",
        "-Wno-unused-but-set-variable",
        "-Wno-implicit-fallthrough",
      ],
      "xcode_settings": {
        "OTHER_CFLAGS": [
          "-std=c99",
        ]
      }
    }
  ]
}
