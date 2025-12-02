#include "Fridge.hpp"
#include <sstream>

void Fridge::addProduct(const Product& p){
    products.push_back(p);

    saveToFile();
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
