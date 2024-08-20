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

HashTable* linearProbing(){

}

HashTable* quadraticProbing() {

}

HashTable* chaining() {

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

    printf("\n\n");

    // Create Linear Probing Bucket
    HashTable *linear_hash_table = (HashTable*)malloc(BucketSize * sizeof(HashTable));

    if (linear_hash_table == NULL) {
        printf("Initial Memory Allocation Failed.\n");
        return 1;
    }

    linear_hash_table = linearProbing(hash_table, HashTableSize);

    for(int i = 0; i < BucketSize; i++) {
        if(linear_hash_table == NULL) {
            printf("Bucket: %d  NULL", i);
        }

        printf("Bucket: %d  Word: %s", i, linear_hash_table->word);
    }

    // Create Quadratic Probing Bucket
    HashTable *quadratic_hash_table = (HashTable*)malloc(BucketSize * sizeof(HashTable));

    if (hash_table == NULL) {
        printf("Initial Memory Allocation Failed.\n");
        return 1;
    }

    quadratic_hash_table = quadraticProbing(hash_table, HashTableSize);

    for(int i = 0; i < BucketSize; i++) {
        if(quadratic_hash_table == NULL) {
            printf("Bucket: %d  NULL", i);
        }

        printf("Bucket: %d  Word: %s", i, quadratic_hash_table->word);
    }

    // Create Chaining Bucket
    HashTable *chaining_hash_table = (HashTable*)malloc(BucketSize * sizeof(HashTable));

    if (hash_table == NULL) {
        printf("Initial Memory Allocation Failed.\n");
        return 1;
    }

    chaining_hash_table = chaining(hash_table, HashTableSize);

    for(int i = 0; i < BucketSize; i++) {
        if(chaining_hash_table == NULL) {
            printf("Bucket: %d  NULL", i);
        }

        printf("Bucket: %d  Word: %s", i, chaining_hash_table->word);
    }

    // Free Allocated Memory For Each Node Word
    for (int i = 0; i < HashTableSize; i++) {
        free(hash_table[i].word);
    }

    // Free Hash Table
    free(hash_table);

    return 0;
}
