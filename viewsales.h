#include <stdio.h>


// prints and sorts all recorded sales data with bubble sorting based on the total price of each purchase
void viewSalesData(int circle)
{
	int i, j; // needed for for loop and sorting (indexes)
	// 7 arrays below are for copying initial arrays, needed to print data in descending order
	const char *sortedBoughtCarModels[circle];
	const char *sortedDiscountGivenText[circle];
	const char *sortedCustomerNames[circle];

	double sortedPricesPerSale[circle];
	double sortedCarPricesPerSale[circle];
	float sortedDiscountValueList[circle];
	unsigned short sortedCarAmountPerSale[circle];
	// duplicate data of the initial arrays into new arrays
	for (i = 0; i < circle; i++)
	{
		sortedBoughtCarModels[i] = boughtCarModels[i];
		sortedDiscountGivenText[i] = discountGivenText[i];
		sortedCustomerNames[i] = customerNames[i];

		sortedPricesPerSale[i] = pricesPerSale[i];
		sortedCarPricesPerSale[i] = carPricesPerSale[i];
		sortedDiscountValueList[i] = discountValueList[i];
		sortedCarAmountPerSale[i] = carAmountPerSale[i];
	}
	// bubble sorting in descending order based on the total price
	for (j = 0; j < circle; j++)
	{
		for (i = j + 1; i < circle; i++)
		{
			if (sortedPricesPerSale[i] > sortedPricesPerSale[j])
			{
				double temp = sortedPricesPerSale[j];
				sortedPricesPerSale[j] = sortedPricesPerSale[i];
				sortedPricesPerSale[i] = temp;

				const char *temp1 = sortedBoughtCarModels[j];
				sortedBoughtCarModels[j] = sortedBoughtCarModels[i];
				sortedBoughtCarModels[i] = temp1;

				double temp2 = sortedCarPricesPerSale[j];
				sortedCarPricesPerSale[j] = sortedCarPricesPerSale[i];
				sortedCarPricesPerSale[i] = temp2;

				unsigned short temp3 = sortedCarAmountPerSale[j];
				sortedCarAmountPerSale[j] = sortedCarAmountPerSale[i];
				sortedCarAmountPerSale[i] = temp3;

				const char *temp4 = sortedDiscountGivenText[j];
				sortedDiscountGivenText[j] = sortedDiscountGivenText[i];
				sortedDiscountGivenText[i] = temp4;

				float temp5 = sortedDiscountValueList[j];
				sortedDiscountValueList[j] = sortedDiscountValueList[i];
				sortedDiscountValueList[i] = temp5;

				const char *temp6 = sortedCustomerNames[j];
				sortedCustomerNames[j] = sortedCustomerNames[i];
				sortedCustomerNames[i] = temp6;
			}
		}
	}
	// needed to show total value for every successful purchase
	float totalSalesValue = 0;
	// needed to show total amount of sold cars
	unsigned int carsSold = 0;
	// prints into the console the data in descending order
	puts("\n\nAll sales data:\n");
	for (i = 0; i < circle; i++)
	{
		printf("\n\nSale Index: %d \n"
			   "| Sale Amount:\t %24lf |\n"
			   "| Car Brand:\t %24s |\n"
			   "| Car Price:\t %24lf |\n"
			   "| Number of Cars:\t %16hd |\n"
			   "| Discount Given:\t %16s |\n"
			   "| Discount Amount:\t %16f |\n"
			   "| Customer Name:\t %16s |\n",
			   i + 1, sortedPricesPerSale[i], sortedBoughtCarModels[i],
			   sortedCarPricesPerSale[i], sortedCarAmountPerSale[i],
			   sortedDiscountGivenText[i], sortedDiscountValueList[i], sortedCustomerNames[i]);

		// total amount of sold cars is updated
		carsSold += carAmountPerSale[i];
		// total value is needed to display full price for all purchases
		totalSalesValue += pricesPerSale[i];
	}
	// conclusion
	printf("\n\n%d Cars have been sold with a total value of %f GBP. \nThere are %hd Cars unsold now.\n",
		   carsSold, totalSalesValue, carsAvailable);
	enter();
	getchar();
}


void writingFile(int amountLines)
{
	// 'i == amountLines' is needed to adjust starting point, according to the old information from the file
	for (int i = amountLines; i < numberOfSales; i++)
	{
		// needed to use as an index when updating the arrays
		int modelOfCar = modelOfCarPerSale[i];
		float price = carAmountPerSale[i] * carPrices[modelOfCar];
		strcpy(boughtCarModels[i], carModelsCopy[modelOfCar]);
		// if user got a discount it will substract a discount value from the price and put "Yes" in the array,
		// in other way it will put "No"
		if (discountGivenPerSale[i] == true)
		{
			strcpy(discountGivenText[i], "Yes");
			price *= (1 - DISCOUNT_PERCENTAGE);
		}
		else if (discountGivenPerSale[i] == false)
		{
			strcpy(discountGivenText[i], "No");
		}
		// puts 'SO' stands for special offer
		else
		{
			strcpy(discountGivenText[i], "SO");
		}
		// adds the total price to the array
		pricesPerSale[i] = price;
		// adds price of car to the array
		carPricesPerSale[i] = carPrices[modelOfCar];
	}
	
	// writes data sales into the file in csv format
	FILE *file;
	file = fopen("SalesData.csv", "w");
	// checks if file exists
	if (file != NULL)
	{
		// this variable is needed to check if there is information in the file
		int checking = 1;
		fprintf(file, "%d\n", checking);
		// writes sales data to the file
		for (int i = 0; i < numberOfSales; i++)
		{
			fprintf(file, "%lf,%s,%lf,%hd,%s,%f,%s\n",
					pricesPerSale[i], boughtCarModels[i],
					carPricesPerSale[i], carAmountPerSale[i],
					discountGivenText[i], discountValueList[i],
					customerNames[i]);
		}
		fclose(file);
	}
	else
	{
		puts("Error occurred while writing in a file");
	}
	getchar();
}
