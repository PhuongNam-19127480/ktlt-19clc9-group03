#ifndef function_h
#define funtion_h
#include <iostream>
#include <fstream>
#include<string>
#include<string.h>
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
	float  final =NULL;
	float midterm = NULL;
	float total = NULL;
	float bonus = NULL;
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
void output_file_Student(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst);
int day_of_month(int thang, int nam);
int day_after_1_week(int day, int thang, int nam);
bool isCheck(int nam);
void view(LinkedList lst2, LinkedList lst, Node* currentlst);
void view_Attendence_List_Of_Course(LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View, string Class, string inputpath);
void export_Attendence(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst, string inputpath);
void export_Attendence_list_Of_Course(ofstream& fout, LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View, string& outputpath, string Class, string& inputpath);
void view_List_Of_Course(LinkedList lst);
void view_List_Student_Of_Course(LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View);
void view_2(string inputpath, LinkedList &lst2, LinkedList lst, Node* currentlst);
void edit_Attendence(ofstream& fout, string inputpath, string outputpath, LinkedList& lst2, LinkedList lst, Node* currentlst, string studentID_edit, int year_edit, int month_edit, int day_edit, int attend);
void edit_Attendence_Of_Course(ofstream& fout, LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View, string Class, string& studentID_edit, int& year_edit, int& month_edit, int& day_edit, int& attend);
#endif