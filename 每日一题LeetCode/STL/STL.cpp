#include"iostream"
#include"string.h"
#include"queue"
using namespace std;
class Stud
{
	char name[10];
	int score;
	public:
		Stud(char name1[],int score1)
		{
			strcpy(name,name1);
			score=score1;
		}
		void disp()
		{
			cout<<name<<"\t"<<score<<endl;
		}
		bool operator<(const Stud &s) const
		{
			return score>s.score;
		}
};
int main()
{
	priority_queue<Stud> qu;
	Stud st("",0);
	qu.push(Stud("mary",90));
	qu.push(Stud("tom",80));
	while(!qu.empty())
	{
		st=qu.top();
		st.disp();
		qu.pop();
	}
	return 0;
}
