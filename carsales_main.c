// I used a built-in VS code "Format Document" function to make this code more readable
// project was made on a macOS machine, so I used system("clear") instead of system("cls")
// project was separeted into the files, in order to read it easier

// for input and output
#include <stdio.h>
// for fflush(stdin) function that clears the buffer
#include <ctype.h>
// for application of 'true' and 'false' directly instead of creating the variables
#include <stdbool.h>
// to operate between the string variables
#include <string.h>
// to use system("clear") function
#include <stdlib.h>
// library consists of globally declared variables
#include "variables.h"
// library consists of functions that needed to show cars and their remaining amount in descending order
#include "carstock.h"
// library consists of functions that needed for purchase process
#include "purchasecar.h"
// library includes functions that are needed to show the sales data in decending order
#include "viewsales.h"
// library consists of void functions that print main menu, greetings, and parting
#include "printing.h"
// library includes the function that is needed to read the information from the file (function that writes the information is in "viewsales.h")
#include "linecount.h"
// needed to generage random number
#include <time.h>


int main()
{
	// this variable is needed to properly input the data into the arrays, if there were previous purchases
	int amountLines = 0;
	amountLines = linesCounter(); // located in "linecount.h"
	numberOfSales += amountLines;

	greetings(); // located in "printing.h"

	// main loop, needed to process the program until the user stops it
	do
	{
		// cleans the buffer
		fflush(stdin);

		mainMenu(); // located in "printing.h"

		int userChoiseCheck = scanf("%d", &userChoice);
		// needed to check if user wrote letters
		if (!userChoiseCheck)
		{
			systemClear(); // located in "shortfunc.h"
			puts("write only numbers");
			continue;
		}
		else
		{
			// switch function for the user to choose menu options
			switch (userChoice)
			{
			case MENU_OPTION_VIEW_CARS:
				systemClear();
				viewCarModels(numberOfCars); // "carstock.h"
				systemClear();
				break;

			case MENU_OPTION_BUY_CARS:
				systemClear();
				randomNumberChooseDiscount();
				buyingCars(amountLines);  // located in "purchasecar.h"
				writingFile(amountLines); // located in "viewsales.h"
				break;

			case MENU_OPTION_VIEW_SALES:
				systemClear();
				viewSalesData(numberOfSales); // located in "viewsales.h"
				break;
				
			default:
				// prints a message if the user wrote wrong number
				systemClear();
				if (userChoice != MENU_OPTION_EXIT)
				{
					puts("There is no option on this number");
				}
				break;
			}
		}
	} while (userChoice != MENU_OPTION_EXIT);

	// will say goodbye to the user if program is ended
	goodByeCustomer(); // located in "printing.h"
	return 0;
}