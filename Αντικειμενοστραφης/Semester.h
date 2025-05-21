#ifndef SEMESTER_H
#define SEMESTER_H

#include <vector>
#include "Course.h"

using namespace std;

class Course;

class Semester {
	int semesterNum;
	vector<Course*> sem;
	
public:
	Semester();
	Semester(int semesterNum);
	~Semester();
    void addCourse(Course* course);
    
    void setSemNum(int num){
    	semesterNum = num;
	}
    int getSemNum() const ;
    void displayCourses() const;
    void changeSemester();
    
    const vector<Course*>& getCourses() const;

};

#endif

