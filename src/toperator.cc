#include "toperator.h"
#include "utils.h"
#include "spdlog/spdlog.h"

std::map<tflite::BuiltinOperator, func_ptr> OperatorManager::op_map;
//std::map<tflite::BuiltinOperator, int> OperatorManager::op_map = {};
//std::map<int, int> OperatorManager::op_map;
bool OperatorManager::op_map_init = false;

TOperator::TOperator(const tflite::Operator* op, const int index)
        : operator_(op), operator_index_(index) {
    opcode_index_ = operator_->opcode_index();

    for (auto i : *operator_->inputs()) {
        inputs_.push_back(i);
    }

    for (auto i : *operator_->outputs()) {
        outputs_.push_back(i);
    }

    spdlog::info("TOperator is created!");
}

TOperator::~TOperator(void) {
}

void TOperator::display_info(void) {
    spdlog::info("Operator[{}] --------------------------------", opcode_index_);
    // Field; opcode_index
    spdlog::info("opcode_index    : {}", opcode_index_);

    std::string s;
    // Field; inputs
    VInt2String(s, inputs_);
    spdlog::info("inputs          : {}", s);

    // Field; outputs
    VInt2String(s, outputs_);
    spdlog::info("outputs         : {}", s);
    
    spdlog::info("--------------------------------------------");
}
