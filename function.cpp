#include"header.h"
//Load file
Node *createNode() {
	Node* p = new Node;
	p->next = NULL;
	return p;
}

void loadStaff(fstream &fin, LinkedList &list) {

	list.head = NULL;
	Node* cur = NULL;

	while (true) {
		//init
		Node* p = createNode();
		//add
		fin >> p->staff.username;
		if (p->staff.username == "")
			break;
		fin >> p->staff.password;
		fin.ignore();
		getline(fin, p->staff.name,'\n');
		fin >> p->staff.gender;
		p->type = 1;
		//move
		if (list.head == NULL) {
			list.head = p;
			cur = list.head;
		}
		else {
			cur->next = p;
			cur = cur->next;
		}	
		
	}
	list.tail = cur;
}

void loadLecturer(fstream& fin, LinkedList& list) {

	list.head = NULL;
	Node* cur = NULL;

	while (true) {
		//init
		Node* p = createNode();
		//add
		fin >> p->lecturer.username;
		if (p->lecturer.username == "")
			break;
		fin >> p->lecturer.password;
		fin.ignore();
		getline(fin, p->lecturer.name, '\n');
		getline(fin, p->lecturer.degree, '\n');
		fin >> p->lecturer.gender;
		p->type = 2;
		//move
		if (list.head == NULL) {
			list.head = p;
			cur = list.head;
		}
		else {
			cur->next = p;
			cur = cur->next;
		}

	}
	list.tail = cur;
}

void loadStudent(fstream& fin, LinkedList& studentList)
{

	studentList.head = NULL;
	Node* cur = NULL;

	while (true)
	{

		Node* p = new Node;
		p = createNode();
		getline(fin, p->student.username, '\n');
		if (p->student.username == "")
			break;
		getline(fin, p->student.password, '\n');
		getline(fin, p->student.name, '\n');
		getline(fin, p->student.DOB, '\n');
		getline(fin, p->student.gender, '\n');
		fin >> p->student.midterm;
		fin >> p->student.final;
		fin >> p->student.bonus;
		fin >> p->student.total;

		p->student.checkIn = NULL;
		CheckIn* check_cur = NULL;
		int count = 0;
		while (count != 10) {

			CheckIn* check_p = createCheckIn();

			fin >> check_p->startYear;
			fin >> check_p->startMonth;
			fin >> check_p->startDay;
			fin >> check_p->startHour;
			fin >> check_p->startMinute;
			fin >> check_p->endHour;
			fin >> check_p->endMinute;
			fin >> check_p->check;

			if (p->student.checkIn == NULL) {
				p->student.checkIn = check_p;
				check_cur = check_p;
			}
			else {
				check_cur->next = check_p;
				check_cur = check_cur->next;
			}

			count++;
		}
		fin.ignore();
		fin.ignore();

		if (studentList.head == NULL) {
			studentList.head = p;
			cur = p;
		}
		else {
			cur->next = p;
			cur = cur->next;
			studentList.tail = cur;
		}
	}
}

void readStaffFile(LinkedList& list) {
	fstream fin;
	fin.open("Staff.txt");
	if (!fin.is_open()) {
		cout << "Can't open this file" << endl;
	}
	else {
		loadStaff(fin, list);
	}
	fin.close();
}

void readLecturerFile(LinkedList& list) {
	fstream fin;
	fin.open("Lecturer.txt");
	if (!fin.is_open()) {
		cout << "Can't open this file" << endl;
	}
	else {
		loadLecturer(fin, list);
	}
	fin.close();
}

void readStudentFile(LinkedList &list) {
	fstream fin;
	fin.open("19APCS1-CS162.txt");
	if (!fin.is_open()) {
		cout << "Can't open this file" << endl;
	}
	else {
		loadStudent(fin, list);
	}
	fin.close();
}

