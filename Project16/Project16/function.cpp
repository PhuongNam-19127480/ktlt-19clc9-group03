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

void edit_course(LinkedList& lst)
{
	Schedule s;
	cout << "input the num of the course you want to edit" << endl;
	cin >> s.No;
	Node* current = lst.head;
	while (current!=NULL)
	{
		if (current->schedule.No == s.No)
		{
			while (true)
			{
				int n;
				cout << "1.courseID" << endl;
				cout << "2.courseName" << endl;
				cout << "3.class" << endl;
				cout << "4.lecturerUserName" << endl;
				cout << "5.lecturerDegree" << endl;
				cout << "6.Gender" << endl;
				cout << "7.startDate" << endl;
				cout << "8.EndDate" << endl;
				cout << "9.DayofWeek" << endl;
				cout << "10.startHour" << endl;
				cout << "11.EndHour" << endl;
				cout << "12.Room" << endl;
				cout << "13.edit all" << endl;
				cout << "0.exit" << endl;

				cout << "Room" << endl;
				cout << endl;
				cout << "pls choose which you want to edit" << endl;
			
				cin >> n;
				if (n == 1)
				{
					cout << "inputcourseID" << endl;
					cin.ignore(1);
					getline(cin, current->schedule.courseID);
				}
				else if (n == 2)
				{
					cout << "input courseName" << endl;
					cin.ignore(1);
					getline(cin, current->schedule.courseName);
				}
				else if (n == 3)
				{
					cout << "input class" << endl;
					cin.ignore(1);
					getline(cin, current->schedule.classs);
				}
				else if (n == 4)
				{
					cout << "nhap vao lecturerUserName" << endl;
					cin.ignore(1);
					getline(cin, current->schedule.LecturerUsername);
				}
				else if (n == 5)
				{
					cout << "input lecturerDegree" << endl;
					cin.ignore(1);
					getline(cin, current->schedule.LecturerDegree);
				}
				else if (n == 6)
				{
					cout << "input Gender" << endl;
					cin.ignore(1);
					getline(cin, current->schedule.lecturerGender);
				}
				else if (n == 7)
				{
					cin.ignore(1);
					cout << "input startDay" << endl;
					getline(cin, current->schedule.startDay);
					cout << "input startMonth" << endl;
					getline(cin, current->schedule.startMonth);
					cout << "input startYear" << endl;
					getline(cin, current->schedule.startYear);
				}
				else if (n ==8 )
				{
					cin.ignore(1);
					cout << "input EndDay" << endl;
					getline(cin, current->schedule.EndDay);
					cout << "input EndMonth" << endl;
					getline(cin, current->schedule.Endmonth);
					cout << "input EndYear" << endl;
					getline(cin, current->schedule.EndYear);
				}
				else if (n == 9)
				{
					cin.ignore(1);
					cout << "input DayofWeek" << endl;
					getline(cin, current->schedule.Dayofweek);
				}
				else if (n == 10)
				{
					cin.ignore(1);
					cout << "input startHour" << endl;
					getline(cin, current->schedule.starthour);
					cout << "input startMinute" << endl;
					getline(cin, current->schedule.startminute);
				}
				else if (n == 11)
				{
					cin.ignore(1);
					cout << "input EndHour" << endl;
					getline(cin, current->schedule.endhour);
					cout << "input EndMinute" << endl;
					getline(cin, current->schedule.endminute);
				}
				else if (n == 12)
				{
					cin.ignore(1);
					cout << "input Room" << endl;
					getline(cin, current->schedule.Room);
				}
				else if (n == 13)
				{
					cout << "nhap vao courseID" << endl;
					cin.ignore(1);
					getline(cin, current->schedule.courseID);
					cout << "nhap vao coureName" << endl;
					getline(cin, current->schedule.courseName);
					cout << "nhap vao class" << endl;
					getline(cin, current->schedule.classs);
					cout << "nhap vao LecturerUsername" << endl;
					getline(cin, current->schedule.LecturerUsername);
					cout << "nhap vao LecturerName" << endl;
					getline(cin, current->schedule.LecturerName);
					cout << "nhap vao LecturerDegree" << endl;
					getline(cin, current->schedule.LecturerDegree);
					cout << "nhap vao LecturerGenger" << endl;

					getline(cin, current->schedule.lecturerGender);
					cout << "nhap vao startDay" << endl;


					getline(cin, current->schedule.startDay);
					cout << "nhap vao startMonth" << endl;
					getline(cin, current->schedule.startMonth);
					cout << "nhap vao startYear" << endl;
					getline(cin, current->schedule.startYear);
					cout << "nhap vao EndDay" << endl;


					getline(cin, current->schedule.EndDay);
					cout << "nhap vao EndMonth" << endl;
					getline(cin, current->schedule.Endmonth);
					cout << "nhap vao Endyear" << endl;
					getline(cin, current->schedule.EndYear);

					cout << "Nhap vao Dayofweek" << endl;


					getline(cin, current->schedule.Dayofweek);
					cout << "nhap vao starthour" << endl;
					getline(cin, current->schedule.starthour);
					cout << "nhap vao startminute" << endl;
					getline(cin, current->schedule.startminute);
					cout << "nhap vao endhour" << endl;

					getline(cin, current->schedule.endhour);
					cout << "nhap vao endminute" << endl;

					getline(cin, current->schedule.endminute);
					cout << "nhap vao Room" << endl;
					getline(cin, current->schedule.Room);
				}
				else if (n == 0)
				{
				break;
                }
			}
			break;
		}
		else
		{
		current = current->next;
        }
	}
}

