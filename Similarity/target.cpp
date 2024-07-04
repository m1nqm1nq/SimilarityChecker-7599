#include <string>
using namespace std;

class SimilarityChecker
{
public:
    SimilarityChecker()
    {
        for (int idx = 0; idx < ALPHABET; idx++)
        {
            existletterStr1[idx] = false;
            existletterStr2[idx] = false;
        }
    }
    void SetCheckTarget(string Str1, string Str2)
    {
        this->Str1 = Str1;
        this->Str2 = Str2;
        lenStr1 = (int)Str1.length();
        lenStr2 = (int)Str2.length();
    }
    int Check()
    {
        return Check1_Length() + Check2_Alphabet();
    }

    int Check1_Length()
    {
        if (lenStr1 == lenStr2) return SCORE_LENGTH_MAX;
        if (lenStr1 >= lenStr2 * 2) return SCORE_LENGTH_MIN;
        if (lenStr2 >= lenStr1 * 2) return SCORE_LENGTH_MIN;

        int result; // = (1 - (lenLong - lenShort) / lenShort) * 60
        if (lenStr1 >= lenStr2)
        {
            result = (lenStr2 * 2 - lenStr1) * SCORE_LENGTH_MAX / lenStr2;
        }
        else
        {
            result = (lenStr1 * 2 - lenStr2) * SCORE_LENGTH_MAX / lenStr1;
        }

        return result;
    }

    int Check2_Alphabet()
    {
        if (CheckStringEmpty() == true) return 0;
        if (CheckStringHasInvalidLetter() == true) return 0;

        FindExistingLetters();
        return (GetSameLetters() * SCORE_ALPHA_MAX / GetTotalLetters());
    }

private:
    const int SCORE_LENGTH_MAX = 60;
    const int SCORE_LENGTH_MIN = 0;
    const int SCORE_ALPHA_MAX = 40;
    const int SCORE_ALPHA_MIN = 0;
    static const int ALPHABET = 26;
    string Str1;
    string Str2;
    int lenStr1;
    int lenStr2;
    bool existletterStr1[ALPHABET];
    bool existletterStr2[ALPHABET];

    bool CheckStringEmpty()
    {
        if (Str1.empty()) return true;
        if (Str2.empty()) return true;
        return false;
    }

    bool CheckStringHasInvalidLetter()
    {
        for (char ch : Str1)
        {
            if ('A' <= ch && ch <= 'Z') continue;
            return true;
        }
        for (char ch : Str2)
        {
            if ('A' <= ch && ch <= 'Z') continue;
        }
        return false;
    }

    void FindExistingLetters()
    {
        for (char ch : Str1)
        {
            existletterStr1[ch - 'A'] = true;
        }
        for (char ch : Str2)
        {
            existletterStr2[ch - 'A'] = true;
        }
    }

    int GetSameLetters()
    {
        int result = 0;
        for (int i = 0; i < ALPHABET; i++)
        {
            if ((existletterStr1[i] == true) && (existletterStr2[i] == true))
                result++;
        }
        return result;
    }

    int GetTotalLetters()
    {
        int result = 0;
        for (int i = 0; i < ALPHABET; i++)
        {
            if ((existletterStr1[i] == true) || (existletterStr2[i] == true))
                result++;
        }
        return result;
    }
};