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
	string Endmonth;
	string EndYear;
	string Dayofweek;
	string starthour;
	string startminute;
	string endhour;
	string endminute;
	string Room;

};

struct node {
	schedule data;
	node* next;
};





struct list {
	node* head;
	node* tail;
};

node* createNode(schedule s);
void load_file(list& lst, ifstream& fin,int &count);
void output_file(list lst, ofstream& fout);
int string_to_int(string temp);

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
Node* create_Node_student(student s);
void output_file_student(ofstream& fout, LinkedList lst2,list lst,node*currentlst);
int day_of_month(int thang,int nam);
int day_after_1_week(int day,int thang,int nam);
bool isCheck(int nam);


void view_Attendence(LinkedList lst2, list lst, node* currentlst);
	

#endif