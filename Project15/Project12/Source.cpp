#include"function.h"
int main()
{
	schedule s;
	ofstream fout;
	ifstream fin;
	LinkedList lst2;
	cout << "nhap vao thu tu mon hoc" << endl;
	getline(cin, s.No);
	cout << "nhap vao courseID" << endl;

	getline(cin, s.courseID);
	cout << "nhap vao coureName" << endl;
	getline(cin, s.courseName);
	cout << "nhap vao class" << endl;
	getline(cin, s.classs);
	cout << "nhap vao LecturerUsername" << endl;
	getline(cin, s.LecturerUsername);
	cout << "nhap vao LecturerName" << endl;
	getline(cin, s.LecturerName);
	cout << "nhap vao LecturerDegree" << endl;
	getline(cin, s.LecturerDegree);
	cout << "nhap vao LecturerGenger" << endl;

	getline(cin, s.lecturerGender);
	cout << "nhap vao startDay" << endl;
	

	getline(cin, s.startDay);
	cout << "nhap vao startMonth" << endl;
	getline(cin, s.startMonth);
	cout << "nhap vao startYear" << endl;
	getline(cin, s.startYear);
	cout << "nhap vao EndDay" << endl;

	
	getline(cin, s.EndDay);
	cout << "nhap vao EndMonth" << endl;
	getline(cin, s.EndMonth);
	cout << "nhap vao Endyear" << endl;
	getline(cin, s.EndYear);

	cout << "Nhap vao Dayofweek" << endl;


	getline(cin, s.Dayofweek);
	cout << "nhap vao starthour" << endl;
	getline(cin, s.starthour);
	cout << "nhap vao startminute" << endl;
	getline(cin, s.startminute);
	cout << "nhap vao endhour" << endl;

	getline(cin, s.endhour);
	cout << "nhap vao endminute" << endl;

	getline(cin, s.endminute);
	cout << "nhap vao Room" << endl;
	getline(cin, s.Room);
	fout.open("2019-2020-HK2-schedule-19APCS1.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "can not open 2019-2020-HK2-schedule-19APCS1.txt file" << endl;
	}
	else
	{
		outputfile(s,fout);
		fout.close();
		
	}

	fin.open("student.txt");
	if (!fin.is_open())
	{
		cout << "can not open student.txt" << endl;
	}
	else
	{
		load_file_student(fin, lst2);
		string outputpath;
		outputpath = s.classs;
		outputpath.append("-");
		outputpath.append(s.courseID);
		outputpath.append(".txt");
		fout.open(outputpath);
		if (!fout.is_open())
		{
			cout << "can not create file";
		}
		else
		{
			output_file_student(fout, lst2, s);
			fout.close();
		}

	}

	fin.close();
	return 0;
}