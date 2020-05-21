class Solution 
{
public:
    string predictPartyVictory(string senate) 
    {
        bool R = true, D = true;
        //R,D标记senate中是否还有R,D
	    int person = 0;
        //标记变量person,当person>0时，表示R方可以淘汰D方；person<0时，表示D方可以淘汰R方。
	    while (R&&D)//R\D标记本轮循环中，senate是否存在R\D.（且是淘汰前的序列中）
	    {
		    R = false;
		    D = false;
		    for(int i=0;i<senate.size();i++)
		    {
			    if(senate[i] == 'R')
			    {
				    R = true;
				    if(person < 0)//D方有权淘汰R方
					    senate[i] = '0';
				    person++;//无论有没有D淘汰掉R，person都++。cause有淘汰时，D的淘汰权用掉一次，person++；没有淘汰时，R的淘汰权增加1，person++.
			    }
			    else if(senate[i] == 'D')
			    {
				    D = true;
				    if(person > 0)
					    senate[i] = '0';
				    person--;
			    }
		    }
	    }
	    return person > 0 ? "Radiant" : "Dire";
    }
};
