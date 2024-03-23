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
    OperatorManager(tflite::BuiltinOperator opcode, func_ptr f) {
        RegisterOperator(opcode, f);
        spdlog::info("Operator Constructor: {}", OperatorManager::op_map.size());
    }
    ~OperatorManager(void) {
    }

    void RegisterOperator(tflite::BuiltinOperator opcode,
            func_ptr f) {
        if (op_map_init == false) {
            OperatorManager::op_map = {};
            op_map_init = true;
        }
        OperatorManager::op_map.insert({opcode, f});
    }
    static std::map<tflite::BuiltinOperator, func_ptr> op_map;
    static bool op_map_init;
private:
};
//extern OperatorManager opmng;

using TOperatorPList = std::vector<std::shared_ptr<TOperator>>;
#endif