//Write file
void save(fstream& fout, LinkedList list, Node user) {

	Node* cur = list.head;

	switch (user.type) {
	case 1:
		cur = list.head;

		while (cur != NULL) {
			fout << cur->staff.username;
			fout << '\n';
			fout << cur->staff.password;
			fout << '\n';
			fout << cur->staff.name;
			fout << '\n';
			if (cur->next != NULL) {
				fout << cur->staff.gender << endl;
				fout << '\n';
			}
			else {
				fout << cur->staff.gender;
			}
			cur = cur->next;
		}
		break;
	case 2:
		cur = list.head;

		while (cur != NULL) {
			fout << cur->lecturer.username;
			fout << '\n';
			fout << cur->lecturer.password;
			fout << '\n';
			fout << cur->lecturer.name;
			fout << '\n';
			fout << cur->lecturer.degree;
			fout << '\n';
			if (cur->next != NULL) {
				fout << cur->lecturer.gender << endl;
				fout << '\n';
			}
			else {
				fout << cur->lecturer.gender;
			}
			cur = cur->next;
		}
		break;
	case 3:
		cur = list.head;

		while (cur != NULL) {
			fout << cur->student.username;
			fout << '\n';
			fout << cur->student.password;
			fout << '\n';
			fout << cur->student.name;
			fout << '\n';
			fout << cur->student.DOB;
			fout << '\n';
			fout << cur->student.gender;
			fout << '\n';
			//point
			fout << cur->student.midterm;
			fout << '\n';
			fout << cur->student.final;
			fout << '\n';
			fout << cur->student.bonus;
			fout << '\n';
			fout << cur->student.total;
			fout << '\n';
			//schedule
			CheckIn* check_cur = cur->student.checkIn;
			int count = 0;
			while (count != 10) {

				fout << check_cur->startYear;
				fout << " ";
				if (check_cur->startMonth < 10)
					fout << "0";
				fout << check_cur->startMonth;
				fout << " ";
				if (check_cur->startDay < 10)
					fout << "0";
				fout << check_cur->startDay;
				fout << " ";
				fout << check_cur->startHour;
				fout << " ";
				fout << check_cur->startMinute;
				fout << " ";
				fout << check_cur->endHour;
				fout << " ";
				fout << check_cur->endMinute;
				fout << " ";
				if (check_cur->next != NULL) {
					fout << check_cur->check << endl;
				}
				else if (check_cur->next == NULL && cur->next == NULL) {
					fout << check_cur->check;
				}
				else {
					fout << check_cur->check << endl;
					fout << '\n';
				}
				//move
				check_cur = check_cur->next;

				count++;
			}
			cur = cur->next;
		}
		break;
	}
}

void write(LinkedList list, Node& user) {
	fstream fout;

	switch (user.type) {
	case 1:
		fout.open("Staff.txt");
		break;
	case 2:
		fout.open("Lecturer.txt");
		break;
	case 3:
		fout.open("19APCS1-CS162.txt");
		break;
	}

	if (!fout.is_open()) {
		cout << "Can't open this file" << endl;
	}
	else {
		save(fout, list, user);
	}
	fout.close();
}

//Login
int checkLogin(string username, string password, Node& user, LinkedList list) {
	Node* cur = list.head;
	switch (user.type) {
	case 1:
		cur = list.head;
		while (cur != NULL) {
			if (cur->staff.username == username && cur->staff.password == password) {
				user.staff.username = cur->staff.username;
				user.staff.password = cur->staff.password;
				user.staff.name = cur->staff.name;
				user.staff.gender = cur->staff.gender;
				return 1;
			}
			else
				cur = cur->next;
		}
		break;
	case 2:
		cur = list.head;
		while (cur != NULL) {
			if (cur->lecturer.username == username && cur->lecturer.password == password) {
				user.lecturer.username = cur->lecturer.username;
				user.lecturer.password = cur->lecturer.password;
				user.lecturer.name = cur->lecturer.name;
				user.lecturer.degree = cur->lecturer.degree;
				user.lecturer.gender = cur->lecturer.gender;
				return 1;
			}
			else
				cur = cur->next;
		}
		break;
	case 3:
		cur = list.head;
		while (cur != NULL) {
			if (cur->student.username == username && cur->student.password == password) {
				user.student.username = cur->student.username;
				user.student.password = cur->student.password;
				user.student.name = cur->student.name;
				user.student.DOB = cur->student.DOB;
				user.student.gender = cur->student.gender;
				//point
				user.student.midterm = cur->student.midterm;
				user.student.final = cur->student.final;
				user.student.bonus = cur->student.bonus;
				user.student.total = cur->student.total;
				int count = 0;
				//schedule
				user.student.checkIn = NULL;
				CheckIn* check_lcur = cur->student.checkIn;
				CheckIn* check_scur = user.student.checkIn;
				while (count != 10) {

					CheckIn* check_p = createCheckIn();

					check_p->startYear = check_lcur->startYear;
					check_p->startMonth = check_lcur->startMonth;
					check_p->startDay = check_lcur->startDay;
					check_p->startHour = check_lcur->startHour;
					check_p->startMinute = check_lcur->startMinute;
					check_p->endHour = check_lcur->endHour;
					check_p->endMinute = check_lcur->endMinute;
					check_p->check = check_lcur->check;
					//move
					if (user.student.checkIn == NULL) {
						user.student.checkIn = check_p;
						check_scur = check_p;
						check_lcur = check_lcur->next;
					}
					else {
						check_scur->next = check_p;
						check_scur = check_scur->next;
						check_lcur = check_lcur->next;
					}
					count++;
				}
				return 1;
			}
			else
				cur = cur->next;
		}
		break;
	}

	return -1;
}

