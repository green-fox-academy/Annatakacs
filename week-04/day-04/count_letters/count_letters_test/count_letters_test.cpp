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
    ASSERT_EQ(myMap["E"], 1);
    ASSERT_EQ(myMap["L"], 1);
    ASSERT_EQ(myMap["A"], 1);
}

TEST(TestDictionary, SeeIfMapIsReady2)
{
    //Arrange
    Letters letters;
    letters.word = "KONSTANTIN";

    //Act
    std::map<std::string, int> myMap = letters.makingDictionay(letters.word);

    // Assert
    ASSERT_EQ(myMap["K"], 1);
    ASSERT_EQ(myMap["O"], 1);
    ASSERT_EQ(myMap["N"], 3);
    ASSERT_EQ(myMap["S"], 1);
    ASSERT_EQ(myMap["T"], 2);
    ASSERT_EQ(myMap["A"], 1);
    ASSERT_EQ(myMap["I"], 1);
}
