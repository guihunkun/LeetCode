/*
    C++的 bitset 在 bitset 头文件中，它是一种类似数组的结构，它的每一个元素只能是０或１，每个元素仅用１bit空间。
    
    bitset<128> bits;  //无参构造，长度为 128，默认每一位为 0
    bits.count()       //求bitset中 1 的位数
    bits.test(id)      //检查下标 id 处的元素是 0 还是 1; 是1返回true，是0返回false
    bits.any()     　　//检查bitset中是否有 1
    bits.none()    　　//检查bitset中是否没有 1   
    bits.all()     　　//检查bitset中是全部为 1
    bits.flip()  　　  //flip函数不指定参数时，将bitset每一位全部取反
    bits.flip(id)  　　//flip函数指定参数id时，将下标id处"反转", 即 0 变 1, 1 变 0
*/
class Solution 
{
public:
    bool canPermutePalindrome(string s) 
    {
        bitset<128> bits;
        for(char c : s) 
        {
            bits.flip(c);
        }
        return bits.none() || bits.count() == 1;
    }
};