Node login() {
	Node user;
	LinkedList list;
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;

	//check login then return user
	readStaffFile(list);
	user.type = 1;
	if (checkLogin(username, password, user, list) == 1)
	return user;

	readLecturerFile(list);
	user.type = 2;
	if (checkLogin(username, password, user, list) == 1)
	return user;

	readStudentFile(list);
	user.type = 3;
	if (checkLogin(username, password, user, list) == 1)
	return user;

	user.type = -1;
	return user;
}

//Menu 
void menuStaff(Node user) {
	bool con = true;
	int choice;
	while (con) {
		cout << "-----Staff menu-----" << endl;
		cout << "0. Comeback" << endl;
		cout << "choice: ";
		cin >> choice;
		switch (choice) {
			//add here
			case 0:
				con = false;
				break;
			default:
				break;
		}
	}
}

void menuLecturer(Node user) {
	bool con = true;
	int choice;
	while (con) {
		cout << "-----Lecturer menu-----" << endl;
		cout << "0. Comeback" << endl;
		cout << "choice: ";
		cin >> choice;
		switch (choice) {
			//add here
			case 0:
				con = false;
				break;
			default:
				break;
		}
	}
}

void menuStudent(Node user) {
	bool con = true;
	int choice;
	while (con) {
		cout << "-----Student menu-----" << endl;
		cout << "1. Check in" << endl;
		cout << "2. View check in" << endl;
		cout << "3. View schedules" << endl;
		cout << "4. View scores of a course" << endl;
		cout << "0. Comeback" << endl;
		cout << "choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				checkIn(user);
				break;
			case 2:
				viewCheckIn(user);
				break;
			case 3:
				viewSchedules(user);
				break;
			case 4:
				viewScore(user);
				break;
			case 0:
				con = false;
				break;
			default:
				break;
		}
	}	
}

void menuShow(Node user) {
	switch (user.type) {
	case 1:
		menuStaff(user);
		break;
	case 2:
		menuLecturer(user);
		break;
	case 3:
		menuStudent(user);
		break;
	}
}

void menuFunction(Node user) {
	bool con = true;
	int choice;
	while (con) {
		cout << "-----Function menu-----" << endl;
		cout << "1. Show menu" << endl;
		cout << "2. View profile info" << endl;
		cout << "3. Change password" << endl;
		cout << "0. Logout" << endl;
		cout << "choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			menuShow(user);
			break;
		case 2:
			viewProfile(user);
			break;
		case 3:
			changePassword(user);
			break;
		case 0:
			cout << "Goodbye..." << endl;
			con = false;
			break;
		default:
			break;
		}
		
	}
}

void menuLogin() {
	bool con = true;
	int choice;
	Node user;
	while (con) {
		cout << "-----Main menu-----" << endl;
		cout << "1. Login" << endl;
		cout << "0. Exit" << endl;
		cout << "choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				user = login();
				if (user.type != -1)
					menuFunction(user);
				else
					cout << "wrong password or account not existance!" << endl;
				break;
			case 0:
				cout << "Exiting...." << endl;
				con = false;
				break;
			default:
				break;
		}
	}
}

//View profile
string gender(Node user) {
	string gender;
	switch (user.type) {
	case 1:
		if (user.staff.gender == "1") {
			gender = "Female";
			return gender;
		}
		if (user.staff.gender == "0") {
			gender = "Male";
			return gender;
		}
	case 2:
		if (user.lecturer.gender == "1") {
			gender = "Female";
			return gender;
		}
		if (user.lecturer.gender == "0") {
			gender = "Male";
			return gender;
		}
	case 3:
		if (user.student.gender == "1") {
			gender = "Female";
			return gender;
		}
		if (user.student.gender == "0") {
			gender = "Male";
			return gender;
		}
	}
}

