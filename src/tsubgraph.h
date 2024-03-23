#ifndef __TSUBGRAPH_H__
#define __TSUBGRAPH_H__

#include <vector>

#include "schema_v3a_generated.h"
#include "toperator.h"
#include "ttensor.h"

class TSubGraph {
public:
    TSubGraph(const tflite::SubGraph* sg);
    ~TSubGraph(void);

    void display_info(void);
private:
    const tflite::SubGraph* subgraph_;
    TTensorPList tensors_;
    TOperatorPList operators_;
};

using TSubGraphPList = std::vector<std::shared_ptr<TSubGraph>>;
#endif
