/*Create a Structure called BankMgmt with AccNumber, CustName, AvlBalance,
AccType as members. Implement a Bank management Application as menu driven
program for the above said Structure scenario.
Menu Option:

1. Withdrawal 2. Deposit 3. Display Balance 4. Exit
If option

1 is chosen- Amount can be withdrawn from the account (Withdrawn amount
should be given as input). For withdrawal the condition is- the AvlBalance must be
greater than withdrawn amount).

2 is chosen- Amount can be deposited to the account (the deposited amount
should be given as input). The deposited amount should be reflected in AvlBalance of
the account.

3 is chosen- Current available balance (AvlBalance) of the AccNumber should
be Displayed with other details

4 is chosen- Exit from the application*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int AccNumber;
    char CustName[100];
    float AvlBalance;
    char AccType[100];
} bankmanagement;

void displayDetails(bankmanagement account) {
    printf("Account Number: %d\n", account.AccNumber);
    printf("Customer Name: %s\n", account.CustName);
    printf("Available Balance: %.3f\n", account.AvlBalance);
    printf("Account Type: %s\n", account.AccType);
}

void withdrawAmount(bankmanagement *account) {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);

    if (account->AvlBalance >= amount) {
        account->AvlBalance -= amount;
        printf("Remaining balance : %.3f\n", account->AvlBalance);
    } else {
        printf("Insufficient balance.\n");
    }
}

void depositAmount(bankmanagement *account) {
    float amount;
    printf("Enter the amount to deposit : ");
    scanf("%f", &amount);

    account->AvlBalance += amount;
    printf("Remaining balance: %.3f\n", account->AvlBalance);
}

int main() {
    bankmanagement account;
    int choice;

    printf("Enter the account number: ");
    scanf("%d", &account.AccNumber);
    printf("Enter the customer name: ");
    scanf("%s", account.CustName);
    printf("Enter the available balance: ");
    scanf("%f", &account.AvlBalance);
    printf("Enter the account type: ");
    scanf("%s", account.AccType);

    do {

        printf("\nBank Management Application\n");
        printf("1. Withdrawal\n");
        printf("2. Deposit\n");
        printf("3. Display Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                withdrawAmount(&account);
                break;
            case 2:
                depositAmount(&account);
                break;
            case 3:
                displayDetails(account);
                break;
            case 4:
                printf("Exiting the application.\n");
                break;
            default:
                printf("Invalid option :\n");
        }
    } while (choice != 4);

   return 0;

}
