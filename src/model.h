#include "schema_v3a_generated.h"

class Model {
public:
    Model(const char* buf) {
        model_ = tflite::GetModel(buf);
    }
    ~Model(void) {}
private:
    const tflite::Model *model_;
};
