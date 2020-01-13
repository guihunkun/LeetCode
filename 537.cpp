class Solution 
{
public:
    string complexNumberMultiply(string a, string b) 
    {
        // 切割出实部和虚部
        vector<string> as;
        stringstream ss(a);
        string tmp;
        while (getline(ss, tmp, '+')) as.push_back(tmp);
        as[1].erase(as[1].end() - 1);
        vector<string> bs;
        stringstream ss2(b);
        while (getline(ss2, tmp, '+')) bs.push_back(tmp);
        bs[1].erase(bs[1].end() - 1);
        // 转成int然后计算
        int a_real = stoi(as[0]);
        int a_img = stoi(as[1]);
        int b_real = stoi(bs[0]);
        int b_img = stoi(bs[1]);

        return to_string(a_real * b_real - a_img * b_img) + "+" + to_string(a_real * b_img + a_img * b_real) +"i";
    }
};
