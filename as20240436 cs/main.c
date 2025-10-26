#include <stdio.h>
#include <string.h>

#define MAX_CITIES 30



void addCities(int maxCities ,char cityNames[][30], int *cityCount);
void displayCities(char cityNames[][30], int cityCount);
void renameCity(char cityNames[][30],int cityCount);
void removeCity(char cityNames[][30],int *cityCount);
void inputDistance(int distance[][MAX_CITIES],int cityCount,char cityNames[][30]);
void displayDistanceTable(int distance[][MAX_CITIES],int cityCount,char cityNames[][30]);
void showVehicles(char vehicleNames[][30],int vehicleCount);


int main() {
    char cityNames[MAX_CITIES][30];
    int cityCount = 0;
    int choice,choice1,choice2,choice3;
    int distance[MAX_CITIES][MAX_CITIES];
    char vehicleNames[MAX_CITIES][30] = {"Truck A","Van B","Lorry C"};
    int vehicleCount = 3;

    for(int i=0; i< MAX_CITIES;i++){
        for(int j=0;j<MAX_CITIES; j++){
            distance[i][j] = (i==j) ?0:-1;
        }
    }

    do{
        printf("\n===============================\n");
        printf("--Logistics Management System--");
        printf("\n===============================\n");
        printf("1. Manage cities\n");
        printf("2. Manage distance\n");
        printf("3. manage vehicles\n");
        printf("4. Exit\n");


        printf("enter your choice:");
        scanf("%d",&choice);

        switch (choice){
        case 1:


    do {

        printf("------ city Management ------\n");

        printf("1. Add City\n");

        printf("2. Rename city\n");
        printf("3. Remove cities\n");
        printf("4. Show Cities\n");
        printf("5. back to main menu\n");

        printf("Enter your choice: ");
        scanf("%d", &choice1);

        switch (choice1)
         {
            case 1:
                addCities(MAX_CITIES,cityNames, &cityCount);
                break;
            case 2:
                renameCity(cityNames,cityCount);
                break;
            case 3:
                removeCity(cityNames,&cityCount);
                break;

            case 4:
                displayCities(cityNames, cityCount);
                break;

            case 5:
                printf("return main menu...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    while (choice1 != 5);
    break;
            case 2:
                if(cityCount < 2){
                    printf("\n add at leest 2 cities ");
                    break;
                }
                do{
                printf("------ Distance Management ------\n");
                printf("1. Input/Edit Distance\n");
                printf("2. Display Distance Table\n");
                printf("3. Back to Main Menu\n");


                printf("Enter your choice: ");
                scanf("%d", &choice2);

                switch(choice2){
                    case 1:
                        inputDistance(distance, cityCount, cityNames);
                        break;
                    case 2:
                        displayDistanceTable(distance,cityCount,cityNames);
                        break;
                    case 3:
                        printf("Returning to main menu...\n");
                        break;
                    default:
                        printf("Invalid choice!\n");
                }



                }while(choice2 !=3);
                break;
                    case 3:
                        do{
                            printf("------Vehicle Management------\n");
                            printf("1. Show Vehicles\n");
                            printf("2. Back to main menu \n");

                            printf("enter your choice:");
                            scanf("%d",&choice3);

                            switch(choice3){
                            case 1:
                                showVehicles(vehicleNames,vehicleCount);
                                break;

                            case 2:
                                printf("return to main menu \n");
                                break;
                            default:
                                printf("invalid choice\n");
                            }
                        }while(choice3 !=2);
                        break;

            case 4:
                printf("Exiting program....\n");
                break;

            default:

                printf("Invalid choice..\n");
        }
        }while (choice != 4);


    return 0;
}

void addCities(int maxCities,char cityNames[][30], int *cityCount){
    char newCity[30];
    int i =0;
    if (*cityCount >= maxCities) {
        printf("Cannot add more cities.\n");
        return;
    }

    printf("Enter city name: ");
    scanf(" %[^\n]",newCity);
    while(newCity[i] != '\0'){
        cityNames[*cityCount][i] = newCity[i];
        i++;
    }
    cityNames[*cityCount][i] = '\0';
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
 char newName[30];
 printf("Enter new name:");
 scanf(" %[^\n]",newName);

 int i =0;
 while(newName[i] != '\0'){
    cityNames[index - 1][i] = newName[i];
    i++;
 }
 cityNames[index - 1][i] = '\0';

 printf("City renamed successfully!\n");
}

void removeCity(char cityNames[][30],int *cityCount)
{
    if(*cityCount == 0){
        printf("No citties to remove \n");
    return;

        }
        displayCities(cityNames,*cityCount);

        int index;
        printf("Enter city number to remove:");
        scanf("%d",&index);

        if(index < 1 || index > *cityCount){
            printf("Invalid city number \n");
            return;
        }
        for(int i = index - 1; i < *cityCount - 1;i++){
            int j =0;
            while(cityNames[i +1][j] != '\0'){
                cityNames[i][j] = cityNames[i +1][j];
                j++;
            }
            cityNames[i][j] = '\0';
        }
        (*cityCount)--;
        printf("city removed successfully....\n");
}

void inputDistance(int distance[][MAX_CITIES], int cityCount, char cityNames[][30])
{
    int c1, c2, dist;
    displayCities(cityNames, cityCount);

    printf("Enter source city number: ");
    scanf("%d", &c1);


    printf("Enter destination city number: ");
    scanf("%d", &c2);

    if (c1 < 1 || c1 > cityCount || c2 < 1 || c2 > cityCount || c1 == c2) {
        printf("Invalid city selection!\n");

        return;

    }

    printf("Enter distance between %s and %s (km): ", cityNames[c1 - 1], cityNames[c2 - 1]);
    scanf("%d", &dist);

    if (dist <= 0) {
        printf("Distance must be positive.\n");
        return;

}

    distance[c1 - 1][c2 - 1] = dist;
    distance[c2 - 1][c1 - 1] = dist;

    printf("Distance recorded successfully!\n");

}


void displayDistanceTable(int distance[][MAX_CITIES], int cityCount, char cityNames[][30])
{
    if (cityCount < 2) {
        printf("Not enough cities to display.\n");
        return;
    }

    printf("\n------ Distance Table (km) ------\n      ");

    for (int i = 0; i < cityCount; i++)
        {
        printf("%-10s", cityNames[i]);

    }
    printf("\n");

    for (int i = 0; i < cityCount; i++)
        {
        printf("%-5s", cityNames[i]);
        for (int j = 0; j < cityCount; j++)
        {
            if (distance[i][j] == -1)

                printf("%-10s", "-");

            else

                printf("%-10d", distance[i][j]);
}
        printf("\n");
    }
    printf("---------------------------------\n");
}

void showVehicles(char vehicleNames[][30], int vehicleCount)
{
    if (vehicleCount == 0)
        {
        printf("No vehicles available.\n");
        return;
    }

    printf("\n--- Vehicle List ---\n");
    for (int i = 0; i < vehicleCount; i++)
        {
        printf("%d. %s\n", i + 1, vehicleNames[i]);
    }

    printf("---------------------\n");


}



