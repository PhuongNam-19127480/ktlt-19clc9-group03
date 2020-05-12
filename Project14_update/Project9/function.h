#ifndef function_h
#define funtion_h
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
struct Schedule {
	string No;
	//string className;
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
void load_file(LinkedList& lst, ifstream& fin, int& count);
void output_file(LinkedList lst, ofstream& fout);
int string_to_int(string temp);



void load_file_Student(ifstream& fin, LinkedList& lst2);
Node* create_Node_Student(Student s);
void output_file_Student_from_csv_to_txt(ofstream& fout, LinkedList lst2,LinkedList lst,Node*currentlst);
int day_of_month(int thang,int nam);
int day_after_1_week(int day,int thang,int nam);
bool isCheck(int nam);
//void remove_specific_student( LinkedList &lst2, LinkedList lst);
void main_schedule_from_csv_to_txt(LinkedList &lst, LinkedList &lst2);
void option_schedule(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10);


//void view_Attendence(LinkedList lst2, LinkedList lst, Node* currentlst);
void option_course(LinkedList& lst);
void load_file_schedule_txt(LinkedList& lst, ifstream& fin, int& count);
void Add_course(LinkedList& lst, int& count, Schedule& s);
void output_file_schedule_txt(LinkedList lst, ofstream& fout);
void main_add_course(LinkedList &lst,LinkedList &lst2);
void output_file_Student_Add(ofstream& fout, LinkedList lst2, Schedule s);

#endif