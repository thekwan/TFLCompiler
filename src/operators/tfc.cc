#include "toperator.h"
#include "tfc.h"
#include "spdlog/spdlog.h"

TFc::TFc(const tflite::Operator* op, const int index) : TOperator(op, index) {
    spdlog::info("TFc is created!");
}

TFc::~TFc(void) {
}

std::shared_ptr<TOperator>
createOpFc(const tflite::Operator* op, const int idx) {
    return std::make_shared<TFc>(op, idx);
}

OperatorRegister op_fc(
        tflite::BuiltinOperator::BuiltinOperator_FULLY_CONNECTED,
        createOpFc);
