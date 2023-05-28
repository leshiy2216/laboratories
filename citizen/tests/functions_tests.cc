#include <gtest/gtest.h>
#include <functions/functions.h>
#define CAPACITY 10
#define MINSIZE 16242
using namespace std;
using namespace peoples;

// Тест функции payday() класса Schooler
TEST(HumanTest, SchoolerPayday) {
    Schooler schooler("John", "ABC School", 123, true);
    double payday = schooler.payday(true, 4.5, 10);
    EXPECT_EQ(payday, 0.6 * MINSIZE);
}

// Тест функции payday() класса Student
TEST(HumanTest, StudentPayday) {
    Student student("Alice", "XYZ University", 456, 4.2);
    double payday = student.payday(false, 4.2, 5);
    EXPECT_EQ(payday, 0.6 * MINSIZE);
}

// Тест функции payday() класса Retire
TEST(HumanTest, RetirePayday) {
    Retire retiree("Bob", 789, 15);
    double payday = retiree.payday(false, 4.8, 15);
    EXPECT_EQ(payday, 3 * MINSIZE);
}

// Тест функции max_payday() класса HumanList
TEST(HumanListTest, MaxPayday) {
    HumanList humanList;
    humanList.insert(0, make_shared<Schooler>("John", "ABC School", 123, true));
    humanList.insert(1, make_shared<Student>("Alice", "XYZ University", 456, 4.2));
    humanList.insert(2, make_shared<Retire>("Bob", 789, 15));

    double maxPayday = humanList.max_payday(true, 4.2, 10);
    EXPECT_EQ(maxPayday, 0.6 * MINSIZE);
}