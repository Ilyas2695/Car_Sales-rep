#include <stdio.h>


// summary of a purchase, addition to numberOfSales to input values into arrays and for loops
unsigned short numberOfSalesAdding(unsigned short carsNeeded, float totalPrice, unsigned short carsAvailable, unsigned short numberOfSales)
{
	puts("\n\nThank you.");
	printf("You have purchased %hd cars in our car dealership.\n", carsNeeded);
	printf("Total price is %f GBP.\n", totalPrice);
	printf("There are %hd cars remaining.\n", carsAvailable);
	numberOfSales++;
	printf("%hd purchases have been completed\n\n", numberOfSales);

	return numberOfSales;
}


// prints if user gets a discount or not
void discountYesNot(int giveDiscount)
{
	switch (giveDiscount)
	{
	// prints eather positive or negative message to user about his/her discount
	case true:
		// calculates the discount value
		discountValue = totalPrice - totalPrice * (1 - DISCOUNT_PERCENTAGE);
		// adds the discount value to the array
		discountValueList[numberOfSales] = discountValue;
		// substracts total price with discount value
		totalPrice -= discountValue;

		puts("\nThere is a discount provided!");
		break;

	case false:
		puts("\nThere is no discount provided.");
		break;
		
	case SPECIAL_OFFER:
		discountValue = totalPrice;
		discountValueList[numberOfSales] = discountValue;
		totalPrice = 0;
		puts("\nSpecial offer has been applied.");
	}
}


// checks if age fits the discount criterias
char ageChecking(unsigned short userAge)
{
	giveDiscount = false;

	// checks if there is 10th transactions, to provide spacial offer
	// 9 because at the moment when it is 10th transaction the numberOfSales is still 9
	if (numberOfSales == 9)
	{
		puts("\nCongratulations!!!\nYou are our 10th purchaser, this means that your purchase will be for free");
		return SPECIAL_OFFER;
	}
	else if (userAge >= DISCOUNT_MIN_AGE && userAge <= DISCOUNT_MAX_AGE)
	{
		giveDiscount = true;
	}
	else
	{
		char nusCardResponse;
		printf("\nDo you have our Membership card? Answer 'y' or 'n': "); // Membership card for additional chance to get a discount

		scanf("\n%c", &nusCardResponse);

		if (nusCardResponse == 'y')
		{
			giveDiscount = true;
		}
	}

	systemClear();
	return giveDiscount;
}


// checks and substracts carsNeeded from the existing amount of models (changes the array)
int *subtractingAmountOfModels(int carsNeeded, int model, int MODEL)
{
	if (carsNeeded > carModelsAmount[MODEL])
	{
		systemClear();
		puts("\nsorry, we do not have this amount of models you require");
		return false;
	}
	else
	{
		model = carModelsAmount[MODEL];
		model -= carsNeeded;
		carModelsAmount[MODEL] = model;

		return carModelsAmount;
	}
}


// compares each amount of models with needed cars, then prints a corresponding warning if there are less cars
int carModelsAvailable(int numberOfCars, int carsNeeded, unsigned short carsAvailable)
{
	fflush(stdin);
	// amount of each model
	int mercedeses = carModelsAmount[0];
	int fords = carModelsAmount[1];
	int toyotas = carModelsAmount[2];
	int hyndais = carModelsAmount[3];

	// presents models and their index to choose
	puts("\nCar Models:");
	for (int i = 0; i < numberOfCars; i++)
	{
		printf("%d - %s\n", i, carModels[i]);
	}

	// checks if the user writes letters
	printf("\nWhat model of car do you need? Choose from above: ");
	unsigned short car = scanf("%hd", &carModel);
	fflush(stdin);
	if (!car)
	{
		systemClear();
		puts("write only numbers");
		return 100;
	}

	// these blocks are needed to check if the user requires more cars for each model
	// returns 100 because if returns 1 or true, 1 is an index of first model's title
	int *models;
	switch (carModel)
	{
	case MERCEDES:
		models = subtractingAmountOfModels(carsNeeded, mercedeses, MERCEDES);
		if (models == false)
			return 100;

		return carModel;
	case FORD:
		models = subtractingAmountOfModels(carsNeeded, fords, FORD);
		if (models == false)
			return 100;

		return carModel;
	case TOYOTA:
		models = subtractingAmountOfModels(carsNeeded, toyotas, TOYOTA);
		if (models == false)
			return 100;

		return carModel;
	case HYNDAI:
		models = subtractingAmountOfModels(carsNeeded, hyndais, HYNDAI);
		if (models == false)
			return 100;

		return carModel;
	default:
		systemClear();
		puts("sorry, there is no model on this number");
		return 100;
	}
}


