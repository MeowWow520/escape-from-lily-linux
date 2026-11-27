CXX      ?= clang++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -O2 -g
CPPFLAGS += -Isrc $(shell pkg-config --cflags sdl3)
LDLIBS   += $(shell pkg-config --libs sdl3)

SRC    := $(wildcard src/*.cpp) $(wildcard src/core/*.cpp) $(wildcard src/core/*/*.cpp)
OBJ    := $(patsubst src/%.cpp,build/%.o,$(SRC))
TARGET := build/escape-from-lily

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDLIBS) -o $@

build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(OBJ:.o=.d)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build

.PHONY: all run clean