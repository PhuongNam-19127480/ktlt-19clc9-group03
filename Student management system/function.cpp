#include"header.h"

string classes[101] = { "19APCS1", "19APCS2", "19CLC1", "19CLC2", "19CLC3", "19CLC4",
"19CLC5", "19CLC6", "19CLC7", "19CLC8", "19CLC9", "19CLC10" };

string listOfCourse[101] = {
	"19APCS1-CM101", "19APCS1-CS162",
	"19APCS2-CM101", "19APCS2-CS162",
	"19CLC1-CM101", "19CLC1-CS162",
	"19CLC2-CM101", "19CLC2-CS162",
	"19CLC3-CM101", "19CLC3-CS162",
	"19CLC4-CM101", "19CLC4-CS162",
	"19CLC5-CM101", "19CLC5-CS162",
	"19CLC6-CM101", "19CLC6-CS162",
	"19CLC7-CM101", "19CLC7-CS162",
	"19CLC8-CM101", "19CLC8-CS162",
	"19CLC9-CM101", "19CLC9-CS162",
	"19CLC10-CM101", "19CLC10-CS162"
};

//Load file
Node *createNode() {
	Node* p = new Node;
	p->next = NULL;
	return p;
}

void loadStaff(fstream &fin, LinkedList &list) {

	list.head = NULL;
	Node* cur = NULL;

	while (!fin.eof()) {
		//init
		Node* p = createNode();
		//add
		getline(fin, p->staff.username, '\n');
		getline(fin, p->staff.password, '\n');
		getline(fin, p->staff.name,'\n');
		getline(fin, p->staff.gender, '\n');
		fin.ignore();
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

void loadLecturer(fstream& fin, LinkedList& list) {

	list.head = NULL;
	Node* cur = NULL;

	while (!fin.eof()) {
		//init
		Node* p = createNode();
		//add
		getline(fin, p->lecturer.username, '\n');
		getline(fin, p->lecturer.password, '\n');
		getline(fin, p->lecturer.name, '\n');
		getline(fin, p->lecturer.degree, '\n');
		getline(fin, p->lecturer.gender, '\n');
		fin.ignore();
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

void loadStudent(fstream& fin, LinkedList& list) {
	list.head = NULL;
	Node* cur = NULL;

	while (!fin.eof())
	{
		//init
		Node* p = createNode();
		//add
		p = createNode();
		getline(fin, p->student.username, '\n');
		getline(fin, p->student.password, '\n');
		getline(fin, p->student.name, '\n');
		getline(fin, p->student.DOB, '\n');
		getline(fin, p->student.classes, '\n');
		getline(fin, p->student.gender, '\n');
		fin.ignore();
		p->type = 3;
		//move
		if (list.head == NULL) {
			list.head = p;
			cur = p;
		}
		else {
			cur->next = p;
			cur = cur->next;
		}
	}
	list.tail = cur;
}

void readStudentFile(LinkedList& list) {
	fstream fin;
	fin.open("Student.txt");
	if (!fin.is_open()) {
		cout << "Can't open this file" << endl;
	}
	else {
		loadStudent(fin, list);
	}
	fin.close();
}

//Write file
void save(ofstream& fout, LinkedList list, Node user) {

	Node* cur = list.head;

	switch (user.type) {
	case 1:
		cur = list.head;

		while (cur != NULL) {
			fout << cur->staff.username << endl;
			fout << cur->staff.password << endl;
			fout << cur->staff.name << endl;
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
			fout << cur->lecturer.username << endl;
			fout << cur->lecturer.password << endl;
			fout << cur->lecturer.name << endl;
			fout << cur->lecturer.degree << endl;
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
			fout << cur->student.username << endl;
			fout << cur->student.password << endl;
			fout << cur->student.name << endl;
			fout << cur->student.DOB << endl;
			fout << cur->student.classes << endl;
			if (cur->next != NULL) {
				fout << cur->student.gender << endl;
				fout << '\n';
			}
			else {
				fout << cur->student.gender;
			}
			cur = cur->next;
		}
		break;
	}
}

void write(LinkedList list, Node user) {
	ofstream fout;

	switch (user.type) {
	case 1:
		fout.open("Staff.txt");
		break;
	case 2:
		fout.open("Lecturer.txt");
		break;
	case 3:
		fout.open("Student.txt");
		break;
	}

	if (!fout.is_open()) {
		cout << "Can't open this file" << endl;
	}
	else {
		fout << "";
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
				user.student.classes = cur->student.classes;
				user.student.gender = cur->student.gender;
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
	LinkedList list;
	switch (user.type) {
	case 1:
		menuStaff(user); // funcion_thien
		break;
	case 2:
		menuLecturer(); // fucntion_2A
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
		if (user.staff.gender == "0") {
			gender = "Female";
			return gender;
		}
		if (user.staff.gender == "1") {
			gender = "Male";
			return gender;
		}
	case 2:
		if (user.lecturer.gender == "0") {
			gender = "Female";
			return gender;
		}
		if (user.lecturer.gender == "1") {
			gender = "Male";
			return gender;
		}
	case 3:
		if (user.student.gender == "0") {
			gender = "Female";
			return gender;
		}
		if (user.student.gender == "1") {
			gender = "Male";
			return gender;
		}
	}
}

void viewProfile(Node user) {
	switch (user.type) {
	case 1:
		cout << "Name:" << user.staff.name << " gender:" << gender(user) << endl;
		break;
	case 2:
		cout << "Name:" << user.lecturer.name << " degree:" << user.lecturer.degree << " gender:" << gender(user) << endl;
		break;
	case 3:
		cout << "Name:" << user.student.name << " class:" << user.student.classes << " Date of birth:" << user.student.DOB << " gender:" << gender(user) << endl;
		break;
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

//load check in (load student in classes)
void loadStudentInClass(ifstream& fin, LinkedList& studentList)
{
	studentList.head = NULL;
	Node* cur = NULL;

	while (!fin.eof())
	{
		//init
		Node* p = createNode();
		//add
		p = createNode();
		getline(fin, p->student.username, '\n');
		if (p->student.username == "")
			break;
		getline(fin, p->student.name, '\n');
		getline(fin, p->student.DOB, '\n');
		getline(fin, p->student.gender, '\n');
		//score
		fin >> p->student.midterm;
		fin >> p->student.final;
		fin >> p->student.bonus;
		fin >> p->student.total;
		//check in
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
		//active
		fin >> p->student.status;
		fin.ignore();
		fin.ignore();
		//move
		if (studentList.head == NULL) {
			studentList.head = p;
			cur = p;
		}
		else {
			cur->next = p;
			cur = cur->next;
		}
	}
	studentList.tail = cur;
}

void readStudenInClassFile(string path, LinkedList& studentList) {
	ifstream fin;
	path += ".txt";
	fin.open(path);
	if (!fin.is_open()) {
		cout << "Can't open this file" << endl;
	}
	else {
		loadStudentInClass(fin, studentList);
	}
	fin.close();
}

//Save check in
void saveCheckIn(ofstream& fout, LinkedList studentList) {
	Node* cur = studentList.head;

	while (cur != NULL) {

		fout << cur->student.username << endl;
		fout << cur->student.name << endl;
		fout << cur->student.DOB << endl;
		fout << cur->student.gender << endl;
		//score
		fout << cur->student.midterm << endl;
		fout << cur->student.final << endl;
		fout << cur->student.bonus << endl;
		fout << cur->student.total << endl;
		//schedule
		CheckIn* check_cur = cur->student.checkIn;
		int count = 0;
		while (count != 10) {

			fout << check_cur->startYear << " ";
			if (check_cur->startMonth < 10)
				fout << "0";
			fout << check_cur->startMonth << " ";
			if (check_cur->startDay < 10)
				fout << "0";
			fout << check_cur->startDay << " ";
			fout << check_cur->startHour << " ";
			fout << check_cur->startMinute << " ";
			fout << check_cur->endHour << " ";
			fout << check_cur->endMinute << " ";
			fout << check_cur->check << endl;
			//move
			count++;
			check_cur = check_cur->next;
		}
		//active
		fout << cur->student.status << endl;
		fout << '\n';
		//move
		cur = cur->next;
	}
}

void readCheckIn(string path, LinkedList studentList) {
	ofstream fout;
	path += ".txt";
	fout.open(path);
	if (!fout.is_open()) {
		cout << "Can't open this file" << endl;
	}
	else {
		saveCheckIn(fout, studentList);
	}
	fout.close();
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

int isCheckIn(LinkedList &studentList, Node user) {

	tm localTime = currentDateTime();

	Node* cur = studentList.head;
	
	while (cur != NULL) {
		CheckIn* check_cur = cur->student.checkIn;
		if (user.student.username == cur->student.username) {
			while (check_cur != NULL) {

				if (check_cur->startYear == localTime.tm_year) {
					if (check_cur->startMonth == localTime.tm_mon) {
						if (check_cur->startDay == localTime.tm_mday) {
							if ((localTime.tm_hour == check_cur->startHour && localTime.tm_min > check_cur->startMinute)
								|| (localTime.tm_hour > check_cur->startHour && localTime.tm_hour < check_cur->endHour)
								|| (localTime.tm_hour == check_cur->endHour && localTime.tm_min < check_cur->endMinute)) {
								check_cur->check = 1;
								return 1;
							}
						}

					}
				}

				check_cur = check_cur->next;
			}
		}
		cur = cur->next;
	}
	
	return 0;
}

void checkIn(Node user) {

	LinkedList studentList;

	for (int i = 0; i < 24; i++) {
		readStudenInClassFile(listOfCourse[i], studentList);
		if (isCheckIn(studentList, user) == 1) {
			cout << "Check!" << endl;
			readCheckIn(listOfCourse[i], studentList);
			return;
		}
	}
	cout << "Too late!" << endl;
}

void viewCheckIn(Node user) {

	LinkedList studentList;

	for (int i = 0; i < 24; i++) {

		readStudenInClassFile(listOfCourse[i], studentList);

		Node* cur = studentList.head;

		while (cur != NULL) {
			if (user.student.username == cur->student.username) {
				CheckIn* check_cur = cur->student.checkIn;
				cout << "class: " << listOfCourse[i] << endl;

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
			}
			cur = cur->next;
		}
	}
	cout << endl;
}

void viewSchedules(Node user) {

	LinkedList studentList;

	for (int i = 0; i < 24; i++) {

		readStudenInClassFile(listOfCourse[i], studentList);

		Node* cur = studentList.head;
		while (cur != NULL) {

			if (user.student.username == cur->student.username) {
				CheckIn* check_cur = cur->student.checkIn;

				cout << "class: " << listOfCourse[i] << endl;
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

			}
			cur = cur->next;
		}
	}
	cout << endl;
}

void viewScore(Node user) {

	LinkedList studentList;

	for (int i = 0; i < 24; i++) {

		readStudenInClassFile(listOfCourse[i], studentList);

		Node* cur = studentList.head;
		while (cur != NULL) {

			if (user.student.username == cur->student.username) {

				cout << "class: " << listOfCourse[i] << endl;
				if (cur->student.midterm == -1)
					cout << "Midterm is empty" << endl;
				else
					cout << "Your Midterm: " << cur->student.midterm << endl;
				if (cur->student.final == -1)
					cout << "Final is empty" << endl;
				else
					cout << "Your Final: " << cur->student.final << endl;
				if (cur->student.bonus == -1)
					cout << "Bonus is empty" << endl;
				else
					cout << "Your Bonus: " << cur->student.bonus << endl;
				if (cur->student.total == -1)
					cout << "Total is empty" << endl;
				else
					cout << "Your Total: " << cur->student.total << endl;

			}
			cur = cur->next;
		}
	}
	cout << endl;
}