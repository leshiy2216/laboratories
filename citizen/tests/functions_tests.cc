#include <gtest/gtest.h>
#include <functions/functions.h>

// SCHOOLER

TEST(PaydayTests, PaydaySchooler) // 1
{
	Human FirstPerson = Human(SCHOOLER, "Andrey Pavlovich Konev", "19 school", 1488, true);
	EXPECT_EQ(FirstPerson.payday_for_schooler(), 8121);
}

TEST(PaydayTests, PaydaySchoolerIfFalse) // 2
{
	Human FirstHuman = Human(SCHOOLER, "Anton Vladimirovich Maksomov", "29 school", 1312, false);
	EXPECT_EQ(FirstHuman.payday_for_schooler(), 0);
}

// STUDENT

TEST(PaydayTests, PaydayStudentIfVeryGood) // 3
{
	Human FirstPeople = Human(STUDENT, "Andrey Alekseevich Danilov", "VUZ karaka", 1488, 5);
	EXPECT_EQ(FirstPeople.payday_for_student(), 12993.6)
}

TEST(PaydayTests, PaydayStudentIfVeryBad) // 4
{
	Human FirstPeople = Human(STUDENT, "Artem Alekseevich Danilov", "VUZ karakul", 1488, 2.9);
	EXPECT_EQ(FirstPeople.payday_for_student(), 0)
}

TEST(PaydayTests, PaydayStudentIfBad) // 5
{
	Human FirstPeople = Human(STUDENT, "Andrey Maksimovich Danilov", "VUZ karakada", 1488, 3.7);
	EXPECT_EQ(FirstPeople.payday_for_student(), 8121)
}

TEST(PaydayTests, PaydayStudentIfGood) // 6
{
	Human FirstPeople = Human(STUDENT, "Sergey Alekseevich Danilov", "VUZ karakazaza", 1488, 4.4);
	EXPECT_EQ(FirstPeople.payday_for_student(), 9745.2)
}

TEST(PaydayTests, PaydayStudentIfAlmostVeryGood) // 7
{
	Human FirstPeople = Human(STUDENT, "Andrey Evgenievich Danilov", "VUZ darakaraka", 1488, 4.9);
	EXPECT_EQ(FirstPeople.payday_for_student(), 11369.4)
}

// RETIRE

TEST(PaydayTests, PaydayRetireVeryLow) // 8
{
	Human FirstPeople = Human(RETIRE, "Alexey Vladimirovich Zhorkin", 1312, 3);
	EXPECT_EQ(FirstPeople.payday_for_retire(), 0);
}

TEST(PaydayTests, PaydayRetireVeryHigh) // 9
{
	Human FirstPeople = Human(RETIRE, "Alexey Vladimirovich Durov", 1312, 33);
	EXPECT_EQ(FirstPeople.payday_for_retire(), 81210);
}

TEST(PaydayTests, PaydayRetireEqMin) // 10
{
	Human FirstPeople = Human(RETIRE, "Maksim Vladimirovich Zhorkin", 1312, 5);
	EXPECT_EQ(FirstPeople.payday_for_retire(), 16242);
}

TEST(PaydayTests, PaydayRetireLow) // 11
{
	Human FirstPeople = Human(RETIRE, "Alexey Maksimovich Zhorkin", 1312, 7);
	EXPECT_EQ(FirstPeople.payday_for_retire(), 32484);
}

TEST(PaydayTests, PaydayRetireBetterLow) // 12
{
	Human FirstPeople = Human(RETIRE, "Alexey Vladimirovich Zhorkin", 1312, 13);
	EXPECT_EQ(FirstPeople.payday_for_retire(), 48726);
}

TEST(PaydayTests, PaydayRetireHigh) // 13
{
	Human FirstPeople = Human(RETIRE, "Alexey Danilovich Zhorkin", 1312, 28);
	EXPECT_EQ(FirstPeople.payday_for_retire(), 64968);
}