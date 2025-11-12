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

//==============================================================================================//

TEST(PasswordTest, SC_$)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("$");
    ASSERT_EQ(false, actual);
}

TEST(PasswordTest, SC_0)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("0");
    ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_lowercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("hi how are you");
    ASSERT_EQ(false, actual);
}

TEST(PasswordTest, first_letter_uppercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("Hi how are you");
    ASSERT_EQ(true, actual);
}

TEST(PasswordTest, Everything_but_the_first_letters_is_uppercase)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("hI hOW aRE yOU");
    ASSERT_EQ(true, actual);
}

TEST(PasswordTest, all_uppercase1)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("HI HOW ARE YOU");
    ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_uppercase2)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("ABAB");
    ASSERT_EQ(false, actual);
}

TEST(PasswordTest, SC_)
{
    Password my_password;
    bool actual = my_password.has_mixed_case("!?");
    ASSERT_EQ(false, actual);
}

//==================================================================//

TEST(PasswordTest, UniqueCharacters_EmptyString)
{
    Password my_password;
    unsigned int actual = my_password.unique_characters("");
    ASSERT_EQ(0, actual);
}

TEST(PasswordTest, UniqueCharacters_AllUnique)
{
    Password my_password;
    unsigned int actual = my_password.unique_characters("abcABC123!@#");
    ASSERT_EQ(12, actual);
}

TEST(PasswordTest, UniqueCharacters_WithDuplicates)
{
    Password my_password;
    unsigned int actual = my_password.unique_characters("aabbcc");
    ASSERT_EQ(3, actual);
}

TEST(PasswordTest, UniqueCharacters_CaseSensitive)
{
    Password my_password;
    unsigned int actual = my_password.unique_characters("Aa");
    ASSERT_EQ(2, actual);  // 'A' and 'a' are different ASCII chars
}

TEST(PasswordTest, UniqueCharacters_SpecialCharacters)
{
    Password my_password;
    unsigned int actual = my_password.unique_characters("!!@@##");
    ASSERT_EQ(3, actual);  // '!', '@', and '#'
}