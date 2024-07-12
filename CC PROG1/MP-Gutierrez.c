/**************************************************************************************
This is to certify that this project is my own work, based on my personal efforts in
studying and applying the concepts learned. I have constructed the functions and
their respective algorithms and corresponding code by myself. The program was
run, tested, and debugged by my own efforts. I further certify that I have not copied
in part or whole or otherwise plagiarized the work of other students and/or persons.
                                      <Allen Andrei D. Gutierrez>, DLSU ID#<12207292>
**************************************************************************************/
/*
	Description: This program takes a maximum of three orders
				 then calculates the bill.
	Programmed by: <Allen Andrei Gutierrez> <Block 13 - S26A>
	Last modified: <December 4, 2022>
	Version:  <1>
	[Acknowledgements: <https://www.youtube.com/watch?v=QCe2ks9b8YI>]
*/
#include <stdio.h>
#include <stdlib.h>

/* This function displays the menu as well as the IDs for the meal of the
	day discount
Precondition: None
@param *SetMain is the random number assigned for SetMain
@param *SetSide is the random number assigned for SetSide
@param *SetDrink is the random number assigned for SetDrink
@return nothing as the function is void
*/
void displayMenu (int *SetMain, int *SetSide, int *SetDrink)
{
	//Assigns Random numbers for the Meal set of the day
	//Values changes as the program repeats
	*SetMain = (rand()%4) + 1;
	*SetSide= (rand()%4) + 1;
	*SetDrink = (rand()%4) + 1;
	
	printf("\nMains:\n");
	printf("ID %8s%30s\n", "Type", "Price");
	printf("%5d%20s%16.2f\n", 1, "Chicken", 90.00);
	printf("%5d%19s%18.2f\n", 2, "Pork", 105.00);
	printf("%5d%19s%18.2f\n", 3, "Fish", 125.00);
	printf("%5d%19s%18.2f\n", 4, "Beef", 135.00);
	printf("\nSides:\n");
	printf("ID %8s%30s\n", "Type", "Price");
	printf("%5d%23s%13.2f\n", 1, "Steamed Rice", 20.00);
	printf("%5d%23s%13.2f\n", 2, "Shredded Corn", 35.00);
	printf("%5d%24s%12.2f\n", 3, "Mashed Potatoes", 50.00);
	printf("%5d%26s%10.2f\n", 4, "Steamed Vegetables", 65.00);
	printf("\nDrinks:\n");
	printf("ID %8s%30s\n", "Type", "Price");
	printf("%5d%22s%14.2f\n", 1, "Mineral Water", 25.00);
	printf("%5d%19s%17.2f\n", 2, "Iced Tea", 35.00);
	printf("%5d%17s%19.2f\n", 3, "Soda", 45.00);
	printf("%5d%20s%16.2f\n", 4, "Fruit Juice", 55.00);
	printf("\nMeal Set of the Day ID:\t%d\t%d\t%d\n", *SetMain, *SetSide, *SetDrink);
	printf("Order all three in one order and get 15 percent off!\n");
}

