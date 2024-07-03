#include "pch.h"
#include "../Similarity/target.cpp"

#include <string>
using namespace std;

TEST(TsSimilarity, TcCheck1LengthIsEmptyBoth)
{
    SimilarityChecker sc;
    EXPECT_EQ(sc.Check1_Length("", ""), 60);
}

TEST(TsSimilarity, TcCheck1LengthIsEmpty1)
{
    SimilarityChecker sc;
    EXPECT_EQ(sc.Check1_Length("ABC", ""), 0);
}

TEST(TsSimilarity, TcCheck1LengthIsDiff1)
{
    SimilarityChecker sc;
    EXPECT_EQ(sc.Check1_Length("ABC", "A"), 0);
}

TEST(TsSimilarity, TcCheck1LengthIsDiff2)
{
    SimilarityChecker sc;
    EXPECT_EQ(sc.Check1_Length("ABC", "AB"), 30);
}

TEST(TsSimilarity, TcCheck1LengthIsDiff3)
{
    SimilarityChecker sc;
    EXPECT_EQ(sc.Check1_Length("ABC", "ABCDE"), 20);
}

TEST(TsSimilarity, TcCheck1LengthIsDiff4)
{
    SimilarityChecker sc;
    EXPECT_EQ(sc.Check1_Length("ABCEFGHIJKLMN", "ABCDEFGHIJKL"), 55);
}