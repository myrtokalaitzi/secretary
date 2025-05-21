#include <iostream>
#include <string>
#include <iterator>
#include <set>

#include "Person.h"
#include "Secretary.h"

using namespace std;

Secretary::Secretary() {
	
}

Secretary::~Secretary() {
    students.clear();
    professors.clear();
    courses.clear();
    //cout << "deconstructed" << endl;
}
	
//Secretary Secretary::operator+(const Person& op2) {
//    Secretary t = *this;
//    Person* newPerson = new Person(op2);
//    t.sec.insert(newPerson);
//    return t;
//}

Secretary Secretary::operator+(const Student& op2) {
    Student* newStudent = new Student(op2); 
    addStudent(newStudent);
    writeStudentsToFile("stud.txt");
    
    return *this;
}
Secretary Secretary::operator+(const Professor& op2) {
    Professor* newProfessor = new Professor(op2); 
    addProfessor(newProfessor);
    writeProfessorsToFile("prof.txt");
    
    return *this;
}
Secretary Secretary::operator+(const Course& op2) {
    Course* newCourse = new Course(op2); 
    addCourse(newCourse);
    writeCoursesToFile("cour.txt");
    
    return *this;
}

void Secretary::addProfessor(Professor* professor) {
    professors.insert(professor);
}
void Secretary::addStudent(Student* student) {
    students.insert(student);
}
void Secretary::addCourse(Course* course) {
    courses.insert(course);
}

void Secretary::writeStudentsToFile(const string& filename) const {
    ofstream outputFile(filename, ios::trunc); 

    if (outputFile.is_open()) {
    	
		for (auto it = students.begin(); it != students.end(); ++it) {
            const auto& student = *it;
            outputFile << student->getName() << ", " << student->getIdNumber() << ", " << student->getCurrentSemesterNum() <<", "<< student->getAdmissionYear() << ", " << student->getEmail() << ", " << student->getPhone();

            if (next(it) != students.end()) {
                outputFile << endl;
            }
        }

        outputFile.close();
    } else {
        cerr << "Unable to open the file for writing." << endl;
    }
}
void Secretary::writeProfessorsToFile(const string& filename) const {
    ofstream outputFile(filename, ios::trunc); 

    if (outputFile.is_open()) {

        for (auto it = professors.begin(); it != professors.end(); ++it) {
            const auto& professor = *it;
            outputFile << professor->getName() << ", " << professor->getEmail() << ", " << professor->getPhone();

            if (next(it) != professors.end()) {
                outputFile << endl;
            }
        }
        
        outputFile.close();
    } else {
        cerr << "Unable to open the file for writing." << endl;
    }
}
void Secretary::writeCoursesToFile(const string& filename) const {
    ofstream outputFile(filename, ios::trunc); 

    if (outputFile.is_open()) {
		
		for (auto it = courses.begin(); it != courses.end(); ++it) {
            const auto& course = *it;
            outputFile << course->getName() << ", " << course->getEcts()<< ", " << course->isMandatory() << ", " << course->getSemester();

            if (next(it) != courses.end()) {
                outputFile << endl;
            }
        }

        outputFile.close();
    } else {
        cerr << "Unable to open the file for writing." << endl;
    }
}

void Secretary::DeleteProfessor(string name) {
	Professor* professorToDelete = GetProfessor(name);
	professors.erase(professorToDelete);
	delete professorToDelete;
    writeProfessorsToFile("prof.txt");
    return;

}
void Secretary::DeleteStudent(long long int id){
	Student* studentToDelete = GetStudent(id);
	students.erase(studentToDelete);
	delete studentToDelete;
    writeStudentsToFile("stud.txt");
    return;

}
void Secretary::DeleteCourse(string name){
	Course* courseToDelete = GetCourse(name);
	courses.erase(courseToDelete);
	delete courseToDelete;
    writeCoursesToFile("cour.txt");
    return;

}


ostream& operator<<(ostream& str, Secretary& obj) {
    str << "\n\nProfessors:\n\n";
    for (const auto& professor : obj.professors) {
        str << *professor << endl;
    }
    str << "\n\nStudents:\n\n";
    for (const auto& student : obj.students) {
        str << *student << endl;
    }
    str << "\n\nCourses:\n\n";
    for (const auto& course : obj.courses) {
        str << *course << endl;
    }
    return str;
}

istream &operator>>(istream& str, Secretary& obj){
	string filename;
	filename = "stud.txt";
	cout << "Reading data from file: " << filename << endl;

    ifstream file_stud(filename);
    if (!file_stud.is_open()) {
        cerr << "Error: Unable to open file '" << filename << "'" << endl;
        return str;
    }
    


   	while(file_stud.good()){
    	Student* s = new Student();
    	file_stud >> *s;
        obj.students.insert(s);
	}

	filename = "prof.txt";
	cout << "Reading data from file: " << filename << endl;
    ifstream file_prof(filename);
    
    if (!file_prof.is_open()) {
        cerr << "Error: Unable to open file '" << filename << "'" << endl;
        return str;
    }

    while(file_prof.good()){
    	Professor* p = new Professor();
    	file_prof >> *p;
        obj.professors.insert(p);
	}

	filename = "cour.txt";
	cout << "Reading data from file: " << filename << endl;

    ifstream file_cour(filename);
    if (!file_cour.is_open()) {
        cerr << "Error: Unable to open file '" << filename << "'" << endl;
        return str;
    }

    while(file_cour.good()){
    	Course* c = new Course();
    	file_cour >> *c;
        obj.courses.insert(c);
	}

    return str;
}


