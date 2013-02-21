NODEPS            = clean veryclean
TARGET            = f77crash

CXX_SOURCE_FILES  = $(sort $(wildcard *.cc) fortran.cc)
OBJECT_FILES      = $(patsubst %.cc,%.o,$(CXX_SOURCE_FILES))
DEP_FILES         = $(patsubst %.cc,%.d,$(CXX_SOURCE_FILES))

CXXFLAGS += -I.. -Wall -Werror -std=c++11

all : $(TARGET)

$(TARGET): tokens.h fortran.h fortran.cc $(DEP_FILES) $(OBJECT_FILES)
	$(CXX) $(OBJECT_FILES) -o $(TARGET)

tokens.h : tokens
	(grep -n . tokens | sed "s/\([^:]*\):\(.*\)/#define \2 \1/"; echo) > tokens.h.tmp
	wc -l tokens | sed 's/^[^0-9]*\([1-9][0-9]*\)[^0-9]*$$/#define NUM_TOKENS \1/' >> tokens.h.tmp
	(echo "#ifndef F77CRASH_TOKENS_H\n#define F77CRASH_TOKENS_H 1\n"; \
	 echo "#define SEOF 0\n"; \
	 cat tokens.h.tmp; \
	 echo "\n#endif // F77CRASH_TOKENS_H") > tokens.h; \
	$(RM) tokens.h.tmp

%.d: %.cc
	set -e; rm -f $@; \
    $(CXX) -M $(CXXFLAGS) $< > $@.$$$$; \
    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
    rm -f $@.$$$$

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
-include $(DEP_FILES)
endif

fortran.h fortran.cc: fortran.y.in tokens.h
	( grep "#define S" tokens.h | sed "s/#define/%token/" ;\
	cat fortran.y.in ) > fortran.y; \
	bison --defines=fortran.h -o fortran.cc fortran.y

%.o: %.cc %.d
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(OBJECT_FILES) $(TARGET)

.PHONY: veryclean
veryclean: clean
	$(RM) fortran.cc fortran.y fortran.h tokens.h $(DEP_FILES)
