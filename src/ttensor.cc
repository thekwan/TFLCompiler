#include "ttensor.h"
#include "utils.h"
#include "spdlog/spdlog.h"

TTensor::TTensor(const tflite::Tensor* ts, const int index) 
    : tensor_(ts), tensor_index_(index) {
    for (auto s : (*tensor_->shape())) {
        shape_.push_back(s);
    }

    spdlog::info("TTensor is created!");
}

TTensor::~TTensor(void) {
}

void TTensor::display_info(void) {
    spdlog::info("Tensor[{}] ----------------------------------", tensor_index_);
    // Field; name
    auto name = tensor_->name();
    if (name != nullptr) {
        spdlog::info("Name of Tensor: {}", name->c_str());
    }

    // Field; tensors
    spdlog::info("# of tensors  : {}", EnumNameTensorType(tensor_->type()));

    // Field; shape
    std::string s;
    VInt2String(s, tensor_->shape());
    spdlog::info("shape         : {}", s);
    spdlog::info("--------------------------------------------");
}
