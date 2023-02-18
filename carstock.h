#include <stdio.h>
#include "shortfunc.h"


void viewCarModels(int numbersOfCars)
{
	int i;
	int j;
	// 2 below arrays are needed to copy all information from initial arrays, and present information in descending order
	const char *sortedCarModels[4];
	int sortedCarModelsAmount[4];
	// copies arrays to safely sort the information
	for (i = 0; i < numbersOfCars; i++)
	{
		sortedCarModels[i] = carModels[i];
		sortedCarModelsAmount[i] = carModelsAmount[i];
	}
	// bubble sorting
	for (j = 0; j < numbersOfCars - 1; j++)
	{
		for (i = j + 1; i < numbersOfCars; i++)
		{
			if (sortedCarModelsAmount[i] > sortedCarModelsAmount[j])
			{
				const char *temp = sortedCarModels[j];
				sortedCarModels[j] = sortedCarModels[i];
				sortedCarModels[i] = temp;

				int temp1 = sortedCarModelsAmount[j];
				sortedCarModelsAmount[j] = sortedCarModelsAmount[i];
				sortedCarModelsAmount[i] = temp1;
			}
		}
	}
	// prints sorted information
	puts("\nCar models, we have: \n");

	for (i = 0; i < numbersOfCars; i++)
	{
		printf("| %-32s%-2d |\n", sortedCarModels[i], sortedCarModelsAmount[i]);
	}

	enter();
	getchar();
}