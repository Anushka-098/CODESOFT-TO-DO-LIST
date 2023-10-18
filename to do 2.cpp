#include <iostream>
#include <string>

const int MaxTasks = 100; 

struct Task {
    std::string description;
    bool completed;

    Task() : description(""), completed(false) {}

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    Task tasks[MaxTasks];
    int numTasks;

public:
    ToDoList() : numTasks(0) {}

    void addTask(const std::string& description) {
        if (numTasks < MaxTasks) {
            tasks[numTasks] = Task(description);
            numTasks++;
            std::cout << "Task added: " << description << std::endl;
        } else {
            std::cout << "To-Do list is full" << std::endl;
        }
    }

    void viewTasks() {
        if (numTasks == 0) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "To-Do List:" << std::endl;
            for (int i = 0; i < numTasks; i++) {
                std::cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << std::endl;
            }
        }
    }

    void markTaskAsCompleted(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= numTasks) {
            tasks[taskIndex - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[taskIndex - 1].description << std::endl;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }

    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= numTasks) {
            std::cout << "Removed task: " << tasks[taskIndex - 1].description << std::endl;
            for (int i = taskIndex - 1; i < numTasks - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            numTasks--;
        } else {
            std::cout << "Invalid task number." << std::endl;
        }
    }
};

int main() {
    ToDoList toDoList;
    while (true) {
        std::cout << "Options:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();  
                std::cout << "Enter task description: ";
                std::string description;
                getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> taskIndex;
                toDoList.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter the task number to remove: ";
                std::cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }

    return 0;
}

