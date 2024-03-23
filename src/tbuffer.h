#ifndef __TBUFFER_H__
#define __TBUFFER_H__

#include "schema_v3a_generated.h"

class TBuffer {
public:
    TBuffer(const tflite::Buffer* bf);
    ~TBuffer(void);

    void display_info(void);
private:
    const tflite::Buffer* buffer_;
};
#endif
