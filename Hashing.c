#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table
#define TABLE_SIZE 10

// Structure to represent a node in the hash table
struct Node
{
    int key;
    int value;
    struct Node *next;
};

// Structure to represent the hash table
struct HashTable
{
    struct Node *table[TABLE_SIZE];
};

// Function to create a new node
struct Node *createNode(int key, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to create a hash table
struct HashTable *createHashTable()
{
    struct HashTable *hashTable = (struct HashTable *)malloc(sizeof(struct HashTable));

    // Initialize each bucket in the hash table to NULL
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable->table[i] = NULL;
    }

    return hashTable;
}

// Hash function to calculate the index in the hash table
int hash(int key)
{
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable *hashTable, int key, int value)
{
    int index = hash(key);

    // Create a new node with the key-value pair
    struct Node *newNode = createNode(key, value);

    // Check if the bucket is empty
    if (hashTable->table[index] == NULL)
    {
        hashTable->table[index] = newNode;
    }
    else
    {
        // Collision handling: Add to the front of the linked list
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }
}

// Function to retrieve the value associated with a key from the hash table
int get(struct HashTable *hashTable, int key)
{
    int index = hash(key);

    // Traverse the linked list at the index
    struct Node *current = hashTable->table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            // Key found, return the associated value
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return -1;
}

// Function to display the contents of the hash table
void display(struct HashTable *hashTable)
{
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("%d: ", i);

        // Traverse the linked list at the current index
        struct Node *current = hashTable->table[i];
        while (current != NULL)
        {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }

        printf("NULL\n");
    }
}

// Function to free the memory allocated for the hash table
void freeHashTable(struct HashTable *hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        // Traverse the linked list at the current index
        struct Node *current = hashTable->table[i];
        while (current != NULL)
        {
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(hashTable);
}

int main()
{
    // Create a hash table
    struct HashTable *myHashTable = createHashTable();

    // Insert key-value pairs
    insert(myHashTable, 1, 10);
    insert(myHashTable, 11, 20);
    insert(myHashTable, 21, 30);
    insert(myHashTable, 31, 40);
    insert(myHashTable, 2, 50);
    insert(myHashTable, 12, 60);

    // Display the contents of the hash table
    display(myHashTable);

    // Retrieve values using keys
    printf("\nValue for key 11: %d\n", get(myHashTable, 11));
    printf("Value for key 2: %d\n", get(myHashTable, 2));
    printf("Value for key 31: %d\n", get(myHashTable, 31));

    // Free the memory allocated for the hash table
    freeHashTable(myHashTable);

    return 0;
}
