#ifndef _S_
#define _S_

#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

struct StudentFromCSV {
	string No;
	string ID;
	string Lastname;
	string Firstname;
	string Gender;
	string Day;
	string Month;
	string Year;
	string DoB;
	string Password;
};

struct Subjects {
	string name;
	Subjects* next;
};

struct Classes {
	string name;
	Subjects* next;
};

struct Staff {
	string username, name, password, gender;
};

struct Lecturer {
	string username, name, password, degree, gender;
};

struct CheckIn {
	//Name
	string name;
	//Day
	int startDay, startMonth, startYear; //start

	//Hour, Minutes
	int startHour, startMinute; //start
	int endHour, endMinute; //end

	//check
	int check;
	CheckIn* next;
};

struct Student {
	//Node Student
	string username, name, password, DOB, classes, gender;
	//Score
	float midterm = NULL, final = NULL, bonus = NULL, total = NULL;
	//check in
	CheckIn* checkIn;
	//active
	string active;
};

struct Schedule {
	//Node courses
	string no, courseId, courseName, classes;
	//Node lecturers
	Lecturer lecturer;

	//Day
	string startDay, startMonth, startYear; //start
	string endDay, endMonth, endYear; //end

	//Hour, Minutes
	string startHour, startMinute; //start
	string endHour, endMinute; //end

	//??
	string DayOfWeek;
	//Room
	string Room;
	Schedule* next;
};

struct Time {
	int seconds, minutes, hours, days, months, years;
};

struct Node {
	Staff staff; //1
	Lecturer lecturer; //2
	Student student; //3
	Schedule schedule; //4
	Classes classes; //5
	StudentFromCSV Info; //6
	Node* next;
	int type;
	//type Staff:0, Lecturer:1 -> cmt after struct is type
	//the type of empty list is -1
};

struct LinkedList {
	Node* head;
	Node* tail;
	int count;
	string ClassName;
};

void menuClass(Node user);
Node* CreateNodeThien(string No, string ID, string Lastname, string Firstname, string Gender, string Day, string Month, string Year);
void LoadStudent(ifstream& finput, LinkedList& Stu);
void Load_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2);
void InsertStudent(LinkedList& Stu);
void EditStudent(LinkedList& Stu);
void Delete_Student(LinkedList& Class);
void SaveStudentFile(LinkedList Stu);
void OuputStudentList(LinkedList Stu);
void Insert_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2);
void Edit_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2);
void View_Class_List(LinkedList CLC1, LinkedList CLC2, LinkedList CLC3, LinkedList CLC4, LinkedList CLC5, LinkedList CLC6, LinkedList CLC7, LinkedList CLC8, LinkedList CLC9, LinkedList CLC10, LinkedList APCS1, LinkedList APCS2);
void View_Student_List_Option(LinkedList CLC1, LinkedList CLC2, LinkedList CLC3, LinkedList CLC4, LinkedList CLC5, LinkedList CLC6, LinkedList CLC7, LinkedList CLC8, LinkedList CLC9, LinkedList CLC10, LinkedList APCS1, LinkedList APCS2);
void Delete_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2);
void Change_Class_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2);
void Add_Student_To_Class(LinkedList& Stu, LinkedList TempList);
void Delete_Student_From_Class(LinkedList& Class, LinkedList& TempList);

#endif