#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Semester.h"
#include "Student.h"
#include "Professor.h"

using namespace std;

class Student;
class Professor;

class Course
{
	string name;
	int ects;
	bool mandatory;
	int semester;
	float grade;
	
	vector<Professor*> professorsTeaching;
	vector<Student*> enrolledStudents;
	vector<Student*> studentsPassed;
	
	public:
		
		Course();
		Course(const string& name, int ects, bool mandatory, int semester);

		~Course();
		
		string getName() const;
		int getEcts() const;
		bool isMandatory() const;
		int getSemester() const;
		float getGrade() const;
		const vector<Professor*>& getProfessors() const;
		const vector<Student*>& getStudentsEnrolled() const;
		const vector<Student*>& getStudentsPassed() const;
		
		void setName(string n);
		void setECTS(int Ects);
		void setSemester(int sem);
		void setMandatory(bool t);
		void setGrade(float g);
		
		friend ostream &operator<<(ostream &str, const Course &obj);
        friend istream &operator>>(istream &str, Course &obj);
        
        Course(const Course &c);
        Course& operator=(const Course &op2);
		
		void enrollStudent(Student* student);	
		void displayEnrolledStudents() const;
		
		void PassedStudent(Student* student);
		void displayPassedStudents() const;
		
		void addProfessor(Professor* professor);
    	void displayProfessors() const;
    	
    	void displayStudents();

};

#endif
