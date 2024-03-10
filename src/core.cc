#include <fstream>

#include "core.h"

Core::Core(const char* filename) {
    std::ifstream infile;
    infile.open(filename, std::ios::binary | std::ios::in);

    model_buf_ = nullptr;

    if (infile.is_open()) {
        infile.seekg(0,std::ios::end);
        int length = infile.tellg();
        infile.seekg(0,std::ios::beg);
        model_buf_ = new char[length];
        infile.read(model_buf_, length);
        infile.close();

        model_ = new Model(model_buf_);
    }
}
