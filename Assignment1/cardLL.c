// Linked list of transport card records implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cardLL.h"
#include "cardRecord.h"

// linked list node type
// DO NOT CHANGE
typedef struct node {
    cardRecordT data;
    struct node *next;
} NodeT;

// linked list type
typedef struct ListRep {
   NodeT *head;

/* Add more fields if you wish */

} ListRep;

/*** Your code for stages 2 & 3 starts here ***/

// Time complexity: O(1)
// Explanation: new an empty list.
List newLL() {
    ListRep *list=malloc(sizeof(ListRep));
    assert(list!=NULL);
    list->head = NULL;
    return list;  
}

// Time complexity: O(n)
// Explanation: Drop the list from the head until there is no Node in the list.
void dropLL(List listp) {
    NodeT *p;
    p = listp->head;
    while(p!=NULL){
        NodeT *temp = p->next;
        free(p);
        p = temp;
    }
}

// Time complexity:O(n) 
// Explanation: The removeLL will consider three situations, if the list is NULL,
// then just return Card not found, if the head's cardID is equal to the cardID that should be removed,
// then do the remove operation, at last it will scan the list, if the cardID is found in the list then remove,
// else print it is not in the list.
void removeLL(List listp, int cardID) {
    if (listp->head == NULL){
        printf("Card not found.\n");
    }else if (listp->head->data.cardID == cardID){
        NodeT *temp = listp->head->next;
        free(listp->head);
        listp->head = temp;
        printf("Card removed.\n");      
    }else{
        NodeT *p = listp->head;
        while((p->next!=NULL) && (p->next->data.cardID != cardID)){
            p = p->next;
        }
        if (p->next!=NULL){
            NodeT *temp = p->next->next;
            free(p->next);
            p->next = temp;
            printf("Card removed.\n");      
        }else{
            printf("Card not found.\n");
        }
    }
}

// Time complexity: O(2n)
// Explanation: First check whether the list is null, if the list is null, then insert into the head.
// if the head is not null, then check whether the cardID is in the list, if in , then add or minus the amount,
// else add the new card in the list.
void insertLL(List listp, int cardID, float cardAmount) {
   if (listp->head == NULL){
       NodeT *head = malloc(sizeof(NodeT));
       assert(head!=NULL);
       head->data.cardID = cardID;
       head->data.balance = cardAmount;
       head->next = NULL;
       listp->head = head;
       printf("Card added.\n");
   }
   else if(listp->head != NULL){
       NodeT *p;
       int flag = 1;
       p = listp->head;
       while(1){
           if(p->data.cardID == cardID){
               flag = 0;
               break;
           }
           if(p->next!=NULL){
               p = p->next;
           }else
               break;
       }
       if (flag == 1){
          NodeT *new = malloc(sizeof(NodeT));
          assert(new!=NULL);
          new->data.cardID = cardID;
          new->data.balance = cardAmount;
          if(cardID < listp->head->data.cardID){
              new->next = listp->head;
              listp->head = new;
              printf("Card added.\n");
          }else{
            p = listp->head;
            while((p->next!=NULL) && (cardID > p->next->data.cardID)){
                p = p->next;
                }
            if(p->next==NULL){
                new->next = NULL;
                p->next = new;
            }
            else{
                NodeT *temp = p->next;
                p->next = new;
                new->next = temp;
            }
            printf("Card added.\n");
          }
        }
        else if(flag == 0){
           p->data.balance += cardAmount;
           printf("-----------------\n");
           printf("Card ID: %d\n", p->data.cardID);
           if (p->data.balance >= 0)
                printf("Balance: $%.2f\n", p->data.balance);
           else
                printf("Balance: $%.2f\n", -p->data.balance);
           if (p->data.balance < 5){
                printf("Low balance\n");
           }
           printf("-----------------\n");
        }
    }
}

// Time complexity: O(n)
// Explanation: scan the list until the pointer point to null.
void getAverageLL(List listp, int *n, float *balance) {
    if(listp->head==NULL){
        *n = 0;
        *balance = 0;
    }
    else{
        *n = 0;
        *balance = 0;
        float sum = 0;
        NodeT *p = listp->head;
        while(p!=NULL){
            *n += 1;
            sum += p->data.balance;
            p = p->next;
        }
        *balance = sum / *n; 
    }
}

// Time complexity: O(n)
// Explanation: In order to show all nodes in the list,
//so there should be a pointer starts from the head of the list,
//and the loop will be stoped until the pointer point to NULL, which is the next of the last node of the list.
void showLL(List listp) {
   NodeT *p;
   p = listp->head;
   while(p!=NULL){
        printf("-----------------\n");
        printf("Card ID: %d\n", p->data.cardID);
        if (p->data.balance >= 0)
            printf("Balance: $%.2f\n", p->data.balance);
        else
            printf("Balance: -$%.2f\n", -p->data.balance);
        if(p->data.balance < 5)
            printf("Low balance\n");
        printf("-----------------\n");
        p = p->next;
   }
}