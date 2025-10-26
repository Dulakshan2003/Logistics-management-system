#include <stdio.h>
#include <string.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 100
#define FUEL_PRICE 310.0

typedef struct {
    int id;
    char source[30];
    char destination[30];
    char vehicle[30];
    int distance;
    char status[20];
    double weight, baseCost, fuelUsed, fuelCost, operationalCost, profit, totalCharge, timeHrs;

} Delivery;

typedef struct {
char name[20];
int capacity;
double ratePerKm, speed, efficiency;

} Vehicle;


void addCities(int maxCities ,char cityNames[][30], int *cityCount);
void displayCities(char cityNames[][30], int cityCount);
void renameCity(char cityNames[][30],int cityCount);
void removeCity(char cityNames[][30],int *cityCount);
void inputDistance(int distance[][MAX_CITIES],int cityCount,char cityNames[][30]);
void displayDistanceTable(int distance[][MAX_CITIES],int cityCount,char cityNames[][30]);
void showVehicles(Vehicle vehicles[],int vehicleCount);
void addDelivery(Delivery deliveries[], int *deliveryCount, char cityNames[][30], int cityCount, Vehicle vehicles[], int vehicleCount, int distance[][MAX_CITIES]);
void showDeliveries(Delivery deliveries[], int deliveryCount);


int main() {
    char cityNames[MAX_CITIES][30];
    int cityCount = 0;
    int choice,choice1,choice2,choice3,choice4;
    int distance[MAX_CITIES][MAX_CITIES];
    Vehicle vehicles[3]={
        {"Truck",5000,40,50,6},
        {"Van",1000,30,60,12},
        {"Lorry",10000,80,45,4}
    };

    int vehicleCount = 3;
    Delivery deliveries[MAX_DELIVERIES];
    int deliveryCount = 0;

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
        printf("4. manage deliveri\n");
        printf("5. Exit\n");


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
                        showVehicles(vehicles, vehicleCount);
                         break;

                            case 4:
                                do{
                                    printf("------ Delivery Management ------\n");
                                    printf("1. Add Delivery\n");
                                    printf("2. show deliveries\n");
                                    printf("3. back to main menu\n");

                                printf("enter your choice:");
                                scanf("%d",&choice4);

                                switch (choice4){
                                case 1:
                                    addDelivery(deliveries, &deliveryCount, cityNames, cityCount, vehicles, vehicleCount, distance);
                                    break;
                                case 2:
                                    showDeliveries(deliveries, deliveryCount);
                                    break;

                                case 3:
                                    printf("return main menu\n");
                                    break;

                                default:
                                    printf("invalid choice");


            }

                }while (choice4  !=3);
                break;

            case 5:
                printf("Exiting program....\n");
                break;

            default:

                printf("Invalid choice..\n");
        }
        }while (choice != 5);


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

void showVehicles(Vehicle vehicles[], int vehicleCount)
{
    if (vehicleCount == 0)
        {
        printf("No vehicles available.\n");
        return;
    }

   printf("\n--- Vehicle List ---\n");
printf("%-5s %-10s %-10s %-10s %-10s %-10s\n", "ID", "Type", "Cap(kg)", "Rate/km", "Speed", "FuelEff");
for (int i = 0; i < vehicleCount; i++){
    printf("%-5d %-10s %-10d %-10.2f %-10.2f %-10.2f\n", i+1, vehicles[i].name, vehicles[i].capacity,
           vehicles[i].ratePerKm, vehicles[i].speed, vehicles[i].efficiency);
}
printf("---------------------------------\n");



}

void addDelivery(Delivery deliveries[], int *deliveryCount, char cityNames[][30], int cityCount,Vehicle vehicles[], int vehicleCount, int distance[][MAX_CITIES])
{
    if (cityCount < 2) {
        printf("Add at least 2 cities first\n");
        return;
    }

    if (*deliveryCount >= MAX_DELIVERIES) {
        printf("Cannot add more deliveries\n");
        return;
    }

    Delivery d;
    d.id = *deliveryCount + 1;

    printf("\n--- Add New Delivery ---\n");
    displayCities(cityNames, cityCount);

    printf("Enter source city number: ");
    int s, dcity;
    scanf("%d", &s);
    printf("Enter destination city number: ");
    scanf("%d", &dcity);

    if (s < 1 || s > cityCount || dcity < 1 || dcity > cityCount || s == dcity) {
        printf("Invalid city selection!\n");
        return;
    }

    strcpy(d.source, cityNames[s - 1]);
    strcpy(d.destination, cityNames[dcity - 1]);



    d.distance = distance[s - 1][dcity - 1];
    if (d.distance <= 0) {
        printf("Distance not recorded between selected cities.\n");
        return;
    }

    showVehicles(vehicles, vehicleCount);
    printf("Select vehicle number: ");
    int v;
    scanf("%d", &v);
    if (v < 1 || v > vehicleCount) {
        printf("Invalid vehicle selection!\n");
        return;
    }

    Vehicle veh = vehicles[v - 1];
    strcpy(d.vehicle, veh.name);

    printf("Enter cargo weight (kg): ");
    scanf("%lf", &d.weight);

    if (d.weight > veh.capacity) {
        printf("Weight exceeds vehicle capacity (%d kg)\n", veh.capacity);
        return;

   }
   d.baseCost = d.distance * veh.ratePerKm * (1 + d.weight / 10000.0);
    d.fuelUsed = d.distance / veh.efficiency;
    d.fuelCost = d.fuelUsed * FUEL_PRICE;
    d.operationalCost = d.baseCost + d.fuelCost;
    d.profit = d.baseCost * 0.25;
    d.totalCharge = d.operationalCost + d.profit;
    d.timeHrs = d.distance / veh.speed;

    strcpy(d.status, "Pending");
    deliveries[*deliveryCount] = d;
    (*deliveryCount)++;

    printf("\n======================================================\n");
    printf("DELIVERY COST ESTIMATION\n");
    printf("------------------------------------------------------\n");
    printf("From: %s\nTo: %s\n", d.source, d.destination);
    printf("Distance: %d km\nVehicle: %s\nWeight: %.2f kg\n", d.distance, d.vehicle, d.weight);
    printf("------------------------------------------------------\n");
    printf("Base Cost: %.2f LKR\nFuel Used: %.2f L\nFuel Cost: %.2f LKR\n", d.baseCost, d.fuelUsed, d.fuelCost);
    printf("Operational Cost: %.2f LKR\nProfit: %.2f LKR\nCustomer Charge: %.2f LKR\n", d.operationalCost, d.profit, d.totalCharge);
    printf("Estimated Time: %.2f hours\n", d.timeHrs);
    printf("======================================================\n");


}



void showDeliveries(Delivery deliveries[], int deliveryCount)
{
    if (deliveryCount == 0) {
        printf("No deliveries found\n");
        return;
    }

   printf("\n------ Delivery List ------\n");


for (int i = 0; i < deliveryCount; i++) {
     printf("ID: %d | From: %s -> To: %s | Vehicle: %s | Distance: %d km | Charge: LKR %.2f | Status: %s\n",deliveries[i].id, deliveries[i].source, deliveries[i].destination,deliveries[i].vehicle, deliveries[i].distance, deliveries[i].totalCharge, deliveries[i].status);


}
printf("----------------------------\n");


}




