#define TABLE_SIZE 250

typedef struct Node{
  char *key;
  int value;
}Node;

typedef struct{
    Node* table[TABLE_SIZE];
    int size;
}hashtable;

int hash(char *key);
Node* createNode(char *key,int value);
int lookup(hashtable *ht,char *key);
void insert(hashtable *ht,char *key,int value);
void delete(hashtable *ht,char *key);
void freeHashTable(hashtable *ht);
void initHashTable(hashtable *ht);
