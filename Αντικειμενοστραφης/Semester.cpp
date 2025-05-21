#include "Semester.h"

using namespace std;

Semester::Semester() {
}
Semester::Semester(int semesterNum) : semesterNum(semesterNum) {
}
Semester::~Semester() {
	sem.clear();
}
	
void Semester::addCourse(Course* course) {
    sem.push_back(course);
}

int Semester::getSemNum() const {
	return semesterNum;
}
void Semester::displayCourses() const {
    for (const auto& course : sem) {
        cout << "- " << course->getName() << "\n";
    }
}

void Semester::changeSemester(){
	if(semesterNum<8){
		semesterNum++;
	}
	sem.clear();
}

const vector<Course*>& Semester::getCourses() const {
    return sem;
}
