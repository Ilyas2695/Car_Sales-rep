#define _CRT_SECURE_NO_WARNINGS

// discount criterias and percentage
int DISCOUNT_MIN_AGE;
int DISCOUNT_MAX_AGE;
float DISCOUNT_PERCENTAGE;
// needed when there is 10th transaction to provide special offer as a free purchase
#define SPECIAL_OFFER 2
// menu oprtions
#define MENU_OPTION_VIEW_CARS 1
#define MENU_OPTION_BUY_CARS 2
#define MENU_OPTION_VIEW_SALES 3
#define MENU_OPTION_EXIT 4
// maximum amount of sales
#define MAX_SALES 75
// numbers to choose models of cars
#define MERCEDES 0
#define FORD 1
#define TOYOTA 2
#define HYNDAI 3


// available cars | amount of cars that will be wanted by user | age of user | index to choose models of cars
unsigned short carsAvailable = MAX_SALES, carsNeeded = 0, userAge = 0, carModel;

// for giving discount process
int giveDiscount;

// total price, will be inputed into the array, then sorted in descending order
float totalPrice = 0;

// for choosing option in the main menu
int userChoice;

// discount value will be added to this variable, if giveDiscount becomes true
float discountValue;

// will be added by 1 every cycle, to input variables into the arrays, and use in salesData
unsigned short numberOfSales = 0;

// price for a car model bought by user each cycle
double carPricesPerSale[MAX_SALES];

// total price array for each cycle
double pricesPerSale[MAX_SALES];

// includes titles for each car model bought by user each cycle
char boughtCarModels[MAX_SALES][201];

// includes Yes/No (if discount was given or not)
char discountGivenText[MAX_SALES][10];

// includes amount of bought cars for each cycle
unsigned short carAmountPerSale[MAX_SALES];

// needed to include names of models
unsigned short modelOfCarPerSale[MAX_SALES];

// contains eather Yes or No for each cycle, needed to know given discount or not
unsigned short discountGivenPerSale[MAX_SALES];

// discount amount for each cycle (either 0 or a particular amount)
int amountOfDiscount[MAX_SALES];

// customer names
char customerNames[MAX_SALES][201];

// countains value of discount for each cycle
float discountValueList[MAX_SALES];

// prices for cars
float carPrices[] = {260000.0f, 90000.0f, 100000.0f, 40000.0f};

// number of available models
int numberOfCars = sizeof(carPrices) / sizeof(float);

// amount of cars for each model
int carModelsAmount[] = {5, 15, 25, 30};

// names of models, first needed to sort, second to input into the array of purchased cars
const char *carModels[4] = {"Mercedes G Wagon", "Ford F-150 Raptor", "Toyota LC 200", "Hyundai IONIQ 5"};
char carModelsCopy[4][201] = {"Mercedes G Wagon", "Ford F-150 Raptor", "Toyota LC 200", "Hyndai IONIQ 5"};