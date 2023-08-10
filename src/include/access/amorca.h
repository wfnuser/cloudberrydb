#include <stdint.h>

#ifndef AMORCA_H
#define AMORCA_H

typedef struct CostInfo
{
    double dTableWidth;
    double dIndexFilterCostUnit;
    double dIndexScanTupCostUnit;
    double dIndexScanTupRandomFactor;
    double dRowsIndex;
    double dNumRebinds;
    uint32_t ulIndexKeys;
} CostInfo;

typedef double (*AmOrcaCostEstimateFunc) (CostInfo* ci);

#endif   /* AMORCA_H */
