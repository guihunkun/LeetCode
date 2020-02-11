class Solution 
{
public:
    bool isScramble(const string& s1, const string& s2) 
    {
        return isScramble(s1.begin(), s1.end(), s2.begin(), s2.end());
    }
    template<typename RandomIt>
    bool isScramble(RandomIt f1, RandomIt l1, RandomIt f2, RandomIt l2) 
    {
        auto p = mismatch(f1, l1, f2, l2);
        if(p.first == l1 && p.second == l2) 
            return true;
        string cp1(f1, l1); sort(cp1.begin(), cp1.end());
        string cp2(f2, l2); sort(cp2.begin(), cp2.end());
        if (cp1 != cp2) 
            return false;
        for (int i = 1; i < distance(f1, l1); ++i) 
        {
            auto m1 = next(f1, i);
            auto m2 = next(f2, i);
            auto n2 = prev(l2, i);
            if (isScramble(f1, m1, f2, m2) && isScramble(m1, l1, m2, l2))
                return true;
            if (isScramble(f1, m1, n2, l2) && isScramble(m1, l1, f2, n2))
                return true;
        }
        return false;
    }
};
