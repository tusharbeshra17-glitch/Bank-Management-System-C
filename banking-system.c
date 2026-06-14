#include <stdio.h>

struct Account{
    int accNo;
    int pin;
    float balance;
};

int main(){
    struct Account acc;
    int choice;
    float amount;

    // ======Account Creation======
    printf("Create Account\n");

    printf("Account Number: ");
    scanf("%d", &acc.accNo);

    printf("Set PIN: ");
    scanf("%d", &acc.pin);

    printf("Initial Deposit: ");
    scanf("%f", &acc.balance);

    // ======Login Variables======
    int enteredPin;
    int isLoggedIn = 0;   // flag to check login status whether log in or not

    while (1){
        printf("\n===== BANK MENU =====\n");
        printf("1. Login\n");          // menu
        printf("2. Check Balance\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        // LOGIN 
        if (choice == 1){
            printf("Enter PIN: ");
            scanf("%d", &enteredPin);

            if (enteredPin == acc.pin){
                printf("Login Successful!\n");
                isLoggedIn = 1;   // mark as logged in
            }
            else{
                printf("Incorrect PIN!\n");
            }
        }

        // CHECK BALANCE
        else if (choice == 2){
            if (isLoggedIn == 0){
                printf("Please login first!\n");
                continue;
            }
            printf("Balance: %.2f\n", acc.balance);
        }

        else if (choice == 3){
            if (isLoggedIn == 0){
                printf("Please login first!\n");  //DEPOSIT 
                continue;
            }

            printf("Enter Amount: ");
            scanf("%f", &amount);

            if (amount <= 0){
                printf("Invalid Amount\n");
            }
            else{
                 acc.balance += amount;
                 printf("Deposit Successful\n");
            }
        }

        
        else if (choice == 4){
            if (isLoggedIn == 0){
                printf("Please login first!\n");   // WITHDRAW 
                continue;
            }

            printf("Enter Amount: ");
            scanf("%f", &amount);

            if (amount <= 0){
                printf("Invalid Amount\n");
            }
            else if (amount > acc.balance){
                printf("Insufficient Balance\n");
            }
            else{
                acc.balance = acc.balance - amount;
                printf("Withdrawal Successful\n");
            }
        }

        
        else if (choice == 5){
            printf("Thank You!\n");  // exit
            break;
        }

        else{
            printf("Invalid Choice\n");  // invalide entry
        }
    }

    return 0;
}