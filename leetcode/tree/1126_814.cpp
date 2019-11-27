/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool traverse(TreeNode* root){
        if(root == NULL)
            return false;
        bool r = false;
        if(traverse(root -> left) == false)
            root -> left = NULL;
        else
            r = true;
        if(traverse(root -> right) ==  false)
            root -> right = NULL;
        else
            r = true;
        if(root -> val == 1 || r == true)
            return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool res = traverse(root);
        if(res == false)
            return NULL;
        return root;
    }
};
