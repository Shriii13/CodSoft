#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task

struct Task {
    string description;
    bool completed;

    //description of task
   
    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask(description);
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description;
          
          //for showing completion
           
            if (tasks[i].completed) {
                cout << " [Completed]";
            } else {
                cout << " [Pending]";
            }
            cout << endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Marked task " << index << " as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

//removal of task

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task " << index << " removed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDesc;
    size_t taskIndex;

    while (true) {
        cout << "\n============= TO-DO LIST ==============" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // Ignore newline character from previous input
                getline(cin, taskDesc);
                todoList.addTask(taskDesc);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                todoList.markTaskCompleted(taskIndex);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}