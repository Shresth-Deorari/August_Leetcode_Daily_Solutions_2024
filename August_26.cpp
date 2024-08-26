/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void f(Node * root,vector<int>&post){
        if(root == NULL)return;
        for(auto i : root->children){
            f(i,post);
        }
        post.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int>post;
        f(root,post);
        return post;
    }
};