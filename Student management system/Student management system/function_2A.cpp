#include"header.h"
Node* CreateNodeAnh(Schedule s)
{
	Node* p = new Node;
	p->schedule.no = s.no;
	p->schedule.id = s.id;
	p->schedule.name = s.name;
	p->schedule.classes = s.classes;
	p->schedule.LecturerUsername = s.LecturerUsername;
	p->schedule.LecturerName = s.LecturerName;
	p->schedule.LecturerDegree = s.LecturerDegree;
	p->schedule.lecturerGender = s.lecturerGender;
	p->schedule.startDay = s.startDay;
	p->schedule.startMonth = s.startMonth;
	p->schedule.startYear = s.startYear;
	p->schedule.endDay = s.endDay;
	p->schedule.endMonth = s.endMonth;
	p->schedule.endYear = s.endYear;
	p->schedule.DayOfWeek = s.DayOfWeek;
	p->schedule.startHour = s.startHour;
	p->schedule.startMinute = s.startMinute;
	p->schedule.endHour = s.endHour;
	p->schedule.endMinute = s.endMinute;
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
	getline(fin, s.no, ',');

	getline(fin, s.id, ',');

	getline(fin, s.name, ',');

	getline(fin, s.classes, ',');

	getline(fin, s.LecturerUsername, ',');
	getline(fin, s.LecturerName, ',');

	getline(fin, s.LecturerDegree, ',');


	getline(fin, s.lecturerGender, ',');
	getline(fin, s.startMonth, '/');
	getline(fin, s.startDay, '/');

	getline(fin, s.startYear, ',');
	getline(fin, s.endMonth, '/');
	getline(fin, s.endDay, '/');

	getline(fin, s.endYear, ',');


	getline(fin, s.DayOfWeek, ',');

	getline(fin, s.startHour, ',');

	getline(fin, s.startMinute, ',');


	getline(fin, s.endHour, ',');

	getline(fin, s.endMinute, ',');

	getline(fin, s.Room, '\n');
	count++;

	Node* p = CreateNodeAnh(s);
	lst.head = p;
	lst.head->next = current;
	current = lst.head;
	lst.tail = lst.head;
	while (!fin.eof())
	{

		getline(fin, s.no, ',');
		if (s.no == "")
		{
			break;
		}

		getline(fin, s.id, ',');

		getline(fin, s.name, ',');

		getline(fin, s.classes, ',');

		getline(fin, s.LecturerUsername, ',');
		getline(fin, s.LecturerName, ',');

		getline(fin, s.LecturerDegree, ',');


		getline(fin, s.lecturerGender, ',');
		getline(fin, s.startMonth, '/');

		getline(fin, s.startDay, '/');

		getline(fin, s.startYear, ',');
		getline(fin, s.endMonth, '/');
		getline(fin, s.endDay, '/');

		getline(fin, s.endYear, ',');


		getline(fin, s.DayOfWeek, ',');

		getline(fin, s.startHour, ',');

		getline(fin, s.startMinute, ',');


		getline(fin, s.endHour, ',');

		getline(fin, s.endMinute, ',');

		getline(fin, s.Room, '\n');
		p = CreateNodeAnh(s);
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
		fout << current->schedule.no << endl;
		fout << current->schedule.id << endl;
		fout << current->schedule.name << endl;
		fout << current->schedule.classes << endl;
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
		fout << current->schedule.endYear << " ";
		if (string_to_int(current->schedule.endMonth) < 10)
		{
			fout << "0" << current->schedule.endMonth << " ";
		}
		else
		{
			fout << current->schedule.endMonth << " ";
		}
		if (string_to_int(current->schedule.endDay) < 10)
		{
			fout << "0" << current->schedule.endDay << endl;
		}
		else
		{
			fout << current->schedule.endDay << endl;
		}

		fout << current->schedule.DayOfWeek << endl;
		fout << current->schedule.startHour << " ";
		fout << current->schedule.startMinute << endl;
		fout << current->schedule.endHour << " ";
		fout << current->schedule.endMinute << endl;
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
	p->student.username = s.username;
	p->student.password = s.password;
	p->student.name = s.name;
	p->student.DOB = s.DOB;
	p->student.gender = s.gender;

	p->next = NULL;
	return p;
}

void load_file_Student(ifstream& fin, LinkedList& lst2)
{

	Student s;
	lst2.head = NULL;
	lst2.tail = lst2.head;
	Node* current = lst2.head;

	getline(fin, s.username, '\n');
	getline(fin, s.password, '\n');
	getline(fin, s.name, '\n');
	getline(fin, s.DOB, '\n');
	getline(fin, s.classes, '\n');
	getline(fin, s.gender, '\n');

	Node* p = create_Node_Student(s);
	lst2.head = p;
	lst2.head->next = current;
	current = lst2.head;


	while (!fin.eof())
	{
		getline(fin, s.username, '\n');


		getline(fin, s.username, '\n');
		if (s.username == "")
		{
			break;
		}
		getline(fin, s.password, '\n');
		getline(fin, s.name, '\n');
		getline(fin, s.DOB, '\n');
		getline(fin, s.classes, '\n');
		getline(fin, s.gender, '\n');
		p = create_Node_Student(s);
		current->next = p;
		current = current->next;
		lst2.tail = current;

	}




}
void output_file_Student_from_csv_to_txt(ofstream& fout, LinkedList lst2, LinkedList lst, Node* currentlst)
{

	Node* current = lst2.head;
	while (current->next != NULL) {
		fout << current->student.username << endl;
		//fout << current->student.password << endl;
		fout << current->student.name << endl;
		fout << current->student.DOB << endl;
		fout << current->student.gender << endl;


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
		int temp = string_to_int(currentlst->schedule.endDay);
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
		fout << currentlst->schedule.startHour << " ";
		fout << currentlst->schedule.startMinute << " ";
		fout << currentlst->schedule.endHour << " ";
		fout << currentlst->schedule.endMinute << " ";
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
			fout << currentlst->schedule.startHour << " ";
			fout << currentlst->schedule.startMinute << " ";
			fout << currentlst->schedule.endHour << " ";
			fout << currentlst->schedule.endMinute << " ";
			fout << "-1" << endl;
			if (day == string_to_int(currentlst->schedule.endDay) && month == string_to_int(currentlst->schedule.endMonth))
			{
				break;
			}

		}

		fout << current->student.status << endl;
		fout << endl;

		current = current->next;
	}
	fout << current->student.username << endl;
	//fout << current->student.password << endl;
	fout << current->student.name << endl;
	fout << current->student.DOB << endl;
	fout << current->student.gender << endl;


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
	int temp = string_to_int(currentlst->schedule.endDay);
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
	fout << currentlst->schedule.startHour << " ";
	fout << currentlst->schedule.startMinute << " ";
	fout << currentlst->schedule.endHour << " ";
	fout << currentlst->schedule.endMinute << " ";
	fout << "-1" << endl;

	while (1) //&& month != string_to_int(currentlst->data.endMonth))
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
		fout << currentlst->schedule.startHour << " ";
		fout << currentlst->schedule.startMinute << " ";
		fout << currentlst->schedule.endHour << " ";
		fout << currentlst->schedule.endMinute << " ";
		fout << "-1" << endl;
		if (day == string_to_int(currentlst->schedule.endDay) && month == string_to_int(currentlst->schedule.endMonth))
		{
			break;
		}


	}

	fout << current->student.status << endl;
	fout << endl;

	current = current->next;
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

