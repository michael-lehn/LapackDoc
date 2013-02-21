#ifndef F77CRASH_HIGHLIGHT_H
#define F77CRASH_HIGHLIGHT_H 1

#include <f77crash/tokens.h>
#include <string>

void
initHighlight();

bool
isHighlighted(int tokenId);

const std::string &
getHighlightTag(int tokenId);

#endif // F77CRASH_HIGHLIGHT_H
