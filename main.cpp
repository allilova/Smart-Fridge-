#include <iostream>
#include <string>
#include "Fridge.hpp"
#include "NotificationManager.hpp"
#include "RecipeRecommender.hpp"
#include "StatisticsManager.hpp"
#include "Product.hpp" 

void clearInputBuffer(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Category inputCategory(){
    int choice;
    std::cout << "Select Category:\n";
    std::cout << "0. DAIRY\n";
    std::cout << "1. MEAT\n";
    std::cout << "2. VEGETABLE\n";
    std::cout << "3. FRUIT\n";
    std::cout << "4. OTHER\n";
    std::cout << "Enter choice (1-5): ";
    while(!(std::cin >> choice) || choice < 0 || choice > 4){
        std::cout << "Invalid input. Please enter a number between 1 and 5: ";
        clearInputBuffer();
    }
    std::cin.ignore();
    return static_cast<Category>(choice);
}

int main() {
    Fridge myFridge;
    NotificationManager notifier;
    RecipeRecommender recommender;
    StatisticsManager stats;

    myFridge.loadFromFile();

    int choice = 0;
    std::string todayDate;

    while (true){
        std::cout << "\nSmart Fridge Menu:\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. Remove Product\n";
        std::cout << "3. View Fridge Contents\n";
        std::cout << "4. Search Product\n";
        std::cout << "5. Sort Products\n";
        std::cout << "6. Check Expired Products\n";
        std::cout << "7. Analyze Fridge Contents\n";
        std::cout << "8. Recommend Recipes\n";
        std::cout << "9. Generate Shopping List for Recipes\n";
        std::cout << "10. View Statistics\n";
        std::cout << "11. Set Today's Date\n";
        std::cout << "12. Exit\n";
        std::cout << "Enter your choice: ";

        if(!(std::cin >> choice)){
            clearInputBuffer();
            continue;
        }
        std::cin.ignore();
        if(choice == 12){
            std::cout << "Exiting Smart Fridge. Goodbye!\n";
            break;
        }

        

    

    return 0;
}