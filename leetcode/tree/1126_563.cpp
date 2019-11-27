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
    int traverse(TreeNode* root, int& res){
        if(root == NULL)
            return 0;
        int left = traverse(root -> left, res);
        int right = traverse(root -> right, res);
        res += abs(left - right);
        return (left + right + root -> val);
    }
    int findTilt(TreeNode* root) {
        int res = 0;
        traverse(root, res);
        return res;
    }
};
