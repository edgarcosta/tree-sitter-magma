# tree-sitter-magma

A tree-sitter parser for the Magma computational algebra language.

## Playground

Try the grammar and the Topiary formatter in your browser:
<https://edgarcosta.github.io/tree-sitter-magma/>

## Installation

```bash
npm install tree-sitter-magma
```

## Usage

### Node.js

```javascript
const Parser = require('tree-sitter');
const Magma = require('tree-sitter-magma');

const parser = new Parser();
parser.setLanguage(Magma);

const sourceCode = `
// Your Magma code here
`;

const tree = parser.parse(sourceCode);
console.log(tree.rootNode.toString());
```

## Development

### Building

```bash
npm run build
```

### Testing

```bash
npm test
```

### Generating the parser

```bash
tree-sitter generate
```

## Contributing

This parser is generated from the existing yacc grammar for Magma. Contributions are welcome!

## lava — community multi-tool

`lava` is a single-binary CLI that bundles this grammar with a Topiary-based
formatter. Future versions will add highlighting, LSP, and MCP servers.

### Install

```bash
# Prebuilt binary (recommended once releases land)
curl --proto '=https' --tlsv1.2 -LsSf \
  https://github.com/edgarcosta/tree-sitter-magma/releases/latest/download/lava-cli-installer.sh | sh

# From source
cargo install --git https://github.com/edgarcosta/tree-sitter-magma lava-cli
```

### Use

```bash
lava format foo.m              # print formatted Magma to stdout
lava format -w foo.m bar.m     # rewrite in place
lava format --check src/       # CI gate; exits 1 if any file would change
lava format -r src/            # walk a directory (respects .gitignore)
echo "x:=1;" | lava fmt        # pipeline-friendly via stdin
```

`lava` ships an embedded `magma.scm` query file. Override with
`--query path/to/your.scm`, `./.lava/magma.scm` (auto-discovered with
git-style walk-up), or `$XDG_CONFIG_HOME/lava/magma.scm`.

### Develop

The Rust workspace lives under `crates/`:

- `crates/lava-core` — library (formatter today, highlight + parse later).
- `crates/lava` — the CLI binary (package `lava-cli`).

`topiary/build.sh` remains the iteration loop for query authors editing
`topiary/magma.scm`. The same file is `include_str!`'d into the binary.

## License

MIT