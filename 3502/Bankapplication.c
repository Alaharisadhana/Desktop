#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_BALANCE 50.0 // Minimum balance requirement

// Structure to represent an account
struct Account {
    int accountNumber;
    char name[100];
    char bankName[100];
    char branch[100];
    char address[200];
    int pin; // Add PIN number
    double balance;
};

// Function to create a new account
struct Account createAccount(int accountNumber, char name[], char bankName[], char branch[], char address[], int pin) {
    struct Account newAccount;
    newAccount.accountNumber = accountNumber;
    strcpy(newAccount.name, name);
    strcpy(newAccount.bankName, bankName);
    strcpy(newAccount.branch, branch);
    strcpy(newAccount.address, address);
    newAccount.pin = pin;
    newAccount.balance = MIN_BALANCE; // Initialize balance to the minimum
    return newAccount;
}

// Function to deposit cash into an account
void deposit(struct Account *account, int pin, double amount) {
    if (account->pin != pin) {
        printf("Invalid PIN. Deposit failed.\n");
    } else {
        account->balance += amount;
        printf("Deposited %.2lf into account %d\n", amount, account->accountNumber);
    }
}

// Function to withdraw cash from an account
void withdraw(struct Account *account, int pin, double amount) {
    if (account->pin != pin) {
        printf("Invalid PIN. Withdrawal failed.\n");
    } else if (account->balance >= amount && (account->balance - amount) >= MIN_BALANCE) {
        account->balance -= amount;
        printf("Withdrawn %.2lf from account %d\n", amount, account->accountNumber);
    } else if (account->balance < amount) {
        printf("Insufficient balance in account %d\n", account->accountNumber);
    } else {
        printf("Minimum balance requirement not met. Withdrawal failed.\n");
    }
}

// Function to display account information
void displayAccount(struct Account account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.name);
    printf("Bank Name: %s\n", account.bankName);
    printf("Branch: %s\n", account.branch);
    printf("Address: %s\n", account.address);
    printf("Balance: %.2lf\n", account.balance);
}

int main() {
    struct Account currentAccount;
    int choice;
    int accountNumber;
    char name[100];
    char bankName[100];
    char branch[100];
    char address[200];
    int pin; // Add PIN
    double amount;

    while (1) {
        //system("cls"); // Clear the screen (Windows)
        printf("\x1b[2J");
        printf("Banking Application Menu\n");
        printf("1. Create New Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Information\n");
        printf("5. Logout\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter account holder name: ");
                scanf("%s", name);
                printf("Enter bank name: ");
                scanf("%s", bankName);
                printf("Enter branch: ");
                scanf("%s", branch);
                printf("Enter address: ");
                scanf("%s", address);
                printf("Enter PIN: ");
                scanf("%d", &pin);
                currentAccount = createAccount(accountNumber, name, bankName, branch, address, pin);
                printf("Account created successfully!\n");
                break;
            case 2:
                if (currentAccount.accountNumber == 0) {
                    printf("Please create an account first.\n");
                } else {
                    int enteredPin;
                    printf("Enter your PIN: ");
                    scanf("%d", &enteredPin);
                    if (enteredPin == currentAccount.pin) {
                        printf("Enter amount to deposit: ");
                        scanf("%lf", &amount);
                        deposit(&currentAccount, enteredPin, amount);
                    } else {
                        printf("Invalid PIN. Deposit failed.\n");
                    }
                }
                break;
            case 3:
                if (currentAccount.accountNumber == 0) {
                    printf("Please create an account first.\n");
                } else {
                    int enteredPin;
                    printf("Enter your PIN: ");
                    scanf("%d", &enteredPin);
                    if (enteredPin == currentAccount.pin) {
                        printf("Enter amount to withdraw: ");
                        scanf("%lf", &amount);
                        withdraw(&currentAccount, enteredPin, amount);
                    } else {
                        printf("Invalid PIN. Withdrawal failed.\n");
                    }
                }
                break;
            case 4:
                displayAccount(currentAccount);
                break;
            case 5:
                // Logout (reset currentAccount)
                currentAccount.accountNumber = 0;
                currentAccount.balance = 0.0;
                strcpy(currentAccount.name, "");
                strcpy(currentAccount.bankName, "");
                strcpy(currentAccount.branch, "");
                strcpy(currentAccount.address, "");
                currentAccount.pin = 0;
                printf("Logged out successfully!\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        getchar(); // Consume newline character
        printf("Press Enter to continue...");
        getchar(); // Wait for Enter key press
    }

    return 0;
}
