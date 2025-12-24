# Smart-Fridge-
Smart Fridge Simulator: A C++ console application for tracking products, expiration dates, and automatically generating shopping lists.
# 🧊 Smart Fridge System

Smart Fridge is a console-based C++ application designed to help users manage food products in their refrigerator efficiently. The system tracks quantities, expiration dates, provides consumption statistics, and recommends recipes based on available ingredients.

## ✨ Key Features

* **Inventory Management**: Add, remove, and search for products in the fridge.
* **Expiration Tracking**: Automatically notifies users about expired products and items expiring on the current day.
* **Data Persistence**: Automatically saves and loads data from a file (`fridge_data.txt`), ensuring no information is lost between sessions.
* **Recipe Recommendations**: 
  * Suggests recipes that can be cooked with current stock.
  * Generates a "Shopping List" for recipes where only a few ingredients are missing.
* **Consumption Statistics**: Tracks frequently used products and visualizes depletion rates.
* **Smart Sorting**: Allows users to sort products by expiration date for better organization.

## 🛠️ Technical Stack

* **Language**: C++11 or higher.
* **Libraries**: Standard C++ Library (`iostream`, `vector`, `string`, `algorithm`, `fstream`, `map`).
* **Storage**: Text-based CSV-style persistence (`fridge_data.txt`).

## 🚀 Compilation and Execution

To compile the project, use `g++` or any standard C++ compiler:

```bash
g++ main.cpp Fridge.cpp Product.cpp NotificationManager.cpp RecipeRecommender.cpp StatisticsManager.cpp -o SmartFridge
```

Run the application:

```bash
./SmartFridge
```

## 👤 Author: Aleksandra Lilova