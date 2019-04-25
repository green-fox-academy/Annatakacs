#include "gtest/gtest.h"
#include "letters.h"

TEST(TestDictionary, SeeIfMapIsReady)
{
    //Arrange
    Letters letters;
    letters.word = "BELA";

    //Act
    std::map<std::string, int> myMap = letters.makingDictionay(letters.word);

    // Assert
    ASSERT_EQ(myMap["B"], 1);
    ASSERT_EQ(myMap["E"], 2);
    ASSERT_EQ(myMap["L"], 3);
    ASSERT_EQ(myMap["A"], 4);
}

