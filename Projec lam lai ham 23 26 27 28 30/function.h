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
struct Course {
	string courseID;
	string classs;
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
struct Lecturer {
	string username;
	string password;
	string fullname;
	string degree;
	int gender;
	int order;
};
struct Node {
	Schedule schedule;
	Student student;
	Lecturer lecturer;
	Course course;
	Node* next;
};

struct LinkedList {
	Node* head;
	Node* tail;
};

Node* createNode(Schedule s);
Node* createNodeLtr(Lecturer lecturer);
int string_to_int(string temp);
Node* create_Node_Student(Student s);

int day_of_month(int thang, int nam);
int day_after_1_week(int day, int thang, int nam);
bool isCheck(int nam);
void view_Attendence_List_Of_Course(LinkedList lst, LinkedList lst2);
void export_Attendence(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst, string inputPath);
void  export_Attendence_list_Of_Course(LinkedList lst, LinkedList lst2);
void view_List_Of_Course(LinkedList lst);
void view_List_Student_Of_Course(LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View);
void view_2(string inputPath, LinkedList &lst2, LinkedList lst, Node* currentlst);
void edit_Attendence(ofstream& fout, string inputPath, string outputpath, LinkedList& lst2, LinkedList lst, Node* currentlst, string studentID_edit, int year_edit, int month_edit, int day_edit, int attend);
void edit_Attendence_Of_Course(ofstream& fout, LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View, string Class, string& studentID_edit, int& year_edit, int& month_edit, int& day_edit, int& attend);
void import_Scoreboard(string inputPath, string outputpath, LinkedList& lst2, LinkedList lst, Node* currentlst);
void import_Scoreboard_Of_Course(LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View, string Class, string& inputPath);
void view_Scoreboard(string inputPath, LinkedList& lst2, LinkedList lst, Node* currentlst);
void view_Scoreboard_Of_Course(LinkedList lst, LinkedList lst2, string Class);
void edit_Grade(string inputPath, LinkedList& lst2, LinkedList lst, Node* currentlst, string studentID_View);
void edit_Grade_Of_a_Student(LinkedList lst, LinkedList lst2, string Class);
void export_Grade(string inputPath, string outputpath, LinkedList& lst2, LinkedList lst, Node* currentlst);
void export_Grade_Of_Course(LinkedList lst, LinkedList lst2, string Class);
void viewLecturer(LinkedList lst);
Node* createNode_Course(Course course);
void view_List_Of_Course2(LinkedList& lstCourse);
void main_View_Attendence_List_Of_Course();
void view_3(string inputPath);
void export_3(string inputPath, string outputpath);
void main_Export_Attendence_csv_File();
void main_View_Student_Of_Course();
void view_Student(string inputPath);
void edit_Attendence2(string inputPath);
void main_Edit_Attendence();
void import_Score_Board2(string inputPath);
void main_import_ScoreBoard();
void edit_Grade2(string inputPath);
void main_Edit_Grade();
void view_ScoreBoard2(string inputPath);
void main_View_Score_Board();
void option_Lecturer();
#endif