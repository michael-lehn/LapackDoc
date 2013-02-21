#ifndef F77CRASH_CURSOR_H
#define F77CRASH_CURSOR_H

#include <string>

struct Cursor
{
    long         fromLine, toLine;
    int          fromCol, toCol;
    std::string  content;
    int          tokenId;
    int          statementNumber;

    bool
    operator<(const Cursor &cursor) const;

    bool
    operator==(const Cursor &cursor) const;
};

extern Cursor    cursor;
extern Cursor    voidCursor;

#endif // F77CRASH_CURSOR_H
