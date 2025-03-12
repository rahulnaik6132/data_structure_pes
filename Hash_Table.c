/*
    Name : Rahul Ravikumar Naik
    Topic : Hash Table
    Class : B
    SRN : PES1PG24CA133
*/

#include <stdio.h>
#define TABLE_SIZE 10

void initializeTable(int table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = -1;
    }
}

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void displayTable(int table[])
{
    printf("Current Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != -1)
        {
            printf("Index %d: %d\n", i, table[i]);
        }
        else
        {
            printf("Index %d: None\n", i);
        }
    }
    printf("\n");
}
void insert(int table[], int key)
{
    int index = hashFunction(key);
    while (table[index] != -1)
    {
        index = (index + 1) % TABLE_SIZE;
    }
    table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
    displayTable(table); 
}

int main()
{
    int hashTable[TABLE_SIZE];  
    initializeTable(hashTable); 

    int keys[] = {12, 22, 32, 42, 52, 62};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++)
    {
        insert(hashTable, keys[i]);
    }

    return 0;
}
