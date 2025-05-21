#include "Student.h"
#include "Course.h"
#include "Semester.h"

using namespace std;

//Constructors
Student::Student() : Person(), idNumber(0), admissionYear(0), ectsCollected(0), passedMandatoryCourses(0) {
	currentSemester = new Semester();
	previousSemesters = new Semester();

}
Student::Student(const string& name, const string& email, long long int phone, long long int idNumber, int admissionYear, int semesterNum, int ectsCollected, int passedMandatoryCourses): 
Person(name, email, phone), idNumber(idNumber), admissionYear(admissionYear), ectsCollected(ectsCollected), passedMandatoryCourses(passedMandatoryCourses) {
	currentSemester = new Semester(semesterNum);
	previousSemesters = new Semester(semesterNum);
}
//Destructor
Student::~Student(){
	delete currentSemester;
	delete previousSemesters;
}

//Mutators
void Student::setEctsCollected(int ec){
	ectsCollected = ec;
}
void Student::setIdNumber(long long int id){
	idNumber = id;
}
void Student::setAdmissionYear(int ay){
	admissionYear = ay;
}
void Student::setPassedMandatoryCourses(int pmc){
	passedMandatoryCourses = pmc;
}

//Accesors
long long int Student::getIdNumber() const{
	return idNumber;
}
int Student::getAdmissionYear() const{
	return admissionYear;
}
int Student::getCurrentSemesterNum() const{
	return currentSemester->getSemNum();
}
int Student::getEctsCollected() const{
	return ectsCollected;
}
int Student::getPassedMandatoryCourses() const{
	return passedMandatoryCourses;
}
Semester* Student::getCurrentSemester() const{
	return currentSemester;
}

ostream &operator<<(ostream &str, const Student &obj){
    str << "Name: " << obj.name << endl;
    str << "ID Number: " << obj.idNumber << endl;
    str << "Admission Year: " << obj.admissionYear << endl;    
    str << "Email: " << obj.email << endl;
    str << "Phone Number: " << obj.phone << endl;
//    str << "Current Semester: " << obj.currentSemester->getSemNum() << endl;
//    str << "ECTS Collected: " << obj.ectsCollected << endl;
//    str << "Passed Mandatory Courses: " << obj.passedMandatoryCourses << endl;
    
    return str;
}

istream &operator>>(istream &str, Student &obj){
	if (str.rdbuf() == cin.rdbuf()) {
        // Reading from console
    	cout << "Give Surname and Name: ";
    	str.ignore();
    	getline(str, obj.name);
    	
		bool idNumberInputValid = false;
    	while (!idNumberInputValid) {
        	cout << "Give ID Number: ";
        	try{
        		if (str >> obj.idNumber) {
            		idNumberInputValid = true;
        		} else {
            		throw(obj.idNumber);
            	}
        	}
        	catch(long long int idNumber){
				cout << "Invalid input. Please enter a valid ID Number." << endl;
            	str.clear();
            	while (str.get() != '\n');
			}
    	}

    	bool admissionYearInputValid = false;
    	while (!admissionYearInputValid) {
        	cout << "Give Admission Year: ";
        	try{
        		if (str >> obj.admissionYear && obj.admissionYear >= 2016 && obj.admissionYear < 2024) {
        	    	admissionYearInputValid = true;
        		} else {
	        	    throw(obj.admissionYear);
        	    }
        	}
        	catch(int admissionYear){
				cout << "Invalid input. Please enter a valid Admission Year." << endl;
            	str.clear();
            	while (str.get() != '\n');
			}
    	}

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
				cout << "Invalid input. Please enter a valid phone number." << endl;
            	str.clear();
            	while (str.get() != '\n');
			}
    	}
	}else {
        // Reading from file
        int num;
        string line;
		getline(str, line);
        stringstream ss(line);
        
        getline(ss, obj.name, ',');
        
        ss >> obj.idNumber;
        ss.ignore();
        
        ss >> num;
        obj.currentSemester->setSemNum(num);
		ss.ignore();
		
        ss >> obj.admissionYear;
        ss.ignore();
        
        getline(ss >> ws, obj.email, ',');
        
        ss >> obj.phone;
	}
    return str;
}


void Student::enrollInCourse(Course* course) const{
	if (course->getSemester() <= 0 || course->getSemester() > 8){
    	cerr << "Invalid semester number" << endl;		
	} else if (course->getSemester() <= currentSemester->getSemNum()) {
        currentSemester->addCourse(course);
        cout << "Enrolled in course: " << course->getName() << endl;
    } else {
        cerr << "Cannot enroll in this course" << endl;
    }
}

void Student::displayCurrentSemesterCourses() const {
	cout << "Courses in current Semester \n" ;
    currentSemester->displayCourses();
}

	
void Student::takeExam( Course* course, float grade) {
	for (const auto& cour : currentSemester->getCourses()) {
        if(cour->getName() == course->getName()){
        	cour->setGrade(grade);
		}
    }
    if (grade >= 5){
    	ectsCollected += course->getEcts();
        if(course->isMandatory()){
        passedMandatoryCourses++;
		}
	}
}

void Student::displayGrades(){
	cout << "\nGrades of "<<idNumber <<endl ;
	
	for (const auto& cour : previousSemesters->getCourses()) {
        cout<<"- "<<cour->getName()<<": "<<cour->getGrade()<<endl;
    }
	for (const auto& cour : currentSemester->getCourses()) {
        cout<<"- "<<cour->getName()<<": "<<cour->getGrade()<<endl;
        
    }
    cout << "Total ECTS Collected: " << ectsCollected << endl;
    cout << "Total Mandatory Courses Passed: " << passedMandatoryCourses << endl;
}


void Student::changeSem(){
	//cout<< name << ": " << currentSemester->getSemNum() << endl;
	
	for (const auto& cour : currentSemester->getCourses()) {
        previousSemesters->addCourse(cour);
    }
    currentSemester->changeSemester();
    
}



