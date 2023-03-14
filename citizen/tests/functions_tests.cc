#include <gtest/gtest.h>
#include <functions/functions.h>

TEST(PaydayTests, PaydaySchooler) // 1
{
	Human FirstPerson = Human(SCHOOLER, "Andrey Pavlovich Daun", "19 school", 1488, true);
	EXPECT_EQ(FirstPerson.payday_for_schooler(), 8121);
}

TEST(PaydayTests, PaydaySchoolerIfFalse) // 2
{
	Human FirstHuman = Human(SCHOOLER, "Anton Vladimirovich Degenerat", "29 school", 1312, false);
	EXPECT_EQ(FirstHuman.payday_for_schooler(), 0);
}