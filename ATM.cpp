#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <string>
#include <string.h>
#include <sstream>


#define MAX 5

using namespace std;

typedef struct enroll{
    char fname[20];
    char mname[20];
    char lname[20];
    char pin[6];
    char accountno[69];
    float balance;


} REGISTER;
REGISTER reg[20];

float intbalance = 3000;
int last;


void register_acc();
void makenull();
int isempty();
void success();
char* pincode();
void pins();
int verify(char *pin, char *vpin);
void anyKey();
void initialBalance();
void verifyAcc();
void title();
char* generatePin();
void displaySuccess();
char* generateCardNo();



void makenull(){

last = -1;


}

int main(){

    makenull();
    register_acc();
}


void register_acc(){
    system("cls");
    char fname[20], mname[20], lname[20];
    char choice;

    title();

    last++;
    cout << "\t\t\t\t\t"<<"Enter First Name: ";
    cin >> fname;
    strcpy(reg[last].fname, fname);
    cout << "\t\t\t\t\t" << "Enter Middle Name: ";
    cin >> mname;
    strcpy(reg[last].mname, mname);
    cout << "\t\t\t\t\t" << "Enter Last Name: ";
    cin >> lname;
    strcpy(reg[last].lname, lname);
    initialBalance();






}

void success(){
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

cout<<"\t\t\t\t\t\t  ___ _   _  ___ ___ ___  ___ ___ "<<endl;
cout<<"\t\t\t\t\t\t / __| | | |/ __/ __/ _ \/ __/ __|"<<endl;
cout<<"\t\t\t\t\t\t \\__ \\ |_| | (_| (_|  __/\\__ \\__ \\"<<endl;
cout<<"\t\t\t\t\t\t |___/\\__,_|\\___\\___\\___||___/___/"<<endl;
}

int verify(char *pin, char *vpin){

    return strcmpi(pin, vpin) == 0 ;

}

void anyKey(){

    cout << endl << endl << "\t\t\t\tPress any key to continue" << endl;
    getch();

}

void initialBalance(){

    int balance;
    char choice;
    string pin;
    string cardno;

    cout << endl << "\t\t\t\t\t" << "Minimum Balance of: " << intbalance;
    cout << endl << "\t\t\t\t\t" << "Enter Initial Balance: ";
    cin >> balance;

    while (balance < intbalance){

        cout << endl << "Insafficient Initial Balance!" << endl;
        cout << endl << "Re-enter Initial Balance: ";
        cin >> balance;

    }

        reg[last].balance = balance;
        cardno = generateCardNo();
        pin = generatePin();
        strcpy(reg[last].accountno, cardno.c_str());
        strcpy(reg[last].pin,pin.c_str());
        cout << endl << endl << "Press [Enter] key to Confirm" << endl << "Press [Any] key to Cancel";
        choice = getch();

    if (choice == 13){
        cout << endl << cardno; getch();
        cout << endl << reg[last].accountno; getch();

        cout << endl << reg[last].pin ; getch();
        cout << endl << pin; getch();
        cout << endl << reg[last].accountno; getch();
        displaySuccess();

    }
    else {
        last--;
        register_acc();
    }
}

void title(){

    cout << "\t\t\t\t\t" << "==========ATM SIMULATOR 2019==========" << endl << endl;
    cout << "\t\t\t\t\t" << "    ==========REGISTER==========" << endl << endl << endl;


}

char* generatePin(){

    char *pin = new char[6];
    srand(time(NULL));
    int value = rand() % 899999 + 100000;
    itoa(value, pin, 10);
    pin[6] = '\0';
    return pin;

}
void displaySuccess(){

    char choice;
    system("cls");
    success();
    cout << endl << endl << endl << "\t\t\t\t\t" << "First name:: " << reg[last].fname;
    cout << endl << "\t\t\t\t\t" << "Middle name: " << reg[last].mname;
    cout << endl << "\t\t\t\t\t" << "Last name: " << reg[last].lname;
    cout << endl << "\t\t\t\t\t" << "Balance: " << reg[last].balance;
    cout << endl << "\t\t\t\t\t" << "Account No./Card No.: " << reg[last].accountno;
    cout << endl << "\t\t\t\t\t" << "-------------------------------------------------------------------------";
    cout << endl << "\t\t\t\t\t" << "Initial Pin: " << reg[last].pin << endl;
    anyKey();
}

char* generateCardNo(){

char* toReturn = new char[20];
string genAcc = "TITE-";
ostringstream os;
for (int i = 0; i < 12; ++i){
int digit = rand() % 10;
os << digit;
}

string result = genAcc + os.str();
strcpy(toReturn, result.c_str());
return toReturn;

}


