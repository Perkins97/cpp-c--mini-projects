#include <iostream>
#include <vector>
using namespace std;

void taskUpdate(vector<string>& tasks, vector<string>& taskDates, vector<string>& taskTimes,string newTask, string newDate, string newTime) {
    char updateChoice;

            cout << "Do you want to update previously added tasks ?" << "Y / N" << endl;
            cin >> updateChoice;
    if (tasks.empty()) {
            cout << "No tasks to update." << endl;
        return;
    }
    if (updateChoice == 'Y' || updateChoice == 'y') {
        int taskNum;

            cout << "Select task to update" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }

        cout << "Select task number :" ;
        cin >> taskNum;
        cin.ignore();

         if (taskNum >= 1 || taskNum < tasks.size()) {
            cout << "Enter new task :"  ;
            getline(cin, newTask);
            tasks[taskNum - 1] = newTask;

            cout << "Enter new date (e.g. DD/MM/YYYY) : ";
            getline(cin, newDate);
             taskDates[taskNum - 1] = newDate;

             cout << "Enter new time (e.g. HH:MM) : ";
             getline(cin, newTime);
             taskTimes[taskNum - 1] = newTime;

         }

    }

}

void taskDelete(vector<string>& tasks, vector<string>& taskDates, vector<string>& taskTimes) {
    cout << "== TASK HISTORY ==" << endl;
    int deleteChoice;
    char confirm;
    if (tasks.empty()) {
        cout << "No tasks available to delete" << endl;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
        cout << "Select a task to delete :" ;
        cin >> deleteChoice;
    if (deleteChoice < 1 || deleteChoice > tasks.size()) {
        cout << "Invalid task number " << endl;
        return;
    }
        cout << "Do you want to delete previously added tasks ?" << "Y / N" << endl;
        cin >> confirm;
        if (confirm == 'Y' || confirm == 'y' ) {
            tasks.erase (tasks.begin() + (deleteChoice -1));
            taskDates.erase(taskDates.begin() + (deleteChoice -1));
            taskTimes.erase(taskTimes.begin() + (deleteChoice -1));
            cout << "Task Has Been Successfully Deleted " << '\n';
         }
        else {
            cout << "Deletion cancelled. THANK YOU" << endl;
        }
    }



int main() {
 int choice;
    char subChoice;

    string taskDate, task, taskTime;
    vector <string> tasks, taskDates, taskTimes;


    do {
        cout << "== TO-DO LIST DASHBOARD ==" << endl;
        cout << "1. Create New Tasks " << endl;
        cout << "2. View Previously Added Tasks " << endl;
        cout << "3. Update  Tasks " << endl;
        cout << "4. Delete Tasks " << endl;
        cout << "5.Exit " << endl;

        cin >> choice;
        if (choice == 1 ) {

            cout << "Enter task :"  ;
            cin.ignore();
            getline(cin, task);
            tasks.push_back(task);

            cout << "Enter task date (DD/MM/YYYY) :"  ;
            cin >> taskDate;
            taskDates.push_back(taskDate);

            cout << "Enter task time (HH:MM) :"  ;
            cin >> taskTime;
            taskTimes.push_back(taskTime);

            cout << "Task Added Successfully" << endl;
//IF USER WANTS TO ADD MULTIPLE TASK
        do {
            cout << "Add another task ?" << endl;
            cout <<"(Y / N )" << endl;
            cin >> subChoice;

            if (subChoice == 'Y' || subChoice == 'y') {
                cout << "Enter task :"  ;
                cin.ignore();
                getline(cin, task);
                tasks.push_back(task);
                cout << "Enter task date  (DD/MM/YYYY) :"  ;
                cin >> taskDate;
                cout << "Enter task time  (HH:MM) :"  ;
                cin >> taskTime;
                taskDates.push_back(taskDate);
                taskTimes.push_back(taskTime);
            }
            else {
                cout << "All Tasks Added Successfully" << endl;
            }
        }while (subChoice == 'Y' || subChoice == 'y');

        }
        else if (choice == 2) {
            cout << "== TASK  HISTORY ==" << endl;
            cout << "Task Name " <<" ||  " << "Task Date & Time " << endl;
            for (int i = 0; i < tasks.size(); i++) {
                cout << i + 1 << ". "<< tasks[i] << " |" << taskDates[i]<< " |" << taskTimes[i] << endl;
            }

        }
        else if (choice == 3) {
             cout << "== CURRENT TASKS ==" << endl;
            taskUpdate(tasks, taskDates,taskTimes,task,taskDate,taskTime);
        }
        else if (choice == 4) {
            taskDelete(tasks, taskDates,taskTimes);
        }


    }while (choice != 5);



}
