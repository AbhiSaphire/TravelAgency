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
    cout <<"Strength of password:-";
    if (hasLower && hasUpper && hasDigit && specialChar && (n >= 8)){
        pattern_spaces (4); cout << "Strong" << endl;
    }
    else if ((hasLower || hasUpper) && specialChar && (n >= 6)){
        pattern_spaces (4); cout << "Moderate" << endl;
    }
    else{
        pattern_spaces (4); cout << "Weak" << endl;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------

class travel_agency{
public:
	char username[40], name[40], reservation[30], hotels[30], bankaccountDetails[50], city[30], state[30], country [30], places[30], phone[10];
	string Password, email, city_code, city_code_P;
	int choice, rating, i;
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
		pattern_spaces (4); cout<<"ENTER PASSWORD : "; cin>>Password; printStrongNess(Password);
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
	friend void payment_from_Dest(city_code);
   	void show_nationalDest(){
   		ofstream national ("nationalDest.txt");
   		if (national.good()){
   			i = 1;
   			pattern_spaces (4); pattern_line (60); pattern_spaces (4); pattern_line (60);
			pattern_spaces (12); cout<<"INDIA"<<endl; pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<setw(15)<<"CITY Code"<<setw(15)<<"CITY"<<setw(30)<<"RATINGS"<<endl;
   			while (national >> city_code >> city >> rating >> price >> getline(info)){
				pattern_spaces (4); cout<<setw(3)<<i<<setw(10)<<city_code<<setw(15)<<city<<setw(30)<<rating<<endl;
				i++;
			}
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
		}
   	}
   	void show_internationalDest(){
   		ofstream international ("internationalDest.txt");
   		if (internationalDest.good()){
   			i = 1;
		   	pattern_spaces (4); pattern_line (60); pattern_spaces (4); pattern_line (60);
		   	pattern_spaces (11); cout<<"INTERNATIONAL"<<endl; pattern_spaces (4); pattern_line (60);
		   	pattern_spaces (4); cout<<setw(15)<<"CITY Code"<<setw(30)<<"CITY"<<setw(30)<<"RATINGS"<<endl;
		   	while (international >> city_code >> city >> rating >> price >> getline(info)){
		   		pattern_spaces (4); cout<<setw(3)<<i<<setw(10)<<city_code<<setw(30)<<city<<setw(30)<<rating<<endl;
				i++;
			}
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
		}
	}
   	void get_nationalDest(){
	   	ofstream national ("nationalDest.txt");
	   	if (national.good()){
		   	pattern_spaces (4); pattern_line (60);
		   	pattern_spaces (4); cout<<"ENTER CITY CODE : "; cin>>city_code_P;
		   	while (national >> city_code >> city >> ratings >> price >> info){
		   		if (city_code_P == city_code){
		   			pattern_spaces (4); pattern_line (60);
		   			pattern_spaces (4); cout<<setw(15)<<"CITY Code"<<setw(15)<<"CITY"<<setw(30)<<"RATINGS"<<setw(10)<<"PRICE"<<setw(30)<<"DETAILS"<<endl;
		   			pattern_spaces (4); cout<<setw(15)<<city_code<<setw(15)<<city<<setw(30)<<rating<<setw(10)<<price<<setw(30)<<info<<endl<<endl;
		   			pattern_spaces (4); cout<<"CONTINUE TO PAYMENT : (1 for YES || 0 for NO)"<<endl; cin>>choice;
		   		}
		   	}
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
		}
   	}
   	void get_internationalDest(){
   		ofstream international ("internationalDest.txt");
	   	if (international.good()){
		   	pattern_spaces (4); pattern_line (60);
		   	pattern_spaces (4); cout<<"ENTER CITY CODE : "; cin>>city_code_P;
		   	while (international >> city_code >> city >> ratings >> price >> info){
		   		if (city_code_P == city_code){
		   			pattern_spaces (4); pattern_line (60);
		   			pattern_spaces (4); cout<<setw(15)<<"CITY Code"<<setw(15)<<"CITY"<<setw(30)<<"RATINGS"<<setw(10)<<"PRICE"<<setw(30)<<"DETAILS"<<endl;
		   			pattern_spaces (4); cout<<setw(15)<<city_code<<setw(15)<<city<<setw(30)<<rating<<setw(10)<<price<<setw(30)<<info<<endl<<endl;
		   			pattern_spaces (4); cout<<"CONTINUE TO PAYMENT : (1 for YES || 0 for NO)"<<endl; cin>>choice;
		   		}
		   	}
		}
		else{
			pattern_spaces (4); pattern_line (60);
			pattern_spaces (4); cout<<"SORRY CONNECTION NOT BUILD PROPERLY...  BAD DAY :-( ";
		}
   	}
};

class  packages : public travel_agency{
public:
	void show_packages(){
		ofstream package ("packages.txt");
	   	if (package.good()){
	   		i = 1;
			pattern_spaces (4); pattern_line (60);
   			pattern_spaces (10); cout<<"PACKAGES JUST FOR YOU"<<endl; pattern_spaces (4); pattern_line (60);
   			while (package >> package_type >> package_time >> package_price){
				pattern_spaces (4); cout<<setw(3)<<i<<setw(20)<<package_type<<setw(30)<<package_time<<setw(6)<<package_price<<endl;
				i++;
			}
		}
	}
};


class payment : public travel_agency{
public:
	void show_payment_methods(){

	}
}; 


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
