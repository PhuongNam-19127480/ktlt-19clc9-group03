#include "Header.h"


Node* CreateNode(string No, string ID, string Lastname, string Firstname, string Gender, string Day, string Month, string Year) {
	Node* p = new Node;
	p->Info.No = No;
	p->Info.ID = ID;
	p->Info.Lastname = Lastname;
	p->Info.Firstname = Firstname;
	p->Info.Gender = Gender;
	p->Info.Day = Day;
	p->Info.Month = Month;
	p->Info.Year = Year;
	p->Info.DoB = p->Info.Day + " " + p->Info.Month + " " + p->Info.Year;
	string Password = (p->Info.ID).substr(4,7);
	p->Info.Password = Password + p->Info.Day + p->Info.Month;
	p->next = NULL;
	return p;
}

void LoadStudent(ifstream& finput, LinkedList& Stu) {
	char base[101];
	char inputPath[101];
	cout << "Enter inputPath: ";
	cin.ignore();
	cin.getline(base, 100);
	strcpy_s(inputPath, strlen(base) + 1, base);
	finput.open(inputPath);
	if (!finput.is_open()) {
		cout << "Can't open CSV file";
	}
	else {
		Stu.count = 0;
		string No, ID, Lastname, Firstname, Gender, Day, Month, Year, DoB;
		getline(finput, No, ',');
		getline(finput, ID, ',');
		getline(finput, Lastname, ',');
		getline(finput, Firstname, ',');
		getline(finput, Gender, ',');
		getline(finput, DoB);
		Stu.head = NULL;
		Stu.tail = NULL;
		getline(finput, No, ',');
		getline(finput, ID, ',');
		getline(finput, Lastname, ',');
		getline(finput, Firstname, ',');
		getline(finput, Gender, ',');
		getline(finput, Day, '/');
		getline(finput, Month, '/');
		getline(finput, Year);
		Stu.count++;
		Node* p = CreateNode(No, ID, Lastname, Firstname, Gender, Day, Month, Year);
		Stu.head = p;
		Node* current = Stu.head;
		while (finput.eof() == false) {
			getline(finput, No, ',');
			getline(finput, ID, ',');
			getline(finput, Lastname, ',');
			getline(finput, Firstname, ',');
			getline(finput, Gender, ',');
			getline(finput, Day, '/');
			getline(finput, Month, '/');
			getline(finput, Year);
			Node* p = CreateNode(No, ID, Lastname, Firstname, Gender, Day, Month, Year);
			current->next = p;
			current = current->next;
			Stu.count++;
		}
		Stu.tail = current;
		finput.close();
	}

}

void Load_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10) {
	ifstream finput;
	while (true) {
		int choice;
		cout << "You have to load from CSV file in order to do other options !" << endl;
		cout << "Please choose class to load from CSV file" << endl;
		cout << "1. Load 19APCS1" << endl;
		cout << "2. Load 19APCS2" << endl;
		cout << "3. Load 19APCS3" << endl;
		cout << "4. Load 19APCS4" << endl;
		cout << "5. Load 19APCS5" << endl;
		cout << "6. Load 19APCS6" << endl;
		cout << "7. Load 19APCS7" << endl;
		cout << "8. Load 19APCS8" << endl;
		cout << "9. Load 19APCS9" << endl;
		cout << "10. Load 19APCS10" << endl;
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "Loading 19APCS1" << endl;
			LoadStudent(finput, APCS1);
			APCS1.ClassName = "19APCS1";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 2) {
			cout << "Loading 19APCS2" << endl;
			LoadStudent(finput, APCS2);
			APCS2.ClassName = "19APCS2";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 3) {
			cout << "Loading 19APCS3" << endl;
			LoadStudent(finput, APCS3);
			APCS3.ClassName = "19APCS3";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 4) {
			cout << "Loading 19APCS4" << endl;
			LoadStudent(finput, APCS4);
			APCS4.ClassName = "19APCS4";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 5) {
			cout << "Loading 19APCS5" << endl;
			LoadStudent(finput, APCS5);
			APCS5.ClassName = "19APCS5";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 6) {
			cout << "Loading 19APCS6" << endl;
			LoadStudent(finput, APCS6);
			APCS6.ClassName = "19APCS6";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 7) {
			cout << "Loading 19APCS7" << endl;
			LoadStudent(finput, APCS7);
			APCS7.ClassName = "19APCS7";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 8) {
			cout << "Loading 19APCS8" << endl;
			LoadStudent(finput, APCS8);
			APCS8.ClassName = "19APCS8";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 9) {
			cout << "Loading 19APCS9" << endl;
			LoadStudent(finput, APCS9);
			APCS9.ClassName = "19APCS9";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 10) {
			cout << "Loading 19APCS10" << endl;
			LoadStudent(finput, APCS10);
			APCS10.ClassName = "19APCS10";
			cout << "Loading successful" << endl;
			cout << endl;
		}
		else if (choice == 0) {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}

}

void InsertStudent(LinkedList& Stu) {
	string No, ID, Lastname, Firstname, Gender, Day, Month, Year;
	int n;
	cout << "Enter the number of student you want to insert: ";
	cin >> n;
	cin.ignore();
	Node* current = Stu.head;
	while (current->next != Stu.tail) {
		current = current->next;
	}
	for (int i = 0; i < n; i++) {
		ostringstream convert;
		convert << Stu.count;
		No = convert.str();
		cout << "Enter ID: ";
		getline(cin, ID);
		cout << "Enter Lastname: ";
		getline(cin,Lastname);
		cout << "Enter Firstname: ";
		getline(cin, Firstname);
		cout << "Enter Gender (Male/Female): ";
		getline(cin, Gender);
		cout << "Enter Day of Birth: ";
		getline(cin, Day);
		cout << "Enter Month of Birth: ";
		getline(cin, Month);
		cout << "Enter Year of Birth: ";
		getline(cin, Year);
		cout << "Import Successfully";
		Node* p = CreateNode(No, ID, Lastname, Firstname, Gender, Day, Month, Year);
		current->next = p;
		current = current->next;
		Stu.count++;
	}
	current = current->next;
	Stu.tail = current;
}


