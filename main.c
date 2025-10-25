#include <stdio.h>
#include <string.h>

#define MAX_CITIES 30



void addCity(char cityNames[][30], int *cityCount);
void displayCities(char cityNames[][30], int cityCount);
void renameCity(char cityNames[][30],int cityCount);

int main() {
    char cityNames[MAX_CITIES][30];
    int cityCount = 0;
    int choice;

    do {
        printf("\n===============================\n");
        printf("--Logistics Management System--");
        printf("\n===============================\n");
        printf("1. Add City\n");
        printf("2. Show Cities\n");
        printf("3. Rename city\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                addCity(cityNames, &cityCount);
                break;
            case 2:
                displayCities(cityNames, cityCount);
                break;
            case 3:
                renameCity(cityNames,cityCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    while (choice != 4);

    return 0;
}

void addCity(char cityNames[][30], int *cityCount)
{
    if (*cityCount >= MAX_CITIES) {
        printf("Cannot add more cities.\n");
        return;
    }

    printf("Enter city name: ");
    scanf(" %[^\n]", cityNames[*cityCount]);
    (*cityCount)++;

    printf("City added successfully!\n");
}

void displayCities(char cityNames[][30], int cityCount)
{
    if (cityCount == 0) {
        printf("No cities available.\n");
        return;
    }

    printf("\n--- City List ---\n");
    for (int i = 0; i < cityCount; i++) {
        printf("%d. %s\n", i + 1, cityNames[i]);
    }
}
void renameCity(char cityNames[][30],int cityCount)
{
    if(cityCount == 0)
{
        printf("No cities to rename.\n");
        return;

    }
 displayCities(cityNames,cityCount);

 int index;
 printf("Enter city number to rename:");
 scanf("%d",&index);

 if(index < 1 || index > cityCount)
 {
     printf("Invalid city number!\n");
     return;
 }
 printf("Enter new name for %s:",cityNames[index - 1]);
 scanf(" %[^\n]",cityNames[index - 1]);

 printf("City renamed successfully!\n");
}
