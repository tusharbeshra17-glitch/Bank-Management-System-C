#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

/* ================= ACCOUNT STRUCTURE ================= */

struct Account {
    int accNo;
    char name[50];
    int pin;
    float balance;
};

/* ================= GLOBAL VARIABLES ================= */

struct Account accounts[MAX_ACCOUNTS];
int totalAccounts = 0;

/* ================= CREATE ACCOUNT ================= */

void createAccount() {

    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("\nBank storage full!\n");
        return;
    }

    printf("\n=================================\n");
    printf("        CREATE ACCOUNT\n");
    printf("=================================\n");

    printf("Enter Account Number : ");
    scanf("%d", &accounts[totalAccounts].accNo);

    getchar();

    printf("Enter Name           : ");
    fgets(accounts[totalAccounts].name, 50, stdin);

    accounts[totalAccounts].name[
        strcspn(accounts[totalAccounts].name, "\n")
    ] = '\0';

    printf("Set 4-Digit PIN      : ");
    scanf("%d", &accounts[totalAccounts].pin);

    printf("Initial Deposit      : ");
    scanf("%f", &accounts[totalAccounts].balance);

    totalAccounts++;

    printf("\nAccount Created Successfully!\n");
}

/* ================= FIND ACCOUNT ================= */

int findAccount(int accNo) {

    for (int i = 0; i < totalAccounts; i++) {

        if (accounts[i].accNo == accNo) {
            return i;
        }
    }

    return -1;
}

/* ================= LOGIN SYSTEM ================= */

int login() {

    int accNo, pin;

    printf("\n=================================\n");
    printf("             LOGIN\n");
    printf("=================================\n");

    printf("Enter Account Number : ");
    scanf("%d", &accNo);

    printf("Enter PIN            : ");
    scanf("%d", &pin);

    int index = findAccount(accNo);

    if (index == -1) {
        printf("\nAccount not found!\n");
        return -1;
    }

    if (accounts[index].pin != pin) {
        printf("\nIncorrect PIN!\n");
        return -1;
    }

    printf("\nLogin Successful!\n");

    return index;
}

/* ================= CHECK BALANCE ================= */

void checkBalance() {

    int index = login();

    if (index == -1) {
        return;
    }

    printf("\nCurrent Balance : %.2f\n",
           accounts[index].balance);
}

/* ================= DEPOSIT MONEY ================= */

void depositMoney() {

    int index = login();

    if (index == -1) {
        return;
    }

    float amount;

    printf("Enter Deposit Amount : ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("\nInvalid Amount!\n");
        return;
    }

    accounts[index].balance += amount;

    printf("\nDeposit Successful!\n");

    printf("Updated Balance : %.2f\n",
           accounts[index].balance);
}

/* ================= WITHDRAW MONEY ================= */

void withdrawMoney() {

    int index = login();

    if (index == -1) {
        return;
    }

    float amount;

    printf("Enter Withdrawal Amount : ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("\nInvalid Amount!\n");
        return;
    }

    if (amount > accounts[index].balance) {
        printf("\nInsufficient Balance!\n");
        return;
    }

    accounts[index].balance -= amount;

    printf("\nWithdrawal Successful!\n");

    printf("Remaining Balance : %.2f\n",
           accounts[index].balance);
}

/* ================= VIEW ALL ACCOUNTS ================= */

void viewAccounts() {

    if (totalAccounts == 0) {
        printf("\nNo accounts found.\n");
        return;
    }

    printf("\n=================================\n");
    printf("          ALL ACCOUNTS\n");
    printf("=================================\n");

    for (int i = 0; i < totalAccounts; i++) {

        printf("\nAccount Number : %d\n",
               accounts[i].accNo);

        printf("Account Holder : %s\n",
               accounts[i].name);

        printf("Balance        : %.2f\n",
               accounts[i].balance);
    }
}

/* ================= MAIN FUNCTION ================= */

int main() {

    int choice;

    while (1) {

        printf("\n=================================\n");
        printf("       BANK MANAGEMENT SYSTEM\n");
        printf("=================================\n");

        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. View All Accounts\n");
        printf("6. Exit\n");

        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                createAccount();
                break;

            case 2:
                checkBalance();
                break;

            case 3:
                depositMoney();
                break;

            case 4:
                withdrawMoney();
                break;

            case 5:
                viewAccounts();
                break;

            case 6:
                printf("\nThank You For Using Our Bank!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}