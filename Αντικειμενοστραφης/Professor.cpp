#include "Professor.h"

using namespace std;


// Constructor
Professor::Professor() : Person() {
	currentSemester = new Semester();
}
Professor::Professor(const string& name, const string& email, long long int phone, int semesterNum) : Person(name, email, phone){
	currentSemester = new Semester(semesterNum);
}

// Destructor
Professor::~Professor() {
	delete currentSemester;
}

int Professor::getCurrentSemesterNum() const{
	return currentSemester->getSemNum();
}

Semester* Professor::getCurrentSemester() const{
	return currentSemester;
}
void Professor::teachCourse(Course* course) const{
	currentSemester->addCourse(course);
}

void Professor::displayCoursesTeaching() const {
    cout << "Courses Teaching by Professor " << getName() << ":\n";
    currentSemester->displayCourses();
}

void Professor::profStats(){
	for (const auto& cour : currentSemester->getCourses()) {
		float sum = 0;
		int count= 0;
		cout<<"\nStats for "<<cour->getName()<<":"<<endl;
		cout<< cour->getStudentsPassed().size()  << "/" << cour->getStudentsEnrolled().size() <<" Enrolled Students have passed "<<cour->getName()<<endl;
		for (const auto& stud : cour->getStudentsEnrolled()) {
			for (const auto& course : stud->getCurrentSemester()->getCourses()){
				if (course->getName() == cour->getName()){
					sum = sum + course->getGrade();
					if(course->getGrade() >= 8){
						count++;
					}
				}
			}			
		}
		cout << "Average grade is: " << sum / cour->getStudentsEnrolled().size()<<endl;
		cout << count << " Students Passed with a grade over 8! " <<endl;
	}
}

void Professor::changeSem(){
	
    currentSemester->changeSemester();
    
}








