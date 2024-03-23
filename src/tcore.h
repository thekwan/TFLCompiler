#ifndef __TCORE_H__
#define __TCORE_H__

#include "tmodel.h"

class TCore {
public:
    TCore(const char* filename);
    ~TCore(void);

    bool isOpened(void) { return tmodel_ != nullptr; }
    void display_info(void);
private:
    char* tmodel_buf_;
    std::shared_ptr<TModel> tmodel_;
};
#endif
