class Solution 
{
public:
    int dayOfYear(string date) 
    {
        long long num = 0;
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8));
        bool runnian = false;
        if((year%4 == 0 && year%100 != 0) || year%400 == 0 )
        {
            runnian = true;
        }
        num += day;
        month--;
        for(int i= month;i>0;i--)
        {
            switch (i)
            {
                case 1:num += 31;
                   break;
                case 2:
                    if(runnian) 
                    { 
                        num += 29;
                        break;
                    }
                    else 
                    {
                        num += 28;
                        break;
                    }
                case 3:num += 31;
                    break;
                case 4:num += 30;
                    break;
                case 5:num += 31;
                    break;
                case 6:num += 30;
                    break;
                case 7:num += 31;
                    break;
                case 8:num += 31;
                    break;
                case 9:num += 30; 
                   break;
                case 10:num += 31;
                    break;
                case 11:num += 30;
                    break;
            }
        }
        return num;
    }
};
