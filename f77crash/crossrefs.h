#ifndef F77CRASH_CROSSREFS_H
#define F77CRASH_CROSSREFS_H 1


#include <map>
#include <string>
#include <vector>
#include <f77crash/cursor.h>

namespace CrossRefs {

extern std::string                    currentRoutine;

extern std::map<std::string, std::vector<std::string> >  call;

extern std::map<std::string, int>     external;
extern std::map<std::string, int>     intrinsic;
extern std::map<std::string, int>     variable;
extern std::map<std::string, Cursor>  declaration;

extern std::map<Cursor, std::string>  name;
extern std::map<Cursor, std::string>  defs;
extern std::map<std::string, Cursor>  args;

void
dump(const char *srcFile);

} // namespace CrossRefs

#endif // F77CRASH_CROSSREFS_H 1
