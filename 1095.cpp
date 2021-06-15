/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    int find_peak(MountainArray &mountainArr)
    {
        int l=0, r=mountainArr.length()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            int m_val=mountainArr.get(m);
            int m_r_val=mountainArr.get(m+1);
            if(m_val<m_r_val)
                l=m+1;
            else
                r=m-1;
        }
        return l;
    }
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int peak=find_peak(mountainArr);
        int l=0, r=peak;
        if(mountainArr.get(l)<=target&&mountainArr.get(r)>=target)
            while(l<=r)
            {
                int m=(l+r)/2;
                int val=mountainArr.get(m);
                if(val==target)
                    return m;
                else if(val<target)
                    l=m+1;
                else
                    r=m-1;
            }
        l=peak;
        r=mountainArr.length()-1;
        if(mountainArr.get(r)<=target&&mountainArr.get(l)>=target)
            while(l<=r)
            {
                int m=(l+r)/2;
                int val=mountainArr.get(m);
                if(val==target)
                    return m;
                else if(val<target)
                    r=m-1;
                else
                    l=m+1;
            }
        return -1;
    }
};
