#include"function.h"
void outputfile(schedule s,ofstream &fout)
{
	fout << s.No << endl;
	fout << s.courseID << endl;
	fout << s.courseName << endl;
	fout << s.classs << endl;
	fout << s.LecturerUsername << endl;
	fout << s.LecturerName << endl;
	fout << s.LecturerDegree << endl;
	if (s.lecturerGender == "Male")
	{
		fout << "0" << endl;
	}
	else
	{
		fout << "1" << endl;
	}
	fout << s.startYear << " ";
	
		fout << s.startMonth << " ";
	

	
		fout << s.startDay << endl;
	
	fout << s.EndYear << " ";
	
		fout << s.EndMonth << " ";
	

	
		fout << s.EndDay << endl;
	
	fout << s.Dayofweek << endl;
	fout << s.starthour << " ";
	fout << s.startminute << endl;
	fout << s.endhour << " ";
	fout << s.endminute << endl;
	fout << s.Room << endl;
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
void output_file_student(ofstream& fout, LinkedList lst2, schedule s)
{

	Node* current = lst2.head;
	while (current != NULL) 
	{
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

		int day = string_to_int(s.startDay);
		int month = string_to_int(s.startMonth);
		int year = string_to_int(s.startYear);
		//int temp = string_to_int(currentlst->data.EndDay);
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
		while (day != string_to_int(s.EndDay)) //&& month != string_to_int(currentlst->data.Endmonth))
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

