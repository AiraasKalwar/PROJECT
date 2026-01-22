#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <string>

using namespace std;

/* ========== ANSI COLORS ========== */
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

/* ========== ANIMATION UTILITIES ========== */
void typingEffect(const string &text, int delay = 40) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

void spinner(const string &msg, int durationMs = 1200) {
    const char spin[] = {'|', '/', '-', '\\'};
    cout << CYAN << msg << " ";
    int steps = durationMs / 100;
    for (int i = 0; i < steps; i++) {
        cout << spin[i % 4] << '\r' << msg << " ";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << RESET << endl;
}

void progressBar(const string &msg) {
    cout << CYAN << msg << endl << "[";
    for (int i = 0; i < 30; i++) {
        cout << "█" << flush;
        this_thread::sleep_for(chrono::milliseconds(35));
    }
    cout << "] ✔" << RESET << endl;
}

/* ================= HEADER ================= */
void printHeader() {
    cout << CYAN;
    typingEffect("Initializing Core Modules...");
    spinner("Loading Student Registry");
    spinner("Connecting Room Allocation Engine");
    cout << RESET;

    cout << BLUE << BOLD << R"(

>>======================================<<
||   █▓▒░ HOSTEL MANAGEMENT SYSTEM ░▒▓█   ||
>>======================================<<

)" << RESET;

    typingEffect(">> Boot Sequence Complete <<", 50);
}

/* ================= DATA STRUCTURE ================= */
struct Student {
    int id;
    string name;
    string program;
    int roomNo;
};

Student students[50];
int totalStudents = 0;

/* ================= ADD STUDENT ================= */
void addStudent() {
    if (totalStudents >= 50) {
        cout << RED << "\nHostel is full!\n" << RESET;
        return;
    }

    cout << YELLOW << "\n--- Add Student Record ---\n" << RESET;

    cout << "Enter Student ID: ";
    cin >> students[totalStudents].id;
    cin.ignore();

    cout << "Enter Student Name: ";
    getline(cin, students[totalStudents].name);

    cout << "Enter Program: ";
    getline(cin, students[totalStudents].program);

    cout << "Enter Room Number: ";
    cin >> students[totalStudents].roomNo;

    spinner("Saving record");
    totalStudents++;

    cout << GREEN << "✔ Student added successfully!\n" << RESET;
}

/* ================= VIEW STUDENTS ================= */
void viewStudents() {
    if (totalStudents == 0) {
        cout << RED << "\nNo student records found.\n" << RESET;
        return;
    }

    cout << BLUE << "\n--- Hostel Student Records ---\n" << RESET;
    cout << BOLD
         << left << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(20) << "Program"
         << setw(10) << "Room\n"
         << RESET;
    cout << string(65, '-') << "\n";

    for (int i = 0; i < totalStudents; i++) {
        cout << left
             << setw(10) << students[i].id
             << setw(25) << students[i].name
             << setw(20) << students[i].program
             << setw(10) << students[i].roomNo << "\n";
    }
}

/* ================= SEARCH STUDENT ================= */
void searchStudent() {
    if (totalStudents == 0) {
        cout << RED << "\nNo records available.\n" << RESET;
        return;
    }

    int searchId;
    cout << YELLOW << "\nEnter Student ID to search: " << RESET;
    cin >> searchId;

    progressBar("Searching database");

    for (int i = 0; i < totalStudents; i++) {
        if (students[i].id == searchId) {
            cout << GREEN << "\n✔ Student Found!\n" << RESET;
            cout << "Name    : " << students[i].name << "\n";
            cout << "Program : " << students[i].program << "\n";
            cout << "Room No : " << students[i].roomNo << "\n";
            return;
        }
    }

    cout << RED << "\n✘ Student not found.\n" << RESET;
}

/* ================= EXIT ANIMATION ================= */
void exitAnimation() {
    cout << RED;
    typingEffect("\nShutting down system...");
    spinner("Saving data");
    spinner("Releasing memory");
    progressBar("System shutdown");
    cout << GREEN << "\n✔ Goodbye! System closed safely.\n" << RESET;
}

/* ================= MAIN ================= */
int main() {
    int choice;
    printHeader();

    do {
        cout << YELLOW << "\n===== MENU =====\n" << RESET;
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: exitAnimation(); break;
            default:
                cout << RED << "\nInvalid choice! Try again.\n" << RESET;
        }

    } while (choice != 4);

    return 0;
}
