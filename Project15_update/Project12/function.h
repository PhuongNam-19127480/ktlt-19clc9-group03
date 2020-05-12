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

//struct node {
//	Schedule data;
//	node* next;
//};
//
//
//
//
//
//struct list {
//	node* head;
//	node* tail;
//};

void outputfile(Schedule s,ofstream &fout);

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
};

struct Node {
	Student student;
	Schedule schedule;
	Node* next;
};

struct LinkedList {
	Node* head;
	Node* tail;
};



void load_file_Student(ifstream& fin, LinkedList& lst2);
int string_to_int(string temp);
Node* create_Node_Student(Student s);
void output_file_Student_Add(ofstream& fout,LinkedList lst2,Schedule s);
int day_of_month(int thang, int nam);
int day_after_1_week(int day, int thang, int nam);
bool isCheck(int nam);
void load_file_schedule_txt(LinkedList& lst, ifstream& fin, int& count);
Node* createNode(Schedule s);
void Add_course(LinkedList& lst,int &count,Schedule &s);
void output_file_schedule_txt(LinkedList lst, ofstream& fout);
void main_add_course();




#endif;