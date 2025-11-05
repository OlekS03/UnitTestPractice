/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multiple_leading_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("AAAxyz");
    ASSERT_EQ(3, actual);
}

TEST(PasswordTest, no_repeated_leading_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("Abbb");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string)
{
    Password my_password;
    int actual = my_password.count_leading_characters("");
    ASSERT_EQ(0, actual);
}

TEST(PasswordTest, case_sensitivity)
{
    Password my_password;
    int actual = my_password.count_leading_characters("AAaAA");
    ASSERT_EQ(2, actual);
}

TEST(PasswordTest, all_same_character)
{
    Password my_password;
    int actual = my_password.count_leading_characters("ZZZZZZ");
    ASSERT_EQ(6, actual);
}

TEST(PasswordTest, numeric_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("1111abc");
    ASSERT_EQ(4, actual);
}

TEST(PasswordTest, special_characters)
{
    Password my_password;
    int actual = my_password.count_leading_characters("$$$Hello");
    ASSERT_EQ(3, actual);
}

