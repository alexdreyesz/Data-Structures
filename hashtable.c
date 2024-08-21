#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int HashTableSize = 0;
int HashTableCapacity = 5;
int BucketSize = 10;

typedef struct HashTable {
    char *word;
    int key;
    struct HashTable *next;

} HashTable;

HashTable* resize_table(HashTable *hash_table);
HashTable* create_node(HashTable *hash_table, char *word);
int createKey(char *word);
HashTable* linearProbing(HashTable *hash_table, int size);
HashTable* quadraticProbing(HashTable *hash_table, int size);
HashTable* chaining(HashTable *hash_table, int size);

// Create Node For Hash Table
HashTable* create_node(HashTable *hash_table, char *word) { 
    if(HashTableSize >= HashTableCapacity) {
        hash_table = resize_table(hash_table);
    }
    
    HashTable *new_node = (HashTable*)malloc(sizeof(HashTable));
    if (new_node == NULL) {
        printf("Memory Allocation For New Node Failed.\n");
        exit(1);
    }

    new_node->word = (char*)malloc((strlen(word) + 1) * sizeof(char));
    if (new_node->word == NULL) {
        printf("Memory allocation for word failed.\n");
        exit(1);
    }

    strcpy(new_node->word, word);
    new_node->key = createKey(word);

    hash_table[HashTableSize] = *new_node;
    HashTableSize++;

    // Free The Memory For new_node
    free(new_node);

    return hash_table;
}

// If Hash Table Size Exceed Hash Table Capacity Increase Capacity By twice It's Size
HashTable* resize_table(HashTable *hash_table) {
    HashTableCapacity = HashTableCapacity * 2;
    
    hash_table = (HashTable*)realloc(hash_table, HashTableCapacity * sizeof(HashTable));

    if (hash_table == NULL) {
        printf("Memory Reallocation Failed.\n");
        exit(1);
    }

    return hash_table;
}

// Create Key For Hash Table Node With word 
int createKey(char *word) {
    int value = 0;
   
    for(int i = 0; i < strlen(word); i++) {
        // Make The Range From "a" - "z" To Start From 0
        value = value - 97;
        
        // If Range Is From 'A' - 'Z' Accomodate The Value By 32
        if(word[i] >= 'A' && word[i] <= 'Z') {
            value = value + 32;
        }

        // Add The Values
        value = value + (int)word[i];
    }

    return value;
}

HashTable* linearProbing(HashTable *hash_table, int size) {
    HashTable *linear_hash_table = (HashTable*)malloc(BucketSize * sizeof(HashTable));

    // Initialize linear_hash_table
    for (int i = 0; i < BucketSize; i++) {
        linear_hash_table[i].word = NULL;
        linear_hash_table[i].key = -1;
        linear_hash_table[i].next = NULL;
    }

    int key = 0;
    
    for (int i = 0; i < size; i++) {
        key = hash_table[i].key % BucketSize;

        // Linear Probing To Find An Empty Spot
        while (linear_hash_table[key].word != NULL) {
            key = (key + 1) % BucketSize; // Wrap Around If Necessary
        }

        // Allocate Memory And Copy The Word
        linear_hash_table[key].word = (char*)malloc((strlen(hash_table[i].word) + 1) * sizeof(char));
        strcpy(linear_hash_table[key].word, hash_table[i].word);
        linear_hash_table[key].key = hash_table[i].key;
    }

    return linear_hash_table;
}

HashTable* quadraticProbing(HashTable *hash_table, int size) {
    HashTable *quadratic_hash_table = (HashTable*)malloc(BucketSize * sizeof(HashTable));

    // Initialize quadratic_hash_table
    for (int i = 0; i < BucketSize; i++) {
        quadratic_hash_table[i].word = NULL;
        quadratic_hash_table[i].key = -1;
        quadratic_hash_table[i].next = NULL;
    }

    int key = 0;
    int exponent = 0;
    
    for (int i = 0; i < size; i++) {
        key = hash_table[i].key % BucketSize;

        // Quadratic Probing To Find An Empty Spot
        while (quadratic_hash_table[key].word != NULL) {
            key = (key + 2^exponent) % BucketSize; // Wrap Around If Necessary
            exponent++;
            continue;
        }

        exponent = 0;

        // Allocate Memory And Copy The Word
        quadratic_hash_table[key].word = (char*)malloc((strlen(hash_table[i].word) + 1) * sizeof(char));
        strcpy(quadratic_hash_table[key].word, hash_table[i].word);
        quadratic_hash_table[key].key = hash_table[i].key;
    }

    return quadratic_hash_table;
}

