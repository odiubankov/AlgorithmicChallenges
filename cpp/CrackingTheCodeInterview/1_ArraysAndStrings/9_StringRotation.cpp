#include "9_StringRotation.h"

bool rotateString(const std::string& a, const std::string& b) {
    if (a.size() != b.size())
        return false;

    std::string c = a + a;
    return c.find(b) != std::string::npos;
}
