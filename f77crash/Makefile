NODEPS            = clean veryclean
TARGET            = f77crash

CXX_SOURCE_FILES  = $(sort $(wildcard *.cc) fortran.cc)
OBJECT_FILES      = $(patsubst %.cc,%.o,$(CXX_SOURCE_FILES))
DEP_FILES         = $(patsubst %.cc,%.d,$(CXX_SOURCE_FILES))
TMP_DIR           = .tmp

GENERATE_FILES    = fortran.cc fortran.y tokens.h

CXXFLAGS += -I.. -Wall -Werror -std=c++11

all : $(TARGET)

$(TARGET): $(GENERATE_FILES) $(DEP_FILES) $(OBJECT_FILES)
	$(CXX) $(OBJECT_FILES) -o $(TARGET)

tokens.h : tokens
	@mkdir -p $(TMP_DIR)
	(grep -n . tokens | sed "s/\([^:]*\):\(.*\)/#define \2 \1/"; echo) > $(TMP_DIR)/tokens.h.tmp
	wc -l tokens | sed 's/^[^0-9]*\([1-9][0-9]*\)[^0-9]*$$/#define NUM_TOKENS \1/' >> $(TMP_DIR)/tokens.h.tmp
	(echo "#ifndef F77CRASH_TOKENS_H\n#define F77CRASH_TOKENS_H 1\n"; \
	 echo "#define SEOF 0\n"; \
	 cat $(TMP_DIR)/tokens.h.tmp; \
	 echo "\n#endif // F77CRASH_TOKENS_H") > tokens.h; \
	# rm -f $(TMP_DIR)/tokens.h.tmp

%.d: %.cc $(GENERATE_FILES)
	@mkdir -p $(TMP_DIR)
	set -e; rm -f $@; \
    $(CXX) -M $(CXXFLAGS) $< > $(TMP_DIR)/$@.$$$$; \
    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $(TMP_DIR)/$@.$$$$ > $@; \
    rm -f $(TMP_DIR)/$@.$$$$

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
-include $(DEP_FILES)
endif

fortran.cc fortran.y: fortran.y.in tokens.h
	( grep "#define S" tokens.h | sed "s/#define/%token/" ;\
	cat fortran.y.in ) > fortran.y; \
	bison -o fortran.cc fortran.y

%.o: %.cc %.d
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(OBJECT_FILES) $(TARGET) $(TMP_DIR)

.PHONY: veryclean
veryclean: clean
		$(RM) $(GENERATE_FILES) $(DEP_FILES)
