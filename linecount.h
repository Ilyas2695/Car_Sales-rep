#include <stdio.h>


// counts the lines to add amountLines to numberOfSales in order to properly input the data into the arrays, if there were information in the file
int linesCounter()
{
	// -1 because there will be "1" on the first line after the first purchase, this "1" is needed to check if there is the data in the file
	int lines = -1;
	char newLineCharacter;
	// checks the existance of the information in a file
	int is_exist = 0;

	FILE *file;
	file = fopen("SalesData.csv", "r");
	if (file != NULL)
	{
		fscanf(file, "%d", &is_exist);
		// if there is no information in a file, then the function returns 0
		if (is_exist == 1)
		{
			do
			{
				newLineCharacter = fgetc(file); // gets every character in a file, until it finds the newline character to count a line
				if (newLineCharacter == '\n')
					lines++;
			} while (newLineCharacter != EOF); // loop continues until the file ends
		}
		else
		{
			return 0;
		}
		fclose(file);
	}
	else
	{
		puts("file was not detected");
		return 0;
	}

	// this part reads all data from the file and inputs into the arrays
	file = fopen("SalesData.csv", "r");
	// checks if the file exists
	if (file != NULL)
	{
		// this variable is needed to get "1" at the start of the data in a file
		int first;
		fscanf(file, "%d\n", &first);
		for (int i = 0; i < lines; i++)
		{
			fscanf(file, "%lf,%[^,],%lf,%hd,%[^,],%f,%201[^\n]\n", &pricesPerSale[i], boughtCarModels[i],
				   &carPricesPerSale[i], &carAmountPerSale[i],
				   discountGivenText[i], &discountValueList[i],
				   customerNames[i]);
		}
		// closes file and returns amount of lines
		fclose(file);

		for (int i = 0; i < lines; i++)
		{
			// substract data(from the file) from the existing data for each model of car
			if ((carPricesPerSale[i] == 260000.000000) && (carModelsAmount[0] >= carAmountPerSale[i]))
			{
				carModelsAmount[0] -= carAmountPerSale[i];
			}
			else if ((carPricesPerSale[i] == 90000.000000) && (carModelsAmount[1] >= carAmountPerSale[i]))
			{
				carModelsAmount[1] -= carAmountPerSale[i];
			}
			else if ((carPricesPerSale[i] == 100000.000000) && (carModelsAmount[2] >= carAmountPerSale[i]))
			{
				carModelsAmount[2] -= carAmountPerSale[i];
			}
			else if ((carPricesPerSale[i] == 40000.000000) && (carModelsAmount[3] >= carAmountPerSale[i]))
			{
				carModelsAmount[3] -= carAmountPerSale[i];
			}
			// substract the amount of bought cars from the amount of all available cars
			carsAvailable -= carAmountPerSale[i];
		}
	}
	else
	{
		puts("file was not detected");
	}
	return lines;
}