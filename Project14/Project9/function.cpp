#include"function.h";
node* createNode(schedule s)
{
	node* p = new node;
	p->data.No = s.No;
	p->data.courseID = s.courseID;
	p->data.courseName = s.courseName;
	p->data.classs = s.classs;
	p->data.LecturerUsername = s.LecturerUsername;
	p->data.LecturerName = s.LecturerName;
	p->data.LecturerDegree = s.LecturerDegree;
	p->data.lecturerGender = s.lecturerGender;
	p->data.startDay = s.startDay;
	p->data.startMonth = s.startMonth;
	p->data.startYear = s.startYear;
	p->data.EndDay = s.EndDay;
	p->data.Endmonth= s.Endmonth;
	p->data.EndYear = s.EndYear;
	p->data.Dayofweek = s.Dayofweek;
	p->data.starthour = s.starthour;
	p->data.startminute = s.startminute;
	p->data.endhour = s.endhour;
	p->data.endminute = s.endminute;
	p->data.Room = s.Room;
	p->next = NULL;
	return p;
}

void load_file(list& lst, ifstream& fin,int &count)
{
	count = 0;
	string temp;
	lst.head = NULL;
	lst.tail = NULL;
	node* current = lst.head;
	schedule s;
	getline(fin,temp, '\n');
	getline(fin, s.No, ',');
	
	getline(fin, s.courseID, ',');
	
	getline(fin, s.courseName, ',');
	
	getline(fin, s.classs, ',');
	
	getline(fin, s.LecturerUsername, ',');
	getline(fin, s.LecturerName, ',');
	
	getline(fin, s.LecturerDegree, ',');
	
	
	getline(fin, s.lecturerGender, ',');
	getline(fin, s.startMonth, '/');
	getline(fin, s.startDay, '/');
	
	getline(fin, s.startYear, ',');
	getline(fin, s.Endmonth, '/');
	getline(fin, s.EndDay, '/');
	
	getline(fin, s.EndYear, ',');

	
	getline(fin, s.Dayofweek, ',');
	
	getline(fin, s.starthour, ',');
	
	getline(fin, s.startminute, ',');
	
	
	getline(fin, s.endhour, ',');
	
	getline(fin, s.endminute, ',');
	
	getline(fin, s.Room,'\n');
	count++;
	
	node* p = createNode(s);
	lst.head = p;
	lst.head->next = current;
	current = lst.head;
	lst.tail = lst.head;
	while (!fin.eof())
	{

		getline(fin, s.No, ',');
		if (s.No == "")
		{
			break;
		}

		getline(fin, s.courseID, ',');

		getline(fin, s.courseName, ',');

		getline(fin, s.classs, ',');

		getline(fin, s.LecturerUsername, ',');
		getline(fin, s.LecturerName, ',');

		getline(fin, s.LecturerDegree, ',');


		getline(fin, s.lecturerGender, ',');
		getline(fin, s.startMonth, '/');

		getline(fin, s.startDay, '/');
		
		getline(fin, s.startYear, ',');
		getline(fin, s.Endmonth, '/');
		getline(fin, s.EndDay, '/');
		
		getline(fin, s.EndYear, ',');


		getline(fin, s.Dayofweek, ',');

		getline(fin, s.starthour, ',');

		getline(fin, s.startminute, ',');


		getline(fin, s.endhour, ',');

		getline(fin, s.endminute, ',');

		getline(fin, s.Room, '\n');
		p = createNode(s);
		current->next = p;
		current = current->next;
		lst.tail = current;
		count++;
	}
	
	


	

}

void output_file(list lst, ofstream& fout)
{


	node* current = lst.head;
	while (current != NULL)
	{
		fout << current->data.No << endl;
		fout << current->data.courseID << endl;
		fout << current->data.courseName << endl;
		fout << current->data.classs << endl;
		fout << current->data.LecturerUsername << endl;
		fout << current->data.LecturerName << endl;
	
		fout << current->data.LecturerDegree << endl;
		if (current->data.lecturerGender == "Male")
		{
			fout << "0" << endl;
		}
		else
		{
			fout << "1" << endl;
		}
		fout << current->data.startYear << " ";
		if (string_to_int(current->data.startMonth) <10)
		{
			fout << "0" << current->data.startMonth << " ";
	    }
		else
		{
			fout << current->data.startMonth << " ";
		}
		if (string_to_int(current->data.startDay) < 10)
		{
			fout << "0" << current->data.startDay << endl;
		}
		else
		{
			cout << current->data.startDay << endl;
		}
		fout << current->data.EndYear << " ";
		if (string_to_int(current->data.Endmonth) < 10)
		{
			fout << "0" << current->data.Endmonth << " ";
		}
		else
		{
			fout << current->data.Endmonth << " ";
		}
		if (string_to_int(current->data.EndDay) < 10)
		{
			fout << "0" << current->data.EndDay << endl;
		}
		else
		{
			fout << current->data.EndDay << endl;
		}

        fout << current->data.Dayofweek << endl;
		fout << current->data.starthour << " ";
		fout << current->data.startminute << endl;
		fout << current->data.endhour << " ";
		fout << current->data.endminute << endl;
		fout << current->data.Room << endl;
		fout << endl;
		current = current->next;

	}
}

