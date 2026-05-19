#include "hlpr.h"

char* cp_str(const char *s)
{
    if (s == nullptr) return nullptr;
    char *nw = new char[strlen(s)+1];
    strcpy(nw, s);
    return nw;
}