#include"function.h"
//void outputfile(Schedule s,ofstream &fout)
//{
//	fout << s.No << endl;
//	fout << s.courseID << endl;
//	fout << s.courseName << endl;
//	fout << s.classs << endl;
//	fout << s.LecturerUsername << endl;
//	fout << s.LecturerName << endl;
//	fout << s.LecturerDegree << endl;
//	if (s.lecturerGender == "Male")
//	{
//		fout << "0" << endl;
//	}
//	else
//	{
//		fout << "1" << endl;
//	}
//	fout << s.startYear << " ";
//	
//		fout << s.startMonth << " ";
//	
//
//	
//		fout << s.startDay << endl;
//	
//	fout << s.EndYear << " ";
//	
//		fout << s.Endmonth << " ";
//	
//
//	
//		fout << s.EndDay << endl;
//	
//	fout << s.Dayofweek << endl;
//	fout << s.starthour << " ";
//	fout << s.startminute << endl;
//	fout << s.endhour << " ";
//	fout << s.endminute << endl;
//	fout << s.Room << endl;
//}

void load_file_schedule_txt(LinkedList& lst, ifstream& fin, int& count)
{
	count = 0;
	string temp;
	lst.head = NULL;
	lst.tail = NULL;
	Node* current = lst.head;
	Schedule s;
	//getline(fin, temp, '\n');
	getline(fin, s.No, '\n');
	//fin >> s.No;

	getline(fin, s.courseID, '\n');
	//	getline(fin, s.courseID, '\n');

	getline(fin, s.courseName, '\n');

	getline(fin, s.classs, '\n');

	getline(fin, s.LecturerUsername, '\n');
	getline(fin, s.LecturerName, '\n');

	getline(fin, s.LecturerDegree, '\n');


	getline(fin, s.lecturerGender, '\n');
	getline(fin, s.startYear, ' ');
	getline(fin, s.startMonth, ' ');
	getline(fin, s.startDay, '\n');

	getline(fin, s.EndYear, ' ');
	getline(fin, s.Endmonth, ' ');
	getline(fin, s.EndDay, '\n');




	getline(fin, s.Dayofweek, '\n');

	getline(fin, s.starthour, ' ');

	getline(fin, s.startminute, '\n');


	getline(fin, s.endhour, ' ');

	getline(fin, s.endminute, '\n');

	getline(fin, s.Room, '\n');
	count++;

	Node* p = createNode(s);
	lst.head = p;
	lst.head->next = current;
	current = lst.head;
	lst.tail = lst.head;
	while (!fin.eof())
	{

		getline(fin, s.No, '\n');
		getline(fin, s.No, '\n');
		//fin >> s.No;
		temp = s.No;
		if (s.No == "")
		{
			break;
		}

		getline(fin, s.courseID, '\n');
		//getline(fin, s.courseID, '\n');

		getline(fin, s.courseName, '\n');

		getline(fin, s.classs, '\n');

		getline(fin, s.LecturerUsername, '\n');
		getline(fin, s.LecturerName, '\n');

		getline(fin, s.LecturerDegree, '\n');


		getline(fin, s.lecturerGender, '\n');
		getline(fin, s.startYear, ' ');
		getline(fin, s.startMonth, ' ');
		getline(fin, s.startDay, '\n');

		getline(fin, s.EndYear, ' ');
		getline(fin, s.Endmonth, ' ');
		getline(fin, s.EndDay, '\n');




		getline(fin, s.Dayofweek, '\n');

		getline(fin, s.starthour, ' ');

		getline(fin, s.startminute, '\n');


		getline(fin, s.endhour, ' ');

		getline(fin, s.endminute, '\n');

		getline(fin, s.Room, '\n');
		p = createNode(s);
		current->next = p;
		current = current->next;
		lst.tail = current;
		count++;
	}
}

