class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        visited.resize(n+1,false);
        res.resize(2*(n-1)+1,0);
        back_track(0);
        return res;
    }
    
    vector<int> res;
    vector<bool> visited;

    bool back_track(int pos) {
        int n=visited.size()-1;
        if (pos>=res.size())    return true;
        if (res[pos]!=0)    return back_track(pos+1);
        for (int i=n;i>=1;i--) {
            if (visited[i]) continue;
            if (i==1)   {
                visited[1]=true;
                res[pos] = 1;
                if (back_track(pos+1))  return true;
                visited[1]=false;
                res[pos] = 0;
                return false;
            }
            else {
                if (pos+i>=res.size())  continue;
                if (res[pos+i]!=0)  continue;
                res[pos]=i;res[pos+i]=i;
                visited[i] = true;
                if (back_track(pos+1))  return true;
                res[pos]=0;res[pos+i]=0;
                visited[i] = false;
            }
        }
        return false;
    }
}; 
