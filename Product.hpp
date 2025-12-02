#ifndef PRODUCT_HPP 
#define PRODUCT_HPP

#include <string>
#include <iostream>

enum class Category {
    DAIRY,      
    MEAT,      
    VEGETABLE,  
    FRUIT,      
    OTHER      
};

class Product {
private:
    std::string name;
    Category category;
    double quantity;          
    std::string expirationDate; 
    std::string addedDate;      

public:
    Product(std::string name, Category category, double quantity, 
            std::string expirationDate, std::string addedDate);
            
    bool isExpired(std::string currentDate) const;
    std::string toString() const;

    std::string getName() const;
    Category getCategory() const;
    double getQuantity() const;
    std::string getExpirationDate() const;

    static std::string categoryToString(Category cat);
};

#endif 