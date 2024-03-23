#ifndef __UTILS_H__
#define __UTILS_H__

#include "schema_v3a_generated.h"

void VInt2String(std::string& s, std::vector<int>& v);
void VInt2String(std::string& s, const flatbuffers::Vector<int>* v);

#endif