int string_to_int(string temp)
{
	int num;
	int size = temp.length();

	num = (int)(temp[0] - '0');
	if (size > 2)
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



Node* create_Node_student(student s)
{
	Node* p = new Node;
	p->data.studentID = s.studentID;
	p->data.studentPass = s.studentPass;
	p->data.studentName = s.studentName;
	p->data.studentDOB = s.studentDOB;
	p->data.studentGender = s.studentGender;
	p->next = NULL;
	return p;
}

void load_file_student(ifstream& fin, LinkedList& lst2)
{
	
	student s;
	lst2.head = NULL;
	lst2.tail = lst2.head;
	Node* current = lst2.head;

	getline(fin, s.studentID, '\n');
	getline(fin, s.studentPass, '\n');
	getline(fin, s.studentName, '\n');
	getline(fin, s.studentDOB, '\n');
	getline(fin, s.studentGender, '\n');
	Node* p = create_Node_student(s);
	lst2.head = p;
	lst2.head->next = current;
	current = lst2.head;


	while (!fin.eof())
	{
		getline(fin, s.studentID, '\n');


		getline(fin, s.studentID, '\n');
		getline(fin, s.studentPass, '\n');
		getline(fin, s.studentName, '\n');
		getline(fin, s.studentDOB, '\n');
		getline(fin, s.studentGender, '\n');
		p = create_Node_student(s);
		current->next = p;
		current = current->next;
		lst2.tail = current;

	}




}
void output_file_student(ofstream& fout, LinkedList lst2,list lst,node*currentlst)
{

	Node* current = lst2.head;
	while (current != NULL) {
		fout << current->data.studentID << endl;
		fout << current->data.studentPass << endl;
		fout << current->data.studentName << endl;
		fout << current->data.studentDOB << endl;
		fout << current->data.studentGender << endl;
	

		if (current->data.midterm == NULL)
		{
			fout << "-1" << endl;
		}
		else
		{
			fout << current->data.midterm << endl;
		}
		if (current->data.final == NULL)
		{
			fout << "-1" << endl;
		}
		else
		{
			fout << current->data.final;
		}
		if (current->data.bonus == NULL)
		{
			fout << "-1" << endl;
		}
		else
		{
			fout << current->data.bonus << endl;
		}
		if (current->data.total == NULL)
		{
			fout << "-1" << endl;
		}
		else
		{
			fout << current->data.total << endl;
		}
		
		int day = string_to_int(currentlst->data.startDay);
		int month = string_to_int(currentlst->data.startMonth);
		int year = string_to_int(currentlst->data.startYear);
		int temp = string_to_int(currentlst->data.EndDay);
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
		fout << currentlst->data.starthour << " ";
		fout << currentlst->data.startminute << " ";
		fout << currentlst->data.endhour << " ";
		fout << currentlst->data.endminute << " ";
		fout << "-1" << endl;
		
		while (day != string_to_int(currentlst->data.EndDay)) //&& month != string_to_int(currentlst->data.Endmonth))
		{
			int temp = day;
			temp = temp + 7;
			day = day_after_1_week(day, month,year);
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
				fout<<"0" << month << " ";
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
			fout << currentlst->data.starthour << " ";
			fout << currentlst->data.startminute << " ";
			fout << currentlst->data.endhour << " ";
			fout << currentlst->data.endminute << " ";
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

	int day_after_1_week( int day,int thang,int nam)
	{
		if (day + 7 > day_of_month(thang,nam))
		{
			int temp = day + 7;
			
			day = temp-day_of_month( thang,nam);
		}
		else
		{
			day = day + 7;
		}
		return day;
	}

	void view_Attendence(LinkedList lst2, list lst, node* currentlst)
	{
		Node* current = lst2.head;
		while (current != NULL) {
			cout << current->data.studentID << endl;
			cout << current->data.studentPass << endl;
			cout << current->data.studentName << endl;
			cout << current->data.studentDOB << endl;
			cout << current->data.studentGender << endl;
			int day = string_to_int(currentlst->data.startDay);
			int month = string_to_int(currentlst->data.startMonth);
			int year = string_to_int(currentlst->data.startYear);
			int temp = string_to_int(currentlst->data.EndDay);
			cout << year << " ";
			if (month < 10)
			{
				cout << "0" << month << " ";
			}
			else
			{
				cout << month << " ";
			}
			if (day < 10)
			{
				cout << "0" << day << " ";
			}
			else
			{
				cout << day << " ";
			}
			cout << currentlst->data.starthour << " ";
			cout << currentlst->data.startminute << " ";
			cout << currentlst->data.endhour << " ";
			cout << currentlst->data.endminute << " ";
			cout << "-1" << endl;

			while (day != string_to_int(currentlst->data.EndDay)) //&& month != string_to_int(currentlst->data.Endmonth))
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


				cout << year << " ";
				if (month < 10)
				{
					cout << "0" << month << " ";
				}
				else
				{
					cout << month << " ";
				}
				if (day < 10)
				{
					cout << "0" << day << " ";
				}
				else
				{
					cout << day << " ";
				}
				cout << currentlst->data.starthour << " ";
				cout << currentlst->data.startminute << " ";
				cout << currentlst->data.endhour << " ";
				cout << currentlst->data.endminute << " ";
				cout << "-1" << endl;


			}


			cout << endl;
			current = current->next;
		}
	}
