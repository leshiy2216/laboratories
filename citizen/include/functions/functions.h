#pragma once
#include <string>
#include <iostream>
using namespace std;

int sum_stub(int lhs, int rhs);

namespace citizen
{

	const int MinSize = 16242;

	enum HumanType
	{
		schooler,
		student,
		retire
	};

	enum AverageScore
	{
		Bad,
		Average,
		Good,
		Better,
		Perfectly
	};

	class Human
	{

	public:

		// general
		string FLname;

		// schooler
		string school;
		int TicketNumber;
		bool flag;
		Human(string FLname, string school, int TicketNumber, bool flag)
		{
			FLname = FLname;
			school = school;
			TicketNumber = TicketNumber;
			flag = flag;
		}
		double SchoolPayday(int flag);

		// student
		string university;
		int StudentID;
		double AverageScore;
		Human(string FLname, string university, int StudentID, double AverageScore)
		{
			FLname = FLname;
			university = university;
			StudentID = StudentID;
			AverageScore = AverageScore;
		}
		double StudentPayday(double AverageScore);

		// retire
		int IDcard;
		int experience;
		Human(string FLname, int IDcard, int experience)
		{
			FLname = FLname;
			IDcard = IDcard;
			experience = experience;
		}
		double RetirePayday(int experience);

	private:
		HumanType Type;

		Human(HumanType Type, string FLname, string school, int TicketNumber, bool flag, string university, int StudentID, double AverageScore, int IDcard, int experience)
		{
			this->Type = Type;
			this->FLname = FLname;
			this->school = school;
			this->TicketNumber = TicketNumber;
			this->flag = flag;
			this->university = university;
			this->StudentID = StudentID;
			this->AverageScore = AverageScore;
			this->IDcard = IDcard;
			this->experience = experience;
		}
	};

}