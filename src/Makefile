BUILD_DIR=./build
BIN_DIR=$(BUILD_DIR)/bin

PROJECT_PATH=$(BIN_DIR)/Kalkulacka
TEST_PATH=$(BIN_DIR)/test_lib
PROFILE_PATH=$(BIN_DIR)/profiling

LOGIN=xdohun00
TARGET=$(PROFILE_PATH) $(PROJECT_PATH) $(TEST_PATH)

####################################################

.PHONY: all run profile test doc pack clean

all: $(TARGET)

run: $(PROJECT_PATH)
	cd $(BIN_DIR) && ./Kalkulacka

profile: $(PROFILE_PATH)
	cd $(BIN_DIR) && ./profiling

test: $(TEST_PATH)
	cd $(BIN_DIR) && ./test_lib

doc: Doxyfile
	doxygen

pack:
	make clean
	zip -r ../$(LOGIN) ../*

clean:
	rm -fr $(BUILD_DIR)/*

##################################################

$(TARGET): $(BUILD_DIR)/Makefile ./gui/* *.cpp ./include/*.h
	make -C$(BUILD_DIR) -j8

$(BUILD_DIR)/Makefile: CMakeLists.txt
	cmake . -B$(BUILD_DIR)