void main_schedule_from_csv_to_txt(LinkedList& lst, LinkedList& lst2)
{
	string academic;
	string semester;
	string classes;
	char base[101];
	Course c;
	string outputpath;

	int count;

	cout << "Enter academic:" << endl;
	getline(cin, academic);
	cout << "Enter semester: " << endl;
	getline(cin, semester);
	cout << "Enter classes: " << endl;
	getline(cin, classes);
	cout << "Enter the input path of the Schedule csv file " << endl;
	cin.getline(base, 100);
	char inputpath[101];
	strcpy_s(inputpath, strlen(base) + 1, base);
	outputpath = academic;
	outputpath.append("-");
	outputpath.append(semester);
	outputpath.append("-");
	outputpath.append("schedule");
	outputpath.append("-");
	outputpath.append(classes);
	outputpath.append(".txt");

	ifstream fin;
	ofstream fout;
	fin.open(inputpath);
	if (!fin.is_open())
	{
		cout << "can not open file "<<inputpath<<" pls check again your file" << endl;
		return;


	}
	else
	{
		load_file(lst, fin, count);
		fout.open(outputpath);
		if (!fout.is_open())
		{
			cout << "can not create file" << endl;
		}
		else
		{
			output_file(lst, fout);
			fout.close();
		}

		fin.close();
	}

	cout << "pls input the input path of the file student txt of the classes you want to import course: " << endl;
	cin.getline(base, 100);
	strcpy_s(inputpath, strlen(base) + 1, base);
	fin.open(inputpath);

	if (!fin.is_open())
	{
		cout << "can not open file " << inputpath<<" pls check again your file" << endl;
		return;
	}
	else
	{

		load_file_Student(fin, lst2);
		Node* current = lst.head;

		while (count != 0)
		{

			outputpath = classes;
			outputpath.append("-");
			outputpath.append(current->schedule.id);
			outputpath.append(".txt");
			c.classes = classes;
			c.id = current->schedule.id;
			
			fout.open(outputpath);
			if (!fout.is_open())
			{
				cout << "can not create file" << endl;
			}
			else
			{
				output_file_Student_from_csv_to_txt(fout, lst2, lst, current);
				fout.close();
				cout << "inport Schedule from csv to txt and add " << current->schedule.id << " to " << classes << " success" << endl;
				

			}
			count--;
			current = current->next;
			fin.close();
			fout.open("List_Of_Course.txt", ios::app);
			if (!fout.is_open())
			{
				cout << "can not create file list of course" << endl;
			}
			else
			{

				fout << c.classes << "-" << c.id << endl;
				fout.close();

			}
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
	
	getline(fin, s.no, '\n');
	

	getline(fin, s.id, '\n');
	

	getline(fin, s.name, '\n');

	getline(fin, s.classes, '\n');

	getline(fin, s.LecturerUsername, '\n');
	getline(fin, s.LecturerName, '\n');

	getline(fin, s.LecturerDegree, '\n');


	getline(fin, s.lecturerGender, '\n');
	getline(fin, s.startYear, ' ');
	getline(fin, s.startMonth, ' ');
	getline(fin, s.startDay, '\n');

	getline(fin, s.endYear, ' ');
	getline(fin, s.endMonth, ' ');
	getline(fin, s.endDay, '\n');




	getline(fin, s.DayOfWeek, '\n');

	getline(fin, s.startHour, ' ');

	getline(fin, s.startMinute, '\n');


	getline(fin, s.endHour, ' ');

	getline(fin, s.endMinute, '\n');

	getline(fin, s.Room, '\n');
	count++;

	Node* p = CreateNodeAnh(s);
	lst.head = p;
	lst.head->next = current;
	current = lst.head;
	lst.tail = lst.head;
	while (!fin.eof())
	{

		getline(fin, s.no, '\n');
		getline(fin, s.no, '\n');
		
		temp = s.no;
		if (s.no == "")
		{
			break;
		}

		getline(fin, s.id, '\n');
		

		getline(fin, s.name, '\n');

		getline(fin, s.classes, '\n');

		getline(fin, s.LecturerUsername, '\n');
		getline(fin, s.LecturerName, '\n');

		getline(fin, s.LecturerDegree, '\n');


		getline(fin, s.lecturerGender, '\n');
		getline(fin, s.startYear, ' ');
		getline(fin, s.startMonth, ' ');
		getline(fin, s.startDay, '\n');

		getline(fin, s.endYear, ' ');
		getline(fin, s.endMonth, ' ');
		getline(fin, s.endDay, '\n');

		getline(fin, s.DayOfWeek, '\n');

		getline(fin, s.startHour, ' ');

		getline(fin, s.startMinute, '\n');


		getline(fin, s.endHour, ' ');

		getline(fin, s.endMinute, '\n');

		getline(fin, s.Room, '\n');
		p = CreateNodeAnh(s);
		current->next = p;
		current = current->next;
		lst.tail = current;
		count++;
	}
}

void Add_course(LinkedList& lst, int& count, Schedule& s)
{

	cout << "Enter the No of the course" << endl;
	getline(cin, s.no);
	cout << "Enter id of the course" << endl;

	getline(cin, s.id);
	cout << "Enter the course Name" << endl;
	getline(cin, s.name);
	cout << "Enter the class of the new course" << endl;
	getline(cin, s.classes);
	cout << "Enter the Lecturer Username" << endl;
	getline(cin, s.LecturerUsername);
	cout << "Enter the Lecturer Name" << endl;
	getline(cin, s.LecturerName);
	cout << "Enter the Lecturer Degree" << endl;
	getline(cin, s.LecturerDegree);
	cout << "Enter the Lecturer Genger" << endl;

	getline(cin, s.lecturerGender);
	cout << "Enter start Day of the course" << endl;


	getline(cin, s.startDay);
	cout << "Enter start Month of the course" << endl;
	getline(cin, s.startMonth);
	cout << "Enter start Year of the course" << endl;
	getline(cin, s.startYear);
	cout << "Enter end Day of the course" << endl;


	getline(cin, s.endDay);
	cout << "Enter end Month of the course" << endl;
	getline(cin, s.endMonth);
	cout << "Enter endYear of the course" << endl;
	getline(cin, s.endYear);

	cout << "Enter Day Of Week to study the course" << endl;


	getline(cin, s.DayOfWeek);
	cout << "Enter startHour of the course" << endl;
	getline(cin, s.startHour);
	cout << "Enter start Minute of the course" << endl;
	getline(cin, s.startMinute);
	cout << "Enter end Hour of the course" << endl;

	getline(cin, s.endHour);
	cout << "Enter end Minute of the course" << endl;

	getline(cin, s.endMinute);
	cout << "Enter Room of the course" << endl;
	getline(cin, s.Room);

	Node* p = CreateNodeAnh(s);
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
			fout << current->schedule.no << endl;
			fout << current->schedule.id << endl;
			fout << current->schedule.name << endl;
			fout << current->schedule.classes << endl;
			fout << current->schedule.LecturerUsername << endl;
			fout << current->schedule.LecturerName << endl;
			
			fout << current->schedule.LecturerDegree << endl;
			if (current->schedule.LecturerDegree == "0" || current->schedule.lecturerGender == "Male" || current->schedule.lecturerGender == "male")
			{
				fout << "0" << endl;
			}
			else
			{
				fout << "1" << endl;
			}
			//fout << current->schedule.lecturerGender << endl;
			fout << current->schedule.startYear << " ";


			fout << current->schedule.startMonth << " ";


			fout << current->schedule.startDay << endl;

			fout << current->schedule.endYear << " ";

			fout << current->schedule.endMonth << " ";


			fout << current->schedule.endDay << endl;


			fout << current->schedule.DayOfWeek << endl;
			fout << current->schedule.startHour << " ";
			fout << current->schedule.startMinute << endl;
			fout << current->schedule.endHour << " ";
			fout << current->schedule.endMinute << endl;
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

	int count;
	char base[101];
	//cout << "input the input path of your schedule txt file" << endl;
	////cout << "nhap vao duong dan chua file: " << endl;
	//cin.getline(base, 100);
	//char inputpath[101];
	//strcpy_s(inputpath, strlen(base) + 1, base);
	string inputpath;
	string classes;
	string academic;
	string semester;
	cout << "pls Enter the academic of the Schedule you want to add the new course" << endl;
	getline(cin, academic);
	cout << "pls Enter the semester" << endl;
	getline(cin, semester);
	cout << "pls Enter the classes you want to add the new course" << endl;
	getline(cin, s.classes);
	
	inputpath = academic;
	inputpath.append("-");
	inputpath.append(semester);

	inputpath.append("-Schedule-");
	inputpath.append(s.classes);

	inputpath.append(".txt");



	fin.open(inputpath);
	if (!fin.is_open())
	{
		cout << "can not open "<<inputpath<<" to write"<<" pls check again your file" << endl;
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
			cout << "can not open file to write" << endl;
		}
		else
		{
			output_file_schedule_txt(lst, fout);
			
			fout.close();
		}
		fin.close();
	}

	cout << "pls Enter the input path of the file student txt of your class want to add the new course" << endl;
	getline(cin, inputpath);

	fin.open(inputpath);
	
	if (!fin.is_open())
	{
		cout << "can not open "<<inputpath<<" to import pls check again your file" << endl;
		return;
	}
	else
	{
		load_file_Student(fin, lst2);
		string outputpath;
		outputpath = s.classes;
		outputpath.append("-");
		outputpath.append(s.id);
		outputpath.append(".txt");
		
		fout.open(outputpath);
		if (!fout.is_open())
		{
			cout << "can not create file";
			return;
		}
		else
		{
			output_file_Student_Add(fout, lst2, s);
			fout.close();
		}
		fout.open("List_Of_Course.txt", ios::app);
		if (!fout.is_open())
		{
			cout << "can not open file List_Of_Course to write" << endl;
			return;
		}
		else
		{
			fout << s.classes << "-" << s.id << endl;
			fout.close();
		}

	}


	cout << "Add course successfully" << endl;
	cout << endl;
	view_schedule_2(lst);
	fin.close();

}


void output_file_Student_Add(ofstream& fout, LinkedList lst2, Schedule s)
{
	Node* current = lst2.head;
	while (current->next != NULL)
	{
		fout << current->student.username << endl;
		//fout << current->student.password << endl;
		fout << current->student.name << endl;
		fout << current->student.DOB << endl;
		fout << current->student.gender << endl;


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
		fout << s.startHour << " ";
		fout << s.startMinute << " ";
		fout << s.endHour << " ";
		fout << s.endMinute << " ";
		fout << "-1" << endl;
		while (1) //&& month != string_to_int(currentlst->student.endMonth))
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
			fout << s.startHour << " ";
			fout << s.startMinute << " ";
			fout << s.endHour << " ";
			fout << s.endMinute << " ";
			fout << "-1" << endl;
			if (day == string_to_int(s.endDay) && month == string_to_int(s.endMonth))
			{
				break;
			}


		}
		fout << current->student.status << endl;
		fout << endl;
		current = current->next;


	}

	fout << current->student.username << endl;
	
	fout << current->student.name << endl;
	fout << current->student.DOB << endl;
	fout << current->student.gender << endl;


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
	//int temp = string_to_int(currentlst->student.endDay);
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
	fout << s.startHour << " ";
	fout << s.startMinute << " ";
	fout << s.endHour << " ";
	fout << s.endMinute << " ";
	fout << "-1" << endl;
	while (1) //&& month != string_to_int(currentlst->student.endMonth))
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
		fout << s.startHour << " ";
		fout << s.startMinute << " ";
		fout << s.endHour << " ";
		fout << s.endMinute << " ";
		fout << "-1" << endl;
		if (day == string_to_int(s.endDay) && month == string_to_int(s.endMonth))
		{
			break;
		}


	}
	fout << current->student.status << endl;
	fout << endl;
	current = current->next;
}


//Edit course

