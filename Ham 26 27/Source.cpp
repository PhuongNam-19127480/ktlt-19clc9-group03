#include"function.h"
int main()
{
	string academic;
	string semester;
	string Class;
	char base[101];
	string outputpath;
	list lst;
	LinkedList lst2;
	int count;
	string index="3";
	cout << "nhap vao nam hoc:" << endl;
	getline(cin, academic);
	cout << "nhap vao hoc ki: " << endl;
	getline(cin, semester);
	cout << "nhap vao lop hoc: " << endl;
	getline(cin, Class);
	cout << "nhap vao duong dan chua file: " << endl;
	cin.getline(base, 100);
	char inputpath[101];
	strcpy_s(inputpath, strlen(base) + 1, base);
	outputpath = academic;
	outputpath.append("-");
	outputpath.append(semester);
	outputpath.append("-");
	outputpath.append("schedule");
	outputpath.append("-");
	outputpath.append(Class);
	outputpath.append(".txt");
	ifstream fin;
	ofstream fout;
	fin.open(inputpath);
	if (!fin.is_open())
	{
		cout << "can not open"<<inputpath<<"file";


	}
	else
	{
		load_file(lst, fin, count);
		fout.open(outputpath);
		if (!fout.is_open())
		{
			cout << "can not create"<<outputpath<<" file";
		}
		else
		{
			output_file(lst, fout);
			fout.close();
		}

		fin.close();
	}

	fin.open("Student.txt");

	if (!fin.is_open())
	{
		cout << "can not open file Student.txt";
	}
	else
	{

		load_file_student(fin, lst2);
		node* current = lst.head;
		/*while (count != 0)
		{
			node* current2 = lst.head;
			outputpath = Class;
			outputpath.append("-");
			outputpath.append(current->data.courseID);
			outputpath.append(".txt");
			fout.open(outputpath);
			if (!fout.is_open())
			{
				cout << "can not create" << outputpath << " file";
			}
			else
			{
				output_file_student(fout, lst2, lst, current);
				fout.close();
			}
			count--;
			current = current->next;
			fin.close();
		}*/
		
			//function View Attence list of a Course 
			/*current = lst.head;
			while (1) {
				node* current2 = lst.head;
				while (current2 != NULL) {
					cout << current2->data.No << "." << current2->data.classs << "-" << current2->data.courseID << "\n";
					current2 = current2->next;
				}
				cout << "0. back\n";
				cout << "Enter No of courese to view:";
				getline(cin, index);
				if (index == "0") {
					break;
				}
				else {
					while (1)
					{
						if (index == current->data.No) {
							view_Attendence(lst2, lst, current);
							current = lst.head;
							break;
						}
						else {
							current = current->next;
						}
						if (current == NULL) {
							cout << "Course is not exist\n";
							current = lst.head;
							break;
						}
					}
				}
			}*/
			//function export Attendence list of a Course
			current = lst.head;
			while (1) {
				node* current2 = lst.head;
				while (current2 != NULL) {
					cout << current2->data.No << "." << current2->data.classs << "-" << current2->data.courseID << "\n";
					current2 = current2->next;
				}
				cout << "0. back\n";
				cout << "Enter No of courese to export:";
				getline(cin, index);
				if (index == "0") {
					break;
				}
				else {
					while (1)
					{
						if (index == current->data.No) {
							outputpath = "";
							outputpath.append(Class);
							outputpath.append("-");
							outputpath.append(current->data.courseID);
							outputpath.append("-Attendence");
							outputpath.append(".csv");
							fout.open(outputpath);
							if (!fout.is_open())
							{
								cout << "can not create" << outputpath << " file";
							}
							else
							{
								output_Attendence_list_Of_Course(fout, lst2, lst, current);
								fout.close();
								cout << "Export successfully\n";
								current = lst.head;
								break;
							}
						}
						else {
							current = current->next;
						}
						if (current == NULL) {
							cout << "Course is not exist\n";
							current = lst.head;
							break;
						}
					}
				}
			}
		
	}
	
	return 0;
}