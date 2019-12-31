class Solution 
{
public:
    bool isRoratedDigit(int num)
    {
        vector<int> rec;
        int nu = num;
        while(nu)
        {
            int a = nu%10;
            if(a == 3 || a == 4 || a == 7)
                return false;
            else
                rec.push_back(a);
            nu /= 10;
        }
        int tar = 0;
        for(int i = rec.size() - 1; i >= 0; i--)
        {
            switch(rec[i])
            {
                case 0:
                    tar  = tar*10+rec[i];
                    break;
                case 1:
                    tar  = tar*10+rec[i];
                    break;
                case 2:
                    tar  = tar*10+5;
                    break;
                case 5:
                    tar  = tar*10+2;
                    break;
                case 6:
                    tar  = tar*10+9;
                    break;
                case 8:
                    tar  = tar*10+rec[i];
                    break;
                case 9:
                    tar  = tar*10+6;
                    break;
            }
        }
        if(num == tar)
            return false;
        else
            return true;
    }
    int rotatedDigits(int N) 
    {
        int res = 0;
        for(int i = 1; i <= N; i++)
        {
            if(isRoratedDigit(i))
            {
                res++;
            }
        }
        return res;
    }
};
