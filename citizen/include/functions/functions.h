#pragma once
#include <iostream>
#include <string>
using namespace std;
#define Human_ptr Human*

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
		// constructors & destructors:
		Human() {}; // standard constructor
		Human(HumanType type, string name, string educational_institution, int ticket, int book, bool is_large_family, double score, int retire_id, int experience); // something class constructor
		

		// calculations paydays:
		double payday_for_schooler();
		double payday_for_student();
		double payday_for_retire();
		double payday_for_all(HumanType type);

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


		// operator

		// methods:
		void print_info();
	};

	class HumanList
	{
	private:
		Human** _ptr;
		int _size; // current size of array
	public:
		HumanList(): _size(0), _ptr(nullptr){}
		HumanList(const HumanList& list);
		void Swap(HumanList& cpy) noexcept;
		HumanList& operator=(const HumanList& list);
		Human& operator[](const int index);
		void add(Human item);
		void add(Human item, int index);
		void Del(int index);
		void clear() noexcept;
		~HumanList();
		void Print();
	};
}