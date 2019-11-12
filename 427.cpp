/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution 
{
    Node* buildTree(int x, int y, int size, auto M) 
    {
        bool flag[2] = {false, false};
        Node* root = new Node(false, false, NULL, NULL, NULL, NULL);
        
        for(int i=x; i<x+size; i++) for(int j=y; j<y+size; j++) flag[M[i][j]] = true;

        if(flag[0] ^ flag[1]) root->isLeaf = true, root->val = flag[1];
        else {
            int s = size>>1;
            root->topLeft = buildTree(x, y, s, M);
            root->topRight = buildTree(x, y+s, s, M);
            root->bottomLeft = buildTree(x+s, y, s, M);
            root->bottomRight = buildTree(x+s, y+s, s, M);
        }
        
        return root;
    }
    
public:
    Node* construct(vector<vector<int>>& grid) 
    {
        return buildTree(0, 0, grid.size(), grid);
    }
};
