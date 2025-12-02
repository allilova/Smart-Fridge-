#include "Fridge.hpp"
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
    for(const auto& p : products){
        std::cout << p.toString() << std::endl;
    }
}

