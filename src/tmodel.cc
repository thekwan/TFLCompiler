#include "tmodel.h"
#include "spdlog/spdlog.h"

TModel::TModel(const char* buf) {
    model_ = tflite::GetModel(buf);

    for (auto sg : *(model_->subgraphs())) {
        subgraphs_.push_back(std::make_shared<TSubGraph>(sg));
    }

    spdlog::info("TModel is created!");
}

TModel::~TModel(void) {
}

void TModel::display_info(void) {
    spdlog::info("Model --------------------------------------");
    // Field; description
    auto desc = model_->description();
    if (desc != nullptr) {
        spdlog::info("Description of model: {}", desc->c_str());
    }

    // Field; sub-graph
    auto subgraphs = model_->subgraphs();
    if (subgraphs != nullptr) {
        spdlog::info("# of subgraph: {}", subgraphs->size());
    }
    //for (auto& subgraph : subgraphs) {
    //    subgraph->display_info();
    //}
    
    // Field; buffers
    auto buffers = model_->buffers();
    if (buffers != nullptr) {
        spdlog::info("# of buffers : {}", buffers->size());
    }

    // Field; operator_codes
    auto operator_codes = model_->operator_codes();
    if (operator_codes != nullptr) {
        spdlog::info("# of operator_codes: {}", operator_codes->size());
    }

    for (auto& sg : subgraphs_) {
        sg->display_info();
    }
    spdlog::info("--------------------------------------------");
}
