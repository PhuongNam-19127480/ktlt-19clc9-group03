#ifndef function_h
#define funtion_h
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
struct schedule {
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
	string EndMonth;
	string EndYear;
	
	string Dayofweek;
	string starthour;
	string startminute;
	string endhour;
	string endminute;
	string Room;

};

//struct node {
//	schedule data;
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

void outputfile(schedule s,ofstream &fout);

struct student {
	string studentID;
	string studentPass;
	string studentName;
	string studentDOB;
	string studentGender;
	float final = NULL;
	float midterm = NULL;
	float total = NULL;
	float bonus = NULL;
};

struct Node {
	student data;
	Node* next;
};

struct LinkedList {
	Node* head;
	Node* tail;
};



void load_file_student(ifstream& fin, LinkedList& lst2);
int string_to_int(string temp);
Node* create_Node_student(student s);
void output_file_student(ofstream& fout,LinkedList lst2,schedule s);
int day_of_month(int thang, int nam);
int day_after_1_week(int day, int thang, int nam);
bool isCheck(int nam);

#endif;