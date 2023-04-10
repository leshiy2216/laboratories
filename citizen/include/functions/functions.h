#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace peoples 
{
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
		Human(HumanType type, string name, string educational_institution, int ticket, int book, bool is_large_family, double score, int retire_id, int experience); // for schooler
		/*Human(int, HumanType type, string name, string educational_institution, int book, double score); // for student
		Human(double, HumanType type, string name, int retire_id, int experience); // for retire*/

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
		Human _person[CAPACITY];
		int _size;
	public:
		// constructors:
		HumanList(); // standard
		HumanList(Human _person[], int _size); // schooler
		HumanList(Human _person[], int _size, float); // student
		HumanList(Human _person[], int _size, double); // retire

		int size() const;
		void insert(int index, Human f);
		void remove(int index);
		Human& operator[](int index);
	};
}