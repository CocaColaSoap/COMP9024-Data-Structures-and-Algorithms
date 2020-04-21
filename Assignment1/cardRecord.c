// Transport card record implementation ... Assignment 1 COMP9024 18s2
#include <stdio.h>
#include "cardRecord.h"

#define LINE_LENGTH 1024
#define NO_NUMBER -999

// scan input line for a positive integer, ignores the rest, returns NO_NUMBER if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return NO_NUMBER;
   else
      return n;
}

// scan input for a floating point number, ignores the rest, returns NO_NUMBER if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if (sscanf(line, "%f", &f) != 1)
      return NO_NUMBER;
   else
      return f;
}

int readValidID(void) {
   int flag = 1;
   int n;
   int cardNumber;
   int count = 0;

   printf("Enter card ID: ");
   while(flag){
      cardNumber = readInt();
      if(cardNumber != -999){
            n = cardNumber;  
            count = 0;        
            while(n != 0)
            {
                  n /= 10;
                  count += 1; 
            }
            if(count == 8)
                  flag = 0;
            else
                  printf("Not valid. Enter a valid value: "); 
      }
      else
            printf("Not valid. Enter a valid value: "); 
   }
   return cardNumber;
}

float readValidAmount(void) {
      int flag = 1;
      float cardAmount;
      printf("Enter amount: ");
      while(flag){
            cardAmount = readFloat();
            if(cardAmount > -2.35 && cardAmount < 250){
                  flag = 0;
            }
            else
                  printf("Not valid. Enter a valid value: ");
      }
      return cardAmount;
}

void printCardData(cardRecordT card) {
      printf("-----------------\n");
      printf("Card ID: %d\n", card.cardID);
      if (card.balance >= 0)
            printf("Balance: $%.2f\n", card.balance);
      else
            printf("Balance: -$%.2f\n", -card.balance);
      if(card.balance < 5)
            printf("Low balance\n");
      printf("-----------------\n");
}
}