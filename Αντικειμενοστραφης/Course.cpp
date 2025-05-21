#include "Course.h"
#include "Semester.h"

using namespace std;

// Constructor
Course::Course() : name("0"), ects(0), mandatory(0), semester(0) {
	
}
Course::Course(const string& name, int ects, bool mandatory, int semester)
    : name(name), ects(ects), mandatory(mandatory), semester(semester){
	
	}

// Destructor
Course::~Course() {
	for (Professor* professor : professorsTeaching) {
        delete professor;
    }

    // Cleanup dynamically allocated memory for enrolledStudents
    for (Student* student : enrolledStudents) {
        delete student;
    }

    // Cleanup dynamically allocated memory for studentsPassed
    for (Student* student : studentsPassed) {
        delete student;
    }
}

//Mutators
void Course::setName(string n){
	name = n;
}
void Course::setECTS(int Ects){
	ects = Ects;
}
void Course::setSemester(int sem){
	semester = sem;
}
void Course::setMandatory(bool t){
	mandatory = t;
}
void Course::setGrade(float g){
	grade = g;
}

//Accesors
string Course::getName() const {
        return name;
}
int Course::getEcts() const {
        return ects;
}
bool Course::isMandatory() const {
        return mandatory;
}
int Course::getSemester() const {
        return semester;
}
float Course::getGrade() const{
	return grade;
}
const vector<Professor*>& Course::getProfessors() const {
    return professorsTeaching;
}
const vector<Student*>& Course::getStudentsEnrolled() const {
    return enrolledStudents;
}
const vector<Student*>& Course::getStudentsPassed() const {
    return studentsPassed;
}

ostream &operator<<(ostream &str, const Course &obj){
    str << "Name of the course: " << obj.name << endl;
    str << "ECTS of the course: " << obj.ects << endl;
    str << "Semester of the course: " << obj.semester << endl;
   
    return str;
}
istream &operator>>(istream &str, Course &obj){
	if (str.rdbuf() == cin.rdbuf()) {
    	// Reading from console
  		cout << "Give the Name of the course: ";
    	str.ignore();
    	getline(str, obj.name);
   
    	bool ectsInputValid = false;
    	while (!ectsInputValid) {
        	cout << "Give the ECTS of the course: ";
        	try{
        		if (str >> obj.ects && obj.ects >= 2 && obj.ects <= 8) {
            		ectsInputValid = true;
        		} else {
            		throw(obj.ects);
            	}
        	}
            catch(int ects){
				cout << "Invalid input. Please enter valid ECTS." << endl;
            	str.clear();
            	while (str.get() != '\n');
			}
    	}
    	bool mandatoryInputValid = false;
    	while (!mandatoryInputValid) {
        	cout << "Is the course mandatory? (0/1): ";
        	try{
        		if (str >> obj.mandatory) {
            		mandatoryInputValid = true;
        		} else {
            		throw(obj.mandatory);
            	}
        	}
        	catch(int mandatory){
				cout << "Invalid input. Please enter 0 or 1." << endl;
            	str.clear();
            	while (str.get() != '\n');
			}
    	}
    	bool semInputValid = false;
        while (!semInputValid) {
        	cout << "Enter number of semester: ";
        	try{
				if (str >> obj.semester) {
            		semInputValid = true;
        		} else {
        			throw (obj.semester);
				}
			}
			catch(int semester){
				cout << "Invalid input. Please enter a valid Semester." << endl;
            	str.clear();
            	while (str.get() != '\n');
//            	cout << "You entered: " << obj.semester << endl;
			}
    	}
    	
	}else {
        // Reading from file
        string line;
		getline(str, line);
        stringstream ss(line);
        getline(ss, obj.name, ',');
        ss >> obj.ects;
        ss.ignore();
        ss >> obj.mandatory;
        ss.ignore();
        ss >> obj.semester;
        
	}
    return str;
}   	

Course::Course(const Course& other) {
    name = other.name;
    ects = other.ects;
    mandatory = other.mandatory;
    semester = other.semester;
    grade = other.grade;
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {
        name = other.name;
    	ects = other.ects;
    	mandatory = other.mandatory;
    	semester = other.semester;
    	grade = other.grade;
    }
    return *this;
}
    	
void Course::enrollStudent(Student* student) {
	if (semester <= student->getCurrentSemester()->getSemNum())
    	enrolledStudents.push_back(student);
}

void Course::displayEnrolledStudents() const {
	if (enrolledStudents.empty()){
		cout << "No students enrolled in this course ";
	} else {
    	cout << "Enrolled Students for " << name << ":\n";
    	for (const auto& student : enrolledStudents) {
        	cout << "- " << student->getName() << "\n";
    	}
    }
}

void Course::PassedStudent(Student* student) {
    studentsPassed.push_back(student);
}

void Course::displayPassedStudents() const {
	if (studentsPassed.empty()){
		cout << "No students have passed this course ";
	} else {
		string filename = "Students Passed " + name;
    	fstream file(filename, ios::out | ios::app );	
    	cout << "Students Passed " << name << ":\n";
    	for (const auto& student : studentsPassed) {
        	cout << "- " << student->getName() << "\n";
        	file << student->getIdNumber()<<endl;
    	}
    }
}

void Course::addProfessor(Professor* professor){
	professorsTeaching.push_back(professor);
}
void Course::displayProfessors() const{
	if (professorsTeaching.empty()){
		cout << "No Professor teaching this course ";
	} else {
		cout << "Professors for " << name << ":\n";
    	for (const auto& professor : professorsTeaching) {
        	cout << "- " << professor->getName() << "\n";
    	}
	}
	
}

void Course::displayStudents(){
	for (const auto& student : enrolledStudents) {
        cout << ". " << student->getName() <<"  "<< student << "\n";
    }
	
}