void EditStudent(LinkedList& Stu) {
	string No, ID, Lastname, Firstname, Gender, Day, Month, Year, DoB;
	string StuID;
	int n;
	int i = 0;
	cout << "Enter the number of students you want to edit: ";
	cin >> n;
	cin.ignore();
	while (i < n) {
		Node* current = Stu.head;
		cout << "Enter ID of a student you want to edit: ";
		getline(cin, StuID);
		while (current != NULL) {
			if (current->Info.ID == StuID) {
				break;
			}
			else {
				current = current->next;
			}
		}

		cout << current->Info.No << endl;
		cout << current->Info.ID << endl;
		cout << current->Info.Lastname << endl;
		cout << current->Info.Firstname << endl;
		cout << current->Info.Gender << endl;
		cout << current->Info.DoB << endl;
		cout << current->Info.Password << endl;
		cout << endl;
		cout << "Edit information: " << endl;
		cout << "Edit ID: ";
		getline(cin, ID);
		current->Info.ID = ID;
		cout << "Edit Lastname: ";
		getline(cin, Lastname);
		current->Info.Lastname = Lastname;
		cout << "Edit Firstname: ";
		getline(cin, Firstname);
		current->Info.Firstname = Firstname;
		cout << "Edit Gender (Male/Female): ";
		getline(cin, Gender);
		current->Info.Gender = Gender;
		cout << "Edit Day of Birth: ";
		getline(cin, Day);
		current->Info.Day = Day;
		cout << "Edit Month of Birth: ";
		getline(cin, Month);
		current->Info.Month = Month;
		cout << "Edit Year of Birth: ";
		getline(cin, Year);
		current->Info.Year = Year;
		current->Info.DoB = current->Info.Day + " " + current->Info.Month + " " + current->Info.Year;
		string Password = (current->Info.ID).substr(4, 7);
		current->Info.Password = Password + current->Info.Day + current->Info.Month;
		cout << "Edit Successfully" << endl;
		i++;
	}

}


void Delete_Student(LinkedList& Class) {
	int n;
	int Count = 0;
	string StuID;
	int i = 0;
	int j = 1;
	cout << "Enter the number of students you want to delete: ";
	cin >> n;
	cin.ignore();
	while (i < n) {
		cout << "Enter ID of a student you want to delete: ";
		getline(cin, StuID);
		if (Class.head->Info.ID == StuID) {
			cout << "Delete student from class" << endl;
			cout << Class.head->Info.No << endl;
			cout << Class.head->Info.ID << endl;
			cout << Class.head->Info.Lastname << endl;
			cout << Class.head->Info.Firstname << endl;
			cout << Class.head->Info.Gender << endl;
			cout << Class.head->Info.DoB << endl;
			cout << Class.head->Info.Password << endl;
			cout << endl;
			cout << "Delete Successfully" << endl;
			Node* p = Class.head;
			Class.head = Class.head->next;
			delete p;
			Class.count--;
		}
		else if (Class.head->Info.ID != StuID) {
			Node* previous = Class.head;
			Node* current = previous->next;
			while (current != Class.tail) {
				if (current->Info.ID == StuID) {
					cout << "Delete student from class" << endl;
					cout << current->Info.No << endl;
					cout << current->Info.ID << endl;
					cout << current->Info.Lastname << endl;
					cout << current->Info.Firstname << endl;
					cout << current->Info.Gender << endl;
					cout << current->Info.DoB << endl;
					cout << current->Info.Password << endl;
					cout << endl;
					Node* p = current;
					previous->next = current->next;
					current = previous->next;
					delete p;
					Class.count--;
					cout << "Delete Successfully" << endl;

				}
				else {
					previous = current;
					current = current->next;
				}
			}
		}
		i++;
	}
	Node* current1 = Class.head;
	while (current1 != Class.tail && Count <= Class.count) {
		current1->Info.No = (j + '0');
		j++;
		current1 = current1->next;
		Count++;
	}
}


void SaveStudentFile(ofstream& foutput, LinkedList Stu) {
	foutput << "No,";
	foutput << "ID,";
	foutput << "Lastname,";
	foutput << "Firstname,";
	foutput << "Gender,";
	foutput << "DoB" << "\n";
	Node* current = Stu.head;
	while (current != NULL) {
		foutput << current->Info.No << "\n";
		foutput << current->Info.ID << "\n";
		foutput << current->Info.Lastname << "\n";
		foutput << current->Info.Firstname << "\n";
		if (current->Info.Gender == "Male") {
			foutput << 0 << '\n';
		}
		else {
			foutput << 1 << '\n';
		}
		foutput << current->Info.Day << "/";
		foutput << current->Info.Month << "/";
		foutput << current->Info.Year << "\n";
		foutput << current->Info.Password << '\n';
		foutput << "\n";
		current = current->next;
	}
}


void OuputStudentList(LinkedList Stu) {
	Node* current = Stu.head;
	int Count = 0;
	while (current != Stu.tail && Count < Stu.count) {
		cout << current->Info.No << endl;
		cout << current->Info.ID << endl;
		cout << current->Info.Lastname << endl;
		cout << current->Info.Firstname << endl;
		cout << current->Info.Gender << endl;
		cout << current->Info.DoB << endl;
		cout << current->Info.Password << endl;
		cout << endl;
		current = current->next;
		Count++;
	}
}

