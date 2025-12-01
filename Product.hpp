#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

class Product {
public:
    
    Product(std::string n, std::string c, double q, std::string exDate, std::string adDate) {
        name = n;
        quantity = q;
        expiryDate = exDate;
        addedDate = adDate;

       
        if (isValidCategory(c)) {
            category = c;
        } else {
            category = "other"; 
            std::cout << "Warning: Invalid category for " << n << ". Set to 'other'.\n";
        }
    }

    ~Product() {}

    
    void displayInfo() const {
        std::cout << "Name: " << name << "\n"
                  << "Category: " << category << "\n"
                  << "Quantity: " << quantity << "\n"
                  << "Expires: " << expiryDate << "\n"
                  << "Added: " << addedDate << "\n"
                  << "--------------------------\n";
    }

private:
    std::string name;
    std::string category; 
    double quantity;      
    std::string expiryDate;
    std::string addedDate;
    bool isValidCategory(const std::string& c) {
        const std::vector<std::string> validCategories = {"dairy", "meat", "vegetable", "fruit", "drink", "other"};
        for (const auto& valid : validCategories) {
            if (valid == c) return true;
        }
        return false;
    }
};