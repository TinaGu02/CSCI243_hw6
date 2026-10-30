#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define NUM_BUCKETS 16

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

struct HashTable {
    Entry *buckets[NUM_BUCKETS];
    size_t size;
};

HashTable *ht_create() {
    return calloc(1, sizeof(HashTable));
}

void ht_destroy(HashTable *self) {
    if(self == NULL) {
        return;
    }
    for(size_t i = 0; i < NUM_BUCKETS; i++) {
        Entry *item = self->buckets[i];
        while(item != NULL) {
            Entry *temp = item->next;
            free(item);
            item = temp;
        }
    }
    free(self);
}
