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
    void traverse(TreeNode* root, int x, int y, int depth, int& xDepth, int& yDepth, bool& a){
        if(root == NULL)
            return;
        if(root -> left && root -> right){
            if((root -> left -> val == x && root -> right -> val == y) || (root -> left -> val == y && root -> right -> val == x)) {
            a = true;
            return;
            }
        }
        if(root -> left && root -> left -> val == x)
            xDepth = depth;
        else if(root -> right && root -> right -> val == x)
            xDepth = depth;
        if(root -> left && root -> left -> val == y)
            yDepth = depth;
        else if(root -> right && root -> right -> val == y)
            yDepth = depth;
        if(xDepth && yDepth)
            return;
        traverse(root -> left, x, y, depth + 1, xDepth, yDepth, a);
        traverse(root -> right, x, y, depth + 1, xDepth, yDepth, a);
        return;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false;
        if(root -> val == x || root -> val == y)
            return false;
        int xDepth = 0;
        int yDepth = 0;
        bool a = false;
        traverse(root, x, y, 1, xDepth, yDepth, a);
        cout << xDepth << yDepth << endl;
        if(a == true)
            return false;
        else if(xDepth == yDepth)
            return true;
        else
            return false;
    }
};
