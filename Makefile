CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Iinclude -Ileveldb/include -std=c++11 -Wall -g -fsanitize=address -fno-omit-frame-pointer
LDFLAGS=-g -Lleveldb/out-static -fsanitize=address -fno-omit-frame-pointer
LDLIBS=-lleveldb

SRCS=src/log.cc \
			src/util.cc \
			src/table.cc \
			src/field.cc \
			src/store/directory.cc \
			src/store/tablestore.cc

OBJS=$(subst .cc,.o,$(SRCS))

TEST_SRCS=test/test.cc \
			test/log.cc \
			test/field.cc \
			test/table.cc \
			test/store/directory.cc

TEST_OBJS=$(subst .cc,.o,$(TEST_SRCS))

all: test_runner

test_runner: $(OBJS) $(TEST_OBJS)
	$(CXX) $(LDFLAGS) -o test_runner $(OBJS) $(TEST_OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS) $(TEST_SRCS)
	$(RM) -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)
	$(RM) $(TEST_OBJS)

dist-clean: clean
	$(RM) *~ .depend

include .depend
