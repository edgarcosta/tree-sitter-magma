{
  "targets": [
    {
      "target_name": "tree_sitter_magma_binding",
      "include_dirs": [
        "<!(node -e \"console.log(require('node-addon-api').include)\")",
        "src"
      ],
      "dependencies": [
        "<!(node -e \"console.log(require('node-addon-api').gyp)\")"
      ],
      "sources": [
        "bindings/node/binding.cc",
        "src/parser.c",
        # NOTE: if your language has an external scanner, add it here.
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