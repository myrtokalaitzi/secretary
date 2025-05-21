#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <vector>
#include <fstream>
#include <sstream>

#include "Semester.h"
#include "Person.h"
#include "Student.h"
#include "Course.h"

using namespace std;
class Student;

class Professor : public Person
{
	Semester* currentSemester;
	
	public:
		Professor();
		Professor(const string& name, const string& email, long long int phone, int semesterNum);
		~Professor();
		
		int getCurrentSemesterNum() const;
		Semester* getCurrentSemester() const;
		
		void teachCourse(Course* course) const;
		
		void displayCoursesTeaching() const;
		
		void profStats();
		
		void changeSem();
		
		
};

#endif
