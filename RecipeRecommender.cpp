#include "RecipeRecommender.hpp"
#include <algorithm>

RecipeRecommender::RecipeRecommender(){
    Recipe r1;
    r1.name = "Tarator";
    r1.requiredIngredients = {"cucumber", "yogurt", "garlic", "water", "dill"};
    recipeDatabase.push_back(r1);

    Recipe r2;
    r1.name = "Shopska Salad";
    r1.requiredIngredients = {"tomato", "cucumber", "cheese", "onion", "peppers"};
    recipeDatabase.push_back(r2);

    Recipe r3;
    r1.name = "Omlette";
    r1.requiredIngredients = {"eggs", "cheese", "oil", "milk"};
    recipeDatabase.push_back(r3);

    Recipe r4;
    r1.name = "Musaka";
    r1.requiredIngredients = {"meat", "potato", "onion", "yoghurt", "eggs"};
    recipeDatabase.push_back(r4);

    Recipe r5;
    r1.name = "Fruit Salad";
    r1.requiredIngredients = {"apple", "banana", "orange", "honey"};
    recipeDatabase.push_back(r5);
}

bool RecipeRecommender::isIngredientAvailable(const std::string ingredient, const std::vector<Product>& fridgeContents){
    for(const auto& product : fridgeContents){
        if(product.getName().find(ingredient) != std::string::npos){
            if(product.getQuantity() > 0){
                return true;
            }
        }
    }
    return false;
}

void RecipeRecommender::analyzerProductsInFridge(const std::vector<Product>& fridgeContents){
    std::cout << "Analyzing fridge contents:\n";
    if(fridgeContents.empty()){
        std::cout << "The fridge is empty.\n";
        return;
    }
    std::cout << "Total products in fridge: " << fridgeContents.size() << "\n";
    std::cout << "Available products:\n";
    for(const auto& product : fridgeContents){
        std::cout << "- " << product.getName() << " (" << product.getQuantity() << ")\n";
    }

}

void RecipeRecommender::recommendRecipes(const std::vector<Product>& fridgeContents){
    std::cout << "Recommended Recipes based on your fridge contents:\n";
   bool foundAny = false;
   for(const auto& recipe : recipeDatabase){
    std::vector<std::string> missing;
    for(const auto& ingr : recipe.requiredIngredients){
        if(!isIngredientAvailable(ingr, fridgeContents)){
            missing.push_back(ingr);
        }
    }
    if(missing.empty()){
        std::cout << "Cook: " << recipe.name << "You have all the ingredients!\n";
        foundAny = true;
    }
   }
    if(!foundAny){
     std::cout << "No complete recipes can be made with the current fridge contents.\n";
    std::cout << "Consider checking missing ingredients for recipes.\n";
    }
}

void RecipeRecommender::checkMissingProductsForRecipe(const std::vector<Product>& fridgeContents){
    std::cout << "SHOPPING LIST (Related recipes): \n";
    bool potentialRecipesFound = false;
    for(const auto& recipe : recipeDatabase){
        std::vector<std::string> missing;

        for(const auto& ingr : recipe.requiredIngredients){
            if(!isIngredientAvailable(ingr, fridgeContents)){
                missing.push_back(ingr);
            }
        }

        if(missing.size() > 0 && missing.size() <=3 ){
            std::cout << "To make " << recipe.name << ", you need to buy:\n";
            for(const auto& m : missing){
                std::cout << " [ ]" << m << "\n";
            }
            potentialRecipesFound = true;
        }
    }
    if(!potentialRecipesFound){
        std::cout << "You have most ingredients for all recipes! Great job!\n";
    }
}

