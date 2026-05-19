# Student Management System 



---

# 1. Introduction

The **Student Management System** is a console-based application developed using **C++**.
The main objective of this project is to manage student records efficiently using file handling techniques.

This system allows users to:

* Add new student records
* Display all student records
* Update existing student details
* Delete student records
* Store data permanently using text files

The project demonstrates the practical implementation of:

* Object-Oriented Programming (OOP)
* File Handling
* Data Validation
* Menu Driven Programs
* CRUD Operations

---

# 2. Objective of the Project

The objectives of this project are:

* To create a simple student database management system
* To understand file handling in C++
* To perform CRUD operations
* To improve programming logic using classes and objects
* To build a beginner-friendly real-world console application

---

# 3. Technologies Used

| Technology                 | Purpose                            |
| -------------------------- | ---------------------------------- |
| C++                        | Core Programming Language          |
| File Handling              | Store and retrieve student records |
| OOP Concepts               | Encapsulation using classes        |
| Text File (`students.txt`) | Database storage                   |

---

# 4. Features of the System

## 4.1 Add Student Record

* User enters:

  * Student ID
  * Name
  * Age
  * Course
* Data is stored in `students.txt`
* Duplicate IDs are prevented

---

## 4.2 Display All Records

* Reads data from the file
* Displays records in tabular format

Example:

| ID  | Name  | Age | Course  |
| --- | ----- | --- | ------- |
| 101 | Rahul | 20  | CSE     |
| 102 | Priya | 19  | AI & DS |

---

## 4.3 Update Student Record

* Searches record using Student ID
* Allows modification of:

  * Name
  * Age
  * Course

---

## 4.4 Delete Student Record

* Deletes student details using Student ID
* Remaining records are preserved

---

## 4.5 Input Validation

The program validates:

* Invalid numeric inputs
* Negative ages
* Duplicate IDs

---

# 5. System Architecture

```text
+-----------------------+
|   User Input Menu     |
+-----------------------+
            |
            v
+-----------------------+
|  StudentManager Class |
+-----------------------+
   |     |      |     |
   v     v      v     v
 Add  Display Update Delete
   |
   v
students.txt File
```

---

# 6. Explanation of Classes

## 6.1 Student Class

The `Student` class represents individual student records.

### Data Members

```cpp
int id;
string name;
int age;
string course;
```

### Functions

| Function     | Purpose                  |
| ------------ | ------------------------ |
| getId()      | Returns ID               |
| getName()    | Returns Name             |
| getAge()     | Returns Age              |
| getCourse()  | Returns Course           |
| setName()    | Updates Name             |
| setAge()     | Updates Age              |
| setCourse()  | Updates Course           |
| displayRow() | Displays student details |

---

## 6.2 StudentManager Class

Handles all operations related to file management.

### Functions

| Function              | Purpose                     |
| --------------------- | --------------------------- |
| addStudent()          | Adds new student            |
| displayAll()          | Displays all records        |
| updateStudent()       | Updates record              |
| deleteStudent()       | Deletes record              |
| idExists()            | Checks duplicate IDs        |
| parseAndDisplayLine() | Reads and formats file data |

---

# 7. File Handling Used

The system uses:

## Writing to File

```cpp
ofstream outFile(filename, ios::app);
```

## Reading from File

```cpp
ifstream inFile(filename);
```

## Temporary File for Update/Delete

```cpp
ofstream tempFile("temp.txt");
```

---

# 8. Program Workflow

## Step 1

Display Main Menu

## Step 2

User selects operation

## Step 3

Program performs requested operation

## Step 4

Data saved into file

## Step 5

Program returns to menu

---

# 9. Sample Input and Output

## Main Menu

```text
====================================
     STUDENT MANAGEMENT SYSTEM
====================================
1. Add New Student Record
2. Display All Student Records
3. Update Student Record
4. Delete Student Record
5. Exit
```

---

## Add Student Example

```text
Enter Student ID: 101
Enter Name: Rahul
Enter Age: 20
Enter Course: CSE

Student record added successfully!
```

---

## Display Records Example

```text
ID        Name                     Age     Course
-------------------------------------------------------
101       Rahul                    20      CSE
102       Priya                    19      AI & DS
```

---

# 10. Advantages of the Project

* Easy to use
* Beginner friendly
* Demonstrates real-world CRUD operations
* Permanent storage using files
* Proper input validation
* Clean menu-driven interface

---

# 11. Limitations

* Uses text file instead of database
* No graphical user interface
* Data encryption is not implemented
* Single-user application

---

# 12. Future Enhancements

Future improvements that can be added:

## 12.1 Database Integration

Replace text files with:

* MySQL
* MongoDB
* SQLite

---

## 12.2 GUI Interface

Develop graphical interface using:

* Qt
* C++ GUI libraries

---

## 12.3 Search Functionality

Add:

* Search by Name
* Search by Course
* Search by Age

---

## 12.4 Authentication System

Add:

* Admin Login
* Password Protection

---

## 12.5 Sorting and Filtering

Enable:

* Sort by ID
* Sort by Name
* Filter by Course

---

## 12.6 Export Features

Export data into:

* PDF
* Excel
* CSV

---

# 13. GitHub Commands

## Clone Repository

```bash
git clone <repository-url>
```

Example:

```bash
git clone https://github.com/username/student-management-system.git
```

---

## Navigate to Project Folder

```bash
cd student-management-system
```

---

## Compile the Program

### Using g++

```bash
g++ main.cpp -o student
```

---

## Run the Program

### Windows

```bash
student.exe
```

### Linux / Mac

```bash
./student
```

---

# 14. Commands to Upload to GitHub

## Initialize Git

```bash
git init
```

---

## Add Files

```bash
git add .
```

---

## Commit Files

```bash
git commit -m "Initial commit"
```

---

## Connect Remote Repository

```bash
git remote add origin https://github.com/username/student-management-system.git
```

---

## Push to GitHub

```bash
git branch -M main
git push -u origin main
```

---

# 15. Screenshots Section

##  Main Menu

<img width="467" height="245" alt="image" src="https://github.com/user-attachments/assets/4426c9f2-d936-4833-828b-e4505d27e952" />


---

## Add Student

<img width="448" height="208" alt="image" src="https://github.com/user-attachments/assets/39282e88-d5f5-472c-b4b6-47769140578a" />


---

## Display Records

<img width="825" height="401" alt="image" src="https://github.com/user-attachments/assets/b0004bf7-a0f4-4fde-b77b-f05788c43d9a" />

---

# 16. Conclusion

The **Student Management System** project successfully demonstrates the implementation of file handling and object-oriented programming concepts in C++.

The project provides a simple and efficient way to manage student records using CRUD operations. It is highly suitable for beginners to understand real-world application development using C++.

This project can be further enhanced with databases, GUI integration, authentication, and advanced search functionalities.

---

# 17. Folder Structure

```text
Student-Management-System/
│
├── main.cpp
├── students.txt
├── README.md
└── screenshots/
    ├── menu.png
    ├── add.png
    ├── display.png
    ├── update.png
    └── delete.png
```

---

# 18. README.md Short Description

```md
A simple Student Management System built using C++ and File Handling.
The project supports Add, Display, Update, and Delete operations using text file storage.
```
