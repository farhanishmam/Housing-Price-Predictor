# Housing Price Predictor

My first C++ project. The Housing Price Predictor is a program designed to provide quick and easy estimates of real estate prices. It aims to assist individuals who may lack knowledge about housing prices, helping them to buy or sell properties at fair market values. This tool is also useful for professionals in the real estate industry, fostering greater transparency between buyers and sellers.

## Features:

-	Accurately estimate house price based on location and area.
-	Graphically present the price vs. area and price vs. location to the user.
-	Update the model based on frequent data feed (since the price varies with time).  
   
## Implementation:

The Housing Price Predictor uses machine learning principles implemented in C/C++. The process can be broken down into the following steps: 

1. **Selecting the Model:** We chose a model that considers the price, area, and location of houses. In the future, we plan to include more features and models for diverse use cases.
2. **Gathering the Data:** Data on house prices, locations, and areas are collected by experts and fed into the program. For testing, we use randomly generated data that aligns with a reference model.
3. **Building the Model:** The model is constructed using a linear regression algorithm with multiple variables, implemented in C/C++. We use the gradient descent algorithm to optimize the model. The variables include all factors influencing housing prices.
4. **Predicting the Price:** The program predicts housing prices by comparing input data to the model variables. Each factor is multiplied by its corresponding weight, producing an estimated price.
5. **Visualization:** Graphs showing price vs. location and price vs. area are generated based on the model's predictions. Key points on these graphs are analyzed to provide insights.
6. **Evaluation:** The generated model is evaluated against a pre-existing reference model. The final results are graphically presented using the `SDL` library.

## Getting Started

### Prerequisites
- C/C++ compiler (GCC, Clang, etc.)
- SDL library for graphical output

### Installation
1. Clone the repository:
   ```
   git clone https://github.com/yourusername/housing-price-predictor.git
   cd housing-price-predictor
   ```
2. Build the project:
   ```
   g++ main.cpp -o housePricePredictor
   ```
3. Run the program:
   ```
   ./housePricePredictor
   ```