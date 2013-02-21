#include <f77crash/cursor.h>
#include <f77crash/crossrefs.h>


#include <iostream>

namespace CrossRefs {

std::string                         currentRoutine;

std::map<std::string, std::vector<std::string> >  call;

std::map<std::string, int>          external;
std::map<std::string, int>          intrinsic;
std::map<std::string, int>          variable;
std::map<std::string, Cursor>       declaration;

std::map<Cursor, std::string>       name;
std::map<Cursor, std::string>       defs;
std::map<std::string, Cursor>       args;

void
dump(const char *srcFile)
{
    typedef std::map<Cursor, std::string>  NameMap;
    typedef std::map<Cursor, std::string>  DefsMap;

    for (NameMap::const_iterator it = name.begin(); it != name.end(); ++it) {
        Cursor cursor = it->first;

        if (external.find(it->second) != external.end()) {
            std::cout << "EXTERNAL,"
                      << cursor.fromLine-1 << "." << cursor.fromCol+6 << ":"
                      << cursor.toLine-1 << "." << cursor.toCol+6 << ","
                      << it->second
                      << std::endl;
        } else if (intrinsic.find(it->second) != intrinsic.end()) {
            std::cout << "INTRINSIC,"
                      << cursor.fromLine-1 << "." << cursor.fromCol+6 << ":"
                      << cursor.toLine-1 << "." << cursor.toCol+6 << ","
                      << it->second
                      << std::endl;
        } else if (variable.find(it->second) != variable.end()) {
            if ((declaration.find(it->second) != declaration.end())
             && (cursor == declaration[it->second]))
            {
                if (args.find(it->second)!=args.end()) {
                    std::cout << "ARGDEF,";
                } else {
                    std::cout << "DEFINITION,";
                }
                std::cout << cursor.fromLine-1 << "." << cursor.fromCol+6 << ":"
                          << cursor.toLine-1 << "." << cursor.toCol+6 << ","
                          << variable[it->second] << ","
                          << it->second
                          << std::endl;
            } else {
                std::cout << "VARIABLE,"
                          << cursor.fromLine-1 << "." << cursor.fromCol+6 << ":"
                          << cursor.toLine-1 << "." << cursor.toCol+6 << ","
                          << variable[it->second] << ","
                          << it->second
                          << std::endl;
            }
         }

    }

    for (DefsMap::const_iterator it = defs.begin(); it != defs.end(); ++it) {
        Cursor      cursor = it->first;
        std::string type   = it->second;

        std::cerr << cursor.content << "," << type << ","
                  << cursor.fromLine << "," << srcFile
                  << std::endl;
        std::cout << type << ","
                  << cursor.fromLine-1 << "." << cursor.fromCol+6 << ":"
                  << cursor.toLine-1 << "." << cursor.toCol+6 << ","
                  << cursor.content
                  << std::endl;
     }

    typedef std::map<std::string, std::vector<std::string> >  CallMap;
    for (CallMap::const_iterator it = call.begin(); it != call.end(); ++it) {
        for (size_t k=0; k < (it->second).size(); ++k) {
            std::cerr << it->first << ",CALLS,"
                      << (it->second)[k]
                      << "," << srcFile
                      << std::endl;
        }
    }
}

} // namespace CrossRefs
