#include"function.h"
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
Node* createNodeLtr(Lecturer lecturer) {
	Node* p = new Node;
	p->lecturer.username = lecturer.username;
	p->lecturer.password = lecturer.password;
	p->lecturer.fullname = lecturer.fullname;
	p->lecturer.degree = lecturer.degree;
	p->lecturer.gender = lecturer.gender;
	p->next = NULL;
	return p;
}
void load_file(LinkedList& lst, ifstream& fin, int& count)
{
	count = 0;
	string temp;
	lst.head = NULL;
	lst.tail = NULL;
	Node* current = lst.head;
	Schedule s;
	getline(fin, temp, '\n');
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

	getline(fin, s.Room, '\n');
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
		if (string_to_int(current->schedule.startMonth) < 10)
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
			fout << current->schedule.startDay << endl;
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
	if (temp == "-1\n2020") {
		return 2020;
	}
	else if (temp == "-1\n2019") {
		return 2019;
	}
	else if (temp == "-1\n2020") {
		return 2018;
	}
	else if (temp == "-1\n2021") {
		return 2021;
	}
	else if (temp == "-1\n2017") {
		return 2017;
	}
	else {
		int num = 0;
		int size = temp.length();
		if (size < 2) {
			num = (int)(temp[0] - '0');
		}
		else if (size >= 2)
		{
			for (int i = 0; i < size; i++)
			{
				int num2;
				if (temp[i] == '0' || temp[i] == '1' || temp[i] == '2' || temp[i] == '3' ||
					temp[i] == '4' || temp[i] == '5' || temp[i] == '6' || temp[i] == '7' ||
					temp[i] == '8' || temp[i] == '9') {
					num2 = (int)(temp[i] - '0');
					num = num * 10 + num2;
				}
				else {
					num = num;
				}

			}
		}
		return num;
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

		while (1)
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
			if (day == string_to_int(currentlst->schedule.EndDay) && month == string_to_int(currentlst->schedule.Endmonth)) {
				break;
			}

		}
		fout <<1<< endl;
		fout <<endl;
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
//Function(export_Attendence) use for export_Attendence_list_Of_Course Funtion 
void export_Attendence(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst, string inputpath)
{
	ifstream fin;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	else {
		Node* current = lst2.head;
		int i = 0;
		while (current != NULL) {
			int j = 0;
			if (i == 0) {
				getline(fin, current->student.StudentID, '\n');
				getline(fin, current->student.StudentPass, '\n');
				getline(fin, current->student.StudentName, '\n');
				getline(fin, current->student.StudentDOB, '\n');
				getline(fin, current->student.StudentGender, '\n');
				fin >> current->student.midterm;
				fin >> current->student.final;
				fin >> current->student.bonus;
				fin >> current->student.total;
				fin.ignore();
				getline(fin, currentlst->schedule.startYear, ' ');
				getline(fin, currentlst->schedule.startMonth, ' ');
				getline(fin, currentlst->schedule.startDay, ' ');
				getline(fin, currentlst->schedule.starthour, ' ');
				getline(fin, currentlst->schedule.startminute, ' ');
				getline(fin, currentlst->schedule.endhour, ' ');
				getline(fin, currentlst->schedule.endminute, ' ');
				fin >> attendence[i][j];
				fin.ignore();
				j++;
				int n = 1;
				while (n != 10) {
					getline(fin, year1, ' ');
					getline(fin, month1, ' ');
					getline(fin, day1, ' ');
					getline(fin, startHour1, ' ');
					getline(fin, startMinute1, ' ');
					getline(fin, endHour1, ' ');
					getline(fin, endMinute1, ' ');
					fin >> attendence[i][j];
					fin.ignore();
					j++;
					n++;
				}
			}
			else {
				getline(fin, current->student.StudentID, '\n');
				getline(fin, current->student.StudentID, '\n');
				getline(fin, current->student.StudentPass, '\n');
				getline(fin, current->student.StudentName, '\n');
				getline(fin, current->student.StudentDOB, '\n');
				getline(fin, current->student.StudentGender, '\n');
				fin >> current->student.midterm;
				fin >> current->student.final;
				fin >> current->student.bonus;
				fin >> current->student.total;
				fin.ignore();
				getline(fin, currentlst->schedule.startYear, ' ');
				getline(fin, currentlst->schedule.startMonth, ' ');
				getline(fin, currentlst->schedule.startDay, ' ');
				getline(fin, currentlst->schedule.starthour, ' ');
				getline(fin, currentlst->schedule.startminute, ' ');
				getline(fin, currentlst->schedule.endhour, ' ');
				getline(fin, currentlst->schedule.endminute, ' ');
				fin >> attendence[i][j];
				fin.ignore();
				j++;
				int n = 1;
				while (n != 10) {
					getline(fin, year1, ' ');
					getline(fin, month1, ' ');
					getline(fin, day1, ' ');
					getline(fin, startHour1, ' ');
					getline(fin, startMinute1, ' ');
					getline(fin, endHour1, ' ');
					getline(fin, endMinute1, ' ');
					fin >> attendence[i][j];
					fin.ignore();
					j++;
					n++;
				}
			}

			current = current->next;
			i++;
		}
		fin.close();
	}
	Node* current = lst2.head;
	while (current != NULL) {
		fout << current->student.StudentID << endl;
		fout << current->student.StudentPass << endl;
		fout << current->student.StudentName << endl;
		fout << current->student.StudentDOB << endl;
		fout << current->student.StudentGender << endl;
		int day = string_to_int(currentlst->schedule.startDay);
		int month = string_to_int(currentlst->schedule.startMonth);
		int year = string_to_int(currentlst->schedule.startYear);
		int temp = string_to_int(currentlst->schedule.EndDay);
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


			fout << 2020 << " ";
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


		fout << endl;
		current = current->next;
	}
	fout.close();
}

//Ham 26 Search and view Attendence_List_Of_Course
void view_Attendence_List_Of_Course(LinkedList lst, LinkedList lst2) {
	Node* current = lst.head;
	string class_View, courseID_View, Class,inputpath;
	ifstream fin;
	while (1) {
		view_List_Of_Course(lst);
		cout << "0. back\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to view:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->schedule.classs && courseID_View == current->schedule.courseID) {
					inputpath = current->schedule.classs;
					inputpath.append("-");
					inputpath.append(current->schedule.courseID);
					inputpath.append(".txt");
					view_2(inputpath, lst2, lst, current);
					current = lst.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lst.head;
					break;
				}
			}
		}
	}
}
//Ham 27 export_Attendence_list_Of_Course
void export_Attendence_list_Of_Course( LinkedList lst, LinkedList lst2) {
	ofstream fout;
	string class_View, courseID_View, outputpath, inputpath;
	Node* current = lst.head;
	while (1) {
		view_List_Of_Course(lst);
		cout << "0. back\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to view:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->schedule.classs && courseID_View == current->schedule.courseID) {
					inputpath = current->schedule.classs;
					inputpath.append("-");
					inputpath.append(current->schedule.courseID);
					inputpath.append(".txt");
					outputpath = "";
					outputpath.append(current->schedule.classs);
					outputpath.append("-");
					outputpath.append(current->schedule.courseID);
					outputpath.append("-Attendence");
					outputpath.append(".csv");
					fout.open(outputpath);
					if (!fout.is_open())
					{
						cout << "can not create" << outputpath << " file";
					}
					else
					{
						export_Attendence(fout, lst2, lst, current, inputpath);
						fout.close();
						cout << "Export successfully\n";
						current = lst.head;
						break;
					}
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lst.head;
					break;
				}
			}
		}
	}
}
//Ham 28 View list of courses in the current semester
void view_List_Of_Course(LinkedList lst) {
	Node* current2 = lst.head;
	while (current2 != NULL) {
		cout << current2->schedule.No << "." << current2->schedule.classs << "-" << current2->schedule.courseID << "\n";
		current2 = current2->next;
	}
}
void view_List_Student_Of_Course(LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View) {
	Node* current = lst.head;
	string inputpath;
	int attendence[100][100];
	int active[100];
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	ifstream fin;
	while (1) {
		view_List_Of_Course(lst);
		cout << "0. back\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to view:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->schedule.classs && courseID_View == current->schedule.courseID) {
					inputpath = current->schedule.classs;
					inputpath.append("-");
					inputpath.append(current->schedule.courseID);
					inputpath.append(".txt");
					fin.open(inputpath);
					fin.open(inputpath);
					if (!fin.is_open()) {
						cout << "can't open " << inputpath << " file";
					}
						Node* current = lst2.head;
						int i = 0;
						while (current != NULL) {
							int j = 0;
							if (i == 0) {
								getline(fin, current->student.StudentID, '\n');
							}
							else {
								getline(fin, current->student.StudentID, '\n');
								getline(fin, current->student.StudentID, '\n');
							}
							getline(fin, current->student.StudentPass, '\n');
							getline(fin, current->student.StudentName, '\n');
							getline(fin, current->student.StudentDOB, '\n');
							getline(fin, current->student.StudentGender, '\n');
							fin >> current->student.midterm;
							fin >> current->student.final;
							fin >> current->student.bonus;
							fin >> current->student.total;
							fin.ignore();
							getline(fin, year1, ' ');
							getline(fin, month1, ' ');
							getline(fin, day1, ' ');
							getline(fin, startHour1, ' ');
							getline(fin, startMinute1, ' ');
							getline(fin, endHour1, ' ');
							getline(fin, endMinute1, ' ');
							fin >> attendence[i][j];
							fin.ignore();
							j++;
							int n = 1;
							while (n != 10) {
								getline(fin, year1, ' ');
								getline(fin, month1, ' ');
								getline(fin, day1, ' ');
								getline(fin, startHour1, ' ');
								getline(fin, startMinute1, ' ');
								getline(fin, endHour1, ' ');
								getline(fin, endMinute1, ' ');
								fin >> attendence[i][j];
								if (n < 9) {
									fin.ignore();
								}
								j++;
								n++;
							}
							fin >> active[i];
							fin.ignore();
							current = current->next;
							i++;
						}
						fin.close();
					
					
				    current = lst2.head;
					while (current != NULL) {
						cout << current->student.StudentID << endl;
						cout << current->student.StudentPass << endl;
						cout << current->student.StudentName << endl;
						cout << current->student.StudentDOB << endl;
						cout << current->student.StudentGender << endl;
						cout << endl;
						current = current->next;
					}
					current = lst.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lst.head;
					break;
				}
			}
		}
	}
}
void view_2(string inputpath, LinkedList& lst2, LinkedList lst, Node* currentlst)
{
	ifstream fin;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	else {
		Node* current = lst2.head;
		int i = 0;
		while (current != NULL) {
			int j = 0;
			if (i == 0) {
				getline(fin, current->student.StudentID, '\n');
			}
			else {
				getline(fin, current->student.StudentID, '\n');
				getline(fin, current->student.StudentID, '\n');
			}
				getline(fin, current->student.StudentPass, '\n');
				getline(fin, current->student.StudentName, '\n');
				getline(fin, current->student.StudentDOB, '\n');
				getline(fin, current->student.StudentGender, '\n');
				fin >> current->student.midterm;
				fin >> current->student.final;
				fin >> current->student.bonus;
				fin >> current->student.total;
				fin.ignore();
				getline(fin, currentlst->schedule.startYear, ' ');
				getline(fin, currentlst->schedule.startMonth, ' ');
				getline(fin, currentlst->schedule.startDay, ' ');
				getline(fin, currentlst->schedule.starthour, ' ');
				getline(fin, currentlst->schedule.startminute, ' ');
				getline(fin, currentlst->schedule.endhour, ' ');
				getline(fin, currentlst->schedule.endminute, ' ');
				fin >> attendence[i][j];
				fin.ignore();
				j++;
				int n = 1;
				while (n != 10) {
					getline(fin, year1, ' ');
					getline(fin, month1, ' ');
					getline(fin, day1, ' ');
					getline(fin, startHour1, ' ');
					getline(fin, startMinute1, ' ');
					getline(fin, endHour1, ' ');
					getline(fin, endMinute1, ' ');
					fin >> attendence[i][j];
					if (n < 9) {
						fin.ignore();
					}
					j++;
					n++;
				}
			fin >> active[i];
			fin.ignore();
			current = current->next;
			i++;
		}
		fin.close();
	}
	Node* current = lst2.head;
	int i = 0;
	while (current->next != NULL) {
		cout << current->student.StudentID << endl;
		cout << current->student.StudentPass << endl;
		cout << current->student.StudentName << endl;
		cout << current->student.StudentDOB << endl;
		cout << current->student.StudentGender << endl;
	    cout << current->student.midterm << endl;
		cout << current->student.final <<  endl;
		cout << current->student.bonus <<  endl;
		cout << current->student.total << endl;
		int day = string_to_int(currentlst->schedule.startDay);
		int month = string_to_int(currentlst->schedule.startMonth);
		int year = string_to_int(currentlst->schedule.startYear);
		int temp = string_to_int(currentlst->schedule.EndDay);
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
		cout << currentlst->schedule.starthour << " ";
		cout << currentlst->schedule.startminute << " ";
		cout << currentlst->schedule.endhour << " ";
		cout << currentlst->schedule.endminute << " ";
		int j = 0;
		cout << attendence[i][j] << endl;
		j++;
		while (day != string_to_int(currentlst->schedule.EndDay)) //&& month != string_to_int(currentlst->schedule.endmonth))
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
			cout << currentlst->schedule.starthour << " ";
			cout << currentlst->schedule.startminute << " ";
			cout << currentlst->schedule.endhour << " ";
			cout << currentlst->schedule.endminute << " ";
			cout << attendence[i][j] << endl;
			j++;
		}
		cout << active[i];
		cout << endl;
		i++;
		current = current->next;
		cout << endl;
	}

}

