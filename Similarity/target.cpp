#include <string>
using namespace std;

class SimilarityChecker
{
public:
    void SetCheckTarget(string A, string B)
    {
        this->A = A;
        this->B = B;
        lenA = (int)A.length();
        lenB = (int)B.length();
    }
    int Check()
    {
        return Check1_Length() + Check2_Alphabet();
    }

    int Check1_Length()
    {
        if (lenA == lenB) return 60;
        if (lenA == 0 || lenB == 0) return 0; // Avoid Divide By zero

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

    int Check2_Alphabet()
    {
        return 0;
    }

private:
    string A;
    string B;
    int lenA;
    int lenB;
};