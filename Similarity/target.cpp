#include <string>
using namespace std;

class SimilarityChecker
{
public:
    int Check(string A, string B)
    {
        return Check1_Length(A, B) + Check2_Alphabet(A, B);
    }

    int Check1_Length(string A, string B)
    {
        return 0;
    }

    int Check2_Alphabet(string A, string B)
    {
        return 0;
    }
};