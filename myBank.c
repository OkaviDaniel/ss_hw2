#include "myBank.h"
#include <stdio.h>
#define TOTAL_ACCOUNTS 50
int COUNTER_OF_OPENED_ACCOUNTS=0;
double myBank[2][TOTAL_ACCOUNTS];


void initMatrix()
{
    for(int i=0; i < TOTAL_ACCOUNTS; ++i)
    {   
     myBank[0][i]=0;
     myBank[1][i]=0;
    }
}

void createAccount()
{
    int i;
    double amountToInsert=0;

    if(COUNTER_OF_OPENED_ACCOUNTS<=TOTAL_ACCOUNTS)
    {      
        printf("Please enter amount for deposit: ");
        if(scanf("%lf",&amountToInsert)==1)
        {
            //getchar();
            for(i=0;i<TOTAL_ACCOUNTS;i++)
             {
                 //The available location
                if(myBank[1][i]==0)
                 {
                     //We will update the location to be unavailable
                    myBank[1][i]=1;
                    myBank[0][i] = myBank[0][i] + amountToInsert;

                    //We will update the account balance
                    printf("New account number is: %d\n" ,901 + i);
                    printf("\n");
                    COUNTER_OF_OPENED_ACCOUNTS++;
                    return;
                }
            }
        }
        else
        {
            printf("Failed to read the amount\n");
            printf("\n");
        }
        
    }
    else
    {
        printf("No space\n");
        printf("\n");
    }
}

void checkBalance(int accountNumber)
{
    if(isValid(accountNumber))
    {
        printf("The balance of account %d is: %.2lf\n",accountNumber,myBank[0][accountNumber-901]);
        printf("\n");
    }
}

void deposit(int accountNumber,double money)
{
    if(isValid(accountNumber))
    {
        myBank[0][accountNumber-901] =  myBank[0][accountNumber-901] + money;
        printf("The new balance is: %.2lf\n",myBank[0][accountNumber-901]);
        printf("\n");
    }
}

void withDrawal(int accountNumber,double money )
{
    if(isValid(accountNumber))
    {
        if(money > myBank[0][accountNumber-901])
        {
            printf("Cannot withdraw more than the balance\n");
            printf("\n");
        }
        else
        {
            myBank[0][accountNumber-901]-=money;
            printf("The new balance is: %.2lf\n",myBank[0][accountNumber-901]);
            printf("\n");
        }
    }
}

void closeAccount(int accountNumber)
{
    if(isValid(accountNumber))
    {
        myBank[1][accountNumber-901]=0;
        COUNTER_OF_OPENED_ACCOUNTS--;
        printf("Closed account number %d \n",accountNumber);
        printf("\n");
    }
}

void addInterest(double interest)
{
    int i;
    if(-99<=interest && interest <=99)
        for(i=0; i<TOTAL_ACCOUNTS; i++){

            if(myBank[1][i]==1)
            {
                myBank[0][i]+=myBank[0][i]*(interest/100);
            }
        }
    
}

void printAllOpenedAccounts()
{
    if(COUNTER_OF_OPENED_ACCOUNTS == 0)
    {
        printf("No opened accounts\n");
        printf("\n");
    }
    else
    {
        int i;
    for(i=0; i < TOTAL_ACCOUNTS; i++){

        if(myBank[1][i]==1)
        {
            printf("The balance of account number %d is: %.2lf\n",i+901,myBank[0][i]);
        }
    }
    printf("\n");
    }
}

void closeAllAccounts()
{
    int i;
    for(i=0; i < TOTAL_ACCOUNTS; i++)
    {
        myBank[1][i]=0;
    }
    COUNTER_OF_OPENED_ACCOUNTS=0;

}

//returns 1 in case of valid otherwose 0
int isValid(int accountNumber )
{

  //  printf("account is: %lf",accountNumber);
    if(accountNumber < 901 || accountNumber > 950)
    {
        printf("Account number must be a number between 901-950 !\n");
        printf("\n");
        return 0;
    }
    if(myBank[1][(int)accountNumber - 901]==0)
    {
        printf("This account is closed \n");
        printf("\n");
        return 0;
    }
    return 1;
}







