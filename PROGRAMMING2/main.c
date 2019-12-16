#include <stdio.h>
#include "minidb.h"

int main()
{
    int choice = 0;
    
    while(choice!=9){
		printf("\n");
        printMenu();
        printf("Enter a choice (1-9): ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            initializeDB();
            break;
            case 2:
            inputRecord();
            break;
            case 3:
            searchDB();
			case 4:
			deleteDB();
			break;
            case 5:
            listDB();
            break;
			case 6:
			listSortedDB();
			break;
            case 7:
            saveDB();
            break;
            case 8:
            loadDB();
            break;
            
        }
    }
    return 0;
}
