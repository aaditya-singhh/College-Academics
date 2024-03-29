/*



Design a data structure that supports the following operations in O(1) time.
insert(x): Inserts an item x to the data structure if not already present.
remove(x): Removes item x from the data structure if present.
search(x): Searches an item x in the data structure.
getRandom(): Returns a random element from current set of elements

Following are detailed operations.
 insert(x) 

1. Check if x is already present by doing a hash map lookup. 
2. If not present, then insert it at the end of the array. 
3. Add in the hash table also, x is added as key and last array
index as the index.

 remove(x) 

1. Check if x is present by doing a hash map lookup. 
2. If present, then find its index and remove it from a hash
map. 
3. Swap the last element with this element in an array and
remove the last element. 
Swapping is done because the last element can be removed
in O(1) time. 
4. Update index of the last element in a hash map.

 getRandom() 

1. Generate a random number from 0 to last index. 
2. Return the array element at the randomly generated index.

 search(x) 

 Do a lookup for x in hash map.




*/






#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#define MAX_SIZE 1000


int elements[MAX_SIZE];
bool isUsed[MAX_SIZE]; //by default initialized with false for all elements
int size = 0;


//hashing fxn
int hash(int key) {
    return abs(key) % MAX_SIZE;
}


bool mapInsert(int x) {
    if (size >= MAX_SIZE)
        return false; //exceeding array/map size


    int index = hash(x);


    while (isUsed[index]) {
        if (elements[index] == x)
            return false; //element already exists
        index = (index + 1) % MAX_SIZE;
    }


    elements[index] = x;
    isUsed[index] = true;
    size++;
    return true;
}


bool mapRemove(int x) {
    int index = hash(x);


    for (int i = 0; i < MAX_SIZE; i++) { //for loop for handling collisions
        if (!isUsed[index])
            return false; //element not found


        if (elements[index] == x) {
            isUsed[index] = false;
            size--;
            return true;
        }


        index = (index + 1) % MAX_SIZE;
    }


    return false; //element not found
}


bool mapSearch(int x) {
    int index = hash(x);


    for (int i = 0; i < MAX_SIZE; i++) {
        if (!isUsed[index])
            return false; //element not found


        if (elements[index] == x)
            return true;


        index = (index + 1) % MAX_SIZE;
    }


    return false; //element not found
}


int mapRandom() {
    if (size == 0)
        return -1; //empty set


    int randomIndex = rand() % size;
    return elements[randomIndex];
}


int main() {
    srand((unsigned int)time(NULL)); //seeding the random number generator
    int choice, element;


    while (1) {
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Search\n");
        printf("4. Get Random\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                printf("Enter an element to insert: ");
                scanf("%d", &element);
                if (mapInsert(element))
                    printf("Element %d inserted successfully.\n", element);
                else
                    printf("Element %d already exists or max size reached.\n", element);
                break;
            case 2:
                printf("Enter an element to remove: ");
                scanf("%d", &element);
                if (mapRemove(element))
                    printf("Element %d removed successfully.\n", element);
                else
                    printf("Element %d not found.\n", element);
                break;
            case 3:
                printf("Enter an element to search: ");
                scanf("%d", &element);
                if (mapSearch(element))
                    printf("Element %d is present.\n", element);
                else
                    printf("Element %d is not present.\n", element);
                break;
            case 4:
                element = mapRandom();
                if (element != -1)
                    printf("Random element: %d\n", element);
                else
                    printf("The set is empty.\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }


    return 0;
}

