#pragma once
#include <string>
#include <iostream>
using namespace std;

int sum_stub(int lhs, int rhs);

enum HumanState
{
	schooler,
	student,
	retire
};

class human 
{
public:

	string flname;
	string schoolname;
	int ticket_number;

private:

	HumanState State;
};