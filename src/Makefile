CC=g++
CFLAGS=-std=c++14
LDFLAGS=-lm
TARGET=
TEST=test_prg
TEST_LIBS=-lgtest -lgtest_main -lpthread

.PHONY: all pack clean test doc run profile

all: $(TEST) $(TARGET)

#pack: TODO:

clean:
	rm -f *.o $(TEST) $(TARGET)

test: $(TEST)
	./$(TEST)

# potreba libgtest.a a libtest_main.a v /usr/lib
$(TEST): $(TEST).o math_lib.o
	$(CC) $(CFLAGS) -o $@ $^ $(TEST_LIBS) $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

#doc: TODO:

#run: TODO:

#profile: TODO:
