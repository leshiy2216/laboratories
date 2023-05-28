#include <gtest/gtest.h>
#include <functions/functions.h>
#define CAPACITY 10
#define MINSIZE 16242
using namespace std;
using namespace peoples;


// Add element to array #1
TEST(HumanListTest, InsertElement) 
{
	HumanList list;
	HumanPtr human = make_shared<Schooler>("Vasiliy", "School of Science", 123, false);

	list.insert(0, human);

	ASSERT_EQ(list.size(), 1);
	ASSERT_EQ(list[0]->get_name(), "Vasiliy");
}


// Delete element from array #2
TEST(HumanListTest, RemoveElement) 
{
	HumanList list;
	HumanPtr human1 = make_shared<Schooler>("Andrey", "School of Society", 123, false);
	HumanPtr human2 = make_shared<Student>("Maksim", "University", 456, 4.5);

	list.insert(0, human1);
	list.insert(1, human2);

	list.remove(0);

	ASSERT_EQ(list.size(), 1);
	ASSERT_EQ(list[0]->get_name(), "Maksim");
}


// Calculation payday for Schooler #3
TEST(HumanTest, SchoolerPayday) 
{
	HumanPtr human = make_shared<Schooler>("Maksim", "High School", 123, true);
	double payday = human->payday(true, 0, 0);

	ASSERT_EQ(payday, 8121);
}


// Calculation payday for Student #4
TEST(HumanTest, StudentPayday) 
{
	HumanPtr human = make_shared<Student>("Daniil", "University", 456, 4.2);
	double payday = human->payday(false, 4.2, 0);

	ASSERT_DOUBLE_EQ(payday, 9745.2);
}


// Calculation payday for Retire #5
TEST(HumanTest, RetirePayday) 
{
	HumanPtr human = make_shared<Retire>("Evgeniy", 789, 15);
	double payday = human->payday(false, 0, 15);

	ASSERT_EQ(payday, 48726);
}

// Check size #6
TEST(HumanListTest, Size) 
{
	HumanList list;
	HumanPtr human1 = make_shared<Schooler>("Andrey", "School of Society", 123, false);
	HumanPtr human2 = make_shared<Student>("Maksim", "University", 456, 4.5);

	list.insert(0, human1);
	list.insert(1, human2);

	int size = list.size();

	ASSERT_EQ(size, 2);
}


// Check swap #7
TEST(HumanListTest, Swap) 
{
	HumanList list1;
	HumanList list2;
	HumanPtr human1 = make_shared<Schooler>("Andrey", "School of Society", 123, false);
	HumanPtr human2 = make_shared<Student>("Maksim", "University", 456, 4.5);

	list1.insert(0, human1);
	list2.insert(0, human2);

	list1.swap(list2);

	ASSERT_EQ(list1[0]->get_name(), "Maksim");
	ASSERT_EQ(list2[0]->get_name(), "Andrey");
}