void viewProfile(Node user) {
	switch (user.type) {
	case 1:
		cout << "Name:" << user.staff.name << " gender:" << gender(user) << endl;
	case 2:
		cout << "Name:" << user.lecturer.name << " degree:" << user.lecturer.degree << " gender:" << gender(user) << endl;
	case 3:
		cout << "Name:" << user.student.name << " class:" << user.student.classes << " Date of birth:" << user.student.DOB << " gender:" << gender(user) << endl;
	}
	
}

//Change password
void saveNewPassword(LinkedList &list, Node &user) {
	
	Node *cur = list.head;

	switch (user.type) {
	case 1:
		while (cur != NULL) {
			if (cur->staff.name == user.staff.name) {
				cur->staff.password = user.staff.password;
				break;
			}
			else
				cur = cur->next;
		}
		break;
	case 2:
		while (cur != NULL) {
			if (cur->lecturer.name == user.lecturer.name) {
				cur->lecturer.password = user.lecturer.password;
				break;
			}
			else
				cur = cur->next;
		}
		break;
	case 3:
		while (cur != NULL) {
			if (cur->student.name == user.student.name) {
				cur->student.password = user.student.password;
				break;
			}
			else
				cur = cur->next;
		}
		break;
	}
	
}

void changePassword(Node &user) {
	//Read file
	LinkedList list;

	string curPassword;
	string newPassword;
	string newAgPassword;

	list.head = NULL;
	Node* cur = list.head;

	switch (user.type) {
	case 1:
		readStaffFile(list);
		break;
	case 2:
		readLecturerFile(list);
		break;
	case 3:
		readStudentFile(list);
		break;
	}

	cout << "Current password: ";
	cin >> curPassword;
	switch (user.type) {
		case 1:
			if (curPassword == user.staff.password) {
				cout << "New password: ";
				cin >> newPassword;
				cout << "Input new password again: ";
				cin >> newAgPassword;
				if (newPassword == newAgPassword) {
					user.staff.password = newPassword;
					saveNewPassword(list, user);
					write(list, user);
					cout << "Your password is changed!" << endl;
				}
				else
					cout << "input password again is wrong!" << endl;
			}
			else {
				cout << "password is wrong!" << endl;
			}
			break;
		case 2:
			if (curPassword == user.lecturer.password) {
				cout << "New password: ";
				cin >> newPassword;
				cout << "Input new password again: ";
				cin >> newAgPassword;
				if (newPassword == newAgPassword) {
					user.lecturer.password = newPassword;
					saveNewPassword(list, user);
					write(list, user);
					cout << "Your password is changed!" << endl;
				}
				else
					cout << "input password again is wrong!" << endl;
			}
			else {
				cout << "password is wrong!" << endl;
			}
			break;
		case 3:
			if (curPassword == user.student.password) {
				cout << "New password: ";
				cin >> newPassword;
				cout << "Input new password again: ";
				cin >> newAgPassword;
				if (newPassword == newAgPassword) {
					user.student.password = newPassword;
					saveNewPassword(list, user);
					write(list, user);
					cout << "Your password is changed!" << endl;
				}
				else
					cout << "input password again is wrong!" << endl;
			}
			else {
				cout << "password is wrong!" << endl;
			}
			break;
	}
}

//Student function
CheckIn* createCheckIn() {
	CheckIn* p = new CheckIn;
	p->next = NULL;
	return p;
}

//Check in
tm currentDateTime() {
	Time timeNow;

	time_t now = time(0);
	tm localTime;
	now = time(NULL);
	localtime_s(&localTime, &now);

	localTime.tm_sec = (&localTime)->tm_sec;
	localTime.tm_min = (&localTime)->tm_min;
	localTime.tm_hour = (&localTime)->tm_hour;
	localTime.tm_mday = (&localTime)->tm_mday;
	localTime.tm_mon = (&localTime)->tm_mon + 1;
	localTime.tm_year = (&localTime)->tm_year + 1900;

	
	return localTime;
}
//Check in
void saveCheckIn(LinkedList& list, Node& user) {

	CheckIn* check_cur = user.student.checkIn;

	Node* cur = list.head;
	while (cur != NULL) {
		if (user.student.username == cur->student.username) {
			int count = 0;
			//schedule
			CheckIn* check_lcur = cur->student.checkIn;
			CheckIn* check_scur = user.student.checkIn;
			while (count != 10) {
				if (check_lcur->check != check_scur->check)
				{
					check_lcur->check = check_scur->check;
					return;
				}
				//move
				check_scur = check_scur->next;
				check_lcur = check_lcur->next;
				count++;
			}
			return;
		} else
			cur = cur->next;
	}
}

