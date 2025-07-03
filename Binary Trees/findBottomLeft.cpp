// LC 513 
// find the bottomost left 


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
    // Approch 1 :
    // This takes up unecessay space by storing a vector 

    // vector<int> ans  ;
    // int maxLevel = INT_MIN ;

    // void helper1(TreeNode *root , int level){
    //     if(root == NULL) return ;
        
    //     if(ans.size() == level) ans.push_back(root->val) ;

    //     helper1(root->left , level+1) ;
    //     helper1(root->right , level+1) ;
    // }

    // Approch 2 :
    // No space is needed here :
    int maxLevel = -1 ;
    int ans = 0 ;

    int findBottomLeftValue(TreeNode* root) {
        // helper1(root , 0 );
        // return ans.back() ;

        helper2(root,0) ;
        return ans ;
    }

    void helper2(TreeNode* root , int level){
        if(root == NULL ) return ;

        if(level > maxLevel){
            ans = root->val ;
            maxLevel = level ;
        }

        helper2(root->left , level+1);
        helper2(root->right , level+1);
    }
};