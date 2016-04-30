CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-Iinclude -Ileveldb -std=c++11 -Wall -g
LDFLAGS=-g
LDLIBS=

SRCS=src/log.cc src/util.cc src/table.cc
OBJS=$(subst .cc,.o,$(SRCS))
TEST_SRCS=test/test.cc test/log.cc
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
