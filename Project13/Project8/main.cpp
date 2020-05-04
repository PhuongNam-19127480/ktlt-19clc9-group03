#include"function.h"
int main()
{
	int choice = 0;
	Semester s;
	LinkedList lst;
	ofstream fout;
	ifstream fin;
	while (true)
	{
		cout << "1 create Semester" << endl;
		cout << "2 update Semester" << endl;
		cout << "3 delete Semester" << endl;
		cout << "4 view Semester" << endl;
		cout << "0 exit" << endl;
		cout << "pls choose your choice:" << endl;
		cin >> choice;
		cout << endl;
		cout << endl;
		if (choice == 1)
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
				cout << "can not create file";
			}
			else
			{
				create_file(lst, s, fout);
				fout.close();
			}
			
			cout << endl;
		}
		else if (choice == 4)
		{
			fin.open("Semester.txt");
			if (!fin.is_open())
			{
				cout << "can not open file";
			}
			else
			{
				input_Semester(lst, fin);
				view_Semester(lst);
				fin.close();
			}
			
			
		}
		else if (choice == 0)
		{
			break;
		}
		else if (choice == 3)
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
					delete_Semester(lst);
					fout.open("Semester.txt", ios::out);
					if (!fout.is_open())
					{
						cout << "can not open file" << endl;
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
		else if (choice == 2)
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
							cout << "can not open file" << endl;
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
	}
	return 0;
}