#ifndef _SS_
#define _SS_

#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include <iomanip>
#include <ctime>
using namespace std;

struct Staff {
	string username, name, password, gender;
};

struct Lecturer {
	string username, name, password, degree, gender;
};

struct CheckIn {
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
	CheckIn *checkIn;
};

struct Time {
	int seconds, minutes, hours, days, months, years;

};

struct Schedule {
	//Node courses
	string no, id, name, classes;
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
};

struct Node {
	Staff staff; //1
	Lecturer lecturer; //2
	Student student; //3
	Schedule schedule; //4
	Node* next;
	int type;
	//type Staff:0, Lecturer:1 -> cmt after struct is type
	//the type of empty list is -1
};

struct LinkedList {
	Node *head;
	Node *tail;
};

//Read File
Node* createNode();

void readStaffFile(LinkedList& list);

void readLecturerFile(LinkedList& list);

void readStudentFile(LinkedList& list);

void loadStaff(fstream& fin, LinkedList& list);

void loadLecturer(fstream& fin, LinkedList& list);

void loadStudent(fstream& fin, LinkedList& list);

//write
void write(LinkedList list, Node& user);

void save(fstream& fout, LinkedList list, Node user);

//Login
int checkLogin(string username, string password, Node &user, LinkedList list);

Node login();

//Menu
void menuLogin();

void menuFunction(Node user);

void menuShow(Node user);

void menuStudent(Node user);

void menuLecturer(Node user);

void menuStaff(Node user);

//View profile
string gender(Node user);

void viewProfile(Node user);

//Change password
void saveNewPassword(LinkedList& list, Node& user);

void changePassword(Node& user);

//Student function
CheckIn* createCheckIn();

void displayStudent(LinkedList& list);

	//Check in
	tm currentDateTime();

	void saveCheckIn(LinkedList& list, Node& user);

	void checkIn(Node& user);

	void viewCheckIn(Node user);

	void viewSchedules(Node user);

	void viewScore(Node user);

#endif

