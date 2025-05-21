#include <iostream>
#include <string>
#include <iterator>
#include <set>

#include "Person.h"

using namespace std;

int count =0;

//Constructors
Person::Person():name("0"),/* age(0),*/ email("0"), phone(0){
    ++count;
    //cout<<"constructed 1"<<endl;
}
Person::Person(const string& n){
    name = n;
//    age = 0;
    email = "0";
    phone = 0;
    ++count;
    //cout<<"constructed 2"<<endl;
}
Person::Person(const string& n,/* int a,*/ const string& e){
    name = n;
//    age = a;
    email = e;
    phone = 0;
    ++count;
    //cout<<"constructed 4"<<endl;
}
Person::Person(const string& n,/* int a,*/ const string& e, long long int p){
    name = n;
//    age = a;
    email = e;
    phone = p;
    ++count;
    //cout<<"constructed 5"<<endl;
}
Person::~Person(){
    //cout<<"deconstructed"<<endl;
}

//Mutators
void Person::setName(string n){
	name = n;
}
//void Person::setAge(int a){
//	age = a;
//}
void Person::setEmail(string e){
	email = e;
}
void Person::setPhone(long long int p){
	phone = p;
}

//Accessors
string Person::getName() const{
	return name;
}
//int Person::getAge() const{
//    return age;
//}
string Person::getEmail() const{
    return email;
}
long long int Person::getPhone() const{
    return phone;
}

bool Person::operator<(const Person &other) const {
    return name < other.name;
}

ostream &operator<<(ostream &str, const Person &obj){
    str << "Name: " << obj.name << endl;
//    str << "Age: " << obj.age << endl;
    str << "Email: " << obj.email << endl;
    str << "Phone Number: " << obj.phone << endl;
    return str;
}

istream &operator>>(istream &str, Person &obj){
	if (str.rdbuf() == cin.rdbuf()) {
        // Reading from console
    	cout << "Give Surname and Name: ";
    	getline(str, obj.name);
   
    	cout << "Give Email: ";
    	str >> obj.email;

    	bool phoneInputValid = false;
    	while (!phoneInputValid) {
        	cout << "Give Phone number: ";
        	try{
        		if (str >> obj.phone && obj.phone >= 1000000000 && obj.phone <= 9999999999) {
            		phoneInputValid = true;
        		} else {
            		throw(obj.phone);
            	}
        	}
        	catch(long long int phone){
				cout << "Invalid input. Please enter a valid phone Number." << endl;
            	str.clear();
            	while (str.get() != '\n');
			}
    	}
	}else {
        // Reading from file
        string line;
		getline(str, line);
        stringstream ss(line);
        getline(ss, obj.name, ',');
        getline(ss >> ws, obj.email, ',');
        ss >> obj.phone;  
	}
	return str;
}

