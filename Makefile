RM = /bin/rm
MV = /bin/mv
CP = /bin/cp
MKDIR=mkdir
TAR=gtar
PLANARITY_BIN=planarity
CMAKE=cmake

ifneq (,$(wildcard ./.env))
	include .env
	export
endif

CMAKE_OPTS=-DCMAKE_C_COMPILER=$(CC) -DCMAKE_CXX_COMPILER=$(CXX) -DBOOST_ROOT=$(BOOST_ROOT)

SRC_CPP=src
PROJ_DIR=$(PWD)
BUILD_DIR=$(PROJ_DIR)/build

build:
	$(CMAKE) -S . -B "$(BUILD_DIR)/Release" $(CMAKE_OPTS) -DCMAKE_BUILD_TYPE=Release
	$(CMAKE) --build "$(BUILD_DIR)/Release"
	$(MKDIR) -p "dist"
	$(RM) -f "dist/$(PLANARITY_BIN)"
	$(CP) -f "build/Release/$(PLANARITY_BIN)" "dist/"
	@echo "Created: dist/$(PLANARITY_BIN)"

build-debug:
	$(CMAKE) -S . -B "$(BUILD_DIR)/Debug" $(CMAKE_OPTS) -DCMAKE_BUILD_TYPE=Debug
	$(CMAKE) --build "$(BUILD_DIR)/Debug"

clean:
	@echo "Cleaning..."
	@$(RM) -rf build/* dist/*
	@echo "Cleaning done."

.PHONY: build build-debug clean
