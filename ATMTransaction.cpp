#include <iostream>
#include <string>

class AtmTransaction
{
    private:
        std::string name;
        double balance;

    public:
        enum class AtmAction : int8_t
        {
            CheckBalance,
            Deposit,
            Withdraw,
            Exit
        };

        AtmTransaction(const std::string &name, double balance) : name(name), balance(balance)
        {
            if (balance < 0) balance = 0;
        }

        std::string getName() const
        {
            return name;
        }

        double getBalance() const
        {
            return balance;
        }

        void deposit(double amount)
        {
            if (amount > 0)
            {
                balance += amount;
            }
        }

        void withdraw(double amount)
        {
            if (amount > 0 && amount <= balance)
            {
                balance -= amount;
            }
        }
};

int main()
{
    double amount;
    AtmTransaction myAccount("Javad HP", 2000.0);

    bool running = true;
    while (running) {
        std::cout << "\n--- ATM Menu ---\n";
        std::cout << "0. Check Balance\n1. Deposit\n2. Withdraw\n3. Exit\n";
        std::cout << "Enter choice: ";
        
        int choice;
        std::cin >> choice;
        
        // Convert integer input into your strongly-typed enum
        AtmTransaction::AtmAction action = static_cast<AtmTransaction::AtmAction>(choice);

        switch (action) {
            case AtmTransaction::AtmAction::CheckBalance:
                std::cout << "The balance is: " << myAccount.getBalance() << "\n";
                break;
            case AtmTransaction::AtmAction::Deposit:
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                myAccount.deposit(amount);
                std::cout << "Deposited. Current balance: " << myAccount.getBalance() << "\n";
                break;
            case AtmTransaction::AtmAction::Withdraw:
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                myAccount.withdraw(amount);
                std::cout << "Withdrawn. Current balance: " << myAccount.getBalance() << "\n";
                break;
            case AtmTransaction::AtmAction::Exit:
                std::cout << "Thank you for using the ATM. Goodbye!\n";
                running = false; // Breaks the while loop
                break;
            default:
                std::cout << "Invalid selection. Try again.\n";
                break;
        }
    }
    return 0;
}