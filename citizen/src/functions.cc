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

// constr

Schooler::Schooler(string name, string educational_institution, int ticket, bool is_large_family)
{
	this->name = name;
	this->educational_institution = educational_institution;
	this->ticket = ticket;
	this->is_large_family = is_large_family;
}

Student::Student(string name, string educational_institution, int book, double score)
{
	this->name = name;
	this->educational_institution = educational_institution;
	this->book = book;
	this->score = score;
}

Retire::Retire(string name, int id, int experience)
{
	this->name = name;
	this->id = id;
	this->experience = experience;
}

// SET GET HUMAN

void Human::set_name(string name) { this->name = name; }
string Human::get_name() { return name; }


// PAYDAYS

double Schooler::payday(bool is_large_family, double score, int experience) const
{
	if (is_large_family) return 0.5 * MINSIZE;
	if (is_large_family = 0) return 0;
}

double Student::payday(bool is_large_family, double score, int experience) const
{
	if (score < 3.5) return 0;
	if (score >= 3.5 and score < 4) return 0.5 * MINSIZE;
	if (score >= 4 and score < 4.5) return 0.6 * MINSIZE;
	if (score >= 4.5 and score < 5) return 0.7 * MINSIZE;
	if (score == 5) return 0.8 * MINSIZE;
}

double Retire::payday(bool is_large_family, double score, int experience) const
{
	if (experience < 5) return 0;
	if (experience > 30) return 5 * MINSIZE;
	if (experience == 5) return MINSIZE;
	if (experience > 5 and experience <= 10) return 2 * MINSIZE;
	if (experience > 10 and experience <= 20) return 3 * MINSIZE;
	if (experience > 20 and experience <= 30) return 4 * MINSIZE;
}

// PRINTS

void Schooler::print(std::ostream& stream) const
{
	stream << "Type of Human: Schooler" << endl;
	stream << "Name: " << name << endl;
	stream << "School: " << educational_institution << endl;
	stream << "Ticket: " << ticket << endl;
	stream << "From Large Family? - " << is_large_family << endl;
	stream << "Payday Is " << payday(is_large_family, 0, 0) << endl;
	// stream << "Payday: " << payday << endl;
}

void Student::print(std::ostream& stream) const
{
	stream << "Type of Human: Student" << endl;
	stream << "Name: " << name << endl;
	stream << "University: " << educational_institution << endl;
	stream << "Book: " << book << endl;
	stream << "Score: " << score << endl;
	stream << "Payday Is " << payday(0, score, 0) << endl;
	// stream << "Payday: " << payday << endl;
}

void Retire::print(std::ostream& stream) const
{
	stream << "Type of Human: Retire" << endl;
	stream << "Name: " << name << endl;
	stream << "ID: " << id << endl;
	stream << "Experience: " << experience << endl;
	stream << "Payday Is " << payday(0, 0, experience) << endl;
	// stream << "Payday: " << payday << endl;
}

// CLONES

HumanPtr Schooler::clone() 
{
	return make_shared<Schooler>(*this);
}

HumanPtr Student::clone()
{
	return make_shared<Student>(*this);
}

HumanPtr Retire::clone()
{
	return make_shared<Retire>(*this);
}

// MAX PAYDAY

double HumanList::max_payday() const
{

	double maxPayday = 0.0;

	for (int i = 0; i < _humans.size(); ++i)
	{
		bool is_large_family = 1;
		double score = 4.2;
		int experience = 10;
		double payday = _humans[i]->payday(is_large_family, score, experience);
		if (payday > maxPayday)
		{
			maxPayday = payday;
		}
	}
	return maxPayday;
}

HumanList::HumanList(const HumanList& other)
{
	const int n = other.size();
	_humans.reserve(n);
	for (size_t i = 0; i < n; ++i)
	{
		_humans.push_back(other[i]->clone());
	}
}

void HumanList::insert(int index, HumanPtr f)
{
	if (index < 0 || index > _humans.size()) throw runtime_error("error1");
	_humans.insert(_humans.begin() + index, f);
}

void HumanList::remove(int index)
{
	if (index >= _humans.size() || index < 0) throw runtime_error("error1");
	_humans.erase(_humans.begin() + index);
}

void HumanList::clear() { _humans.clear(); }

void HumanList::swap(HumanList& rhs) noexcept
{
	std::swap(_humans, rhs._humans);
}

void HumanList::print_humans(int index) const
{
	_humans[index]->print(std::cout);
}

HumanPtr& HumanList::operator[](int index)
{
	return _humans.at(index);
}

HumanPtr HumanList::operator[](int index) const
{
	return _humans.at(index);
}

HumanList& HumanList::operator=(const HumanList& other)
{
	HumanList tmp(other);
	tmp.swap(*this);
	return *this;
}

int HumanList::size() const
{
	return _humans.size();
}