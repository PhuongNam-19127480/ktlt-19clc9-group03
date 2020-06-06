#include "header.h"

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

