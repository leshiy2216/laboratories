#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
#define HumanPtr std::shared_ptr<Human>

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
	protected:
		string name;
		Human() = default;
		Human(const Human&) = default;
		Human& operator=(const Human&) = default;
	public:
		string get_name();
		void set_name(string _name);

		virtual double payday(bool is_large_family, double score, int experience) const = 0;
		virtual void print(std::ostream&) const = 0; //
		virtual HumanPtr clone() = 0; //

		virtual ~Human() = default;
	};

	class Schooler : public Human
	{
	protected:
		string educational_institution;
		int ticket;
		bool is_large_family;
	public:
		string get_educational_institution();
		void set_educational_institution(string _educational);
		int get_ticket();
		void set_ticket(int _ticket);
		bool get_is_large_family();
		void set_is_large_family(bool _ilf);


		Schooler(string name, string educational_institution, int ticket, bool is_large_family);

		double payday(bool is_large_family, double score, int experience) const override;
		void print(std::ostream&) const override;
		HumanPtr clone() override;
	};

	class Student : public Human
	{
	protected:
		string educational_institution;
		int book;
		double score;
	public:
		string get_educational_institution();
		void set_educational_institution(string _educational);
		int get_book();
		void set_book(int _book);
		double get_score();
		void set_score(double _score);

		Student(string name, string educational_institution, int book, double score);

		double payday(bool is_large_family, double score, int experience) const override;
		void print(std::ostream&) const override;
		HumanPtr clone() override;
	};

	class Retire : public Human
	{
	protected:
		int id;
		int experience;
	public:
		int get_id();
		void set_id(int _id);
		int get_experience();
		void set_experience(int _exp);

		Retire(string name, int id, int experience);

		double payday(bool is_large_family, double score, int experience) const override;
		void print(std::ostream&) const override;
		HumanPtr clone() override;
	};

	class HumanList
	{
	private:
		std::vector<HumanPtr> _humans;
	public:
		HumanList() = default;
		HumanList(const HumanList& other);

		HumanPtr& operator[](int index);
		HumanPtr operator[](int index) const;
		HumanList& operator=(const HumanList& other);

		void swap(HumanList& rhs) noexcept;
		void insert(int index, HumanPtr f);
		void remove(int index);
		void print_humans(int index) const;
		//void swap(Space& other);
		void clear();
		int size() const;
		double max_payday() const;
	};
}