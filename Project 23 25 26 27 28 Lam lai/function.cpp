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

		while (day != string_to_int(currentlst->schedule.EndDay)) //&& month != string_to_int(currentlst->schedule.Endmonth))
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
// Function(view) use for  view_Attendence function
void view(LinkedList lst2, LinkedList lst, Node* currentlst)
{
	Node* current = lst2.head;
	while (current != NULL) {
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
		cout << "-1" << endl;

		while (day != string_to_int(currentlst->schedule.EndDay) && month != string_to_int(currentlst->schedule.Endmonth)) //&& month != string_to_int(currentlst->schedule.endmonth))
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
			cout << "-1" << endl;

		}


		cout << endl;
		current = current->next;
	}
}
//Function(export_Attendence) use for export_Attendence_list_Of_Course Funtion 
void export_Attendence(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst,string inputpath)
{
	ifstream fin;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	string attendence = "-1";
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	else {
		Node* current = lst2.head;
		while (current != NULL) {
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
			getline(fin, attendence, '\n');
			int n = 1;
			while (n != 10) {
				getline(fin, year1, ' ');
				getline(fin, month1, ' ');
				getline(fin, day1, ' ');
				getline(fin, startHour1, ' ');
				getline(fin, startMinute1, ' ');
				getline(fin, endHour1, ' ');
				getline(fin, endMinute1, ' ');
				getline(fin, attendence, '\n');
				n++;
			}

			current = current->next;
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
}

//Ham 26 Search and view Attendence_List_Of_Course
void view_Attendence_List_Of_Course(LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View, string Class, string inputpath) {
	Node* current = lst.head;
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
				if (class_View == Class && courseID_View == current->schedule.courseID) {
					inputpath = Class;
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
void export_Attendence_list_Of_Course(ofstream& fout, LinkedList lst, LinkedList lst2, string& class_View, string& courseID_View, string& outputpath, string Class,string &inputpath) {
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
				if (class_View == Class && courseID_View == current->schedule.courseID) {
					inputpath = Class;
					inputpath.append("-");
					inputpath.append(current->schedule.courseID);
					inputpath.append(".txt");
					outputpath = "";
					outputpath.append(Class);
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
						export_Attendence(fout, lst2, lst, current,inputpath);
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
					Node* current = lst2.head;
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
void view_2(string inputpath, LinkedList lst2, LinkedList lst, Node* currentlst)
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

			current = current->next;
			i++;
		}
		fin.close();
	}
	Node* current = lst2.head;
	int i = 0;
	while (current != NULL) {
		cout << current->student.StudentID << endl;
		cout << current->student.StudentPass << endl;
		cout << current->student.StudentName << endl;
		cout << current->student.StudentDOB << endl;
		cout << current->student.StudentGender << endl;
		cout << current->student.midterm<<" 1" << endl;
		cout << current->student.final << " 2" << endl;
		cout << current->student.bonus << " 3" << endl;
		cout << current->student.total << " 4" << endl;
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
		cout << attendence[i][j]<< endl;
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
		cout << endl;
		i++;
		current = current->next;
	}

}
void edit_Attendence_Of_Course(ofstream& fout, LinkedList lst2, LinkedList lst, string& class_View, string& studentID_View , int& day_edit, int& month_edit, int& year_edit, string& courseID_View ,string& outputpath, string Class, string& inputpath) {
	Node* current = lst.head;
	while (1) {
		view_List_Of_Course(lst);
		cout << "0. back\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter CourseID of courese to view:";
		getline(cin, courseID_View);
	/*	cout << "Enter StudentID of courese to view:";
		getline(cin, studentID_View);
		cout << "Enter year to edit: ";
		cin >> year_edit;
		cout << "Enter month to edit: ";
		cin >> month_edit;
		cout << "Enter day to edit: ";
		cin >> day_edit;*/
		if (class_View == "0" || courseID_View == "0"||studentID_View=="0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == Class && courseID_View == current->schedule.courseID) {
					inputpath = Class;
					inputpath.append("-");
					inputpath.append(current->schedule.courseID);
					inputpath.append(".txt");
					outputpath =inputpath;
					fout.open(outputpath);
					if (!fout.is_open())
					{
						cout << "can not create" << outputpath << " file";
					}
					else
					{
						edit_Attendence(fout, lst2, lst, current, studentID_View, day_edit,month_edit,year_edit,outputpath,Class,inputpath);
						fout.close();
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
void edit_Attendence(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst,string studentID_View,int day_edit,int month_edit, int year_edit, string outputpath, string Class, string inputpath)
{
	int a = -100;
	ifstream fin;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	else {
		Node* current = lst2.head;
		while (current != NULL) {
			int i = 0;
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
			fin >> attendence[i];
			fin.ignore();
			i++;
			int n = 1;
			while (n != 10) {
				getline(fin, year1, ' ');
				getline(fin, month1, ' ');
				getline(fin, day1, ' ');
				getline(fin, startHour1, ' ');
				getline(fin, startMinute1, ' ');
				getline(fin, endHour1, ' ');
				getline(fin, endMinute1, ' ');
				fin >> attendence[i];
				fin.ignore();
				i++;
				n++;
			}

			current = current->next;
		}
		fin.close();
		 current = lst2.head;
		while (current != NULL) {
			fout << current->student.StudentID << endl;
			fout << current->student.StudentPass << endl;
			fout << current->student.StudentName << endl;
			fout << current->student.StudentDOB << endl;
			fout << current->student.StudentGender << endl;
			fout << current->student.midterm << "\n";
			fout << current->student.final << "\n";
			fout << current->student.bonus << "\n";
			fout << current->student.total<<"\n";
			int day = string_to_int(currentlst->schedule.startDay);
			int month = string_to_int(currentlst->schedule.startMonth);
			int year = string_to_int(currentlst->schedule.startYear);
			int temp = string_to_int(currentlst->schedule.EndDay);
			int i = 0;
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
				fout << attendence[i] << endl;
				
				i++;


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
				fout << attendence[i] << endl;
				i++;


			}


			fout << endl;
			current = current->next;
		}
	}
	if (a == 100) {
		cout << "Edit sucessfully";
	}
	else {
		cout << "Can't Edit";
	}
}