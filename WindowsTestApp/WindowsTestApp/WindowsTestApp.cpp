// WindowsTestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <exception>
#include <math.h>
#if 0
TEST(TrivialTest, ChecksWeCanTest) {
	EXPECT_EQ(0, 1);
}

TEST(TrivialTest, ExpectContinuesEvaluating) {
	EXPECT_TRUE(false);
	ASSERT_FALSE(true);
	EXPECT_TRUE(true);
}

TEST(TrivialTest, ThrowsException) {
	auto fn = []() { throw std::exception(); };
	EXPECT_THROW(fn(), std::exception);
}

TEST(TrivialTest, FloatEq)
{
	float a = sqrt(9.0f) - 3.0f;
	EXPECT_FLOAT_EQ(0.0f, a);
}

TEST(TrivialTest, GmockStartsWith)
{
	std::string s = "Ciao Mondo!";
	EXPECT_THAT(s, ::testing::StartsWith("Ciao"));
}

TEST(TrivialTest, GmockContains)
{
	std::vector<int> v = { 1, 2, 3, 4 };
	EXPECT_THAT(v, ::testing::Contains(3));
}

class FixtureTest : public ::testing::Test {
protected:
	FixtureTest() {
		instance_resource_ = 42;
		// inizialization
	}

	~FixtureTest() {
	}
	// virtual void SetUp()
	// virtual void TearDown()
	int instance_resource_; // reacreated each test
};

TEST_F(FixtureTest, Test0)
{
	EXPECT_EQ(42, instance_resource_);
}

class SharedTest : public ::testing::Test {
protected:
	static void SetUpTestCase() {
		shared_resource_ = 31;
	}
	static void TearDownTestCase() {
		shared_resource_ = 0;
	}
	static int shared_resource_; // Shared expensive resource
};

int SharedTest::shared_resource_ = -1;

TEST_F(SharedTest, Test1)
{
	EXPECT_THAT(31, shared_resource_);
}
#endif

// parametric

bool IsEven(int n)
{
	return n % 2 == 0;
}


class ParamTest : public ::testing::TestWithParam<int> {
};

TEST_P(ParamTest, IsEven) {
	EXPECT_TRUE(IsEven(GetParam()));
}

INSTANTIATE_TEST_CASE_P(InstantiationName,
	ParamTest,
	::testing::Values(2, 6, 4));

#if 0
// mock

struct Bar {};

class FooInterface {
public:
	virtual ~FooInterface() = default;
	virtual int GetSize() const = 0;
	virtual std::string Describe(const char* name) = 0;
	virtual std::string Describe(int type) = 0;
	virtual bool Process(Bar elem, int count) = 0;
};

class MockFoo : public FooInterface {
public:
	MOCK_CONST_METHOD0(GetSize, int());
	MOCK_METHOD1(Describe, std::string(const char* name));
	MOCK_METHOD1(Describe, std::string(int type));
	MOCK_METHOD2(Process, bool(Bar elem, int count));
};

static std::string MyProductionFunction(FooInterface* foo)
{
	auto siz = foo->GetSize();
	auto s = foo->Describe(5);
	s = foo->Describe(5);
	s = foo->Describe(5);

	return "good";
}

TEST(BarTest, DoesThis) {
	MockFoo foo;
	ON_CALL(foo, GetSize())
		.WillByDefault(::testing::Return(1));
	// ... other default actions ...
	EXPECT_CALL(foo, Describe(5))
		.Times(3)
		.WillRepeatedly(::testing::Return("Category 5"));
	// ... other expectations ...
	EXPECT_EQ("good", MyProductionFunction(&foo));
}
#endif

class Vector2ElemTest : public ::testing::Test {
protected:
	Vector2ElemTest() {
		instance_resource_.push_back(1);
		instance_resource_.push_back(2);
		// inizialization
	}
	//~VectorTest() { delete instance_resource_; }
	// virtual void SetUp()
	// virtual void TearDown()
	std::vector<int> instance_resource_; // reacreated each test
};

TEST_F(Vector2ElemTest, DISABLED_NotEmpty) {
	EXPECT_FALSE(instance_resource_.empty());
	instance_resource_.push_back(3);
}

TEST_F(Vector2ElemTest, Size) {
	EXPECT_EQ(2, instance_resource_.size());
}

TEST(TreeAModel, VectorAddElem)
{
	std::vector<int> v{ 1,2,3 };

	v.push_back(4);

	EXPECT_EQ(4, v.size());
}

