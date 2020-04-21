// Linked list interface ... COMP9024 18s2
#include <stdbool.h>

typedef struct node {
    int v;
    struct node *next;
} NodeT;
typedef struct ListRep {
   NodeT *head;
} ListRep;

typedef struct pathnode{
    struct pathnode *next;
    struct ListRep *list;
}PathNodeT;

typedef struct PathRep{
    PathNodeT *head;
}PathRep;
typedef struct ListRep *List;
typedef struct PathRep *Path;
List newLL();
void insertLL(List, int);
void freeLL(List);
void showLL(List);
int locationLL(List, int);
Path newpath();
void insertPath(Path,List);
void freePath(Path);
List copyLL(List);
