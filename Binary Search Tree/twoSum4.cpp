// Two sum 4 in a BST 
// implemented using BST iterator with a small reverse variable added to get the next and prev element 

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
class BSTiterator{
public:

    stack<TreeNode*> st ;
    bool reverse = true ;

    // constructor :
    // reverse true = push left (for next)
    // reverse false = push right (for prev)
    BSTiterator(TreeNode* root , bool Isreverse){
        reverse = Isreverse ;
        pushall(root) ;
    }

    int next(){
        TreeNode* ans = st.top() ;
        st.pop() ;
        if(reverse) pushall(ans->right) ;
        else pushall(ans->left) ;
        return ans->val ;
    }

    bool hasNext(){
        if(!st.empty()) return true ;
        else return false ;
    }
    
private:
    void pushall(TreeNode* root){
        while(root != NULL){
            st.push(root) ;
            if(reverse) root = root->left ;
            else root = root->right ;
        }
    }
 };

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator nextObj(root, true );
        BSTiterator prevObj(root, false );

        int low = nextObj.next() ;
        int high = prevObj.next() ;

        while(low<high){
            if(low + high == k) return true ;
            else if (low + high < k) low = nextObj.next() ;
            else high = prevObj.next() ;
        }
        return false ;
    }
};