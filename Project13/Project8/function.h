#ifndef function_h
#define function_h
#include<iostream>
#include <fstream>
using namespace std;
struct Semester
{
	int n = 0;
	char Semesters[11];
	char academic[20];
};

struct Node
{
	Semester data;
	Node* next;
};

struct LinkedList
{
	Node* head;
};

Node* createNote(Semester &s);
void create_file(LinkedList& lst,Semester s,ofstream&fout);
void input_Semester(LinkedList& lst,ifstream &fin);
void view_Semester(LinkedList lst);
void update_Semester(LinkedList& lst, Semester &s);
void output_Semester(LinkedList lst, ofstream& fout);
void delete_Semester(LinkedList& lst);
#endif