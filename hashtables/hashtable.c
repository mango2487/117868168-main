#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// hash table implementaition (the engineer man YT)
// efficient way to store/retirve value by key

#define TABLE_SIZE 10000
// implement two structs (hash table itself/ and one entry in the hash table)

typedef struct entry_t { // entry in the table ()
    char * key;
    char * value:
    struct entry_t *next;
} entry_t;

typedef struct { //hash table (just an array of pointer to an entry)
    entry_t ** entries;
} ht_t;

// make hash function
unsigned int hash(const char *key){
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    // do several rounds of multiplication
    for (; i < key_len; i++) {
        value = value * 37 + key[i];
    }

    //make sure value is 0 <= value  < TABLE_SIZE
    value = value % TABLE_SIZE;
    return value;
}

entry_t *ht_pair(const char *key, const char *value) {
    // allocate the entry
    entry_t *entry = malloc(sizeof(entry_t) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    // copy the key and value in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    // next starts out null but may be set later on
    entry->next = NULL;

    return entry;
}


//making hash table
ht_t *ht_create(void){
    //alloc table
  ht_t *hashtable = malloc(sizeof(ht_t*) * 1);

  // alloc table entries
  hashtable->entries = malloc(sizeof(entry_t*) * TABLE_SIZE);

  // set each to NULL for proper opperation
  int i = 0;
  for (; i < TABLE_SIZE; i++) {
    hashtable->entries[i] = NULL;
  }

  return hashtable;

}

// implement a way to insert into hash table
void ht_set(ht_t *hashtable, const char *key, const char *value){
    unsigned int slot = hash(key);

    // try to look up an entry set
    entry_t *entry = hashtable->entries[slot];

    // no entry means slot empty, insert immediately
    if (entry == NULL) {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }

    entry_t * prev;

    // walk through each entry until either the und is
    // reached or a matching key is found
    while (entry != NULL) {
        //check key
        if(strcmp(entry->key, key) == 0) {
            // match found, replace value
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;
    }

    // end of chain reached without a match, add new
    prev->next = ht_t(key, value);
}

//ht_get function implementation
char *ht_get(ht_t *hashtable, const char *key) {
    unsigned int slot = hash(key);

    // try to find a valid slot
    entry_t *entry = hashtable-> entries[slot];

    // no slot means no entry
    if( entry == NULL) {
        return NULL;
    }

    //walk through each entry in the slot, which  could just
    // be a sigle thing
    while (entry != NULL) {
        // return value if found
        if (strcmp(entry->key, key) == 0) {
            return entry->value;
        }

        //proceed to next key if available
        entry  = entry->next;
    }

    // reaching here meaning there were >= 1 entries but no key match
    return NULL;
}

void ht_del(ht_t *hashtable, const char *key) {
    unsigned int bucket = hash(key);

    // try to find a valid bucket
    entry_t *entry = hashtable->entries[bucket];

    // no bucket means no entry
    if (entry == NULL) {
        return;
    }

    entry_t *prev;
    int idx = 0;

    // walk through each entry until either the end is reached or a matching key is found
    while (entry != NULL) {
        // check key
        if (strcmp(entry->key, key) == 0) {
            // first item and no next entry
            if (entry->next == NULL && idx == 0) {
                hashtable->entries[bucket] = NULL;
            }

            // first item with a next entry
            if (entry->next != NULL && idx == 0) {
                hashtable->entries[bucket] = entry->next;
            }

            // last item
            if (entry->next == NULL && idx != 0) {
                prev->next = NULL;
            }

            // middle item
            if (entry->next != NULL && idx != 0) {
                prev->next = entry->next;
            }

            // free the deleted entry
            free(entry->key);
            free(entry->value);
            free(entry);

            return;
        }

        // walk to next
        prev = entry;
        entry = prev->next;

        ++idx;
    }
}

 void ht_dump(ht_t * hashtable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        entry_t *entry = hashtable->entries[i];

        if (entry == NULL) {
            continue
        }

        printf("slot[%4d]: ", i);

        for (;;) {
            printf("%s=%s ", entry->key, entry->value);

            if (entry->next == NULL) {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
 }

int main(int argc, char **argv){
    ht_t *ht = ht_create();

    ht_set(ht, "name1", "em");
    ht_set(ht, "name2", "russion");
    ht_set(ht, "name3", "pizza");
    ht_set(ht, "name4", "doge");
    ht_set(ht, "name5", "pyro");
    ht_set(ht, "name6", "joost");
    ht_set(ht, "name7", "kalix");

    ht_dump(ht);

    return 0;
}
