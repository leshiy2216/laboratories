#pragma once
#include <string>
#include <iostream>
#define MINSIZE 16242
using namespace std;

namespace citizen
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
		string PlaceName;
		int ticket;
		bool is_large_family;
		int book;
		double score;
		int ID;
		int years;

	public:
		Human(HumanType type, string name, string PlaceName, int ticket, bool is_large_family);
		Human(HumanType type, string name, string PlaceName, int book, double score);
		Human(HumanType type, string name, int ID, int years);
		void set_type(HumanType type);
		void set_name(string name);
		void set_PlaceName(string PlaceName);
		void set_ticket(int ticket);
		void set_IsLargeFamily(bool is_large_family);
		void set_book(int book);
		void set_score(double score);
		void set_ID(int ID);
		void set_years(int years);
		HumanType get_type();
		string get_name();
		string get_PlaceName();
		int get_ticket();
		bool get_IsLargeFamily();
		int get_book();
		double get_score();
		int get_ID();
		int get_years();
		double payday_schooler();
		double payday_student();
		double payday_retire();
	};

	class HumanList
	{
	private:
		static const int CAPACITY = 10;
		Human persons[CAPACITY];
		int size;

	public:
		HumanList();
		HumanList(Human person[], int size);
		HumanList(Human person[], int size, float);
		HumanList(Human person[], int size, int);
		Human get_person_with_index(int i);
		void set_size(int size);
		int get_size();
		void create_person(int index, Human person);
	};
}