VERSION='"0.1.0"'
CXXFLAGS=-Wall -DVERSION=$(VERSION) -g
LDFLAGS=-ltorrent-rasterbar -lboost_system

TMPBORK_TEMPORARY::=$(shell mktemp)

bork: $(wildcard *.cpp) $(wildcard *.hpp)
clean:
	-rm bork

format: $(wildcard *.cpp) $(wildcard *.hpp)
	-[ -f /tmp/bork ] && mv /tmp/bork $(TMPBORK_TEMPORARY)
	for file in $^; do \
		clang-format $$file >/tmp/bork; \
		mv /tmp/bork $$file; \
	done
	-mv $(TMPBORK_TEMPORARY) /tmp/bork

.PHONY: clean format
