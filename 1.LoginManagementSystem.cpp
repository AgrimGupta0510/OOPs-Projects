#include<bits/stdc++.h>
using namespace std;

class User{
    private:
        string username,password;
    public:
        User(string name, string pass){
            username=name;
            password=pass;
        }
        string getUsername(){
            return username;
        }
        string getPassword(){
            return password;
        }

};

class UserManager{
    private:
        vector<User> users;
    public:
        void RegisterUser(){
            string username,password;
            cout<<"\t\tEnter User Name :";
            cin>>username;
            cout<<"\t\tEnter Password :";
            cin>>password;

            User newUser(username,password);
            users.push_back(newUser);

            cout<<"\t\t User Registered Successfully......."<<endl;
        }       
        
        bool LoginUser(string name, string pass){
            for(int i=0;i<users.size();i++){
                if(users[i].getUsername()==name && users[i].getPassword()==pass){
                    cout<<"\t\t Login Successfully....."<<endl;
                    return true;
                }
            }
            cout<<"\t\t Invalid User Name or Password..."<<endl;
            return false;
        }

        void ShowUser(){
            cout<<"\t\t ---Users List---"<<endl;
            for(int i=0;i<users.size();i++){
                cout<<"\t\t"<<users[i].getUsername()<<endl;
            }
        }

        void SearchUser(string name){
            for(int i=0;i<users.size();i++){
                if(users[i].getUsername()==name){
                    cout<<"\t\t User Found....."<<endl;
                }
            }
        }

        void DeleteUser(string name){
            for(int i=0;i<users.size();i++){
                if(users[i].getUsername()==name){
                    users.erase(users.begin()+i);
                    cout<<"\t\t User Removed Successfully..."<<endl;
                }
            }
        }

};

int main(){

    UserManager usermanage;
    int op;
    char choice;
    do{        
        system("cls");
        cout<<"\n\n\t\t 1. Register User"<<endl;
        cout<<"\t\t 2. Login"<<endl;
        cout<<"\t\t 3. Show User List"<<endl;
        cout<<"\t\t 4. Search User"<<endl;
        cout<<"\t\t 5. Delete User"<<endl;
        cout<<"\t\t 6. Exit"<<endl;
        cout<<"\t\t Enter Your Choice"<<endl;
        cout<<endl;

        cin>>op;

        switch(op){
            case 1:{
                usermanage.RegisterUser();
                break;
            }
            case 2:{
                string username,password;
                cout<<"\t\t Enter Username: ";
                cin>>username;
                cout<<"\t\t Enter Password: ";
                cin>>password;
                usermanage.LoginUser(username,password);
                break;
            }
            case 3:{
                usermanage.ShowUser();
                break;
            }
            case 4:{
                string username;
                cout<<"\t\t Enter Username you want to search: ";
                cin>>username;                
                usermanage.SearchUser(username);
                break;
            }
            case 5:{
                string username;
                cout<<"\t\t Enter Username: ";
                cin>>username;
                usermanage.DeleteUser(username);
                break;
            }
            case 6:{
                exit(1);
                break;
            }

        }
        cout<<"\t\t Do You Want to Continue [Y/N] ? :";
        cin>>choice;

    }while(choice=='y' || choice=='Y');    

    return 0;
}




