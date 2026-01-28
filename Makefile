CXX := g++
CXXFLAGS := -std=c++20 -Wall -I StarFruit

BUILD := build
EXE := app.exe

DLL := $(BUILD)/StarFruit.dll
IMPLIB := $(BUILD)/libStarFruit.a
DLL_DST := ./StarFruit.dll

DLL_SRC := \
	StarFruit/src/Application.cpp \
	StarFruit/src/Log.cpp
DLL_INCLUDES := \
	-IStarFruit/vendor/spdlog/include \
	-IStarFruit/include \
	-IStarFruit \

APP_SRC := Sandbox/src/Sandbox.cpp
APP_INCLUDES := \
	-IStarFruit/vendor/spdlog/include \
	-IStarFruit/include \
	-IStarFruit \

all: $(EXE)

# ---------- DLL ----------
$(DLL): $(DLL_SRC)
	mkdir -p $(BUILD)
	$(CXX) -shared $(DLL_SRC) \
	    -o $(DLL) \
	    -Wl,--out-implib,$(IMPLIB) \
		$(DLL_INCLUDES)

# ---------- EXE ----------
$(EXE): $(APP_SRC) $(DLL)
	$(CXX) $(APP_SRC) \
	    -o $(EXE) \
	    -Wl,-subsystem,console \
		$(APP_INCLUDES) \
	    -L$(BUILD) -lStarFruit
	cp $(DLL) $(DLL_DST)

clean:
	rm -rf $(BUILD) *.exe *.dll

.PHONY: all clean
