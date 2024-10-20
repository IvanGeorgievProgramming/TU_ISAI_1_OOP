#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include <stdexcept>

#include "BankAccount.h"
#include "SavingAccount.h"

using namespace std;

class Bank {
private:
    string bankName;
    vector<BankAccount> bankAccounts;
    vector<SavingAccount> savingAccounts;

public:
    // * Constructor
    Bank(string bankName);

    // * Getters
    string getBankName();
    vector<BankAccount>& getBankAccounts();
    vector<SavingAccount>& getSavingAccounts();

    // * Setters
    void setBankName(string bankName);
    void setBankAccounts(vector<BankAccount>& bankAccounts);
    void setSavingAccounts(vector<SavingAccount>& savingAccounts);

    // * Methods
    void addBankAccount(BankAccount& bankAccount);
    void addSavingAccount(SavingAccount& savingAccount);
    void removeBankAccount(int accountNumber);
    void removeSavingAccount(int accountNumber);
    void displayAccounts();
};

#endif
