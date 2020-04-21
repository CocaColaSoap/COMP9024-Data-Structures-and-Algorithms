/**
     main.c

     Program supplied as a starting point for
     Assignment 1: Transport card manager

     COMP9024 18s2
**/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "cardRecord.h"
#include "cardLL.h"
void printHelp();
void CardLinkedListProcessing();

int main(int argc, char *argv[]) {
int cardNumber;
float cardAmount;
char *str = argv[1];
int i = 0;
int numberofcards;
float sum = 0;
    if (argc == 2) { 
        while(str[i]!='\0'){
            if (isdigit(str[i])){
                i++;
                continue;               
            }else{
                CardLinkedListProcessing();
            }
        }
        numberofcards = atoi(str);
        cardRecordT *cardrecords=malloc(numberofcards * sizeof(cardRecordT));
        assert(cardrecords!=NULL);
        for(i = 0;i < numberofcards ;i++){
            cardNumber = readValidID();
            cardAmount = readValidAmount();
            sum += cardAmount;
            cardrecords[i].cardID = cardNumber;
            cardrecords[i].balance = cardAmount;
        }
        for(i = 0;i < numberofcards;i++){
            printCardData(cardrecords[i]);
        }
        printf("Number of cards on file: %d\n", numberofcards);
        if (sum/numberofcards >= 0)
            printf("Average balance: $%.2f\n", sum/numberofcards);
        else
            printf("Average balance: -$%.2f\n", -sum/numberofcards);
        free(cardrecords);   
   } else {
      CardLinkedListProcessing();
   }
   return 0;
}

/* Code for Stages 2 and 3 starts here */

void CardLinkedListProcessing() {
   int op, ch;
   int cardNumber;
   float cardAmount;
   int count;
   float avg;
   int  n;
   List list = newLL();   // create a new linked list
   
   while (1) {
      printf("Enter command (a,g,p,q,r, h for Help)> ");

      do {
	 ch = getchar();
      } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
      op = ch;
      // skip the rest of the line until newline is encountered
      while (ch != '\n') {
	 ch = getchar();
      }
      
      switch (op) {
        case 'a':
        case 'A':
        cardNumber = readValidID();
        cardAmount = readValidAmount(); 
        insertLL(list,cardNumber,cardAmount);
            /*** Insert your code for adding a card record ***/
            
            
	    break;

         case 'g':
         case 'G':       
            getAverageLL(list, &count, &avg);
            printf("Number of cards on file: %d\n",count);
            if (avg >= 0)
                printf("Average balance: $%.2f\n",avg);
            else
                printf("Average balance: $%.2f\n",-avg);
            /*** Insert your code for getting average balance ***/

	    break;
	    
         case 'h':
         case 'H':
            printHelp();
	    break;
	    
         case 'p':
         case 'P':
            showLL(list);
            /*** Insert your code for printing all card records ***/

	    break;

         case 'r':
         case 'R':
            n = readValidID();
            removeLL(list ,n);
            /*** Insert your code for removing a card record ***/

	    break;

	 case 'q':
         case 'Q':
            dropLL(list);       // destroy linked list before returning
	    printf("Bye.\n");
	    return;
      }
   }
}

void printHelp() {
   printf("\n");
   printf(" a - Add card record\n" );
   printf(" g - Get average balance\n" );
   printf(" h - Help\n");
   printf(" p - Print all records\n" );
   printf(" r - Remove card\n");
   printf(" q - Quit\n");
   printf("\n");
}
