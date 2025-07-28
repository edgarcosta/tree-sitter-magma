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