CXX := g++
CXXFLAGS := -std=c++20 -Wall -I StarFruit

BUILD := build
EXE := app.exe

DLL_DST := ./StarFruit.dll
DLL := $(BUILD)/StarFruit.dll
IMPLIB := $(BUILD)/libStarFruit.a

DLL_SRC := StarFruit/src/Application.cpp
APP_SRC := Sandbox/src/Sandbox.cpp

all: $(EXE)

# ---------- DLL ----------
$(DLL): $(DLL_SRC)
	mkdir -p $(BUILD)
	$(CXX) -shared $(DLL_SRC) \
	    -o $(DLL) \
	    -Wl,--out-implib,$(IMPLIB) \
		-IStarFruit/include \
	    -IStarFruit \

# ---------- EXE ----------
$(EXE): $(APP_SRC) $(DLL)
	$(CXX) $(APP_SRC) \
	    -o $(EXE) \
	    -Wl,-subsystem,console \
	    -IStarFruit/include \
		-IStarFruit/src \
		-IStarFruit \
	    -L$(BUILD) -lStarFruit
	cp $(DLL) $(DLL_DST)

clean:
	rm -rf $(BUILD) *.exe *.dll

.PHONY: all clean
