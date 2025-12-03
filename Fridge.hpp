#ifndef FRIDGE_HPP
#define FRIDGE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Product.hpp"

class Fridge{
    private:
    std::vector<Product> products;

    const std::string filename = "fridge_data.txt";


    public:
    const std::vector<Product>& getContents() const { return products; }
     void addProduct(const Product& p);
     void removeProduct(const Product& p);
     void searchProduct();
     void sortProducts();
     void displayProducts() const;
     void expiredProducts();
     void generateListOfMissingProducts();
     void saveToFile() const;
     void loadFromFile();
};

#endif