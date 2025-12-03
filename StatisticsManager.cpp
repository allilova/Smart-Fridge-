#include "StatisticsManager.hpp"
#include <iomanip>

void StatisticsManager::logProductConsumption(const std::string& productName){
    consumptionHistory[productName]++;
}

void StatisticsManager::MostUsedProducts(){
    std::cout << "Most Used Products:\n";

    if(consumptionHistory.empty()){
        std::cout << "No consumption data available.\n";
        return;
    }

    std::vector<std::pair<std::string, int>> sortedList;
    for(const auto& item : consumptionHistory){
        sortedList.push_back(item);
    }

    std::sort(sortedList.begin(), sortedList.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b){
        return a.second > b.second;
    });

    int count = 0;
    for(const auto& item : sortedList){
        std::cout << count + 1 << ". " << item.first << " -> " << item.second << " pati\n";
        count++;
        if(count >= 5) break;
    }
}

void StatisticsManager::TrackingExhaustionRates(){
    std::cout << "Frequency of depletion (%)\n";
    if(consumptionHistory.empty()){
        std::cout << "No consumption data available.\n";
        return;
    }

    int totalItemsConsumed = 0;
    for(const auto& item : consumptionHistory){
        totalItemsConsumed += item.second;
    }

    std::cout << std::left << std::setw(20) << "Product" << "Depletion Rate (%)\n";

    for(const auto& item : consumptionHistory){
        double percentage = (double)item.second / totalItemsConsumed * 100.0;

        std::cout << std::left << std::setw(20) << item.first << std::fixed << std::setprecision(1) << percentage << "%\n";
    }
}

void StatisticsManager::BasicStatistics(){
    std::cout << "Basic Statistics:\n";
    if(consumptionHistory.empty()){
        std::cout << "No consumption data available.\n";
        return;
    }

    for(const auto& item : consumptionHistory){
        std::string name = item.first;
        int count = item.second;

        std::cout << std::left << std::setw(15) << name << " | ";

        for(int i = 0; i < count; i++){
            std::cout << "#";
        }
        std::cout << " (" << count << ")\n";
    }
}