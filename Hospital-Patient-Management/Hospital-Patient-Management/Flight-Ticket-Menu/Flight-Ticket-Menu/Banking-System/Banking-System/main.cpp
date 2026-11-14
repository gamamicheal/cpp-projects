#include <iostream>

using namespace std;

int main(){
    int choice, withdrawChoice, depositChoice;
    double BalanceAmount = 1000.00; // Initial balance
    double withdrawAmount, depositAmount;
    cout << "====BANKING SYSTEM MENU====" << endl;
    do{
      cout << "Welcome Gama!!!" << endl;
      cout << "1. Check balance" << endl;
      cout << "2. Withdraw money" << endl;
      cout << "3. Deposit money" << endl;
      cout << "4. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;
      while(choice < 1 || choice > 4){
        cout << "Invalid choice! Enter a valid choice (1 - 4): ";   
        cin >> choice;
    }
    switch(choice){
        case 1:
            cout << "Your balance is: K " << BalanceAmount << endl;
            break;
        case 2:
            do{
                cout << "=====WITHDRAWAL MENU===== " << endl;
                cout << "1. Withdraw k50" << endl;
                cout << "2. Withdraw k100" << endl;
                cout << "3. Withdraw k200" << endl;
                cout << "4.Enter custom amount" << endl;
                cout << "5. Back to main menu" << endl;
                cout << "Enter your choice: ";
                cin >> withdrawChoice;
                if(withdrawChoice < 1 || withdrawChoice > 5){
                    cout << "Invalid choice! Try again " << endl;
                    continue;
                }
                switch(withdrawChoice){
                case 1:
                    withdrawAmount = 50;
                    break;
                case 2:
                    withdrawAmount = 100;
                    break;
                case 3:
                    withdrawAmount = 200;
                    break;
                case 4:
                    cout << "Enter amount: K";
                    cin >> withdrawAmount;
                    break;
                case 5:
                    continue;
                }
                if(withdrawChoice != 5){
                    if(withdrawAmount <= 0){
                        cout << "Invalid withdrawal amount" << endl;
                    }else if(withdrawAmount > BalanceAmount){
                        cout << "Insufficient balance" << endl;
                    }else {
                        BalanceAmount -= withdrawAmount;
                        cout << "Withdrawal successfully" << endl;
                        cout << "New balance: K" << BalanceAmount << endl;
                    }
                }
            }while(withdrawChoice != 5);

            break;

        

        case 3:
            do{
                cout << "=====DEPOSIT MENU=====" << endl;
                cout << "1. Deposit k50" << endl;
                cout << "2. Deposit k100" << endl;
                cout << "3. Deposit k200" << endl;
                cout << "4. Enter custom amount" << endl;
                cout << "5. Back to main menu" << endl;
                cout << "Enter your choice: " << endl;
                cin >> depositChoice;
                if(depositChoice < 1|| depositChoice > 5){
                    cout << "Invalid choice! Try again" << endl;
                    continue;
                }
                switch(depositChoice){
                case 1:
                    depositAmount = 50;
                    break;
                case 2:
                    depositAmount = 100;
                    break;
                case 3:
                    depositAmount = 200;
                    break;
                case 4:
                    cout << "Enter amount: K" << endl;
                    cin >> depositAmount;
                    break;
                case 5:
                    continue;
                }
                if(depositChoice != 5){
                    if(depositAmount <= 0){
                        cout << "Invalid deposit amount!" << endl;
                    }else{
                        BalanceAmount += depositAmount;
                        cout << "Deposit successful" << endl;
                        cout << "New balance: K" << BalanceAmount << endl;
                    }
                }

            }
            while(depositChoice !=5);
                break;

        case 4:
            cout << "Thank you for using our banking system" << endl;
            break;
        }

    }while(choice != 4);
    return 0;
}
