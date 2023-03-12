#include <functions/functions.h>
#include <iostream>
#include <string>
#define MINSIZE 16242
using namespace std;

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