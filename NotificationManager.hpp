#ifndef NotificationManager_HPP
#define NotificationManager_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Product.hpp"

class NotificationManager{
    public:
    void notifyExpirationDateApproaching(const std::vector<Product>& fridgeContents, const std::string& currentDate);
    void notifyExpiredProducts(const std::vector<Product>& fridgeContents, const std::string& currentDate);
    void notifyAddedProduct(const std::string& productName);
    void notifyRemovedProduct(const std::string& productName);
};
#endif