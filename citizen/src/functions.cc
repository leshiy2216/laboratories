#include <functions/functions.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include<utility>
#include<cmath>
#include <math.h>
#define MINSIZE 16242
#define SIZE 4
using namespace std;
using namespace peoples;

void Human::set_name(const string& name)
{
	this->name = name;
}

const string& Human::get_name() const
{
	return name;
}

void Schooler::set_educational_institution(const string& educational_institution)
{
	this->educational_institution = educational_institution;
}

void Schooler::set_ticket(int ticket)
{
	this->ticket = ticket;
}

void Schooler::set_is_large_family(bool is_large_family)
{
	this->is_large_family = is_large_family;
}

int Schooler::get_ticket() const
{
	return ticket;
}

bool Schooler::get_is_large_family() const
{
	return is_large_family;
}

const string& Schooler::get_educational_institution() const
{
	return educational_institution;
}

unique_ptr<Human>Schooler::clone() const
{
	return make_unique<Schooler>(*this);
}

void Schooler::print(ostream& stream) const
{
	stream << "Schooler: " << name << ", Educational Institution: " << educational_institution << ", Ticket: " << ticket << ", Large Family: " << is_large_family << endl;
}

unique_ptr<Human>Student::clone() const
{
	return make_unique<Student>(*this);
}

void Student::print(ostream& stream) const
{
	stream << "Student: " << name << ", Educational Institution: " << educational_institution << ", Book: " << book << ", Score: " << score << endl;
}

void Student::set_educational_institution(const string& educational_institution) 
{
	this->educational_institution = educational_institution;
}

void Student::set_book(int book) 
{
	this->book = book;
}

void Student::set_score(double score)
{
	this->score = score;
}

const string&Student::get_educational_institution() const 
{
	return educational_institution;
}

int Student::get_book() const 
{
	return book;
}

double Student::get_score() const 
{
	return score;
}

unique_ptr<Human>Retire::clone() const
{
	return make_unique<Retire>(*this);
}

void Retire::print(ostream& stream) const
{
	stream << "Retire: " << name << ", Retire ID: " << retire_id << ", Experience: " << experience << endl;
}

void Retire::set_retire_id(int retire_id) 
{
	this->retire_id = retire_id;
}
void Retire::set_experience(int experience)
{
	this->experience = experience;
}

int Retire::get_retire_id() const 
{
	return retire_id;
}
int Retire::get_experience() const
{
	return experience;
}
// set & get:
/*
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

*/
/*
// 2nd class

Human& HumanList::operator[](const int index)
{
	if (index >= _size)
		throw runtime_error("Index out of range");
	return _ptr[index][0];
}

void HumanList::clear() noexcept
{
	for (int i = 0; i < _size; ++i)
		delete[] _ptr;
	_ptr = nullptr;
	_size = 0;
}

HumanList::~HumanList()
{
	clear();
}

HumanList::HumanList(const HumanList& list) :
	_ptr(new Human_ptr[list._size]),
	_size(list._size)
{
	for (int i = 0; i < _size; ++i)
	{
		_ptr[i] = new Human(*list._ptr[i]);
	}
}

void HumanList::Swap(HumanList& cpy) noexcept
{
	swap(_ptr, cpy._ptr);
	swap(_size, cpy._size);
}

HumanList& HumanList::operator=(const HumanList& list)
{
	HumanList _copy(list);
	Swap(_copy);
	return *this;
}

void HumanList::add(Human item)
{
	Human_ptr* ptr = new Human * [_size + 1];
	for (int i = 0; i < _size; i++)
	{
		ptr[i] = new Human;
		*ptr[i] = *this->_ptr[i];
	}
	delete[] _ptr;

	_ptr = ptr;
	_ptr[_size] = new Human;
	*_ptr[_size] = item;
	++_size;
}

void HumanList::add(Human item, int index)
{
	if (index < 0) throw runtime_error("Wrong index");
	Human_ptr* ptr = new Human * [_size + 1];
	for (int i = 0; i < index; i++)
	{
		ptr[i] = new Human();
		*ptr[i] = *this->_ptr[i];
	}
	ptr[index] = new Human();
	*ptr[index] = item;
	for (int i = 0; i > index && i < _size + 1; i++)
	{
		ptr[i] = new Human;
		*ptr[i] = *this->_ptr[i - 1];
	}
	delete[] _ptr;
	_ptr = ptr;
	++_size;
}

void HumanList::Del(int index)
{
	for (int i = index; i < _size - 1; i++)
	{
		_ptr[i] = _ptr[i + 1];
	}
	auto ptr = new Human * [_size - 1];
	--_size;
	for (int i = 0; i < _size; i++)
	{
		ptr[i] = _ptr[i];
	}
	delete[] _ptr;
	_ptr = ptr;
}

void HumanList::Print()
{
	for (int i = 0; i < _size; i++)
	{
		cout << endl;
		cout << "Human " << i + 1 << endl;
		if (_ptr[i]->get_type() == SCHOOLER)
		{
			cout << endl;
			cout << "Type: schooler" << endl;
			cout << "Name: " << _ptr[i]->get_name() << endl;
			cout << "School: " << _ptr[i]->get_educational_institution() << endl;
			cout << "Ticket: " << _ptr[i]->get_ticket() << endl;
			//cout << "family " << _ptr[i]->get_is_large_family() << endl;
			if (_ptr[i]->get_is_large_family() == 1) cout << "From large family" << endl;
			else cout << "Not large family" << endl;
			cout << "Payday: " << _ptr[i]->payday_for_schooler() << endl;
		}
		if (_ptr[i]->get_type() == STUDENT)
		{
			cout << endl;
			cout << "Type: student" << endl;
			cout << "Name: " << _ptr[i]->get_name() << endl;
			cout << "University: " << _ptr[i]->get_educational_institution() << endl;
			cout << "Book: " << _ptr[i]->get_book() << endl;
			cout << "Score: " << _ptr[i]->get_score() << endl;
			cout << "Payday: " << _ptr[i]->payday_for_student() << endl;
		}
		if (_ptr[i]->get_type() == RETIRE)
		{
			cout << endl;
			cout << "Type: retire" << endl;
			cout << "Name: " << _ptr[i]->get_name() << endl;
			cout << "ID: " << _ptr[i]->get_retire_id() << endl;
			cout << "Experience: " << _ptr[i]->get_experience() << endl;
			cout << "Payday: " << _ptr[i]->payday_for_retire() << endl;
		}
	}
}

double HumanList::max_payday() const
{
	double max = 0;
	for (int i = 0; i < _size; i++)
	{
		if (_ptr[i]->payday_for_all(_ptr[i]->get_type()) > max)
		{
			max = _ptr[i]->payday_for_all(_ptr[i]->get_type());
		}
	}
	return max;
}*/