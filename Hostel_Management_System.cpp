#include <iostream>
using namespace std;

// Structure to store student data
struct Student {
    int id;
    string name;
    string program;
    int roomNo;
};

// Array to store records
Student students[50];
int totalStudents = 0;

// Function to add student
void addStudent() {
    if (totalStudents >= 50) {
        cout << "\nHostel record is full!\n";
        return;
    }

    cout << "\nEnter Student ID: ";
    cin >> students[totalStudents].id;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, students[totalStudents].name);

    cout << "Enter Program: ";
    getline(cin, students[totalStudents].program);

    cout << "Enter Room Number: ";
    cin >> students[totalStudents].roomNo;

    totalStudents++;
    cout << "\nStudent record added successfully!\n";
}

// Function to view all students
void viewStudents() {
    if (totalStudents == 0) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n--- Hostel Student Records ---\n";
    for (int i = 0; i < totalStudents; i++) {
        cout << "\nStudent ID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nProgram: " << students[i].program;
        cout << "\nRoom Number: " << students[i].roomNo;
        cout << "\n-----------------------------\n";
    }
}

// Function to search student by ID
void searchStudent() {
    if (totalStudents == 0) {
        cout << "\nNo records available to search.\n";
        return;
    }

    int searchId;
    cout << "\nEnter Student ID to search: ";
    cin >> searchId;

    for (int i = 0; i < totalStudents; i++) {
        if (students[i].id == searchId) {
            cout << "\nStudent Found!\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Program: " << students[i].program << endl;
            cout << "Room Number: " << students[i].roomNo << endl;
            return;
        }
    }

    cout << "\nStudent not found.\n";
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== HOSTEL MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. View All Students";
        cout << "\n3. Search Student by ID";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
