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
        int lenA = A.length();
        int lenB = B.length();
        if (lenA == lenB) return 60;
        if (lenA == 0 || lenB == 0) return 0;

        int result; // = (1 - (lenLong - lenShort) / lenShort) * 60
        if (lenA >= lenB)
        {
            result = (lenB * 2 - lenA) * 60 / lenB;
        }
        else
        {
            result = (lenA * 2 - lenB) * 60 / lenA;
        }

        if (result < 0) return 0;
        return result;
    }

    int Check2_Alphabet(string A, string B)
    {
        return 0;
    }
};