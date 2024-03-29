#include "tsubgraph.h"
#include "toperator.h"
#include "spdlog/spdlog.h"

TSubGraph::TSubGraph(const tflite::SubGraph* sg,
        const flatbuffers::Vector<flatbuffers::Offset<tflite::OperatorCode>>* operator_codes) {
    subgraph_ = sg;

    int i = 0;
    for (auto t : *subgraph_->tensors()) {
        tensors_.push_back(std::make_shared<TTensor>(t, i++));
    }

    i = 0;
    for (auto o : *subgraph_->operators()) {
        auto opcode = o->opcode_index();
        auto operator_code = operator_codes->Get(opcode);
        auto func = OpManager().GetCreateOpFunc(operator_code->builtin_code());
        operators_.push_back(func(o, i++));
    }

    spdlog::info("TSubGraph is created!");
}

TSubGraph::~TSubGraph(void) {
}

void TSubGraph::display_info(void) {
    spdlog::info("SubGraph -----------------------------------");
    // Field; name
    auto name = subgraph_->name();
    if (name != nullptr) {
        spdlog::info("Name of SubGraph: {}", name->c_str());
    }

    // Field; tensors
    spdlog::info("# of tensors  : {}", subgraph_->tensors()->size());
    spdlog::info("# of inputs   : {}", subgraph_->inputs()->size());
    spdlog::info("# of outputs  : {}", subgraph_->outputs()->size());
    spdlog::info("# of operators: {}", subgraph_->operators()->size());

    for (auto& t : tensors_) {
        t->display_info();
    }

    for (auto& op : operators_) {
        op->display_info();
    }
    spdlog::info("--------------------------------------------");
}
