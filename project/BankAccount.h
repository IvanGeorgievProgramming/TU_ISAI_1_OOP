#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountName;
    double balance;

public:
    // * Constructor
    BankAccount(int accountNumber, string accountName, double balance);

    // * Getters
    int getAccountNumber();
    string getAccountName();
    double getBalance();

    // * Setters
    void setAccountNumber(int accountNumber);
    void setAccountName(string accountName);
    void setBalance(double balance);

    // * Methods
    void deposit(double amount);
    void withdraw(double amount);
    string toString();
};

#endif
