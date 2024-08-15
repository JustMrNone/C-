#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
    string accountType;
    float accountBalance;
    vector<string> transactionHistory;
    // Protected method to update transaction history
    void addTransactionToHistory(const string& transaction) {
        transactionHistory.push_back(transaction);
    }

public:
    // Constructor
    BankAccount(string number, string holderName, string type, float balance)
        : accountNumber(number), accountHolderName(holderName), accountType(type), accountBalance(balance) {}

    // Getter methods
    string getAccountNumber() const { return accountNumber; }
    string getAccountHolderName() const { return accountHolderName; }
    string getAccountType() const { return accountType; }
    float getAccountBalance() const { return accountBalance; }
    const vector<string>& getTransactionHistory() const { return transactionHistory; }

    // Setter methods
    void setAccountNumber(string number) { accountNumber = number; }
    void setAccountHolderName(string holderName) { accountHolderName = holderName; }
    void setAccountType(string type) { accountType = type; }
    void setAccountBalance(float balance) { accountBalance = balance; }

    // Deposit method
    void deposit(float amount) {
        accountBalance += amount;
        transactionHistory.push_back("Deposit: +" + to_string(amount));
    }

    // Withdraw method
    void withdraw(float amount) {
        if (amount > accountBalance) {
            cout << "Error: Insufficient funds for withdrawal." << endl;
        } else {
            accountBalance -= amount;
            transactionHistory.push_back("Withdrawal: -" + to_string(amount));
        }
    }

    // Transfer funds from one account to another
    virtual void transfer(BankAccount& recipient, float amount) {
        if (amount > accountBalance) {
            cout << "Error: Insufficient funds for transfer." << endl;
        } else {
            withdraw(amount);
            recipient.deposit(amount);
            transactionHistory.push_back("Transfer: -" + to_string(amount) + " to " + recipient.getAccountNumber());
            recipient.transactionHistory.push_back("Transfer: +" + to_string(amount) + " from " + accountNumber);
        }
    }

    // Virtual method for interest rate with a default implementation
    virtual float getInterestRate() const {
        return 0.0; // Default interest rate for base class
    }

    // Calculate interest earned on a SavingsAccount balance based on compounding frequency
    virtual float calculateInterest(int compoundingFrequency) const {
        return 0.0; // Default interest calculation for base class
    }
};

// Child class: SavingsAccount
class SavingsAccount : public BankAccount {
public:
    // Constructor
    SavingsAccount(string number, string holderName, float balance)
        : BankAccount(number, holderName, "Savings", balance) {}

    // Override calculateInterest method
    float calculateInterest(int compoundingFrequency) const override {
        float annualInterestRate = getInterestRate();
        float compoundedInterest = getAccountBalance() * pow(1 + (annualInterestRate / compoundingFrequency), compoundingFrequency) - getAccountBalance();
        return compoundedInterest;
    }

    // Override getInterestRate method
    float getInterestRate() const override {
        return 0.03; // Example interest rate for SavingsAccount
    }
};

// Child class: CheckingAccount
class CheckingAccount : public BankAccount {
public:
    // Constructor
    CheckingAccount(string number, string holderName, float balance)
        : BankAccount(number, holderName, "Checking", balance) {}

    // Override getInterestRate method
    float getInterestRate() const override {
        return 0.01; // Example interest rate for CheckingAccount
    }
};

// Child class: CreditAccount
class CreditAccount : public BankAccount {
private:
    float interestRate;

public:
    // Constructor
    CreditAccount(string number, string holderName, float balance, float rate)
        : BankAccount(number, holderName, "Credit", balance), interestRate(rate) {}

    // Override calculateInterest method
    float calculateInterest(int compoundingFrequency) const override {
        float compoundedInterest = getAccountBalance() * pow(1 + (interestRate / compoundingFrequency), compoundingFrequency) - getAccountBalance();
        return compoundedInterest;
    }

    // Override getInterestRate method
    float getInterestRate() const override {
        return interestRate;
    }
};

// Child class: JointAccount
class JointAccount : public BankAccount {
private:
    vector<string> accountHolders;

public:
    // Constructor
    JointAccount(string number, const vector<string>& holders, float balance)
        : BankAccount(number, "Joint Account", "Joint", balance), accountHolders(holders) {}

    // Override transfer method for JointAccount
     void transfer(BankAccount& recipient, float amount) override {
        // JointAccount allows transfers to any account holder
        BankAccount::transfer(recipient, amount);
        addTransactionToHistory("Transfer: +" + to_string(amount) + " from Joint Account");
    }

    // Override getInterestRate method
     float getInterestRate() const override {
        return 0.02; // Example interest rate for JointAccount
    }
};

int main() {
    // Example usage
    BankAccount* account1 = new SavingsAccount("123456", "John Doe", 1000.0);
    BankAccount* account2 = new CheckingAccount("987654", "Bob Smith", 1500.0);

    // Deposit and withdraw
    account1->deposit(500.0);
    account1->withdraw(300.0);
    account2->deposit(200.0);

    // Transfer funds
    account1->transfer(*account2, 200.0);

    // Calculate interest
    float savingsInterest = account1->calculateInterest(12);
    float creditInterest = account2->calculateInterest(12);

    // Output transaction history for Savings Account
    cout << "Transaction History for Savings Account:" << endl;
    for (const auto& transaction : account1->getTransactionHistory()) {
        cout << transaction << endl;
    }

    // Output interest earned
    cout << "Interest earned on Savings Account: " << savingsInterest << endl;
    cout << "Interest charged on Credit Account: " << creditInterest << endl;

    delete account1;
    delete account2;

    return 0;
}
