//---------------------------------------------------------------TRAVEL AGENCY PROGRAM----------------------------------------------------------------

//--------------------------------------------------------------------HEADER FILES--------------------------------------------------------------------

#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <conio.h>
#include <fstream>
using namespace std;

//----------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------DECLARATIONS AND HELPING FUNCTIONS DEFINITONS------------------------------------------------------

void payment_mode(int);

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
	mycheck = check(pwd,def);
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
    pattern_spaces (4); cout <<"Strength of password :: ";
    if (hasLower && hasUpper && hasDigit && specialChar && (n >= 8)){
        cout << "Strong" << endl;
    }
    else if ((hasLower || hasUpper) && specialChar && (n >= 6)){
        cout << "Moderate" << endl;
    }
    else{
        cout << "Weak" << endl;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------CLASSES------------------------------------------------------------------------

char username[20], name[20], phone[10];
string Password, email;
int debit;

class travel_agency{
public:
	char username[20], name[20], city[30], phone[10], package_type[20], package_time[30];
	string Password, email, city_code, city_code_P;
	int choice, rating, package_price, price, debit, i, ch;

   	virtual void accept() = 0;
	friend void payment_mode(int);
};

class admin : public travel_agency{
	int op;
public:
	friend void show_nationalDest();
	friend void show_internationalDest();

	void modify_package (){
		pattern_spaces (4); cout<<"1. VIEW PACKAGES"<<endl; pattern_spaces (4); cout<<"2. ADD NEW PACKAGES "; cin>>op; cout<<endl;
		switch (op){
			case 1: {
                ifstream package ("packages.txt");
				if (package.good()){
					i = 1;
					while (package >> city_code >> package_type >> package_time >> package_price){
						pattern_spaces (4); cout<<setw(3)<<i<<setw(20)<<city_code<<setw(30)<<package_type<<setw(30)<<package_time<<setw(10)<<package_price<<endl;
						i++;
					}
				}
				else{
					pattern_spaces (4); pattern_line (60);
					pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( "<<endl;
				}
                }
				break;
			case 2:	{
			    ofstream package;
			    package.open("packages.txt", ios_base::app);
				if (package.good()){
					pattern_spaces (4); cout<<"PACKAGE CODE : "; cin>>city_code; cout<<endl;
					pattern_spaces (4); cout<<"PACKAGE TYPE : "; cin>>package_type; cout<<endl;
					pattern_spaces (4); cout<<"PACKAGE TIME : "; cin>>package_time; cout<<endl;
					pattern_spaces (4); cout<<"PACKAGE PRICE : "; cin>>package_price; cout<<endl;
					package << city_code << " " << package_type << " " << package_time << " " << package_price << endl;
					pattern_spaces (8); cout<<"-----ENTRY FILLED-----"<<endl;
				}
				else{
					pattern_spaces (4); pattern_line (60);
					pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( "<<endl;
				}
                }
				break;
			default:	pattern_spaces (4); cout<<"LOOK AT CHOICES BEFORE SELECTING .. "; modify_package();
		}
	}
	void modify_nationalDest (){
		pattern_spaces (4); cout<<"1. SHOW DESTINATIONS "<<endl;
		pattern_spaces (4); cout<<"2. ADD NEW DESTINATIONS : "; cin>>op;
		switch(op){
			case 1:	{
			    ifstream national ("nationalDest.txt");
		   		if (national.good()){
		   			i = 1;
		   			pattern_spaces (4); pattern_line (60); pattern_spaces (4); pattern_line (60);
					pattern_spaces (10); cout<<"INDIA"<<endl; pattern_spaces (4); pattern_line (60);
					pattern_spaces (4); cout<<setw(8)<<"SNo"<<setw(20)<<"CITY CODE"<<setw(20)<<"CITY"<<setw(30)<<"RATINGS"<<endl;
		   			while (national >> city_code >> city >> rating >> price){
						pattern_spaces (4); cout<<setw(8)<<i<<setw(20)<<city_code<<setw(20)<<city<<setw(30)<<rating<<endl;
						i++;
					}
				}
				else{
					pattern_spaces (4); pattern_line (60);
					pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
					return;
				}
                }
				break;
			case 2:	{
			    ofstream national;
			    national.open("nationalDest.txt", ios_base::app);
				if (national.good()){
					pattern_spaces (4); cout<<"CITY CODE : "; cin>>city_code; cout<<endl;
					pattern_spaces (4); cout<<"CITY : "; cin>>city; cout<<endl;
					pattern_spaces (4); cout<<"RATINGS : "; cin>>rating; cout<<endl;
					pattern_spaces (4); cout<<"PRICE : "; cin>>price; cout<<endl;
					national << city_code << " " << city << " " << rating << " " << price <<endl;
					pattern_spaces (8); cout<<"-----ENTRY FILLED-----"<<endl;
				}
				else{
					pattern_spaces (4); pattern_line (60);
					pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( "<<endl;
				}
                }
				break;
			default:	pattern_spaces (4); cout<<"LOOK AT CHOICES BEFORE SELECTING .. "; modify_nationalDest();
		}
	}
	void modify_internationalDest (){
		pattern_spaces (4); cout<<"1. SHOW DESTINATIONS "<<endl;
		pattern_spaces (4); cout<<"2. ADD NEW DESTINATIONS : "; cin>>op;
		switch(op){
			case 1:{
			    ifstream international ("internationalDest.txt");
		   		if (international.good()){
		   			i = 1;
				   	pattern_spaces (4); pattern_line (60); pattern_spaces (4); pattern_line (60);
				   	pattern_spaces (11); cout<<"INTERNATIONAL"<<endl; pattern_spaces (4); pattern_line (60);
				   	pattern_spaces (4); cout<<setw(8)<<"S No"<<setw(20)<<"CITY Code"<<setw(30)<<"CITY"<<setw(30)<<"RATINGS"<<endl;
				   	while (international >> city_code >> city >> rating >> price){
				   		pattern_spaces (4); cout<<setw(8)<<i<<setw(20)<<city_code<<setw(30)<<city<<setw(30)<<rating<<endl;
						i++;
					}
				}
				else{
					pattern_spaces (4); pattern_line (60);
					pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
					return;
				}
                }
				break;
			case 2:	{
			    ofstream international;
			    international.open("internationalDest.txt", ios_base::app);
				if (international.good()){
					pattern_spaces (4); cout<<"CITY CODE : "; cin>>city_code; cout<<endl;
					pattern_spaces (4); cout<<"CITY : "; cin>>city; cout<<endl;
					pattern_spaces (4); cout<<"RATINGS : "; cin>>rating; cout<<endl;
					pattern_spaces (4); cout<<"PRICE : "; cin>>price; cout<<endl;
					international << city_code << " " << city << " " << rating << " " << price << endl;
					pattern_spaces (8); cout<<"-----ENTRY FILLED-----"<<endl;
				}
				else{
					pattern_spaces (4); pattern_line (60);
					pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( "<<endl;
				}
                }
				break;
			default:	pattern_spaces (4); cout<<"LOOK AT CHOICES BEFORE SELECTING .. "; modify_internationalDest();
		}
	}
	void view_cutomer_details (){
		ifstream customer("customerDetails.txt");
		if (customer.good()){
			pattern_spaces (4); cout<<setw(30)<<"USERNAME"<<setw(20)<<"NAME"<<setw(30)<<"PHONE NUMBER"<<setw(10)<<"DEBIT"<<endl;
			while(customer >> username >> name >> email >> phone >> Password >>debit){
				pattern_spaces (4); cout<<setw(30)<<username<<setw(20)<<name<<setw(30)<<phone<<setw(10)<<debit<<endl;
			}
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( "<<endl;
		}
	}

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
   		pattern_spaces (4); cout<<"3. VIEW CUSTOMER RECORDS"<<endl; pattern_spaces (4); cout<<"4. EXIT "; cin>>choice; cout<<endl;
   		switch (choice){
   			case 1:	modify_package();
   				break;
   			case 2:	pattern_spaces (4); cout<<"1. NATIONAL"<<endl; pattern_spaces (4); cout<<"2. INTERNATIONAL "; cin>>ch; cout<<endl;
   				switch (ch){
   					case 1 :	modify_nationalDest();
   						break;
   					case 2 :	modify_internationalDest();
   						break;
   					default :	pattern_spaces (4); cout<<"WRONG CHOICE>>>";
   				}
   				break;
   			case 3:	view_cutomer_details();
   				break;
   			case 4:	pattern_spaces (4); cout<<">>>>>>>>>>>   EXITING   >>>>>>>"; pattern_spaces (4); pattern_line (60);
   				exit(0);
   			default:	pattern_spaces (4); cout<<"WRONG CHOICE>>>";
   				pattern_spaces (4); pattern_line (60);
   				display();
   		}
   	}
};

class customer : public travel_agency{
public:
    virtual void show_nationalDest(){}
    virtual void show_internationalDest(){}
    virtual void show_packages(){}

   	void accept(){
	  	pattern_spaces (4); pattern_line (60);
		pattern_spaces (4); pattern_line (60);
		pattern_spaces (11); cout<<"WELCOME CUSTOMER"<<endl;
		pattern_spaces (4); cout<<"ENTER USERNAME : "; cin>>username; cout<<endl;
		pattern_spaces (4); cout<<"ENTER NAME : "; cin>>name; cout<<endl;
		pattern_spaces (4); cout<<"ENTER EMAIL ID : "; cin>>email; cout<<endl;
		pattern_spaces (4); cout<<"ENTER PHONE NUMBER : "; cin>>phone; cout<<endl;
		pattern_spaces (4); cout<<"ENTER PASSWORD : "; cin>>Password; printStrongNess(Password);
		pattern_spaces (4); cout<<"ENTER HOW MUCH DEBIT YOU HAVE : "; cin>>debit;
		ofstream customer;
		customer.open("customerDetails.txt", ios_base::app);
		if (customer.good()){
			customer << username << " " << name << " " << email << " " << phone << " " << Password << " " << debit << endl;
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( "<<endl;
		}
	}
};

class destination : public customer{
public:
   	void show_nationalDest(){
   		ifstream national ("nationalDest.txt");
   		if (national.good()){
   			i = 1;
   			pattern_spaces (4); pattern_line (60); pattern_spaces (4); pattern_line (60);
			pattern_spaces (10); cout<<"INDIA"<<endl; pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<setw(8)<<"SNo"<<setw(20)<<"CITY CODE"<<setw(20)<<"CITY"<<setw(30)<<"RATINGS"<<endl;
   			while (national >> city_code >> city >> rating >> price){
				pattern_spaces (4); cout<<setw(8)<<i<<setw(20)<<city_code<<setw(20)<<city<<setw(30)<<rating<<endl;
				i++;
			}
			get_nationalDest();
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
			return;
		}
   	}
   	void show_internationalDest(){
   		ifstream international ("internationalDest.txt");
   		if (international.good()){
   			i = 1;
		   	pattern_spaces (4); pattern_line (60); pattern_spaces (4); pattern_line (60);
		   	pattern_spaces (11); cout<<"INTERNATIONAL"<<endl; pattern_spaces (4); pattern_line (60);
		   	pattern_spaces (4); cout<<setw(8)<<"S No"<<setw(20)<<"CITY Code"<<setw(30)<<"CITY"<<setw(30)<<"RATINGS"<<endl;
		   	while (international >> city_code >> city >> rating >> price){
		   		pattern_spaces (4); cout<<setw(8)<<i<<setw(20)<<city_code<<setw(30)<<city<<setw(30)<<rating<<endl;
				i++;
			}
			get_internationalDest();
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
			return;
		}
	}
   	void get_nationalDest(){
	   	ifstream national ("nationalDest.txt");
	   	if (national.good()){
		   	pattern_spaces (4); pattern_line (60);
		   	pattern_spaces (4); cout<<"ENTER CITY CODE : "; cin>>city_code_P;
		   	while (national >> city_code >> city >> rating >> price){
		   		if (city_code_P == city_code){
		   			pattern_spaces (4); pattern_line (60);
		   			pattern_spaces (4); cout<<setw(25)<<"CITY Code"<<setw(30)<<"CITY"<<setw(30)<<"RATINGS"<<setw(20)<<"PRICE"<<endl;
		   			pattern_spaces (4); cout<<setw(25)<<city_code<<setw(30)<<city<<setw(30)<<rating<<setw(20)<<price<<endl<<endl;
		   			pattern_spaces (4); cout<<"CONTINUE TO PAYMENT : (1 for YES || 0 for NO) "; cin>>choice; cout<<endl;
		   			if (choice == 1){
		   				payment_mode(package_price);
		   				return;
		   			}
		   		}
		   	}
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
			return;
		}
   	}
   	void get_internationalDest(){
   		ifstream international ("internationalDest.txt");
	   	if (international.good()){
		   	pattern_spaces (4); pattern_line (60);
		   	pattern_spaces (4); cout<<"ENTER CITY CODE : "; cin>>city_code_P;
		   	while (international >> city_code >> city >> rating >> price){
		   		if (city_code_P == city_code){
		   			pattern_spaces (4); pattern_line (60);
		   			pattern_spaces (4); cout<<setw(25)<<"CITY Code"<<setw(30)<<"CITY"<<setw(30)<<"RATINGS"<<setw(20)<<"PRICE"<<endl;
		   			pattern_spaces (4); cout<<setw(25)<<city_code<<setw(30)<<city<<setw(30)<<rating<<setw(20)<<price<<endl<<endl;
		   			pattern_spaces (4); cout<<"CONTINUE TO PAYMENT : (1 for YES || 0 for NO) "; cin>>choice; cout<<endl;
		   			if (choice == 1){
		   				payment_mode(package_price);
		   				return;
		   			}
		   		}
		   	}
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
			return;
		}
   	}
};

class  packages : public customer{
public:
	void show_packages(){
		ifstream package ("packages.txt");
	   	if (package.good()){
	   		i = 1;
			pattern_spaces (4); pattern_line (60);
   			pattern_spaces (10); cout<<"PACKAGES JUST FOR YOU"<<endl; pattern_spaces (4); pattern_line (60);
   			pattern_spaces (4); cout<<setw(13)<<"PACKAGE CODE"<<setw(20)<<"PACKAGE TYPE"<<setw(30)<<"PACKAGE TIME"<<setw(20)<<"PRICE"<<endl;
   			pattern_spaces (4); pattern_line (60);
   			while (package >> city_code >> package_type >> package_time >> package_price){
				pattern_spaces (4); cout<<setw(3)<<i<<setw(10)<<city_code<<setw(20)<<package_type<<setw(30)<<package_time<<setw(20)<<package_price<<endl;
				i++;
			}
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"CHOOSE YOUR PACKAGE :: ENTER PACKAGE CODE : "; cin>>city_code_P; cout<<endl;
			while (package >> city_code >> package_type >> package_time >> package_price){
				if (city_code_P == city_code){
					pattern_spaces (4); pattern_line (60);
					pattern_spaces (4); cout<<setw(13)<<"PACKAGE CODE"<<setw(20)<<"PACKAGE TYPE"<<setw(30)<<"PACKAGE TIME"<<setw(20)<<"PRICE"<<endl;
					pattern_spaces (4); cout<<setw(3)<<i<<setw(10)<<city_code<<setw(20)<<package_type<<setw(30)<<package_time<<setw(20)<<package_price<<endl;
					pattern_spaces (4); cout<<"CONTINUE TO PAYMENT : (1 for YES || 0 for NO)"; cin>>choice; cout<<endl;
		   			if (choice == 1){
		   				payment_mode(package_price);
		   				return;
		   			}
				}
			}
		}
	}
};

//-----------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------PAYMENT FUNCTION-------------------------------------------------------------------

void payment_mode(int n){
	fstream customer;
	customer.open("customerDetails.txt", ios_base::app);
	if (customer.good()){
		customer >> username >> name >> email >> phone >> Password >> debit;
		debit -= n;
		customer << username << name << email << phone << Password << debit << endl;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------MAIN FUNCTION--------------------------------------------------------------------


int main(){
	travel_agency *T;
	int ch, choice;
	header(1);
	admin A;
	customer C, *ptr;
	destination D;
	packages P;
	while(1){
		pattern_spaces (4); cout<<"1. ADMIN"<<endl;
		pattern_spaces (4); cout<<"2. CUSTOMER"<<endl;
		pattern_spaces (4); cout<<"3. EXIT "; cin>>ch; cout<<endl;
		switch (ch){
			case 1 :	T = &A;
                        T->accept();
						A.display();
						break;
			case 2 :	T = &C;
                        T->accept();
                        ptr = &D;
                        header(2);
				   		pattern_spaces (4); cout<<"1. NATIONAL DESTINATION TOURISM"<<endl; pattern_spaces (4); cout<<"2. INTERNATIONAL DESTINATIONS TOURISM"<<endl;
				   		pattern_spaces (4); cout<<"3. OR SELECT OUR WORLD CLASS PACKAGES JUST FOR YOU"<<endl; pattern_spaces (4); cout<<"4. EXIT"; cin>>choice;
				   		switch (choice){
				   			case 1:	ptr->show_nationalDest ();
				   				break;
				  	 		case 2:	ptr->show_internationalDest ();
				   				break;
				   			case 3:	ptr = &P;
				   				ptr->show_packages ();
				   				break;
				   			case 4:	pattern_spaces (4); cout<<">>>>>>>>>>>   EXITING   >>>>>>>"; pattern_spaces (4); pattern_line (60);
				   				exit(0);
				   		}
						break;
			case 3 :	pattern_spaces (4); cout<<"EXITING>>>>";
						exit(0);
			default :	pattern_spaces (4); cout<<"WRONG CHOICE.";

		}
	}
	return 0;
}
