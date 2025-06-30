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
    int maxDepth(TreeNode* root) {
        
        // Level Order Approch 
        // int ans = 0 ;
        // queue<TreeNode*> q ;
        // if(root == NULL) return 0 ;
        // q.push(root) ;

        // while(!q.empty()){
        //     int size = q.size() ;
        //     vector<int> level ;
        //     for(int i = 0 ; i<size ; i++){
        //         TreeNode* temp = q.front() ;
        //         q.pop() ;
        //         if(temp->left != NULL) q.push(temp->left);
        //         if(temp->right != NULL) q.push(temp->right);
        //         level.push_back(temp->val);
        //     }
        //     ans++ ;
        // }
        // return ans ;

        // Recursive Way 
        if(root == NULL) return 0 ;

        int lh = maxDepth(root->left) ;
        int rh = maxDepth(root->right) ;

        return 1 + max(lh,rh) ;
    }
};