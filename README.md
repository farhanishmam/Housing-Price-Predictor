# Housing-Price-Predictor
        Project: Housing Price Predictor

The housing price predictor is a program to get a quick and easy estimate of the real price of housing properties. There are times when people with no idea on housing prices, struggle to find and buy the right house at the right price. Same goes for people who are trying to sell their houses and has no idea what they should ask for. Our Housing Price Estimator is developed with the intention to provide potential buyers, sellers and even professionals an approximation of housing prices. Our goal is to create more transparency between the buyers and sellers in the real estate industry. 

Features:

By the end of the project, we are expecting our program to be capable of 
-	Accurately estimating the price of a house by considering its location and area
-	Graphically present the price against area and price against location graphs to the user for visual data representation 
-	Update the model based on frequent data feed (since price varies with time)   
   
Implementation:

The program is a simple and straight-forward implementation of machine learning in the practical field. Machine learning is the process by which a computer program can do certain tasks based on the on-field data fed to the program instead of being explicitly programmed. In our case, the “machine” is equivalent to our computer program and the “learning” part is when the computer generates a model based on the data given to it. In this way, the computer can estimate a price coherent to the data we provided.
The whole program is planned to be implemented in the five following steps:

1)	Selecting the model

First, we select a model based on which we are supposed to gather our data. In our case, we selected a model where we consider the price, area and location of the houses. In the future, we are hoping to add more features to this model and also develop new ones for other purposes.

2)	Gathering the data
Data on appropriate price of houses at different locations along with the area of the house is gathered by our experts which is directly fed to our program. In our testing case, we use data which are randomly generated from a program along with its reference model.
3)	Building the model
Based on the current database, our program builds the model which we selected earlier. The model is build using C-programming language for coding. Our approach to building the model is linear regression with multiple variables which would be implemented using the gradient descend algorithm. Here the number of variables would be equivalent to the number of factors we are considering.

4)	Predicting the price

The price is to be predicted by comparing the data to each variable of the model. A certain factor value is derived from the model for each variable. The factor value is then multiplied to weighted value of each factor, which would produce the estimated price.

5)	Producing the graphs 

Based on the data comparison of each variable, we will produce the graphs. In our case, price against location and price against area graphs would be produced. An analysis on the key points of the graph is also given. 

6)	Evaluating and presenting the results 

The model is then compared with the pre-existing reference model. The difference is to be minimized by making necessary changes in the code. The final result is to be graphically presented to the user using a third part library called SDL.


Timeline:

Week-(1-2):  Creating all the required matrix functions
Week-3:  Implementing the gradient descend algorithm 
Week-4:  Creating test data based on existing model and feeding it to the program
Week-5:  Creating a test model
Week-6:  Comparing the test model with reference model
Week-7: Make necessary changes on test model
Week-(8-9): Building and integrating the GUI 

Future plans:

Although, the current number of features is not enough to provide a realistic estimation, in the future, we are hoping to add more features to our program which will help in proving a more accurate and realistic prediction.
We are hoping to:
-	Add more factors to consider (number of bedrooms, number of bathrooms, flooring, material used) 
-	Implement the program for a wide variety of houses other than apartment flats (e.g. villas, ranch-style houses, duplex, triplex etc.)
-	Implement the program for real-estate and properties 
-	Implement the program for property renting
-	Integrate a web-based buying-selling feature which will search for potential buyers and sellers based on vacancy along with price prediction


 



