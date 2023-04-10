#include <gtest/gtest.h>
#include <functions/functions.h>
#define CAPACITY 10
using namespace std;
using namespace peoples;

// schooler

TEST(PaymentTests, SchoolerFromSmall) // 1
{
	Human Tolyanchik(HumanType::SCHOOLER, "Tolya", "44sc", 1488, 0, 0, 0, 0, 0);
	int r = Tolyanchik.payday_for_schooler();
	EXPECT_EQ(r, 0);
}

TEST(PaymentTests, SchoolerFromLarge) // 2
{
	Human Tolyanchik(SCHOOLER, "Tolya", "44sc", 1488, 0, 1, 0, 0, 0);
	int r = Tolyanchik.payday_for_schooler();
	EXPECT_EQ(r, 8121);
}

// student
/*
TEST(PaymentTests, StudentSoBad) // 3
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 1488, 3.3);
	double r = Tolyanchik.payday_for_student();
	EXPECT_EQ(r, 0);
}

TEST(PaymentTests, StudentBad) // 4
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 1488, 3.9);
	double r = Tolyanchik.payday_for_student();
	EXPECT_EQ(r, 8121);
}

TEST(PaymentTests, StudentGood) // 5
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 1488, 4.2);
	double r = Tolyanchik.payday_for_student();
	EXPECT_EQ(r, 9745.2);
}

TEST(PaymentTests, StudentSoGood) // 6
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 1488, 4.7);
	double r = Tolyanchik.payday_for_student();
	EXPECT_EQ(r, 11369.4);
}

TEST(PaymentTests, StudentBest) // 7
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 1488, 5);
	double r = Tolyanchik.payday_for_student();
	EXPECT_EQ(r, 12993.6);
}*/