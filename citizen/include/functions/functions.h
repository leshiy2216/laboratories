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
	Human(); // default
	Human(HumanType type, string name, string educational_institution, int ticket, bool is_large_family); // for schooler
	Human(HumanType type, string name, string educational_institution, int book, double score); // for student
	Human(HumanType type, string name, int retire_id, int experience); // for retire

	// calculations paydays:
	double payday_for_schooler();
	double payday_for_student();
	double payday_for_retire();

	// set & get:
	void set_type(HumanType type);
	void set_name(string name);
	void set_educational_institution(string educational_institution);
	void set_ticket(int ticket);
	void set_is_large_family(bool is_large_family);
	void set_book(int book);
	void set_score(double score);
	void set_retire_id(int retire_id);
	void set_experience(int experience);

	// ---------------------------------------------------------------

	HumanType get_type();
	string get_name();
	string get_educational_institution();
	int get_ticket();
	bool get_is_large_family();
	int get_book();
	double get_score();
	int get_retire_id();
	int get_experience();
};

class HumanList
{
private:
	static const int CAPACITY = 10;
	Human persons[CAPACITY];
	int size;
public:
	// constructors:
	HumanList(); // default
	HumanList(Human person[], int size); // schooler
	HumanList(Human person[], int size, float); // student
	HumanList(Human person[], int size, int); // retire

	Human get_human_by_index(int i);
	int get_size();
	void set_size(int size);
	Human operator[](int ind) const;
	Human& operator[](int ind);
	void add_human(int ind, Human citizen);
	void del_human(int ind);
	void clear();
};