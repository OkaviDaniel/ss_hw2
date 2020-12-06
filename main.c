#include <stdio.h>
#include "myBank.h"
#define TOTAL_ACCOUNTS 50


int main() {
    
    int accountNumber=0;
    double money;
    double interest;
    char input;

    initMatrix();
    do
    {

      printf("Please choose a transaction type: \n");
      printf("O-Open Account \n");
      printf("B-Balance Inquiry \n");
      printf("D-Deposit \n");
      printf("W-Withdrawal \n");
      printf("C-Close Account \n");
      printf("I-Interest \n");
      printf("P-Print \n");
      printf("E-Exit\n");
      scanf(" %c",&input);

        switch (input)
        {
            case 'O':
                createAccount();
                break;

            case 'B':
                printf("Please enter account number: ");
                if(scanf("%d",&accountNumber)==1)
                {
                    checkBalance(accountNumber);
                    break;
                }
                else
                {
                    printf("Failed to read the account number\n");
                    printf("\n");
                    break;
                }
                
            case 'D':
                printf("Please enter account number: ");
                if(scanf("%d",&accountNumber)==1)
                {
                    printf("Please enter the amount to deposit: ");
                    if(scanf("%lf",&money)==1)
                    {
                        deposit(accountNumber,money);
                        break;
                    }
                    else
                    {
                        printf("Failed to read the amount\n");
                        printf("\n");
                        break;
                    }
                    
                }
                else
                {
                    printf("Failed to read the account number\n");
                    printf("\n");
                    break;
                }               
                
            case 'W':
                printf("Please enter account number: ");
                if(scanf("%d",&accountNumber)==1)
                {
                    printf("Please enter the amount to withdraw: ");
                    if(scanf("%lf",&money)==1)
                    {
                        withDrawal(accountNumber,money);
                        break;
                    }
                    else
                    {
                        printf("Failed to read the amount\n");
                        printf("\n");
                        break;
                    }                
                }
                else
                {
                    printf("Failed to read the account number\n");
                    printf("\n");
                    break;
                }
                
                
            case 'C':
                printf("Please enter account number: ");
                if(scanf("%d",&accountNumber)==1)
                {
                    closeAccount(accountNumber);
                    break;
                }
                else
                {
                    printf("Failed to read the account number\n");
                    printf("\n");
                    break;
                }
                


            case 'I':
                printf("Please enter interest rate: ");
                if(scanf("%lf",&interest)==1)
                {
                    addInterest(interest);
                    printf("\n");
                    break;
                }
                else
                {
                    printf("Failed to read the interest rate\n");
                    printf("\n");
                    break;
                }

            case 'P':
                printAllOpenedAccounts();
                break;

            case 'E':
                closeAllAccounts();
                return 0;
           
            default:
                printf("Invalid transaction type\n");
                printf("\n");
                break;
        }

    }while (1);

    return 0;
}





























