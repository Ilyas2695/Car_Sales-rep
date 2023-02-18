#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define SIZE 51


struct Node
{
	char name[SIZE];
	int price;
	int amount;
	int age;
	char carModel[SIZE];
	struct Node *next;
};

char cars[][SIZE] = {"Mercedes", "Ford", "Toyota"};
char prices[] = {100, 30, 80};


struct Node *allocate()
{

	struct Node *p;

	p = (struct Node *)malloc(sizeof(struct Node) * 1);
	if (p == NULL)
	{
		fprintf(stderr, "INALID ALLOCATION!\n");
		exit(1);
	}

	return p;
}


int wordValidation(char word[]){

	for(int i = 0; word[i] != '\0'; i++){
        if (isdigit(word[i])){
            puts("your name does not have to contain any numbers!");
            return true;
        }
	}
	return false;
}

void fill(struct Node *s)
{

	int choise;
	int choise1;
	char userName[SIZE];
	while(1){
		fflush(stdin);
		puts("what is your name?");
		scanf("%s", userName);
		getchar();
		if (wordValidation(userName)){
			continue;
		}else{
			strcpy(s->name, userName);
		}
		printf("what is your age?");
		
		int n = scanf("%d", &s->age);
		if (!n){
			puts("write only numbers");
			continue;
		}

		fflush(stdin);

		for (int i = 0; i < 3; i++)
		{
			printf("%d: model: %s, price: %d\n", i, cars[i], prices[i]);
		}

		printf("what car do you want?");
		n = scanf("%d", &choise);
		if (!n){
			puts("write only numbers");
			continue;
		}

		printf("how many?");
		n = scanf("%d", &choise1);
		if (!n){
			puts("write only numbers");
			continue;
		}

		strcpy(s->carModel, cars[choise]);
		s->price = (prices[choise] * choise1);
		s->amount = choise1;
		break;
	}
}

int output(struct Node *s)
{

	int count = 0;

	if (s == NULL)
	{
		printf("nothing to output\n");
	}
	else
	{
		while (s != NULL)
		{
			printf("%d years old %s bought: %s, price: %d, amount: %d\n", s->age, s->name, s->carModel, s->price, s->amount);
			s = s->next;
			count++;
		}
	}

	return count;
}


void enter(){

	puts("Press enter...");
	getchar();
	getchar();

}


void clear(){
	system("clear");
}


void save(struct Node *s){
	FILE* file;

	if(s == NULL){
		puts("List is empty\n");
		return;
	}

	int i;
	
	file = fopen("file.dat", "w");
	if (file == NULL){
		fprintf(stderr, "cannot open the file");
		exit(1);
	}
	int length = output(s);
	printf("%d structures are going to be saved\n", length);

	for(i = 0; i<length; i++){
		fwrite(s, sizeof(struct Node), 1, file);
		s = s->next;
	}
	printf("%d were saved into the file\n", length);

	fclose(file);

}


void open(struct Node *s){
	int i, records = 1;
	FILE* file;
	
	file = fopen("file.dat", "r");
	if (file == NULL){
		fprintf(stderr, "cannot open the file");
		return;
	}
	while(1){
		fread(s, sizeof(struct Node), 1, file);
		if (s->next==NULL){
			break;
		}
		s->next = allocate();
		s = s->next;
		records++;
	}
	printf("%d records were read\n", records);
	fclose(file);
	puts("DONE");
}


int main()
{

	struct Node *first, *current, *temp;
	int Q = true;
	char input;
	int r,record;

	first = NULL;

	while (Q != false)
	{
		clear();
		puts("Main menu:\n");

		puts("Buy: B");
		puts("Delete: D");
		puts("See the output: O");
		puts("Save: S");
		puts("Open File: F");
		puts("Quit: Q");
		puts("Choose one option:");
		scanf("%c", &input);

		switch (input)
		{
			case 'B':
				if (first == NULL)
				{
					current = allocate();
					first = current;
					fill(current);
				}
				else
				{
					while (current->next)
						current = current->next;

					current->next = allocate();
					current = current->next;
					fill(current);
				}
				current->next = NULL;

				enter();
				break;

			case 'D':
				if (first == NULL){
					puts("Nothing to delete");
				}
				else{
					r = output(first);
					printf("Delete 1 to %d", r);
					scanf("%d", &record);
					if (record > r || record < 1){
						puts("value out of range");
						break;
					}
					if (record == 1){
						if (first->next == NULL){
							free(first);
							first = NULL;
							
						}else{
							temp = first;
							first = first->next;
							free(temp);
							temp = NULL;
						}
						puts("DONE");
						enter();
						break;
					}while(record-2){

						current = current->next;
						record--;
					}
					temp = current->next;
					current->next = temp->next;

					free(temp);
					temp = NULL;
					puts("DONE");
				}
				enter();
				break;

			case 'O':
				output(first);
				enter();
				break;

			case 'S':
				save(first);
				enter();
				break;

			case 'F':
				first = allocate();
				open(first);
				enter();
				break;
			
			case 'Q':
				Q = false;
				break;		
		}
	}
	puts("thanks you for visiting us!))");
	return 0;
}