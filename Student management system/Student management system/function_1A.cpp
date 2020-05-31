#include "header.h"


Node* CreateNodeCSV(string No, string ID, string Lastname, string Firstname, string Gender, string Day, string Month, string Year) {
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

void menuStaff(Node user) {
	LinkedList CLC1, CLC2, CLC3, CLC4, CLC5, CLC6, CLC7, CLC8, CLC9, CLC10, APCS1, APCS2;
	string choice;

	while (true) {
		cout << "-----Staff menu-----" << endl;
		cout << "1. Load student from class" << endl;
		cout << "2. Insert student to a class" << endl;
		cout << "3. Edit a student" << endl;
		cout << "4. Remove a student" << endl;
		cout << "5. Change class" << endl;
		cout << "6. View list of classes " << endl;
		cout << "7. View list of students in a class" << endl;
		cout << "8. Semester function" << endl;
		cout << "0. Comeback" << endl;
		cout << endl;

		cout << "choice: ";
		cin >> choice;

		if (choice == "1") {
			cout << "1. Load student from class" << endl;
			Load_Option(CLC1, CLC2, CLC3, CLC4, CLC5, CLC6, CLC7, CLC8, CLC9, CLC10, APCS1, APCS2);
			cout << endl;
		}
		else if (choice == "2") {
			cout << "2. Insert student to a class" << endl;
			Insert_Option(CLC1, CLC2, CLC3, CLC4, CLC5, CLC6, CLC7, CLC8, CLC9, CLC10, APCS1, APCS2);
			cout << endl;
		}
		else if (choice == "3") {
			cout << "3. Edit an existing student" << endl;
			Edit_Option(CLC1, CLC2, CLC3, CLC4, CLC5, CLC6, CLC7, CLC8, CLC9, CLC10, APCS1, APCS2);
			cout << endl;
		}
		else if (choice == "4") {
			cout << "4. Remove a student" << endl;
			Delete_Option(CLC1, CLC2, CLC3, CLC4, CLC5, CLC6, CLC7, CLC8, CLC9, CLC10, APCS1, APCS2);
			cout << endl;
		}
		else if (choice == "5") {
			cout << "5. Change class" << endl;
			Change_Class_Option(CLC1, CLC2, CLC3, CLC4, CLC5, CLC6, CLC7, CLC8, CLC9, CLC10, APCS1, APCS2);
			cout << endl;
		}
		else if (choice == "6") {
			cout << "6. View list of class" << endl;
			View_Class_List(CLC1, CLC2, CLC3, CLC4, CLC5, CLC6, CLC7, CLC8, CLC9, CLC10, APCS1, APCS2);
			cout << endl;
		}
		else if (choice == "7") {
			cout << "7. View list of students in a class" << endl;
			View_Student_List_Option(CLC1, CLC2, CLC3, CLC4, CLC5, CLC6, CLC7, CLC8, CLC9, CLC10, APCS1, APCS2);
			cout << endl;
		}
		else if (choice == "8") {
			main_semester();
		}
		else if (choice == "0") {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}

void LoadStudent(ifstream& finput, LinkedList& Stu) {
	Stu.head = NULL;
	Stu.tail = NULL;
	char base[101];
	char inputPath[101];
	cout << "Enter inputPath: ";
	cin.ignore();
	cin.getline(base, 100);
	strcpy_s(inputPath, strlen(base) + 1, base);
	finput.open(inputPath);
	if (!finput.is_open()) {
		cout << "Can't open CSV file" << endl;
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
		getline(finput, No, ',');
		getline(finput, ID, ',');
		getline(finput, Lastname, ',');
		getline(finput, Firstname, ',');
		getline(finput, Gender, ',');
		getline(finput, Day, '/');
		getline(finput, Month, '/');
		getline(finput, Year);
		Stu.count++;
		Node* p = CreateNodeCSV(No, ID, Lastname, Firstname, Gender, Day, Month, Year);
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
			Node* p = CreateNodeCSV(No, ID, Lastname, Firstname, Gender, Day, Month, Year);
			current->next = p;
			current = current->next;
			Stu.count++;
		}
		Stu.tail = current;
		finput.close();
	}

}

void Load_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2) {
	ifstream finput;
	while (true) {
		string choice;
		cout << "You have to load from CSV file in order to do other options !" << endl;
		cout << "Please choose class to load from CSV file" << endl;
		cout << "1. Load 19CLC1" << endl;
		cout << "2. Load 19CLC2" << endl;
		cout << "3. Load 19CLC3" << endl;
		cout << "4. Load 19CLC4" << endl;
		cout << "5. Load 19CLC5" << endl;
		cout << "6. Load 19CLC6" << endl;
		cout << "7. Load 19CLC7" << endl;
		cout << "8. Load 19CLC8" << endl;
		cout << "9. Load 19CLC9" << endl;
		cout << "10. Load 19CLC10" << endl;
		cout << "11. Load 19APCS1" << endl;
		cout << "12. Load 19APCS2" << endl;
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == "1") {
			cout << "Loading 19CLC1" << endl;
			LoadStudent(finput, CLC1);
			CLC1.ClassName = "19CLC1";
			SaveStudentFile(CLC1);
			if (CLC1.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "2") {
			cout << "Loading 19CLC2" << endl;
			LoadStudent(finput, CLC2);
			CLC2.ClassName = "19CLC2";
			SaveStudentFile(CLC2);
			if (CLC2.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "3") {
			cout << "Loading 19CLC3" << endl;
			LoadStudent(finput, CLC3);
			CLC3.ClassName = "19CLC3";
			SaveStudentFile(CLC3);
			if (CLC3.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "4") {
			cout << "Loading 19CLC4" << endl;
			LoadStudent(finput, CLC4);
			CLC4.ClassName = "19CLC4";
			SaveStudentFile(CLC4);
			if (CLC4.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "5") {
			cout << "Loading 19CLC5" << endl;
			LoadStudent(finput, CLC5);
			CLC5.ClassName = "19CLC5";
			SaveStudentFile(CLC5);
			if (CLC5.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "6") {
			cout << "Loading 19CLC6" << endl;
			LoadStudent(finput, CLC6);
			CLC6.ClassName = "19CLC6";
			SaveStudentFile(CLC6);
			if (CLC6.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "7") {
			cout << "Loading 19CLC7" << endl;
			LoadStudent(finput, CLC7);
			CLC7.ClassName = "19CLC7";
			SaveStudentFile(CLC7);
			if (CLC7.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "8") {
			cout << "Loading 19CLC8" << endl;
			LoadStudent(finput, CLC8);
			CLC8.ClassName = "19CLC8";
			SaveStudentFile(CLC8);
			if (CLC8.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "9") {
			cout << "Loading 19CLC9" << endl;
			LoadStudent(finput, CLC9);
			CLC9.ClassName = "19CLC9";
			SaveStudentFile(CLC9);
			if (CLC9.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "10") {
			cout << "Loading 19CLC10" << endl;
			LoadStudent(finput, CLC10);
			CLC10.ClassName = "19CLC10";
			SaveStudentFile(CLC10);
			if (CLC10.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "11") {
			cout << "Loading 19APCS1" << endl;
			LoadStudent(finput, APCS1);
			APCS1.ClassName = "19APCS1";
			SaveStudentFile(APCS1);
			if (APCS1.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "12") {
			cout << "Loading 19APCS2" << endl;
			LoadStudent(finput, APCS2);
			APCS2.ClassName = "19APCS2";
			SaveStudentFile(APCS2);
			if (APCS2.head != NULL) {
				cout << "Loading successful" << endl;
			}
			else {
				cout << "Loading unsuccessful" << endl;
			}
			cout << endl;
		}
		else if (choice == "0") {
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
		cout << "Import Successfully" << endl;
		Node* p = CreateNodeCSV(No, ID, Lastname, Firstname, Gender, Day, Month, Year);
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


void SaveStudentFile(LinkedList Stu) {
	ofstream foutput;
	string inputPath;
	inputPath = "";
	inputPath.append(Stu.ClassName);
	inputPath.append("-Student.txt");

	foutput.open(inputPath);
	if (!foutput.is_open()) {
		cout << "Can't open output file";
	}
	else {
		Node* current = Stu.head;
		while (current != NULL) {
			if (current == NULL) {
				break;
			}
			else {
				foutput << current->Info.ID << "\n";
				foutput << current->Info.Password << '\n';
				foutput << current->Info.Lastname << " ";
				foutput << current->Info.Firstname << "\n";
				foutput << current->Info.Day << " ";
				foutput << current->Info.Month << " ";
				foutput << current->Info.Year << "\n";
				foutput << Stu.ClassName << "\n";
				if (current->Info.Gender == "Male") {
					foutput << 0 << '\n';
				}
				else {
					foutput << 1 << '\n';
				}
				foutput << "\n";
				current = current->next;
			}	
		}
		foutput.close();
	}
}


void OuputStudentList(LinkedList Stu) {
	Node* current = Stu.head;
	int Count = 0;
	if (current == NULL) {
		cout << "You haven't loaded this class" << endl;
	}
	else {
		while (current != Stu.tail && Count < Stu.count) {
			cout << current->Info.No << endl;
			cout << current->Info.ID << endl;
			cout << current->Info.Lastname << " " << current->Info.Firstname << endl;
			cout << current->Info.Gender << endl;
			cout << current->Info.DoB << endl;
			cout << current->Info.Password << endl;
			cout << endl;
			current = current->next;
			Count++;
		}
	}	
}

void Insert_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2) {
	while (true) {
		string choice;
		cout << "Please choose a class you want to insert students !" << endl;
		if (CLC1.ClassName.length() != 0) {
			cout << "1. " << CLC1.ClassName << endl;
		}
		if (CLC2.ClassName.length() != 0) {
			cout << "2. " << CLC2.ClassName << endl;
		}
		if (CLC3.ClassName.length() != 0) {
			cout << "3. " << CLC3.ClassName << endl;
		}
		if (CLC4.ClassName.length() != 0) {
			cout << "4. " << CLC4.ClassName << endl;
		}
		if (CLC5.ClassName.length() != 0) {
			cout << "5. " << CLC5.ClassName << endl;
		}
		if (CLC6.ClassName.length() != 0) {
			cout << "6. " << CLC6.ClassName << endl;
		}
		if (CLC7.ClassName.length() != 0) {
			cout << "7. " << CLC7.ClassName << endl;
		}
		if (CLC8.ClassName.length() != 0) {
			cout << "8. " << CLC8.ClassName << endl;
		}
		if (CLC9.ClassName.length() != 0) {
			cout << "9. " << CLC9.ClassName << endl;
		}
		if (CLC10.ClassName.length() != 0) {
			cout << "10. " << CLC10.ClassName << endl;
		}
		if (APCS1.ClassName.length() != 0) {
			cout << "11. " << APCS1.ClassName << endl;
		}
		if (APCS2.ClassName.length() != 0) {
			cout << "12. " << APCS2.ClassName << endl;
		}
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == "1") {
			if (CLC1.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC1" << endl;
				InsertStudent(CLC1);
				SaveStudentFile(CLC1);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "2") {
			if (CLC2.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC2" << endl;
				InsertStudent(CLC2);
				SaveStudentFile(CLC2);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "3") {
			if (CLC3.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC3" << endl;
				InsertStudent(CLC3);
				SaveStudentFile(CLC3);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "4") {
			if (CLC4.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC4" << endl;
				InsertStudent(CLC4);
				SaveStudentFile(CLC4);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "5") {
			if (CLC5.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC5" << endl;
				InsertStudent(CLC5);
				SaveStudentFile(CLC5);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "6") {
			if (CLC6.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC6" << endl;
				InsertStudent(CLC6);
				SaveStudentFile(CLC6);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "7") {
			if (CLC7.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC7" << endl;
				InsertStudent(CLC7);
				SaveStudentFile(CLC7);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "8") {
			if (CLC8.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC8" << endl;
				InsertStudent(CLC8);
				SaveStudentFile(CLC8);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "9") {
			if (CLC9.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC9" << endl;
				InsertStudent(CLC9);
				SaveStudentFile(CLC9);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "10") {
			if (CLC10.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19CLC10" << endl;
				InsertStudent(CLC10);
				SaveStudentFile(CLC10);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "11") {
			if (APCS1.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19APCS1" << endl;
				InsertStudent(APCS1);
				SaveStudentFile(APCS1);
				cout << "-----End-----" << endl;
				cout << endl;
			}
			
		}
		else if (choice == "12") {
			if (APCS2.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Inserting 19APCS2" << endl;
				InsertStudent(APCS2);
				SaveStudentFile(APCS2);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "0") {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}

void Edit_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2) {

	while (true) {
		string choice;
		cout << "Choose a class to edit student" << endl;
		if (CLC1.ClassName.length() != 0) {
			cout << "1. " << CLC1.ClassName << endl;
		}
		if (CLC2.ClassName.length() != 0) {
			cout << "2. " << CLC2.ClassName << endl;
		}
		if (CLC3.ClassName.length() != 0) {
			cout << "3. " << CLC3.ClassName << endl;
		}
		if (CLC4.ClassName.length() != 0) {
			cout << "4. " << CLC4.ClassName << endl;
		}
		if (CLC5.ClassName.length() != 0) {
			cout << "5. " << CLC5.ClassName << endl;
		}
		if (CLC6.ClassName.length() != 0) {
			cout << "6. " << CLC6.ClassName << endl;
		}
		if (CLC7.ClassName.length() != 0) {
			cout << "7. " << CLC7.ClassName << endl;
		}
		if (CLC8.ClassName.length() != 0) {
			cout << "8. " << CLC8.ClassName << endl;
		}
		if (CLC9.ClassName.length() != 0) {
			cout << "9. " << CLC9.ClassName << endl;
		}
		if (CLC10.ClassName.length() != 0) {
			cout << "10. " << CLC10.ClassName << endl;
		}
		if (APCS1.ClassName.length() != 0) {
			cout << "11. " << APCS1.ClassName << endl;
		}
		if (APCS2.ClassName.length() != 0) {
			cout << "12. " << APCS2.ClassName << endl;
		}
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == "1") {
			if (CLC1.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC1" << endl;
				EditStudent(CLC1);
				SaveStudentFile(CLC1);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "2") {
			if (CLC2.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC2" << endl;
				EditStudent(CLC2);
				SaveStudentFile(CLC2);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "3") {
			if (CLC3.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC3" << endl;
				EditStudent(CLC3);
				SaveStudentFile(CLC3);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "4") {
			if (CLC4.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC4" << endl;
				EditStudent(CLC4);
				SaveStudentFile(CLC4);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "5") {
			if (CLC5.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC5" << endl;
				EditStudent(CLC5);
				SaveStudentFile(CLC5);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "6") {
			if (CLC6.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC6" << endl;
				EditStudent(CLC6);
				SaveStudentFile(CLC6);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "7") {
			if (CLC7.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC7" << endl;
				EditStudent(CLC7);
				SaveStudentFile(CLC7);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "8") {
			if (CLC8.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC8" << endl;
				EditStudent(CLC8);
				SaveStudentFile(CLC8);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "9") {
			if (CLC9.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC9" << endl;
				EditStudent(CLC9);
				SaveStudentFile(CLC9);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "10") {
			if (CLC10.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19CLC10" << endl;
				EditStudent(CLC10);
				SaveStudentFile(CLC10);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "11") {
			if (APCS1.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19APCS1" << endl;
				EditStudent(APCS1);
				SaveStudentFile(APCS1);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "12") {
			if (APCS2.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Editing student in 19APCS2" << endl;
				EditStudent(APCS2);
				SaveStudentFile(APCS2);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "0") {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}
void View_Student_List_Option(LinkedList CLC1, LinkedList CLC2, LinkedList CLC3, LinkedList CLC4, LinkedList CLC5, LinkedList CLC6, LinkedList CLC7, LinkedList CLC8, LinkedList CLC9, LinkedList CLC10, LinkedList APCS1, LinkedList APCS2) {
	while (true) {
		string choice;
		cout << "Please choose a class to view !" << endl;
		if (CLC1.ClassName.length() != 0) {
			cout << "1. " << CLC1.ClassName << endl;
		}
		if (CLC2.ClassName.length() != 0) {
			cout << "2. " << CLC2.ClassName << endl;
		}
		if (CLC3.ClassName.length() != 0) {
			cout << "3. " << CLC3.ClassName << endl;
		}
		if (CLC4.ClassName.length() != 0) {
			cout << "4. " << CLC4.ClassName << endl;
		}
		if (CLC5.ClassName.length() != 0) {
			cout << "5. " << CLC5.ClassName << endl;
		}
		if (CLC6.ClassName.length() != 0) {
			cout << "6. " << CLC6.ClassName << endl;
		}
		if (CLC7.ClassName.length() != 0) {
			cout << "7. " << CLC7.ClassName << endl;
		}
		if (CLC8.ClassName.length() != 0) {
			cout << "8. " << CLC8.ClassName << endl;
		}
		if (CLC9.ClassName.length() != 0) {
			cout << "9. " << CLC9.ClassName << endl;
		}
		if (CLC10.ClassName.length() != 0) {
			cout << "10. " << CLC10.ClassName << endl;
		}
		if (APCS1.ClassName.length() != 0) {
			cout << "11. " << APCS1.ClassName << endl;
		}
		if (APCS2.ClassName.length() != 0) {
			cout << "12. " << APCS2.ClassName << endl;
		}
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == "1") {
			cout << "Viewing 19CLC1" << endl;
			OuputStudentList(CLC1);
			cout << "-----End-----" << endl;
			cout << endl;	
		}
		else if (choice == "2") {
			cout << "Viewing 19CLC1" << endl;
			OuputStudentList(CLC2);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "3") {
			cout << "Viewing 19CLC3" << endl;
			OuputStudentList(CLC3);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "4") {
			cout << "Viewing 19CLC4" << endl;
			OuputStudentList(CLC4);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "5") {
			cout << "Viewing 19CLC5" << endl;
			OuputStudentList(CLC5);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "6") {
			cout << "Viewing 19CLC6" << endl;
			OuputStudentList(CLC6);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "7") {
			cout << "Viewing 19CLC7" << endl;
			OuputStudentList(CLC7);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "8") {
			cout << "Viewing 19CLC8" << endl;
			OuputStudentList(CLC8);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "9") {
			cout << "Viewing 19CLC9" << endl;
			OuputStudentList(CLC9);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "10") {
			cout << "Viewing 19CLC10" << endl;
			OuputStudentList(CLC10);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "11") {
			cout << "Viewing 19APCS1" << endl;
			OuputStudentList(APCS1);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "12") {
			cout << "Viewing 19APCS2" << endl;
			OuputStudentList(APCS2);
			cout << "-----End-----" << endl;
			cout << endl;
		}
		else if (choice == "0") {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}

void View_Class_List(LinkedList CLC1, LinkedList CLC2, LinkedList CLC3, LinkedList CLC4, LinkedList CLC5, LinkedList CLC6, LinkedList CLC7, LinkedList CLC8, LinkedList CLC9, LinkedList CLC10, LinkedList APCS1, LinkedList APCS2) {

	cout << "List of classes you have already loaded" << endl;
	if (CLC1.ClassName.length() != 0) {
		cout << "1. " << CLC1.ClassName << endl;
	}
	if (CLC2.ClassName.length() != 0) {
		cout << "2. " << CLC2.ClassName << endl;
	}
	if (CLC3.ClassName.length() != 0) {
		cout << "3. " << CLC3.ClassName << endl;
	}
	if (CLC4.ClassName.length() != 0) {
		cout << "4. " << CLC4.ClassName << endl;
	}
	if (CLC5.ClassName.length() != 0) {
		cout << "5. " << CLC5.ClassName << endl;
	}
	if (CLC6.ClassName.length() != 0) {
		cout << "6. " << CLC6.ClassName << endl;
	}
	if (CLC7.ClassName.length() != 0) {
		cout << "7. " << CLC7.ClassName << endl;
	}
	if (CLC8.ClassName.length() != 0) {
		cout << "8. " << CLC8.ClassName << endl;
	}
	if (CLC9.ClassName.length() != 0) {
		cout << "9. " << CLC9.ClassName << endl;
	}
	if (CLC10.ClassName.length() != 0) {
		cout << "10. " << CLC10.ClassName << endl;
	}
	if (APCS1.ClassName.length() != 0) {
		cout << "11. " << APCS1.ClassName << endl;
	}
	if (APCS2.ClassName.length() != 0) {
		cout << "12. " << APCS2.ClassName << endl;
	}
	cout << "-----End-----" << endl;
}

void Delete_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2) {

	while (true) {
		int n;
		string choice;
		cout << "Choose a class to delete student" << endl;
		if (CLC1.ClassName.length() != 0) {
			cout << "1. " << CLC1.ClassName << endl;
		}
		if (CLC2.ClassName.length() != 0) {
			cout << "2. " << CLC2.ClassName << endl;
		}
		if (CLC3.ClassName.length() != 0) {
			cout << "3. " << CLC3.ClassName << endl;
		}
		if (CLC4.ClassName.length() != 0) {
			cout << "4. " << CLC4.ClassName << endl;
		}
		if (CLC5.ClassName.length() != 0) {
			cout << "5. " << CLC5.ClassName << endl;
		}
		if (CLC6.ClassName.length() != 0) {
			cout << "6. " << CLC6.ClassName << endl;
		}
		if (CLC7.ClassName.length() != 0) {
			cout << "7. " << CLC7.ClassName << endl;
		}
		if (CLC8.ClassName.length() != 0) {
			cout << "8. " << CLC8.ClassName << endl;
		}
		if (CLC9.ClassName.length() != 0) {
			cout << "9. " << CLC9.ClassName << endl;
		}
		if (CLC10.ClassName.length() != 0) {
			cout << "10. " << CLC10.ClassName << endl;
		}
		if (APCS1.ClassName.length() != 0) {
			cout << "11. " << APCS1.ClassName << endl;
		}
		if (APCS2.ClassName.length() != 0) {
			cout << "12. " << APCS2.ClassName << endl;
		}
		cout << "0. Exiting" << endl;
		cout << "-----@-----" << endl;

		cout << "Your choice: ";
		cin >> choice;

		if (choice == "1") {
			if (CLC1.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC1" << endl;
				Delete_Student(CLC1);
				SaveStudentFile(CLC1);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "2") {
			if (CLC2.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC2" << endl;
				Delete_Student(CLC2);
				SaveStudentFile(CLC2);
				cout << "-----End-----" << endl;
				cout << endl;
			}		
		}
		else if (choice == "3") {
			if (CLC3.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC3" << endl;
				Delete_Student(CLC3);
				SaveStudentFile(CLC3);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "4") {
			if (CLC4.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC4" << endl;
				Delete_Student(CLC4);
				SaveStudentFile(CLC4);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "5") {
			if (CLC5.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC5" << endl;
				Delete_Student(CLC5);
				SaveStudentFile(CLC5);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "6") {
			if (CLC6.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC6" << endl;
				Delete_Student(CLC6);
				SaveStudentFile(CLC6);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "7") {
			if (CLC7.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC7" << endl;
				Delete_Student(CLC7);
				SaveStudentFile(CLC7);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "8") {
			if (CLC8.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC8" << endl;
				Delete_Student(CLC8);
				SaveStudentFile(CLC8);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "9") {
			if (CLC9.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC9" << endl;
				Delete_Student(CLC9);
				SaveStudentFile(CLC9);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}	
		else if (choice == "10") {
			if (CLC10.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19CLC10" << endl;
				Delete_Student(CLC10);
				SaveStudentFile(CLC10);
				cout << "-----End-----" << endl;
				cout << endl;
			}
		}
		else if (choice == "11") {
			if (APCS1.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19APCS1" << endl;
				Delete_Student(APCS1);
				SaveStudentFile(APCS1);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "12") {
			if (APCS2.ClassName.length() == 0) {
				cout << "You haven't loaded this class" << endl;
			}
			else {
				cout << "Deleting student in 19APCS2" << endl;
				Delete_Student(APCS2);
				SaveStudentFile(APCS2);
				cout << "-----End-----" << endl;
				cout << endl;
			}	
		}
		else if (choice == "0") {
			cout << "Exiting" << endl;
			break;
		}
		else {
			cout << "Incorrect" << endl;
		}
	}
}

void Delete_Student_From_Class(LinkedList& Class, LinkedList& TempList) {
	TempList.head = NULL;
	int n;
	int Count = 0;
	string StuID;
	int j = 1;
	int i = 0;
	cout << "Enter the number of students you want to change class: ";
	cin >> n;
	cin.ignore();
	while (i < n) {
		cout << "Enter ID of a student wants to change class: ";
		getline(cin, StuID);
		if (Class.head->Info.ID == StuID) {
			Node* temp = CreateNodeCSV(Class.head->Info.No, Class.head->Info.ID, Class.head->Info.Lastname, Class.head->Info.Firstname, Class.head->Info.Gender, Class.head->Info.Day, Class.head->Info.Month, Class.head->Info.Year);
			temp->next = TempList.head;
			TempList.head = temp;
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
					Node* temp = CreateNodeCSV(current->Info.No, current->Info.ID, current->Info.Lastname, current->Info.Firstname, current->Info.Gender, current->Info.Day, current->Info.Month, current->Info.Year);
					temp->next = TempList.head;
					TempList.head = temp;
					Node* p = current;
					previous->next = current->next;
					current = previous->next;
					delete p;
					Class.count--;
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

void Add_Student_To_Class(LinkedList& Stu, LinkedList TempList) {
	int n;
	int Count = 0;
	int j = 1;

	Node* current = Stu.head;
	while (current != Stu.tail) {
		current = current->next;
	}

	Node* current1 = TempList.head;
	while (current1 != NULL) {
		current->next = current1;
		current = current->next;
		current1 = current1->next;
		Stu.count++;
	}
	current = current->next;
	Stu.tail = current;

	Node* current2 = Stu.head;
	while (current2 != Stu.tail && Count <= Stu.count) {
		current2->Info.No = (j + '0');
		j++;
		current2 = current2->next;
		Count++;
	}
}



void Change_Class_Option(LinkedList& CLC1, LinkedList& CLC2, LinkedList& CLC3, LinkedList& CLC4, LinkedList& CLC5, LinkedList& CLC6, LinkedList& CLC7, LinkedList& CLC8, LinkedList& CLC9, LinkedList& CLC10, LinkedList& APCS1, LinkedList& APCS2) {
	int Accept = 0;
	string OldClass, NewClass;
	LinkedList TempList;

	cout << "Class you can change: " << endl;
	if (CLC1.ClassName.length() != 0) {
		cout << "1. " << CLC1.ClassName << endl;
	}
	if (CLC2.ClassName.length() != 0) {
		cout << "2. " << CLC2.ClassName << endl;
	}
	if (CLC3.ClassName.length() != 0) {
		cout << "3. " << CLC3.ClassName << endl;
	}
	if (CLC4.ClassName.length() != 0) {
		cout << "4. " << CLC4.ClassName << endl;
	}
	if (CLC5.ClassName.length() != 0) {
		cout << "5. " << CLC5.ClassName << endl;
	}
	if (CLC6.ClassName.length() != 0) {
		cout << "6. " << CLC6.ClassName << endl;
	}
	if (CLC7.ClassName.length() != 0) {
		cout << "7. " << CLC7.ClassName << endl;
	}
	if (CLC8.ClassName.length() != 0) {
		cout << "8. " << CLC8.ClassName << endl;
	}
	if (CLC9.ClassName.length() != 0) {
		cout << "9. " << CLC9.ClassName << endl;
	}
	if (CLC10.ClassName.length() != 0) {
		cout << "10. " << CLC10.ClassName << endl;
	}
	if (APCS1.ClassName.length() != 0) {
		cout << "11. " << APCS1.ClassName << endl;
	}
	if (APCS2.ClassName.length() != 0) {
		cout << "12. " << APCS2.ClassName << endl;
	}
	cout << "-----@-----" << endl;
	if (CLC1.ClassName.length() == 0 && CLC2.ClassName.length() == 0 && CLC3.ClassName.length() == 0 && CLC4.ClassName.length() == 0 && CLC5.ClassName.length() == 0 && CLC6.ClassName.length() == 0 && CLC7.ClassName.length() == 0 && CLC8.ClassName.length() == 0 && CLC9.ClassName.length() == 0 && CLC10.ClassName.length() == 0 && APCS1.ClassName.length() == 0 && APCS2.ClassName.length() == 0) {
		cout << "No class you can change" << endl;
	}
	else {
		cout << "Class has student to change class: ";
		getline(cin, OldClass);
		getline(cin, OldClass);
		cout << "Class student move to: ";
		getline(cin, NewClass);

		if (OldClass == NewClass) {
			cout << "Students have already in this class" << endl;
		}
		else {
			if (OldClass == CLC1.ClassName && CLC1.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC1, TempList);
				SaveStudentFile(CLC1);
			}
			else if (OldClass == CLC2.ClassName && CLC2.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC2, TempList);
				SaveStudentFile(CLC2);
			}
			else if (OldClass == CLC3.ClassName && CLC3.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC3, TempList);
				SaveStudentFile(CLC3);
			}
			else if (OldClass == CLC4.ClassName && CLC4.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC4, TempList);
				SaveStudentFile(CLC4);
			}
			else if (OldClass == CLC5.ClassName && CLC5.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC5, TempList);
				SaveStudentFile(CLC5);
			}
			else if (OldClass == CLC6.ClassName && CLC6.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC6, TempList);
				SaveStudentFile(CLC6);
			}
			else if (OldClass == CLC7.ClassName && CLC7.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC7, TempList);
				SaveStudentFile(CLC7);
			}
			else if (OldClass == CLC8.ClassName && CLC8.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC8, TempList);
				SaveStudentFile(CLC8);
			}
			else if (OldClass == CLC9.ClassName && CLC9.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC9, TempList);
				SaveStudentFile(CLC9);
			}
			else if (OldClass == CLC10.ClassName && CLC10.ClassName.length() != 0) {
				Delete_Student_From_Class(CLC10, TempList);
				SaveStudentFile(CLC10);
			}
			else if (OldClass == APCS1.ClassName && APCS1.ClassName.length() != 0) {
				Delete_Student_From_Class(APCS1, TempList);
				SaveStudentFile(APCS1);
			}
			else if (OldClass == APCS2.ClassName && APCS2.ClassName.length() != 0) {
				Delete_Student_From_Class(APCS2, TempList);
				SaveStudentFile(APCS2);
			}
			else {
				cout << "No class including student you want to move !" << endl;
				Accept = 1;
			}


			if (NewClass == CLC1.ClassName && CLC1.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC1, TempList);
				SaveStudentFile(CLC1);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == CLC2.ClassName && CLC2.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC2, TempList);
				SaveStudentFile(CLC2);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == CLC3.ClassName && CLC3.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC3, TempList);
				SaveStudentFile(CLC3);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == CLC4.ClassName && CLC4.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC4, TempList);
				SaveStudentFile(CLC4);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == CLC5.ClassName && CLC5.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC5, TempList);
				SaveStudentFile(CLC5);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == CLC6.ClassName && CLC6.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC6, TempList);
				SaveStudentFile(CLC6);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == CLC7.ClassName && CLC7.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC7, TempList);
				SaveStudentFile(CLC7);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == CLC8.ClassName && CLC8.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC8, TempList);
				SaveStudentFile(CLC8);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == CLC9.ClassName && CLC9.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC9, TempList);
				SaveStudentFile(CLC9);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == CLC10.ClassName && CLC10.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(CLC10, TempList);
				SaveStudentFile(CLC10);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == APCS1.ClassName && APCS1.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(APCS1, TempList);
				SaveStudentFile(APCS1);
				cout << "Change class successful" << endl;
			}
			else if (NewClass == APCS2.ClassName && APCS2.ClassName.length() != 0 && Accept == 0) {
				Add_Student_To_Class(APCS2, TempList);
				SaveStudentFile(APCS2);
				cout << "Change class successful" << endl;
			}
			else {
				cout << "Change class unsuccessful" << endl;
				cout << "Please loading classes before changing" << endl;
			}
		}
	}
}