void edit_Attendence(ofstream &fout,string inputpath, string outputpath,LinkedList& lst2, LinkedList lst, Node* currentlst, string studentID_edit, int year_edit, int month_edit, int day_edit, int attend)
{
	ifstream fin;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int a = -100;
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	else {
		Node* current = lst2.head;
		int i = 0;
		while (current != NULL) {
			int j = 0;
			if (i == 0) {
				getline(fin, current->student.StudentID, '\n');
			}
			else {
				getline(fin, current->student.StudentID, '\n');
				getline(fin, current->student.StudentID, '\n');
			}
			getline(fin, current->student.StudentPass, '\n');
			getline(fin, current->student.StudentName, '\n');
			getline(fin, current->student.StudentDOB, '\n');
			getline(fin, current->student.StudentGender, '\n');
			fin >> current->student.midterm;
			fin >> current->student.final;
			fin >> current->student.bonus;
			fin >> current->student.total;
			fin.ignore();
			getline(fin, currentlst->schedule.startYear, ' ');
			getline(fin, currentlst->schedule.startMonth, ' ');
			getline(fin, currentlst->schedule.startDay, ' ');
			getline(fin, currentlst->schedule.starthour, ' ');
			getline(fin, currentlst->schedule.startminute, ' ');
			getline(fin, currentlst->schedule.endhour, ' ');
			getline(fin, currentlst->schedule.endminute, ' ');
			fin >> attendence[i][j];
			fin.ignore();
			j++;
			int n = 1;
			while (n != 10) {
				getline(fin, year1, ' ');
				getline(fin, month1, ' ');
				getline(fin, day1, ' ');
				getline(fin, startHour1, ' ');
				getline(fin, startMinute1, ' ');
				getline(fin, endHour1, ' ');
				getline(fin, endMinute1, ' ');
				fin >> attendence[i][j];
				if (n < 9) {
					fin.ignore();
				}
				j++;
				n++;
			}
			fin >> active[i];
			fin.ignore();
			current = current->next;
			i++;
		}
		fin.close();
	}
	Node* current = lst2.head;
	fout.open(outputpath);
	if (!fout.is_open()) {
		cout << "can't create " << outputpath << " file ";
	}
	else {
		int i = 0;
		while (current != NULL) {
			fout << current->student.StudentID << endl;
			fout << current->student.StudentPass << endl;
			fout << current->student.StudentName << endl;
			fout << current->student.StudentDOB << endl;
			fout << current->student.StudentGender << endl;
			fout << current->student.midterm << endl;
			fout << current->student.final << endl;
			fout << current->student.bonus << endl;
			fout << current->student.total << endl;
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
			int j = 0;
			if (year_edit == year && month_edit == month && day_edit == day) {
				if (studentID_edit == current->student.StudentID) {
					attendence[i][j] = attend;
					a = 100;
				}
			}
			fout << attendence[i][j] << endl;
			j++;
			while (day != string_to_int(currentlst->schedule.EndDay)) //&& month != string_to_int(currentlst->schedule.endmonth))
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
				if (year_edit==year&&month_edit==month&&day_edit==day) {
					if (studentID_edit == current->student.StudentID) {
						attendence[i][j] = attend;
						a = 100;
					}
				}
				fout << attendence[i][j] << endl;
				j++;
			}
			fout << active[i] << endl<<endl;
			i++;
			current = current->next;
		}
	}
	if (a == 100) {
		cout << "\nEdit successfully\n";
	}
	else {
		cout << "\ncan't Edit\n";
	}
	fout.close();
}
void edit_Attendence_Of_Course(ofstream& fout, LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View, string Class,string &studentID_edit,int &year_edit,int &month_edit,int &day_edit,int &attend) {
	Node* current = lst.head;
	string inputpath,outputpath;
	ifstream fin;
	while (1) {
		view_List_Of_Course(lst);
		cout << "0. back\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to view:";
		getline(cin, courseID_View);
		cout << "Enter student ID to edit: ";
		getline(cin, studentID_edit);
		cout << "Enter year to edit: ";
		cin >> year_edit;
		cout << "Enter month to edit: ";
		cin >> month_edit;
		cout << "Enter day to edit: ";
		cin >> day_edit;
		cout << "Enter attendence to edit: ";
		cin >> attend;
		cout << "\n 1 is active , 0 is dropped\n";
		cin.ignore();

		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->schedule.classs && courseID_View == current->schedule.courseID) {
					inputpath = current->schedule.classs;
					inputpath.append("-");
					inputpath.append(current->schedule.courseID);
					inputpath.append(".txt");
					outputpath = inputpath;
					view_2(inputpath, lst2, lst, current);
					edit_Attendence(fout, inputpath, outputpath, lst2, lst, current,studentID_edit,year_edit,month_edit,day_edit,attend);
					cout << "\n After edit: \n";
					view_2(inputpath, lst2, lst, current);
					current = lst.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lst.head;
					break;
				}
			}
		}
	}
}
void import_Scoreboard(string inputpath, string outputpath, LinkedList& lst2, LinkedList lst, Node* currentlst) {
	ifstream fin;
	ofstream fout; 
	string temp1;
	int attendence[100][100];
	int a = -100;
	int active[100];
	fin.open(outputpath);
	if (!fin.is_open()) {
		cout << "can't open " << outputpath << " file";
	}
	else {
		Node* current = lst2.head;
		int i = 0;
		while (current != NULL) {
			int j = 0;
			if (i == 0) {
				getline(fin, current->student.StudentID, '\n');
			}
			else {
				getline(fin, current->student.StudentID, '\n');
				getline(fin, current->student.StudentID, '\n');
			}
			getline(fin, current->student.StudentPass, '\n');
			getline(fin, current->student.StudentName, '\n');
			getline(fin, current->student.StudentDOB, '\n');
			getline(fin, current->student.StudentGender, '\n');
			fin >> current->student.midterm;
			fin >> current->student.final;
			fin >> current->student.bonus;
			fin >> current->student.total;
			fin.ignore();
			getline(fin, currentlst->schedule.startYear, ' ');
			getline(fin, currentlst->schedule.startMonth, ' ');
			getline(fin, currentlst->schedule.startDay, ' ');
			getline(fin, currentlst->schedule.starthour, ' ');
			getline(fin, currentlst->schedule.startminute, ' ');
			getline(fin, currentlst->schedule.endhour, ' ');
			getline(fin, currentlst->schedule.endminute, ' ');
			fin >> attendence[i][j];
			fin.ignore();
			j++;
			int n = 1;
			while (n != 10) {
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				fin >> attendence[i][j];
				if (n < 9) {
					fin.ignore();
				}
				j++;
				n++;
			}
			fin >> active[i];
			fin.ignore();
			current = current->next;
			i++;
		}
		fin.close();
	}
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file \n";
	}
	else {
		getline(fin, temp1, '\n');
		Node* current = lst2.head;
		char a;
		while (current!=NULL) {
			getline(fin, temp1, ',');
			getline(fin, current->student.StudentID, ',');
			getline(fin, current->student.StudentName, ',');
			fin>> current->student.midterm;
			fin.ignore();
			fin >> a;
			fin>> current->student.final;
			current->student.final += int(a - '0');
			fin.ignore();
			fin >> a;
			fin>> current->student.bonus ;
			current->student.bonus += int(a - '0');
			fin.ignore();
			fin >> a;
			fin>> current->student.total;
			current->student.total += int(a - '0');
			fin.ignore();
			current = current->next;
		}
		cout << "Import sucessfully\n";
	}
	fin.close();
	 Node* current = lst2.head;
	fout.open(outputpath);
	if (!fout.is_open()) {
		cout << "can't create " << outputpath << " file ";
	}
	else {
		int i = 0;
		while (current != NULL) {
			fout << current->student.StudentID << endl;
			fout << current->student.StudentPass << endl;
			fout << current->student.StudentName << endl;
			fout << current->student.StudentDOB << endl;
			fout << current->student.StudentGender << endl;
			fout << current->student.midterm << endl;
			fout << current->student.final << endl;
			fout << current->student.bonus << endl;
			fout << current->student.total << endl;
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
			int j = 0;
			fout << attendence[i][j] << endl;
			j++;
			while (day != string_to_int(currentlst->schedule.EndDay)) //&& month != string_to_int(currentlst->schedule.endmonth))
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
				fout << attendence[i][j] << endl;
				j++;
			}
			fout << active[i] << endl<<endl;
			i++;
			current = current->next;
		}
	}
	fout.close();
}
void import_Scoreboard_Of_Course(LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View, string Class, string& inputpath) {
	Node* current = lst.head;
	string outputpath;
	ifstream fin;
	while (1) {
		view_List_Of_Course(lst);
		cout << "0. back\n";
		cout << "Enter Class of courese to import: ";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to import: ";
		getline(cin, courseID_View);
		cout << "Enter Scoreboard csv file: ";
		getline(cin,inputpath);

		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->schedule.classs && courseID_View == current->schedule.courseID) {
					outputpath = current->schedule.classs;
					outputpath.append("-");
					outputpath.append(current->schedule.courseID);
					outputpath.append(".txt");
					import_Scoreboard(inputpath, outputpath, lst2, lst, current);
					current = lst.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lst.head;
					break;
				}
			}
		}
	}
}
void view_Scoreboard(string inputpath, LinkedList& lst2, LinkedList lst, Node* currentlst) {
	ifstream fin;
	string temp1;
	int attendence[100][100];
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	else {
		Node* current = lst2.head;
		int i = 0;
		while (current != NULL) {
			int j = 0;
			if (i == 0) {
				getline(fin, current->student.StudentID, '\n');
			}
			else {
				getline(fin, current->student.StudentID, '\n');
				getline(fin, current->student.StudentID, '\n');
			}
			getline(fin, current->student.StudentPass, '\n');
			getline(fin, current->student.StudentName, '\n');
			getline(fin, current->student.StudentDOB, '\n');
			getline(fin, current->student.StudentGender, '\n');
			fin >> current->student.midterm;
			fin >> current->student.final;
			fin >> current->student.bonus;
			fin >> current->student.total;
			fin.ignore();
			getline(fin, currentlst->schedule.startYear, ' ');
			getline(fin, currentlst->schedule.startMonth, ' ');
			getline(fin, currentlst->schedule.startDay, ' ');
			getline(fin, currentlst->schedule.starthour, ' ');
			getline(fin, currentlst->schedule.startminute, ' ');
			getline(fin, currentlst->schedule.endhour, ' ');
			getline(fin, currentlst->schedule.endminute, ' ');
			fin >> attendence[i][j];
			fin.ignore();
			j++;
			int n = 1;
			while (n != 10) {
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				fin >> attendence[i][j];
				if (n < 9) {
					fin.ignore();
				}
				j++;
				n++;
			}
			fin >> active[i];
			fin.ignore();
			current = current->next;
			i++;
		}
		fin.close();
	}
	Node* current = lst2.head;
	int i = 1;
		while (current != NULL) {
			cout << i << "\n";
			cout << current->student.StudentID << endl;
			cout << current->student.StudentPass << endl;
			cout << current->student.StudentName << endl;
			cout << current->student.StudentDOB << endl;
			cout << current->student.StudentGender << endl;
			cout << current->student.midterm << endl;
			cout << current->student.final << endl;
			cout << current->student.bonus << endl;
			cout << current->student.total << endl << endl;
			i++;
			current = current->next;
		}
}

