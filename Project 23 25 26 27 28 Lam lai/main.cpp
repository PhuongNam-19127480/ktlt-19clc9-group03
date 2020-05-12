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
	//int day_edit, month_edit, year_edit;
	string class_View, courseID_View,studentID_View;
	cout << "nhap vao nam hoc:" << endl;
	getline(cin, academic);
	cout << "nhap vao hoc ki: " << endl;
	getline(cin, semester);
	cout << "nhap vao lop hoc: " << endl;
	getline(cin, Class);
	cout << "nhap vao duong dan chua file: " << endl;
	//cin.getline(base, 100);
	string inputpath;
	getline(cin, inputpath);
	//strcpy_s(inputpath, strlen(base) + 1, base);
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

	fin.open("C:\\Users\\admin\\source\\repos\\Test\\Project 23 25 26 Lam lai\\Student.txt");

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

		//view_Attendence_List_Of_Course(lst, lst2, class_View, courseID_View, Class, inputpath);
		//export_Attendence_list_Of_Course(fout, lst, lst2, class_View, courseID_View, outputpath, Class,inputpath);
		view_List_Student_Of_Course(lst, lst2, class_View,courseID_View);
		/*edit_Attendence_Of_Course(fout, lst2, lst, class_View, studentID_View, day_edit, month_edit, year_edit,courseID_View,
			outputpath,Class,inputpath);*/
	}
	return 0;
}