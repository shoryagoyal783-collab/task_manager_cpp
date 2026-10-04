#include <bits/stdc++.h>
using namespace std;


    void count(int a){
        cout<<"Loaded "<<a<<" task(s) from tasks_data.txt."<<endl;
    }
    struct Task {
    string task_name;
    string notes;
    int priority;
    string deadline;
    bool completed = false;
};
    int main() {
        vector<Task> task;
vector<Task> completedTask;
        
        int a=0;
        while(1){
        cout<<"==================== Daily Task Scheduler ===================="<<endl;
        cout<<"1) Add a task"<<endl<<"2) List / search / filter tasks"<<endl<<"3) Mark complete/reopen task "<<endl<<"4) Delete a task"<<endl<<endl<<"================================================================"<<endl;

cout<<"Choose an option:";
int opt;
cin>>opt;
   
if (opt == 1) {
    Task t;

    cout << "--- Add a task ---" << endl;

    cout << "Task name (use underscores for spaces): ";
    cin >> t.task_name;

    cout << "Notes (enter 0 to skip): ";
    cin >> t.notes;

    if (t.notes == "0") {
        t.notes = "";
    }

    cout << "Priority (1=High, 2=Medium, 3=Low): ";
    cin >> t.priority;

    if (t.priority < 1 || t.priority > 3) {
        t.priority = 2;
    }

    cout << "Deadline (YYYY-MM-DD, or 0 to skip): ";
    cin >> t.deadline;

    if (t.deadline == "0") {
        t.deadline = "";
    }

    task.push_back(t);

    cout << "Task added successfully!" << endl;
    a++;
    count(a);
}


if (opt==2) {
    if (task.empty()) {
        cout << "No task" << endl;
    }

    for (int i = 0; i < task.size(); i++) {
        cout << "Task : "<< task[i].task_name << endl;
        cout << "Notes: "<< task[i].notes<< endl;

        cout << "Priority: ";
        if (task[i].priority == 1)
            cout << "High";
        else if (task[i].priority == 2)
            cout << "Medium";
        else
            cout << "Low";

        cout << endl;
        cout << "Deadline: "<< task[i].deadline<< endl;
    }
    count(a);
}


 if (opt == 3) {

    cout << "--- Mark Complete / Reopen Task ---" << endl;
    cout << "1) Mark a pending task as complete" << endl;
    cout << "2) Reopen a completed task" << endl;

    int choice;
    cin >> choice;
    if (choice == 1) {

        if (task.empty()) {
            cout << "No task" << endl;
        }
        else {
            cout << "Pending Tasks:" << endl;

            for (int i = 0; i < (int)task.size(); i++) {
                cout << i + 1 << ") "
                     << task[i].task_name << endl;
            }

            cout << "Enter task number: ";
            int num;
            cin >> num;

            if (num < 1 || num > (int)task.size()) {
                cout << "Invalid task number." << endl;
            }
            else {
                task[num - 1].completed = true;
                completedTask.push_back(task[num - 1]);
                task.erase(task.begin() + (num - 1));

                cout << "Task marked as complete!" << endl;
            }
        }
    }
    else if (choice == 2) {

        if (completedTask.empty()) {
            cout << "No task" << endl;
        }
        else {
            cout << "Completed Tasks:" << endl;

            for (int i = 0; i < (int)completedTask.size(); i++) {
                cout << i + 1 << ") "
                     << completedTask[i].task_name << endl;
            }

            cout << "Enter task number: ";
            int num;
            cin >> num;

            if (num < 1 || num > (int)completedTask.size()) {
                cout << "Invalid task number." << endl;
            }
            else {
                completedTask[num - 1].completed = false;
                task.push_back(completedTask[num - 1]);
                completedTask.erase(
                    completedTask.begin() + (num - 1)
                );

                cout << "Task reopened successfully!" << endl;
            }
        }
    }

    else {
        cout << "Invalid choice." << endl;
    
    }
    count(a);
}

if(opt==4) {
    if (task.empty()) {
        cout << "No tasks" << endl;
    }

        cout << "Enter task number to delete: ";
        int num;
        cin >> num;

        if (num < 1 || num > (int)task.size()) {
            cout << "Invalid task number." << endl;
        }
        else {
            task.erase(task.begin() + (num - 1));

            cout << "Task deleted successfully!" << endl;
        }
    }
        }}