// asks how many cars the user needs, and checks if the user writes wrong information
int carsAsking()
{
	fflush(stdin); // cleans the buffer
	printf("\n\nHow many cars do you need? Amount: ");
	unsigned short cars = scanf("%hd", &carsNeeded);
	fflush(stdin);
	// if the user has written letters, this if stetement will warn user and return false to ask again
	if (!cars)
	{
		systemClear();
		puts("write only numbers");
		return false;
	}
	// checks each amount of models to warn user and returns false to ask again if there are less cars than user requires
	if ((carModelsAmount[MERCEDES] < carsNeeded) && (carModelsAmount[FORD] < carsNeeded) && (carModelsAmount[TOYOTA] < carsNeeded) && (carModelsAmount[HYNDAI] < carsNeeded))
	{
		systemClear();
		puts("Sorry, there are fewer cars remaining than you require.");
		return false;
	}
	// if successfully passed all examinations of needed cars, function returns carsNeeded
	else
	{
		return carsNeeded;
	}
}


// checks if the user wrote numbers in his/her name
// I did not deside to add the examination for other simbols, because many people have different names.
int nameAsking()
{
	printf("What is your name? Name: ");
	scanf("\n%[^\n]s", customerNames[numberOfSales]);
	// iterate through each character in the user's name to the end
	for (int i = 0; customerNames[numberOfSales][i] != '\0'; i++)
	{
		// checks every character if it is a number
		if ((isdigit(customerNames[numberOfSales][i])))
		{
			systemClear();
			puts("\nwrite letters only!\n");
			return false;
		}
	}
	return true;
}


// checks availability of cars
int carsAvalability()
{
	if (carsAvailable > 0)
	{
		printf("There are %hd cars available.\n\n", carsAvailable);
	}
	else
	{
		puts("Sorry, there are no more cars available.");
		return false; // returns false if there are no cars anymore, then returns to the main menu
	}
	return true; // returns true if there are remaining cars
}


// checks, if the user is able to buy a car according to his/her age
int ageAsking()
{
	// clears the buffer
	fflush(stdin);
	unsigned short userage = 0;
	printf("How old are you? Age: ");
	int age = scanf("%hd", &userage);

	//  checks if the user wrote letters in his/her age
	if (!age)
	{
		systemClear();
		puts("write only numbers!");
		return false;
	}
	else if (userage < 18 || userage > 100)
	{
		systemClear();
		puts("\nsorry, your age is not for purchasing a car\n");
		return false;
	}
	return userage;
}


// main function for purchasing the cars
void buyingCars(int amountLines)
{
	while (true)
	{
		userAge = ageAsking();
		if (userAge == false)
			continue;
		systemClear();

		// isbreak is needed to ask again in order to get right data, but in this part it is needed to break the loop
		// if there are no cars available
		int isbreak = carsAvalability();
		if (isbreak == false)
			break;

		// asks user to input until he/she inputs right data
		while (true)
		{
			fflush(stdin);
			isbreak = nameAsking();
			if (isbreak == false)
				continue;
			break;
		}
		systemClear();

		// loop is needed to ask again to get right data
		while (true)
		{
			// checks if the data is right and adds the needed cars to the array
			unsigned short carsNeeded = carsAsking();
			if (carsNeeded == false)
				continue;
			else
			{
				carAmountPerSale[numberOfSales] = carsNeeded;
			}
			// checks if the data is right
			carModel = carModelsAvailable(numberOfCars, carsNeeded, carsAvailable);
			if (carModel == 100)
				continue;
			else
			{
				// adds title of a choosen car to the array
				modelOfCarPerSale[numberOfSales] = carModel;
				// adds value of a purchase to the array
				totalPrice = carsNeeded * carPrices[carModel];
				// substract needed cars from all cars
				carsAvailable -= carsNeeded;
				break;
			}
		}
		// will be used in the array below to add "Yes" or "No" to array
		giveDiscount = ageChecking(userAge);
		discountGivenPerSale[numberOfSales] = giveDiscount;
		discountYesNot(giveDiscount);
		numberOfSales = numberOfSalesAdding(carsNeeded, totalPrice, carsAvailable, numberOfSales);
		break;
	}
}