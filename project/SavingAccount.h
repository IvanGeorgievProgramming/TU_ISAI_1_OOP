#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include <stdexcept>
#include <string>

#include "BankAccount.h"

using namespace std;

class SavingAccount : public BankAccount {
private:
    double interestRate;

public:
    // * Constructor
    SavingAccount(int accountNumber, string accountName, double balance, double interestRate);

    // * Getters
    double getInterestRate();

    // * Setters
    void setInterestRate(double interestRate);

    // * Methods
    void addInterest();
    string toString();
};

#endif
