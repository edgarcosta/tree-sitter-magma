#!/bin/bash

# A script to extract and test all Magma code snippets from markdown files.

# Directory containing the markdown documentation
DOCS_DIR="grammar-docs"
# Directory to store the temporary magma snippet files
SNIPPET_DIR="/tmp/magma_snippets_$$"
mkdir -p "$SNIPPET_DIR"

# Counters for the final report
SUCCESS_COUNT=0
FAIL_COUNT=0
SNIPPET_COUNT=0

# Trap to ensure cleanup on exit
trap 'rm -rf "$SNIPPET_DIR"; echo; echo "Cleaned up temporary files."; exit' INT TERM EXIT

echo "Extracting Magma code snippets from '$DOCS_DIR'..."

# Use awk to find all markdown files and extract magma code blocks from them.
# Each snippet is saved to a uniquely named file in the SNIPPET_DIR.
find "$DOCS_DIR" -name "*.md" -print0 | xargs -0 awk '
  /^```magma(-spec)?/{
    in_block=1;
    
    # Determine the language specifier for the output file
    lang = "magma";
    if ($0 ~ /magma-spec/) {
      lang = "magma-spec";
    }

    # Sanitize filename by replacing slashes with underscores
    fn = FILENAME;
    gsub(/\//, "_", fn);
    
    # Create a unique filename for each snippet
    outfile=sprintf("'"$SNIPPET_DIR"'/snip_%s_%s_%d.m", fn, lang, FNR);
    next
  }
  /^```/{
    if (in_block) {
      in_block=0;
      # Add a quit command to ensure magma exits
      print "quit;" >> outfile
      close(outfile)
    }
  }
  in_block {
    print >> outfile
  }
'

echo "Finished extracting snippets."
echo "----------------------------------------"
echo "Running tests on all extracted snippets..."
echo "----------------------------------------"

# Loop through all the generated snippet files and run them
for snippet_file in "$SNIPPET_DIR"/snip_*.m; do
  if [ -f "$snippet_file" ]; then
    SNIPPET_COUNT=$((SNIPPET_COUNT + 1))
    echo
    echo "--- Running: $(basename "$snippet_file") ---"

    # Distinguish between spec files and runnable examples
    if [[ "$snippet_file" == *magma-spec* ]]; then
      echo "--- Testing as SPEC file ---"
    else
      echo "--- Testing as RUNNABLE file ---"
    fi

    # Execute the snippet and capture the result
    if magma < "$snippet_file" >/dev/null 2>&1; then
      echo "--- RESULT: SUCCESS ---"
      SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
    else
      echo "--- RESULT: FAILURE ---"
      FAIL_COUNT=$((FAIL_COUNT + 1))
      echo "--- FAILED SNIPPET CONTENT: ---"
      # Print the content of the failed snippet, without the 'quit;'
      head -n -1 "$snippet_file"
      echo "-------------------------------"
    fi
  fi
done

echo
echo "========================================"
echo "           TEST SUMMARY"
echo "========================================"
echo "Total Snippets Found: $SNIPPET_COUNT"
echo "Successful: $SUCCESS_COUNT"
echo "Failed: $FAIL_COUNT"
echo "========================================"
echo

# The trap will handle cleanup.
exit 0 