//leetcode
class Solution 
{
private:
    int parent[1001];
    int find(int x){
        while(parent[x] != x){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {
        int n = A.size();
        //建立初始结点
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        //将有关系的结点并起来
        unordered_map<string,int> father;
        for(int i=0;i<n;i++){
            for(int j=1;j<A[i].size();j++){
                if(father.count(A[i][j])){
                    int root = father[A[i][j]];
                    parent[find(root)] = parent[i];
                }else{
                    father[A[i][j]] = i;
                }
            }
        }
        //遍历每个结点，找到其根节点，然后将email全放到这个根节点对应的集合中去
        unordered_map<int,unordered_set<string>> dump;
        for(int i=0;i<n;i++){
            int root = find(i);
            for(int j=1;j<A[i].size();j++){
                dump[root].insert(A[i][j]);
            }
        }
        //按要求格式化输出
        vector<vector<string>> ans;
        for(auto node:dump){
            vector<string> res;
            int root = node.first;
            string name = A[root][0];
            res.push_back(name);
            for(auto item:node.second){
                res.push_back(item);
            }
            //注意要排序，因为默认名字长度小于email，所以全排
            sort(res.begin(),res.end());
            ans.push_back(res);
        }
        return ans;

    }
};
