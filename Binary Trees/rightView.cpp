//lc 199 
// find the right side view 

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
    vector<int> ans ; 

    vector<int> rightSideView(TreeNode* root) {

        // Level order Iterative way 
        // Has higher space complexity as the stack in case of a full binary tree can take a lot of space so an recursive way is better to solve it and keep the code clean  

        // vector<int> ans ;
        // queue<TreeNode*> q ;
        // if(root == NULL) return ans ;
        // q.push(root) ;

        // while(!q.empty()){
        //     int size = q.size() ;
        //     vector<int> level ;
        //     for(int i = 0 ; i<size ; i++){
        //         TreeNode* temp = q.front() ;
        //         q.pop() ;
        //         if(temp->left != NULL) q.push(temp->left) ;
        //         if(temp->right != NULL) q.push(temp->right) ;
        //         level.push_back(temp->val) ;
        //     }
        //     ans.push_back(level[size-1]) ;
        // }
        // return ans ;

        // Recursive way :

        if(root == NULL ) return ans ;
        helper(root,0) ;
        return ans ;
    }

    void helper(TreeNode* root , int level){
        // base case 
        if(root == NULL ) return ;

        if(level == ans.size()) ans.push_back(root->val) ;

        helper(root->right , level+1) ;
        helper(root->left , level+1) ;
    }
};