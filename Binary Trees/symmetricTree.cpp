// LC 101 

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
    bool isSymmetric(TreeNode* root) {
        bool ans = helper(root->left , root->right ) ;
        return ans ;
    }

    bool helper(TreeNode* p , TreeNode* q){
        if(p == NULL || q==NULL){
            return (p==q) ;
        }

        return (p->val == q->val ) && helper(p->left , q->right) && helper(p->right,q->left ) ;
    }
};