void edit_course(LinkedList& lst, Node*& current1, string& inputpath, LinkedList& lst2)
{

	Schedule s;
	ofstream fout;
	string old_oldid;
	string old_classes;
	//view_schedule_2(lst);
	cout << "input the num of the course you want to edit" << endl;
	cin >> s.no;
	Node* current = lst.head;
	while (current != NULL)
	{
		if (current->schedule.no == s.no)
		{
			old_oldid = current->schedule.id;
			old_classes = current->schedule.classes;
			while (true)
			{
				string choice;
				cout << "1.id" << endl;
				cout << "2.name" << endl;
				cout << "3.classes" << endl;
				cout << "4.lecturerUserName" << endl;
				cout << "5.lecturerDegree" << endl;
				cout << "6.Gender" << endl;
				cout << "7.startDate" << endl;
				cout << "8.EndDate" << endl;
				cout << "9.DayOfWeek" << endl;
				cout << "10.startHour" << endl;
				cout << "11.endHour" << endl;
				cout << "12.Room" << endl;
				cout << "13.edit all" << endl;
				cout << "0.exit" << endl;

				cout << "Room" << endl;
				cout << endl;
				cout << "pls choose which you want to edit" << endl;

				getline(cin, choice);
				if (choice == "1")
				{
					cout << "inputid" << endl;
					//cin.ignore(1);
					getline(cin, current->schedule.id);
				}
				else if (choice == "2")
				{
					cout << "input name" << endl;
					//cin.ignore(1);
					getline(cin, current->schedule.name);

				}
				else if (choice == "3")
				{
					cout << "input classes" << endl;
					//cin.ignore(1);
					getline(cin, current->schedule.classes);
				}
				else if (choice == "4")
				{
					cout << "nhap vao lecturerUserName" << endl;
					//cin.ignore(1);
					getline(cin, current->schedule.LecturerUsername);
				}
				else if (choice == "5")
				{
					cout << "input lecturerDegree" << endl;
					//cin.ignore(1);
					getline(cin, current->schedule.LecturerDegree);
				}
				else if (choice == "6")
				{
					cout << "input Gender" << endl;
					//cin.ignore(1);
					getline(cin, current->schedule.lecturerGender);
				}
				else if (choice == "7")
				{
					//cin.ignore(1);
					cout << "input startDay" << endl;
					getline(cin, current->schedule.startDay);
					cout << "input startMonth" << endl;
					getline(cin, current->schedule.startMonth);
					cout << "input startYear" << endl;
					getline(cin, current->schedule.startYear);
				}
				else if (choice == "8")
				{
					//cin.ignore(1);
					cout << "input endDay" << endl;
					getline(cin, current->schedule.endDay);
					cout << "input endMonth" << endl;
					getline(cin, current->schedule.endMonth);
					cout << "input endYear" << endl;
					getline(cin, current->schedule.endYear);
				}
				else if (choice == "9")
				{
					//cin.ignore(1);
					cout << "input DayOfWeek" << endl;
					getline(cin, current->schedule.DayOfWeek);
				}
				else if (choice == "10")
				{
					//cin.ignore(1);
					cout << "input startHour" << endl;
					getline(cin, current->schedule.startHour);
					cout << "input startMinute" << endl;
					getline(cin, current->schedule.startMinute);
				}
				else if (choice == "11")
				{
					//cin.ignore(1);
					cout << "input endHour" << endl;
					getline(cin, current->schedule.endHour);
					cout << "input endMinute" << endl;
					getline(cin, current->schedule.endMinute);
				}
				else if (choice == "12")
				{
					//cin.ignore(1);
					cout << "input Room" << endl;
					getline(cin, current->schedule.Room);
				}
				else if (choice == "13")
				{
					cout << "nhap vao id" << endl;
					//cin.ignore(1);
					getline(cin, current->schedule.id);
					cout << "nhap vao coureName" << endl;
					getline(cin, current->schedule.name);
					cout << "nhap vao classes" << endl;
					getline(cin, current->schedule.classes);
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
					cout << "nhap vao endDay" << endl;


					getline(cin, current->schedule.endDay);
					cout << "nhap vao endMonth" << endl;
					getline(cin, current->schedule.endMonth);
					cout << "nhap vao endYear" << endl;
					getline(cin, current->schedule.endYear);

					cout << "Nhap vao DayOfWeek" << endl;


					getline(cin, current->schedule.DayOfWeek);
					cout << "nhap vao startHour" << endl;
					getline(cin, current->schedule.startHour);
					cout << "nhap vao startMinute" << endl;
					getline(cin, current->schedule.startMinute);
					cout << "nhap vao endHour" << endl;

					getline(cin, current->schedule.endHour);
					cout << "nhap vao endMinute" << endl;

					getline(cin, current->schedule.endMinute);
					cout << "nhap vao Room" << endl;
					getline(cin, current->schedule.Room);
				}
				else if (choice == "0")
				{
					break;
				}
				else
				{
				cout << "your choice dosen't exsit pls choose again" << endl;
				continue;
 }
			}
			break;
		}
		else
		{
			current = current->next;
		}
	}
	current1 = current;
	string outputpath;
	/*string temp;
	temp = current1->schedule.startDay;*/
	outputpath = current1->schedule.classes;
	outputpath.append("-");
	outputpath.append(current1->schedule.id);
	outputpath.append(".txt");
	string old_course;
	old_course = old_classes;
	old_course.append("-");
	old_course.append(old_oldid);
	old_course.append(".txt");
	char* c = new char[old_course.size() + 1];
	for (int i = 0; i < old_course.size(); i++)
	{
		c[i] = old_course[i];
	}
	c[old_course.size()] = '\0';

	inputpath = old_course;
	//inputpath.append(".txt");
	//test(c);

	LinkedList lofcourse;

	load_file_course_student(lst2, lst, inputpath, outputpath, current1);
	load_List_Of_Course2(lofcourse);
	Node* currentlofcourse = lofcourse.head;
	string temp = currentlofcourse->course.classes;
	while (currentlofcourse != NULL)
	{
		if (currentlofcourse->course.classes == old_classes && currentlofcourse->course.id == old_oldid)
		{
			currentlofcourse->course.classes = current1->schedule.classes;
			currentlofcourse->course.id = current1->schedule.id;
			break;
		}
		else
		{
			currentlofcourse = currentlofcourse->next;
		}
	}
	if (currentlofcourse == NULL)
	{
		remove(c);

		delete[] c;
		return;
	}
	fout.open("List_Of_Course.txt");
	if (!fout.is_open())
	{
		cout << "can not open file List_Of_Course.txt" << endl;
		return;
	}
	else
	{
		save_list_of_course(fout, lofcourse);
		fout.close();
	}
	remove(c);

	delete[] c;
	cout << "edit successfully" << endl;
	view_schedule_2(lst);
}

void main_edit_course(LinkedList& lst, LinkedList& lst2)
{

	
	ifstream fin;
	ofstream fout;
	int count;
	string outputpath;
	char base[101];
	Node* cur = NULL;
	Schedule s;
	string academic;
	string semester;
	
	cout << "Enter the year of the schedule you want to edit" << endl;
	getline(cin, academic);
	cout << "Enter the semester of the schedule you want to edit" << endl;
	getline(cin, semester);
	cout << "Enter the classes you want to edit schedule" << endl;
	cin >> s.classes;
	string inputpath1;
	string inputpath2;
	
	inputpath1 = academic;
	inputpath1.append("-");
	inputpath1.append(semester);
	inputpath1.append("-Schedule-");
	inputpath1.append(s.classes);

	inputpath1.append(".txt");


	fin.open(inputpath1);
	if (!fin.is_open())
	{
		cout << "can not open "<<inputpath1<<" to edit,pls check again your file" << endl;
	}
	else
	{
		load_file_schedule_txt(lst, fin, count);
		//view_schedule(lst);
		view_schedule_2(lst);
		edit_course(lst, cur, inputpath2, lst2);

		fout.open(inputpath1, ios::out);
		if (!fout.is_open())
		{
			cout << "can not open file "<<inputpath1<<" for update" << endl;
			return;
		}
		else
		{
			output_file_schedule_txt(lst, fout);
		/*	cout << "edit successfully" << endl;
			view_schedule_2(lst);*/
		
			fout.close();
		}
		fin.close();
	}
}

void view_schedule(LinkedList lst)
{
	Node* current = lst.head;
	while (current != NULL)
	{
		cout << current->schedule.no << endl;
		cout << current->schedule.id << endl;
		cout << current->schedule.name << endl;
		current = current->next;
	}
}

void view_schedule_2(LinkedList lst)
{
	Node* current = lst.head;
	while (current != NULL)
	{
		cout << current->schedule.no << endl;
		cout << current->schedule.id << endl;
		cout << current->schedule.name << endl;
		cout << current->schedule.classes << endl;
		cout << current->schedule.LecturerUsername << endl;
		cout << current->schedule.LecturerName << endl;
		cout << current->schedule.LecturerDegree << endl;
		cout << current->schedule.lecturerGender << endl;
		cout << current->schedule.startYear << " ";
		cout << current->schedule.startMonth << " ";
		cout << current->schedule.startDay << endl;
		cout << current->schedule.endYear << " ";
		cout << current->schedule.endMonth << " ";
		cout << current->schedule.endDay << endl;
		cout << current->schedule.DayOfWeek << endl;
		cout << current->schedule.startHour << " ";
		cout << current->schedule.startMinute << endl;
		cout << current->schedule.endHour << " ";
		cout << current->schedule.endMinute << endl;
		cout << current->schedule.Room << endl;
		cout << endl;
		current = current->next;
	}
}


void delete_course(LinkedList& lst, int& count)
{

	if (lst.head == NULL)
	{
		return;
	}
	else
	{
		Schedule s;
		cout << "input the num of the course you want to delete" << endl;
		cin >> s.no;

		Node* current = lst.head;
		while (current != NULL)
		{
			if (current->schedule.no == s.no)
			{
				break;
			}
			else
			{
				current = current->next;
			}
		}
		if (current == NULL)
		{
			cout << "can not find your course want to delete" << endl;
			return;
		}

		string delete_classes = current->schedule.classes;
		string delete_id = current->schedule.id;
		if (current == lst.head)
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
				if (current->schedule.no == s.no)
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
		string outputpath;
		outputpath = delete_classes;
		outputpath.append("-");
		outputpath.append(delete_id);
		outputpath.append(".txt");
		string str = outputpath;

		char* c = new char[str.size() + 1];
		for (int i = 0; i < str.size(); i++)
		{
			c[i] = str[i];
		}
		c[str.size()] = '\0';
		remove(c);

		delete[] c;
		LinkedList lofcourse;

		
		load_List_Of_Course2(lofcourse);
		Node* currentlofcourse = lofcourse.head;
		
		string temp = currentlofcourse->course.classes;
		while (currentlofcourse != NULL)
		{
			if (currentlofcourse->course.classes == delete_classes && currentlofcourse->course.id == delete_id)
			{
				break;
			}
			else
			{
				currentlofcourse = currentlofcourse->next;
			}
		}
		if (currentlofcourse == NULL)
		{
			return;
		}
		if (currentlofcourse == lofcourse.head)
		{
	
			lofcourse.head = lofcourse.head->next;
			delete currentlofcourse;
			
		}
		else
		{
			Node* prev = lofcourse.head;
			currentlofcourse = lofcourse.head->next;
			while (currentlofcourse != NULL)
			{
				if (currentlofcourse->course.classes == delete_classes && currentlofcourse->course.id == delete_id)
				{
					break;
				}
				else
				{
					currentlofcourse = currentlofcourse->next;
					prev = prev->next;
				}
			}
			prev->next = currentlofcourse->next;
			delete currentlofcourse;

		}
	
		ofstream fout;
		
		fout.open("List_Of_Course.txt");
		if (!fout.is_open())
		{
			cout << "can not open file List_Of_Course.txt to save" << endl;
			return;
		}
		else
		{
			save_list_of_course(fout, lofcourse);
			fout.close();
		}
		cout << "delete " << delete_id << " from " << delete_classes<<" successfully" << endl;
		view_schedule(lst);
	}
	
	


}

void main_delete_course(LinkedList& lst)
{

	Schedule s;
	ifstream fin;
	ofstream fout;
	int count;
	char base[101];

	string inputpath;
	string academic;
	string semester;
	string classes;
	cout << "pls Enter the academic of the Schedule you want to delete course" << endl;
	getline(cin, academic);
	cout << "pls Enter the semester of the Schedule you want to delete course" << endl;
	getline(cin, semester);
	cout << "pls Enter the classes you want to delete course" << endl;
	getline(cin, s.classes);
	inputpath = academic;
	inputpath.append("-");
	inputpath.append(semester);

	inputpath.append("-Schedule-");
	inputpath.append(s.classes);

	inputpath.append(".txt");

	fin.open(inputpath);
	if (!fin.is_open())
	{
		cout << "can not open file "<<inputpath<<" to write,pls check again your file" << endl;
		return;
	}
	else
	{
		load_file_schedule_txt(lst, fin, count);
		view_schedule(lst);

		delete_course(lst, count);
		fout.open(inputpath, ios::out);
		if (!fout.is_open())
		{
			cout << "can not open file "<<inputpath<<" for the ouput" << endl;
			return;
		}
		else
		{
			output_file_schedule_txt(lst, fout);

			//cout << "delete successfully" << endl;
			fout.close();
		}
		fin.close();
	}
}

