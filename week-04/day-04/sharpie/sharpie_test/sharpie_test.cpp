#include "gtest/gtest.h"
#include "Sharpie.h"

TEST(TestSharpie, CheckIfConstructorWorks)
{
    // Arrange
    std::string color = "yellow";
    float width = 10.2;
    Sharpie sharpie(color, width);

    // Act
    std::string colorResult = sharpie.getcolor();
    float widthResult = sharpie.getwidth();

    // Assert
    ASSERT_EQ(colorResult, color);
    ASSERT_EQ(widthResult, width);
}

TEST(TestSharpie, CheckIfInkIsSet)
{
    // Arrange
    std::string color = "yellow";
    float width = 10.2;
    Sharpie sharpie(color, width);

    // Act
    float inkAmount = sharpie.getinkAmount();

    // Assert
    ASSERT_EQ(inkAmount, 100);
}

TEST(TestSharpie, CheckIf1UseWorks)
{
    // Arrange
    std::string color = "yellow";
    float width = 10.2;
    Sharpie sharpie(color, width);

    // Act
    sharpie.use();
    float inkAmount = sharpie.getinkAmount();

    // Assert
    ASSERT_EQ(inkAmount, 85);
}

TEST(TestSharpie, CheckIf3UsesWork)
{
    // Arrange
    std::string color = "yellow";
    float width = 10.2;
    Sharpie sharpie(color, width);

    // Act
    sharpie.use();
    sharpie.use();
    sharpie.use();
    float inkAmount = sharpie.getinkAmount();

    // Assert
    ASSERT_EQ(inkAmount, 55);
}