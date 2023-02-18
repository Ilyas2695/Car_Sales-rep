#include <stdio.h>


// needed to exit from an option
void enter()
{
	puts("\npress Enter...");
	getchar();
}


// clears the terminal
void systemClear()
{
	system("clear");
}


// changes minimum and maximum ages with a discount
void changeDiscount(int minAgeDiscount, int maxAgeDiscount, float discPercentage)
{
	DISCOUNT_MIN_AGE = minAgeDiscount;
	DISCOUNT_MAX_AGE = maxAgeDiscount;
	DISCOUNT_PERCENTAGE = discPercentage;
	printf("\nToday we have %f percent discounts for people from %d to %d ages\n", DISCOUNT_PERCENTAGE * 100, DISCOUNT_MIN_AGE, DISCOUNT_MAX_AGE);
}


// function generates random number from minNum to maxNum
void randomNumberChooseDiscount()
{
	int minNum = 1;
	int maxNum = 5;
	int randNum = (rand() % (maxNum - minNum + 1)) + minNum;

	// this part chooses which minimum and maximum ages are needed to get a discount
	if (randNum == 1)
	{
		changeDiscount(25, 40, 0.10f);
	}
	else if (randNum == 2)
	{
		changeDiscount(45, 60, 0.15f);
	}
	else if (randNum == 3)
	{
		changeDiscount(65, 80, 0.25f);
	}
	else if (randNum == 4)
	{
		changeDiscount(85, 100, 0.30f);
	}
	else if (randNum == 5)
	{
		changeDiscount(18, 30, 0.20f);
	}
}