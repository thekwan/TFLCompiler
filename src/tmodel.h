#ifndef __TMODEL_H__
#define __TMODEL_H__

#include "schema_v3a_generated.h"

#include "tsubgraph.h"

class TModel {
public:
    TModel(const char* buf);
    ~TModel(void);

    void display_info(void);
private:
    const tflite::Model *model_;
    TSubGraphPList subgraphs_;
};
#endif
