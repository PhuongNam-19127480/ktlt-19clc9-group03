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
		cout << "can not open file";


	}
	else
	{
		load_file(lst, fin,count);
		fout.open(outputpath);
		if (!fout.is_open())
		{
			cout << "can not create file";
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
		cout << "can not open file";
	}
	else
	{

		load_file_student(fin, lst2);
		node* current = lst.head;
		
		while (count != 0)
		{
			
			outputpath = Class;
			outputpath.append("-");
			outputpath.append(current->data.courseID);
			outputpath.append(".txt");
				fout.open(outputpath);
			if (!fout.is_open())
			{
				cout << "can not create file";
			}
			else
			{
				output_file_student(fout, lst2,lst,current);
				fout.close();
				 view_Attendence(lst2, lst, current);
				
			}
			count--;
			current = current->next;
			fin.close();
		}

	}
	return 0;
}