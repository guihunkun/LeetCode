/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
        if (node == NULL) {
            return nullptr;
        }
        unordered_map<Node*, Node*> mmp;
        queue<Node*> q;
        q.push(node);
        // bfs遍历所有节点，设置对应的新节点
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();

            auto* nod = new Node();
            nod->val = top->val;
            mmp[top] = nod;
            for (const auto n : top->neighbors) {
                if (mmp.find(n) == mmp.end()) {
                    q.push(n);
                }
            }
        }
        for(auto ite = mmp.begin(); ite != mmp.end(); ++ite)
        {
            for(const auto& n : ite->first->neighbors) {
                ite->second->neighbors.push_back(mmp[n]);
            }
        }

        return mmp[node];
    }
};
