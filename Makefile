ifeq ($(OS),Windows_NT)
$(error Windows is not supported)
endif

LANGUAGE_NAME := tree-sitter-magma
HOMEPAGE_URL := https://github.com/tree-sitter/tree-sitter-magma
VERSION := 0.1.0

# repository
SRC_DIR := src

TS ?= tree-sitter

# install directory layout
PREFIX ?= /usr/local
DATADIR ?= $(PREFIX)/share
INCLUDEDIR ?= $(PREFIX)/include
LIBDIR ?= $(PREFIX)/lib
PCLIBDIR ?= $(LIBDIR)/pkgconfig

# source/object files
PARSER := $(SRC_DIR)/parser.c
EXTRAS := $(filter-out $(PARSER),$(wildcard $(SRC_DIR)/*.c))
OBJS := $(patsubst %.c,%.o,$(PARSER) $(EXTRAS))

# flags
ARFLAGS ?= rcs
override CFLAGS += -I$(SRC_DIR) -std=c11 -fPIC

# ABI versioning
SONAME_MAJOR = $(shell sed -n 's/\#define LANGUAGE_VERSION //p' $(PARSER))
SONAME_MINOR = $(word 1,$(subst ., ,$(VERSION)))

# OS-specific bits
ifeq ($(shell uname),Darwin)
	SOEXT = dylib
	SOEXTVER_MAJOR = $(SONAME_MAJOR).$(SOEXT)
	SOEXTVER = $(SONAME_MAJOR).$(SONAME_MINOR).$(SOEXT)
	LINKSHARED = -dynamiclib -Wl,-install_name,$(LIBDIR)/lib$(LANGUAGE_NAME).$(SOEXTVER),-rpath,@executable_path/../Frameworks
else
	SOEXT = so
	SOEXTVER_MAJOR = $(SOEXT).$(SONAME_MAJOR)
	SOEXTVER = $(SOEXT).$(SONAME_MAJOR).$(SONAME_MINOR)
	LINKSHARED = -shared -Wl,-soname,lib$(LANGUAGE_NAME).$(SOEXTVER)
endif
ifneq ($(filter $(shell uname),FreeBSD NetBSD DragonFly),)
	PCLIBDIR := $(PREFIX)/libdata/pkgconfig
endif

all: lib$(LANGUAGE_NAME).a lib$(LANGUAGE_NAME).$(SOEXT) $(LANGUAGE_NAME).pc

lib$(LANGUAGE_NAME).a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

lib$(LANGUAGE_NAME).$(SOEXT): $(OBJS)
	$(CC) $(LDFLAGS) $(LINKSHARED) $^ $(LDLIBS) -o $@
ifneq ($(STRIP),)
	$(STRIP) $@
endif

$(LANGUAGE_NAME).pc: bindings/c/$(LANGUAGE_NAME).pc.in
	sed -e 's|@PROJECT_VERSION@|$(VERSION)|' \
		-e 's|@CMAKE_INSTALL_LIBDIR@|$(LIBDIR:$(PREFIX)/%=%)|' \
		-e 's|@CMAKE_INSTALL_INCLUDEDIR@|$(INCLUDEDIR:$(PREFIX)/%=%)|' \
		-e 's|@PROJECT_DESCRIPTION@|$(DESCRIPTION)|' \
		-e 's|@PROJECT_HOMEPAGE_URL@|$(HOMEPAGE_URL)|' \
		-e 's|@CMAKE_INSTALL_PREFIX@|$(PREFIX)|' $< > $@

$(PARSER): $(SRC_DIR)/grammar.json
	$(TS) generate $^

install: all
	install -d '$(DESTDIR)$(DATADIR)'/tree-sitter/queries/magma '$(DESTDIR)$(INCLUDEDIR)'/tree_sitter '$(DESTDIR)$(PCLIBDIR)' '$(DESTDIR)$(LIBDIR)'
	install -m644 bindings/c/tree_sitter/$(LANGUAGE_NAME).h '$(DESTDIR)$(INCLUDEDIR)'/tree_sitter/$(LANGUAGE_NAME).h
	install -m644 $(LANGUAGE_NAME).pc '$(DESTDIR)$(PCLIBDIR)'/$(LANGUAGE_NAME).pc
	install -m644 lib$(LANGUAGE_NAME).a '$(DESTDIR)$(LIBDIR)'/lib$(LANGUAGE_NAME).a
	install -m755 lib$(LANGUAGE_NAME).$(SOEXT) '$(DESTDIR)$(LIBDIR)'/lib$(LANGUAGE_NAME).$(SOEXTVER)
	ln -sf lib$(LANGUAGE_NAME).$(SOEXTVER) '$(DESTDIR)$(LIBDIR)'/lib$(LANGUAGE_NAME).$(SOEXTVER_MAJOR)
	ln -sf lib$(LANGUAGE_NAME).$(SOEXTVER_MAJOR) '$(DESTDIR)$(LIBDIR)'/lib$(LANGUAGE_NAME).$(SOEXT)
ifneq ($(wildcard queries/*.scm),)
	install -m644 queries/*.scm '$(DESTDIR)$(DATADIR)'/tree-sitter/queries/magma
endif

uninstall:
	$(RM) '$(DESTDIR)$(LIBDIR)'/lib$(LANGUAGE_NAME).a \
		'$(DESTDIR)$(LIBDIR)'/lib$(LANGUAGE_NAME).$(SOEXTVER) \
		'$(DESTDIR)$(LIBDIR)'/lib$(LANGUAGE_NAME).$(SOEXTVER_MAJOR) \
		'$(DESTDIR)$(LIBDIR)'/lib$(LANGUAGE_NAME).$(SOEXT) \
		'$(DESTDIR)$(INCLUDEDIR)'/tree_sitter/$(LANGUAGE_NAME).h \
		'$(DESTDIR)$(PCLIBDIR)'/$(LANGUAGE_NAME).pc
	$(RM) -r '$(DESTDIR)$(DATADIR)'/tree-sitter/queries/magma

clean:
	$(RM) $(OBJS) $(LANGUAGE_NAME).pc lib$(LANGUAGE_NAME).a lib$(LANGUAGE_NAME).$(SOEXT)
	$(RM) -r .corpus_tmp

# --- Testing ---

# Tree-sitter corpus tests
test:
	$(TS) test

# Parse external Magma files and report error rates
# Usage: make parse-packages PACKAGE_DIR=/opt/magma/current/package
#        make parse-examples EXAMPLES_DIR=examples
PACKAGE_DIR ?= /opt/magma/current/package
EXAMPLES_DIR ?= examples
MAGMA ?= magma
TIMEOUT ?= 10
CORPUS_DIR ?= test/corpus

parse-packages:
	@total=0; errors=0; \
	for f in $$(find $(PACKAGE_DIR) -name '*.m' -type f | sort); do \
		total=$$((total + 1)); \
		output=$$($(TS) parse "$$f" --quiet 2>&1); \
		if echo "$$output" | grep -q 'ERROR\|MISSING'; then \
			errors=$$((errors + 1)); \
			echo "FAIL: $$f"; \
			echo "$$output" | grep 'ERROR\|MISSING' | head -3; \
			echo '---'; \
		fi; \
		if [ $$((total % 500)) -eq 0 ]; then \
			echo "[progress] $$total files..." >&2; \
		fi; \
	done; \
	echo ""; \
	echo "Packages: $$total files, $$errors errors, $$(( (total - errors) * 100 / total ))% success"

parse-examples:
	@total=0; errors=0; \
	for f in $(EXAMPLES_DIR)/*; do \
		case "$$(basename $$f)" in *.c|*.py|*.R) continue;; esac; \
		total=$$((total + 1)); \
		output=$$($(TS) parse "$$f" --quiet 2>&1); \
		if echo "$$output" | grep -q 'ERROR\|MISSING'; then \
			errors=$$((errors + 1)); \
			echo "FAIL: $$f"; \
		fi; \
	done; \
	echo "Examples: $$total files, $$errors errors, $$(( (total - errors) * 100 / total ))% success"

# Validate corpus test source code against real Magma
# Checks that the Magma code in test/corpus/*.txt is syntactically valid
# Only flags "bad syntax" errors (true parse failures), not runtime errors
# like "not declared", "Illegal declaration (must be done in package only)", etc.
# Skips: invalid.txt (intentionally bad syntax)
validate-corpus:
	@python3 scripts/extract_corpus_code.py $(CORPUS_DIR) .corpus_tmp --skip invalid types
	@pass=0; fail=0; skip=0; \
	for f in .corpus_tmp/*.m; do \
		name=$$(basename "$$f"); \
		output=$$(echo 'quit;' | cat "$$f" - | timeout $(TIMEOUT) $(MAGMA) -b 2>&1); \
		if echo "$$output" | grep -q 'bad syntax'; then \
			fail=$$((fail + 1)); \
			echo "SYNTAX ERROR: $$name"; \
			echo "$$output" | grep -B1 'bad syntax' | head -4; \
			echo '---'; \
		else \
			pass=$$((pass + 1)); \
		fi; \
	done; \
	$(RM) -r .corpus_tmp; \
	echo ""; \
	echo "Validated: $$pass passed, $$fail syntax errors"; \
	[ "$$fail" -eq 0 ]

.PHONY: all install uninstall clean test parse-packages parse-examples validate-corpus
