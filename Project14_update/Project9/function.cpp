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
	p->schedule.Endmonth= s.Endmonth;
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

void load_file(LinkedList& lst, ifstream& fin,int &count)
{
	count = 0;
	string temp;
	lst.head = NULL;
	lst.tail = NULL;
	Node* current = lst.head;
	Schedule s;
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
	
	Node* p = createNode(s);
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

void output_file(LinkedList lst, ofstream& fout)
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
		if (current->schedule.lecturerGender == "Male")
		{
			fout << "0" << endl;
		}
		else
		{
			fout << "1" << endl;
		}
		fout << current->schedule.startYear << " ";
		if (string_to_int(current->schedule.startMonth) <10)
		{
			fout << "0" << current->schedule.startMonth << " ";
	    }
		else
		{
			fout << current->schedule.startMonth << " ";
		}
		if (string_to_int(current->schedule.startDay) < 10)
		{
			fout << "0" << current->schedule.startDay << endl;
		}
		else
		{
			cout << current->schedule.startDay << endl;
		}
		fout << current->schedule.EndYear << " ";
		if (string_to_int(current->schedule.Endmonth) < 10)
		{
			fout << "0" << current->schedule.Endmonth << " ";
		}
		else
		{
			fout << current->schedule.Endmonth << " ";
		}
		if (string_to_int(current->schedule.EndDay) < 10)
		{
			fout << "0" << current->schedule.EndDay << endl;
		}
		else
		{
			fout << current->schedule.EndDay << endl;
		}

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
void output_file_Student_from_csv_to_txt(ofstream& fout, LinkedList lst2,LinkedList lst,Node*currentlst)
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

	//void view_Attendence(LinkedList lst2, LinkedList lst, Node* currentlst)
	//{
	//	Node* current = lst2.head;
	//	while (current != NULL) {
	//		cout << current->student.StudentID << endl;
	//		cout << current->student.StudentPass << endl;
	//		cout << current->data.StudentName << endl;
	//		cout << current->data.StudentDOB << endl;
	//		cout << current->data.StudentGender << endl;
	//		int day = string_to_int(currentlst->data.startDay);
	//		int month = string_to_int(currentlst->data.startMonth);
	//		int year = string_to_int(currentlst->data.startYear);
	//		int temp = string_to_int(currentlst->data.EndDay);
	//		cout << year << " ";
	//		if (month < 10)
	//		{
	//			cout << "0" << month << " ";
	//		}
	//		else
	//		{
	//			cout << month << " ";
	//		}
	//		if (day < 10)
	//		{
	//			cout << "0" << day << " ";
	//		}
	//		else
	//		{
	//			cout << day << " ";
	//		}
	//		cout << currentlst->data.starthour << " ";
	//		cout << currentlst->data.startminute << " ";
	//		cout << currentlst->data.endhour << " ";
	//		cout << currentlst->data.endminute << " ";
	//		cout << "-1" << endl;

	//		while (day != string_to_int(currentlst->data.EndDay)) //&& month != string_to_int(currentlst->data.Endmonth))
	//		{
	//			int temp = day;
	//			temp = temp + 7;
	//			day = day_after_1_week(day, month, year);
	//			if (month == 12)
	//			{
	//				if (temp > day_of_month(month, year))
	//				{
	//					month = 1;
	//				}

	//			}
	//			else
	//			{
	//				if (temp > day_of_month(month, year))
	//				{
	//					month = month + 1;
	//				}
	//			}


	//			cout << year << " ";
	//			if (month < 10)
	//			{
	//				cout << "0" << month << " ";
	//			}
	//			else
	//			{
	//				cout << month << " ";
	//			}
	//			if (day < 10)
	//			{
	//				cout << "0" << day << " ";
	//			}
	//			else
	//			{
	//				cout << day << " ";
	//			}
	//			cout << currentlst->data.starthour << " ";
	//			cout << currentlst->data.startminute << " ";
	//			cout << currentlst->data.endhour << " ";
	//			cout << currentlst->data.endminute << " ";
	//			cout << "-1" << endl;


	//		}


	//		cout << endl;
	//		current = current->next;
	//	}
	//}

	void main_schedule_from_csv_to_txt(LinkedList &lst,LinkedList &lst2)
	{
		string academic;
		string semester;
		string Class;
		char base[101];
		string outputpath;
		//LinkedList lst;
		//LinkedList lst2;
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
		/*outputpath = academic;
		outputpath.append("-");
		outputpath.append(semester);
		outputpath.append("-");
		outputpath.append("schedule");
		outputpath.append("-");
		outputpath.append(Class);
		outputpath.append(".txt");*/
		cout << "pls input the output path you want for file Schedule txt" << endl;
		getline(cin, outputpath);
		ifstream fin;
		ofstream fout;
		fin.open(inputpath);
		if (!fin.is_open())
		{
			cout << "can not open file";
			return;


		}
		else
		{
			load_file(lst, fin, count);
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

		cout << "pls input the input path of the file student APCS1 txt: " << endl;
		cin.getline(base, 100);
		strcpy_s(inputpath, strlen(base) + 1, base);
		fin.open(inputpath);

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

			/*	outputpath = Class;
				outputpath.append("-");
				outputpath.append(current->schedule.courseID);
				outputpath.append(".txt");*/
				cout << "pls input the output path you want for file "<<Class<<"course "<<current->schedule.courseID<< endl;
				getline(cin, outputpath);
				fout.open(outputpath);
				if (!fout.is_open())
				{
					cout << "can not create file";
				}
				else
				{
					output_file_Student_from_csv_to_txt(fout, lst2, lst, current);
					fout.close();
					// view_Attendence(lst2, lst, current);

				}
				count--;
				current = current->next;
				fin.close();
			}

		}

	}


	void option_schedule(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10)
	{
		ifstream fin;
		while (true)
		{
			int choice;
			cout << "You have to load from CSV file in order to do other options !" << endl;
			cout << "Please choose class to load from CSV file" << endl;
			cout << "1. Load schedule 19APCS1" << endl;
			cout << "2. Load schedule 19APCS2" << endl;
			cout << "3. Load schedule 19APCS3" << endl;
			cout << "4. Load schedule 19APCS4" << endl;
			cout << "5. Load schedule 19APCS5" << endl;
			cout << "6. Load schedule 19APCS6" << endl;
			cout << "7. Load schedule 19APCS7" << endl;
			cout << "8. Load schedule 19APCS8" << endl;
			cout << "9. Load schedule 19APCS9" << endl;
			cout << "10. Load schedule 19APCS10" << endl;
			cout << "0. Exiting" << endl;
			cout << "-----@-----" << endl;

			cout << "Your choice: ";
			cin >> choice;
			if (choice == 1)
			{
				
				
					LinkedList student_APCS1;
				/*	cout << "loading 19APCS1 Schedule";
					main_schedule_from_csv_to_txt(APCS1, student_APCS1);*/
					while(true)
					{
						int choice;
						cout << "if you don't have the Schedule txt yet,pls choose 1 to create schedule txt,if you already have you can choose other option" << endl;
						cout << "1.create file schedule txt file" << endl;
						cout << "2.Add course to file" << endl;
						cout << "0.exit" << endl;
						cin >> choice;
						if (choice == 1)
						{

							LinkedList student_APCS1;
							cout << "loading 19APCS1 Schedule";
							main_schedule_from_csv_to_txt(APCS1, student_APCS1);
						}
						else if (choice == 2)
						{
							cin.ignore(1);
							main_add_course(APCS1,student_APCS1);
						}
						else if (choice == 0)
						{
							break;
						}
					}

			}
			else if (choice == 2)
			{
				LinkedList student_APCS2;
				cout << "loading 19APCS2 Schedule";
				main_schedule_from_csv_to_txt(APCS1, student_APCS2);
			}
			else if (choice == 3)
			{
				LinkedList student_APCS3;
				cout << "loading 19APCS3 Schedule";
				main_schedule_from_csv_to_txt(APCS1, student_APCS3);

			}
			else if (choice == 4)
			{
				LinkedList student_APCS4;
				cout << "loading 19APCS4 Schedule";
				main_schedule_from_csv_to_txt(APCS1, student_APCS4);
			}
			else if (choice == 5)
			{
				LinkedList student_APCS5;
				cout << "loading 19APCS5 Schedule";
				main_schedule_from_csv_to_txt(APCS1, student_APCS5);
			}
			else if (choice == 6)
			{
				LinkedList student_APCS6;
				cout << "loading 19APCS6 Schedule";
				main_schedule_from_csv_to_txt(APCS1, student_APCS6);
			}
			else if (choice == 7)
			{
				LinkedList student_APCS7;
				cout << "loading 19APCS7 Schedule";
				main_schedule_from_csv_to_txt(APCS1, student_APCS7);
			}
			else if (choice == 8)
			{
				LinkedList student_APCS8;
				cout << "loading 19APCS8 Schedule";
				main_schedule_from_csv_to_txt(APCS1, student_APCS8);
			}
			else if (choice == 9)
			{
				LinkedList student_APCS9;
				cout << "loading 19APCS9 Schedule";
				main_schedule_from_csv_to_txt(APCS1, student_APCS9);
			}
			else if (choice == 9)
			{
				LinkedList student_APCS10;
				cout << "loading 19APCS10 Schedule";
				main_schedule_from_csv_to_txt(APCS1, student_APCS10);
			}
			else if (choice == 0)
			{
				break;
			}
		}

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

	void Add_course(LinkedList& lst, int& count, Schedule& s)
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

		Node* p = createNode(s);
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


	void main_add_course(LinkedList& lst, LinkedList& lst2)
	{
		Schedule s;
		ofstream fout;
		ifstream fin;
		//LinkedList lst;
		//LinkedList lst2;
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
		char base[101];
		cout << "input the input path of your schedule txt file" << endl;
		//cout << "nhap vao duong dan chua file: " << endl;
		cin.getline(base, 100);
		char inputpath[101];
		strcpy_s(inputpath, strlen(base) + 1, base);

		fin.open(inputpath);
		if (!fin.is_open())
		{
			cout << "can not open schedule file";
			return;
		}
		else
		{
			load_file_schedule_txt(lst, fin, count);
			Add_course(lst, count, s);
			//view_schedule(lst);
			//edit_course(lst);
			//delete_course(lst, count);
			fout.open(inputpath, ios::out);
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
		cout << "input the input path of your student txt file" << endl;
		////cout << "nhap vao duong dan chua file: " << endl;
		cin.getline(base, 100);
		//char inputpath[101];
		strcpy_s(inputpath, strlen(base) + 1, base);

		fin.open(inputpath);
		////fin.open("student.txt");
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