void remove_specific_student(LinkedList& lst2, LinkedList lst, string classes)
{
	ifstream fin;
	ofstream fout;
	Student s;
	string IDstudent;
	string IDcourse;
	
	string inputpath;
	
	
	cout << "pls input the ID course of the student you remove" << endl;
	getline(cin, IDcourse);
	cout << endl;

	

	inputpath = classes;
	inputpath.append("-");
	inputpath.append(IDcourse);
	inputpath.append(".txt");
	view_Student(inputpath);
	cout << "pls input the ID of the student you want to remove" << endl;
	getline(cin, IDstudent);

	
	Node* currentlst = lst.head;
	//ifstream fin;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int temp;
	
	int attendence[100][100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file,pls check again your file and try again";
		return;
	}
	else
	{
		int count = 0;
		int temp;

		lst2.head = NULL;
		lst2.tail = lst2.head;
		Node* current = lst2.head;
		int i = 0;
		int j = 0;
		getline(fin, s.username, '\n');
		//getline(fin, s.password, '\n');
		getline(fin, s.name, '\n');
		getline(fin, s.DOB, '\n');
		getline(fin, s.gender, '\n');


		fin >> s.midterm;
		fin >> s.final;
		fin >> s.bonus;
		fin >> s.total;
		fin.ignore();
		getline(fin, year1, ' ');
		getline(fin, month1, ' ');
		getline(fin, day1, ' ');
		getline(fin, startHour1, ' ');
		getline(fin, startMinute1, ' ');
		getline(fin, endHour1, ' ');
		getline(fin, endMinute1, ' ');
		//fin >> temp;
		fin >> attendence[i][j];
		//int temp = attendence[i][j];
		fin.ignore();
		j++;
		int n = 1;
		while (n != 10)
		{
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
			n++;
			j++;
		}
		fin >> s.status;
		fin.ignore();
		i++;
		Node* p = create_Node_course_student(s);
		lst2.head = p;
		lst2.head->next = current;
		current = lst2.head;
		n = 1;


		while (!fin.eof())
		{

			getline(fin, s.username, '\n');
			getline(fin, s.username, '\n');
			if (s.username == "")
			{
				break;
			}
			j = 0;
			//getline(fin, s.password, '\n');
			getline(fin, s.name, '\n');
			getline(fin, s.DOB, '\n');
			getline(fin, s.gender, '\n');


			fin >> s.midterm;
			fin >> s.final;
			fin >> s.bonus;
			fin >> s.total;
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
			while (n != 10)
			{
				getline(fin, year1, ' ');
				getline(fin, month1, ' ');
				getline(fin, day1, ' ');
				getline(fin, startHour1, ' ');
				getline(fin, startMinute1, ' ');
				getline(fin, endHour1, ' ');
				getline(fin, endMinute1, ' ');
				fin >> attendence[i][j];
				int temp = attendence[i][j];
				if (n < 9) {
					fin.ignore();
				}
				j++;
				n++;
			}
			fin >> current->student.status;

			fin.ignore();
			n = 1;
			p = create_Node_course_student(s);
			current->next = p;
			current = current->next;
			lst2.tail = current;
			i++;

		}
		fin.close();
	}
	Node* current = lst2.head;
	while (current != NULL)
	{
		if (current->student.username == IDstudent)
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
		if (currentlst->schedule.id == IDcourse)
		{
			break;
		}
		else
		{
			currentlst = currentlst->next;
		}
	}
	if (current == NULL)
	{
		cout << "can not find the student you want to remove" << endl;
		return;
	}
	current->student.status = 0;
	current = lst2.head;
	fout.open(inputpath, ios::out);
	if (!fout.is_open()) {
		cout << "can't open " << inputpath << " file to write,pls check again your file and try again";
		return;
	}
	else {
		int i = 0;
		while (current != NULL) {
			fout << current->student.username << endl;
			//fout << current->student.password << endl;
			fout << current->student.name << endl;
			fout << current->student.DOB << endl;
			fout << current->student.gender << endl;
			fout << current->student.midterm << endl;
			fout << current->student.final << endl;
			fout << current->student.bonus << endl;
			fout << current->student.total << endl;
			int day = string_to_int(currentlst->schedule.startDay);
			int month = string_to_int(currentlst->schedule.startMonth);
			int year = string_to_int(currentlst->schedule.startYear);
			int temp = string_to_int(currentlst->schedule.endDay);

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
			fout << currentlst->schedule.startHour << " ";
			fout << currentlst->schedule.startMinute << " ";
			fout << currentlst->schedule.endHour << " ";
			fout << currentlst->schedule.endMinute << " ";
			int j = 0;
			
			fout << attendence[i][j] << endl;
			j++;
			while (1) //&& month != string_to_int(currentlst->schedule.endMonth))
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
				fout << currentlst->schedule.startHour << " ";
				fout << currentlst->schedule.startMinute << " ";
				fout << currentlst->schedule.endHour << " ";
				fout << currentlst->schedule.endMinute << " ";
				
				fout << attendence[i][j] << endl;
				j++;
				if (day == string_to_int(currentlst->schedule.endDay) && month == string_to_int(currentlst->schedule.endMonth))
				{
					break;
				}
			}
			fout << current->student.status << endl;
			fout << endl;
			i++;
			current = current->next;
		}
	}
	cout << endl;
	cout << "remove successfully" << endl;
	view_Student(inputpath);

	fout.close();

}

void main_remove_specific_student(LinkedList lst, LinkedList& lst2)
{
	Schedule s;

	ifstream fin;
	int count = 0;
	
	string inputpath;
	string academic;
	string semester;
	string classes;
	cout << "pls Enter the academic of the course you want to remove student" << endl;
	getline(cin, academic);
	cout << "pls Enter the semester of the course you want to remove student" << endl;
	getline(cin, semester);
	cout << "pls Enter the classes you want to remove student" << endl;
	getline(cin, s.classes);
	inputpath = academic;
	inputpath.append("-");
	inputpath.append(semester);
	//inputpath.append("-");
	inputpath.append("-Schedule-");
	inputpath.append(s.classes);

	inputpath.append(".txt");

	fin.open(inputpath);
	if (!fin.is_open())
	{
		cout << "can not open file "<<inputpath<<" to write,pls check again your file" << endl;
		return;
	}
	else
	{
		load_file_schedule_txt(lst, fin, count);

		remove_specific_student(lst2, lst, s.classes);
		

	}
	fin.close();

}



void Add_specific_student(LinkedList& lst)
{
	Student s;
	Schedule sc;
	string academic;
	string semester;
	string inputpath;
	int count = 0;
	string outputpath;
	ifstream fin;
	ofstream fout;
	string day;
	string month;
	string year;
	cout << "Enter the academic of the course you want to add student " << endl;

	getline(cin, academic);
	cout << "Enter the semester of the course you want to add student" << endl;
	getline(cin, semester);
	cout << "Enter the classes you want to Add student" << endl;
	getline(cin, sc.classes);
	cout << "Enter Course ID you want to Add student" << endl;
	getline(cin, sc.id);
	cout << "Enter ID of student" << endl;
	getline(cin, s.username);
	
	cout << "Enter the student Name" << endl;
	getline(cin, s.name);
	cout << "Enter student date of bitrh" << endl;
	getline(cin, day);
	cout << "Enter student Month of bitrh" << endl;
	getline(cin, month);
	cout << "Enter student Year of birth" << endl;
	getline(cin, year);
	cout << "Enter student Gender" << endl;
	getline(cin, s.gender);
	s.DOB = day;
	s.DOB.append(" ");
	s.DOB.append(month);
	s.DOB.append(" ");
	s.DOB.append(year);
	inputpath = academic;
	inputpath.append("-");
	inputpath.append(semester);

	inputpath.append("-Schedule-");
	inputpath.append(sc.classes);

	inputpath.append(".txt");

	fin.open(inputpath);
	if (!fin.is_open())
	{
		cout << "can not open "<<inputpath << endl;
		return;
	}
	else
	{
		load_file_schedule_txt(lst, fin, count);
		fin.close();
	}
	Node* current = lst.head;
	while (current != NULL)
	{
		if (current->schedule.id == sc.id)
		{
			break;
		}
		else
		{
			current = current->next;
		}
	}
	if (current == NULL)
	{
		cout << "can not find the ID of your course in Schedule file" << endl;
		return;
	}
	else
	{
		outputpath = sc.classes;
		outputpath.append("-");
		outputpath.append(sc.id);
		outputpath.append(".txt");
		fout.open(outputpath, ios::app);
		if (!fout.is_open())
		{
			cout << "can not open file to write" << endl;
		}
		else
		{
			fout << s.username << endl;

			fout << s.name << endl;
			fout << s.DOB << endl;
			fout << s.gender << endl;
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
			fout << current->schedule.startYear << " ";

			fout << current->schedule.startMonth << " ";
			fout << current->schedule.startDay << " ";
			int day = string_to_int(current->schedule.startDay);
			int month = string_to_int(current->schedule.startMonth);
			int year = string_to_int(current->schedule.startYear);
			int temp = string_to_int(current->schedule.endDay);
			fout << current->schedule.startHour << " ";
			fout << current->schedule.startMinute << " ";
			fout << current->schedule.endHour << " ";
			fout << current->schedule.endMinute << " ";
			fout << "-1" << endl;

			while (1) //&& month != string_to_int(currentlst->data.endMonth))
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
				fout << current->schedule.startHour << " ";
				fout << current->schedule.startMinute << " ";
				fout << current->schedule.endHour << " ";
				fout << current->schedule.endMinute << " ";
				fout << "-1" << endl;
				if (day == string_to_int(current->schedule.endDay) && month == string_to_int(current->schedule.endMonth))
				{
					break;
				}


			}

			fout << current->student.status << endl;
			fout << endl;

		}
	}
	cout << "Add successfully" << endl;
	view_Student(outputpath);

}


void load_file_course_student(LinkedList lst2, LinkedList& lst1, string inputpath, string outputpath, Node* currentlst)
{
	ifstream fin;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int temp;
	ofstream fout;
	string temp1 = currentlst->schedule.startDay;

	
	int attendence[100][100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file" << endl;
		return;
	}
	else
	{
		int count = 0;
		int temp;
		Student s;
		lst2.head = NULL;
		lst2.tail = lst2.head;
		Node* current = lst2.head;
		int i = 0;
		int j = 0;
		getline(fin, s.username, '\n');
	
		getline(fin, s.name, '\n');
		getline(fin, s.DOB, '\n');
		getline(fin, s.gender, '\n');


		fin >> s.midterm;
		fin >> s.final;
		fin >> s.bonus;
		fin >> s.total;
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
		while (n != 10)
		{
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
			n++;
			j++;
		}
		fin >> s.status;
		fin.ignore();
		i++;
		Node* p = create_Node_course_student(s);
		lst2.head = p;
		lst2.head->next = current;
		current = lst2.head;
		n = 1;

		while (!fin.eof())
		{

			getline(fin, s.username, '\n');
			getline(fin, s.username, '\n');
			if (s.username == "")
			{
				break;
			}
			j = 0;
			//getline(fin, s.password, '\n');
			getline(fin, s.name, '\n');
			getline(fin, s.DOB, '\n');
			getline(fin, s.gender, '\n');


			fin >> s.midterm;
			fin >> s.final;
			fin >> s.bonus;
			fin >> s.total;
			fin.ignore();
			getline(fin, year1, ' ');
			getline(fin, month1, ' ');
			getline(fin, day1, ' ');
			getline(fin, startHour1, ' ');
			getline(fin, startMinute1, ' ');
			getline(fin, endHour1, ' ');
			getline(fin, endMinute1, ' ');
			//fin >> temp;
			fin >> attendence[i][j];
			fin.ignore();
			j++;
			int n = 1;
			while (n != 10)
			{
				getline(fin, year1, ' ');
				getline(fin, month1, ' ');
				getline(fin, day1, ' ');
				getline(fin, startHour1, ' ');
				getline(fin, startMinute1, ' ');
				getline(fin, endHour1, ' ');
				getline(fin, endMinute1, ' ');
				fin >> attendence[i][j];
				int temp = attendence[i][j];
				if (n < 9) {
					fin.ignore();
				}
				j++;
				n++;
			}
			fin >> current->student.status;
			fin.ignore();
			n = 1;
			p = create_Node_course_student(s);
			current->next = p;
			current = current->next;
			lst2.tail = current;
			i++;

		}
		fin.close();
	}
	Node* current = lst2.head;
	fout.open(outputpath);
	if (!fout.is_open()) {
		cout << "can't create " << inputpath << " file " << endl;
		return;
	}
	else {
		int i = 0;
		while (current != NULL) {
			fout << current->student.username << endl;
		//	fout << current->student.password << endl;
			fout << current->student.name << endl;
			fout << current->student.DOB << endl;
			fout << current->student.gender << endl;
			fout << current->student.midterm << endl;
			fout << current->student.final << endl;
			fout << current->student.bonus << endl;
			fout << current->student.total << endl;
			int day = string_to_int(currentlst->schedule.startDay);
			int month = string_to_int(currentlst->schedule.startMonth);
			int year = string_to_int(currentlst->schedule.startYear);
			int temp = string_to_int(currentlst->schedule.endDay);

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
			fout << currentlst->schedule.startHour << " ";
			fout << currentlst->schedule.startMinute << " ";
			fout << currentlst->schedule.endHour << " ";
			fout << currentlst->schedule.endMinute << " ";
			int j = 0;
		
			fout << attendence[i][j] << endl;
			j++;
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
				fout << currentlst->schedule.startHour << " ";
				fout << currentlst->schedule.startMinute << " ";
				fout << currentlst->schedule.endHour << " ";
				fout << currentlst->schedule.endMinute << " ";
			
				fout << attendence[i][j] << endl;
				j++;
				if (day == string_to_int(currentlst->schedule.endDay) && month == string_to_int(currentlst->schedule.endMonth))
				{
					break;
				}
			}
			fout << current->student.status << endl;
			fout << endl;
			i++;
			current = current->next;
		}
	}

	fout.close();

}

