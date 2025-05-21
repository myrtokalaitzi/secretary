#include <iostream>
#include <fstream>
#include <sstream>
#include "Secretary.h"



int main() {
    Secretary secretary;
	
	cin >> secretary;
	cout << secretary;
	
    int choice;
    do {
        
        bool ChoiceInputValid = false;
    	while (!ChoiceInputValid) {
	        cout << "\nMenu:\n";
	        cout << "1. Add/Modify/Delete Professor\n";
	        cout << "2. Add/Modify/Delete Student\n";
	        cout << "3. Add/Modify/Delete Course\n";
	        cout << "4. Assign Professors to a Course\n";
	        cout << "5. Enroll Student in a Course\n";
	        cout << "6. Print Students who Passed a Course\n";
	        cout << "7. Print Semester Statistics for a Professor\n";
	        cout << "8. Print Detailed Grades for a Student\n";
	        cout << "9. Print Students Eligible for Graduation\n";
	        cout << "10. Assign Grades\n";
	        cout << "11. Change Semester\n";
	        cout << "0. Exit\n";
	        cout << "Enter your choice: ";
	    	if (cin >> choice) {
				ChoiceInputValid = true;
				
		        switch (choice) {
		            case 1: {
		            	cout << "\nMenu:\n";
		        		cout << "1. Add Professor\n";
		        		cout << "2. Modify Professor\n";
		        		cout << "3. Delete Professor\n";
		        		cout << "0. Exit\n";
		        		
		        		cout << "Enter your choice: ";
		    	    	cin >> choice;
		
		        		switch (choice) {
		            		case 1: {
		                		// Add Professor
		                		Professor professor;
		                		cin.sync();
		                		cin >> professor;
								secretary = secretary + professor;
		                		
		                		break;
		                	}
		                	case 2: {
		                		// Modify Professor
		                		cout << "\nEnter Professor Surname and Name to modify: ";
		                		string profName;
		                		cin.sync();
		                		getline(cin, profName);
		                		cin.sync();
		                		if (secretary.FindProfessor(profName, secretary) ){
		                			
		                			string newName;
		                			string newEmail;
		                			long long int newPhone;
		                			
		                			cout << "New Surname and Name: ";
		                			getline(cin, newName);
		                			cin.sync();
		                			
		                			cout << "New Email: ";
		                			getline(cin, newEmail);
		                			cin.sync();
		                			
		                			bool phoneInputValid = false;
		    						while (!phoneInputValid) {
		    	    					cout << "New Phone number: ";
		    	    					if (cin >> newPhone && newPhone >= 1000000000 && newPhone<=9999999999) {
		        	    					phoneInputValid = true;
		        						} else {
		        	    					cout << "Invalid input. Please enter a valid phone number." << endl;
		        	    					cin.clear();
		        	    					while (cin.get() != '\n');
		        	    				}
		    						}
		                			
		                			secretary.GetProfessor(profName)->setName(newName);
		                			secretary.GetProfessor(newName)->setEmail(newEmail);
		                			secretary.GetProfessor(newName)->setPhone(newPhone);
		                			secretary.writeProfessorsToFile("prof.txt");
								}
								else {
									cout << "\nNo match for this Professor \n";
								}
		                
		                		break;
		                	}
		                	case 3: {
		                		// Delete Professor
		                		cout << "\nEnter Professor Surname and Name to delete: ";
		                		string profName;
		                		cin.sync();
		                		getline(cin, profName);
		                		cin.sync();
		                		if (secretary.FindProfessor(profName, secretary) ){
		                			secretary.DeleteProfessor(profName);
		                			cout << "Professor " << profName << " Deleted succesfully\n";
		                		}
								else {
									cout << "\nNo match for this Professor \n";
								}
		                		break;
		                	}
		                	case 0: {
		                		// Exit the program
		                		cout << "Exiting program.\n";
		                		break;
		            		}
		            		default:
		                		cout << "Invalid choice. Please enter a valid choice.\n";
		                }
		            	break;
		            }
		            case 2: {
		                cout << "\nMenu:\n";
		        		cout << "1. Add Student\n";
		        		cout << "2. Modify Student\n";
		        		cout << "3. Delete Student\n";
		        		cout << "0. Exit\n";
		        		
		        		cout << "Enter your choice: ";
		    	    	cin >> choice;
		        		
		        		switch (choice) {
		            		case 1: {
		                		// Add Student
		                		Student student;
		                		cin >> student;
		                		secretary = secretary + student;
		                		break;
		                	}
		                	case 2: {
		                		// Modify Student
		                		cout << "\nEnter Student ID Number to modify: ";
		                		long long int id;
		                		cin.sync();
		                		cin >> id;
		                		cin.sync();
		                		if (secretary.FindStudent(id, secretary) ){
		                			string newName;
		                			long long int newId;
		                			int newAdmissionYear;
		                			string newEmail;
		                			long long int newPhone;
		                			
		                			cout << "New Surname and Name: ";
		                			getline(cin, newName);
		                			cin.sync();
		                			
		                			bool idInputValid = false;
		    						while (!idInputValid) {
		    	    					cout << "New ID Number: ";
		    	    					if (cin >> newId) {
		        	    					idInputValid = true;
		        						} else {
		        	    					cout << "Invalid input. Please enter a valid ID Number." << endl;
		        	    					cin.clear();
		        	    					while (cin.get() != '\n');
		        	    				}
		    						}
		                			
		                			bool adYearInputValid = false;
		    						while (!adYearInputValid) {
		    	    					cout << "New Admission Year: ";
		    	    					if (cin >> newAdmissionYear && newAdmissionYear >= 2016 && newAdmissionYear<=2023) {
		        	    					adYearInputValid = true;
		        						} else {
		        	    					cout << "Invalid input. Please enter a valid Admission Year." << endl;
		        	    					cin.clear();
		        	    					while (cin.get() != '\n');
		        	    				}
		    						}
		                			cin.sync();
		                			cout << "New Email: ";
		                			getline(cin, newEmail);
		                			cin.sync();
		                			
		                			bool phoneInputValid = false;
		    						while (!phoneInputValid) {
		    	    					cout << "New Phone number: ";
		    	    					if (cin >> newPhone && newPhone >= 1000000000 && newPhone<=9999999999) {
		        	    					phoneInputValid = true;
		        						} else {
		        	    					cout << "Invalid input. Please enter a valid phone number." << endl;
		        	    					cin.clear();
		        	    					while (cin.get() != '\n');
		        	    				}
		    						}
		                			
		                			secretary.GetStudent(id)->setIdNumber(newId);
		                			secretary.GetStudent(newId)->setName(newName);
		                			secretary.GetStudent(newId)->setAdmissionYear(newAdmissionYear);
		                			secretary.GetStudent(newId)->setEmail(newEmail);
		                			secretary.GetStudent(newId)->setPhone(newPhone);
		                			secretary.writeStudentsToFile("stud.txt");
								}
								else {
									cout << "\nNo match for this Student \n";
								}
		                		break;
		                	}
		                	case 3: {
		                		// Delete Student
		                		cout << "\nEnter Student ID Number to delete: ";
		                		long long int id;
		                		cin.sync();
		                		cin >> id;
		                		cin.sync();
		                		if (secretary.FindStudent(id, secretary) ){
		                			secretary.DeleteStudent(id);
		                			cout << "Student with ID Number " << id << " Deleted succesfully\n";
		                		}
								else {
									cout << "\nNo match for this Student \n";
								}
		                		break;
		                	}
		                	case 0: {
		                		// Exit the program
		                		cout << "Exiting program.\n";
		                		break;
		            		}
		            		default:
		                		cout << "Invalid choice. Please enter a valid choice.\n";
		            	}
		                break;
		            }
		            case 3: {
		                cout << "\nMenu:\n";
		        		cout << "1. Add Course\n";
		        		cout << "2. Modify Course\n";
		        		cout << "3. Delete Course\n";
		        		cout << "0. Exit\n";
		        		
		        		cout << "Enter your choice: ";
		    	    	cin >> choice;
		        		
		        		switch (choice) {
		            		case 1: {
		                		// Add Course
		                		Course course;
		                		cin >> course;
		                		secretary = secretary + course;
		                		break;
		                	}
		                	case 2: {
		                		// Modify Course
		                		cout << "\nEnter Course Name to modify: ";
		                		string courName;
		                		cin.sync();
		                		getline(cin, courName);
		                		cin.sync();
		                		if (secretary.FindCourse(courName, secretary) ){
		                			
		                			string newName;
		                			int newECTS;
		                			bool newMandatory;
		                			int newSemester;
		                			
		                			cout << "New Name: ";
		                			getline(cin, newName);
		                			cin.sync();
		                			
		                			bool ectsInputValid = false;
		    						while (!ectsInputValid) {
		    	    					cout << "New Ects: ";
		    	    					if (cin >> newECTS && newECTS >= 2 && newECTS <= 8) {
		        	    					ectsInputValid = true;
		        						} else {
		        	    					cout << "Invalid input. Please enter valid Ects." << endl;
		        	    					cin.clear();
		        	    					while (cin.get() != '\n');
		        	    				}
		    						}
		                			
		                			cout << "Is Mandatory?(0/1): ";
		                			cin >> newMandatory;
		                			cin.sync();
		                			
		                			bool semInputValid = false;
		    						while (!semInputValid) {
		    	    					cout << "New Semester: ";
		    	    					if (cin >> newSemester && newSemester > 0 && newSemester <= 8) {
		        	    					semInputValid = true;
		        						} else {
		        	    					cout << "Invalid input. Please enter a valid Semester." << endl;
		        	    					cin.clear();
		        	    					while (cin.get() != '\n');
		        	    				}
		    						}
		                			
		                			secretary.GetCourse(courName)->setName(newName);
		                			secretary.GetCourse(newName)->setECTS(newECTS);
		                			secretary.GetCourse(newName)->setECTS(newMandatory);
		                			secretary.GetCourse(newName)->setSemester(newSemester);
		                			secretary.writeCoursesToFile("cour.txt");
								}
								else {
									cout << "\nNo match for this Professor \n";
								}
		                		break;
		                	}
		                	case 3: {
		                		// Delete Course
		                		cout << "\nEnter Course Name to delete: ";
		                		string courName;
		                		cin.sync();
		                		getline(cin, courName);
		                		cin.sync();
		                		if (secretary.FindCourse(courName, secretary) ){
		                			secretary.DeleteCourse(courName);
		                			cout << "Course " << courName << " Deleted succesfully\n";
		                		}
		                		else {
									cout << "\nNo match for this Professor \n";
								}
		                		break;
		                	}
		                	case 0: {
		                		// Exit the program
		                		cout << "Exiting program.\n";
		                		break;
		            		}
		            		default:
		                		cout << "Invalid choice. Please enter a valid choice.\n";		
		            	}
		                break;
		            }
		            case 4: {
		                // Assign Professors to a Course
		                cout << "\nEnter Professor Surname and Name: ";
		                string profName;
		                cin.sync();
		                getline(cin, profName);
		                cout << "Enter Course Name: ";
		                string courName;
		                cin.sync();
		                getline(cin, courName);
		                if (secretary.FindProfessor(profName, secretary) && secretary.FindCourse(courName, secretary)){
		                	secretary.professorTeachCourse(secretary.GetProfessor(profName), secretary.GetCourse(courName));
						}
						else {
							cout << "\nNo match for Professor or Course\n";
						}
		                break;
		            }
		            case 5: {
		                // Enroll Student in a Course
		                long long int id;
		                bool idInputValid = false;
		    			while (!idInputValid) {
		    	    		cout << "\nEnter Student ID Number: ";
		    	    		if (cin >> id) {
		        	    		idInputValid = true;
		        			} else {
		        	    		cout << "Invalid input. Please enter a valid ID Number." << endl;
		        	    		cin.clear();
		        	    		while (cin.get() != '\n');
		        	    	}
		    			}
		                
		                cout << "Enter Course Name: ";
		                string courName;
		                cin.sync();
		                getline(cin, courName);
		                if (secretary.FindStudent(id, secretary) && secretary.FindCourse(courName, secretary)){
		                	secretary.enrollStudentInCourse(secretary.GetStudent(id), secretary.GetCourse(courName));
						}
						else {
							cout << "\nNo match for Student or Course\n";
						}
		                break;
		            }
		            case 6: {
		                // Print Students who Passed a Course
		                cout << "\nEnter Course Name: ";
		                cin.sync();
		                string courName;
		                getline(cin, courName);
		                
		                if (secretary.FindCourse(courName, secretary)){
							Course* coursee = secretary.GetCourse(courName);
		                	secretary.displayStudentsPassed(coursee);
						}
						else {
							cout << "\nNo match for Course\n";
						}
		                break;
		            }
		            case 7: {
		                // Print Semester Statistics for a Professor
		            	cout << "\nEnter Professor Name: ";
		                cin.sync();
		                string profName;
		                getline(cin, profName);
		                
		                if (secretary.FindProfessor(profName, secretary)){
		            		Professor* prof = secretary.GetProfessor(profName);
		                	secretary.ProfessorStats(prof);
						}
						else {
							cout << "\nNo match for this Professor\n";
						}
		
		                break;
		            }
		            case 8: {
		            	//Print Grades of a Student
		                long long int id;
		                bool idInputValid = false;
		    			while (!idInputValid) {
		    	    		cout << "\nEnter Student id: ";
		    	    		if (cin >> id) {
		        	    		idInputValid = true;
		        			} else {
		        	    		cout << "Invalid input. Please enter a valid ID Number." << endl;
		        	    		cin.clear();
		        	    		while (cin.get() != '\n');
		        	    	}
		    			}
		    			
		                if (secretary.FindStudent(id, secretary)){
		                	Student* s = secretary.GetStudent(id);
		                	secretary.DisplayGrades(s);
		            	}
		
						else {
							cout << "\nNo match for this Student ID\n";
						}
		                break;
		            }
		            case 9: {
		                // Print Students Eligible for Graduation
		                secretary.displayStudentsGraduating();
		                break;
		            }
		            case 10: {
		                secretary.assignGrades();
		                break;
		            }
		            case 11: {
		                secretary.nextSemester();
		                break;
		            }
		            case 0: {
		                // Exit the program
		                cout << "Exiting program.\n";
		                break;
		            }
		            default:
		                cout << "Invalid choice. Please enter a valid choice.\n";
		        }
			} else {
		        cout << "Invalid input. Please enter a valid choice." << endl;
		        cin.clear();
		    	while (cin.get() != '\n');
		    }
	    }
    } while (choice != 0);
    cout << secretary;
    return 0;
}

