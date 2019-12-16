#ifndef _MINIDB_H_
#define _MINIDB_H_

typedef struct inventory {
    char name[50];
    int record;
    int quantity;
    float cost;
} inventory_t;

void printMenu();
//intialize database
void initializeDB();
void inputRecord();
void listDB();
void searchDB();
void saveDB();
void loadDB();
void deleteDB();
void listSortedDB();
#endif //_MINIDB_H_