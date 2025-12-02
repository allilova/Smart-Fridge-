#include <iostream>
#include "Product.hpp" 

int main() {
    
    Product myMilk("Vereia", Category::DAIRY, 1.0, "2023-12-01", "2023-11-20");

    std::cout << "Product Info: " << myMilk.toString() << std::endl;

    std::string today = "2023-12-05"; 
    
    if (myMilk.isExpired(today)) {
        std::cout << "Vnimanie! " << myMilk.getName() << " e s iztekal srok!" << std::endl;
    } else {
        std::cout << "Produkta e v srok." << std::endl;
    }

    return 0;
}