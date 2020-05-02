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
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
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


class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) 
    {   
        if(quadTree1 ->isLeaf && quadTree2->isLeaf)
        {
            return new Node(quadTree1->val || quadTree2->val, true, NULL, NULL, NULL, NULL);
        }
        else if(quadTree1->isLeaf)
        {
            return quadTree1->val == true ? quadTree1 : quadTree2;
        }
        else if(quadTree2->isLeaf)
        {
            return quadTree2->val == true ? quadTree2 : quadTree1;
        }
        else
        {
            Node* node = new Node(false, false, NULL, NULL, NULL, NULL);
            node->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            node->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            node->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            node->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            //如果四个节点均为叶子节点，且值相等 则合并为一个主节点
            if(node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf 
               && node->topLeft->val == node->topRight->val && node->topLeft->val == node->bottomLeft->val 
               && node->topLeft->val == node->bottomRight->val)
            {
                    node->isLeaf = true;
                    node->val = node->topLeft->val;
                    node->topLeft = node->topRight = node->bottomLeft = node->bottomRight = NULL;
            }
            return node;
        }
    }
};