void view_Scoreboard_Of_Course(LinkedList lst, LinkedList lst2,string Class) {
	cout << "\n view_Scoreboard_Of_Course function\n";
	Node* current = lst.head;
	string inputpath, class_View, courseID_View ;
	ifstream fin;
	while (1) {
		view_List_Of_Course(lst);
		cout << "0. back\n";
		cout << "Enter Class of courese to view: ";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to view: ";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->schedule.classs && courseID_View == current->schedule.courseID) {
					inputpath = current->schedule.classs;
					inputpath.append("-");
					inputpath.append(current->schedule.courseID);
					inputpath.append(".txt");
					view_Scoreboard(inputpath, lst2, lst, current);
					current = lst.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lst.head;
					break;
				}
			}
		}
	}
}
void edit_Grade(string inputpath, LinkedList& lst2, LinkedList lst, Node* currentlst, string studentID_View) {
	ifstream fin;
	ofstream fout;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int a = -100;
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	else {
		Node* current = lst2.head;
		int i = 0;
		while (current != NULL) {
			int j = 0;
			if (i == 0) {
				getline(fin, current->student.StudentID, '\n');
			}
			else {
				getline(fin, current->student.StudentID, '\n');
				getline(fin, current->student.StudentID, '\n');
			}
			getline(fin, current->student.StudentPass, '\n');
			getline(fin, current->student.StudentName, '\n');
			getline(fin, current->student.StudentDOB, '\n');
			getline(fin, current->student.StudentGender, '\n');
			fin >> current->student.midterm;
			fin >> current->student.final;
			fin >> current->student.bonus;
			fin >> current->student.total;
			fin.ignore();
			getline(fin, currentlst->schedule.startYear, ' ');
			getline(fin, currentlst->schedule.startMonth, ' ');
			getline(fin, currentlst->schedule.startDay, ' ');
			getline(fin, currentlst->schedule.starthour, ' ');
			getline(fin, currentlst->schedule.startminute, ' ');
			getline(fin, currentlst->schedule.endhour, ' ');
			getline(fin, currentlst->schedule.endminute, ' ');
			fin >> attendence[i][j];
			fin.ignore();
			j++;
			int n = 1;
			while (n != 10) {
				getline(fin, year1, ' ');
				getline(fin, month1, ' ');
				getline(fin, day1, ' ');
				getline(fin, startHour1, ' ');
				getline(fin, startMinute1, ' ');
				getline(fin, endHour1, ' ');
				getline(fin, endMinute1, ' ');
				fin >> attendence[i][j];
				if (n < 9) {
					fin.ignore();
				}
				j++;
				n++;
			}
			fin >> active[i];
			fin.ignore();
			current = current->next;
			i++;
		}
		fin.close();
	}
	Node* current = lst2.head;
	fout.open(inputpath);
	if (!fout.is_open()) {
		cout << "can't create " <<inputpath << " file ";
	}
	else {
		int i = 0;
		while (current != NULL) {
			if (studentID_View == current->student.StudentID) {
				a = 100;
				cout << "Enter Midterm Scorce: ";
				cin >> current->student.midterm;
				cout << "Enter Final Scorce: ";
				cin >> current->student.final;
				cout << "Enter Bonus Scorce: ";
				cin >> current->student.bonus;
				cout << "Enter Total Scorce: ";
				cin >> current->student.total;
			}
			fout << current->student.StudentID << endl;
			fout << current->student.StudentPass << endl;
			fout << current->student.StudentName << endl;
			fout << current->student.StudentDOB << endl;
			fout << current->student.StudentGender << endl;
			fout << current->student.midterm << endl;
			fout << current->student.final << endl;
			fout << current->student.bonus << endl;
			fout << current->student.total << endl;
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
			int j = 0;
			fout << attendence[i][j] << endl;
			j++;
			while (day != string_to_int(currentlst->schedule.EndDay)) //&& month != string_to_int(currentlst->schedule.endmonth))
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
				fout << attendence[i][j] << endl;
				j++;
			}
			fout << active[i] << endl << endl;
			i++;
			current = current->next;
		}
	}
	if (a == 100) {
		cout << "\nEdit successfully\n";
	}
	else {
		cout << "\nStudent ID not exist \n";
	}
	fout.close();
}
void edit_Grade_Of_a_Student(LinkedList lst, LinkedList lst2, string Class) {
	cout << "\n edit_Grade_Of_a_Student\n";
	string class_View; string courseID_View; string studentID_View;
	Node* current = lst.head;
	string inputpath;
	while (1) {
		view_List_Of_Course(lst);
		cout << "0. back\n";
		cout << "Enter Class of courese to edit grade: ";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to edit grade: ";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->schedule.classs && courseID_View == current->schedule.courseID) {
					inputpath = current->schedule.classs;
					inputpath.append("-");
					inputpath.append(current->schedule.courseID);
					inputpath.append(".txt");
					cout << "Enter Student ID to edit grade: ";
					getline(cin, studentID_View);
					edit_Grade(inputpath, lst2, lst, current, studentID_View);
					current = lst.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lst.head;
					break;
				}
			}
		}
	}
}
void export_Grade(string inputpath,string outputpath, LinkedList& lst2, LinkedList lst, Node* currentlst) {
	ifstream fin;
	ofstream fout;
	string temp1;
	int attendence[100][100];
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	else {
		Node* current = lst2.head;
		int i = 0;
		while (current != NULL) {
			int j = 0;
			if (i == 0) {
				getline(fin, current->student.StudentID, '\n');
			}
			else {
				getline(fin, current->student.StudentID, '\n');
				getline(fin, current->student.StudentID, '\n');
			}
			getline(fin, current->student.StudentPass, '\n');
			getline(fin, current->student.StudentName, '\n');
			getline(fin, current->student.StudentDOB, '\n');
			getline(fin, current->student.StudentGender, '\n');
			fin >> current->student.midterm;
			fin >> current->student.final;
			fin >> current->student.bonus;
			fin >> current->student.total;
			fin.ignore();
			getline(fin, currentlst->schedule.startYear, ' ');
			getline(fin, currentlst->schedule.startMonth, ' ');
			getline(fin, currentlst->schedule.startDay, ' ');
			getline(fin, currentlst->schedule.starthour, ' ');
			getline(fin, currentlst->schedule.startminute, ' ');
			getline(fin, currentlst->schedule.endhour, ' ');
			getline(fin, currentlst->schedule.endminute, ' ');
			fin >> attendence[i][j];
			fin.ignore();
			j++;
			int n = 1;
			while (n != 10) {
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				getline(fin, temp1, ' ');
				fin >> attendence[i][j];
				if (n < 9) {
					fin.ignore();
				}
				j++;
				n++;
			}
			fin >> active[i];
			fin.ignore();
			current = current->next;
			i++;
		}
		fin.close();
	}
	Node* current = lst2.head;
	fout.open(outputpath);
	if (!fout.is_open()) {
		cout << "/n Can't open " << outputpath << " file";
	}
	else {
		int i = 1;
		fout << "No,Student ID,Fullname,Midterm,Final,Bonus,Total\n";
		while (current != NULL) {
			fout << i << ",";
			fout << current->student.StudentID << ',';
			fout << current->student.StudentName << ',';
			fout << current->student.midterm << ',';
			fout << current->student.final << ',';
			fout << current->student.bonus << ',';
			fout << current->student.total <<endl;
			i++;
			current = current->next;
		}
		cout << "\n Export Scoreboard to csv file sucessfully \n";
	}
	fout.close();
}
void export_Grade_Of_Course(LinkedList lst, LinkedList lst2, string Class) {
	cout << "\n export_Grade_Of_Course function\n";
	string class_View; string courseID_View; string studentID_View;
	Node* current = lst.head;
	string inputpath,outputpath;
	while (1) {
		view_List_Of_Course(lst);
		cout << "0. back\n";
		cout << "Enter Class of courese to export grade: ";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to export grade: ";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->schedule.classs && courseID_View == current->schedule.courseID) {
					inputpath = current->schedule.classs;
					inputpath.append("-");
					inputpath.append(current->schedule.courseID);
					inputpath.append(".txt");
					outputpath = current->schedule.classs;
					outputpath.append("-");
					outputpath.append(current->schedule.courseID);
					outputpath.append("-");
					outputpath.append("Scoreboard");
					outputpath.append("-");
					outputpath.append("Export");
					outputpath.append(".csv");
					export_Grade(inputpath, outputpath,lst2, lst, current);
					current = lst.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lst.head;
					break;
				}
			}
		}
	}
}

