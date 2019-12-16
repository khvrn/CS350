#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minidb.h"
inventory_t database[100];


void printRecord(inventory_t item);

void printMenu(){
    printf("1. Initalize the database\n");
    printf("2. Input new records\n");
    printf("3. Search for a record\n");
    printf("4. Delete a record\n");
    printf("5. List all records\n");
    printf("6. List all records (sorted)\n");
    printf("7. Save the database\n");
    printf("8. Load an existing database\n");
    printf("9. Exit\n");
}

void initializeDB() {
    printf("\nInitializing...\n");
    for(int i=0; i < 100; i++){
        database[i].name[0] = '\0';
        database[i].record = i+1;
        database[i].quantity = 0;
        database[i].cost = 0;
    }
}

void listDB() {
    for(int i = 0; i < 100; i++){
        printRecord(database[i]);
    }
}

void printRecord(inventory_t item) {
    printf("%d ", item.record);
    printf("%s ", item.name);
    printf("%d ", item.quantity);
    printf("%6.2f\n", item.cost);
}

void inputRecord() {
    inventory_t record;
    printf("Enter name:\n");
    scanf("%s", record.name);
    printf("Enter Record ID:\n");
    scanf("%d", &record.record);
    printf("Enter Quantity:\n");
    scanf("%d", &record.quantity);
    printf("Enter Cost:\n");
    scanf("%f", &record.cost);
    
    database[record.record-1] = record;
}

void searchDB() {
    int id = 0;
    char name[50];
    
    printf("Enter Tool ID:\n");
    scanf("%d", &id);
    printf("Enter Tool Name:\n");
    scanf("%s", name);
    
    for(int i =0; i < 100; i++){
        if((database[i].record == id) && (strcmp(database[i].name, name) == 0)){
            printRecord(database[i]);
            return;
        }
    }
    
    printf("Record not found\n");
}

void deleteDB() {
    int id = 0;
    
    printf("Enter Tool ID:\n");
    scanf("%d", &id);
    
    database[id-1].name[0] = '\0';
	database[id-1].cost = 0;
	database[id-1].quantity = 0;
}

void saveDB() {
    char filename[50];
    FILE *filePointer = NULL;
    
    printf("Enter filename:\n");
    scanf("%s", filename);
    
    filePointer = fopen(filename, "wb");

    fwrite(database, sizeof(inventory_t), 100, filePointer);
	fclose(filePointer);
}

void loadDB() {
    char filename[50];
    FILE *filePointer = NULL;
    
    printf("Enter filename:\n");
    scanf("%s", filename);
    
    filePointer = fopen(filename, "rb");

    fread(database, sizeof(inventory_t), 100, filePointer);
	fclose(filePointer);
}

void listSortedDB() {
	char temp[50];
	
	for(int i = 0; i < 100; i++){
		for(int j=1; j < 100; j++) {
			if(strcmp(database[i].name, database[j].name) > 0){
			strcpy(temp,database[i].name);
            strcpy(database[i].name,database[j].name);
            strcpy(database[j].name,temp);
			}
		}
		printRecord(database[i]);
    }
}
