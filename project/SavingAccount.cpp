#include <iostream>
#include <stdexcept>

#include "SavingAccount.h"

using namespace std;

// * Constructor

SavingAccount::SavingAccount(int accountNumber, string accountName, double balance, double interestRate) : BankAccount(accountNumber, accountName, balance) {
    if (interestRate != (double)interestRate) {
        throw invalid_argument("Interest rate must be a double");
    }
    if (interestRate < 0) {
        throw invalid_argument("Interest rate must be greater than or equal to 0");
    }
    this->interestRate = interestRate;
}

// * Getters

double SavingAccount::getInterestRate() {
    return interestRate;
}

// * Setters

void SavingAccount::setInterestRate(double interestRate) {
    if (interestRate < 0) {
        throw invalid_argument("Interest rate must be greater than or equal to 0");
    }
    this->interestRate = interestRate;
}

// * Methods

void SavingAccount::addInterest() {
    double interest = getBalance() * interestRate / 100;
    setBalance(getBalance() + interest);
}

string SavingAccount::toString() {
    return BankAccount::toString() + " Interest rate: " + to_string(interestRate) + "%";
}
