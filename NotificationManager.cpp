#include "NotificationManager.hpp"

void NotificationManager::notifyAddedProduct(const std::string& productName){
    std::cout << "Notification: Product added - " << productName << "\n";
}

void NotificationManager::notifyRemovedProduct(const std::string& productName){
    std::cout << "Notification: Product removed - " << productName << "\n";
}

void NotificationManager::notifyExpiredProducts(const std::vector<Product>& fridgeContents, const std::string& currentDate){
    bool foundExpired = false;

    for(const auto& product : fridgeContents){
        if(product.isExpired(currentDate)){
            if(!foundExpired){
                std::cout << "Notification: The following products have expired:\n";
                foundExpired = true;
            }
            std::cout << "-> "<< product.getName() << " (Expired on: " << product.getExpirationDate() << ")\n";
        }
    }

    if(foundExpired){
        std::cout << "Please consider removing them from the fridge.\n";
    }
}

void NotificationManager::notifyExpirationDateApproaching(const std::vector<Product>& fridgeContents, const std::string& currentDate){
    bool foundApproaching = false;

    for(const auto& product : fridgeContents){
     if(!product.isExpired(currentDate) && product.getExpirationDate() == currentDate){
        if(!foundApproaching){
            std::cout << "Notification: The following products are expiring today:\n";
            foundApproaching = true;
        }
        std::cout << "-> " << product.getName() << " must be eaten today \n";
     }
    }
}