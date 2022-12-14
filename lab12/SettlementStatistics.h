//
// Created by timea on 12/13/2022.
//

#ifndef CPP_2022_SETTLEMENTSTATISTICS_H
#define CPP_2022_SETTLEMENTSTATISTICS_H

#include "Settlement.h"
#include <vector>

using namespace std;

class SettlementStatistics {
public:
    virtual int numSettlements() const = 0;
    virtual int numCounties() const = 0;
    virtual int numSettlementsByCounty(const string& county) const = 0;
    virtual vector<Settlement> findSettlementsByCounty(
            const string& county) const = 0;
    virtual Settlement findSettlementsByNameAndCounty( const string& name, const string& county) const = 0;
    virtual Settlement maxPopulationDensity() const = 0;
    virtual Settlement minPopulationDensity() const = 0;
    virtual vector<Settlement> findSettlementsByName(const string& name) = 0;
};


#endif //CPP_2022_SETTLEMENTSTATISTICS_H
