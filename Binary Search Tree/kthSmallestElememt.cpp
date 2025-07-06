// LC 230 

// finding the kth smallest element 
// intution - do a preorder traversal in a bst 

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
    vector<int> nodeValues ;
    int cnt = 0 ;
    int ans = 0 ;

    int kthSmallest(TreeNode* root, int k) {

        helper(root , k) ;
        return ans ;
    }

    void helper(TreeNode* root , int k){
        if(root == NULL) return ;

        helper(root->left , k) ;

        cnt++ ;
        if(cnt == k){
            ans = root->val ;
            return ;
        }
        helper(root->right, k ) ;
    }
};