#include "tmodel.h"
#include "spdlog/spdlog.h"

TModel::TModel(const char* buf) {
    model_ = tflite::GetModel(buf);
}

TModel::~TModel(void) {
    delete [] model_;
}

void TModel::display_info(void) {
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
}
