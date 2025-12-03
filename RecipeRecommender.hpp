#ifndef RecipeRecommender_HPP
#define RecipeRecommender_HPP
#include <iostream>
#include <vector>
#include <string>
#include "Product.hpp"

struct Recipe{
    std::string name;
    std::vector<std::string> requiredIngredients;
};

class RecipeRecommender {
    private:
        std::vector<Recipe> recipeDatabase;

    public:
        RecipeRecommender();
        void analyzerProductsInFridge(const std::vector<Product>& fridgeContents);
        void recommendRecipes(const std::vector<Product>& fridgeContents);
        bool isIngredientAvailable(const std::string ingredient, const std::vector<Product>& fridgeContents);
        void checkMissingProductsForRecipe(const std::vector<Product>& fridgeContents);
};
#endif