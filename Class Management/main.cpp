#include <iostream>
using namespace std;

class Student {
public:
    string studentName;
    string studentId, studentRefNum;
    double scores[7];

    void adminMenu () {
        int choice;

        do {
            cout << "=== ADMINISTRATOR DASHBOARD===" << endl;
            cout << "1. Register New Student" << endl;
            cout << "2. View Student Academic Records" << endl;
            cout << "3. Update Student's records / information" << endl;
            cout << "4. Exit" << endl;
            cin >> choice;
            cin.ignore();

            //when user selects Option 1
            if (choice == 1) {
                cout << "STUDENT'S INFO " << endl;
                cout << "Student's Full Name :" ;
                getline(cin, studentName);
                cout << "Student's Index Number :" ;
                cin >> studentId;
                cout << "Student's Reference Number :" ;
                cin >> studentRefNum;
                studScores();
            }
            else if (choice == 2) {
                cout << "=== STUDENT RECORDS ===" << endl;
                studDetails();
                averageScore();
                totalScore();
            }
            else if (choice == 3) {
                int subChoice;

            do {
                cout << "===Update Student's Info===" << endl;
                cout << "1) Update Name" << endl;
                cout << "2) Update Index Number and Reference Number" << endl;
                cout << "3) Update Exam Scores" << endl;
                cout << "4) BACK" << endl;
                cin >> subChoice;

                if (subChoice == 1) {
                    cout << "Enter new name :" ;
                    cin.ignore();
                    getline(cin, studentName);
                    cout << "Name Updated Successfully" << endl;

                }
                else if (subChoice == 2) {

                    cout << "New index number :" ;
                    cin >> studentId;
                    cout << "New reference number :" ;
                    cin >> studentRefNum;
                    cout << "Successfully Updated" << endl;
                }
                else if (subChoice == 3) {
                    cout << " New exam Scores" << endl;
                    for (int i = 0; i < 7; i++) {
                        cout <<"Enter Score " <<" "<< i + 1 <<" :"<< endl;
                        cin >> scores[i];
                    }
                }
            }while (subChoice !=4);

            }
        }while (choice != 4);
    }

    void studScores() {
        for (int i = 0; i < 7; i++) {
            cout <<"Enter Score " <<" "<< i + 1 <<" :" ;
            cin >> scores[i];
        }
    }

    //Average Score Calculation
    void averageScore() {
       double sum = 0;
        for (int i = 0; i < 7; i++) {
            sum += scores[i];
        }
        double studAverage = sum / 7;
        cout << "Average :" << studAverage << endl;
    }

    void totalScore() {
        double studTotalScores = 0;
        for (int i = 0; i < 7; i++) {
            studTotalScores += scores[i];
        }
        cout << "Total Score :" << studTotalScores << endl;
    }

    void studDetails () {
        cout << "Student's Full Name :" << studentName << endl;
        cout << "Student's Index Number :" << studentId << endl;
        cout << "Student's Reference Number :" << studentRefNum << endl;
    }

    void studentInfoUpdate () {
        double newScores[7];
        cout << "Enter New Score :" << endl;
        for (int i = 0; i < 7; i++) {
            cin >> newScores[i];
        }
    }
};






int main() {

    Student studentOne[10];
    studentOne[].adminMenu();



    return 0;
}