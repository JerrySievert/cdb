CC=clang
CXX=clang++
RM=rm -f
CD=cd
CPPFLAGS=-Iinclude -Ileveldb/include -std=c++11 -Wall -g
LDFLAGS=-g -Lleveldb/out-static
LDLIBS=-lleveldb -lpthread

SRCS=src/log.cc \
			src/util.cc \
			src/table.cc \
			src/field.cc \
			src/datum.cc \
			src/store/directory.cc \
			src/store/tablestore.cc

OBJS=$(subst .cc,.o,$(SRCS))

TEST_SRCS=test/test.cc \
			test/log.cc \
			test/field.cc \
			test/table.cc \
			test/datum.cc \
			test/store/directory.cc \
			test/store/tablestore.cc

TEST_OBJS=$(subst .cc,.o,$(TEST_SRCS))

ifdef COV
	CPPFLAGS += -fprofile-arcs -ftest-coverage
	LDFLAGS += -fprofile-arcs -ftest-coverage
endif

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
