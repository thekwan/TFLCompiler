#ifndef __TOPERATOR_H__
#define __TOPERATOR_H__

#include <map>
#include "schema_v3a_generated.h"
#include "spdlog/spdlog.h"

class TOperator {
public:
    TOperator(const tflite::Operator* op, const int index);
    ~TOperator(void);

    void display_info(void);
    //virtual void run_forward(void) = 0;
private:
    const tflite::Operator* operator_;
    const int operator_index_;
    std::vector<int> inputs_;
    std::vector<int> outputs_;
    uint32_t opcode_index_;
};

typedef std::shared_ptr<TOperator>(*func_ptr)(const tflite::Operator*, int);

class OperatorManager {
public:
    OperatorManager() { op_map = {}; }
    ~OperatorManager() {}

    void RegisterOperator(tflite::BuiltinOperator opcode, func_ptr f) {
        assert(op_map.find(opcode) == op_map.end());
        op_map.insert({opcode, f});
        spdlog::info("op_map.size = {}", op_map.size());
    }

    func_ptr GetCreateOpFunc(tflite::BuiltinOperator opcode) {
        assert(op_map.find(opcode) != op_map.end());
        return op_map[opcode];
    }
private:
    std::map<tflite::BuiltinOperator, func_ptr> op_map;
};

OperatorManager& OpManager();

class OperatorRegister {
public:
    OperatorRegister(tflite::BuiltinOperator opcode, func_ptr f) {
        OpManager().RegisterOperator(opcode, f);
    }
};

using TOperatorPList = std::vector<std::shared_ptr<TOperator>>;
#endif
