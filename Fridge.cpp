#include "Fridge.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

void Fridge::addProduct(const Product& p){
    products.push_back(p);

    saveToFile();
}

void Fridge::removeProduct(const Product& p){
    std::string nameToRemove = p.getName();

    auto it = std::remove_if(products.begin(), products.end(), [&nameToRemove](const Product& prod){
                                 return prod.getName() == nameToRemove;});
    if(it != products.end()){
        products.erase(it, products.end());
        std::cout << "Product " << nameToRemove << "successfully." << std::endl;
        saveToFile();
    }else{
        std::cout << "Product " << nameToRemove << " not found in fridge." << std::endl;
    }

}

void Fridge::searchProduct(){
    std::string searchName;
    std::cout << "Enter product name to search: ";
    std::cin.ignore();
    std::getline(std::cin, searchName);

    bool found = false;
    for(const auto& p : products){
        if(p.getName() == searchName){
            std::cout << "Product found: " << p.toString() << std::endl;
            found = true;
            
        }
    }
    if(!found){
        std::cout << "Product " << searchName << " not found in fridge." << std::endl;
    }
}

void Fridge::sortProducts(){
    std::sort(products.begin(), products.end(), [](const Product& a, const Product& b){
        return a.getExpirationDate() < b.getExpirationDate();
    });
    std::cout << "Products sorted by expiration date." << std::endl;
}

void Fridge::saveToFile() const {
    std::ofstream file(filename, std::ios::trunc);
    if(file.is_open()){
        for(const auto& product : products){
            file << product.toString() << "\n";
        }
        file.close();
        std::cout << "Data saved successfully!" << std::endl;
    }else{
        std::cerr << "Error opening file for writing: " << std::endl;
    }
    }
void Fridge::displayProducts() const{
    if(products.empty()){
        std::cout << "Fridge is empty." << std::endl;
        return;
    }
    std::cout << "Products in Fridge:" << std::endl;
    for(const auto& p : products){
        std::cout << p.toString() << std::endl;
    }
}

void Fridge::expiredProducts(){
    std::string today;
    std::cout << "Enter today's date (YYYY-MM-DD): ";
    std::cin >> today;

    std::cout << "Expired Products:" << std::endl;
    bool hasExpired = false;
    for(const auto& p : products){
        if(p.isExpired(today)){
            std::cout <<"Attention!" << p.getName() << "(Expiration Date is:" << p.getExpirationDate() << ")\n";
            hasExpired = true;
        }
    }
    if(!hasExpired){
        std::cout << "No expired products found." << std::endl;
    }
}

void Fridge::generateListOfMissingProducts(){
    std::cout << "List of Missing Products:" << std::endl;
    for(const auto& p : products){
        if(p.getQuantity() < 1.0){
            std::cout <<"- "<< p.getName() << std::endl;
        }
    }
}

void Fridge::loadFromFile(){
    std::ifstream file(filename);
    if(!file.is_open()){
        return;
    }
    products.clear();
    std::string line;
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string segment;

        std::string name, catStr, expDate, addedDate;
        double quantity;

        if(!std::getline(ss, name, ',')) continue;
        if(!std::getline(ss, catStr, ',')) continue;

        std::string qtyStr;
        if(!std::getline(ss, qtyStr, ',')) continue;
        quantity = std::stod(qtyStr);

        if(!std::getline(ss, expDate, ',')) continue;
        if(!std::getline(ss, addedDate, ',')) continue;

        Category cat = Category::OTHER;
        if(catStr == "DAIRY") cat = Category::DAIRY;
        else if(catStr == "MEAT") cat = Category::MEAT;
        else if(catStr == "VEGETABLE") cat = Category::VEGETABLE;
        else if(catStr == "FRUIT") cat = Category::FRUIT;

        Product loadedProduct(name, cat, quantity, expDate, addedDate);
        products.push_back(loadedProduct);
    }
    file.close();
    std::cout << "Data loaded successfully!" << std::endl;
}
