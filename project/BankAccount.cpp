#include <string>
#include <stdexcept>
#include <iostream>

#include "BankAccount.h"

using namespace std;

// * Constructor

BankAccount::BankAccount(int accountNumber, string accountName, double balance) {
    if (accountNumber != (int)accountNumber) {
        throw invalid_argument("Account number must be an integer");
    }
    if (accountNumber <= 0) {
        throw invalid_argument("Account number must be greater than 0");
    }
    if (accountName == "") {
        throw invalid_argument("Account name must not be empty");
    }
    if(balance != (double)balance) {
        throw invalid_argument("Balance must be a double");
    }
    if (balance < 0) {
        throw invalid_argument("Balance must be greater than or equal to 0");
    }

    this->accountNumber = accountNumber;
    this->accountName = accountName;
    this->balance = balance;
}

// * Getters

int BankAccount::getAccountNumber() {
    return accountNumber;
}

string BankAccount::getAccountName() {
    return accountName;
}

double BankAccount::getBalance() {
    return balance;
}

// * Setters

void BankAccount::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}

void BankAccount::setAccountName(string accountName) {
    this->accountName = accountName;
}

void BankAccount::setBalance(double balance) {
    this->balance = balance;
}

// * Methods

void BankAccount::deposit(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Amount must be greater than 0");
    }
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw invalid_argument("Amount must be greater than 0");
    }
    if (amount > balance) {
        throw invalid_argument("Amount must not be greater than balance");
    }
    balance -= amount;
}

string BankAccount::toString() {
    return "Account:\n - Account Number: " + to_string(accountNumber) + "\n - Account Name: " + accountName + "\n - Balance: " + to_string(balance) + "\n";
}