void Insert_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10) {
	while (true) {
		int choice;
		cout << "Please choose a class you want to insert students !" << endl;
		if (APCS1.ClassName.length() != 0) {
			cout << "1. " << APCS1.ClassName << endl;
		}
		if (APCS2.ClassName.length() != 0) {
			cout << "2. " << APCS2.ClassName << endl;
		}
		if (APCS3.ClassName.length() != 0) {
			cout << "3. " << APCS3.ClassName << endl;
		}
		if (APCS4.ClassName.length() != 0) {
			cout << "4. " << APCS4.ClassName << endl;
		}
		if (APCS5.ClassName.length() != 0) {
			cout << "5. " << APCS5.ClassName << endl;
		}
		if (APCS6.ClassName.length() != 0) {
			cout << "6. " << APCS6.ClassName << endl;
		}
		if (APCS7.ClassName.length() != 0) {
			cout << "7. " << APCS7.ClassName << endl;
		}
		if (APCS8.ClassName.length() != 0) {
			cout << "8. " << APCS8.ClassName << endl;
		}
		if (APCS9.ClassName.length() != 0) {
			cout << "9. " << APCS9.ClassName << endl;
		}
		if (APCS10.ClassName.length() != 0) {
			cout << "10. " << APCS10.ClassName << endl;
		}
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "Inserting 19APCS1" << endl;
			InsertStudent(APCS1);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 2) {
			cout << "Inserting 19APCS1" << endl;
			InsertStudent(APCS2);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 3) {
			cout << "Inserting 19APCS3" << endl;
			InsertStudent(APCS3);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 4) {
			cout << "Inserting 19APCS4" << endl;
			InsertStudent(APCS4);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 5) {
			cout << "Inserting 19APCS5" << endl;
			InsertStudent(APCS5);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 6) {
			cout << "Inserting 19APCS6" << endl;
			InsertStudent(APCS6);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 7) {
			cout << "Inserting 19APCS7" << endl;
			InsertStudent(APCS7);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 8) {
			cout << "Inserting 19APCS8" << endl;
			InsertStudent(APCS8);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 9) {
			cout << "Inserting 19APCS9" << endl;
			InsertStudent(APCS9);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 10) {
			cout << "Inserting 19APCS10" << endl;
			InsertStudent(APCS10);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 0) {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}

void Edit_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10) {

	while (true) {
		int choice;
		cout << "Choose a class to edit student" << endl;
		if (APCS1.ClassName.length() != 0) {
			cout << "1. " << APCS1.ClassName << endl;
		}
		if (APCS2.ClassName.length() != 0) {
			cout << "2. " << APCS2.ClassName << endl;
		}
		if (APCS3.ClassName.length() != 0) {
			cout << "3. " << APCS3.ClassName << endl;
		}
		if (APCS4.ClassName.length() != 0) {
			cout << "4. " << APCS4.ClassName << endl;
		}
		if (APCS5.ClassName.length() != 0) {
			cout << "5. " << APCS5.ClassName << endl;
		}
		if (APCS6.ClassName.length() != 0) {
			cout << "6. " << APCS6.ClassName << endl;
		}
		if (APCS7.ClassName.length() != 0) {
			cout << "7. " << APCS7.ClassName << endl;
		}
		if (APCS8.ClassName.length() != 0) {
			cout << "8. " << APCS8.ClassName << endl;
		}
		if (APCS9.ClassName.length() != 0) {
			cout << "9. " << APCS9.ClassName << endl;
		}
		if (APCS10.ClassName.length() != 0) {
			cout << "10. " << APCS10.ClassName << endl;
		}
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "Editing student in 19APCS1" << endl;
			EditStudent(APCS1);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 2) {
			cout << "Editing student in 19APCS2" << endl;
			EditStudent(APCS2);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 3) {
			cout << "Editing student in 19APCS3" << endl;
			EditStudent(APCS3);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 4) {
			cout << "Editing student in 19APCS4" << endl;
			EditStudent(APCS4);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 5) {
			cout << "Editing student in 19APCS5" << endl;
			EditStudent(APCS5);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 6) {
			cout << "Editing student in 19APCS6" << endl;
			EditStudent(APCS6);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 7) {
			cout << "Editing student in 19APCS7" << endl;
			EditStudent(APCS7);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 8) {
			cout << "Editing student in 19APCS8" << endl;
			EditStudent(APCS8);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 9) {
			cout << "Editing student in 19APCS9" << endl;
			EditStudent(APCS9);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 10) {
			cout << "Editing student in 19APCS10" << endl;
			EditStudent(APCS10);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 0) {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}
void View_Student_List_Option(LinkedList APCS1, LinkedList APCS2, LinkedList APCS3, LinkedList APCS4, LinkedList APCS5, LinkedList APCS6, LinkedList APCS7, LinkedList APCS8, LinkedList APCS9, LinkedList APCS10) {
	while (true) {
		int choice;
		cout << "Please choose a class to view !" << endl;
		if (APCS1.ClassName.length() != 0) {
			cout << "1. " << APCS1.ClassName << endl;
		}
		if (APCS2.ClassName.length() != 0) {
			cout << "2. " << APCS2.ClassName << endl;
		}
		if (APCS3.ClassName.length() != 0) {
			cout << "3. " << APCS3.ClassName << endl;
		}
		if (APCS4.ClassName.length() != 0) {
			cout << "4. " << APCS4.ClassName << endl;
		}
		if (APCS5.ClassName.length() != 0) {
			cout << "5. " << APCS5.ClassName << endl;
		}
		if (APCS6.ClassName.length() != 0) {
			cout << "6. " << APCS6.ClassName << endl;
		}
		if (APCS7.ClassName.length() != 0) {
			cout << "7. " << APCS7.ClassName << endl;
		}
		if (APCS8.ClassName.length() != 0) {
			cout << "8. " << APCS8.ClassName << endl;
		}
		if (APCS9.ClassName.length() != 0) {
			cout << "9. " << APCS9.ClassName << endl;
		}
		if (APCS10.ClassName.length() != 0) {
			cout << "10. " << APCS10.ClassName << endl;
		}
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "Viewing 19APCS1" << endl;
			OuputStudentList(APCS1);
			cout << "-----End-----" << endl;
			cout << endl;	
		}
		else if (choice == 2) {
			cout << "Viewing 19APCS1" << endl;
			OuputStudentList(APCS2);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 3) {
			cout << "Viewing 19APCS3" << endl;
			OuputStudentList(APCS3);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 4) {
			cout << "Viewing 19APCS4" << endl;
			OuputStudentList(APCS4);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 5) {
			cout << "Viewing 19APCS5" << endl;
			OuputStudentList(APCS5);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 6) {
			cout << "Viewing 19APCS6" << endl;
			OuputStudentList(APCS6);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 7) {
			cout << "Viewing 19APCS7" << endl;
			OuputStudentList(APCS7);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 8) {
			cout << "Viewing 19APCS8" << endl;
			OuputStudentList(APCS8);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 9) {
			cout << "Viewing 19APCS9" << endl;
			OuputStudentList(APCS9);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 10) {
			cout << "Viewing 19APCS10" << endl;
			OuputStudentList(APCS10);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 0) {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}

void View_Class_List(LinkedList APCS1, LinkedList APCS2, LinkedList APCS3, LinkedList APCS4, LinkedList APCS5, LinkedList APCS6, LinkedList APCS7, LinkedList APCS8, LinkedList APCS9, LinkedList APCS10) {

	cout << "List of classes you have already loaded" << endl;
	if (APCS1.ClassName.length() != 0) {
		cout << "1. " << APCS1.ClassName << endl;
	}
	if (APCS2.ClassName.length() != 0) {
		cout << "2. " << APCS2.ClassName << endl;
	}
	if (APCS3.ClassName.length() != 0) {
		cout << "3. " << APCS3.ClassName << endl;
	}
	if (APCS4.ClassName.length() != 0) {
		cout << "4. " << APCS4.ClassName << endl;
	}
	if (APCS5.ClassName.length() != 0) {
		cout << "5. " << APCS5.ClassName << endl;
	}
	if (APCS6.ClassName.length() != 0) {
		cout << "6. " << APCS6.ClassName << endl;
	}
	if (APCS7.ClassName.length() != 0) {
		cout << "7. " << APCS7.ClassName << endl;
	}
	if (APCS8.ClassName.length() != 0) {
		cout << "8. " << APCS8.ClassName << endl;
	}
	if (APCS9.ClassName.length() != 0) {
		cout << "9. " << APCS9.ClassName << endl;
	}
	if (APCS10.ClassName.length() != 0) {
		cout << "10. " << APCS10.ClassName << endl;
	}
	cout << "-----End-----" << endl;
}

void Delete_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10) {

	while (true) {
		int n;
		int choice;
		cout << "Choose a class to delete student" << endl;
		if (APCS1.ClassName.length() != 0) {
			cout << "1. " << APCS1.ClassName << endl;
		}
		if (APCS2.ClassName.length() != 0) {
			cout << "2. " << APCS2.ClassName << endl;
		}
		if (APCS3.ClassName.length() != 0) {
			cout << "3. " << APCS3.ClassName << endl;
		}
		if (APCS4.ClassName.length() != 0) {
			cout << "4. " << APCS4.ClassName << endl;
		}
		if (APCS5.ClassName.length() != 0) {
			cout << "5. " << APCS5.ClassName << endl;
		}
		if (APCS6.ClassName.length() != 0) {
			cout << "6. " << APCS6.ClassName << endl;
		}
		if (APCS7.ClassName.length() != 0) {
			cout << "7. " << APCS7.ClassName << endl;
		}
		if (APCS8.ClassName.length() != 0) {
			cout << "8. " << APCS8.ClassName << endl;
		}
		if (APCS9.ClassName.length() != 0) {
			cout << "9. " << APCS9.ClassName << endl;
		}
		if (APCS10.ClassName.length() != 0) {
			cout << "10. " << APCS10.ClassName << endl;
		}
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1) {
			cout << "Deleting student in 19APCS1" << endl;
			Delete_Student(APCS1);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 2) {
			cout << "Deleting student in 19APCS2" << endl;
			Delete_Student(APCS2);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 3) {
			cout << "Deleting student in 19APCS3" << endl;
			Delete_Student(APCS3);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 4) {
			cout << "Deleting student in 19APCS4" << endl;
			Delete_Student(APCS4);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 5) {
			cout << "Deleting student in 19APCS5" << endl;
			Delete_Student(APCS5);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 6) {
			cout << "Deleting student in 19APCS6" << endl;
			Delete_Student(APCS6);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 7) {
			cout << "Deleting student in 19APCS7" << endl;
			Delete_Student(APCS7);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 8) {
			cout << "Deleting student in 19APCS8" << endl;
			Delete_Student(APCS8);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 9) {
			cout << "Deleting student in 19APCS9" << endl;
			Delete_Student(APCS9);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 10) {
			cout << "Deleting student in 19APCS10" << endl;
			Delete_Student(APCS10);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == 0) {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}


void Change_Class(LinkedList& OldClass, LinkedList& NewClass) {

	// Delete from old class

	string No, ID, Lastname, Firstname, Gender, Day, Month, Year;
	int Count = 0;
	int n;
	string StuID;
	int i = 0;
	int j = 1;
	cout << "Enter the number of students you want to change class: ";
	cin >> n;
	cin.ignore();
	while (i < n) {
		cout << "Enter ID of a student you want to change class: ";
		getline(cin, StuID);
		while (OldClass.head->Info.ID == StuID) {
			Node* p = OldClass.head;
			OldClass.head = OldClass.head->next;

			// Add to new class

			Node* current3 = NewClass.head;
			while (current3->next != NewClass.tail) {
				current3 = current3->next;
			}
			
			ostringstream convert;
			convert << NewClass.count;
			No = convert.str();
			ID = p->Info.ID;
			Lastname = p->Info.Lastname;
			Firstname = p->Info.Firstname;
			Gender = p->Info.Gender;
			Day = p->Info.Day;
			Month = p->Info.Month;
			Year = p->Info.Year;
			cout << "Change Class Successfully" << endl;
			Node* p1 = CreateNode(No, ID, Lastname, Firstname, Gender, Day, Month, Year);
			current3->next = p1;
			current3 = current3->next;
			NewClass.count++;
			
			current3 = current3->next;
			NewClass.tail = current3;
			delete p;
			OldClass.count--;
		}


		Node* previous = OldClass.head;
		Node* current = previous->next;
		while (current != OldClass.tail) {
			if (current->Info.ID == StuID) {
				Node* p2 = current;
				previous->next = current->next;
				current = previous->next;

				// Add to new class

				Node* current3 = NewClass.head;
				while (current3->next != NewClass.tail) {
					current3 = current3->next;
				}
			
				ostringstream convert;
				convert << NewClass.count;
				No = convert.str();
				ID = p2->Info.ID;
				Lastname = p2->Info.Lastname;
				Firstname = p2->Info.Firstname;
				Gender = p2->Info.Gender;
				Day = p2->Info.Day;
				Month = p2->Info.Month;
				Year = p2->Info.Year;
				cout << "Change Class Successfully" << endl;
				Node* p3 = CreateNode(No, ID, Lastname, Firstname, Gender, Day, Month, Year);
				current3->next = p3;
				current3 = current3->next;
				NewClass.count++;
				
				current3 = current3->next;
				NewClass.tail = current3;
				delete p2;
				OldClass.count--;
				break;
			}
			else {
				previous = current;
				current = current->next;
			}
		}
		i++;
	}
	Node* current1 = OldClass.head;
	while (current1 != OldClass.tail && Count <= OldClass.count + 1) {
		current1->Info.No = j + '0';
		j++;
		current1 = current1->next;
		Count++;
	}
}

void Change_Class_Option(LinkedList& APCS1, LinkedList& APCS2, LinkedList& APCS3, LinkedList& APCS4, LinkedList& APCS5, LinkedList& APCS6, LinkedList& APCS7, LinkedList& APCS8, LinkedList& APCS9, LinkedList& APCS10) {
	while (true) {
		int choice;
		cout << "Choose a class having student need changing class" << endl;
		if (APCS1.ClassName.length() != 0) {
			cout << "1. " << APCS1.ClassName << endl;
		}
		if (APCS2.ClassName.length() != 0) {
			cout << "2. " << APCS2.ClassName << endl;
		}
		if (APCS3.ClassName.length() != 0) {
			cout << "3. " << APCS3.ClassName << endl;
		}
		if (APCS4.ClassName.length() != 0) {
			cout << "4. " << APCS4.ClassName << endl;
		}
		if (APCS5.ClassName.length() != 0) {
			cout << "5. " << APCS5.ClassName << endl;
		}
		if (APCS6.ClassName.length() != 0) {
			cout << "6. " << APCS6.ClassName << endl;
		}
		if (APCS7.ClassName.length() != 0) {
			cout << "7. " << APCS7.ClassName << endl;
		}
		if (APCS8.ClassName.length() != 0) {
			cout << "8. " << APCS8.ClassName << endl;
		}
		if (APCS9.ClassName.length() != 0) {
			cout << "9. " << APCS9.ClassName << endl;
		}
		if (APCS10.ClassName.length() != 0) {
			cout << "10. " << APCS10.ClassName << endl;
		}
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == 1) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS2.ClassName.length() != 0) {
					cout << "2. " << APCS2.ClassName << endl;
				}
				if (APCS3.ClassName.length() != 0) {
					cout << "3. " << APCS3.ClassName << endl;
				}
				if (APCS4.ClassName.length() != 0) {
					cout << "4. " << APCS4.ClassName << endl;
				}
				if (APCS5.ClassName.length() != 0) {
					cout << "5. " << APCS5.ClassName << endl;
				}
				if (APCS6.ClassName.length() != 0) {
					cout << "6. " << APCS6.ClassName << endl;
				}
				if (APCS7.ClassName.length() != 0) {
					cout << "7. " << APCS7.ClassName << endl;
				}
				if (APCS8.ClassName.length() != 0) {
					cout << "8. " << APCS8.ClassName << endl;
				}
				if (APCS9.ClassName.length() != 0) {
					cout << "9. " << APCS9.ClassName << endl;
				}
				if (APCS10.ClassName.length() != 0) {
					cout << "10. " << APCS10.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;

				cout << "Your choice: ";
				cin >> choice;

				if (choice == 2) {
					cout << "Changing from 19APCS1 to 19APCS2" << endl;
					Change_Class(APCS1, APCS2);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 3) {
					cout << "Changing from 19APCS1 to 19APCS3" << endl;
					Change_Class(APCS1, APCS3);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 4) {
					cout << "Changing from 19APCS1 to 19APCS4" << endl;
					Change_Class(APCS1, APCS4);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Changing from 19APCS1 to 19APCS5" << endl;
					Change_Class(APCS1, APCS5);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Changing from 19APCS1 to 19APCS6" << endl;
					Change_Class(APCS1, APCS6);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Changing from 19APCS1 to 19APCS7" << endl;
					Change_Class(APCS1, APCS7);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 8) {
					cout << "Changing from 19APCS1 to 19APCS8" << endl;
					Change_Class(APCS1, APCS8);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 9) {
					cout << "Changing from 19APCS1 to 19APCS9" << endl;
					Change_Class(APCS1, APCS9);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 10) {
					cout << "Changing from 19APCS1 to 19APCS10" << endl;
					Change_Class(APCS1, APCS10);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
			
		}
		else if (choice == 2) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS1.ClassName.length() != 0) {
					cout << "1. " << APCS1.ClassName << endl;
				}
				if (APCS3.ClassName.length() != 0) {
					cout << "3. " << APCS3.ClassName << endl;
				}
				if (APCS4.ClassName.length() != 0) {
					cout << "4. " << APCS4.ClassName << endl;
				}
				if (APCS5.ClassName.length() != 0) {
					cout << "5. " << APCS5.ClassName << endl;
				}
				if (APCS6.ClassName.length() != 0) {
					cout << "6. " << APCS6.ClassName << endl;
				}
				if (APCS7.ClassName.length() != 0) {
					cout << "7. " << APCS7.ClassName << endl;
				}
				if (APCS8.ClassName.length() != 0) {
					cout << "8. " << APCS8.ClassName << endl;
				}
				if (APCS9.ClassName.length() != 0) {
					cout << "9. " << APCS9.ClassName << endl;
				}
				if (APCS10.ClassName.length() != 0) {
					cout << "10. " << APCS10.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;

				cout << "Your choice: ";
				cin >> choice;

				if (choice == 1) {
					cout << "Changing from 19APCS2 to 19APCS1" << endl;
					Change_Class(APCS2, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 3) {
					cout << "Changing from 19APCS2 to 19APCS3" << endl;
					Change_Class(APCS2, APCS3);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 4) {
					cout << "Changing from 19APCS2 to 19APCS4" << endl;
					Change_Class(APCS2, APCS4);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Changing from 19APCS2 to 19APCS5" << endl;
					Change_Class(APCS2, APCS5);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Changing from 19APCS2 to 19APCS6" << endl;
					Change_Class(APCS2, APCS6);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Changing from 19APCS2 to 19APCS7" << endl;
					Change_Class(APCS2, APCS7);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 8) {
					cout << "Changing from 19APCS2 to 19APCS8" << endl;
					Change_Class(APCS2, APCS8);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 9) {
					cout << "Changing from 19APCS2 to 19APCS9" << endl;
					Change_Class(APCS2, APCS9);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 10) {
					cout << "Changing from 19APCS2 to 19APCS10" << endl;
					Change_Class(APCS2, APCS10);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
		}
		else if (choice == 3) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS1.ClassName.length() != 0) {
					cout << "1. " << APCS1.ClassName << endl;
				}
				if (APCS2.ClassName.length() != 0) {
					cout << "2. " << APCS2.ClassName << endl;
				}
				if (APCS4.ClassName.length() != 0) {
					cout << "4. " << APCS4.ClassName << endl;
				}
				if (APCS5.ClassName.length() != 0) {
					cout << "5. " << APCS5.ClassName << endl;
				}
				if (APCS6.ClassName.length() != 0) {
					cout << "6. " << APCS6.ClassName << endl;
				}
				if (APCS7.ClassName.length() != 0) {
					cout << "7. " << APCS7.ClassName << endl;
				}
				if (APCS8.ClassName.length() != 0) {
					cout << "8. " << APCS8.ClassName << endl;
				}
				if (APCS9.ClassName.length() != 0) {
					cout << "9. " << APCS9.ClassName << endl;
				}
				if (APCS10.ClassName.length() != 0) {
					cout << "10. " << APCS10.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;

				cout << "Your choice: ";
				cin >> choice;

				if (choice == 1) {
					cout << "Changing from 19APCS3 to 19APCS1" << endl;
					Change_Class(APCS3, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 2) {
					cout << "Changing from 19APCS3 to 19APCS1" << endl;
					Change_Class(APCS3, APCS2);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 4) {
					cout << "Changing from 19APCS3 to 19APCS4" << endl;
					Change_Class(APCS3, APCS4);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Changing from 19APCS3 to 19APCS5" << endl;
					Change_Class(APCS3, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Changing from 19APCS3 to 19APCS6" << endl;
					Change_Class(APCS3, APCS6);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Changing from 19APCS3 to 19APCS7" << endl;
					Change_Class(APCS3, APCS7);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 8) {
					cout << "Changing from 19APCS3 to 19APCS8" << endl;
					Change_Class(APCS3, APCS8);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 9) {
					cout << "Changing from 19APCS3 to 19APCS9" << endl;
					Change_Class(APCS3, APCS9);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 10) {
					cout << "Changing from 19APCS2 to 19APCS10" << endl;
					Change_Class(APCS2, APCS10);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
		}
		else if (choice == 4) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS1.ClassName.length() != 0) {
					cout << "1. " << APCS1.ClassName << endl;
				}
				if (APCS2.ClassName.length() != 0) {
					cout << "2. " << APCS2.ClassName << endl;
				}
				if (APCS3.ClassName.length() != 0) {
					cout << "3. " << APCS3.ClassName << endl;
				}
				if (APCS5.ClassName.length() != 0) {
					cout << "5. " << APCS5.ClassName << endl;
				}
				if (APCS6.ClassName.length() != 0) {
					cout << "6. " << APCS6.ClassName << endl;
				}
				if (APCS7.ClassName.length() != 0) {
					cout << "7. " << APCS7.ClassName << endl;
				}
				if (APCS8.ClassName.length() != 0) {
					cout << "8. " << APCS8.ClassName << endl;
				}
				if (APCS9.ClassName.length() != 0) {
					cout << "9. " << APCS9.ClassName << endl;
				}
				if (APCS10.ClassName.length() != 0) {
					cout << "10. " << APCS10.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;

				cout << "Your choice: ";
				cin >> choice;

				if (choice == 1) {
					cout << "Changing from 19APCS4 to 19APCS1" << endl;
					Change_Class(APCS4, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 2) {
					cout << "Changing from 19APCS4 to 19APCS2" << endl;
					Change_Class(APCS4, APCS2);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 3) {
					cout << "Changing from 19APCS4 to 19APCS3" << endl;
					Change_Class(APCS4, APCS3);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Changing from 19APCS4 to 19APCS5" << endl;
					Change_Class(APCS4, APCS5);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Changing from 19APCS4 to 19APCS6" << endl;
					Change_Class(APCS4, APCS6);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Changing from 19APCS4 to 19APCS7" << endl;
					Change_Class(APCS4, APCS7);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 8) {
					cout << "Changing from 19APCS4 to 19APCS8" << endl;
					Change_Class(APCS4, APCS8);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 9) {
					cout << "Changing from 19APCS4 to 19APCS9" << endl;
					Change_Class(APCS4, APCS9);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 10) {
					cout << "Changing from 19APCS4 to 19APCS10" << endl;
					Change_Class(APCS4, APCS10);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
		}
		else if (choice == 5) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS1.ClassName.length() != 0) {
					cout << "1. " << APCS1.ClassName << endl;
				}
				if (APCS2.ClassName.length() != 0) {
					cout << "2. " << APCS2.ClassName << endl;
				}
				if (APCS3.ClassName.length() != 0) {
					cout << "3. " << APCS3.ClassName << endl;
				}
				if (APCS4.ClassName.length() != 0) {
					cout << "4. " << APCS4.ClassName << endl;
				}
				if (APCS6.ClassName.length() != 0) {
					cout << "6. " << APCS6.ClassName << endl;
				}
				if (APCS7.ClassName.length() != 0) {
					cout << "7. " << APCS7.ClassName << endl;
				}
				if (APCS8.ClassName.length() != 0) {
					cout << "8. " << APCS8.ClassName << endl;
				}
				if (APCS9.ClassName.length() != 0) {
					cout << "9. " << APCS9.ClassName << endl;
				}
				if (APCS10.ClassName.length() != 0) {
					cout << "10. " << APCS10.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;
	
				cout << "Your choice: ";
				cin >> choice;
	
				if (choice == 1) {
					cout << "Changing from 19APCS5 to 19APCS1" << endl;
					Change_Class(APCS5, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 2) {
					cout << "Changing from 19APCS5 to 19APCS2" << endl;
					Change_Class(APCS5, APCS2);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 3) {
					cout << "Changing from 19APCS5 to 19APCS3" << endl;
					Change_Class(APCS5, APCS3);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 4) {
					cout << "Changing from 19APCS5 to 19APCS4" << endl;
					Change_Class(APCS5, APCS4);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Student has already been in 19APCS5" << endl;
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Changing from 19APCS5 to 19APCS6" << endl;
					Change_Class(APCS5, APCS6);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Changing from 19APCS5 to 19APCS7" << endl;
					Change_Class(APCS5, APCS7);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 8) {
					cout << "Changing from 19APCS5 to 19APCS8" << endl;
					Change_Class(APCS5, APCS8);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 9) {
					cout << "Changing from 19APCS5 to 19APCS9" << endl;
					Change_Class(APCS5, APCS9);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 10) {
					cout << "Changing from 19APCS5 to 19APCS10" << endl;
					Change_Class(APCS5, APCS10);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
		}
		else if (choice == 6) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS1.ClassName.length() != 0) {
					cout << "1. " << APCS1.ClassName << endl;
				}
				if (APCS2.ClassName.length() != 0) {
					cout << "2. " << APCS2.ClassName << endl;
				}
				if (APCS3.ClassName.length() != 0) {
					cout << "3. " << APCS3.ClassName << endl;
				}
				if (APCS4.ClassName.length() != 0) {
					cout << "4. " << APCS4.ClassName << endl;
				}
				if (APCS5.ClassName.length() != 0) {
					cout << "5. " << APCS5.ClassName << endl;
				}
				if (APCS7.ClassName.length() != 0) {
					cout << "7. " << APCS7.ClassName << endl;
				}
				if (APCS8.ClassName.length() != 0) {
					cout << "8. " << APCS8.ClassName << endl;
				}
				if (APCS9.ClassName.length() != 0) {
					cout << "9. " << APCS9.ClassName << endl;
				}
				if (APCS10.ClassName.length() != 0) {
					cout << "10. " << APCS10.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;

				cout << "Your choice: ";
				cin >> choice;

				if (choice == 1) {
					cout << "Changing from 19APCS6 to 19APCS1" << endl;
					Change_Class(APCS6, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 2) {
					cout << "Changing from 19APCS6 to 19APCS2" << endl;
					Change_Class(APCS6, APCS2);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 3) {
					cout << "Changing from 19APCS6 to 19APCS3" << endl;
					Change_Class(APCS6, APCS3);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 4) {
					cout << "Changing from 19APCS6 to 19APCS4" << endl;
					Change_Class(APCS6, APCS4);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Changing from 19APCS6 to 19APCS5" << endl;
					Change_Class(APCS6, APCS5);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Student has already been in 19APCS6" << endl;
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Changing from 19APCS6 to 19APCS7" << endl;
					Change_Class(APCS6, APCS7);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 8) {
					cout << "Changing from 19APCS6 to 19APCS8" << endl;
					Change_Class(APCS6, APCS8);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 9) {
					cout << "Changing from 19APCS6 to 19APCS9" << endl;
					Change_Class(APCS6, APCS9);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 10) {
					cout << "Changing from 19APCS6 to 19APCS10" << endl;
					Change_Class(APCS6, APCS10);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
		}
		else if (choice == 7) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS1.ClassName.length() != 0) {
					cout << "1. " << APCS1.ClassName << endl;
				}
				if (APCS2.ClassName.length() != 0) {
					cout << "2. " << APCS2.ClassName << endl;
				}
				if (APCS3.ClassName.length() != 0) {
					cout << "3. " << APCS3.ClassName << endl;
				}
				if (APCS4.ClassName.length() != 0) {
					cout << "4. " << APCS4.ClassName << endl;
				}
				if (APCS5.ClassName.length() != 0) {
					cout << "5. " << APCS5.ClassName << endl;
				}
				if (APCS6.ClassName.length() != 0) {
					cout << "6. " << APCS6.ClassName << endl;
				}
				if (APCS8.ClassName.length() != 0) {
					cout << "8. " << APCS8.ClassName << endl;
				}
				if (APCS9.ClassName.length() != 0) {
					cout << "9. " << APCS9.ClassName << endl;
				}
				if (APCS10.ClassName.length() != 0) {
					cout << "10. " << APCS10.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;

				cout << "Your choice: ";
				cin >> choice;

				if (choice == 1) {
					cout << "Changing from 19APCS7 to 19APCS1" << endl;
					Change_Class(APCS7, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 2) {
					cout << "Changing from 19APCS7 to 19APCS2" << endl;
					Change_Class(APCS7, APCS2);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 3) {
					cout << "Changing from 19APCS7 to 19APCS3" << endl;
					Change_Class(APCS7, APCS3);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 4) {
					cout << "Changing from 19APCS7 to 19APCS4" << endl;
					Change_Class(APCS7, APCS4);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Changing from 19APCS7 to 19APCS5" << endl;
					Change_Class(APCS7, APCS5);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Changing from 19APCS7 to 19APCS6" << endl;
					Change_Class(APCS7, APCS6);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Student has already been in 19APCS7" << endl;
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 8) {
					cout << "Changing from 19APCS7 to 19APCS8" << endl;
					Change_Class(APCS7, APCS8);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 9) {
					cout << "Changing from 19APCS7 to 19APCS9" << endl;
					Change_Class(APCS7, APCS9);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 10) {
					cout << "Changing from 19APCS7 to 19APCS10" << endl;
					Change_Class(APCS7, APCS10);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
		}
		else if (choice == 8) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS1.ClassName.length() != 0) {
					cout << "1. " << APCS1.ClassName << endl;
				}
				if (APCS2.ClassName.length() != 0) {
					cout << "2. " << APCS2.ClassName << endl;
				}
				if (APCS3.ClassName.length() != 0) {
					cout << "3. " << APCS3.ClassName << endl;
				}
				if (APCS4.ClassName.length() != 0) {
					cout << "4. " << APCS4.ClassName << endl;
				}
				if (APCS5.ClassName.length() != 0) {
					cout << "5. " << APCS5.ClassName << endl;
				}
				if (APCS6.ClassName.length() != 0) {
					cout << "6. " << APCS6.ClassName << endl;
				}
				if (APCS7.ClassName.length() != 0) {
					cout << "7. " << APCS7.ClassName << endl;
				}
				if (APCS9.ClassName.length() != 0) {
					cout << "9. " << APCS9.ClassName << endl;
				}
				if (APCS10.ClassName.length() != 0) {
					cout << "10. " << APCS10.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;

				cout << "Your choice: ";
				cin >> choice;

				if (choice == 1) {
					cout << "Changing from 19APCS8 to 19APCS1" << endl;
					Change_Class(APCS8, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 2) {
					cout << "Changing from 19APCS8 to 19APCS2" << endl;
					Change_Class(APCS8, APCS2);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 3) {
					cout << "Changing from 19APCS8 to 19APCS3" << endl;
					Change_Class(APCS8, APCS3);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 4) {
					cout << "Changing from 19APCS8 to 19APCS4" << endl;
					Change_Class(APCS8, APCS4);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Changing from 19APCS8 to 19APCS5" << endl;
					Change_Class(APCS8, APCS5);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Changing from 19APCS8 to 19APCS6" << endl;
					Change_Class(APCS8, APCS6);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Changing from 19APCS8 to 19APCS7" << endl;
					Change_Class(APCS8, APCS7);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 9) {
					cout << "Changing from 19APCS8 to 19APCS9" << endl;
					Change_Class(APCS8, APCS9);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 10) {
					cout << "Changing from 19APCS8 to 19APCS10" << endl;
					Change_Class(APCS8, APCS10);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
		}
		else if (choice == 9) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS1.ClassName.length() != 0) {
					cout << "1. " << APCS1.ClassName << endl;
				}
				if (APCS2.ClassName.length() != 0) {
					cout << "2. " << APCS2.ClassName << endl;
				}
				if (APCS3.ClassName.length() != 0) {
					cout << "3. " << APCS3.ClassName << endl;
				}
				if (APCS4.ClassName.length() != 0) {
					cout << "4. " << APCS4.ClassName << endl;
				}
				if (APCS5.ClassName.length() != 0) {
					cout << "5. " << APCS5.ClassName << endl;
				}
				if (APCS6.ClassName.length() != 0) {
					cout << "6. " << APCS6.ClassName << endl;
				}
				if (APCS7.ClassName.length() != 0) {
					cout << "7. " << APCS7.ClassName << endl;
				}
				if (APCS8.ClassName.length() != 0) {
					cout << "8. " << APCS8.ClassName << endl;
				}
				if (APCS10.ClassName.length() != 0) {
					cout << "10. " << APCS10.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;

				cout << "Your choice: ";
				cin >> choice;

				if (choice == 1) {
					cout << "Changing from 19APCS9 to 19APCS1" << endl;
					Change_Class(APCS9, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 2) {
					cout << "Changing from 19APCS9 to 19APCS2" << endl;
					Change_Class(APCS9, APCS2);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 3) {
					cout << "Changing from 19APCS9 to 19APCS3" << endl;
					Change_Class(APCS9, APCS3);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 4) {
					cout << "Changing from 19APCS9 to 19APCS4" << endl;
					Change_Class(APCS9, APCS4);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Changing from 19APCS9 to 19APCS5" << endl;
					Change_Class(APCS9, APCS5);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Changing from 19APCS9 to 19APCS6" << endl;
					Change_Class(APCS9, APCS6);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Changing from 19APCS9 to 19APCS7" << endl;
					Change_Class(APCS9, APCS7);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 8) {
					cout << "Changing from 19APCS9 to 19APCS8" << endl;
					Change_Class(APCS9, APCS8);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 10) {
					cout << "Changing from 19APCS9 to 19APCS10" << endl;
					Change_Class(APCS9, APCS10);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
		}
		else if (choice == 10) {
			while (true) {
				int choice;
				cout << "Choose a class student moving to" << endl;
				if (APCS1.ClassName.length() != 0) {
					cout << "1. " << APCS1.ClassName << endl;
				}
				if (APCS2.ClassName.length() != 0) {
					cout << "2. " << APCS2.ClassName << endl;
				}
				if (APCS3.ClassName.length() != 0) {
					cout << "3. " << APCS3.ClassName << endl;
				}
				if (APCS4.ClassName.length() != 0) {
					cout << "4. " << APCS4.ClassName << endl;
				}
				if (APCS5.ClassName.length() != 0) {
					cout << "5. " << APCS5.ClassName << endl;
				}
				if (APCS6.ClassName.length() != 0) {
					cout << "6. " << APCS6.ClassName << endl;
				}
				if (APCS7.ClassName.length() != 0) {
					cout << "7. " << APCS7.ClassName << endl;
				}
				if (APCS8.ClassName.length() != 0) {
					cout << "8. " << APCS8.ClassName << endl;
				}
				if (APCS9.ClassName.length() != 0) {
					cout << "9. " << APCS9.ClassName << endl;
				}
				cout << "0. Exiting" << endl;
				cout << "-----@-----" << endl;

				cout << "Your choice: ";
				cin >> choice;

				if (choice == 1) {
					cout << "Changing from 19APCS10 to 19APCS1" << endl;
					Change_Class(APCS10, APCS1);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 2) {
					cout << "Changing from 19APCS10 to 19APCS2" << endl;
					Change_Class(APCS10, APCS2);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 3) {
					cout << "Changing from 19APCS10 to 19APCS3" << endl;
					Change_Class(APCS10, APCS3);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 4) {
					cout << "Changing from 19APCS10 to 19APCS4" << endl;
					Change_Class(APCS10, APCS4);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 5) {
					cout << "Changing from 19APCS10 to 19APCS5" << endl;
					Change_Class(APCS10, APCS5);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 6) {
					cout << "Changing from 19APCS10 to 19APCS6" << endl;
					Change_Class(APCS10, APCS6);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 7) {
					cout << "Changing from 19APCS10 to 19APCS7" << endl;
					Change_Class(APCS10, APCS7);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 8) {
					cout << "Changing from 19APCS10 to 19APCS8" << endl;
					Change_Class(APCS10, APCS8);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 9) {
					cout << "Changing from 19APCS10 to 19APCS9" << endl;
					Change_Class(APCS10, APCS9);
					cout << "-----End-----" << endl;
					cout << endl;
				}
				else if (choice == 0) {
					cout << "Exiting" << endl;
					break;
				}
				else {
					cout << "Incorrect" << endl;
				}
			}
		}
		else if (choice == 0) {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}

