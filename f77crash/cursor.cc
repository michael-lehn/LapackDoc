#include <f77crash/cursor.h>


bool
Cursor::operator<(const Cursor &cursor) const
{
    if (fromLine<cursor.fromLine) {
        return true;
    }
    if (fromLine==cursor.fromLine && fromCol<cursor.fromCol) {
        return true;
    }
    return false;
}

bool
Cursor::operator==(const Cursor &cursor) const
{
    if (fromLine!=cursor.fromLine) {
        return false;
    }
    if (toLine!=cursor.toLine) {
        return false;
    }
    if (fromCol!=cursor.fromCol) {
        return false;
    }
    if (toCol!=cursor.toCol) {
        return false;
    }
    if (content!=cursor.content) {
        return false;
    }
    if (tokenId!=cursor.tokenId) {
        return false;
    }
    if (statementNumber!=cursor.statementNumber) {
        return false;
    }
    return true;
}

Cursor  cursor;
Cursor  voidCursor;
