CXX := g++
CXXFLAGS := -std=c++20 -Wall -I StarFruit

BUILD := build
EXE := app.exe

IMPLIB := $(BUILD)/libStarFruit.a
DLL := ./StarFruit.dll

DLL_SRC :=  $(wildcard StarFruit/src/*.cpp)
APP_SRC := $(wildcard Sandbox/src/*.cpp)

STAR_INCLUDE := \
    -IStarFruit/vendor/spdlog/include \
    -IStarFruit/include \
    -IStarFruit/events \
    -IStarFruit \

# Precompiled header
PCH_SRC := StarFruit/sfpch.cpp
PCH_H := StarFruit/sfpch.h
PCH := $(BUILD)/sfpch.h.gch

all: $(EXE)

# ---------- Precompiled Header ----------
$(PCH): $(PCH_SRC) $(PCH_H)
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -o $@ -c $(PCH_SRC)

# ---------- DLL ----------
$(DLL): $(DLL_SRC) $(PCH)
	mkdir -p $(BUILD)
	$(CXX) -shared $(DLL_SRC) \
	    -o $(DLL) \
	    -Wl,--out-implib,$(IMPLIB) \
	    $(STAR_INCLUDE) \
	    $(CXXFLAGS)

# ---------- EXE ----------
$(EXE): $(APP_SRC) $(DLL) $(PCH)
	$(CXX) $(APP_SRC) \
	    -o $(EXE) \
	    -Wl,-subsystem,console \
	    $(STAR_INCLUDE) \
	    -L$(BUILD) -lStarFruit \
	    $(CXXFLAGS)

clean:
	rm -rf $(BUILD) *.exe *.dll

.PHONY: all clean
