#ifndef SECRETARY_H
#define SECRETARY_H

#include <iostream>
#include <string>
#include <iterator>
#include <set>
#include <fstream>
#include <sstream>


#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"

#define RequiredMandatoryCourses 18
#define RequiredEctsForGraduation 240

using namespace std;

struct StudentComparator {
    bool operator()(const Student* s1, const Student* s2) const {
        return s1->getIdNumber() < s2->getIdNumber();
    }
};

struct ProfessorComparator {
    bool operator()(const Professor* p1, const Professor* p2) const {
        if (p1->getName() == p2->getName()) {
            return p1->getPhone() < p2->getPhone();
        }
        return p1->getName() < p2->getName();
    }
};

struct CourseComparator {
    bool operator()(const Course* c1, const Course* c2) const {
        return c1->getName() < c2->getName();
    }
};


class Secretary {
           set<Student*, StudentComparator> students;
           set<Professor*, ProfessorComparator> professors;
           set<Course*, CourseComparator> courses;
           set<Student*, StudentComparator> studentsGraduating;

    public:
    	 
        Secretary();
        ~Secretary();
        
        Secretary operator+(const Person& op2);
        Secretary operator+(const Student& op2);
        Secretary operator+(const Professor& op2);
        Secretary operator+(const Course& op2);
        
        void addProfessor(Professor* professor);
        void addStudent(Student* student);
        void addCourse(Course* course);
        
        void writeStudentsToFile(const string& filename) const;
        void writeProfessorsToFile(const string& filename) const;
        void writeCoursesToFile(const string& filename) const;
        
        void DeleteProfessor(string name);
        void DeleteStudent(long long int id);
        void DeleteCourse(string name);
        
        bool FindStudent(long long int id, Secretary& secretary);
        bool FindProfessor(string name, Secretary& secretary);
        bool FindCourse(string name, Secretary& secretary);
        
        Student* GetStudent(long long int id);
        Professor* GetProfessor(string name);
        Course* GetCourse(string name);
        
        friend ostream& operator<<(ostream& str, Secretary& obj);
        friend istream& operator>>(istream& str, Secretary& obj);

        Secretary(const Secretary &s);
        Secretary& operator=(const Secretary &op2);
        
        void enrollStudentInCourse(Student* s, Course* cour);
        void professorTeachCourse(Professor* p, Course* cour);
        
        void PassStudentInCourse(Course* cour);
        void displayStudentsPassed( Course* cour);
        
        void ProfessorStats(Professor* p);
        
        void DisplayGrades(Student* s);
        
        bool graduate(Student* s);
        void displayStudentsGraduating();
        
        void assignGrades();
        
        void nextSemester();
        
};

#endif
