class Solution {
public:
    int ans = 0 ;

    int diameterOfBinaryTree(TreeNode* root) {
        dup = root; 
        height(root);
        return ans;
    }

    int height(TreeNode* rootNode){
        if(rootNode == NULL) return 0 ;

        int lh = height(rootNode->left);
        int rh = height(rootNode->right);

        int len = lh + rh ;

        if(len > ans){
            ans = len ;
        }

        return 1 + max(lh, rh);
    }
};