/* This function inputs the orders and computes the subtotal of the order
Precondition: The inputed values is not negative or characeters
@param *Main is the would be ID No. of Main
@param *Side is the would be ID NO. of Side
@param *Drink is the would be ID NO. of Drink
@param *mCost is the would be price of selected Main
@param *sCost is the would be price of selected Side
@param *dCost is the would be price of selected Drink
@param *OrderPrice is the would be price of the Order
@return the bill which is the subtotal of the order
*/
float getOrder (int *Main, int *Side, int *Drink, float *mCost, 
				float *sCost, float *dCost, float *OrderPrice)
{
	//Initialize variables for the scanf inputs
	char meal, bowl, glass;
	//Initialize variable for bill which is the *OrderPrice
	float bill = *OrderPrice;
	
	printf("\tMain: \t");
	scanf(" %c", &meal);
	
	//Case statement for the Main
	switch(meal)
	{
		case '1':
			*Main = 1;
			*mCost = 90.00;
			printf("%20s\n", "Chicken");
		break;
		case '2':
			*Main = 2;
			*mCost = 105.00;
			printf("%17s\n", "Pork");
			break;
		case '3':
			*Main = 3;
			*mCost = 120.00;
			printf("%17s\n","Fish");
			break;
		case '4':
			*Main = 4;
			*mCost = 135.00;
			printf("%17s\n","Beef");
			break;
		case '0':
			*Main = 0;
			*mCost = 0.00;
			printf("%17s\n","None");
			break;
		default:
			printf("Wrong Input please Change order and try again\n");
			*mCost = 0.00;
	}
	
	printf("\tSide: \t");
	scanf(" %c", &bowl);
	
	//Case statement for the Side 
	switch (bowl)
	{
		case '1':
			*Side = 1;
			*sCost = 20.00;
			printf("%25s\n","Steamed Rice");
		break;
		case '2':
			*Side = 2;
			*sCost = 35.00;
			printf("%26s\n","Shredded Corn");
			break;
		case '3':
			*Side = 3;
			*sCost = 50.00;
			printf("%28s\n", "Mashed Potatoes");
			break;
		case '4':
			*Side = 4;
			*sCost = 65.00;
			printf("%31s\n","Steamed Vegetables");
			break;
		case '0':
			*Side = 0;
			*sCost = 0.00;
			printf("%17s\n","None");
			break;
		default:
			printf("Wrong Input please Change order and try again\n");
			*sCost = 0.00;
	}
	
	printf("\tDrink: \t");
	scanf(" %c", &glass);
	
	//Case statement for the  Drink
	switch (glass)
	{
		case '1':
			*Drink = 1;
			*dCost = 25.00;
			printf("%27s\n","Mineral Water");
		break;
		case '2':
			*Drink = 2;
			*dCost = 35.00;
			printf("%22s\n","Iced Tea");
			break;
		case '3':
			*Drink = 3;
			*dCost = 40.00;
			printf("%18s\n","Soda");
			break;
		case '4':
			*Drink = 4;
			*dCost = 55.00;
			printf("%25s\n","Fruit Juice");
			break;
		case '0':
			*Drink = 0;
			*dCost = 0.00;
			printf("%18s\n", "None");
			break;
		default:
			printf("Wrong Input please Change order and try again\n");
			*dCost = 0.00;
	}
	*OrderPrice = *mCost + *sCost +*dCost;
	return bill;
}

/* This function inputs the orders and computes the subtotal of the order
Precondition: The inputted values are part of the conditional statements in
				the previous function
@param *Main is the ID No. of Main
@param *Side is the ID NO. of Side
@param *Drink is the ID NO. of Drink
@param *mCost is the price of selected Main
@param *sCost is the price of selected Side
@param *dCost is the price of selected Drink
@return nothing as the function is void
*/
void displayTotal (int *Main, int *Side, int *Drink, float *mCost, 
				float *sCost, float *dCost)
{
	//If statements for the printf output of Main
	if (*Main == 1)
	{
		printf("\tMain:%s%17.2f\n", "Chicken", *mCost);
	}
	else if (*Main == 2)
	{
		printf("\tMain:%s%20.2f\n", "Pork", *mCost);
	}
	else if (*Main == 3)
	{
		printf("\tMain:%s%20.2f\n", "Fish", *mCost);
	}
	else if (*Main == 4)
	{
		printf("\tMain:%s%20.2f\n", "Beef", *mCost);
	}
	else if (*Main == 0)
	{
		printf("\tMain:%s%20.2f\n", "None", *mCost);
	}

	//If statements for the printf output of Side
	if (*Side == 1)
	{
		printf("\tSide:%s%12.2f\n", "Steamed Rice", *sCost);
	}	
	else if (*Side == 2)
	{
		printf("\tSide:%s%11.2f\n", "Shredded Corn", *sCost);
	}
	else if (*Side == 3)
	{
		printf("\tSide:%s%9.2f\n", "Mashed Potatoes", *sCost);
	}
	else if (*Side == 4)
	{
		printf("\tSide:%s%6.2f\n", "Steamed Vegetables", *sCost);
	}
	else if (*Side == 0)
	{
		printf("\tSide:%s%20.2f\n", "None", *sCost);
	}
	
	//If statements for the printf output of Drink
	if (*Drink == 1)
	{
		printf("\tDrink:%s%10.2f\n", "Mineral Water", *dCost);
	}
	else if (*Drink == 2)
	{
		printf("\tDrink:%s%15.2f\n", "Iced Tea", *dCost);
	}
	else if (*Drink == 3)
	{
		printf("\tDrink:%s%19.2f\n", "Soda", *dCost);
	}
	else if (*Drink == 4)
	{
		printf("\tDrink:%s%12.2f\n", "Fruit Juice", *dCost);
	}
	else if (*Drink == 0)
	{
		printf("\tDrink:%s%19.2f\n", "None", *dCost);
	}
}

