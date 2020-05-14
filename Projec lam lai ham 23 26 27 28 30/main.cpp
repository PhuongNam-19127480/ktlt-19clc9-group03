#include"function.h"
int main()
{
	string academic;
	string semester;
	string Class;
	char base[101];
	string outputpath;
	LinkedList lst;
	LinkedList lst2;
	int count;
	int attendence;
	char inputpath[100];
	int day_edit, month_edit, year_edit;
	string class_View, courseID_View, studentID_View;
	cout << "nhap vao nam hoc:" << endl;
	getline(cin, academic);
	cout << "nhap vao hoc ki: " << endl;
	getline(cin, semester);
	cout << "nhap vao lop hoc: " << endl;
	getline(cin, Class);
	cout << "nhap vao duong dan chua file: " << endl;
	cin.getline(base, 100);
	string inputpath2;
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
		cout << "can not open" << inputpath << "file";
		return 0;


	}
	else
	{
		load_file(lst, fin, count);
		fout.open(outputpath);
		if (!fout.is_open())
		{
			cout << "can not" << outputpath << "create file";
		}
		else
		{
			output_file(lst, fout);
			fout.close();
		}

		fin.close();
	}

	fin.open("C:\\Users\\admin\\source\\repos\\Test\\Projec lam lai ham 23 26 27 28 30\\Student.txt");

	if (!fin.is_open())
	{
		cout << "can not Student.txt open file";
		return 0;
	}
	else
	{

		load_file_Student(fin, lst2);
		Node* current = lst.head;

		while (count != 0)
		{

			//outputpath = Class;
			outputpath = Class;
			outputpath.append("-");
			outputpath.append(current->schedule.courseID);
			outputpath.append(".txt");
			fout.open(outputpath);
			if (!fout.is_open())
			{
				cout << "can not" << outputpath << "create file";
			}
			else
			{
				output_file_Student(fout, lst2, lst, current);
				fout.close();

			}
			count--;
			current = current->next;
			fin.close();
		}

		//view_Attendence_List_Of_Course( lst, lst2, class_View, courseID_View, Class, inputpath2);
		edit_Attendence_Of_Course(fout,lst, lst2, class_View, courseID_View, Class,studentID_View,year_edit,month_edit,day_edit,attendence);
		//export_Attendence_list_Of_Course(fout, lst, lst2, class_View, courseID_View, outputpath, Class,inputpath2);
		//view_List_Student_Of_Course(lst, lst2, class_View,courseID_View);
	}
	return 0;
}