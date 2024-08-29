#include<bits/stdc++.h>
using namespace std;

class ATM{
    private:
        int balance;
        int pinCode;
        int success;

    public:
        ATM(int bal, int pin){
            this->balance=bal;
            this->pinCode=pin;
        }
        int getBalance(){
            return this->balance;
        }
        int getPincode(){
            return this->pinCode;
        }
        int withdraw(int amount,int pin){
            if(pin!=pinCode){
                return false;
            }
            if(amount>this->balance){
                return false;
            }
            this->balance-=amount;
            return true;
        }

        void deposit(int amount){
            this->balance+=amount;
        }

        int transfer(int amount, ATM &reciever, int pin){
            if(pin!=pinCode){
                return false;
            }
            this->success=withdraw(amount, pin);
            if(success){
                reciever.deposit(amount);
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
    ATM atm(1000,1234);
    ATM atm2(1000,5678);

    int choice;
    int success;
    int amount;
    int pin;
    char op;

    do{
        system("cls");
        cout<<"\t\t 1.View Balance"<<endl;
        cout<<"\t\t 2.Cash Withdraw"<<endl;
        cout<<"\t\t 3.Cash Deposit"<<endl;
        cout<<"\t\t 4.Cash Tranfer"<<endl;
        cout<<"\t\t 5.Exit"<<endl;
        cout<<"Enter Your Choice: "<<endl;
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"Your Balance is: "<<atm.getBalance()<<endl;
                break;
            }
            case 2:{
                cout<<"Your Available Balance is: "<<atm.getBalance()<<endl;
                cout<<"Enter the amount to withdraw :";
                cin>>amount;
                int success=atm.withdraw(amount,atm.getPincode());
                if(success){
                    cout<<"Withdraw Successfull..."<<endl;
                    cout<<"Now Your Balance is : "<<atm.getBalance()<<endl;
                }
                else{
                    cout<<"Insufficient Balance..."<<endl;
                }
                break;
            }
            case 3:{
                cout<<"Enter the amount to deposit :";
                cin>>amount;
                atm.deposit(amount);
                cout<<"Deposit Successfull..."<<endl;
                cout<<"Now Your Balance is : "<<atm.getBalance()<<endl;
                break;
            }
            case 4:{
                cout<<"Enter the amounnt to tranfer: ";
                cin>>amount;
                cout<<"Enter Pin Code: ";
                cin>>pin;
                success=atm.transfer(amount ,atm2 , pin);
                if(success){
                    cout<<"Tranfer successfull...";
                    cout<<"Now Your Balance is : "<<atm.getBalance()<<endl;
                    cout<<"Reciever's Balance is : "<<atm2.getBalance()<<endl;
                }
                else{
                    cout<<"Invalid pin or Insufficient Balance"<<endl;
                }
                break;
            }

            case 5:{
                cout<<"Thanks for using ATM"<<endl;
                exit(1);
                break;
            }
            default:{
                cout<<"Invalid Choice"<<endl;
            }
        }

        cout<<"Do You want to continue or not [Y/N] ? : ";
        cin>>op;
    }while(op=='y' || op=='Y'); 

    return 0;
}