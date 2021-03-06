// MeetingCppTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include <vector>
#include <exception>

bool IsEvenNumber(int n) {
	if (n < 0) {
		throw std::exception();
	}

	return n % 2 == 0;
}

TEST(IsEvenNumberTest, TwoIsEven)
{
	EXPECT_EQ(true, IsEvenNumber(2)) << "problema mantis #3445";
}

TEST(IsEvenNumberTest, TreeIsNotEven)
{
	EXPECT_EQ(false, IsEvenNumber(3));
}

TEST(IsEvenNumberTest, MinusTwoRaisesException)
{
	EXPECT_THROW(IsEvenNumber(-2), std::exception);
}

TEST(IsEvenNumberTest, TwoRaisesNoException)
{
	EXPECT_NO_THROW(IsEvenNumber(2));
}

static std::vector<int> CurrentAndFollowingNum(int n) {
	return { n, n + 1 };
}

TEST(CurrentAndFollowingNunTest, TwoFollowsOne)
{
	auto actual = CurrentAndFollowingNum(1);
	ASSERT_EQ(2, actual.size());
	EXPECT_EQ(1, actual[0]);
	EXPECT_EQ(2, actual[1]);
}


TEST(CurrentAndFollowingNunTest, TwoFollowsOneRevisited)
{
	auto actual = CurrentAndFollowingNum(1);
	auto expected = std::vector<int>({ 1,2 });
	EXPECT_THAT(actual, ::testing::Eq(expected));
}
