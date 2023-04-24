#include <gtest/gtest.h>
#include <functions/functions.h>
#define CAPACITY 10
using namespace std;
using namespace peoples;

// schooler

TEST(PaymentTests, SchoolerFromSmall) // 1
{
	Human Tolyanchik(SCHOOLER, "Tolya", "44sc", 1488, 0, 0, 0, 0, 0);
	int r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 0);
}

TEST(PaymentTests, SchoolerFromLarge) // 2
{
	Human Tolyanchik(SCHOOLER, "Tolya", "44sc", 1488, 0, 1, 0, 0, 0);
	int r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 8121);
}

// student

TEST(PaymentTests, StudentSoBad) // 3
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 0, 1488, 0, 3.2, 0, 0);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 0);
}

TEST(PaymentTests, StudentBad) // 4
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 0, 1488, 0, 3.9, 0, 0);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 8121);
}

TEST(PaymentTests, StudentGood) // 5
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 0, 1488, 0, 4.2, 0, 0);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	ASSERT_DOUBLE_EQ(r, 9745.2);
}

TEST(PaymentTests, StudentSoGood) // 6
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 0, 1488, 0, 4.7, 0, 0);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 11369.4);
}

TEST(PaymentTests, StudentBest) // 7
{
	Human Tolyanchik(STUDENT, "Tolya", "44sc", 0, 1488, 0, 5, 0, 0);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 12993.6);
}

// retire

TEST(PaymentTests, RetireBad) // 8
{
	Human Tolyanchik(RETIRE, "Tolya", "", 0, 0, 0, 0, 1488, 4);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 0);
}

TEST(PaymentTests, RetireBest) // 9
{
	Human Tolyanchik(RETIRE, "Tolya", "", 0, 0, 0, 0, 1488, 31);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 81210);
}

TEST(PaymentTests, RetireMin) // 10
{
	Human Tolyanchik(RETIRE, "Tolya", "", 0, 0, 0, 0, 1488, 5);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	ASSERT_DOUBLE_EQ(r, 16242);
}

TEST(PaymentTests, RetireGood) // 11
{
	Human Tolyanchik(RETIRE, "Tolya", "", 0, 0, 0, 0, 1488, 9);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 32484);
}

TEST(PaymentTests, RetireVeryGood) // 12
{
	Human Tolyanchik(RETIRE, "Tolya", "", 0, 0, 0, 0, 1488, 17);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 48726);
}

TEST(PaymentTests, RetireAlmostBest) // 13
{
	Human Tolyanchik(RETIRE, "Tolya", "", 0, 0, 0, 0, 1488, 24);
	double r = Tolyanchik.payday_for_all(Tolyanchik.get_type());
	EXPECT_EQ(r, 64968);
}

// setters & getters

TEST(SetandGet, GetType) // 14
{
	Human Tolyanchik(SCHOOLER, "Tolya", "44sc", 1488, 0, 1, 0, 0, 0);
	double r = Tolyanchik.get_type();
	EXPECT_EQ(r, SCHOOLER);
}

TEST(SetandGet, SetType) // 15
{
	Human Tolyanchik;
	Tolyanchik.set_type(SCHOOLER);
	EXPECT_EQ(Tolyanchik.get_type(), SCHOOLER);
}

// new tests 

TEST(RandomHuman, payday) // 16
{
	Human human[CAPACITY];
	Human Tolya(RETIRE, "Tolya", "", 0, 0, 0, 0, 1488, 31);
	human[0] = Human();
	human[1] = Tolya;
	double r = human[0].payday_for_all(human[0].get_type());
	double r2 = human[1].payday_for_all(human[1].get_type());

	EXPECT_EQ(r, 11369.4);
	EXPECT_EQ(r2, 81210);
}

// remove & insert

TEST(RemoveAndInsert, removeInsert) // 17
{
	Human l = Human(SCHOOLER, "Tolya", "44sc", 1488, 0, 1, 0, 0, 0);
	HumanList n = HumanList();
	n.insert(2, l);
	n.remove(1);

	EXPECT_EQ(n[1].get_type(), l.get_type());

}

TEST(CopyConstr, copy) // 18
{
	Human Sergey1 = Human();
	Human Sergey2 = Human(Sergey1);
	EXPECT_EQ(Sergey1.get_name(), Sergey2.get_name());
}