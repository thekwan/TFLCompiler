#include "utils.h"

#include <string>

void VInt2String(std::string& s, std::vector<int>& v) {
    s = "[";
    for (auto& i : v) {
        s += std::to_string(i) + ",";
    }
    s.pop_back();
    s += "]";
}

void VInt2String(std::string& s, const flatbuffers::Vector<int>* v) {
    s = "[";
    for (auto i : *v) {
        s += std::to_string(i) + ",";
    }
    s.pop_back();
    s += "]";
}