int main()
{
	//Initialize variables for Meal set of the day
	int SetMain, SetSide, SetDrink;
	//Initialize variables for Mains
	int Main1, Main2, Main3;
	//Initialize variables for Sides
	int Side1, Side2, Side3;
	//Initialize variables for Drinks
	int Drink1, Drink2, Drink3;
	//Initialize variables for Main costs
	float mCost1, mCost2, mCost3;
	//Initialize variables for Side costs
	float sCost1, sCost2, sCost3;
	//Initialize variables for Drink costs
	float dCost1, dCost2, dCost3;
	//Initialize variables for Subtotals
	float OrderPrice1, OrderPrice2, OrderPrice3;
	//Initialize variables for scanf confirm order loop
	int Confirm1, Confirm2, Confirm3;
	//Initialize variables for scanf modify order
	int Change1, Change2, Change3;
	//Initialize variables for scanf type of order cancel
	int Type1, Type2; 
	//Initialize variable for repeat order loop
	int Repeat;
	//Initialize variable for skip Order 3 loop
	int Skip; 
	//Initialize variable for Total Amount of orders
	float TotalAmt;
	
	//This loop allows to make another order or end the program
	while (Repeat !=2 )
	{
	displayMenu(&SetMain, &SetSide, &SetDrink);
	
	//The loop for Order 1
	do
	{
		printf("\nOrder 1:\n");
		getOrder(&Main1, &Side1, &Drink1, &mCost1, &sCost1, &dCost1, &OrderPrice1);
		printf("\nIs this order correct? (1 - Yes / 0 - No): ");
		scanf("%d", &Confirm1);
		
		//Shows input for Change1
		if (Confirm1 == 0)
		{
			printf("Change order or cancel? (1 - Change Order / 2 - Cancel): ");
			scanf("\n%d", &Change1);
			
			if (Change1 == 2)
			{	
				//Order cancelled returns to Main Menu
				printf("Order Cancelled!\n\n");
				displayMenu(&SetMain, &SetSide, &SetDrink);
			}
		}
	}while (Confirm1 != 1); //Terminates loop if Confirm1 = 1
	
	//The loop for Order 2
	do
	{
		//Assigns value for Skip, if Skip = 1 allows loop for Order 3
		Skip = 1;
		printf("\nOrder 2:\n");
		getOrder(&Main2, &Side2, &Drink2, &mCost2, &sCost2, &dCost2, &OrderPrice2);
		printf("\nIs this order correct? (1 - Yes / 0 - No): ");
		scanf("%d", &Confirm2);
		
		//Shows input for Change2
		 if (Confirm2 == 0)
		{
			printf("Change order or cancel? (1 - Change Order / 2 - Cancel): ");
			scanf("\n%d", &Change2);
			
			//Shows input for type of cancel if condition is true
			if (Change2 == 2)
			{	
				printf("You have selected cancel. Cancel the current order or all orders? (1 - Current / 2 - All): ");
				scanf("\n%d", &Type1);
				
				//If statement where if Type1 is == 2 cancels all orders and return back to Main Menu
				if (Type1 == 2)
				{
					//Assign Confirm2 a value of 1 to terminate loop
					Confirm2 = 1;
					//Assign Skip a value of 0 to skip Order 3
					Skip = 0;
					printf("All orders cancelled!\n\n");
				}
				
				//If statement where if Type1 is == 1 only cancels Order 2 and SKIP Order 3 for the bill
				else if (Type1 == 1)
				{
					Skip = 0;
					printf("Order 2 has been cancelled.\n");
					printf("Proceeding to amount due...\n\n");
					Confirm2 = 1;
					
					printf("Order 1:\n");
					displayTotal (&Main1, &Side1, &Drink1, &mCost1, 
								&sCost1, &dCost1);
					//if statement checks if Order 1 meets requirments for Meal set of the day discount 
					if (Main1==SetMain && Side1==SetSide && Drink1==SetDrink)
					{
						printf("\tMeal Set of the day Discount 15\n");
						//Changes value of OrderPrice1 if condition is true
						OrderPrice1 = OrderPrice1 * 0.85;
					}
					//Assigns a value to TotalAmt
					TotalAmt = OrderPrice1;
					printf("Subtotal:\t\t\t\t%.2f\n\n", OrderPrice1);
					printf("Total Amount Due:\t\t\t%.2f\n", TotalAmt);
				}
			}
		}
	
	}while (Confirm2 != 1); //Terminates loop if Confirm2 = 1
	
//If statement for allowing Order 3 if condition is not met skips Order 3
if (Skip == 1)
	//Loop for Order 3
	do
	{
		printf("\nOrder 3:\n");
		getOrder(&Main3, &Side3, &Drink3, &mCost3, &sCost3, &dCost3, &OrderPrice3);
		printf("\nIs this order correct? (1 - Yes / 0 - No): ");
		scanf("%d", &Confirm3);
		
		//Shows input for Change3
		if (Confirm3 == 0)
		{
			printf("Change order or cancel? (1 - Change Order / 2 - Cancel): ");
			scanf("\n%d", &Change3);
			
			//Shows input for type of cancel if condition is true
			if (Change3 == 2)
			{	
				printf("You have selected cancel. Cancel the current order or all orders? (1 - Current / 2 - All): ");
				scanf("\n%d", &Type2);
				
				//If statement where if Type2 is == 2 cancels all orders and return back to Main Menu
				if (Type2 == 2)
				{
					printf("All orders cancelled!\n\n");
					Confirm3 = 1;
					Skip = 0;
				}
				
				//If statement where if Type2 is == 1 only cancels Order 3 and proceeds to the bill
				else if (Type2 == 1)
				{
					//Assign Skip a value of 0
					Skip = 0;
					printf("Order 3 has been cancelled.\n");
					printf("Proceeding to amount due...\n\n");
					//Assign Confirm3 a value of 1 to terminate loop
					Confirm3 = 1;
					
					printf("Order 1:\n");
					displayTotal (&Main1, &Side1, &Drink1, &mCost1, 
								&sCost1, &dCost1);
					//if statement checks if Order 1 meets requirments for Meal set of the day discount 
					if (Main1==SetMain && Side1==SetSide && Drink1==SetDrink)
					{
						printf("\tMeal Set of the day Discount 15 percent\n");
						//Changes value of OrderPrice1 if condition is true
						OrderPrice1 = OrderPrice1 * 0.85;
					}
					printf("Subtotal:\t\t\t%.2f\n\n", OrderPrice1);
						printf("Order 2:\n");
					displayTotal (&Main2, &Side2, &Drink2, &mCost2, 
								&sCost2, &dCost2);
					//if statement checks if Order 2 meets requirments for Meal set of the day discount 
					if (Main2==SetMain && Side2==SetSide && Drink2==SetDrink)
					{
						printf("\tMeal Set of the day Discount 15 percent\n");
						//Changes value of OrderPrice2 if condition is true
						OrderPrice2 = OrderPrice2 * 0.85;
					}
					printf("Subtotal:\t\t\t%.2f\n\n", OrderPrice2);
					TotalAmt = OrderPrice1 + OrderPrice2;
					printf("Total Amount Due:\t\t%.2f\n", TotalAmt);
				}
			}
		}
	}while (Confirm3 != 1);//Terminates loop if Confirm3 = 1
	
	//If statement for allowing display bill with Order 3 if condition is not met skips this display 
	if (Skip == 1)
	{				
		printf("Order 1:\n");
		displayTotal (&Main1, &Side1, &Drink1, &mCost1, 
					&sCost1, &dCost1);
		//if statement checks if Order 1 meets requirments for Meal set of the day discount 
		if (Main1==SetMain && Side1==SetSide && Drink1==SetDrink)
		{
			printf("\tMeal Set of the day Discount 15 percent\n");
			//Changes value of OrderPrice1 if condition is true
			OrderPrice1 = OrderPrice1 * 0.85;
		}
		printf("Subtotal:\t\t\t%.2f\n\n", OrderPrice1);
		
		printf("Order 2:\n");
		displayTotal (&Main2, &Side2, &Drink2, &mCost2, 
					&sCost2, &dCost2);
		//if statement checks if Order 2 meets requirments for Meal set of the day discount 
		if (Main2==SetMain && Side2==SetSide && Drink2==SetDrink)
		{
			printf("\tMeal Set of the day Discount 15 percent\n");
			//Changes value of OrderPrice2 if condition is true
			OrderPrice2 = OrderPrice2 * 0.85;
		}
		printf("Subtotal:\t\t\t%.2f\n\n", OrderPrice2);
		
		printf("Order 3:\n");
		displayTotal (&Main3, &Side3, &Drink3, &mCost3, 
					&sCost3, &dCost3);
		//if statement checks if Order 3 meets requirments for Meal set of the day discount 
		if (Main3==SetMain && Side3==SetSide && Drink3==SetDrink)
		{
			printf("\tMeal Set of the day Discount 15 percent \n");
			//Changes value of OrderPrice2 if condition is true
			OrderPrice3 = OrderPrice3 * 0.85;
		}
		printf("Subtotal:\t\t\t%.2f\n\n", OrderPrice3);
		TotalAmt = OrderPrice1 + OrderPrice2 + OrderPrice3;
		printf("Total Amount Due:\t\t%.2f\n", TotalAmt);
	}
	
	//Ask the user if he/she wants to make another order
	printf("\nMake another order? (1 - Yes / 2 - No): ");
	scanf("\n%d", &Repeat);
	//If Repeat = 2 terminates loop and ends the program
	}
	printf("\nProgram terminated thanks for ordering");
	return 0;
}
