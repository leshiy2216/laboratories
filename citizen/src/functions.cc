#include <functions/functions.h>
#include <iostream>
#include <string>
#include <stdexcept>
#define MINSIZE 16242
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

Human::Human(HumanType type, string name, string educational_institution, int ticket, int book, bool is_large_family, double score, int retire_id, int experience) // schooler
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
/*
Human::Human(HumanType type, string name, string educational_institution, int book, double score) // student
{
	this->type = type;
	this->name = name;
	this->educational_institution = educational_institution;
	this->book = book;
	this->score = score;
}

Human::Human(HumanType type, string name, int retire_id, int experience) // retire
{
	this->type = type;
	this->name = name;
	this->retire_id = retire_id;
	this->experience = experience;
}*/

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

HumanList::HumanList() // standard
{
	this->_size = 9;
	for (int i = 0; i < 9; i++) this->_person[i] = Human();
}

HumanList::HumanList(Human _person[], int _size) // schooler
{
	this->_size = _size;
	
	for (int i = 0; i <= _size; i++)
	{
		this->_person[i].set_type(_person[i].get_type());
		this->_person[i].set_name(_person[i].get_name());
		this->_person[i].set_educational_institution(_person[i].get_educational_institution());
		this->_person[i].set_ticket(_person[i].get_ticket());
		this->_person[i].set_is_large_family(_person[i].get_is_large_family());
	}
}

HumanList::HumanList(Human _person[], int _size, float) // student
{
	this->_size = _size;

	for (int i = 0; i <= _size; i++)
	{
		this->_person[i].set_type(_person[i].get_type());
		this->_person[i].set_name(_person[i].get_name());
		this->_person[i].set_educational_institution(_person[i].get_educational_institution());
		this->_person[i].set_book(_person[i].get_book());
		this->_person[i].set_score(_person[i].get_score());
	}
}

HumanList::HumanList(Human _person[], int _size, double) // retire
{
	this->_size = _size;

	for (int i = 0; i <+ _size; i++)
	{
		this->_person[i].set_type(_person[i].get_type());
		this->_person[i].set_name(_person[i].get_name());
		this->_person[i].set_retire_id(_person[i].get_retire_id());
		this->_person[i].set_experience(_person[i].get_experience());
	}
}

void HumanList::insert(int index, Human f)
{
	if ((index >= CAPACITY) or (index < 0))
	{
		throw runtime_error("error 1");
	}

	for (int i = _size - 1; i >= index; --i)
	{
		_person[i] = _person[i - 1];
	} ++_size;
	_person[index] = f;
}

void HumanList::remove(int index)
{
	if ((index >= CAPACITY) or (index < 0))
	{
		throw runtime_error("error 1");
	}

	for (int i = index; i < _size - 1; ++i)
	{
		_person[i] = _person[i + 1];
	} --_size;
}

Human& HumanList::operator[](int index)
{
	if ((index >= CAPACITY) or (index < 0))
	{
		throw runtime_error("error 1");
	}

	return _person[index];
}