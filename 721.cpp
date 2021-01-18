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
        //������ʼ���
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        //���й�ϵ�Ľ�㲢����
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
        //����ÿ����㣬�ҵ�����ڵ㣬Ȼ��emailȫ�ŵ�������ڵ��Ӧ�ļ�����ȥ
        unordered_map<int,unordered_set<string>> dump;
        for(int i=0;i<n;i++){
            int root = find(i);
            for(int j=1;j<A[i].size();j++){
                dump[root].insert(A[i][j]);
            }
        }
        //��Ҫ���ʽ�����
        vector<vector<string>> ans;
        for(auto node:dump){
            vector<string> res;
            int root = node.first;
            string name = A[root][0];
            res.push_back(name);
            for(auto item:node.second){
                res.push_back(item);
            }
            //ע��Ҫ������ΪĬ�����ֳ���С��email������ȫ��
            sort(res.begin(),res.end());
            ans.push_back(res);
        }
        return ans;

    }
};
