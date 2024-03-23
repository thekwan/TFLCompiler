#include "tmodel.h"

class TCore {
public:
    TCore(const char* filename);
    ~TCore(void);

    bool isOpened(void) { return tmodel_ != nullptr; }
    void display_info(void);
private:
    char* tmodel_buf_;
    TModel* tmodel_;
};
