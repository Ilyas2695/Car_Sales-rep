#include <stdio.h>


// greets the user
void greetings()
{
	puts("\n\n\n\nWelcome to the Car Sales office!");
}


// main menu is needed for navigation
void mainMenu()
{
	printf("\nMenu:\n");
	printf("%d. View Car Models\n", MENU_OPTION_VIEW_CARS);
	printf("%d. Buy Cars\n", MENU_OPTION_BUY_CARS);
	printf("%d. View Sales Data/Download the Sales Data\n", MENU_OPTION_VIEW_SALES);
	printf("%d. Exit\n\n", MENU_OPTION_EXIT);
	printf("Please choose one: ");
}

// parting
void goodByeCustomer()
{
	puts("\n\n\n\nThank you for visiting our car sales office.");
	puts("\nHave a good day!\n\n");
}