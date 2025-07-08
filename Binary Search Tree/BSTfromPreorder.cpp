//LC 173 
// something like a monotonic stack 

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
class BSTIterator {
public:
    stack<TreeNode*> st ;
    BSTIterator(TreeNode* root) {
        addleft(root) ;
    }
    
    int next() {
        TreeNode* ans = st.top() ;
        st.pop() ;
        addleft(ans->right) ;
        return ans->val ;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false ;
    }

    void addleft(TreeNode* node){
        while(node != NULL){
            st.push(node);
            node = node->left ;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */