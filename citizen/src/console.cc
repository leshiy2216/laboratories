#include <iostream>
#include <functions/functions.h>
#include <conio.h>
#include <list>
#include <vector>
using namespace std;
using namespace peoples;


int main()
{
	HumanList humans;
	int choice = -1;
	int type;
	int index;
	Human human;
	string name;
	string schoolORuniversity;
	int ticket;
	bool family;
	int book;
	double score;
	int id;
	int experience;
	do
	{
		cout << "Menu:" << endl;
		cout << "0. EXIT" << endl;
		cout << "1. input" << endl;
		cout << "2. del" << endl;
		cout << "3. print" << endl;
		int choice;
		cout << "what do7" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Human human;
			cout << "index" << endl;
			cin >> index;
			cout << "choose type:" << endl;
			cout << "1. schooler / 2. student / 3. retire" << endl;
			cin >> type;
			if (type == 1)
			{
				human.set_type(SCHOOLER);
				cout << "name" << endl;
				cin >> name;
				human.set_name(name);
				cout << "school" << endl;
				cin >> schoolORuniversity;
				human.set_educational_institution(schoolORuniversity);
				cout << "ticket" << endl;
				cin >> ticket;
				human.set_ticket(ticket);
				cout << "family" << endl;
				cin >> family;
				human.set_is_large_family(family);
			}
			else if (type == 2)
			{
				human.set_type(STUDENT);
				cout << "name" << endl;
				cin >> name;
				human.set_name(name);
				cout << "unik" << endl;
				cin >> schoolORuniversity;
				human.set_educational_institution(schoolORuniversity);
				cout << "book" << endl;
				cin >> book;
				human.set_book(book);
				cout << "score" << endl;
				cin >> score;
				human.set_score(score);
			}
			else if (type == 3)
			{
				human.set_type(RETIRE);
				cout << "name" << endl;
				cin >> name;
				human.set_name(name);
				cout << "id" << endl;
				cin >> id;
				human.set_retire_id(id);
				cout << "exp" << endl;
				cin >> experience;
				human.set_experience(experience);
			}
			else
			{
				cout << "invalid input " << endl;
				continue;
			}
			humans.add(human, index);
			break;
		}
		case 2:
			cout << "index" << endl;
			cin >> index;
			humans.Del(index);
			break;
		case 3:
			humans.Print();
			break;
		}

	}while(choice != 0);
	return 0;
}