#include "toperator.h"
#include "treshape.h"
#include "spdlog/spdlog.h"

TReshape::TReshape(const tflite::Operator* op, const int index)
    : TOperator(op, index) {
    spdlog::info("TReshape is created!");
}

TReshape::~TReshape(void) {
}

std::shared_ptr<TOperator>
createOpReshape(const tflite::Operator* op, const int idx) {
    return std::make_shared<TReshape>(op, idx);
}

OperatorRegister op_reshape(
        tflite::BuiltinOperator::BuiltinOperator_RESHAPE,
        createOpReshape);
