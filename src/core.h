#include "model.h"

class Core {
public:
    Core(const char* filename);
    ~Core(void) {}
private:
    char* model_buf_;
    Model* model_;
};