void viewLecturer(LinkedList lst) {
	ifstream fin;
	int n;
	fin.open("C:\\Users\\admin\\source\\repos\\Test\\Projec lam lai ham 23 26 27 28 30\\Lecturer.txt");
	if (!fin.is_open()) {
		cout << "can't open Lecturer.txt file";
	}
	lst.head = NULL;
	Lecturer lecturer;
	fin >> n;
	string username, password, fullname, degree;
	int gender;
	fin.ignore();
	int i = 0;
	getline(fin, lecturer.username, '\n');
	getline(fin, lecturer.password, '\n');
	getline(fin, lecturer.fullname, '\n');
	getline(fin, lecturer.degree, '\n');
	fin >> lecturer.gender;
	fin.ignore();
	Node* p = createNodeLtr(lecturer);
	lst.head = p;
	Node* current = lst.head;
	current->lecturer.order = 1;
	int b = 1;
	for (int i = 1; i < n; i++) {
		fin.ignore();
		getline(fin, lecturer.username, '\n');
		getline(fin, lecturer.username, '\n');
		getline(fin, lecturer.password, '\n');
		getline(fin, lecturer.fullname, '\n');
		getline(fin, lecturer.degree, '\n');
		fin >> lecturer.gender;
		fin.ignore();
		p = p = createNodeLtr(lecturer);
		current->next = p;
		current = current->next;
		b++;
		current->lecturer.order = b;
	}
	fin.close();
	current = lst.head;
	while (current != NULL) {
		cout << current->lecturer.order << ".\n";
		cout << current->lecturer.username << "\n";
		cout << current->lecturer.password << "\n";
		cout << current->lecturer.fullname << "\n";
		cout << current->lecturer.degree << "\n";
		if (current->lecturer.gender == 0) {
			cout << "Male";
		}
		else {
			cout << "Female";
		}
		cout << "\n" << "\n";
		current = current->next;
	}
}
Node* createNode_Course(Course course) {
	Node* p = new Node;
	p->course.classs = course.classs;
	p->course.courseID = course.courseID;
	p->next = NULL;
	return p;
}
void view_List_Of_Course2(LinkedList &lstCourse) {
	ifstream fin;
	Course course;
	fin.open("C:\\Users\\admin\\source\\repos\\Test\\Projec lam lai ham 23 26 27 28 30\\List_Of_Course.txt");
	if (!fin.is_open()) {
		cout << "can't open List_Of_Course.txt";
	}
	getline(fin, course.classs, '-');
	getline(fin, course.courseID, '\n');
	lstCourse.head = createNode_Course(course);
	Node* current = lstCourse.head;
	while (1) {
		getline(fin, course.classs, '-');
		if (course.classs == "123") {
			break;
		}
		getline(fin, course.courseID, '\n');
		Node* p = createNode_Course(course);
		current->next = p;
		current = current->next;
	}
	current = lstCourse.head;
	int i = 1;
	while (current != NULL) {
		cout << i << "." << current->course.classs << "-" << current->course.courseID << "\n";
		i++;
		current = current->next;
	}
}
void main_View_Attendence_List_Of_Course()
{
	LinkedList lstCourse,lst2,lst;
	string class_View, courseID_View, Class, inputpath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. back\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to view:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classs && courseID_View == current->course.courseID) {
					inputpath="C:\\Users\\admin\\source\\repos\\Test\\Projec lam lai ham 23 26 27 28 30\\";
					inputpath.append(current->course.classs);
					inputpath.append("-");
					inputpath.append(current->course.courseID);
					inputpath.append(".txt");
					view_3(inputpath);
					current = lstCourse.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lstCourse.head;
					break;
				}
			}
		}
	}
}
void view_3(string inputpath)
{
	ifstream fin;
	LinkedList lst2,lst; 
	Student student;
	Schedule schedule;
	
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.StudentID, '\n');
	getline(fin, student.StudentPass, '\n');
	getline(fin, student.StudentName, '\n');
	getline(fin, student.StudentDOB, '\n');
	getline(fin, student.StudentGender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.StudentID = student.StudentID;
	p->student.StudentPass = student.StudentPass;
	p->student.StudentName = student.StudentName;
	p->student.StudentDOB = student.StudentDOB;
	p->student.StudentGender = student.StudentGender;
	p->student.midterm = student.midterm;
	p->student.final = student.final;
	p->student.bonus = student.bonus;
	p->student.total = student.total;
	p->next = NULL;
	lst2.head = p;
	Node* current = lst2.head;
	fin.ignore();
	getline(fin, schedule.startYear, ' ');
	getline(fin, schedule.startMonth, ' ');
	getline(fin, schedule.startDay, ' ');
	getline(fin, schedule.starthour, ' ');
	getline(fin, schedule.startminute, ' ');
	getline(fin, schedule.endhour, ' ');
	getline(fin, schedule.endminute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.starthour = schedule.starthour;
	p->schedule.startminute = schedule.startminute;
	p->schedule.endhour = schedule.endhour;
	p->schedule.endminute = schedule.endminute;
	p->next = NULL;
	lst.head = p;
	Node* currentlst = lst.head;
	fin >> attendence[i][j];
	fin.ignore();
	j++;
	int n = 1;
	while (n != 10) {
		getline(fin, year1, ' ');
		getline(fin, month1, ' ');
		getline(fin, day1, ' ');
		getline(fin, startHour1, ' ');
		getline(fin, startMinute1, ' ');
		getline(fin, endHour1, ' ');
		getline(fin, endMinute1, ' ');
		fin >> attendence[i][j];
		if (n < 9) {
			fin.ignore();
		}
		j++;
		n++;
	}
	fin >> active[i];
	fin.ignore();
	i++;
	while (!fin.eof()) {
		j = 0;
		getline(fin, student.StudentID, '\n');
		getline(fin, student.StudentID, '\n');
		getline(fin, student.StudentPass, '\n');
		getline(fin, student.StudentName, '\n');
		getline(fin, student.StudentDOB, '\n');
		getline(fin, student.StudentGender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.StudentID = student.StudentID;
		p->student.StudentPass = student.StudentPass;
		p->student.StudentName = student.StudentName;
		p->student.StudentDOB = student.StudentDOB;
		p->student.StudentGender = student.StudentGender;
		p->student.midterm = student.midterm;
		p->student.final = student.final;
		p->student.bonus = student.bonus;
		p->student.total = student.total;
		p->next = NULL;
		current->next = p;
		current = current->next;
		fin.ignore();
		getline(fin, year1, ' ');
		getline(fin, month1, ' ');
		getline(fin, day1, ' ');
		getline(fin, startHour1, ' ');
		getline(fin, startMinute1, ' ');
		getline(fin, endHour1, ' ');
		getline(fin, endMinute1, ' ');
		fin >> attendence[i][j];
		fin.ignore();
		j++;
		int n = 1;
		while (n != 10) {
			if (n == 9) {
				getline(fin, schedule.EndYear, ' ');
				getline(fin, schedule.Endmonth, ' ');
				getline(fin, schedule.EndDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.EndDay = schedule.EndDay;
				p->schedule.Endmonth = schedule.Endmonth;
				p->schedule.EndYear = schedule.EndYear;
				p->schedule.starthour = schedule.starthour;
				p->schedule.startminute = schedule.startminute;
				p->schedule.endhour = schedule.endhour;
				p->schedule.endminute = schedule.endminute;
				p->next = NULL;
				lst.head = p;
				Node* currentlst = lst.head;
			}
			else {
				getline(fin, year1, ' ');
				getline(fin, month1, ' ');
				getline(fin, day1, ' ');
			}
			getline(fin, startHour1, ' ');
			getline(fin, startMinute1, ' ');
			getline(fin, endHour1, ' ');
			getline(fin, endMinute1, ' ');
			fin >> attendence[i][j];
			if (n < 9) {
				fin.ignore();
			}
			j++;
			n++;
		}
		fin >> active[i];
		fin.ignore();
		i++;
	}
	fin.close();

	 currentlst = lst.head;
	 current = lst2.head;
	 i = 0;
	while (current->next != NULL) {
		cout << current->student.StudentID << endl;
		cout << current->student.StudentPass << endl;
		cout << current->student.StudentName << endl;
		cout << current->student.StudentDOB << endl;
		cout << current->student.StudentGender << endl;
		int day = string_to_int(currentlst->schedule.startDay);
		int month = string_to_int(currentlst->schedule.startMonth);
		int year = string_to_int(currentlst->schedule.startYear);
		int temp = string_to_int(currentlst->schedule.EndDay);
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
		cout << currentlst->schedule.starthour << " ";
		cout << currentlst->schedule.startminute << " ";
		cout << currentlst->schedule.endhour << " ";
		cout << currentlst->schedule.endminute << " ";
		int j = 0;
		cout << attendence[i][j] << endl;
		j++;
		while (1) //&& month != string_to_int(currentlst->schedule.endmonth))
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
			cout << currentlst->schedule.starthour << " ";
			cout << currentlst->schedule.startminute << " ";
			cout << currentlst->schedule.endhour << " ";
			cout << currentlst->schedule.endminute << " ";
			cout << attendence[i][j] << endl;
			j++;
			if (day == string_to_int(currentlst->schedule.EndDay) && month == string_to_int(currentlst->schedule.Endmonth)) {
				break;
			}
		}
		cout << active[i];
		cout << endl;
		i++;
		current = current->next;
		cout << endl;
	}

}
void main_Export_Attendence_csv_File() {
	LinkedList lstCourse, lst2, lst;
	string class_View, courseID_View, Class, inputpath,outputpath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. back\n";
		cout << "Enter Class of courese to export:";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to export:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classs && courseID_View == current->course.courseID) {
					inputpath = "C:\\Users\\admin\\source\\repos\\Test\\Projec lam lai ham 23 26 27 28 30\\";
					inputpath.append(current->course.classs);
					inputpath.append("-");
					inputpath.append(current->course.courseID);
					inputpath.append(".txt");
					outputpath = "C:\\Users\\admin\\source\\repos\\Test\\Projec lam lai ham 23 26 27 28 30\\";
					outputpath.append(current->course.classs);
					outputpath.append("-");
					outputpath.append(current->course.courseID);
					outputpath.append("-");
					outputpath.append("Attendence");
					outputpath.append(".csv");
					export_3(inputpath,outputpath);
					current = lstCourse.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lstCourse.head;
					break;
				}
			}
		}
	}
}
void export_3(string inputpath,string outputpath)
{
	ifstream fin;
	ofstream fout;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;

	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
		int i = 0;
		int j = 0;
		getline(fin, student.StudentID, '\n');
		getline(fin, student.StudentPass, '\n');
		getline(fin, student.StudentName, '\n');
		getline(fin, student.StudentDOB, '\n');
		getline(fin, student.StudentGender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.StudentID = student.StudentID;
		p->student.StudentPass = student.StudentPass;
		p->student.StudentName = student.StudentName;
		p->student.StudentDOB = student.StudentDOB;
		p->student.StudentGender = student.StudentGender;
		p->student.midterm = student.midterm;
		p->student.final = student.final;
		p->student.bonus = student.bonus;
		p->student.total = student.total;
		p->next = NULL;
		lst2.head = p;
		Node* current = lst2.head;
		fin.ignore();
		getline(fin, schedule.startYear, ' ');
		getline(fin, schedule.startMonth, ' ');
		getline(fin, schedule.startDay, ' ');
		getline(fin, schedule.starthour, ' ');
		getline(fin, schedule.startminute, ' ');
		getline(fin, schedule.endhour, ' ');
		getline(fin, schedule.endminute, ' ');
		p = new Node;
		p->schedule.startDay = schedule.startDay;
		p->schedule.startMonth = schedule.startMonth;
		p->schedule.startYear = schedule.startYear;
		p->schedule.starthour = schedule.starthour;
		p->schedule.startminute = schedule.startminute;
		p->schedule.endhour = schedule.endhour;
		p->schedule.endminute = schedule.endminute;
		p->next = NULL;
		lst.head = p;
		Node* currentlst = lst.head;
		fin >> attendence[i][j];
		fin.ignore();
		j++;
		int n = 1;
		while (n != 10) {
			getline(fin, year1, ' ');
			getline(fin, month1, ' ');
			getline(fin, day1, ' ');
			getline(fin, startHour1, ' ');
			getline(fin, startMinute1, ' ');
			getline(fin, endHour1, ' ');
			getline(fin, endMinute1, ' ');
			fin >> attendence[i][j];
			if (n < 9) {
				fin.ignore();
			}
			j++;
			n++;
		}
		fin >> active[i];
		fin.ignore();
		i++;
		while (!fin.eof()) {
			j = 0;
			getline(fin, student.StudentID, '\n');
			getline(fin, student.StudentID, '\n');
			getline(fin, student.StudentPass, '\n');
			getline(fin, student.StudentName, '\n');
			getline(fin, student.StudentDOB, '\n');
			getline(fin, student.StudentGender, '\n');
			fin >> student.midterm;
			fin >> student.final;
			fin >> student.bonus;
			fin >> student.total;
			Node* p = new Node;
			p->student.StudentID = student.StudentID;
			p->student.StudentPass = student.StudentPass;
			p->student.StudentName = student.StudentName;
			p->student.StudentDOB = student.StudentDOB;
			p->student.StudentGender = student.StudentGender;
			p->student.midterm = student.midterm;
			p->student.final = student.final;
			p->student.bonus = student.bonus;
			p->student.total = student.total;
			p->next = NULL;
			current->next = p;
			current = current->next;
			fin.ignore();
			getline(fin, year1, ' ');
			getline(fin, month1, ' ');
			getline(fin, day1, ' ');
			getline(fin, startHour1, ' ');
			getline(fin, startMinute1, ' ');
			getline(fin, endHour1, ' ');
			getline(fin, endMinute1, ' ');
			fin >> attendence[i][j];
			fin.ignore();
			j++;
			int n = 1;
			while (n != 10) {
				if (n == 9) {
					getline(fin, schedule.EndYear, ' ');
					getline(fin, schedule.Endmonth, ' ');
					getline(fin, schedule.EndDay, ' ');
					p = new Node;
					p->schedule.startDay = schedule.startDay;
					p->schedule.startMonth = schedule.startMonth;
					p->schedule.startYear = schedule.startYear;
					p->schedule.EndDay = schedule.EndDay;
					p->schedule.Endmonth = schedule.Endmonth;
					p->schedule.EndYear = schedule.EndYear;
					p->schedule.starthour = schedule.starthour;
					p->schedule.startminute = schedule.startminute;
					p->schedule.endhour = schedule.endhour;
					p->schedule.endminute = schedule.endminute;
					p->next = NULL;
					lst.head = p;
					Node* currentlst = lst.head;
				}
				else {
					getline(fin, year1, ' ');
					getline(fin, month1, ' ');
					getline(fin, day1, ' ');
				}
				getline(fin, startHour1, ' ');
				getline(fin, startMinute1, ' ');
				getline(fin, endHour1, ' ');
				getline(fin, endMinute1, ' ');
				fin >> attendence[i][j];
				if (n < 9) {
					fin.ignore();
				}
				j++;
				n++;
			}
			fin >> active[i];
			fin.ignore();
			i++;
		}
		fin.close();


	 currentlst = lst.head;
	 current = lst2.head;
	fout.open(outputpath);
	if (!fout.is_open()) {
		cout << "can't save " << outputpath << " file\n";
		return;
	}
	i = 0;
	while (current->next != NULL) {
		fout << current->student.StudentID << endl;
		fout << current->student.StudentPass << endl;
		fout << current->student.StudentName << endl;
		fout << current->student.StudentDOB << endl;
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
		int j = 0;
		fout << attendence[i][j] << endl;
		j++;
		while (1) //&& month != string_to_int(currentlst->schedule.endmonth))
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
			fout << attendence[i][j] << endl;
			j++;
			if (day == string_to_int(currentlst->schedule.EndDay) && month == string_to_int(currentlst->schedule.Endmonth)) {
				break;
			}

		}
		
		fout << active[i];
		fout << endl;
		i++;
		current = current->next;
		fout << endl;
	}
	cout << "Export succesfully\n";
	fout.close();
}
void view_Student(string inputpath) {
	ifstream fin;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;

	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.StudentID, '\n');
	getline(fin, student.StudentPass, '\n');
	getline(fin, student.StudentName, '\n');
	getline(fin, student.StudentDOB, '\n');
	getline(fin, student.StudentGender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.StudentID = student.StudentID;
	p->student.StudentPass = student.StudentPass;
	p->student.StudentName = student.StudentName;
	p->student.StudentDOB = student.StudentDOB;
	p->student.StudentGender = student.StudentGender;
	p->student.midterm = student.midterm;
	p->student.final = student.final;
	p->student.bonus = student.bonus;
	p->student.total = student.total;
	p->next = NULL;
	lst2.head = p;
	Node* current = lst2.head;
	fin.ignore();
	getline(fin, schedule.startYear, ' ');
	getline(fin, schedule.startMonth, ' ');
	getline(fin, schedule.startDay, ' ');
	getline(fin, schedule.starthour, ' ');
	getline(fin, schedule.startminute, ' ');
	getline(fin, schedule.endhour, ' ');
	getline(fin, schedule.endminute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.starthour = schedule.starthour;
	p->schedule.startminute = schedule.startminute;
	p->schedule.endhour = schedule.endhour;
	p->schedule.endminute = schedule.endminute;
	p->next = NULL;
	lst.head = p;
	Node* currentlst = lst.head;
	fin >> attendence[i][j];
	fin.ignore();
	j++;
	int n = 1;
	while (n != 10) {
		getline(fin, year1, ' ');
		getline(fin, month1, ' ');
		getline(fin, day1, ' ');
		getline(fin, startHour1, ' ');
		getline(fin, startMinute1, ' ');
		getline(fin, endHour1, ' ');
		getline(fin, endMinute1, ' ');
		fin >> attendence[i][j];
		if (n < 9) {
			fin.ignore();
		}
		j++;
		n++;
	}
	fin >> active[i];
	fin.ignore();
	i++;
	while (!fin.eof()) {
		j = 0;
		getline(fin, student.StudentID, '\n');
		getline(fin, student.StudentID, '\n');
		getline(fin, student.StudentPass, '\n');
		getline(fin, student.StudentName, '\n');
		getline(fin, student.StudentDOB, '\n');
		getline(fin, student.StudentGender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.StudentID = student.StudentID;
		p->student.StudentPass = student.StudentPass;
		p->student.StudentName = student.StudentName;
		p->student.StudentDOB = student.StudentDOB;
		p->student.StudentGender = student.StudentGender;
		p->student.midterm = student.midterm;
		p->student.final = student.final;
		p->student.bonus = student.bonus;
		p->student.total = student.total;
		p->next = NULL;
		current->next = p;
		current = current->next;
		fin.ignore();
		getline(fin, year1, ' ');
		getline(fin, month1, ' ');
		getline(fin, day1, ' ');
		getline(fin, startHour1, ' ');
		getline(fin, startMinute1, ' ');
		getline(fin, endHour1, ' ');
		getline(fin, endMinute1, ' ');
		fin >> attendence[i][j];
		fin.ignore();
		j++;
		int n = 1;
		while (n != 10) {
			if (n == 9) {
				getline(fin, schedule.EndYear, ' ');
				getline(fin, schedule.Endmonth, ' ');
				getline(fin, schedule.EndDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.EndDay = schedule.EndDay;
				p->schedule.Endmonth = schedule.Endmonth;
				p->schedule.EndYear = schedule.EndYear;
				p->schedule.starthour = schedule.starthour;
				p->schedule.startminute = schedule.startminute;
				p->schedule.endhour = schedule.endhour;
				p->schedule.endminute = schedule.endminute;
				p->next = NULL;
				lst.head = p;
				Node* currentlst = lst.head;
			}
			else {
				getline(fin, year1, ' ');
				getline(fin, month1, ' ');
				getline(fin, day1, ' ');
			}
			getline(fin, startHour1, ' ');
			getline(fin, startMinute1, ' ');
			getline(fin, endHour1, ' ');
			getline(fin, endMinute1, ' ');
			fin >> attendence[i][j];
			if (n < 9) {
				fin.ignore();
			}
			j++;
			n++;
		}
		fin >> active[i];
		fin.ignore();
		i++;
	}
	fin.close();

	currentlst = lst.head;
	current = lst2.head;
	i = 0;
	while (current->next != NULL) {
		cout << current->student.StudentID << endl;
		cout << current->student.StudentPass << endl;
		cout << current->student.StudentName << endl;
		cout << current->student.StudentDOB << endl;
		cout << current->student.StudentGender << endl;
		cout << active[i];
		cout << endl;
		i++;
		current = current->next;
		cout << endl;
	}
}
void main_View_Student_Of_Course() {
	LinkedList lstCourse, lst2, lst;
	string class_View, courseID_View, inputpath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. back\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to view:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classs && courseID_View == current->course.courseID) {
					inputpath = "C:\\Users\\admin\\source\\repos\\Test\\Projec lam lai ham 23 26 27 28 30\\";
					inputpath.append(current->course.classs);
					inputpath.append("-");
					inputpath.append(current->course.courseID);
					inputpath.append(".txt");
					view_Student(inputpath);
					current = lstCourse.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lstCourse.head;
					break;
				}
			}
		}
	}
}
void main_Edit_Attendence() {
	LinkedList lstCourse, lst2, lst;
	string class_View, courseID_View, inputpath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. back\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to view:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classs && courseID_View == current->course.courseID) {
					inputpath = "C:\\Users\\admin\\source\\repos\\Test\\Projec lam lai ham 23 26 27 28 30\\";
					inputpath.append(current->course.classs);
					inputpath.append("-");
					inputpath.append(current->course.courseID);
					inputpath.append(".txt");
					view_Student(inputpath);
					current = lstCourse.head;
					break;
				}
				else {
					current = current->next;
				}
				if (current == NULL) {
					cout << "Class or Course is not exist\n\n";
					current = lstCourse.head;
					break;
				}
			}
		}
	}
}
void edit_Attendence2(string inputpath) {
	ifstream fin;
	ofstream fout;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;
	string studentID_View;
	cout << "Enter Student ID to edit: ";
	getline(cin, studentID_View);
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.StudentID, '\n');
	getline(fin, student.StudentPass, '\n');
	getline(fin, student.StudentName, '\n');
	getline(fin, student.StudentDOB, '\n');
	getline(fin, student.StudentGender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.StudentID = student.StudentID;
	p->student.StudentPass = student.StudentPass;
	p->student.StudentName = student.StudentName;
	p->student.StudentDOB = student.StudentDOB;
	p->student.StudentGender = student.StudentGender;
	p->student.midterm = student.midterm;
	p->student.final = student.final;
	p->student.bonus = student.bonus;
	p->student.total = student.total;
	p->next = NULL;
	lst2.head = p;
	Node* current = lst2.head;
	fin.ignore();
	getline(fin, schedule.startYear, ' ');
	getline(fin, schedule.startMonth, ' ');
	getline(fin, schedule.startDay, ' ');
	getline(fin, schedule.starthour, ' ');
	getline(fin, schedule.startminute, ' ');
	getline(fin, schedule.endhour, ' ');
	getline(fin, schedule.endminute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.starthour = schedule.starthour;
	p->schedule.startminute = schedule.startminute;
	p->schedule.endhour = schedule.endhour;
	p->schedule.endminute = schedule.endminute;
	p->next = NULL;
	lst.head = p;
	Node* currentlst = lst.head;
	fin >> attendence[i][j];
	fin.ignore();
	j++;
	int n = 1;
	while (n != 10) {
		getline(fin, year1, ' ');
		getline(fin, month1, ' ');
		getline(fin, day1, ' ');
		getline(fin, startHour1, ' ');
		getline(fin, startMinute1, ' ');
		getline(fin, endHour1, ' ');
		getline(fin, endMinute1, ' ');
		fin >> attendence[i][j];
		if (n < 9) {
			fin.ignore();
		}
		j++;
		n++;
	}
	fin >> active[i];
	fin.ignore();
	i++;
	while (!fin.eof()) {
		j = 0;
		getline(fin, student.StudentID, '\n');
		getline(fin, student.StudentID, '\n');
		getline(fin, student.StudentPass, '\n');
		getline(fin, student.StudentName, '\n');
		getline(fin, student.StudentDOB, '\n');
		getline(fin, student.StudentGender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.StudentID = student.StudentID;
		p->student.StudentPass = student.StudentPass;
		p->student.StudentName = student.StudentName;
		p->student.StudentDOB = student.StudentDOB;
		p->student.StudentGender = student.StudentGender;
		p->student.midterm = student.midterm;
		p->student.final = student.final;
		p->student.bonus = student.bonus;
		p->student.total = student.total;
		p->next = NULL;
		current->next = p;
		current = current->next;
		fin.ignore();
		getline(fin, year1, ' ');
		getline(fin, month1, ' ');
		getline(fin, day1, ' ');
		getline(fin, startHour1, ' ');
		getline(fin, startMinute1, ' ');
		getline(fin, endHour1, ' ');
		getline(fin, endMinute1, ' ');
		fin >> attendence[i][j];
		fin.ignore();
		j++;
		int n = 1;
		while (n != 10) {
			if (n == 9) {
				getline(fin, schedule.EndYear, ' ');
				getline(fin, schedule.Endmonth, ' ');
				getline(fin, schedule.EndDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.EndDay = schedule.EndDay;
				p->schedule.Endmonth = schedule.Endmonth;
				p->schedule.EndYear = schedule.EndYear;
				p->schedule.starthour = schedule.starthour;
				p->schedule.startminute = schedule.startminute;
				p->schedule.endhour = schedule.endhour;
				p->schedule.endminute = schedule.endminute;
				p->next = NULL;
				lst.head = p;
				Node* currentlst = lst.head;
			}
			else {
				getline(fin, year1, ' ');
				getline(fin, month1, ' ');
				getline(fin, day1, ' ');
			}
			getline(fin, startHour1, ' ');
			getline(fin, startMinute1, ' ');
			getline(fin, endHour1, ' ');
			getline(fin, endMinute1, ' ');
			fin >> attendence[i][j];
			if (n < 9) {
				fin.ignore();
			}
			j++;
			n++;
		}
		fin >> active[i];
		fin.ignore();
		i++;
	}
	fin.close();


	currentlst = lst.head;
	current = lst2.head;
	fout.open(inputpath);
	if (!fout.is_open()) {
		cout << "can't save " << outputpath << " file\n";
		return;
	}
	i = 0;
	while (current->next != NULL) {
		fout << current->student.StudentID << endl;
		fout << current->student.StudentPass << endl;
		fout << current->student.StudentName << endl;
		fout << current->student.StudentDOB << endl;
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
		int j = 0;
		fout << attendence[i][j] << endl;
		j++;
		while (1) //&& month != string_to_int(currentlst->schedule.endmonth))
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
			fout << attendence[i][j] << endl;
			j++;
			if (day == string_to_int(currentlst->schedule.EndDay) && month == string_to_int(currentlst->schedule.Endmonth)) {
				break;
			}

		}

		fout << active[i];
		fout << endl;
		i++;
		current = current->next;
		fout << endl;
	}
	cout << "Export succesfully\n";
	fout.close();
}