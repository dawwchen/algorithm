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
    void traverse(TreeNode* root, vector<int>& count, vector<double>& sum, int depth){
        if(root == NULL)
            return;
        if(depth >= count.size()){
            count.push_back(1);
            sum.push_back(root -> val);
        }
        else{
            count[depth] ++;
            sum[depth] += root -> val;
        }
        traverse(root -> left, count, sum, depth + 1);
        traverse(root -> right, count, sum, depth + 1);
        return;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> count;
        vector<double> sum;
        traverse(root, count, sum, 0);
        for(int i = 0; i < count.size(); i ++)
            sum[i] /= count[i];
        return sum;
    }
};
