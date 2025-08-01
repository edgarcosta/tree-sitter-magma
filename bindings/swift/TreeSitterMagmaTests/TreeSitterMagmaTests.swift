import XCTest
import SwiftTreeSitter
import TreeSitterMagma

final class TreeSitterMagmaTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_magma())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Magma grammar")
    }
}
