#ifndef __TFC_H__
#define __TFC_H__

#include "schema_v3a_generated.h"
#include "toperator.h"

class TFc : public TOperator {
public:
    TFc(const tflite::Operator* op, const int idx);
    ~TFc(void);

    //void display_info(void);
private:
};

#endif
