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
        std::cout << "2. Remove Product\n";;
        std::cout << "3. Search Product\n";
        std::cout << "4. Show available products\n";
        std::cout << "5. Check Expired Products\n";
        std::cout << "6. Missing products (Quantity < 1)\n";
        std::cout << "7. Recommend Recipes\n";
        std::cout << "8. Consumption statistics\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";

        if(!(std::cin >> choice)){
            clearInputBuffer();
            continue;
        }
        std::cin.ignore();
        if(choice == 9){
            std::cout << "Exiting Smart Fridge. Goodbye!\n";
            break;
        }

        switch (choice){
        case 1:{
            std::string name, expDate, addedDate;
            double quantity;

            std::cout << "Enter product name: ";
            std::getline(std::cin, name);
            Category category = inputCategory();

            std::cout << "Enter quantity: ";
            while(!(std::cin >> quantity)){
                std::cout << "Invalid input. Please enter a valid quantity: ";
                clearInputBuffer();
            }
            std::cin.ignore();
            std::cout << "Enter expiration date (YYYY-MM-DD): ";
            std::getline(std::cin, expDate);
            std::cout << "Enter added date (YYYY-MM-DD): ";
            std::getline(std::cin, addedDate);
            Product newProduct(name, category, quantity, expDate, addedDate);
            myFridge.addProduct(newProduct);
            notifier.notifyAddedProduct(name);
            break;
        }
        case 2: {
            std::string nameToRemove;
            std::cout << "Enter product name to remove: ";
            std::getline(std::cin, nameToRemove);
            Product tempProd(nameToRemove, Category::OTHER, 0, "", "");
            myFridge.removeProduct(tempProd);
            notifier.notifyRemovedProduct(nameToRemove);
            stats.logProductConsumption(nameToRemove);
            break;
        }
        case 3:
            myFridge.searchProduct();
            break;
        case 4:
            char sortChoice;
            std::cout << "Sort products before displaying? (y/n): ";
            std::cin >> sortChoice;
            if(sortChoice == 'y' || sortChoice == 'Y'){
                myFridge.sortProducts();
            }
            myFridge.displayProducts();
            break;
        case 5:
            myFridge.expiredProducts();
            std::cout << "Enter today's date (YYYY-MM-DD) for expiration check: ";
            std::cin >> todayDate;
            notifier.notifyExpirationDateApproaching(myFridge.getContents(), todayDate);
            break;
        case 6:
            myFridge.generateListOfMissingProducts();
            break;
        case 7:{
            std::vector<Product> currentContents = myFridge.getContents();
            std::cout << "Analyzing fridge contents for recipe recommendations...\n";
            recommender.analyzerProductsInFridge(currentContents);
            std::cout << "Recommended Recipes:\n";
            recommender.recommendRecipes(currentContents);
            std::cout << "Checking for missing products for recipes...\n";
            recommender.checkMissingProductsForRecipe(currentContents);
            break;
        }
        case 8:{
            std::cout << "Statistics:\n";
            stats.MostUsedProducts();
            std::cout << "\n";
            stats.TrackingExhaustionRates();
            std::cout << "\n";
            stats.BasicStatistics();
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
}
 return 0;
}