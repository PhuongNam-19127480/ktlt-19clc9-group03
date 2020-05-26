#ifndef _SS_
#define _SS_

#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

struct Semester
{
	int n = 0;
	char Semesters[11];
	char academic[20];
};

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
	Subjects *next;
};

struct Staff {
	string username, name, password, gender;
};

struct Lecturer {
	string username, name, password, degree, gender;
	int order;
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
	CheckIn *checkIn;
	//active
	int status = 1;
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
	//lecturer
	string LecturerUsername;
	string LecturerName;
	string LecturerDegree;
	string lecturerGender;

	//??
	string DayOfWeek;
	//Room
	string Room;
	Schedule *next;
};

struct Time {
	int seconds, minutes, hours, days, months, years;
};

struct Course {
	string id;
	string classes;
};

struct Node {
	Staff staff; //1
	Lecturer lecturer; //2
	Student student; //3
	Schedule schedule; //4
	Classes classes; //5
	StudentFromCSV Info; //6
	Course course; //7
	Semester data;
	Node* next;
	int type;
	//type Staff:0, Lecturer:1 -> cmt after struct is type
	//the type of empty list is -1
};

struct LinkedList {
	Node *head;
	Node *tail;
	int count;
	string ClassName;
};

//Read File
Node* createNode();

void loadStaff(fstream& fin, LinkedList& list);

void readStaffFile(LinkedList& list);

void loadLecturer(fstream& fin, LinkedList& list);

void readLecturerFile(LinkedList& list);



//write
void save(ofstream& fout, LinkedList list, Node user);

void write(LinkedList list, Node user);

//Login
int checkLogin(string username, string password, Node &user, LinkedList list);

Node login();

//Menu
void menuLogin();

void menuFunction(Node user);

void menuShow(Node user);

void menuStudent(Node user);

//View profile
string gender(Node user);

void viewProfile(Node user);

//Change password
void saveNewPassword(LinkedList& list, Node& user);

void changePassword(Node& user);

//Student function
void loadStudent(ifstream& fin, LinkedList& list);

void readStudentFile(LinkedList& list);

void saveCheckIn(ofstream& fout, LinkedList studentList);

void readCheckIn(string path, LinkedList studentList);

CheckIn* createCheckIn();

	//Check in
	tm currentDateTime();

	void saveCheckIn(LinkedList& list, Node& user);

	int isCheckIn(LinkedList& studentList, Node user);

	void checkIn(Node user);

	void viewCheckIn(Node user);

	void viewSchedules(Node user);

	void viewScore(Node user);

//Thien
void menuStaff(Node user);
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

//Anh An
Node* createNodeAnh(Schedule s);
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
void menuLecturer(LinkedList& APCS1);

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

// delete course
void delete_course(LinkedList& lst, int& count);
void main_delete_course(LinkedList& lst);
void remove_specific_student(LinkedList& lst2, LinkedList lst, string classes);
void main_remove_specific_student(LinkedList lst, LinkedList& lst2);
int string_to_int2(string temp);
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
//Bonus
Node* createNoteSemester(Semester& s);
void create_file(LinkedList& lst, Semester s, ofstream& fout);
void input_Semester(LinkedList& lst, ifstream& fin);
void view_Semester(LinkedList lst);
void update_Semester(LinkedList& lst, Semester& s);
void output_Semester(LinkedList lst, ofstream& fout);
void delete_Semester(LinkedList& lst);
void main_semester();
void export_3(string inputPath, string outputpath);
void main_Export_Attendence_csv_File();
void edit_Attendence2(string inputPath);
void main_Edit_Attendence();
void import_Score_Board2(string inputPath);
void main_import_ScoreBoard();
void edit_Grade2(string inputPath);
void main_Edit_Grade();
void option_Lecturer();
#endif