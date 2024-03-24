#ifndef __TRESHAPE_H__
#define __TRESHAPE_H__

#include "schema_v3a_generated.h"
#include "toperator.h"

class TReshape : public TOperator {
public:
    TReshape(const tflite::Operator* op, const int idx);
    ~TReshape(void);

    //void display_info(void);
private:
};

#endif
