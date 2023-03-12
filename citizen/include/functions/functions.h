#pragma once
#include <iostream>
#include <string>
using namespace std;

enum HumanType
{
	SCHOOLER,
	STUDENT,
	RETIRE
};

class Human
{
private:
	HumanType type;
	string name;
	string educational_institution;
	int ticket;
	bool is_large_family;
	int book;
	double score;
	int retire_id;
	int experience;
public:
	// constructors:
	Human(HumanType type, string name, string educational_institution, int ticket, bool is_large_family); // for schooler
	Human(HumanType type, string name, string educational_institution, int book, double score); // for student
	Human(HumanType type, string name, int retire_id, int experience); // for retire

	// calculations paydays:
	double payday_for_schooler();
	double payday_for_student();
	double payday_for_retire();
};

class HumanList
{

};