void view_schedule(LinkedList lst)
{
	Node* current = lst.head;
	while (current != NULL)
	{
		cout << current->schedule.No << endl;
		cout << current->schedule.courseID << endl;
		cout << current->schedule.courseName << endl;
		current = current->next;
	}
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

void main_delete_course()
{
	LinkedList lst;
	ifstream fin;
	ofstream fout;
	int count;
	fin.open("2019-2020-hk2-schedule-19APCS1.txt");
	if (!fin.is_open())
	{
		cout << "can not open file";
	}
	else
	{
		load_file_schedule_txt(lst, fin, count);
		view_schedule(lst);
		//edit_course(lst);
		delete_course(lst, count);
		fout.open("2019-2020-hk2-schedule-19APCS1.txt", ios::out);
		if (!fout.is_open())
		{
			cout << "can not open file" << endl;
		}
		else
		{
			output_file_schedule_txt(lst, fout);
			//cout << "edit successfully";
			cout << "delete successfully" << endl;
			fout.close();
		}
		fin.close();
	}
}

void delete_course(LinkedList& lst,int &count)
{
	if(lst.head==NULL)
	{
		return;
	}
	else
	{
		Schedule s;
		cout << "input the num of the course you want to delete" << endl;
		cin >> s.No;
		Node* current = lst.head;
		while (current != NULL)
		{
			if (current->schedule.No == s.No)
			{
				break;
			}
			else
			{
				current = current->next;
			}
		}
		if (current==lst.head)
		{
			//Node* current = lst.head;
			lst.head = lst.head->next;
			delete current;
			count--;
		}
		else
		{
			Node* prev = lst.head;
			current = lst.head->next;

			while (current != NULL)
			{
				if (current->schedule.No == s.No)
				{
					break;
				}
				else
				{
					prev = prev->next;
					current = current->next;
				}
			}
			prev->next = current->next;
			delete current;

		}
	}
}

void main_edit_course()
{

	LinkedList lst;
	LinkedList lst2;
	ifstream fin;
	ofstream fout;
	int count;
	string outputpath;
	fin.open("2019-2020-hk2-schedule-19APCS1.txt");
	if (!fin.is_open())
	{
		cout << "can not open file";
	}
	else
	{
		load_file_schedule_txt(lst, fin, count);
		view_schedule(lst);
		edit_course(lst);
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
			fout.close();
		}
		fin.close();
	}


	fin.open("Student.txt");

	if (!fin.is_open())
	{
		cout << "can not open file";
		return;
	}
	else
	{

		load_file_Student(fin, lst2);
		Node* current = lst.head;

		while (count != 0)
		{

			outputpath = "19APCS1";
			outputpath.append("-");
			outputpath.append(current->schedule.courseID);
			outputpath.append(".txt");
			fout.open(outputpath);

			if (!fout.is_open())
			{
				cout << "can not create file";
			}
			else
			{
				output_file_Student(fout, lst2, lst, current);
				fout.close();
				// view_Attendence(lst2, lst, current);

			}
			count--;
			current = current->next;
			fin.close();
		}

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

void output_file_Student(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst)
{

	Node* current = lst2.head;
	while (current != NULL) {
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
		int month = string_to_int(currentlst->schedule.startMonth);
		int year = string_to_int(currentlst->schedule.startYear);
		int temp = string_to_int(currentlst->schedule.EndDay);
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



