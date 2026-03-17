# tree-sitter-magma

A tree-sitter parser for the Magma computational algebra language.

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

### Neovim (nvim-treesitter)

Add the parser to your nvim-treesitter config:

```lua
local parser_config = require("nvim-treesitter.parsers").get_parser_configs()
parser_config.magma = {
    install_info = {
        url = "https://github.com/edgarcosta/tree-sitter-magma",
        files = {"src/parser.c", "src/scanner.c"},
    },
    filetype = "magma",
}
```

Then register the `.m` filetype (in your `init.lua` or `ftdetect/magma.lua`):

```lua
vim.filetype.add({
    extension = {
        m = function(path, bufnr)
            -- Check for Magma indicators: intrinsic, end function, freeze, etc.
            local content = vim.api.nvim_buf_get_lines(bufnr, 0, 30, false)
            for _, line in ipairs(content) do
                if line:match("^freeze") or line:match("^intrinsic")
                    or line:match("end function") or line:match("end procedure")
                    or line:match("end intrinsic") then
                    return "magma"
                end
            end
            -- Fall back to default (MATLAB/Objective-C)
            return nil
        end,
    },
    pattern = {
        ["*.magma"] = "magma",
    },
})
```

Install the parser:

```vim
:TSInstall magma
```

**Features:** syntax highlighting, code folding (`queries/folds.scm`), indentation (`queries/indents.scm`), textobjects (`queries/textobjects.scm`).

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

## License

MIT