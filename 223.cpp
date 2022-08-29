class Solution 
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        int xRight = min(C,G);
        int xLeft = max(A,E);
        int yTop = min(D,H);
        int yBot = max(F,B);
        
        int s = (C-A) * (D-B);
        if (xRight > xLeft && yTop > yBot) {                        
            s -= (xRight - xLeft)*(yTop - yBot); 
        }           
        s += (G-E) * (H-F);
        return s;
    }
};

