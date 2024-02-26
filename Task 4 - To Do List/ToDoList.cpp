#include <bits/stdc++.h>
using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
}

void viewTasks(const vector<Task>& tasks) {
    cout << "Tasks:\n";
    for (const Task& task : tasks) {
        cout << (task.completed ? "Completed-":"[Pending]-") << task.description << endl;
    }
}

void markCompleted(vector<Task>& tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

void removeTask(vector<Task>& tasks, int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "\n-----------------------------------\n";
        cout << "To-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        
        if (choice == 1){
            cout << "Enter task description: ";
            cin.ignore();
            string info;
            getline(cin, info);
            addTask(tasks, info);
        }
                
        else if(choice == 2){
            viewTasks(tasks);
        }
            
        else if (choice == 3){
            cout << "Enter task index to mark as completed: ";
            int index;
            cin >> index;
            markCompleted(tasks, index);
        }
            
        else if (choice == 4){
            int index;
            cout << "Enter task index to remove : ";
            cin >> index;
            removeTask(tasks, index);
        }
            
        else if (choice == 5){
            cout << "Thanks for using! Visit again.\n";
            return 0;
        }

        else{
            cout << "Invalid choice! Please try again.";
        }
    }

    return 0;
}
