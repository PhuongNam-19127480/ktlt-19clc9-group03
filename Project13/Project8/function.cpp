#include"function.h"
Node* createNote(Semester &s)
{
	Node* p = new Node;
	strcpy_s(p->data.academic, 20, s.academic);
	strcpy_s(p->data.Semesters, 11, s.Semesters);
	p->data.n = s.n;
	p->next = NULL;
	return p;
}

void create_file(LinkedList& lst,Semester s,ofstream&fout)
{

	int temp = 0;
	lst.head = NULL;
	Node* current = lst.head;
	Node* P = createNote(s);
	lst.head = P;
	lst.head->next = current;
	fout << lst.head->data.n << endl;
	fout << lst.head->data.academic << endl;
	fout << lst.head->data.Semesters << endl;
	fout << temp;
	

}

void input_Semester(LinkedList& lst,ifstream &fin)
{
	int x;
	Semester s;
	fin >> s.n;
	fin >> s.academic;
	fin >> s.Semesters;
	lst.head = NULL;
	Node* current = lst.head;
	Node* p = createNote(s);
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
			 s.n=x;
			fin >> s.academic;
			fin >> s.Semesters;
			p = createNote(s);
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

void update_Semester(LinkedList& lst,Semester &s)
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

		 Node* p = createNote(s);
		 current->next = p;
	 }
	 else
	 {
		 s.n = current->data.n;
		 s.n++;
		 Node* p = createNote(s);
		 current->next = p;
	 }


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
	if (current == lst.head || n==1)
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
}


