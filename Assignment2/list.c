// Linked list implementation ... COMP9024 18s2
#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

Path newpath(){
  PathRep *path = malloc(sizeof(PathRep));
  assert(path!=NULL);
  path->head = NULL;
  return path;
}

List newLL() {
    ListRep *list=malloc(sizeof(ListRep));
    assert(list!=NULL);
    list->head = NULL;
    return list;  
}

void insertLL(List listp, int n){
  if(listp->head == NULL){
    NodeT *head = malloc(sizeof(NodeT));
    assert(head!=NULL);
    head->v = n;
    head->next = NULL;
    listp->head = head;
  }
  else if(listp->head != NULL){
    NodeT *p;
    p = listp->head;
    while(p->next!=NULL){
      p = p->next;
    }
    NodeT *new = malloc(sizeof(NodeT));
    assert(new!=NULL);
    new->v = n;
    new->next = NULL;
    p->next = new;
  }
}

void showLL(List listp) {
   NodeT *p;
   p = listp->head;
   while(p!=NULL){
        printf("%d ", p->v);
        p = p->next;
   }
}

void freeLL(List listp) {
    NodeT *p;
    p = listp->head;
    while(p!=NULL){
        NodeT *temp = p->next;
        free(p);
        p = temp;
    }
}

int locationLL(List listp, int n){
  if (listp==NULL)
    return -1;
  NodeT *p;
  int i = 0;
  p = listp->head;
  while(p!=NULL){
    if(p->v == n)
      return i;
    i++;
    p = p->next;
  }
  return -1;
}

void insertPath(Path path, List listp){
  if (path->head == NULL){
    PathNodeT *head = malloc(sizeof(PathNodeT));
    assert(head!=NULL);
    head->next = NULL;
    head->list = listp;
    path->head = head;
  }
  else{
    PathNodeT *p;
    p = path->head;
    while(p->next!=NULL){
      p = p->next;
    }
    PathNodeT *new = malloc(sizeof(PathNodeT));
    assert(new!=NULL);
    new->list = listp;
    new->next = NULL;
    p->next = new;
  }
}

void freePath(Path path){
  PathNodeT *p;
  p = path->head;
  while(p!=NULL){
    PathNodeT *temp = p->next;
    freeLL(p->list);
    free(p);
    p = temp;
  }
}

// Time complexity: O(N)
// This function is used to copy a List
List copyLL(List list){
  List L_copy = newLL();
  NodeT *p = list->head;
  while(p!=NULL){
    insertLL(L_copy, p->v);
    p = p->next;
  }
  return L_copy;
}