Node* createNode(Schedule s)
{
	Node* p = new Node;
	p->schedule.No = s.No;
	p->schedule.courseID = s.courseID;
	p->schedule.courseName = s.courseName;
	p->schedule.classs = s.classs;
	p->schedule.LecturerUsername = s.LecturerUsername;
	p->schedule.LecturerName = s.LecturerName;
	p->schedule.LecturerDegree = s.LecturerDegree;
	p->schedule.lecturerGender = s.lecturerGender;
	p->schedule.startDay = s.startDay;
	p->schedule.startMonth = s.startMonth;
	p->schedule.startYear = s.startYear;
	p->schedule.EndDay = s.EndDay;
	p->schedule.Endmonth = s.Endmonth;
	p->schedule.EndYear = s.EndYear;
	p->schedule.Dayofweek = s.Dayofweek;
	p->schedule.starthour = s.starthour;
	p->schedule.startminute = s.startminute;
	p->schedule.endhour = s.endhour;
	p->schedule.endminute = s.endminute;
	p->schedule.Room = s.Room;
	p->next = NULL;
	return p;
}


int string_to_int(string temp)
{
	int num;
	int size = temp.length();

	num = (int)(temp[0] - '0');
	if (size >= 2)
	{
		for (int i = 1; i < size; i++)
		{
			int num2;
			num2 = (int)(temp[i] - '0');
			num = num * 10 + num2;
		}
	}
	return num;
}



Node* create_Node_Student(Student s)
{
	Node* p = new Node;
	p->student.StudentID = s.StudentID;
	p->student.StudentPass = s.StudentPass;
	p->student.StudentName = s.StudentName;
	p->student.StudentDOB = s.StudentDOB;
	p->student.StudentGender = s.StudentGender;
	p->next = NULL;
	return p;
}

void load_file_Student(ifstream& fin, LinkedList& lst2)
{

	Student s;
	lst2.head = NULL;
	lst2.tail = lst2.head;
	Node* current = lst2.head;

	getline(fin, s.StudentID, '\n');
	getline(fin, s.StudentPass, '\n');
	getline(fin, s.StudentName, '\n');
	getline(fin, s.StudentDOB, '\n');
	getline(fin, s.StudentGender, '\n');
	Node* p = create_Node_Student(s);
	lst2.head = p;
	lst2.head->next = current;
	current = lst2.head;


	while (!fin.eof())
	{
		getline(fin, s.StudentID, '\n');


		getline(fin, s.StudentID, '\n');
		getline(fin, s.StudentPass, '\n');
		getline(fin, s.StudentName, '\n');
		getline(fin, s.StudentDOB, '\n');
		getline(fin, s.StudentGender, '\n');
		p = create_Node_Student(s);
		current->next = p;
		current = current->next;
		lst2.tail = current;

	}




}
void output_file_Student_Add(ofstream& fout, LinkedList lst2, Schedule s)
{

	Node* current = lst2.head;
	while (current != NULL) 
	{
		fout << current->student.StudentID << endl;
		fout << current->student.StudentPass << endl;
		fout << current->student.StudentName << endl;
		fout << current->student.StudentDOB << endl;
		fout << current->student.StudentGender << endl;


		if (current->student.midterm == NULL)
		{
			fout << "-1" << endl;
		}
		else
		{
			fout << current->student.midterm << endl;
		}
		if (current->student.final == NULL)
		{
			fout << "-1" << endl;
		}
		else
		{
			fout << current->student.final;
		}
		if (current->student.bonus == NULL)
		{
			fout << "-1" << endl;
		}
		else
		{
			fout << current->student.bonus << endl;
		}
		if (current->student.total == NULL)
		{
			fout << "-1" << endl;
		}
		else
		{
			fout << current->student.total << endl;
		}

		int day = string_to_int(s.startDay);
		int month = string_to_int(s.startMonth);
		int year = string_to_int(s.startYear);
		//int temp = string_to_int(currentlst->student.EndDay);
		fout << year << " ";
		if (month < 10)
		{
			fout << "0" << month << " ";
		}
		else
		{
			fout << month << " ";
		}
		if (day < 10)
		{
			fout << "0" << day << " ";
		}
		else
		{
			fout << day << " ";
		}
		fout << s.starthour << " ";
		fout << s.startminute << " ";
		fout << s.endhour << " ";
		fout << s.endminute << " ";
		fout << "-1" << endl;
		while (day != string_to_int(s.EndDay)) //&& month != string_to_int(currentlst->student.Endmonth))
		{
			int temp = day;
			temp = temp + 7;
			day = day_after_1_week(day, month, year);
			if (month == 12)
			{
				if (temp > day_of_month(month, year))
				{
					month = 1;
				}

			}
			else
			{
				if (temp > day_of_month(month, year))
				{
					month = month + 1;
				}
			}


			fout << year << " ";
			if (month < 10)
			{
				fout << "0" << month << " ";
			}
			else
			{
				fout << month << " ";
			}
			if (day < 10)
			{
				fout << "0" << day << " ";
			}
			else
			{
				fout << day << " ";
			}
			fout << s.starthour << " ";
			fout << s.startminute << " ";
			fout << s.endhour << " ";
			fout << s.endminute << " ";
			fout << "-1" << endl;
			


		}
		fout << endl;
		current = current->next;


		}


	
}

