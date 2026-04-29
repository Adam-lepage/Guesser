/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}


TEST(GuesserTest, Test1)
{
  Guesser g("hello");
  ASSERT_EQ(g.distance("hello"), 0u);
}

TEST(GuesserTest, Test2)
{
  Guesser g("abcde");
  ASSERT_EQ(g.distance("abzde"), 1u);
}

TEST(GuesserTest, Test3)
{
  Guesser g("hello");
  ASSERT_EQ(g.distance("hi"), 4u);
}

TEST(GuesserTest, Test4)
{
  Guesser g("hello");
  ASSERT_EQ(g.distance("helloo"), 1u);
  ASSERT_EQ(g.distance("hello_this_guess_is_too_long"), 5u);
}

TEST(GuesserTest, Test5)
{
  Guesser g("");
  ASSERT_EQ(g.distance(""), 0u);
  ASSERT_EQ(g.distance("anything"), 0u);
}

TEST(GuesserTest, Test6)
{
  std::string secret(33, 'x');
  std::string secretminus1(32, 'x');
  Guesser g(secret);
  ASSERT_TRUE(g.match(secretminus1));
  ASSERT_FALSE(g.match(secret));
}

TEST(GuesserTest, Test7)
{
  Guesser g("Secret");
  ASSERT_TRUE(g.match("Secret"));
}

TEST(GuesserTest, Test8)
{
  Guesser g("Secret");
  ASSERT_FALSE(g.match("Secrat"));
  ASSERT_FALSE(g.match("Secrat"));
  ASSERT_TRUE(g.match("Secret"));
}

TEST(GuesserTest, Test9)
{
  Guesser g("Secret");
  ASSERT_FALSE(g.match("Secrat"));
  ASSERT_FALSE(g.match("Secrat"));
  ASSERT_FALSE(g.match("Secrat"));
  ASSERT_FALSE(g.match("Secret"));
}

TEST(GuesserTest, Test10)
{
  Guesser g("Secret");
  ASSERT_FALSE(g.match("XXXXXXX"));
  ASSERT_FALSE(g.match("Secret"));
}

TEST(GuesserTest, Test11)
{
  Guesser g("Secret");
  ASSERT_FALSE(g.match("Sxcrxt"));
  ASSERT_TRUE(g.match("Secret"));
}

TEST(GuesserTest, Test12)
{
  Guesser g("Secret");
  ASSERT_FALSE(g.match("Secrat"));
  ASSERT_FALSE(g.match("Secrat"));
  ASSERT_TRUE(g.match("Secret"));
  ASSERT_FALSE(g.match("Secrat"));
  ASSERT_FALSE(g.match("Secrat"));
  ASSERT_TRUE(g.match("Secret"));
}