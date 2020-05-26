#ifndef function_h
#define funtion_h
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
struct Schedule {
	string no;
	//string classesName;
	string id;
	string name;
	string classes;
	string LecturerUsername;
	string LecturerName;
	string LecturerDegree;
	string lecturerGender;
	string startDay;
	string startMonth;
	string startYear;
	string endDay;
	string endMonth;
	string endYear;
	string DayOfWeek;
	string startHour;
	string startMinute;
	string endHour;
	string endMinute;
	string Room;

};

struct Student {
	string username;
	string password;
	string StudentName;
	string DOB;
	string gender;
	string classes;
	float final = NULL;
	float midterm = NULL;
	float total = NULL;
	float bonus = NULL;
	int status = 1;
};

struct Course {
	string id;
	string classes;
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
	//string clasname;
};


Node* createNode(Schedule s);
Node* createNodeLtr(Lecturer lecturer);
void load_file(LinkedList& lst, ifstream& fin, int& count);
void output_file(LinkedList lst, ofstream& fout);
int string_to_int(string temp);



void load_file_Student(ifstream& fin, LinkedList& lst2);
Node* create_Node_Student(Student s);
void output_file_Student_from_csv_to_txt(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst);
int day_of_month(int thang, int nam);
int day_after_1_week(int day, int thang, int nam);
bool isCheck(int nam);
//void remove_specific_student( LinkedList &lst2, LinkedList lst);
void main_schedule_from_csv_to_txt(LinkedList& lst, LinkedList& lst2);
void option_schedule(LinkedList& APCS1);/*, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10);*/


//void view_Attendence(LinkedList lst2, LinkedList lst, Node* currentlst);
void option_course(LinkedList& lst);
void load_file_schedule_txt(LinkedList& lst, ifstream& fin, int& count);
void Add_course(LinkedList& lst, int& count, Schedule& s);
void output_file_schedule_txt(LinkedList lst, ofstream& fout);
void main_add_course(LinkedList& lst, LinkedList& lst2);
void output_file_Student_Add(ofstream& fout, LinkedList lst2, Schedule s);

//edit course
void edit_course(LinkedList& lst, Node*& current1, string& inputpath, LinkedList& lst2);
void main_edit_course(LinkedList& lst, LinkedList& lst2);
void view_schedule(LinkedList lst);
void load_file_course_student(LinkedList lst2, LinkedList& lst1, string inputpath, string outputpath, Node* currentlst);
//void output_file_Student_from_csv_to_txt(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst);
//void load_file_schedule_txt(LinkedList& lst, ifstream& fin, int& count);
//void output_file_schedule_txt(LinkedList lst, ofstream& fout);
//void load_file_Student(ifstream& fin, LinkedList& lst2);
//int day_of_month(int thang, int nam);
//int day_after_1_week(int day, int thang, int nam);
//bool isCheck(int nam);
//int string_to_int(string temp);

// delete course
void delete_course(LinkedList& lst, int& count);
void main_delete_course(LinkedList& lst);
//bool DeleteFile(const char* file_path);


//void view_schedule(LinkedList lst);
//void load_file_schedule_txt(LinkedList& lst, ifstream& fin, int& count);
//void output_file_schedule_txt(LinkedList lst, ofstream& fout);
//void load_file_Student(ifstream& fin, LinkedList& lst2);
//int day_of_month(int thang, int nam);
//int day_after_1_week(int day, int thang, int nam);
//bool isCheck(int nam);
//int string_to_int(string temp);

// remove specific student
void remove_specific_student(LinkedList& lst2, LinkedList lst, string classes);
void main_remove_specific_student(LinkedList lst, LinkedList& lst2);
int string_to_int2(string temp);
// add specufuc student
void Add_specific_student(LinkedList& lst);
Node* create_Node_course_student(Student s);
Node* createNode_Course(Course c);
void load_List_Of_Course2(LinkedList& lstCourse);
void save_list_of_course(ofstream& fout, LinkedList lstCourse);
void view_List_Of_Course2(LinkedList& lstCourse);
void export_Score_Board_csv(string inputpath, string outputpath);
void main_export_Score_Board_csv();
void view_ScoreBoard2(string inputPath);
void main_View_Score_Board();
void view_Student(string inputPath);
void main_View_Student_Of_Course();
void view_3(string inputPath);
void main_View_Attendence_List_Of_Course();
void viewLecturer(LinkedList& lst);




#endif