HashTable* chaining(HashTable *hash_table, int size) {
    HashTable *chaining_hash_table = (HashTable*)malloc(BucketSize * sizeof(HashTable));

    // Initialize chaining_hash_table
    for (int i = 0; i < BucketSize; i++) {
        chaining_hash_table[i].word = NULL;
        chaining_hash_table[i].key = -1;
        chaining_hash_table[i].next = NULL;
    }

    int key = 0;
    
    for (int i = 0; i < size; i++) {
        key = hash_table[i].key % BucketSize;

        // If The Slot Is Empty Place The New Node Directly
        if (chaining_hash_table[key].word == NULL) {
            chaining_hash_table[key].word = (char*)malloc((strlen(hash_table[i].word) + 1) * sizeof(char));
            strcpy(chaining_hash_table[key].word, hash_table[i].word);
            chaining_hash_table[key].key = hash_table[i].key;
            chaining_hash_table[key].next = NULL;
        } else {
            // If The Slot Is Not Empty Chain The New Node
            HashTable *temp = chaining_hash_table + key;

            // Traverse To The End Of The Linked List
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // Allocate A New Node At The End Of The Linked List
            temp->next = (HashTable*)malloc(sizeof(HashTable));
            temp->next->word = (char*)malloc((strlen(hash_table[i].word) + 1) * sizeof(char));
            strcpy(temp->next->word, hash_table[i].word);
            temp->next->key = hash_table[i].key;
            temp->next->next = NULL;
        }
    }

    return chaining_hash_table;
}


int main() {
    // Create Hash Table
    HashTable *hash_table = (HashTable*)malloc(HashTableCapacity * sizeof(HashTable));
    
    if (hash_table == NULL) {
        printf("Initial Memory Allocation Failed.\n");
        return 1;
    }

    // Insert Nodes To Hash Table
    hash_table = create_node(hash_table, "Car");
    hash_table = create_node(hash_table, "Dog");
    hash_table = create_node(hash_table, "Airplane");
    hash_table = create_node(hash_table, "Rock");
    hash_table = create_node(hash_table, "Fire");
    hash_table = create_node(hash_table, "Water");
    hash_table = create_node(hash_table, "Cat");
    hash_table = create_node(hash_table, "Wood");

    printf("\n");

    // Print Each Table 
    for(int i = 0; i < HashTableSize; i++) {
        printf("word: %s, Key: %d\n", hash_table[i].word, hash_table[i].key);
    }

    // Create Linear Probing Bucket
    HashTable *linear_hash_table = (HashTable*)malloc(BucketSize * sizeof(HashTable));

    if (linear_hash_table == NULL) {
        printf("Initial Memory Allocation Failed.\n");
        return 1;
    }

    linear_hash_table = linearProbing(hash_table, HashTableSize);

    printf("\n\nLINEAR PROBING:\n");
    for(int i = 0; i < BucketSize; i++) {
        if(linear_hash_table[i].word == NULL) {
            printf("Bucket: %d,  NULL\n", i);
        } else {
            printf("Bucket: %d,  %s\n", i, linear_hash_table[i].word);
        }
    }

    // Create Quadratic Probing Bucket
    HashTable *quadratic_hash_table = (HashTable*)malloc(BucketSize * sizeof(HashTable));

    if (hash_table == NULL) {
        printf("Initial Memory Allocation Failed.\n");
        return 1;
    }

    quadratic_hash_table = quadraticProbing(hash_table, HashTableSize);

    printf("\n\nQUADRATIC PROBING:\n");
    for(int i = 0; i < BucketSize; i++) {
        if(quadratic_hash_table[i].word == NULL) {
            printf("Bucket: %d,  NULL\n", i);
        } else {
            printf("Bucket: %d,  %s\n", i, quadratic_hash_table[i].word);
        }
    }

    
    // Create Chaining Bucket
    HashTable *chaining_hash_table = (HashTable*)malloc(BucketSize * sizeof(HashTable));

    if (hash_table == NULL) {
        printf("Initial Memory Allocation Failed.\n");
        return 1;
    }

    chaining_hash_table = chaining(hash_table, HashTableSize);
    
    printf("\n\nCHAINING:\n");
    for (int i = 0; i < BucketSize; i++) {
        if (chaining_hash_table[i].word == NULL) {
            printf("Bucket: %d, NULL\n", i);
        } else {
            printf("Bucket: %d, %s", i, chaining_hash_table[i].word);
            HashTable *temp = chaining_hash_table[i].next;

            // Traverse the linked list and print each word
            while (temp != NULL) {
                printf(" -> %s", temp->word);
                temp = temp->next;
            }
            printf("\n");
        }
    }


    // Free Allocated Memory For hash_table
    for (int i = 0; i < HashTableSize; i++) {
        free(hash_table[i].word);
    }

    free(hash_table);


    // Free Allocated Memory For linear_hash_table
    for (int i = 0; i < BucketSize; i++) {
        if (linear_hash_table[i].word != NULL) {
        free(linear_hash_table[i].word);
        }
    }

    free(linear_hash_table);


    // Free Allocated Memory For quadratic_hash_table
    for (int i = 0; i < BucketSize; i++) {
        if (quadratic_hash_table[i].word != NULL) {
        free(linear_hash_table[i].word);
        }
    }

    free(quadratic_hash_table);


    // Free Allocated Memory For chaining_hash_table
    for (int i = 0; i < BucketSize; i++) {
        if (chaining_hash_table[i].word != NULL) {
        free(chaining_hash_table[i].word);
        }
    }

    free(chaining_hash_table);

    return 0;
}
