//TravelAbhi.cpp
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------

void pattern_line(int n){
	for (int i=0; i<n; i++){
		cout<<"__";
	}
	cout<<endl;
}

void pattern_spaces(int n){
	for (int i=0; i<n; i++){
		cout<<"\t";
	}
}

void header(int n){
	system("cls");
	system("color A1");
	cout<<"\n\n";
	pattern_spaces (4); pattern_line (60);
	pattern_spaces (4); pattern_line (60);
	pattern_spaces (10); cout<<"WELCOME TO TRAVEL AGENCY"<<endl;
	pattern_spaces (10); cout<<"   BLACK PERAL TRAVEL "<<endl;
	pattern_spaces (4); cout<<"The life doesn't always give you a second chance, so make the most out of it, with us at the Black Pearl Travel Agency:"<<endl;
	pattern_spaces (4); pattern_line (60);
	pattern_spaces (4); pattern_line (60);
	if(n == 1){
		pattern_spaces (4); cout<<"CONTACT US:-7720813772"; pattern_spaces (9); cout<<"EMAIL:-blac.peral@hotmail.com"<<endl;
		pattern_spaces (8); cout<<"OFFICE ADD.:- G.H RAISONI COLLEGE OF ENGINEERING E-104"<<endl;
		pattern_spaces (4); pattern_line (60);
		pattern_spaces (8); cout<<"    HURRY UP SPECIAL OFFERS ARE COMING TO AN END"<<endl;
		pattern_spaces (8); cout<<"    HURRY UP SPECIAL OFFERS ARE COMING TO AN END"<<endl<<endl;
	}
}

int check(char a[8],char b[5]){
	int i;
    for(i=0;i<8;i++){
        if(a[i]!=b[i]){
        break;
        }
    }
    if(i==8)
    	return 1;
    else
    	return 0;
}

void AccessGrant(){
    char pwd[8], def[]="Abhishek";
	int i=0, mycheck;
	pattern_spaces (4); cout<<"PLEASE ENTER PASSWORD : ";
	while(i<8){
		pwd[i]=getch();
		cout<<"*";
		++i;
	}
	cout<<endl;
	mycheck=check(pwd,def);
	if(mycheck == 1){
		pattern_spaces (4); cout<<"CORRECT PASSWORD"<<endl;
		pattern_spaces (4); pattern_line (60);
	}
	else{
		pattern_spaces (4); cout<<"WRONG PASSWORD!";
		exit(0);
	}
}

