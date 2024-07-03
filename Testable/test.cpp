#include "pch.h"
#include "../Similarity/target.cpp"

#include <string>
using namespace std;

class SimCheckFixture : public testing::Test
{
private:
    SimilarityChecker sc;
public:
    void SetCheckTarget(string A, string B)
    {
        sc.SetCheckTarget(A, B);
    }
    void Check1LengthIsExpectedTo(int Expected)
    {
        EXPECT_EQ(sc.Check1_Length(), Expected);
    }
};

TEST_F(SimCheckFixture, TcCheck1LengthIsEmptyBoth)
{
    SetCheckTarget("", "");
    Check1LengthIsExpectedTo(60);
}

TEST_F(SimCheckFixture, TcCheck1LengthIsEmpty1)
{
    SetCheckTarget("ABC", "");
    Check1LengthIsExpectedTo(0);
}

TEST_F(SimCheckFixture, TcCheck1LengthIsDiff1)
{
    SetCheckTarget("ABC", "A");
    Check1LengthIsExpectedTo(0);
}

TEST_F(SimCheckFixture, TcCheck1LengthIsDiff2)
{
    SetCheckTarget("ABC", "AB");
    Check1LengthIsExpectedTo(30);
}

TEST_F(SimCheckFixture, TcCheck1LengthIsDiff3)
{
    SetCheckTarget("ABC", "ABCDE");
    Check1LengthIsExpectedTo(20);
}

TEST_F(SimCheckFixture, TcCheck1LengthIsDiff4)
{
    SetCheckTarget("ABCEFGHIJKLMN", "ABCDEFGHIJKL");
    Check1LengthIsExpectedTo(55);
}

TEST_F(SimCheckFixture, TcCheck1LengthIsSame)
{
    SetCheckTarget("ZSDFASGRSRG", "ABCDFGHIJKL");
    Check1LengthIsExpectedTo(60);
}