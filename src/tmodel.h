#include "schema_v3a_generated.h"

class TModel {
public:
    TModel(const char* buf);
    ~TModel(void);

    void display_info(void);
private:
    const tflite::Model *model_;
};
