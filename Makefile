VERSION='"0.1.0"'
CXXFLAGS=-Wall -DVERSION=$(VERSION) -g
LDFLAGS=-ltorrent-rasterbar -lboost_system

TMPBORK_TEMPORARY::=$(shell mktemp)

bork: $(wildcard *.cpp) $(wildcard *.hpp)
clean:
	-rm bork

%.formatted: %.cpp
	clang-format -i $^
%.formatted: %.hpp
	clang-format -i $^

format: bork.formatted logging.formatted

.PHONY: clean format %.formatted