Node* create_Node_course_student(Student s)
{
	Node* p = new Node;
	p->student.username = s.username;
	p->student.password = s.password;
	p->student.name = s.name;
	p->student.DOB = s.DOB;
	p->student.gender = s.gender;
	p->student.midterm = s.midterm;
	p->student.final = s.final;
	p->student.bonus = s.bonus;
	p->student.total = s.total;
	p->student.status = s.status;

	p->next = NULL;
	return p;
}


Node* CreateNodeAnh_Course(Course c)
{
	Node* p = new Node;
	p->course.classes = c.classes;
	p->course.id = c.id;
	p->next = NULL;
	return p;
}


void load_List_Of_Course2(LinkedList& lstCourse) {
	ifstream fin;
	Course course;
	fin.open("List_Of_Course.txt");
	if (!fin.is_open()) {
		cout << "can't open List_Of_Course.txt";
		return;
	}
	getline(fin, course.classes, '-');
	getline(fin, course.id, '\n');
	lstCourse.head = CreateNodeAnh_Course(course);
	Node* current = lstCourse.head;
	while (!fin.eof()) {

		getline(fin, course.classes, '-');
		if (course.classes == "")
		{
			break;
		}
		getline(fin, course.id, '\n');
		Node* p = CreateNodeAnh_Course(course);
		current->next = p;
		current = current->next;
	}

}

