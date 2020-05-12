#include "Header.h"

int main() {
	LinkedList APCS1, APCS2, APCS3, APCS4, APCS5, APCS6, APCS7, APCS8, APCS9, APCS10;
	int choice = 0;

	while (true) {
		cout << "6. Load student from class" << endl;
		cout << "7. Insert student to a class" << endl;
		cout << "8. Edit a student" << endl;
		cout << "9. Remove a student" << endl;
		cout << "10. Change class" << endl;
		cout << "11. View list of classes " << endl;
		cout << "12. View list of students in a class" << endl;
		cout << "0. Exit" << endl;
		cout << endl;

		cout << "Your choice: ";
		cin >> choice;
		cout << endl;

		if (choice == 6) {
			cout << "6. Load student from class" << endl;
			Load_Option(APCS1, APCS2, APCS3, APCS4, APCS5, APCS6, APCS7, APCS8, APCS9, APCS10);
			cout << endl;
		}
		else if (choice == 7) {
			cout << "7. Insert student to a class" << endl;
			Insert_Option(APCS1, APCS2, APCS3, APCS4, APCS5, APCS6, APCS7, APCS8, APCS9, APCS10);
			cout << endl;
		}
		else if (choice == 8) {
			cout << "8. Edit an existing student" << endl;
			Edit_Option(APCS1, APCS2, APCS3, APCS4, APCS5, APCS6, APCS7, APCS8, APCS9, APCS10);
			cout << endl;
		}
		else if (choice == 9) {
			cout << "9. Remove a student" << endl;
			Delete_Option(APCS1, APCS2, APCS3, APCS4, APCS5, APCS6, APCS7, APCS8, APCS9, APCS10);
			cout << endl;
		}
		else if (choice == 10) {
			cout << "10. Change class" << endl;
			Change_Class_Option(APCS1, APCS2, APCS3, APCS4, APCS5, APCS6, APCS7, APCS8, APCS9, APCS10);
			cout << endl;
		}
		else if (choice == 11) {
			cout << "11. View list of class" << endl;
			View_Class_List(APCS1, APCS2, APCS3, APCS4, APCS5, APCS6, APCS7, APCS8, APCS9, APCS10);
			cout << endl;
		}
		else if (choice == 12) {
			cout << "12. View list of students in a class" << endl;
			View_Student_List_Option(APCS1, APCS2, APCS3, APCS4, APCS5, APCS6, APCS7, APCS8, APCS9, APCS10);
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



		//cout << "Enter onputPath: ";
		//cin.getline(base, 100);
		//char outputPath[101];
		//strcpy_s(outputPath, strlen(base) + 1, base);
		//foutput.open(outputPath);
		//if (!foutput.is_open()) {
		//	cout << "Can't open Output file";
		//}
		//else {
		//	SaveStudentFile(foutput, Stu);
		//	foutput.close();
		//}
	
	return 0;
}
