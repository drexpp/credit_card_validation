//Project for cs50
//It follows the Luhn's algorithm in order to determinate if a credit card is valid, also prints the company of it.
#include<stdio.h>
#include<cs50.h>
#include<math.h>
 
int main(){      
    long long CardNumber;
     
    do{                                     //Asks for user credit card
        printf("Number: ");
        CardNumber = GetLongLong();
         
            if (CardNumber < pow(10,13)){
                printf("INVALID\n");
                return 0;
        }
 
    }while (CardNumber < pow(10,13) || CardNumber > pow(10,16) || CardNumber == pow(10,14));
     
    long long cc_number = CardNumber;       //Will be used to print out the credit card names later on
    int cc_card_1 = (cc_number/pow(10,13));
    int cc_card_2 = (cc_number/pow(10,14));
    int cc_card_3 = (cc_number/pow(10,15));
    int cc_card_4 = (cc_number/pow(10,12));
     
    int totalsum = 0;                       //Uses Luhn's algorithm to validate credit cards
    for(int i = 0; CardNumber != 0;i++){
        if( i%2 == 0){                      //If it's not a 2n digit of CC saves the number and keeps checking the rest of numbers
            totalsum += CardNumber % 10;
        }
        else{                               //When finds a 2n digit uses module to save it and the proceed to check if it's a double digit and separate it
            int EvenDigits = 0;
            EvenDigits = (2*(CardNumber%10));
            totalsum += (EvenDigits%10) + (EvenDigits/10);
        }
    CardNumber = CardNumber/10;
    }
    if (totalsum %10 != 0){                 // If it doesnt pass Luhn's algorithm will prompt out INVALID 
        printf("INVALID\n");
        return 0;
    }
                                            //short if..else statements for credit card names.
    CardNumber < pow(10,16) && cc_card_1 == 37 ? printf("AMEX\n") :((CardNumber < pow(10,17) && (cc_card_2 > 50 && cc_card_2 < 56)) ? printf("MASTERCARD\n") : 
    (CardNumber < pow(10,17) && (cc_card_3 == 4 || cc_card_4 == 4)) ? printf("VISA\n") :printf("INVALID\n"));
    return 0;
}