void printStrongNess(string& input){
    int n = input.length();
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
    string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

    for (int i = 0; i < n; i++) {
        if (islower(input[i]))
            hasLower = true;
        if (isupper(input[i]))
            hasUpper = true;
        if (isdigit(input[i]))
            hasDigit = true;

        size_t special = input.find_first_not_of(normalChars);
        if (special != string::npos)
            specialChar = true;
    }
    // Strength of password
    cout <<"Strength of password:-";
    if (hasLower && hasUpper && hasDigit &&
        specialChar && (n >= 8))
        cout << "Strong" << endl;
    else if ((hasLower || hasUpper) &&
             specialChar && (n >= 6))
        cout << "Moderate" << endl;
    else
        cout << "Weak" << endl;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------

class travel_agency{
public:
	char username[40], name[40], reservation[30], hotels[30], bankaccountDetails[50], city[30], state[30], country [30], places[30], phone[10];
	string Password, email, city_code;
	int choice, rating;
	float Fare_Charges;

   virtual void accept() = 0;
   virtual void display() = 0;
};

class admin : public travel_agency{
public:
   void accept(){
   	pattern_spaces (4); pattern_line (60);
	pattern_spaces (4); pattern_line (60);
	pattern_spaces (11); cout<<"WELCOME ADMIN"<<endl;
	pattern_spaces (4); cout<<"ENTER USERNAME : "; cin>>username; cout<<endl;
	pattern_spaces (4); cout<<"ENTER NAME : "; cin>>name; cout<<endl;
	AccessGrant();
   }
   void display(){
   	header(2);
   	pattern_spaces (4); cout<<"1. MODIFY PACKAGES"<<endl; pattern_spaces (4); cout<<"2. MODIFY DESTINATIONS"<<endl;
   	pattern_spaces (4); cout<<"3. VIEW CUSTOMER RECORDS"<<endl; pattern_spaces (4); cout<<"4. EXIT"; cin>>choice;
   	switch (choice){
   		case 1:
   			break;
   		case 2:
   			break;
   		case 3:
   			break;
   		case 4:
   			exit(0);
   	}
   }
};

class customer : public travel_agency{
public:
   void accept(){
  	pattern_spaces (4); pattern_line (60);
	pattern_spaces (4); pattern_line (60);
	pattern_spaces (11); cout<<"WELCOME CUSTOMER"<<endl;
	pattern_spaces (4); cout<<"ENTER USERNAME : "; cin>>username; cout<<endl;
	pattern_spaces (4); cout<<"ENTER NAME : "; cin>>name; cout<<endl;
	pattern_spaces (4); cout<<"ENTER EMAIL ID : "; cin>>email; cout<<endl;
	pattern_spaces (4); cout<<"ENTER PHONE NUMBER : "; cin>>phone; cout<<endl;
   }
   void display(){
   	header(2);
   	pattern_spaces (4); cout<<"1. NATIONAL DESTINATION TOURISM"<<endl; pattern_spaces (4); cout<<"2. INTERNATIONAL DESTINATIONS TOURISM"<<endl;
   	pattern_spaces (4); cout<<"3. OR SELECT OUR WORLD CLASS PACKAGES JUST FOR YOU"<<endl; pattern_spaces (4); cout<<"4. EXIT"; cin>>choice;
   	switch (choice){
   		case 1:
   			break;
   		case 2:
   			break;
   		case 3:
   			break;
   		case 4:
   			exit(0);
   	}
   }
};

class destination : public customer, public admin{
public:
   void show_nationalDest(){
   	pattern_spaces (4); pattern_line (60); pattern_spaces (4); pattern_line (60);
   	pattern_spaces (12); cout<<"INDIA"<<endl; pattern_spaces (4); pattern_line (60);
   	pattern_spaces (4); cout<<setw(15)<<"CITY Code"<<setw(15)<<"CITY"<<setw(30)<<"RATINGS"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"1. MUM001"<<setw(15)<<"MUMBAI"<<setw(30)<<"10.0"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"2. DEL100"<<setw(15)<<"DELHI"<<setw(30)<<"9.2"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"3. KOL001"<<setw(15)<<"KOLKATA"<<setw(30)<<"7.9"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"4. CHE001"<<setw(15)<<"CHENNAI"<<setw(30)<<"8.7"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"5. BANG001"<<setw(15)<<"BANG"<<setw(30)<<"9.1"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"6. AGR100"<<setw(15)<<"AGRA"<<setw(30)<<"8.9"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"7. KERA001"<<setw(15)<<"KERALA"<<setw(30)<<"8.8"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"8. GOA102"<<setw(15)<<"GOA"<<setw(30)<<"9.7"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"9. JAI109"<<setw(15)<<"JAIPUR"<<setw(30)<<"8"<<endl;
   }
   void show_internationalDest(){
   	pattern_spaces (4); pattern_line (60); pattern_spaces (4); pattern_line (60);
   	pattern_spaces (11); cout<<"INTERNATIONAL"<<endl; pattern_spaces (4); pattern_line (60);
   	pattern_spaces (4); cout<<setw(15)<<"CITY Code"<<setw(30)<<"CITY"<<setw(30)<<"RATINGS"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"1. USA001"<<setw(30)<<"UNITED STATES OF AMERICA"<<setw(30)<<"10.0"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"2. UK100"<<setw(30)<<"UNITED KINGDOM"<<setw(30)<<"9.2"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"3. FRA001"<<setw(30)<<"FRANCE"<<setw(30)<<"7.9"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"4. GER001"<<setw(30)<<"GERMANY"<<setw(30)<<"8.7"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"5. SPA001"<<setw(30)<<"SPAIN"<<setw(30)<<"9.1"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"6. GREE100"<<setw(30)<<"GREECE"<<setw(30)<<"8.9"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"8. AUS102"<<setw(30)<<"AUSTRALIA"<<setw(30)<<"9.7"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"9. NEW109"<<setw(30)<<"NEW ZEALAND"<<setw(30)<<"8"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"9. RUS109"<<setw(30)<<"RUSSIA"<<setw(30)<<"8"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"9. THAI109"<<setw(30)<<"THAILAND"<<setw(30)<<"8.9"<<endl;
	pattern_spaces (4); cout<<setw(15)<<"9. BANG109"<<setw(30)<<"BANGKOK"<<setw(30)<<"8"<<endl;
   }
   void get_destination(){
   	pattern_spaces (4); pattern_line (60);
   	pattern_spaces (4); cout<<"ENTER CITY CODE : ";
   }
};

class  packages:public travel_agency
{
public:
float Fare_Charges;
char Reservation[30],hotels[30],cities[30],luxury[30];
int Duration;
void accept4();
void display4();
};
void packages::accept4()
{
cout<<"\n                                      ********************************************                        **********************************************:";
cout<<"\n                                      *************************                        PACKAGES ENTRIES                            *********************:";
cout<<"\n                                      ********************************************                        **********************************************:";
cout<<"\n\n                                                                                Enter fare charges:-";
cin>>Fare_Charges;
cout<<"                                                                                    Enter Reservation:-";
cin>>Reservation;
cout<<"                                                                                    Enter hotels:-";
cin>>hotels;
cout<<"                                                                                    Enter cities:-";
cin>>cities;
cout<<"                                                                                    Enter luxury:-";
cin>>luxury;
}
void packages::display4()
{
cout<<"                                       *******************************************************************************************************************";
cout<<"\n                                     ********************************************                        **********************************************:";
cout<<"\n                                     *************************                   WELCOME TO TRAVEL AGENCY                     *************************:";
cout<<"\n                                     ********************************************                        **********************************************:";
cout<<"\n                                     ******************************************************************************************************************:";
cout<<"\n\n                                                                            Enter fare charges:"<<Fare_Charges<<endl;
cout<<"                                                                                Enter reservation:"<<Reservation<<endl;
cout<<"                                                                                Enter hotels:"<<hotels<<endl;
cout<<"                                                                                Enter cities:"<<cities<<endl;
cout<<"                                                                                Enter luxury:"<<luxury<<endl;
}
class payment:public travel_agency
{
public:
   char BankAccount_Details[30],Debit[30], credit[30], Net_Banking[30], E_wallet[30];
   void accept5();
   void display5();
};
void payment::accept5()
{
cout<<"\n                                      ********************************************                        **********************************************:";
cout<<"\n                                      *************************                        PAYMENTS ENTRIES                            *************************:";
cout<<"\n                                      ********************************************                        **********************************************:";
cout<<"\n\n                                                                             Enter bank account details:-";
cin>>BankAccount_Details;
cout<<"                                                                                 Enter debit details:-";
cin>>Debit;
cout<<"                                                                                 Enter credit details:-";
cin>>credit;
cout<<"                                                                                 Enter net banking details:-";
cin>>Net_Banking;
cout<<"                                                                                 Enter E-wallet details:-";
cin>>E_wallet;
}
void payment::display5()
{

cout<<"                                       *******************************************************************************************************************";
cout<<"\n                                     ********************************************                        **********************************************:";
cout<<"\n                                     *************************                   WELCOME TO TRAVEL AGENCY                     *************************:";
cout<<"\n                                     ********************************************                        **********************************************:";
cout<<"\n                                     ******************************************************************************************************************:";
cout<<"\n\n                                                                            Enter bank account details:"<<BankAccount_Details<<endl;
cout<<"                                                                                Enter credit details:"<<credit<<endl;
cout<<"                                                                                Enter net banking details:"<<Net_Banking<<endl;
cout<<"                                                                                Enter E-wallet details:"<<E_wallet<<endl;
}


int main(){
	travel_agency *T;
	int ch;
	header(1);
	admin A;
	customer C;
	while(1){
		pattern_spaces (4); cout<<"1. ADMIN"<<endl;
		pattern_spaces (4); cout<<"2. CUSTOMER"<<endl;
		pattern_spaces (4); cout<<"3. EXIT"<<endl;
		cin>>ch;
		switch (ch){
			case 1 :	T = &A;
                        T->accept();
						T->display();
						break;
			case 2 :	T = &C;
                        T->accept();
                        T->display();
						break;
			case 3 :	pattern_spaces (4); cout<<"EXITING>>>>";
						exit(0);
			default :	pattern_spaces (4); cout<<"WRONG CHOICE.";

		}
	}
	return 0;
}
