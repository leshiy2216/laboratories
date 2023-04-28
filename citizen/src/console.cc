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
	double max;
	do
	{
		std::cout << endl;
		std::cout << "Menu:" << endl;
		std::cout << "0. EXIT" << endl;
		std::cout << "1. Add element into array" << endl;
		std::cout << "2. Delete element from array" << endl;
		std::cout << "3. Print list" << endl;
		std::cout << "4. Search max payday" << endl;
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			Human human;
			std::cout << "Enter index" << endl;
			std::cin >> index;
			system("cls");
			std::cout << "Choose type: " << endl;
			std::cout << "(Press 1 for schooler, 2 - for student, 3 - for retire)" << endl;
			std::cin >> type;
			system("cls");
			if (type == 1)
			{
				human.set_type(SCHOOLER);
				std::cout << "Enter name: " << endl;
				std::cin >> name;
				human.set_name(name);
				system("cls");
				std::cout << "Enter school: " << endl;
				std::cin >> schoolORuniversity;
				human.set_educational_institution(schoolORuniversity);
				system("cls");
				std::cout << "Enter ticket: " << endl;
				std::cin >> ticket;
				human.set_ticket(ticket);
				system("cls");
				std::cout << "From large family?" << endl;
				std::cout << "(0 - No, 1 - Yes)" << endl;
				std::cin >> family;
				human.set_is_large_family(family);
			}
			else if (type == 2)
			{
				human.set_type(STUDENT);
				std::cout << "Enter name: " << endl;
				std::cin >> name;
				human.set_name(name);
				system("cls");
				std::cout << "Enter university: " << endl;
				std::cin >> schoolORuniversity;
				human.set_educational_institution(schoolORuniversity);
				system("cls");
				std::cout << "Enter book: " << endl;
				std::cin >> book;
				human.set_book(book);
				system("cls");
				std::cout << "Enter score: " << endl;
				std::cin >> score;
				human.set_score(score);
			}
			else if (type == 3)
			{
				human.set_type(RETIRE);
				std::cout << "Enter name: " << endl;
				std::cin >> name;
				human.set_name(name);
				system("cls");
				std::cout << "Enter id: " << endl;
				std::cin >> id;
				human.set_retire_id(id);
				system("cls");
				std::cout << "Enter experience: " << endl;
				std::cin >> experience;
				human.set_experience(experience);
			}
			else
			{
				std::cout << "Invalid input" << endl;
				continue;
			}
			humans.add(human, index);
			break;
		}
		case 2:
			system("cls");
			std::cout << "Enter index: " << endl;
			std::cin >> index;
			humans.Del(index);
			break;
		case 3:
			system("cls");
			humans.Print();
			break;
		case 4:
			system("cls");
			max = humans.max_payday();
			cout << "Max payday is: " << max;
		}

	}while(choice != 0);
	return 0;
}