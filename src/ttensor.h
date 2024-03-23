#ifndef __TTENSOR_H__
#define __TTENSOR_H__

#include "schema_v3a_generated.h"

class TTensor {
public:
    TTensor(const tflite::Tensor* ts, const int index);
    ~TTensor(void);

    void display_info(void);
private:
    const tflite::Tensor* tensor_;
    const int tensor_index_;
    std::vector<int> shape_;
};

using TTensorPList = std::vector<std::shared_ptr<TTensor>>;
#endif