int day_of_month(int thang, int nam)
{
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isCheck(nam))
			return 29;
		else
			return 28;
	}
}

bool isCheck(int nam)
{
	return ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0);
}

int day_after_1_week(int day, int thang, int nam)
{
	if (day + 7 > day_of_month(thang, nam))
	{
		int temp = day + 7;

		day = temp - day_of_month(thang, nam);
	}
	else
	{
		day = day + 7;
	}
	return day;
}

void Add_course(LinkedList& lst,int &count, Schedule &s)
{
	
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
	getline(cin, s.Endmonth);
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
	
	Node*p = createNode(s);
	lst.tail->next = p;
	lst.tail = lst.tail->next;
	count++;
}

void output_file_schedule_txt(LinkedList lst, ofstream& fout)
{
	if (lst.head == NULL)
	{
		cout << "there is no course here" << endl;
	}
	else
	{

		Node* current = lst.head;
		while (current != NULL)
		{
			fout << current->schedule.No << endl;
			fout << current->schedule.courseID << endl;
			fout << current->schedule.courseName << endl;
			fout << current->schedule.classs << endl;
			fout << current->schedule.LecturerUsername << endl;
			fout << current->schedule.LecturerName << endl;

			fout << current->schedule.LecturerDegree << endl;
			fout << current->schedule.lecturerGender << endl;
			fout << current->schedule.startYear << " ";


			fout << current->schedule.startMonth << " ";


			fout << current->schedule.startDay << endl;

			fout << current->schedule.EndYear << " ";

			fout << current->schedule.Endmonth << " ";


			fout << current->schedule.EndDay << endl;


			fout << current->schedule.Dayofweek << endl;
			fout << current->schedule.starthour << " ";
			fout << current->schedule.startminute << endl;
			fout << current->schedule.endhour << " ";
			fout << current->schedule.endminute << endl;
			fout << current->schedule.Room << endl;
			fout << endl;
			current = current->next;

		}
	}
}

void main_add_course()
{
	Schedule s;
	ofstream fout;
	ifstream fin;
	LinkedList lst;
	LinkedList lst2;
	/*cout << "nhap vao thu tu mon hoc" << endl;
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
	getline(cin, s.Endmonth);
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
	getline(cin, s.Room);*/
	int count;
	fin.open("2019-2020-hk2-schedule-19APCS1.txt");
	if (!fin.is_open())
	{
		cout << "can not open file";
		return;
	}
	else
	{
		load_file_schedule_txt(lst, fin, count);
		Add_course(lst, count, s);
		//view_schedule(lst);
		//edit_course(lst);
		//delete_course(lst, count);
		fout.open("2019-2020-hk2-schedule-19APCS1.txt", ios::out);
		if (!fout.is_open())
		{
			cout << "can not open file" << endl;
		}
		else
		{
			output_file_schedule_txt(lst, fout);
			//cout << "edit successfully";
			//cout << "delete successfully" << endl;
			cout << "Add successfully" << endl;
			fout.close();
		}
		fin.close();
	}

	fin.open("student.txt");
	if (!fin.is_open())
	{
		cout << "can not open student.txt" << endl;
		return;
	}
	else
	{
		load_file_Student(fin, lst2);
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
			output_file_Student_Add(fout, lst2, s);
			fout.close();
		}

	}

	fin.close();
}

