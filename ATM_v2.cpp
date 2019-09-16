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

float intbalance = 3000;
int last;



void accRegister();
void makenull();
void title();
char* generatePin();
char* generateCardNo();
void inputStruct(char fname[30], char mname[30], char lname[30], char pin[10], char accNo[20], float balance);
void success();
void anyKey();
void displaySuccess();
void saveToTextfile();
void loadTextfile();
void saveAccNo();
char getRemovableDisk();
char * encryptPin(char pin[]);
char * decryptPin(char pin[]);

void title(){


cout << endl << endl << endl << endl;
cout << "\t\t\t\t\t" << " ________    ______  ______        _       ____  _____  ___  ____ " << endl;
cout << "\t\t\t\t\t" << "|_   __  | .' ___  ||_   _ \\      / \\     |_   \\|_   _||_  ||_  _|" << endl;
cout << "\t\t\t\t\t" << "  | |_ \\_|/ .'   \\_|  | |_) |    / _ \\      |   \\ | |    | |_/ /  " << endl;
cout << "\t\t\t\t\t" << "  |  _| _ | |         |  __'.   / ___ \\     | |\\ \\| |    |  __'.  " << endl;
cout << "\t\t\t\t\t" << " _| |__/ |\\ `.___.'\\ _| |__) |_/ /   \\ \\_  _| |_\\   |_  _| |  \\ \\_" << endl;
cout << "\t\t\t\t\t" << "|________| `.____ .'|_______/|____| |____||_____|\\____||____||____|" << endl;

}
void makenull(){

    last = -1;

}

int main(){
    makenull();
    loadTextfile();
    accRegister();

}

char * encryptPin(char pin[]){
    int i;
    for(i = 0; i <= 5 ; i++){
        pin[i] += 36;
    }
    return pin;
}

void accRegister(){

    char fname[20], mname[20], lname[20], choice;
    char* pin = new char[6];
    char* accNo = new char[20];
    int balance;

    system("cls");
    title();
    cout << endl << endl << endl << endl << endl;
    cout << "\t\t\t\t\t" << "==========|REGISTRATION|==========" << endl << endl;
    cout << "\t\t\t\t\t" << "Enter First Name: ";
    cin >> fname;
    cout << "\t\t\t\t\t" << "Enter Middle Name: ";
    cin >> mname;
    cout << "\t\t\t\t\t" << "Enter Last Name: ";
    cin >> lname;

    cout << endl << "\t\t\t\t\t" << "Minimum Initial Balance: " << intbalance;
    cout << endl << "\t\t\t\t\t" << "Enter Initial Balance: ";
    cin >> balance;

    while (balance < intbalance){

        cout << "\t\t\t\t\t" << "Inssuficient Initial Balance!"; getch();
        cout << endl << "\t\t\t\t\t" << "Re-Enter Initial Balance: ";
        cin >> balance;

    }

    cout << endl << "\t\t\t\t\t" << "Press [Enter] key To PROCEED" << endl << "\t\t\t\t\t" << "Press [Any] key to Cancel";
    choice = getch();

    if (choice == 13){
    char drive;
    drive = getRemovableDisk();

    while (drive == '0'){
            drive = getRemovableDisk();
            system("cls");
        Sleep(1000);
        cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t===============|PLEASE INSERT CARD|=============";
        Sleep(500);
    }
        pin = generatePin();
        accNo = generateCardNo();
        inputStruct(fname, mname, lname, pin, accNo, balance);

    }
    else {
        accRegister();
    }


}

char* generateCardNo(){

char* toReturn = new char[20];
string genAcc = "EACB";
ostringstream os;
for (int i = 0; i < 12; ++i){
int digit = rand() % 10;
os << digit;
}

string result = genAcc + os.str();
strcpy(toReturn, result.c_str());
return toReturn;

}

char* generatePin(){

    char *pin = new char[6];
    srand(time(NULL));
    int value = rand() % 899999 + 100000;
    itoa(value, pin, 10);
    pin[6] = '\0';
    return pin;

}

void inputStruct(char fname[30], char mname[30], char lname[30], char pin[10], char accNo[20], float balance){

    last++;
    strcpy(reg[last].fname, fname);
    strcpy(reg[last].mname, mname);
    strcpy(reg[last].lname, lname);
    reg[last].balance = balance;
    strcpy(reg[last].accNum, accNo);
    strcpy(reg[last].pin, pin);

    displaySuccess();
}

void success(){
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

cout<<"\t\t\t\t\t\t  ___ _   _  ___ ___ ___  ___ ___ "<<endl;
cout<<"\t\t\t\t\t\t / __| | | |/ __/ __/ _ \/ __/ __|"<<endl;
cout<<"\t\t\t\t\t\t \\__ \\ |_| | (_| (_|  __/\\__ \\__ \\"<<endl;
cout<<"\t\t\t\t\t\t |___/\\__,_|\\___\\___\\___||___/___/"<<endl;
}

void displaySuccess(){
    system("cls");
    success();
    cout << endl << endl << endl << "\t\t\t\t\t" << "First name: " << reg[last].fname;
    cout << endl << "\t\t\t\t\t" << "Middle name: " << reg[last].mname;
    cout << endl << "\t\t\t\t\t" << "Last name: " << reg[last].lname;
    cout << endl << "\t\t\t\t\t" << "Balance: " << reg[last].balance;
    cout << endl << "\t\t\t\t\t" << "Account No./Card No.: " << reg[last].accNum;
    cout << endl << "\t\t\t\t\t" << "-------------------------------------------------------------------------";
    cout << endl << "\t\t\t\t\t" << "Initial Pin: " << reg[last].pin << endl;
    saveToTextfile();
    anyKey();
    saveAccNo();
    accRegister();
}

void anyKey(){

    cout << endl << endl << "\t\t\t\tPress any key to continue" << endl;
    getch();

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

void saveAccNo(){

    char drive;
    string paths = ":\\";
    char *path = new char[20];

    drive = getRemovableDisk();

    paths.append("EACB");
    paths.insert(0, 1, drive);
    paths.append(".txt");

    strcpy(path, paths.c_str());
    ofstream file(path);

    if(file.is_open()){

        file << reg[last].accNum;

        file.close();
    }





}

char getRemovableDisk(){
    char drive='0';
    int i;
    char szLogicalDrives[MAX_PATH];
    DWORD dwResult = GetLogicalDriveStrings(MAX_PATH, szLogicalDrives);

    string currentDrives="";

    //cout << dwResult << endl;
    for(i=0; i<dwResult; i++)
    {
        if(szLogicalDrives[i]>64 && szLogicalDrives[i] < 90)
        {
          if(GetDriveType(&szLogicalDrives[i]) == DRIVE_REMOVABLE){
                drive = szLogicalDrives[i];
            }
        }
    }
    return drive;
}
