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
    int ans = INT_MIN ;
    int maxPathSum(TreeNode* root) {
        helper(root) ;
        return ans ;
    }

    int helper(TreeNode* root){
        if(root == NULL) return 0 ;

        int leftSum = helper(root->left) ;
        if(leftSum < 0) leftSum = 0 ;
        int rightSum = helper(root->right) ;
        if(rightSum < 0) rightSum = 0 ;

        ans = max(ans , root->val + leftSum + rightSum) ;

        return root->val + max(leftSum,rightSum) ;
    }
};