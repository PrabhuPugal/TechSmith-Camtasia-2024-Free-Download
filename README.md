# Student Management System
A comprehensive Student Management System built using C. This system utilizes heap and hash data structures to efficiently manage student records, including personal details, grades, and attendance.

## Features
1. Add, update, delete, and view student records
2. Manage student grades and attendance
3. Efficient data handling using heap and hash data structures
4. Command-line interface for easy interaction

## Installation
### Prerequisites
GCC compiler
### Steps
Clone the repository:
```
git clone https://github.com/PrabhuPugal/Student-Management-System.git
cd Student-Management-System
```
### Compile the program:
```
gcc -o student_management main.c heap.c hash_table.c -I.
```
### Run the program:
```
./student_management
```
### Usage
Once the program is running, you can use the following commands to manage student records:

1. Add Student: Add a new student record.
2. View Students: Display the list of all students and their details.
3. Update Student: Edit existing student information.
4. Delete Student: Remove a student record from the system.
5. Manage Grades and Attendance: Update and view student grades and attendance records.
6. Example Commands
Add Student:
```
add_student <student_id> <name> <age> <grade>
```
View Students:
```
view_students
```
Update Student:
```
update_student <student_id> <name> <age> <grade>
```
Delete Student:
```
delete_student <student_id>
```
Manage Grades:
update_grade <student_id> <new_grade>

Manage Attendance:
update_attendance <student_id> <attendance_percentage>
