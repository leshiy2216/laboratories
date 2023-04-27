#include <functions/functions.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <istream>
#include <ostream>
#include <math.h>
#define MINSIZE 16242
#define SIZE 4
using namespace std;
using namespace peoples;

// set & get:

void Human::set_type(HumanType type)
{
	this->type = type;
}

void Human::set_name(string name)
{
	this->name = name;
}

void Human::set_educational_institution(string educational_institution)
{
	this->educational_institution = educational_institution;
}

void Human::set_ticket(int ticket)
{
	this->ticket = ticket;
}

void Human::set_is_large_family(bool is_large_family)
{
	this->is_large_family = is_large_family;
}

void Human::set_book(int book)
{
	this->book = book;
}

void Human::set_score(double score)
{
	this->score = score;
}

void Human::set_retire_id(int retire_id)
{
	this->retire_id = retire_id;
}

void Human::set_experience(int experience)
{
	this->experience = experience;
}

//-------------------------------------------------------

HumanType Human::get_type()
{
	return type;
}

string Human::get_name()
{
	return name;
}

string Human::get_educational_institution()
{
	return educational_institution;
}

int Human::get_ticket()
{
	return ticket;
}

bool Human::get_is_large_family()
{
	return is_large_family;
}

int Human::get_book()
{
	return book;
}

double Human::get_score()
{
	return score;
}

int Human::get_retire_id()
{
	return retire_id;
}

int Human::get_experience()
{
	return experience;
}

// constructors:

Human::Human()
{
	type = STUDENT;
	name = "Sergey";
	educational_institution = "1488 VUZ";
	book = 232;
	score = 4.9;
}

Human::Human(HumanType type, string name, string educational_institution, int ticket, int book, bool is_large_family, double score, int retire_id, int experience) // something class
{
	this->type = type;
	this->name = name;
	this->educational_institution = educational_institution;
	this->ticket = ticket;
	this->book = book;
	this->is_large_family = is_large_family;
	this->score = score;
	this->retire_id = retire_id;
	this->experience = experience;
}

// calculations:

double Human::payday_for_schooler()
{
	if (is_large_family) return 0.5 * MINSIZE;
	else return 0;
}

double Human::payday_for_student()
{
	if (score < 3.5) return 0;
	if (score >= 3.5 and score < 4) return 0.5 * MINSIZE;
	if (score >= 4 and score < 4.5) return 0.6 * MINSIZE;
	if (score >= 4.5 and score < 5) return 0.7 * MINSIZE;
	if (score == 5) return 0.8 * MINSIZE;
}

double Human::payday_for_retire()
{
	if (experience < 5) return 0;
	if (experience > 30) return 5 * MINSIZE;
	if (experience == 5) return MINSIZE;
	if (experience > 5 and experience <= 10) return 2 * MINSIZE;
	if (experience > 10 and experience <= 20) return 3 * MINSIZE;
	if (experience > 20 and experience <= 30) return 4 * MINSIZE;
}

double Human::payday_for_all(HumanType type)
{
	switch (type)
	{
	case SCHOOLER:
		if (is_large_family) return 0.5 * MINSIZE;
		if (is_large_family = 0) return 0;
		break;
	case STUDENT:
		if (score < 3.5) return 0;
		if (score >= 3.5 and score < 4) return 0.5 * MINSIZE;
		if (score >= 4 and score < 4.5) return 0.6 * MINSIZE;
		if (score >= 4.5 and score < 5) return 0.7 * MINSIZE;
		if (score == 5) return 0.8 * MINSIZE;
		break;
	case RETIRE:
		if (experience < 5) return 0;
		if (experience > 30) return 5 * MINSIZE;
		if (experience == 5) return MINSIZE;
		if (experience > 5 and experience <= 10) return 2 * MINSIZE;
		if (experience > 10 and experience <= 20) return 3 * MINSIZE;
		if (experience > 20 and experience <= 30) return 4 * MINSIZE;
		break;
	}
}

// operators::

// 2nd class

HumanList::HumanList()
{
	capacity = 10; // default size - 10 elements
	size = 0; // now we not have elements
	humans = new Human * [capacity]; // allocating memory for an array of pointers
}

HumanList::~HumanList()
{
	// delete all elements of array
	for (int i = 0; i < size; i++)
	{
		delete humans[i];
	}
	// delete array
	delete[] humans;
}

void HumanList::insert(Human* human)
{
	if (size >= capacity)
	{
		// doubling the capacity of the array
		capacity *= 2;
		Human** new_humans = new Human * [capacity];
		// copy elements from old array in new array
		for (int i = 0; i < size; i++)
		{
			new_humans[i] = humans[i];
		}
		// delete old array
		delete[] humans;
		// assign a new array of pointers to humans
		humans = new_humans;
	}
	// add element to end of array
	humans[size] = human;
	size++;
}

void HumanList::remove(int index)
{
	if (index >= 0 && index < size)
	{
		// delete elemet with appropriate index
		delete humans[index];
		// shift all elements after the removed one position to the left
		for (int i = 0; i < size - 1; i++)
		{
			humans[i] = humans[i + 1];
		}
		// decrease the number of elements in the array
		size--;
	}
}

void Human::print_info()
{
	cout << "Type: ";
	switch (type)
	{
	case SCHOOLER:
		cout << "Schooler\n";
		cout << "Name: " << name << "\n";
		cout << "Educational institution: " << educational_institution << "\n";
		cout << "Ticket: " << ticket << "\n";
		cout << "Is large family: " << is_large_family << "\n";
		break;

	case STUDENT:
		cout << "Student\n";
		cout << "Name: " << name << "\n";
		cout << "Educational institution: " << educational_institution << "\n";
		cout << "Book: " << book << "\n";
		cout << "Score: " << score << "\n";
		break;

	case RETIRE:
		cout << "Retire\n";
		cout << "Name: " << name << "\n";
		cout << "Retire ID: " << retire_id << "\n";
		cout << "Experience: " << experience << "\n";
		break;
	default:
		cout << "Invalid type\n";
		break;
	}
}

void HumanList::print_list(int size)
{
	if (size == 0)
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Human " << i + 1 << ":" << endl;
			humans[i]->print_info();
		}
	}
}

double HumanList::search_max_payday(Human** list, int size)
{
	double max_payday = 0;
	for (int i = 0; i < size; i++)
	{
		switch (list[i]->get_type())
		{
		case SCHOOLER:
			if (list[i]->payday_for_schooler() > max_payday) max_payday = list[i]->payday_for_schooler();
			break;

		case STUDENT:
			if(list[i]->payday_for_student() > max_payday) max_payday = list[i]->payday_for_student();
			break;

		case RETIRE:
			if(list[i]->payday_for_retire() > max_payday) max_payday = list[i]->payday_for_retire();
			break;
		}
	}
	return max_payday;
}