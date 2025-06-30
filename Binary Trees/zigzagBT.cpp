// LC - 103
// TC and SC = 0(N) ;

// Two approches are written below one with using a reverse function and one without using a reverse function .

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
    // vector<int> reverseVector(vector<int> nums){
    //     int l = 0 ;
    //     int r = nums.size() - 1 ;

    //     while(l<r){
    //         int temp = nums[l] ;
    //         nums[l] = nums[r] ;
    //         nums[r] = temp ;

    //         l++ ;
    //         r-- ;
    //     }
    //     return nums ;
    // }


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        queue<TreeNode*> q ;
        if(root == NULL) return ans ;
        q.push(root) ;
        int flag = 0 ; // flag 0 = L->R , flag 1 = R->L

        while(!q.empty()){
            int size = q.size() ;
            vector<int> level(size) ;

            for(int i = 0 ; i<size ;i++){
                if(q.front()->left != NULL) q.push(q.front()->left) ;
                if(q.front()->right != NULL) q.push(q.front()->right) ;
                if(flag == 1){
                    int index = size - i - 1 ;
                    level[index] = q.front()->val ;
                }else{
                    int index = i ;
                    level[index] = q.front()->val ;
                }
                //level.push_back(q.front()->val) ;
                q.pop() ;
            }
            if(flag == 1 ){
                //ans.push_back(reverseVector(level)) ;
                flag = 0 ;
            }
            else{
                //ans.push_back(level) ;
                flag = 1 ;
            }
            ans.push_back(level) ;
        }
        return ans ;
    }
};