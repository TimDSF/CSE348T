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
    unordered_map<TreeNode*,int> maxSumToRoot;
    
    int maxPathSum(TreeNode* root) {
        int maxSumKid=root->val;
        int maxSumCross=root->val;
        int maxSumTo=0;
        
        if (root->left!=nullptr){
            maxSumKid=max(maxSumKid,maxPathSum(root->left));
            maxSumCross+=max(0,maxSumToRoot[root->left]);
            maxSumTo=max(0,maxSumToRoot[root->left]);
        }
        if (root->right!=nullptr){
            maxSumKid=max(maxSumKid,maxPathSum(root->right));
            maxSumCross+=max(0,maxSumToRoot[root->right]);
            maxSumTo=max(maxSumTo,maxSumToRoot[root->right]);
        }
        maxSumToRoot[root]=maxSumTo+root->val;
        
        return max(maxSumKid,maxSumCross);
    }
};