void checkIn(Node &user) {

	tm localTime = currentDateTime();

	CheckIn* check_cur = user.student.checkIn;
	int check = 0;
	while (check_cur != NULL) {

		if (check_cur->startYear == localTime.tm_year) {
			if (check_cur->startMonth == localTime.tm_mon) {
				if (check_cur->startDay == localTime.tm_mday) {
					if (( localTime.tm_hour == check_cur->startHour && localTime.tm_min > check_cur->startMinute)
						|| (localTime.tm_hour > check_cur->startHour && localTime.tm_hour < check_cur->endHour)
						|| (localTime.tm_hour == check_cur->endHour  && localTime.tm_min < check_cur->endMinute)) {
						check_cur->check = 1;
						check++;
						cout << "Checked!" << endl;
						break;
					}
				}
			
			}
		}
		check_cur = check_cur->next;
	}
	if (check == 0)
		cout << "Too late!" << endl;

	LinkedList list;

	readStudentFile(list);
	saveCheckIn(list, user);
	write(list, user);
}



void viewCheckIn(Node user) {

	CheckIn* check_cur = user.student.checkIn;

	while (check_cur != NULL) {
		
		if (check_cur->startDay < 10)
			cout << "0";
		cout << check_cur->startDay << "/";
		if (check_cur->startMonth < 10)
			cout << "0";
		cout << check_cur->startMonth << "/";
		cout << check_cur->startYear << ": ";

		if (check_cur->check == -1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;

		check_cur = check_cur->next;
	}

	cout << endl;
}

void viewSchedules(Node user) {
	
	CheckIn* check_cur = user.student.checkIn;

	while (check_cur != NULL) {
		if (check_cur->startDay < 10)
			cout << "0";
		cout << check_cur->startDay << "/";
		if (check_cur->startMonth < 10)
			cout << "0";
		cout << check_cur->startMonth << "/";
		cout << check_cur->startYear << " ";
		cout << check_cur->startHour << ":";
		cout << check_cur->startMinute << " ";
		cout << check_cur->endHour << ":";
		cout << check_cur->endMinute << endl;

		check_cur = check_cur->next;
	}

	cout << endl;
}

void viewScore(Node user) {

	if (user.student.midterm == -1)
		cout << "Midterm is empty" << endl;
	else
		cout << "Your Midterm: " << user.student.midterm << endl;
	if (user.student.final == -1)
		cout << "Final is empty" << endl;
	else
		cout << "Your Final: " << user.student.midterm << endl;
	if (user.student.bonus == -1)
		cout << "Bonus is empty" << endl;
	else
		cout << "Your Bonus: " << user.student.total << endl;
	if (user.student.total == -1)
		cout << "Total is empty" << endl;
	else
		cout << "Your Total: " << user.student.midterm << endl;

	cout << endl;
}

void displayStudent(LinkedList& list) {

	Node* cur = list.head;
	CheckIn* check_cur = list.head->student.checkIn;

	while (cur != NULL)
	{
		cout << cur->student.username << endl;
		cout << cur->student.password << endl;
		cout << cur->student.name << endl;
		cout << cur->student.DOB << endl;
		cout << cur->student.gender << endl;
		cout << cur->student.midterm << endl;
		cout << cur->student.final << endl;
		cout << cur->student.bonus << endl;
		cout << cur->student.total << endl;

		CheckIn* check_cur = cur->student.checkIn;
		while (check_cur != NULL) {
			cout << check_cur->startDay << " ";
			cout << check_cur->startMonth << " ";
			cout << check_cur->startYear << " ";
			cout << check_cur->startHour << " ";
			cout << check_cur->startMinute << " ";
			cout << check_cur->endHour << " ";
			cout << check_cur->endMinute << " ";
			cout << check_cur->check << endl;

			check_cur = check_cur->next;
		}
		cout << endl;
		cur = cur->next;
	}
}