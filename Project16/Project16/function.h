#ifndef function_h
#define funtion_h
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
struct Schedule {
	string No;
	string courseID;
	string courseName;
	string classs;
	string LecturerUsername;
	string LecturerName;
	string LecturerDegree;
	string lecturerGender;
	string startDay;
	string startMonth;
	string startYear;
	string EndDay;
	string Endmonth;
	string EndYear;
	string Dayofweek;
	string starthour;
	string startminute;
	string endhour;
	string endminute;
	string Room;

};

struct Student {
	string StudentID;
	string StudentPass;
	string StudentName;
	string StudentDOB;
	string StudentGender;
	float final = NULL;
	float midterm = NULL;
	float total = NULL;
	float bonus = NULL;
	int status = 1;
};

struct Node {
	Schedule schedule;
	Student student;
	Node* next;
};

struct LinkedList {
	Node* head;
	Node* tail;
};

Node* createNode(Schedule s);
void load_file_schedule_txt(LinkedList& lst, ifstream& fin, int& count);
void edit_course(LinkedList& lst);
void delete_course(LinkedList& lst,int &count);
void output_file_schedule_txt(LinkedList lst, ofstream& fout);
void view_schedule(LinkedList lst);
void main_delete_course();
void main_edit_course();
void load_file_Student(ifstream& fin, LinkedList& lst2);
void output_file_Student(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst);
int day_of_month(int thang, int nam);
int day_after_1_week(int day, int thang, int nam);
bool isCheck(int nam);
int string_to_int(string temp);

#endif