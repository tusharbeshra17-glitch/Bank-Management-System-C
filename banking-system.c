#include <stdio.h>
  struct Account acc;
    int choice;
    float amount;

struct Account{
    int accNo;
    int pin;
    float balance;
};
void menu (){
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
        }


int main(){
  
   printf("\n====================================\n");
    printf("         WELCOME TO MY BANK         \n");
    printf("====================================\n");

    printf("Do you have an account?\n");
    printf("1. Yes, I have an account\n");
    printf("2. No, I want to create one\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

     if(choice==1){
     menu();
     }
        if(choice==2 ){
 
        printf("\n====================================\n");
        printf("          CREATE NEW ACCOUNT         \n");
        printf("====================================\n");

        printf("Enter Account Number : ");
        scanf("%d", &acc.accNo);

        printf("Set PIN              : ");
        scanf("%d", &acc.pin);
 
        printf("Initial Deposit      : ");
        scanf("%f", &acc.balance);

        printf("====================================\n");
        printf("   Account Created Successfully!    \n");
        printf("====================================\n");
        
        menu();
    }
   
         return 0;
    }
