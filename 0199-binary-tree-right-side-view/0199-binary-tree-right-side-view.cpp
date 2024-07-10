/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* node,int level,vector<int>& res){
        if(node == NULL) return;
        if(res.size() == level){
            res.push_back(node->val);
        }
        helper(node->right,level+1,res);
        helper(node->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;
    }
};