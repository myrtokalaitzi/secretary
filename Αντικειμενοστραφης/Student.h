#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Person.h"
#include "Course.h"
#include "Semester.h"


using namespace std;

class Semester;
class Course;

class Student : public Person
{
		long long int idNumber;
		int admissionYear;
		Semester* currentSemester;
		Semester* previousSemesters;
		int ectsCollected;
		int passedMandatoryCourses;
	
	public:
		
		Student();
    	Student(const string& name, const string& email, long long int phone, long long int idNumber, int admissionYear, int semesterNum, int ectsCollected, int passedMandatoryCourses);

		~Student();
		
		long long int getIdNumber() const;
		int getAdmissionYear() const;
		int getCurrentSemesterNum() const;
		int getEctsCollected() const;
		int getPassedMandatoryCourses() const;
		Semester* getCurrentSemester() const;
		
		void setIdNumber(long long int id);
		void setAdmissionYear(int ay);
		void setEctsCollected(int ec);
		void setPassedMandatoryCourses(int pmc);	
		
		friend ostream &operator<<(ostream &str, const Student &obj);
        friend istream &operator>>(istream &str, Student &obj);
		
		void enrollInCourse(Course* course) const;
		void displayCurrentSemesterCourses() const;
		
		void takeExam( Course* course, float grade);
		
		void displayGrades();
		
		void changeSem();
		
};

#endif
