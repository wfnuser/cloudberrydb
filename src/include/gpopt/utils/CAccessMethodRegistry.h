#ifndef GPDXL_CAccessMethodRegistry_H
#define GPDXL_CAccessMethodRegistry_H

#include "gpos/base.h"

#include <unordered_map>

extern "C" 
{
    #include "access/amorca.h"
}


// TODO: should use OID instead of oid
namespace gpos
{
class CAccessMethodRegistry {
public:
    static void RegisterCostEstimateFunction(ULONG oid, AmOrcaCostEstimateFunc func);
    static AmOrcaCostEstimateFunc GetCostEstimateFunction(ULONG oid);

private:
    static std::unordered_map<ULONG, AmOrcaCostEstimateFunc> costFunctionRegistry;
};
}

#endif