bool Secretary::FindStudent(long long int id, Secretary& secretary) {
    for (const auto& student : secretary.students) {
        if (student->getIdNumber() == id ) {
            return true;
        }
    }
    return false;
}
bool Secretary::FindProfessor(string name, Secretary& secretary) {
    for (const auto& professor : secretary.professors) {
        if (professor->getName() == name ) {
            return true;
        }
    }
    return false;
}
bool Secretary::FindCourse(string name, Secretary& secretary) {
    for (const auto& course : secretary.courses) {
        if (course->getName() == name ) {
            return true;
        }
    }
    return false;
}


Student* Secretary::GetStudent(long long int id){
	for (const auto& student : students) {
        if (student->getIdNumber() == id ) {
            return student;
        }
    }
    return nullptr;
}
Professor* Secretary::GetProfessor(string name){
	for (const auto& professor : professors) {
        if (professor->getName() == name ) {
            return professor;
        }
    }
    return nullptr;
}
Course* Secretary::GetCourse(string name){
	for (const auto& course : courses) {
        if (course->getName() == name ) {
            return course;
        }
    }
    return nullptr;
}

Secretary::Secretary(const Secretary& op2) {
	students.clear();
	professors.clear();
	courses.clear();

    for (auto student : op2.students) {
        students.insert(new Student(*student));
    }

    for (auto professor : op2.professors) {
        professors.insert(new Professor(*professor));
    }

    for (auto course : op2.courses) {
        courses.insert(new Course(*course)); 
    }

    for (auto student : op2.studentsGraduating) {
        studentsGraduating.insert(new Student(*student));
    }
}


Secretary& Secretary::operator=(const Secretary &op2) {
    if (this != &op2) {
		students.clear();
		professors.clear();
		courses.clear();
		
    	for (auto student : op2.students) {
        	students.insert(new Student(*student));
    	}

    	for (auto professor : op2.professors) {
        	professors.insert(new Professor(*professor));
    	}

    	for (auto course : op2.courses) {
        	courses.insert(new Course(*course));
    	}

    	for (auto student : op2.studentsGraduating) {
        	studentsGraduating.insert(new Student(*student)); 
    	}
	}
    return *this;
}

void Secretary::enrollStudentInCourse(Student* s, Course* cour){
	for (const auto& course : courses) {
		if (course->getName() == cour->getName()){
			Course studentCourse(cour->getName(), cour->getEcts(), cour->isMandatory(), cour->getSemester());
			Course* studCour = new Course(studentCourse);
			s->enrollInCourse(studCour);
			course->enrollStudent(s);
		}
	}
//	cour->displayEnrolledStudents();
}

void Secretary::professorTeachCourse(Professor* p, Course* cour){
	for (const auto& course : courses) {
		if (course->getName() == cour->getName()){
			p->teachCourse(course);
			course->addProfessor(p);
			cout << "Professor " << p->getName() << " is teaching " << cour->getName() << endl;
		}
	}
//	cour->displayProfessors();
}

void Secretary::displayStudentsPassed( Course* cour){
	cour->displayPassedStudents();
}

bool Secretary::graduate(Student* s) {
    return (s->getCurrentSemester()->getSemNum() >= 8 && s->getPassedMandatoryCourses() >= RequiredMandatoryCourses && s->getEctsCollected() >= RequiredEctsForGraduation);
}

void Secretary::ProfessorStats(Professor* p){
	p->profStats();
}

void Secretary::DisplayGrades(Student* s){
    s->displayGrades();

}

void Secretary::displayStudentsGraduating(){
	for (const auto& student : students) {
        if(graduate(student))
			studentsGraduating.insert(student);
    }
    if (studentsGraduating.empty()){
    	cout << "No Students are ready to Graduate.";
	}
	else{
		cout << "Students Graduating" << ":\n";
    	for (const auto& student : studentsGraduating) {
        	cout << "- " << student->getName() << "\n";
    	}
	}
}

void Secretary::assignGrades(){
	for (const auto& cour : courses) {
		cout<< "\nGrades for " << cour->getName() << endl;
		for (const auto& student : students) {	
			for (const auto& stud : cour->getStudentsEnrolled()) {
				if(stud->getName() == student->getName()){
					string filename = cour->getName() + ".txt";

					ifstream file_grades;
					file_grades.open(filename);
    
    				if (!file_grades.is_open()) {
        				cerr << "Error: Unable to open file '" << filename << "'" << endl;
    				}
					long long int id;
					float grade;
    				while(file_grades>>id){
    					file_grades.ignore();
    					file_grades>>grade;
        				if (id == student->getIdNumber()){
        					for (const auto& course : student->getCurrentSemester()->getCourses()){
								if(cour->getName() == course->getName()){
									student->takeExam(course, grade);
									cout <<course->getName()<< " "<< id << " " << grade  <<endl;
									if(grade>= 5){
        								cour->PassedStudent(student);
									}
								}	
							}
						}
					}
					file_grades.close();	
				}
			}
		}
    }	
}

void Secretary::nextSemester(){
	for (const auto& prof : professors) {
		prof->changeSem();	
	}
	for (const auto& student : students) {
		student->changeSem();
	}
}








