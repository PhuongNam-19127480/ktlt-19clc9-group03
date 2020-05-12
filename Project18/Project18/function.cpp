#include"function.h";
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
	temp = s.startYear;
	getline(fin, s.startMonth, ' ');
	temp = s.startMonth;

	getline(fin, s.startDay, '\n');
	temp = s.startDay;

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

void remove_specific_student(LinkedList& lst2, LinkedList lst)
{
	ofstream fout;
	string IDstudent;
	string IDcourse;
	string class_student;
	cout << "pls input the ID of the student you want to remove" << endl;
	getline(cin, IDstudent);
	cout << "pls input the ID course of the student you remove" << endl;
	getline(cin, IDcourse);
	cout << "pls input the class of the student you want to remove" << endl;
	getline(cin, class_student);
	string outputpath;
	outputpath = class_student;
	outputpath.append("-");
	outputpath.append(IDcourse);
	outputpath.append(".txt");
	fout.open(outputpath, ios::out);
	
	if (!fout.is_open())
	{
		cout << "can not open file" << endl;
	}
	else
	{
		Node* current = lst2.head;

		Node* currentlst = lst.head;
		string temp = currentlst->schedule.startDay;
		while (current != NULL)
		{
			if (current->student.StudentID == IDstudent)
			{
				break;
			}
			else
			{
				current = current->next;
			}
		}
		while (currentlst != NULL)
		{
			if (currentlst->schedule.courseID == IDcourse)
			{
				break;
			}
			else
			{
				currentlst = currentlst->next;
			}
		}
		current->student.status = 0;
		current = lst2.head;
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

			int day = string_to_int(currentlst->schedule.startDay);
			//	string temp = current->schedule.startDay;
			int month = string_to_int(currentlst->schedule.startMonth);
			int year = string_to_int(currentlst->schedule.startYear);
			//	int temp = string_to_int(currentlst->schedule.EndDay);
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
			fout << currentlst->schedule.starthour << " ";
			fout << currentlst->schedule.startminute << " ";
			fout << currentlst->schedule.endhour << " ";
			fout << currentlst->schedule.endminute << " ";
			fout << "-1" << endl;

			while (day != string_to_int(currentlst->schedule.EndDay)) //&& month != string_to_int(currentlst->data.Endmonth))
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
				fout << currentlst->schedule.starthour << " ";
				fout << currentlst->schedule.startminute << " ";
				fout << currentlst->schedule.endhour << " ";
				fout << currentlst->schedule.endminute << " ";
				fout << "-1" << endl;


			}

			fout << current->student.status << endl;
			fout << endl;

			current = current->next;


		}
	}
	//Node* current1 = lst.head;


	fout.close();
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

void main_remove_specific_student()
{
	LinkedList lst;
	LinkedList lst2;
	ifstream fin;
	int count = 0;
	fin.open("2019-2020-hk2-schedule-19APCS1.txt");
	if (!fin.is_open())
	{
		cout << "can not open file";
	}
	else
	{
		load_file_schedule_txt(lst, fin, count);
		fin.close();
		fin.open("student.txt");
		if (!fin.is_open())
		{
			cout << "can not open student file" << endl;

		}
		else
		{
			load_file_Student(fin, lst2);

		}
		remove_specific_student(lst2, lst);

	}
	fin.close();

}

