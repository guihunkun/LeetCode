
class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> res;
		for(int n : asteroids) 
        {
			while(true)
            {
				// 若满足以下三个条件，直接将遍历到的n，push到辅助数组中。
				if(res.size() == 0 || res.back() < 0 || n > 0) 
                {
					res.push_back(n);
					break;
				}
				// 若满足以下条件，说明新来的这个行星被撞爆了。
				else if(abs(n) < res.back()) 
                {
					break;
				}
				// 若满足以下条件，说明新来的这个行星和最靠右的行星都被撞爆了。
				else if(abs(n) == res.back()) 
                {
					res.pop_back();
					break;
				}
				// 若满足以下条件，说明新来的这个行星把最靠右的行星给撞爆了，所以不能跳出循环，直到这个新加进来的行星被撞爆，或者不会发生碰撞为止。
				else 
                {
					res.pop_back();
				}
			}
		}
		return res;
    }
};
