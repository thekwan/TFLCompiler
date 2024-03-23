#ifndef __TOPERATOR_H__
#define __TOPERATOR_H__

#include "schema_v3a_generated.h"

class TOperator {
public:
    TOperator(const tflite::Operator* op);
    ~TOperator(void);

    void display_info(void);
private:
    const tflite::Operator* operator_;
    std::vector<int> inputs_;
    std::vector<int> outputs_;
    uint32_t opcode_index_;
};

using TOperatorPList = std::vector<std::shared_ptr<TOperator>>;

#endif
