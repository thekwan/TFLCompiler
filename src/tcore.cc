#include <fstream>

#include "spdlog/spdlog.h"
#include "tcore.h"

TCore::TCore(const char* filename) {
    std::ifstream infile;
    infile.open(filename, std::ios::binary | std::ios::in);

    tmodel_buf_ = nullptr;

    if (infile.is_open()) {
        infile.seekg(0,std::ios::end);
        int length = infile.tellg();
        infile.seekg(0,std::ios::beg);
        tmodel_buf_ = new char[length];
        infile.read(tmodel_buf_, length);
        infile.close();

        tmodel_ = new TModel(tmodel_buf_);
    }
}

TCore::~TCore(void) {
    delete [] tmodel_buf_;
}

void TCore::display_info(void) {
    tmodel_->display_info();
}
