//LC 1008 
// Construct a BST from Preorder Traversal 

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0 ;
        return build(preorder , i , INT_MAX) ;
    }

    TreeNode* build(vector<int> preorder , int &i , int bound){
        //base condition 
        if(preorder.size() == i || preorder[i] > bound) return NULL ;

        // create a new Node
        TreeNode* root = new TreeNode(preorder[i]) ;
        i++ ;
        root->left = build(preorder , i , root->val) ;
        root->right = build(preorder , i , bound) ; 
        return root ;
    }
};