#ifndef StatisticsManager_HPP
#define StatisticsManager_HPP
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

class StatisticsManager{
    private:
        std::map<std::string, int> consumptionHistory;
    public:
    void logProductConsumption(const std::string& productName);
    
    void MostUsedProducts();
    void TrackingExhaustionRates();
    void BasicStatistics();
};
#endif