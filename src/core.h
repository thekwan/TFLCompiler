#include "model.h"

class Core {
public:
    Core(const char* filename);
    ~Core(void) {}

    bool isOpened(void) { return model_ != nullptr; }
private:
    char* model_buf_;
    Model* model_;
};
