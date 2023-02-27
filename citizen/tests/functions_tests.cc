#include <gtest/gtest.h>
#include <functions/functions.h>
using namespace citizen;

TEST(FunctionsTests, SchoolPayday) {
    // Arrange
    double r = Human::SchoolPayday(0)
    
    // Assert
    EXPECT_EQ(r, 0);
}

TEST(FunctionsTests, SchoolPayday) {
    // Arrange
    int flag = 1;
    
    // Act
    int r = SchoolPayday(int flag);
    
    // Assert
    EXPECT_EQ(r, 8121);
}
