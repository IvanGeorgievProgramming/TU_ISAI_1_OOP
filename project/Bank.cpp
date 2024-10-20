#include <iostream>

#include "Bank.h"
#include "BankAccount.h"
#include "SavingAccount.h"

using namespace std;

// * Constructor

Bank::Bank(string bankName) {
    if (bankName == "") {
        throw invalid_argument("Bank name must not be empty");
    }
    this->bankName = bankName;
}

// * Getters

string Bank::getBankName() {
    return bankName;
}

vector<BankAccount>& Bank::getBankAccounts() {
    return bankAccounts;
}

vector<SavingAccount>& Bank::getSavingAccounts() {
    return savingAccounts;
}

// * Setters

void Bank::setBankName(string bankName) {
    if (bankName == "") {
        throw invalid_argument("Bank name must not be empty");
    }
    this->bankName = bankName;
}

void Bank::setBankAccounts(vector<BankAccount>& bankAccounts) {
    this->bankAccounts = bankAccounts;
}

void Bank::setSavingAccounts(vector<SavingAccount>& savingAccounts) {
    this->savingAccounts = savingAccounts;
}

// * Methods

void Bank::addBankAccount(BankAccount& bankAccount) {
    bankAccounts.push_back(bankAccount);
}

void Bank::addSavingAccount(SavingAccount& savingAccount) {
    savingAccounts.push_back(savingAccount);
}

void Bank::removeBankAccount(int accountNumber) {
    for (int i = 0; i < bankAccounts.size(); ++i) {
        if (bankAccounts[i].getAccountNumber() == accountNumber) {
            bankAccounts.erase(bankAccounts.begin() + i);
            return;
        }
    }
    throw invalid_argument("Account number not found");
}

void Bank::removeSavingAccount(int accountNumber) {
    for (int i = 0; i < savingAccounts.size(); ++i) {
        if (savingAccounts[i].getAccountNumber() == accountNumber) {
            savingAccounts.erase(savingAccounts.begin() + i);
            return;
        }
    }
    throw invalid_argument("Account number not found");
}

void Bank::displayAccounts() {
    cout << "Bank: " << bankName << endl;

    cout << "Bank Accounts:" << endl;
    if (bankAccounts.size() == 0) {
        cout << " - No bank accounts found" << endl;
    }
    else{
        for (int i = 0; i < bankAccounts.size(); ++i) {
            cout << bankAccounts[i].toString() << endl;
        }
    }

    cout << "Saving Accounts:" << endl;
    if (savingAccounts.size() == 0) {
        cout << " - No saving accounts found" << endl;
    }
    else{
        for (int i = 0; i < savingAccounts.size(); ++i) {
            cout << savingAccounts[i].toString() << endl;
        }
    }
}
