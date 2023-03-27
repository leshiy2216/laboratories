#include <functions/functions.h>
#include <iostream>
#include <string>
#include <stdexcept>
#define MINSIZE 16242
using namespace std;

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

void Human::set_experience(int experrience)
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
	score = 3.5;
}

Human::Human(HumanType type, string name, string educational_institution, int ticket, bool is_large_family) // schooler
{
	this->type = type;
	this->name = name;
	this->educational_institution = educational_institution;
	this->ticket = ticket;
	this->is_large_family = is_large_family;
}

Human::Human(HumanType type, string name, string educational_institution, int book, double score) // student
{
	this->type = type;
	this->name = name;
	this->educational_institution = educational_institution;
	this->book = book;
	this->score = score;
}

Human::Human(HumanType type, string name, int retire_id, int experience)
{
	this->type = type;
	this->name = name;
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

// for 2nd class

HumanList::HumanList() // default
{
	this->size = 7;
	for (int i = 0; i < size; ++i) person[i] = Human();
}

HumanList:HumanList(Human person[], int size) // schooler
{
	this->size = size;
	
	for (int i = 0; i < size; ++i)
	{
		this->persons[i].set_type(person[i].get_type());
		this->persons[i].set_name(person[i].get_name());
		this->persons[i].set_educational_institution(person[i].get_educational_institution());
		this->persons[i].set_ticket(person[i].get_ticket());
		this->persons[i].set_is_large_family(person[i].get_is_large_family());
	}
}

HumanList:HumanList(Human person[], int size, float) // student
{
	this->size = size;

	for (int i = 0; i < size; ++i)
	{
		this->persons[i].set_type(person[i].get_type());
		this->persons[i].set_name(person[i].get_name());
		this->persons[i].set_educational_institution(person[i].get_educational_institution());
		this->persons[i].set_book(person[i].get_book());
		this->persons[i].set_score(person[i].get_score());
	}
}

HumanList:HumanList(Human person[], int size) // retire
{
	this->size = size;

	for (int i = 0; i < size; ++i)
	{
		this->persons[i].set_type(person[i].get_type());
		this->persons[i].set_name(person[i].get_name());
		this->persons[i].set_retire_id(person[i].get_retire_id());
		this->persons[i].set_experience(person[i].get_experience());
	}
}

Human HumanList::get_human_by_index(int i)
{
	return persons[i];
}

int HumanList::get_size()
{
	return size;
}

void HumanList::set_size(int size)
{
	this->size = size;
}

Human& HumanList::operator[int index]
{
	if ((index < 0) or (index >= size))
	{
		throw std::runtime_error("Index out of range.");
	}
	return persons[index];
}

void HumanList::add_human(int index, Human person)
{
	if (size == CAPACITY)
	{
		throw std::runtime_error("The data array is full.");
	}

	if ((index < 0) or (index >= size))
	{
		throw std::runtime_error("Index out of range.");
	}

	for (int i = size - 1; i >= index; --i) { persons[i] = persons[i - 1]; }
	persons[index] = person;
	++size;
}

void HumanList::clear()
{
	size = 0;
}

void HumanList::del_human(int index)
{
	if (size <= 0)
	{
		throw std::runtime_error("List of Citizen is empty.");
	}
	for (int i = index; i < size - 1; ++i)
	{
		persons[i] = persons[i + 1];
	}
	--size;
}