#include <functions/functions.h>
#include <string>
using namespace citizen;
using namespace std;

Human(HumanType type, string name, string PlaceName, int ticket, bool is_large_family)
{
	this->type = type;
	this->name = name;
	this->PlaceName = PlaceName;
	this->ticket = ticket;
	this->is_large_family = is_large_family;
}

Human(HumanType type, string name, string PlaceName, int book, double score)
{
	this->type = type;
	this->name = name;
	this->PlaceName = PlaceName;
	this->book = book;
	this->score = score;
}

Human(HumanType type, string name, int ID, int years)
{
	this->type = type;
	this->name = name;
	this->ID = ID;
	this->years = years;
}

void set_type(HumanType type)
{
	this->type = type;
}
void set_name(string name)
{
	this->name = name;
}
void set_PlaceName(string PlaceName)
{
	this->PlaceName = PlaceName;
}
void set_ticket(int ticket)
{
	this->ticket = ticket;
}
void set_IsLargeFamily(bool is_large_family)
{
	this->is_large_family = is_large_family;
}
void set_book(int book)
{
	this->book = book;
}
void set_score(double score)
{
	this->score = score;
}
void set_ID(int ID)
{
	this->ID = ID;
}
void set_years(int years)
{
	this->years = years;
}

HumanType get_type()
{
	return type;
}
string get_name()
{
	return name;
}
string get_PlaceName()
{
	return PlaceName;
}
int get_ticket()
{
	return ticket;
}
bool get_IsLargeFamily()
{
	return IsLargeFamily;
}
int get_book()
{
	return book;
}
double get_score()
{
	return score;
}
int get_ID()
{
	return ID;
}
int get_years()
{
	return years;
}

double payday_schooler()
{
	if (IsLargeFamily) return double payment = 0.5 * MINSIZE;
	else return 0;
}

double payday_student()
{
	if (score < 3.5) return 0;
	if (score >= 3.5 && score < 4) return double payment = 0.5 * MINSIZE;
	if (score >= 4 && score < 4.5) return double payment = 0.6 * MINSIZE;
	if (score >= 4.5 && score < 5) return double payment = 0.7 * MINSIZE;
	if (score == 5) return double payment = 0.8 * MINSIZE;
}

double payday_retire()
{
	if (years < 5) return 0;
	if (years > 30) return double payment = 5 * MINSIZE;
	if (years >= 5 && years < 10) return MINSIZE;
	if (years >= 10 && years < 20) return double payment = 2 * MINSIZE;
	if (years >= 20 && years <= 25) return double payment = 3 * MINSIZE;
	if (years > 25 && years <= 30) return double payment = 4 * MINSIZE;
}

HumanList()
{
	this->size = 7;
	for (int i = 0; i < size; ++i)
	{
		persons[i] = Human();
	}
}

HumanList(Human person[], int size)
{
	this->size = size;
	for (int i = 0; i < size; ++i)
	{
		this->persons[i].set_type(person[i].get_type());
		this->persons[i].set_name(person[i].get_name());
		this->persons[i].set_PlaceName(person[i].get_PlaceName());
		this->persons[i].set_ticket(person[i].get_ticket());
		this->persons[i].set_IsLargeFamily(person[i].get_IsLargeFamily());
	}
}
HumanList(Human person[], int size)
{
	this->size = size;
	for (int i = 0; i < size; ++i)
	{
		this->persons[i].set_type(person[i].get_type());
		this->persons[i].set_name(person[i].get_name());
		this->persons[i].set_PlaceName(person[i].get_PlaceName());
		this->persons[i].set_book(person[i].get_book());
		this->persons[i].set_score(person[i].get_score());
	}
}
HumanList(Human person[], int size)
{
	this->size = size;
	for (int i = 0; i < size; ++i)
	{
		this->persons[i].set_type(person[i].get_type());
		this->persons[i].set_name(person[i].get_name());
		this->persons[i].set_ID(person[i].get_ID());
		this->persons[i].set_years(person[i].get_years());
	}
}

Human get_person_with_index(int i)
{
	return persons[i];
}

int get_size()
{
	return size;
}
void set_size(int size)
{
	this->size = size;
}

void create_person(int index, Human person)
{
	for (int i = size - 1; i >= index; --i)
	{
		persons[i] = persons[i - 1];
	}
	persons[index] = person;
	++size;
}