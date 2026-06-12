#include <stdio.h>

struct Account
{
    int accNo;
    int pin;
    float balance;
};

int main()
{
    struct Account acc;

    int choice;
    float amount;

    printf("Create Account\n");

    printf("Account Number: ");
    scanf("%d", &acc.accNo);

    printf("Set PIN: ");
    scanf("%d", &acc.pin);

    printf("Initial Deposit: ");
    scanf("%f", &acc.balance);

    while (1)
    {
        printf("\n===== BANK MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Balance: %.2f\n", acc.balance);
        }

        else if (choice == 2)
        {
            printf("Enter Amount: ");
            scanf("%f", &amount);

            acc.balance = acc.balance + amount;

            printf("Deposit Successful\n");
        }

        else if (choice == 3)
        {
            printf("Enter Amount: ");
            scanf("%f", &amount);

            if (amount > acc.balance)
            {
                printf("Insufficient Balance\n");
            }
            else
            {
                acc.balance = acc.balance - amount;
                printf("Withdrawal Successful\n");
            }
        }

        else if (choice == 4)
        {
            printf("Thank You!\n");
            break;
        }

        else
        {
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
