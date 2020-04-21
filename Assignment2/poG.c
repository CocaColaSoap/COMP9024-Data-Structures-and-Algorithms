#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include "Graph.h"
#include "list.h"

// Time complexity: O(N)
// Explanation: Check the disvisordegree for vertex degree first, if disvisordegree is 0, then it means 
// that there is no vertex connect with the current one, which means that the path has reached the end, and
// it should be store into struct path.
void findPath(Graph g, int vertexchange, List list, int length, Path path, int *divisordegree){
    int i = 0;
    bool flag = false;
    if(divisordegree[vertexchange] > 0){
        flag = true;
    }
    if (flag == true){  
         for(i = vertexchange+1;i<=(g->nV)-1;i++){
                if(adjacent(g, vertexchange, i)){                
                    List list_copy=copyLL(list);           
                    insertLL(list_copy, i);
                    findPath(g, i, list_copy, length + 1, path, divisordegree);
                }
            }  
        freeLL(list);
    }
    else{
        insertLL(list, length);
        insertPath(path, list);
        }
    }

// Time complexity: O((log(10)N)^2)
// Explanation: This function is used for to judge that whether the digits in a is all in b.
bool digitsIn(int a, int b){
    bool flag;
    int x;
    int y;
    int b_backup;
    b_backup = b;
    while(a>0){
        x = a % 10;
        flag = false;
        while(b>0){
            y = b % 10;
            if(x == y){
                flag = true;
                break;
            }
            b = b / 10;
        }
        if(flag == true){
            a = a / 10;
            b = b_backup;
        }
        else
            return false;    
    }
    return true;
}


// Time complexity: O(N^2)
// Explanation: This function is used for to connect vertex.
void addEdge(Graph g, int *divisor,int count, int *divisordegree){
    int i = 0, j = 0;
    for(i = 0; i < count; i ++){
        printf("%d: ", divisor[i]);
        for(j = i + 1; j < count; j ++){
            if((divisor[j] % divisor[i] ==0) && digitsIn(divisor[i], divisor[j])){
                printf("%d ", divisor[j]);
                Edge temp = {i, j};
                insertEdge(g,temp);
                divisordegree[i] += 1; 
            }
        }
        printf("\n");
    }
}

// Time complexity: O(N)
// Explanation: This funcation is used to translate the disvisor from list to an array.
void findDivisor(int *divisor, List list, int count){
    NodeT *x =list->head;
    for(int h = 0;h< count;h++){
        divisor[h] = x->v;
        x = x->next;
    }
    freeLL(list);
}

// Time complexity: O(N^3)
// Explanation: This function is used to caculate the length of the path and print the longest paths.
void findLongestPath(Path path, int *divisor){
    PathNodeT *p;
    NodeT *q;
    int max = 0;
    p = path->head;
    while(p!=NULL){
        q = p->list->head;
        while(q->next!=NULL){
            q = q->next;
        }
        if(max <= q->v){
            max = q->v;
        }
        p = p->next;
    }
    p = path->head;
    while(p!=NULL){
        q = p->list->head;
        while(q->next!=NULL){
            q = q->next;
        }
        if(max == q->v){
            q = p->list->head;
            while(q->next!=NULL){
                if(q->next->next==NULL){
                    printf("%d",divisor[q->v]);
                    break;
                }
                printf("%d < ",divisor[q->v]);
                q = q->next;
            } 
            printf("\n");
        }
        p = p->next;
    }
}

int main(int argc, char *argv[]){
    char *str = argv[1];
    int number;
    int i = 0;
    int count = 0;
    if (argc == 2) { 
        while(str[i]!='\0'){
            if (isdigit(str[i])){
                i++;
                continue;               
            }else{
                return 0;
            }
        }
    }
    number = atoi(str);
    List listpp = newLL();
    for(i = 1; i <= number; i++){
        if(number % i == 0){
            insertLL(listpp,i);
            count += 1;
        }
    }
    int *divisor = (int *) malloc(count * sizeof(int));
    int *divisordegree = calloc(count, sizeof(int));
    findDivisor(divisor, listpp, count);
    Path path = newpath();
    Graph g = newGraph(count);
    printf("Partial order : \n");
    addEdge(g, divisor, count, divisordegree);
    printf("Longest monotonically increasing sequences:\n");
    for(i = 0; i < count; i++){
        List LL = newLL();
        insertLL(LL, i);
        findPath(g, i, LL, 1, path, divisordegree);
    }
    findLongestPath(path, divisor);
    freeGraph(g);
    free(divisor);
    free(divisordegree);
    freePath(path);
}





