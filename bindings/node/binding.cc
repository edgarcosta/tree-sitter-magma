#include <napi.h>

typedef struct TSLanguage TSLanguage;

extern "C" TSLanguage *tree_sitter_magma();

// "tree-sitter", "language" hashed with BLAKE2
const napi_type_tag LANGUAGE_TYPE_TAG = {
  0xaa, 0x8c, 0xf5, 0xa4, 0x40, 0x8c, 0xaa, 0x55,
  0x4d, 0xb8, 0x38, 0x46, 0x87, 0x90, 0x3c, 0xb4
};

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports["name"] = Napi::String::New(env, "magma");
    auto language = Napi::External<TSLanguage>::New(env, tree_sitter_magma());
    language.TypeTag(&LANGUAGE_TYPE_TAG);
    exports["language"] = language;
    return exports;
}

NODE_API_MODULE(tree_sitter_magma_binding, Init)