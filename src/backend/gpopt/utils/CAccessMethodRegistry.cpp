#include "gpopt/utils/CAccessMethodRegistry.h"

std::unordered_map<gpos::ULONG, AmOrcaCostEstimateFunc> gpos::CAccessMethodRegistry::costFunctionRegistry;

void gpos::CAccessMethodRegistry::RegisterCostEstimateFunction(ULONG oid, AmOrcaCostEstimateFunc func) {
    costFunctionRegistry[oid] = func;
}

AmOrcaCostEstimateFunc gpos::CAccessMethodRegistry::GetCostEstimateFunction(ULONG oid) {
    auto it = costFunctionRegistry.find(oid);
    if (it != costFunctionRegistry.end()) {
        return it->second;
    }
    return nullptr;
}

namespace {
    double hashorcacostestimate(CostInfo* ci)
    {
        double dCostPerIndexRow = ci->dTableWidth * ci->dIndexScanTupCostUnit;
        return ci->dNumRebinds *
                    (ci->dRowsIndex * dCostPerIndexRow);
    }

    struct CostFunctionRegistration {
        CostFunctionRegistration() {
            gpos::CAccessMethodRegistry::RegisterCostEstimateFunction(331, hashorcacostestimate);
        }
    };

    static CostFunctionRegistration registration;
}