#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <iterator>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

class Person {
	protected:
        string name;
//        int age;
        string email;
        long long int phone;
        
    public:

        Person();
        Person(const string& n);
        Person(const string& n, const string& e);
        Person(const string& n, const string& e, long long int p);
        ~Person();
		
		void setName(string n);
//		void setAge(int a);
		void setEmail(string e);
		void setPhone(long long int p);
		
		string getName() const;
//		int getAge() const;
		string getEmail() const;
		long long int getPhone() const;
        
        
		bool operator<(const Person &other) const;
        
        friend ostream &operator<<(ostream &str, const Person &obj);
        friend istream &operator>>(istream &str, Person &obj);
};


#endif
