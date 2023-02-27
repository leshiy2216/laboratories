#pragma once
#include <string>
#include <iostream>
using namespace std;

int sum_stub(int lhs, int rhs);

enum HumanType
{
	schooler,
	student,
	retire
};

enum Flag // belonging to a large family(schooler)
{
	No,
	Yes
};

class Human
{

public:

	// general
	HumanType Type;
	string FLname;

	// schooler
	string school;
	int TicketNumber;
	Flag flag;

	// student
	string university;
	int StudentID;
	double AverageScore;

	// retire
	int IDcard;
	int experience;
};