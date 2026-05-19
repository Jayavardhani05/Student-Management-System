#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;


class Student {
private:
    int id;
    string name;
    int age;
    string course;

public:
  
    Student(int i = 0, string n = "", int a = 0, string c = "") {
        id = i;
        name = n;
        age = a;
        course = c;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getCourse() const { return course; }

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setCourse(string c) { course = c; }

    void displayRow() const {
        cout << left << setw(10) << id 
             << setw(25) << name 
             << setw(8) << age 
             << setw(20) << course << endl;
    }
};

class StudentManager {
private:
    const string filename = "students.txt";

   
    void clearInputBuffer() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
   
    void addStudent() {
        int id, age;
        string name, course;

        cout << "\n--- Add New Student ---\n";
        cout << "Enter Student ID (Integer): ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter a valid integer ID: ";
            clearInputBuffer();
        }
        clearInputBuffer(); 

        if (idExists(id)) {
            cout << "Error: A student with ID " << id << " already exists!\n";
            return;
        }

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        while (!(cin >> age) || age <= 0) {
            cout << "Invalid age. Enter a realistic number: ";
            clearInputBuffer();
        }
        clearInputBuffer();

        cout << "Enter Course: ";
        getline(cin, course);

        ofstream outFile(filename, ios::app);
        if (!outFile) {
            cout << "Error opening file for writing!\n";
            return;
        }

      
        outFile << id << "," << name << "," << age << "," << course << "\n";
        outFile.close();

        cout << "Student record added successfully!\n";
    }


    bool idExists(int searchId) {
        ifstream inFile(filename);
        if (!inFile) return false;

        string line;
        while (getline(inFile, line)) {
            size_t pos1 = line.find(',');
            if (pos1 != string::npos) {
                int id = stoi(line.substr(0, pos1));
                if (id == searchId) {
                    inFile.close();
                    return true;
                }
            }
        }
        inFile.close();
        return false;
    }


    void displayAll() {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "\nNo records found or file does not exist yet.\n";
            return;
        }

        cout << "\n---------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(8) << "Age" << setw(20) << "Course" << endl;
        cout << "---------------------------------------------------------------\n";

        string line;
        bool hasRecords = false;

        while (getline(inFile, line)) {
            hasRecords = true;
            parseAndDisplayLine(line);
        }
        inFile.close();

        if (!hasRecords) {
            cout << "The database is currently empty.\n";
        }
        cout << "---------------------------------------------------------------\n";
    }


    void parseAndDisplayLine(const string& line) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
            int id = stoi(line.substr(0, pos1));
            string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            int age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
            string course = line.substr(pos3 + 1);

            Student temp(id, name, age, course);
            temp.displayRow();
        }
    }


    void updateStudent() {
        int searchId;
        cout << "\nEnter Student ID to update: ";
        if (!(cin >> searchId)) {
            clearInputBuffer();
            cout << "Invalid ID entered.\n";
            return;
        }
        clearInputBuffer();

        ifstream inFile(filename);
        ofstream tempFile("temp.txt");

        if (!inFile) {
            cout << "Database file not found.\n";
            return;
        }

        string line;
        bool found = false;

        while (getline(inFile, line)) {
            size_t pos1 = line.find(',');
            int id = stoi(line.substr(0, pos1));

            if (id == searchId) {
                found = true;
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);
                
                string name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                int age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                string course = line.substr(pos3 + 1);

                cout << "\nCurrent Details:\n";
                cout << "Name: " << name << " | Age: " << age << " | Course: " << course << "\n\n";

                cout << "Enter New Name (or press Enter to keep current): ";
                string newName;
                getline(cin, newName);
                if (newName.empty()) newName = name;

                cout << "Enter New Age (or 0 to keep current): ";
                int newAge;
                while (!(cin >> newAge) || newAge < 0) {
                    cout << "Invalid entry. Enter age: ";
                    clearInputBuffer();
                }
                clearInputBuffer();
                if (newAge == 0) newAge = age;

                cout << "Enter New Course (or press Enter to keep current): ";
                string newCourse;
                getline(cin, newCourse);
                if (newCourse.empty()) newCourse = course;

        
                tempFile << id << "," << newName << "," << newAge << "," << newCourse << "\n";
            } else {
          
                tempFile << line << "\n";
            }
        }

        inFile.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        if (found) cout << "Record updated successfully!\n";
        else cout << "Record with ID " << searchId << " not found.\n";
    }


    void deleteStudent() {
        int searchId;
        cout << "\nEnter Student ID to delete: ";
        if (!(cin >> searchId)) {
            clearInputBuffer();
            cout << "Invalid ID entered.\n";
            return;
        }
        clearInputBuffer();

        ifstream inFile(filename);
        ofstream tempFile("temp.txt");

        if (!inFile) {
            cout << "Database file not found.\n";
            return;
        }

        string line;
        bool found = false;

        while (getline(inFile, line)) {
            size_t pos1 = line.find(',');
            int id = stoi(line.substr(0, pos1));

           
            if (id == searchId) {
                found = true;
            } else {
                tempFile << line << "\n";
            }
        }

        inFile.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp.txt", filename.c_str());

        if (found) cout << "Record deleted successfully!\n";
        else cout << "Record with ID " << searchId << " not found.\n";
    }
};


int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "     STUDENT MANAGEMENT SYSTEM      \n";
        cout << "====================================\n";
        cout << "1. Add New Student Record\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Update Student Record\n";
        cout << "4. Delete Student Record\n";
        cout << "5. Exit\n";
        cout << "------------------------------------\n";
        cout << "Enter your choice (1-5): ";
        
        if (!(cin >> choice)) {
            cout << "Invalid entry. Please pick a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.updateStudent(); break;
            case 4: manager.deleteStudent(); break;
            case 5: cout << "\nExiting system. Goodbye!\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}