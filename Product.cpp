#include "Product.hpp" 
#include <sstream>     


Product::Product(std::string name, Category category, double quantity, 
                 std::string expirationDate, std::string addedDate)
    : name(name), category(category), quantity(quantity), 
      expirationDate(expirationDate), addedDate(addedDate) {
}

bool Product::isExpired(std::string currentDate) const {
    return currentDate > expirationDate;
}


std::string Product::toString() const {
    std::stringstream ss;
    ss << name << "," 
       << categoryToString(category) << "," 
       << quantity << "," 
       << expirationDate << "," 
       << addedDate;
    
    return ss.str(); 
}


std::string Product::categoryToString(Category cat) {
    switch (cat) {
        case Category::DAIRY:     return "Dairy";
        case Category::MEAT:      return "Meat";
        case Category::VEGETABLE: return "Vegetable";
        case Category::FRUIT:     return "Fruit";
        case Category::OTHER:     return "Other";
        default:                  return "Unknown";
    }
}


std::string Product::getName() const {
    return name;
}

Category Product::getCategory() const {
    return category;
}

double Product::getQuantity() const {
    return quantity;
}

std::string Product::getExpirationDate() const {
    return expirationDate;
}