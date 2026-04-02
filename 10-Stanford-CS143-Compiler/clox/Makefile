CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=c11 -O2
SRCDIR  = src
BUILDDIR = build

SRCS    = $(wildcard $(SRCDIR)/*.c)
OBJS    = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))
TARGET  = $(BUILDDIR)/clox

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)

test: $(TARGET)
	@failed=0; \
	for f in tests/*.lox; do \
		echo "--- $$f ---"; \
		$(TARGET) $$f || failed=1; \
	done; \
	if [ $$failed -eq 0 ]; then echo "=== All tests passed ==="; \
	else echo "=== SOME TESTS FAILED ==="; exit 1; fi
