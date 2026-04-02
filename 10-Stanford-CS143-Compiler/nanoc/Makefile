CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=c11 -O2
SRCDIR  = src
BUILDDIR = build

SRCS    = $(wildcard $(SRCDIR)/*.c)
OBJS    = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))
TARGET  = $(BUILDDIR)/nanoc

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR) tests/*.s tests/*.o

test: $(TARGET)
	@echo "=== Compiling and running test programs ==="
	@for f in tests/*.nano; do \
		name=$$(basename $$f .nano); \
		echo "--- $$name ---"; \
		$(TARGET) $$f -o tests/$$name && ./tests/$$name; \
		echo "(exit: $$?)"; \
	done
