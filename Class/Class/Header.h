#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Student {
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

struct Node {
	Student Info;
	Node* next;
};


struct LinkedList {
	Node* head;
	Node* tail;
	int count;
	string ClassName;
};

Node* CreateNode(string No, string ID, string Lastname, string Firstname, string Gender, string Day, string Month, string Year);
void LoadStudent(ifstream& finput, LinkedList& Stu);
void Load_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10);
void InsertStudent(LinkedList& Stu);
void EditStudent(LinkedList& Stu);
void Delete_Student(LinkedList& Class);
void SaveStudentFile(ofstream& foutput, LinkedList Stu);
void OuputStudentList(LinkedList Stu);
void Insert_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10);
void Edit_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10);
void View_Class_List(LinkedList APCS1, LinkedList APCS2, LinkedList APCS3, LinkedList APCS4, LinkedList APCS5, LinkedList APCS6, LinkedList APCS7, LinkedList APCS8, LinkedList APCS9, LinkedList APCS10);
void View_Student_List_Option(LinkedList APCS1, LinkedList APCS2, LinkedList APCS3, LinkedList APCS4, LinkedList APCS5, LinkedList APCS6, LinkedList APCS7, LinkedList APCS8, LinkedList APCS9, LinkedList APCS10);
void Delete_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10);
void Change_Class(LinkedList& OldClass, LinkedList& NewClass);
void Change_Class_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10);
