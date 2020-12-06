//
// Created by israela on 3.12.2020.
//

#ifndef SECONDPROJECT_MYBANK_H
#define SECONDPROJECT_MYBANK_H
#define TOTAL_ACCOUNTS 50
//myBank[0] accountNumber
//myBank[1] balance
//myBank[2] opened: 1- nonavailable ,0- available

void initMatrix();
void createAccount();
void checkBalance(int accountNumber);
void deposit(int accountNumber,double money);
void withDrawal(int accountNumber,double money);
void closeAccount(int accountNumber);
void addInterest(double interest);
void printAllOpenedAccounts();
void closeAllAccounts();
int isValid(int accountNumber );

#endif //SECONDPROJECT_MYBANK_H
