#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>


#define MAX 5

using namespace std;

typedef struct accountRegister{
    char fname[10], mname[10], lname[10];
    float balance;
    char accNum[20], pin[10];


} REGISTER;
REGISTER reg[20];

char getRemovableDisk();
void saveToTextfile();
void loadTextfile();
char * getAccountNum();
void login();
void title();
void menu();
int loadAcc();
char *loadAccNo();
void withdraw();

float intbalance = 3000;
int last;


char getRemovableDisk(){
    char drive='0';
    int i;
    char szLogicalDrives[MAX_PATH];
    DWORD dwResult = GetLogicalDriveStrings(MAX_PATH, szLogicalDrives);

    string currentDrives="";

    for(i=0; i<dwResult; i++)
    {
        if(szLogicalDrives[i] > 64 && szLogicalDrives[i] < 90)
        {
          if(GetDriveType(&szLogicalDrives[i]) == DRIVE_REMOVABLE){
                drive =  szLogicalDrives[i];
            }
        }
    }

    Sleep(1000);
    return drive;
}

void loadTextfile(){

    ifstream file("Acc.txt");

    if(file.is_open()){

        file >> last;
        for(int i = 0; i <= last; i++){

            file >> reg[i].fname;
            file >> reg[i].mname;
            file >> reg[i].lname;
            file >> reg[i].balance;
            file >> reg[i].accNum;
            file >> reg[i].pin;
        }

        file.close();
    }

}

void saveToTextfile(){

    ofstream file("Acc.txt");

    if(file.is_open()){

        file << last << endl;
        for(int i = 0; i <= last; i++){

            file << reg[i].fname <<" "<< reg[i].mname <<" "<< reg[i].lname <<" "<<reg[i].accNum <<" "<< reg[i].pin << endl;

        }

        file.close();
    }
}

int main(){

    char drive;

    loadTextfile();

    drive = getRemovableDisk();

    while (drive == '0'){
            drive = getRemovableDisk();
            system("cls");
            Sleep(500);
            cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t===============|PLEASE INSERT CARD|=============";
            Sleep(200);
    }
    menu();

}

void title(){


cout << endl << endl;
cout << "\t\t\t\t\t" << " ________    ______  ______        _       ____  _____  ___  ____ " << endl;
cout << "\t\t\t\t\t" << "|_   __  | .' ___  ||_   _ \\      / \\     |_   \\|_   _||_  ||_  _|" << endl;
cout << "\t\t\t\t\t" << "  | |_ \\_|/ .'   \\_|  | |_) |    / _ \\      |   \\ | |    | |_/ /  " << endl;
cout << "\t\t\t\t\t" << "  |  _| _ | |         |  __'.   / ___ \\     | |\\ \\| |    |  __'.  " << endl;
cout << "\t\t\t\t\t" << " _| |__/ |\\ `.___.'\\ _| |__) |_/ /   \\ \\_  _| |_\\   |_  _| |  \\ \\_" << endl;
cout << "\t\t\t\t\t" << "|________| `.____ .'|_______/|____| |____||_____|\\____||____||____|" << endl;

}

void menu(){

    int choice;
    system("cls");
    title();

    cout << "\n\n\n" << "\t\t\t\t\t" << "[1] Withdraw" << "\t\t\t\t\t" << "[2] Deposit" << endl << endl << endl;
    cout << "\n\n\n" << "\t\t\t\t\t" << "[3] View Balance" << "\t\t\t\t" << "[4] Fund Transfer" << endl << endl << endl;
    cout << "\n\n\n" << "\t\t\t\t\t" << "[5] Change Pin" << "\t\t\t\t\t" << "[6] Exit" << endl << endl << endl;

    choice = getch();
    switch (choice){

case 49:
    withdraw();
    break;
case 50:

default:
    break;

    }




}


char * getAccountNum(){

    char drive;
    char *accNo;
    ifstream file;
    string paths = ":\\";
    char *path = new char[20];

    drive = getRemovableDisk();

    paths.append("EACB");
    paths.insert(0, 1, drive);
    paths.append(".txt");

    strcpy(path, paths.c_str());
    file.open(path);

    if(file.is_open()){
        file>>accNo;
    }
    cout<<accNo;
    file.close();

    return accNo;
}

void login(){
    char *accNo, *pin;

    strcpy(accNo, getAccountNum());

    cout<<"Enter your pin: ";





}

char *loadAccNo(){

    char drive;
    char *accNum = new char[20];
    string paths = ":\\";
    char *path = new char[20];

    drive = getRemovableDisk();

    paths.append("EACB");
    paths.insert(0, 1, drive);
    paths.append(".txt");

    strcpy(path, paths.c_str());
    ifstream file(path);

    if(file.is_open()){

        file >> accNum;

        file.close();
    }

    return accNum;
}

int loadAcc(){

    char *accNo = new char[20];
    accNo = loadAccNo();

    for (int i = 0; i <= last; i++){

        if(strcmpi(accNo, reg[last].accNum) == 0){
            return i;
        }
    }
    return 0;
}

void withdraw(){

  int balance;
  int index = loadAcc();

  system("cls");
  title();
  cout << index; getch();
  cout << "\n\n\n" << "\t\t\t\t\t" << "Enter Amount You want to withdraw: ";
  cin >> balance;
  cout << reg[last].balance; getch();
  cout << reg[index].balance; getch();
  while(balance > reg[index].balance){
    cout << "\n\n" << "\t\t\t\t\t" << "The amount you want to withdraw is below your current balance!" << endl;
    cout << "\n\n" << "\t\t\t\t\t" << "Re-Enter Amount: ";
    cin >> balance;

  }
  cout << endl << endl << endl << "\t\t\t\t\t" << "Please Wait";
  for (int i = 0; i <= 3; i++){
    cout << ".";
  }
}