void save_list_of_course(ofstream& fout, LinkedList lstCourse)
{
	Node* current = lstCourse.head;
	while (current != NULL)
	{
		fout << current->course.classes << "-" << current->course.id << endl;
		current = current->next;
	}
}
void export_Score_Board_csv(string inputpath, string outputpath) {
	ifstream fin;
	ofstream fout;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;
	string temp1, tempInput = inputpath;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100], a = -100, b = -100;
	int active[100];
	fin.open(inputpath);
	if (!fin.is_open()) {
		cout << "can't open " << inputpath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.username, '\n');
	getline(fin, student.name, '\n');
	getline(fin, student.DOB, '\n');
	getline(fin, student.gender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.username = student.username;
	p->student.name = student.name;
	p->student.DOB = student.DOB;
	p->student.gender = student.gender;
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
	getline(fin, schedule.startHour, ' ');
	getline(fin, schedule.startMinute, ' ');
	getline(fin, schedule.endHour, ' ');
	getline(fin, schedule.endMinute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.startHour = schedule.startHour;
	p->schedule.startMinute = schedule.startMinute;
	p->schedule.endHour = schedule.endHour;
	p->schedule.endMinute = schedule.endMinute;
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
		getline(fin, student.username, '\n');
		getline(fin, student.username, '\n');
		getline(fin, student.name, '\n');
		getline(fin, student.DOB, '\n');
		getline(fin, student.gender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.username = student.username;
		p->student.name = student.name;
		p->student.DOB = student.DOB;
		p->student.gender = student.gender;
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
				getline(fin, schedule.endYear, ' ');
				getline(fin, schedule.endMonth, ' ');
				getline(fin, schedule.endDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.endDay = schedule.endDay;
				p->schedule.endMonth = schedule.endMonth;
				p->schedule.endYear = schedule.endYear;
				p->schedule.startHour = schedule.startHour;
				p->schedule.startMinute = schedule.startMinute;
				p->schedule.endHour = schedule.endHour;
				p->schedule.endMinute = schedule.endMinute;
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
		cout << "can't create " << outputpath << " file\n";
		return;
	}
	while (current->next != NULL) {
		fout << current->student.username << endl;
		fout << current->student.name << endl;
		fout << "midterm: " << current->student.midterm << endl;
		fout << "final: " << current->student.final << endl;
		fout << "bonus: " << current->student.bonus << endl;
		fout << "total: " << current->student.total << endl;
		fout << endl;
		current = current->next;
		fout << endl;
	}
	cout << "\nExport scoreboard succesfully\n";
	fout.close();
}
void view_List_Of_Course2(LinkedList& lstCourse) {
	ifstream fin;
	Course course;
	fin.open("List_Of_Course.txt");
	if (!fin.is_open()) {
		cout << "can't open List_Of_Course.txt";
	}
	getline(fin, course.classes, '-');
	getline(fin, course.id, '\n');
	lstCourse.head = CreateNodeAnh_Course(course);
	Node* current = lstCourse.head;
	while (!fin.eof()) {
		getline(fin, course.classes, '-');
		getline(fin, course.id, '\n');
		Node* p = CreateNodeAnh_Course(course);
		current->next = p;
		current = current->next;
	}
	current = lstCourse.head;
	int i = 1;
	while (current->next != NULL) {
		cout << i << "." << current->course.classes << "-" << current->course.id << "\n";
		i++;
		current = current->next;
	}
}
void main_export_Score_Board_csv() {
	LinkedList lstCourse;
	string class_View, courseID_View, Class, inputPath, outputpath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. exit\n";
		cout << "Enter Class of courese to export:";
		getline(cin, class_View);
		cout << "Enter id of courese to export:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classes && courseID_View == current->course.id) {
					inputPath = "";
					inputPath.append(current->course.classes);
					inputPath.append("-");
					inputPath.append(current->course.id);
					inputPath.append(".txt");
					outputpath = "";
					outputpath.append(current->course.classes);
					outputpath.append("-");
					outputpath.append(current->course.id);
					outputpath.append("-");
					outputpath.append("NewScoreboard");
					outputpath.append(".csv");
					export_Score_Board_csv(inputPath, outputpath);
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
void view_ScoreBoard2(string inputPath) {
	ifstream fin;
	ofstream fout;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;
	string temp1, tempInput = inputPath;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100], a = -100, b = -100;
	int active[100];
	fin.open(inputPath);
	if (!fin.is_open()) {
		cout << "can't open " << inputPath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.username, '\n');
	getline(fin, student.name, '\n');
	getline(fin, student.DOB, '\n');
	getline(fin, student.gender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.username = student.username;
	p->student.name = student.name;
	p->student.DOB = student.DOB;
	p->student.gender = student.gender;
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
	getline(fin, schedule.startHour, ' ');
	getline(fin, schedule.startMinute, ' ');
	getline(fin, schedule.endHour, ' ');
	getline(fin, schedule.endMinute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.startHour = schedule.startHour;
	p->schedule.startMinute = schedule.startMinute;
	p->schedule.endHour = schedule.endHour;
	p->schedule.endMinute = schedule.endMinute;
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
		getline(fin, student.username, '\n');
		getline(fin, student.username, '\n');
		getline(fin, student.name, '\n');
		getline(fin, student.DOB, '\n');
		getline(fin, student.gender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.username = student.username;
		p->student.name = student.name;
		p->student.DOB = student.DOB;
		p->student.gender = student.gender;
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
				getline(fin, schedule.endYear, ' ');
				getline(fin, schedule.endMonth, ' ');
				getline(fin, schedule.endDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.endDay = schedule.endDay;
				p->schedule.endMonth = schedule.endMonth;
				p->schedule.endYear = schedule.endYear;
				p->schedule.startHour = schedule.startHour;
				p->schedule.startMinute = schedule.startMinute;
				p->schedule.endHour = schedule.endHour;
				p->schedule.endMinute = schedule.endMinute;
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

	while (current->next != NULL) {
		cout << current->student.username << endl;
		cout << current->student.name << endl;
		cout << "midterm: " << current->student.midterm << endl;
		cout << "final: " << current->student.final << endl;
		cout << "bonus: " << current->student.bonus << endl;
		cout << "total: " << current->student.total << endl;
		cout << endl;
		current = current->next;
		cout << endl;
	}
}
void main_View_Score_Board() {
	LinkedList lstCourse;
	string class_View, courseID_View, inputPath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. exit\n";
		cout << "Enter Class of courese to view ScoreBoard:";
		getline(cin, class_View);
		cout << "Enter id of courese to view ScoreBoard:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classes && courseID_View == current->course.id) {
					inputPath = "";
					inputPath.append(current->course.classes);
					inputPath.append("-");
					inputPath.append(current->course.id);
					inputPath.append(".txt");
					view_ScoreBoard2(inputPath);
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
void view_Student(string inputPath) {
	ifstream fin;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;

	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputPath);
	if (!fin.is_open()) {
		cout << "can't open " << inputPath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.username, '\n');
	getline(fin, student.name, '\n');
	getline(fin, student.DOB, '\n');
	getline(fin, student.gender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.username = student.username;
	p->student.name = student.name;
	p->student.DOB = student.DOB;
	p->student.gender = student.gender;
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
	getline(fin, schedule.startHour, ' ');
	getline(fin, schedule.startMinute, ' ');
	getline(fin, schedule.endHour, ' ');
	getline(fin, schedule.endMinute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.startHour = schedule.startHour;
	p->schedule.startMinute = schedule.startMinute;
	p->schedule.endHour = schedule.endHour;
	p->schedule.endMinute = schedule.endMinute;
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
		getline(fin, student.username, '\n');
		getline(fin, student.username, '\n');
		getline(fin, student.name, '\n');
		getline(fin, student.DOB, '\n');
		getline(fin, student.gender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.username = student.username;
		p->student.name = student.name;
		p->student.DOB = student.DOB;
		p->student.gender = student.gender;
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
				getline(fin, schedule.endYear, ' ');
				getline(fin, schedule.endMonth, ' ');
				getline(fin, schedule.endDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.endDay = schedule.endDay;
				p->schedule.endMonth = schedule.endMonth;
				p->schedule.endYear = schedule.endYear;
				p->schedule.startHour = schedule.startHour;
				p->schedule.startMinute = schedule.startMinute;
				p->schedule.endHour = schedule.endHour;
				p->schedule.endMinute = schedule.endMinute;
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
		cout << current->student.username << endl;
		cout << current->student.name << endl;
		cout << current->student.DOB << endl;
		if (current->student.gender == "0") {
			cout << "Male\n";
		}
		else {
			cout << "Female\n";
		}
		cout << active[i];
		cout << endl;
		i++;
		current = current->next;
		cout << endl;
	}
}
void main_View_Student_Of_Course() {
	LinkedList lstCourse;
	string class_View, courseID_View, inputPath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. exit\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter id of courese to view:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classes && courseID_View == current->course.id) {
					inputPath = "";
					inputPath.append(current->course.classes);
					inputPath.append("-");
					inputPath.append(current->course.id);
					inputPath.append(".txt");
					view_Student(inputPath);
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

void main_View_Attendence_List_Of_Course()
{
	LinkedList lstCourse;
	string class_View, courseID_View, Class, inputPath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. exit\n";
		cout << "Enter Class of courese to view:";
		getline(cin, class_View);
		cout << "Enter id of courese to view:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classes && courseID_View == current->course.id) {
					inputPath = "";
					inputPath.append(current->course.classes);
					inputPath.append("-");
					inputPath.append(current->course.id);
					inputPath.append(".txt");
					view_3(inputPath);
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
int string_to_int2(string temp)
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
void view_3(string inputPath)
{
	ifstream fin;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;

	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputPath);
	if (!fin.is_open()) {
		cout << "can't open " << inputPath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.username, '\n');
	getline(fin, student.name, '\n');
	getline(fin, student.DOB, '\n');
	getline(fin, student.gender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.username = student.username;
	p->student.name = student.name;
	p->student.DOB = student.DOB;
	p->student.gender = student.gender;
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
	getline(fin, schedule.startHour, ' ');
	getline(fin, schedule.startMinute, ' ');
	getline(fin, schedule.endHour, ' ');
	getline(fin, schedule.endMinute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.startHour = schedule.startHour;
	p->schedule.startMinute = schedule.startMinute;
	p->schedule.endHour = schedule.endHour;
	p->schedule.endMinute = schedule.endMinute;
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
		getline(fin, student.username, '\n');
		getline(fin, student.username, '\n');
		getline(fin, student.name, '\n');
		getline(fin, student.DOB, '\n');
		getline(fin, student.gender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.username = student.username;
		p->student.name = student.name;
		p->student.DOB = student.DOB;
		p->student.gender = student.gender;
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
				getline(fin, schedule.endYear, ' ');
				getline(fin, schedule.endMonth, ' ');
				getline(fin, schedule.endDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.endDay = schedule.endDay;
				p->schedule.endMonth = schedule.endMonth;
				p->schedule.endYear = schedule.endYear;
				p->schedule.startHour = schedule.startHour;
				p->schedule.startMinute = schedule.startMinute;
				p->schedule.endHour = schedule.endHour;
				p->schedule.endMinute = schedule.endMinute;
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
		cout << current->student.username << endl;
		cout << current->student.name << endl;
		cout << current->student.DOB << endl;
		if (current->student.gender == "0") {
			cout << "Male\n";
		}
		else {
			cout << "Female\n";
		}
		int day = string_to_int2(currentlst->schedule.startDay);
		int month = string_to_int2(currentlst->schedule.startMonth);
		int year = string_to_int2(currentlst->schedule.startYear);
		int temp = string_to_int2(currentlst->schedule.endDay);
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
		cout << currentlst->schedule.startHour << " ";
		cout << currentlst->schedule.startMinute << " ";
		cout << currentlst->schedule.endHour << " ";
		cout << currentlst->schedule.endMinute << " ";
		int j = 0;
		cout << attendence[i][j] << endl;
		j++;
		while (1) //&& month != string_to_int2(currentlst->schedule.endmonth))
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
			cout << currentlst->schedule.startHour << " ";
			cout << currentlst->schedule.startMinute << " ";
			cout << currentlst->schedule.endHour << " ";
			cout << currentlst->schedule.endMinute << " ";
			cout << attendence[i][j] << endl;
			j++;
			if (day == string_to_int2(currentlst->schedule.endDay) && month == string_to_int2(currentlst->schedule.endMonth)) {
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
Node* CreateNodeAnhLtr(Lecturer lecturer) {
	Node* p = new Node;
	p->lecturer.username = lecturer.username;
	p->lecturer.password = lecturer.password;
	p->lecturer.name = lecturer.name;
	p->lecturer.degree = lecturer.degree;
	p->lecturer.gender = lecturer.gender;
	p->next = NULL;
	return p;
}

void viewLecturer(LinkedList &lst) {
	ifstream fin;
	int n;
	fin.open("Lecturer.txt");
	if (!fin.is_open()) {
		cout << "can't open Lecturer.txt file";
	}
	lst.head = NULL;
	Lecturer lecturer;
	string username, password, name, degree;
	int gender = 0;

	int i = 0;
	getline(fin, lecturer.username, '\n');
	getline(fin, lecturer.password, '\n');
	getline(fin, lecturer.name, '\n');
	getline(fin, lecturer.degree, '\n');
	fin >> lecturer.gender;
	fin.ignore();
	Node* p = CreateNodeAnhLtr(lecturer);
	lst.head = p;
	Node* current = lst.head;
	current->lecturer.order = 1;
	int b = 1;
	while(!fin.eof()) {
		fin.ignore();
		getline(fin, lecturer.username, '\n');
		getline(fin, lecturer.username, '\n');
		getline(fin, lecturer.password, '\n');
		getline(fin, lecturer.name, '\n');
		getline(fin, lecturer.degree, '\n');
		fin >> lecturer.gender;
		fin.ignore();
		p = p = CreateNodeAnhLtr(lecturer);
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
		cout << current->lecturer.name << "\n";
		cout << current->lecturer.degree << "\n";
		if (current->lecturer.gender == "0") {
			cout << "Male";
		}
		else {
			cout << "Female";
		}
		cout << "\n" << "\n";
		current = current->next;
	}
}

//Bonus
Node* createNoteSemester(Semester& s)
{
	Node* p = new Node;
	strcpy_s(p->data.academic, 20, s.academic);
	strcpy_s(p->data.Semesters, 11, s.Semesters);
	p->data.n = s.n;
	p->next = NULL;
	return p;
}

void create_file(LinkedList& lst, Semester s, ofstream& fout)
{

	int temp = 0;
	lst.head = NULL;
	Node* current = lst.head;
	Node* P = createNoteSemester(s);
	lst.head = P;
	lst.head->next = current;
	fout << lst.head->data.n << endl;
	fout << lst.head->data.academic << endl;
	fout << lst.head->data.Semesters << endl;
	fout << temp;

}

void input_Semester(LinkedList& lst, ifstream& fin)
{
	int x;
	Semester s;
	fin >> s.n;
	fin >> s.academic;
	fin >> s.Semesters;
	lst.head = NULL;
	Node* current = lst.head;
	Node* p = createNoteSemester(s);
	lst.head = p;
	lst.head->next = current;
	current = lst.head;


	while (true)
	{
		fin >> x;
		if (x == 0)
		{
			break;
		}
		else
		{
			s.n = x;
			fin >> s.academic;
			fin >> s.Semesters;
			p = createNoteSemester(s);
			current->next = p;
			current = current->next;

		}
	}
}

void view_Semester(LinkedList lst)
{
	Node* current = lst.head;
	while (current != NULL)
	{
		cout << current->data.n << endl;
		cout << current->data.academic << endl;
		cout << current->data.Semesters << endl;
		current = current->next;
	}
}

void update_Semester(LinkedList& lst, Semester& s)
{
	Node* current = lst.head;
	if (current->next != NULL)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		s.n = current->data.n;
		s.n++;

		Node* p = createNoteSemester(s);
		current->next = p;
	}
	else
	{
		s.n = current->data.n;
		s.n++;
		Node* p = createNoteSemester(s);
		current->next = p;
	}
	cout << "update semester successfully" << endl;
	view_Semester(lst);


}

void output_Semester(LinkedList lst, ofstream& fout)
{
	int temp = 0;
	Node* current = lst.head;
	while (current != NULL)
	{
		fout << current->data.n << endl;
		fout << current->data.academic << endl;
		fout << current->data.Semesters << endl;
		current = current->next;
	}
	fout << temp;
}


void delete_Semester(LinkedList& lst)
{
	int n;
	view_Semester(lst);
	cout << "pls choose the num of the Semester you want to delete" << endl;
	cin >> n;
	Node* current = lst.head;
	while (current != NULL)
	{
		if (current->data.n == n)
		{
			break;
		}
		else
		{
			current = current->next;
		}
	}
	if (current == lst.head || n == 1)
	{
		if (lst.head->next == NULL)
		{
			delete current;
			lst.head = NULL;
		}
		else
		{
			lst.head = lst.head->next;
			delete current;
			current = lst.head;
			while (current != NULL)
			{
				current->data.n--;
				current = current->next;
			}
		}
	}
	else if (current->next == NULL)
	{
		Node* prev = lst.head;
		if (prev->next != current)
		{
			while (prev->next != current)
			{
				prev = prev->next;
			}
			delete current;
			prev->next = NULL;
		}
		else
		{
			delete current;
			prev->next = NULL;
		}

	}
	else
	{
		Node* prev = lst.head;
		if (prev->next != current)
		{
			while (prev->next != current)
			{
				prev = prev->next;
			}
			prev->next = current->next;
			delete current;
			current = lst.head;
			while (current != NULL)
			{
				if (current->data.n > n)
				{
					break;
				}
				else
				{
					current = current->next;
				}
			}
			while (current != NULL)
			{
				current->data.n--;
				current = current->next;
			}


		}
		else
		{
			prev->next = current->next;
			delete current;


		}

	}
	cout << "delete semester successfully" << endl;
	view_Semester(lst);
}

void main_semester()
{
	string choice;
	Semester s;
	LinkedList lst;
	ofstream fout;
	ifstream fin;
	while (true)
	{
		cout << "-----Semester function-----" << endl;
		cout << "1. Create Semester" << endl;
		cout << "2. Update Semester" << endl;
		cout << "3. Delete Semester" << endl;
		cout << "4. View Semester" << endl;
		cout << "0. Exit" << endl;
		cout << "Choice: ";
		cin >> choice;
		cout << endl;
		cout << endl;
		if (choice == "1")
		{

			cout << "input year: ";
			cin.getline(s.academic, 20);
			cin.getline(s.academic, 20);
			cout << "input Semester: ";
			cin.getline(s.Semesters, 10);
			s.n++;
			fout.open("Semester.txt");
			if (!fout.is_open())
			{
				cout << "can not create file semester.txt";
			}
			else
			{
				create_file(lst, s, fout);
				fout.close();
			}

			cout << endl;
		}
		else if (choice == "4")
		{
			fin.open("Semester.txt");
			if (!fin.is_open())
			{
				cout << "can not open file Semester.txt pls check again your file"<<endl;
			}
			else
			{
				input_Semester(lst, fin);
				view_Semester(lst);
				fin.close();
			}


		}
		else if (choice == "0")
		{
			break;
		}
		else if (choice == "3")
		{
			fin.open("Semester.txt");
			if (!fin.is_open())
			{
				cout << "can not open file Semester.txt,pls check again your file" << endl;
			}
			else
			{
				input_Semester(lst, fin);
				if (lst.head == NULL)
				{
					cout << "pls create file semester.txt first";
				}
				else
				{
					delete_Semester(lst);
					fout.open("Semester.txt", ios::out);
					if (!fout.is_open())
					{
						cout << "can not open file Semester.txt to write pls check again your file" << endl;
						
					}
					else
					{
						output_Semester(lst, fout);
						fout.close();
					}
					fin.close();
					cout << endl;

				}
			}
		}
		else if (choice == "2")
		{


			fin.open("Semester.txt");
			if (!fin.is_open())
			{
				cout << "can not open file";
			}
			else
			{
				input_Semester(lst, fin);
				if (lst.head == NULL)
				{
					cout << "pls create file";
				}
				else
				{
					cout << "input year: ";
					cin.getline(s.academic, 20);
					cin.getline(s.academic, 20);
					cout << "input Semester: ";
					cin.getline(s.Semesters, 10);
					update_Semester(lst, s);
					fout.open("Semester.txt", ios::out);
					if (!fout.is_open())
					{
						cout << "can not open file semester.txt to write" << endl;
						
					}
					else
					{
						output_Semester(lst, fout);
						fout.close();
					}
					fin.close();
					cout << endl;
				}
			}
		}
		else
		{
		cout << "your choice dosen't exsit pls choose again" << endl;
		continue;
 }
	}
}
void main_Edit_Attendence() {
	LinkedList lstCourse;
	string class_View, courseID_View, inputPath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. exit\n";
		cout << "Enter Class of courese to edit:";
		getline(cin, class_View);
		cout << "Enter id of courese to edit:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classes && courseID_View == current->course.id) {
					inputPath = "";
					inputPath.append(current->course.classes);
					inputPath.append("-");
					inputPath.append(current->course.id);
					inputPath.append(".txt");
					edit_Attendence2(inputPath);
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
void edit_Attendence2(string inputPath) {
	ifstream fin;
	ofstream fout;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;
	string studentID_View;
	int year_edit = 0, month_edit = 0, day_edit = 0, attend;
	int a = -100;
	int b = -100;
	view_3(inputPath);
	cout << "Enter Student ID to edit: ";
	getline(cin, studentID_View);

	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputPath);
	if (!fin.is_open()) {
		cout << "can't open " << inputPath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.username, '\n');
	getline(fin, student.name, '\n');
	getline(fin, student.DOB, '\n');
	getline(fin, student.gender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.username = student.username;
	p->student.name = student.name;
	p->student.DOB = student.DOB;
	p->student.gender = student.gender;
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
	getline(fin, schedule.startHour, ' ');
	getline(fin, schedule.startMinute, ' ');
	getline(fin, schedule.endHour, ' ');
	getline(fin, schedule.endMinute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.startHour = schedule.startHour;
	p->schedule.startMinute = schedule.startMinute;
	p->schedule.endHour = schedule.endHour;
	p->schedule.endMinute = schedule.endMinute;
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
		getline(fin, student.username, '\n');
		getline(fin, student.username, '\n');
		getline(fin, student.name, '\n');
		getline(fin, student.DOB, '\n');
		getline(fin, student.gender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.username = student.username;
		p->student.name = student.name;
		p->student.DOB = student.DOB;
		p->student.gender = student.gender;
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
				getline(fin, schedule.endYear, ' ');
				getline(fin, schedule.endMonth, ' ');
				getline(fin, schedule.endDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.endDay = schedule.endDay;
				p->schedule.endMonth = schedule.endMonth;
				p->schedule.endYear = schedule.endYear;
				p->schedule.startHour = schedule.startHour;
				p->schedule.startMinute = schedule.startMinute;
				p->schedule.endHour = schedule.endHour;
				p->schedule.endMinute = schedule.endMinute;
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
	fout.open(inputPath);
	if (!fout.is_open()) {
		cout << "can't save " << inputPath << " file\n";
	}
	i = 0;
	while (current->next != NULL) {
		if (current->student.username == studentID_View) {
			cout << "Enter year to edit: ";
			cin >> year_edit;
			cout << "Enter month to edit: ";
			cin >> month_edit;
			cout << "Enter day to edit: ";
			cin >> day_edit;
			b = 100;
		}
		fout << current->student.username << endl;
		fout << current->student.name << endl;
		fout << current->student.DOB << endl;
		fout << current->student.gender << endl;
		fout << current->student.midterm << endl;
		fout << current->student.final << endl;
		fout << current->student.bonus << endl;
		fout << current->student.total << endl;
		int day = string_to_int2(currentlst->schedule.startDay);
		int month = string_to_int2(currentlst->schedule.startMonth);
		int year = string_to_int2(currentlst->schedule.startYear);
		int temp = string_to_int2(currentlst->schedule.endDay);
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
		fout << currentlst->schedule.startHour << " ";
		fout << currentlst->schedule.startMinute << " ";
		fout << currentlst->schedule.endHour << " ";
		fout << currentlst->schedule.endMinute << " ";
		int j = 0;
		if (year_edit == year && month_edit == month && day_edit == day && (current->student.username == studentID_View)) {
			cout << "Enter Attendence for this day: ";
			cin >> attend;
			attendence[i][j] = attend;
			a = 100;

		}
		fout << attendence[i][j] << endl;
		j++;
		while (1) //&& month != string_to_int2(currentlst->schedule.endmonth))
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
			fout << currentlst->schedule.startHour << " ";
			fout << currentlst->schedule.startMinute << " ";
			fout << currentlst->schedule.endHour << " ";
			fout << currentlst->schedule.endMinute << " ";
			if (year_edit == year && month_edit == month && day_edit == day && (current->student.username == studentID_View)) {
				cout << "Enter Attendence for this day: ";
				cin >> attend;
				attendence[i][j] = attend;
				a = 100;

			}
			fout << attendence[i][j] << endl;
			if (day == string_to_int2(currentlst->schedule.endDay) && month == string_to_int2(currentlst->schedule.endMonth)) {
				break;
			}
			j++;
		}
		fout << active[i];
		fout << endl;
		i++;
		current = current->next;
		fout << endl;
	}if (b == -100) {
		cout << "\nStudent ID not exits\n";
		cout << "\n Please Entered again: \n";
	}
	if (a == 100) {
		view_3(inputPath);
		cout << "After edit\n";
		cout << "\nEdit successfully\n";
		cin.ignore();
	}
	else {
		if (b != -100) {
			cout << "\n day or month or year you Entered not exits\n";
			cout << "\n Please Entered again: \n";
		}
	}
	fout.close();
}
void import_Score_Board2(string inputPath) {
	ifstream fin;
	ofstream fout;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;
	string temp1, tempInput = inputPath;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputPath);
	if (!fin.is_open()) {
		cout << "can't open " << inputPath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.username, '\n');
	getline(fin, student.name, '\n');
	getline(fin, student.DOB, '\n');
	getline(fin, student.gender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.username = student.username;
	p->student.name = student.name;
	p->student.DOB = student.DOB;
	p->student.gender = student.gender;
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
	getline(fin, schedule.startHour, ' ');
	getline(fin, schedule.startMinute, ' ');
	getline(fin, schedule.endHour, ' ');
	getline(fin, schedule.endMinute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.startHour = schedule.startHour;
	p->schedule.startMinute = schedule.startMinute;
	p->schedule.endHour = schedule.endHour;
	p->schedule.endMinute = schedule.endMinute;
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
		getline(fin, student.username, '\n');
		getline(fin, student.username, '\n');
		getline(fin, student.name, '\n');
		getline(fin, student.DOB, '\n');
		getline(fin, student.gender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.username = student.username;
		p->student.name = student.name;
		p->student.DOB = student.DOB;
		p->student.gender = student.gender;
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
				getline(fin, schedule.endYear, ' ');
				getline(fin, schedule.endMonth, ' ');
				getline(fin, schedule.endDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.endDay = schedule.endDay;
				p->schedule.endMonth = schedule.endMonth;
				p->schedule.endYear = schedule.endYear;
				p->schedule.startHour = schedule.startHour;
				p->schedule.startMinute = schedule.startMinute;
				p->schedule.endHour = schedule.endHour;
				p->schedule.endMinute = schedule.endMinute;
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
	cout << "\nEnter Link to Score Board csv flie: ";
	getline(cin, inputPath);
	fin.open(inputPath);
	if (!fin.is_open()) {
		cout << "can't open " << inputPath << " file\n";
	}
	else {
		getline(fin, temp1, '\n');
		Node* current = lst2.head;
		char a;
		while (current->next != NULL) {
			getline(fin, temp1, ',');
			getline(fin, temp1, ',');
			if (temp1 != current->student.username) {
				cout << "\n Student ID: " << temp1 << " not exist in Course\n";
				cout << "\n Please Enter Link again\n";
				return;
			}
			getline(fin, temp1, ',');
			fin >> current->student.midterm;
			//cout << "\n" << current->student.midterm << "\n";
			fin.ignore();
			fin >> a;
			fin >> current->student.final;
			//	cout << "\n" << current->student.final << "\n";
			current->student.final += int(a - '0');
			fin.ignore();
			fin >> a;
			fin >> current->student.bonus;
			current->student.bonus += int(a - '0');
			fin.ignore();
			fin >> a;
			fin >> current->student.total;
			current->student.total += int(a - '0');
			fin.ignore();
			current = current->next;
		}
		cout << "Import sucessfully\n";
	}
	fin.close();
	currentlst = lst.head;
	current = lst2.head;
	inputPath = tempInput;
	fout.open(inputPath);
	if (!fout.is_open()) {
		cout << "can't save " << inputPath << " file\n";
	}
	i = 0;
	while (current->next != NULL) {
		fout << current->student.username << endl;
		fout << current->student.name << endl;
		fout << current->student.DOB << endl;
		fout << current->student.gender << endl;
		fout << current->student.midterm << endl;
		fout << current->student.final << endl;
		fout << current->student.bonus << endl;
		fout << current->student.total << endl;
		int day = string_to_int2(currentlst->schedule.startDay);
		int month = string_to_int2(currentlst->schedule.startMonth);
		int year = string_to_int2(currentlst->schedule.startYear);
		int temp = string_to_int2(currentlst->schedule.endDay);
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
		fout << currentlst->schedule.startHour << " ";
		fout << currentlst->schedule.startMinute << " ";
		fout << currentlst->schedule.endHour << " ";
		fout << currentlst->schedule.endMinute << " ";
		int j = 0;
		fout << attendence[i][j] << endl;
		j++;
		while (1) //&& month != string_to_int2(currentlst->schedule.endmonth))
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
			fout << currentlst->schedule.startHour << " ";
			fout << currentlst->schedule.startMinute << " ";
			fout << currentlst->schedule.endHour << " ";
			fout << currentlst->schedule.endMinute << " ";

			fout << attendence[i][j] << endl;
			if (day == string_to_int2(currentlst->schedule.endDay) && month == string_to_int2(currentlst->schedule.endMonth)) {
				break;
			}
			j++;
		}
		fout << active[i];
		fout << endl;
		i++;
		current = current->next;
		fout << endl;
	}
	fout.close();
}
void main_import_ScoreBoard()
{
	LinkedList lstCourse;
	string class_View, courseID_View, inputPath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. exit\n";
		cout << "Enter Class of courese to import:";
		getline(cin, class_View);
		cout << "Enter id of courese to import:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classes && courseID_View == current->course.id) {
					inputPath = "";
					inputPath.append(current->course.classes);
					inputPath.append("-");
					inputPath.append(current->course.id);
					inputPath.append(".txt");
					import_Score_Board2(inputPath);
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
void edit_Grade2(string inputPath) {
	ifstream fin;
	ofstream fout;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;
	string temp1, tempInput = inputPath;
	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100], a = -100, b = -100;
	int active[100];
	string studentID_View;
	view_ScoreBoard2(inputPath);
	cout << "\nEnter Student ID to edit grade: ";
	getline(cin, studentID_View);
	fin.open(inputPath);
	if (!fin.is_open()) {
		cout << "can't open " << inputPath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.username, '\n');
	getline(fin, student.name, '\n');
	getline(fin, student.DOB, '\n');
	getline(fin, student.gender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.username = student.username;
	p->student.name = student.name;
	p->student.DOB = student.DOB;
	p->student.gender = student.gender;
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
	getline(fin, schedule.startHour, ' ');
	getline(fin, schedule.startMinute, ' ');
	getline(fin, schedule.endHour, ' ');
	getline(fin, schedule.endMinute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.startHour = schedule.startHour;
	p->schedule.startMinute = schedule.startMinute;
	p->schedule.endHour = schedule.endHour;
	p->schedule.endMinute = schedule.endMinute;
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
		getline(fin, student.username, '\n');
		getline(fin, student.username, '\n');
		getline(fin, student.name, '\n');
		getline(fin, student.DOB, '\n');
		getline(fin, student.gender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.username = student.username;
		p->student.name = student.name;
		p->student.DOB = student.DOB;
		p->student.gender = student.gender;
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
				getline(fin, schedule.endYear, ' ');
				getline(fin, schedule.endMonth, ' ');
				getline(fin, schedule.endDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.endDay = schedule.endDay;
				p->schedule.endMonth = schedule.endMonth;
				p->schedule.endYear = schedule.endYear;
				p->schedule.startHour = schedule.startHour;
				p->schedule.startMinute = schedule.startMinute;
				p->schedule.endHour = schedule.endHour;
				p->schedule.endMinute = schedule.endMinute;
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
	fout.open(inputPath);
	if (!fout.is_open()) {
		cout << "can't save " << inputPath << " file\n";
	}
	i = 0;
	while (current->next != NULL) {
		fout << current->student.username << endl;
		fout << current->student.name << endl;
		fout << current->student.DOB << endl;
		fout << current->student.gender << endl;
		if (studentID_View == current->student.username) {
			cout << "\nEnter new student.midterm Score: ";
			cin >> current->student.midterm;
			cout << "\nEnter new student.final Score: ";
			cin >> current->student.final;
			cout << "\nEnter new student.bonus Score: ";
			cin >> current->student.bonus;
			cout << "\nEnter new student.total Score: ";
			cin >> current->student.total;
			cin.ignore();
			b = 100;
		}
		fout << current->student.midterm << endl;
		fout << current->student.final << endl;
		fout << current->student.bonus << endl;
		fout << current->student.total << endl;
		int day = string_to_int2(currentlst->schedule.startDay);
		int month = string_to_int2(currentlst->schedule.startMonth);
		int year = string_to_int2(currentlst->schedule.startYear);
		int temp = string_to_int2(currentlst->schedule.endDay);
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
		fout << currentlst->schedule.startHour << " ";
		fout << currentlst->schedule.startMinute << " ";
		fout << currentlst->schedule.endHour << " ";
		fout << currentlst->schedule.endMinute << " ";
		int j = 0;
		fout << attendence[i][j] << endl;
		j++;
		while (1) //&& month != string_to_int2(currentlst->schedule.endmonth))
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
			fout << currentlst->schedule.startHour << " ";
			fout << currentlst->schedule.startMinute << " ";
			fout << currentlst->schedule.endHour << " ";
			fout << currentlst->schedule.endMinute << " ";
			fout << attendence[i][j] << endl;
			if (day == string_to_int2(currentlst->schedule.endDay) && month == string_to_int2(currentlst->schedule.endMonth)) {
				break;
			}
			j++;
		}
		fout << active[i];
		fout << endl;
		i++;
		current = current->next;
		fout << endl;
	}
	if (b == -100) {
		cout << "\nStudent ID not exits\n";
		cout << "\n Please Entered again: \n";
	}
	else {
		view_ScoreBoard2(inputPath);
		cout << "After edit\n";
		cout << "\nEdit grade successfully\n";
	}
}
void main_Edit_Grade() {
	LinkedList lstCourse;
	string class_View, courseID_View, inputPath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. exit\n";
		cout << "Enter Class of courese to edit:";
		getline(cin, class_View);
		cout << "Enter id of courese to edit:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classes && courseID_View == current->course.id) {
					inputPath = "";
					inputPath.append(current->course.classes);
					inputPath.append("-");
					inputPath.append(current->course.id);
					inputPath.append(".txt");
					edit_Grade2(inputPath);
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
void menuLecturer() {
	LinkedList lstCourse;
	cin.ignore();
	while (true)
	{
		string choice;
		cout << "-----Lecturer Menu-----\n";
		cout << "1.View list of courses in the current semester." << endl;
		cout << "2.View list of students of a course." << endl;
		cout << "3.View attendance list of a course." << endl;
		cout << "4.Edit an attendance." << endl;
		cout << "5.Import scoreboard of a course from a csv file." << endl;
		cout << "6.Edit grade of a student" << endl;
		cout << "7.View a scoreboard of a course" << endl;
		cout << "0.exit" << endl;
		cout << "pls choose your choice : ";
		getline(cin, choice);
		if (choice == "1")
		{
			view_List_Of_Course2(lstCourse);
		}
		else if (choice == "2")
		{

			main_View_Student_Of_Course();
		}
		else if (choice == "3")
		{

			main_View_Attendence_List_Of_Course();
		}
		else if (choice == "4")
		{
			main_Edit_Attendence();
		}
		else if (choice == "5")
		{

			main_import_ScoreBoard();
		}
		else if (choice == "6")
		{

			main_Edit_Grade();
		}
		else if (choice == "7")
		{
			main_View_Score_Board();
		}
		else if (choice == "0")
		{
			break;
		}
		
	}
}
void main_Export_Attendence_csv_File() {
	LinkedList lstCourse;
	string class_View, courseID_View, Class, inputPath, outputpath;
	ifstream fin;
	while (1) {
		view_List_Of_Course2(lstCourse);
		Node* current = lstCourse.head;
		cout << "0. exit\n";
		cout << "Enter Class of courese to export:";
		getline(cin, class_View);
		cout << "Enter id of courese to export:";
		getline(cin, courseID_View);
		if (class_View == "0" || courseID_View == "0") {
			break;
		}
		else {
			while (1)
			{
				if (class_View == current->course.classes && courseID_View == current->course.id) {
					inputPath = "";
					inputPath.append(current->course.classes);
					inputPath.append("-");
					inputPath.append(current->course.id);
					inputPath.append(".txt");
					outputpath = "";
					outputpath.append(current->course.classes);
					outputpath.append("-");
					outputpath.append(current->course.id);
					outputpath.append("-");
					outputpath.append("Attendence");
					outputpath.append(".csv");
					export_3(inputPath, outputpath);
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
void export_3(string inputPath, string outputpath)
{
	ifstream fin;
	ofstream fout;
	LinkedList lst2, lst;
	Student student;
	Schedule schedule;

	string day1, month1, year1, startHour1, startMinute1, endHour1, endMinute1;
	int attendence[100][100];
	int active[100];
	fin.open(inputPath);
	if (!fin.is_open()) {
		cout << "can't open " << inputPath << " file";
	}
	int i = 0;
	int j = 0;
	getline(fin, student.username, '\n');
	getline(fin, student.name, '\n');
	getline(fin, student.DOB, '\n');
	getline(fin, student.gender, '\n');
	fin >> student.midterm;
	fin >> student.final;
	fin >> student.bonus;
	fin >> student.total;
	Node* p = new Node;
	p->student.username = student.username;
	p->student.name = student.name;
	p->student.DOB = student.DOB;
	p->student.gender = student.gender;
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
	getline(fin, schedule.startHour, ' ');
	getline(fin, schedule.startMinute, ' ');
	getline(fin, schedule.endHour, ' ');
	getline(fin, schedule.endMinute, ' ');
	p = new Node;
	p->schedule.startDay = schedule.startDay;
	p->schedule.startMonth = schedule.startMonth;
	p->schedule.startYear = schedule.startYear;
	p->schedule.startHour = schedule.startHour;
	p->schedule.startMinute = schedule.startMinute;
	p->schedule.endHour = schedule.endHour;
	p->schedule.endMinute = schedule.endMinute;
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
		getline(fin, student.username, '\n');
		getline(fin, student.username, '\n');
		getline(fin, student.name, '\n');
		getline(fin, student.DOB, '\n');
		getline(fin, student.gender, '\n');
		fin >> student.midterm;
		fin >> student.final;
		fin >> student.bonus;
		fin >> student.total;
		Node* p = new Node;
		p->student.username = student.username;
		p->student.name = student.name;
		p->student.DOB = student.DOB;
		p->student.gender = student.gender;
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
				getline(fin, schedule.endYear, ' ');
				getline(fin, schedule.endMonth, ' ');
				getline(fin, schedule.endDay, ' ');
				p = new Node;
				p->schedule.startDay = schedule.startDay;
				p->schedule.startMonth = schedule.startMonth;
				p->schedule.startYear = schedule.startYear;
				p->schedule.endDay = schedule.endDay;
				p->schedule.endMonth = schedule.endMonth;
				p->schedule.endYear = schedule.endYear;
				p->schedule.startHour = schedule.startHour;
				p->schedule.startMinute = schedule.startMinute;
				p->schedule.endHour = schedule.endHour;
				p->schedule.endMinute = schedule.endMinute;
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
		fout << current->student.username << endl;
		fout << current->student.name << endl;
		fout << current->student.DOB << endl;
		int day = string_to_int2(currentlst->schedule.startDay);
		int month = string_to_int2(currentlst->schedule.startMonth);
		int year = string_to_int2(currentlst->schedule.startYear);
		int temp = string_to_int2(currentlst->schedule.endDay);
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
		fout << currentlst->schedule.startHour << " ";
		fout << currentlst->schedule.startMinute << " ";
		fout << currentlst->schedule.endHour << " ";
		fout << currentlst->schedule.endMinute << " ";
		int j = 0;
		fout << attendence[i][j] << endl;
		j++;
		while (1) //&& month != string_to_int2(currentlst->schedule.endmonth))
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
			fout << currentlst->schedule.startHour << " ";
			fout << currentlst->schedule.startMinute << " ";
			fout << currentlst->schedule.endHour << " ";
			fout << currentlst->schedule.endMinute << " ";
			fout << attendence[i][j] << endl;
			j++;
			if (day == string_to_int2(currentlst->schedule.endDay) && month == string_to_int2(currentlst->schedule.endMonth)) {
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