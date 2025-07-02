//LC 987 
// Finding the vertical order traversal from left to right and top to bottom 
// It is done by maintaining a queue which stores the node the row and the col and a map which stores the row , col and all the node values that are present in that position 
// Then the map is traversed using iterators 


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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Answer Data structure to store the answers 
        vector<vector<int>> ans ; 

        map<int , map<int , multiset<int>>> mpp ;
        // <vertical , < level , multiple nodes at a level>>

        queue<pair<TreeNode* , pair<int , int>>> q ;
        // <Node , <level , vertical>>

        if(root == NULL) return ans ;
        q.push({root ,{0,0}}) ;

        while(!q.empty()){
            int size = q.size() ;
            
            for(int i = 0 ; i<size ; i++){
                // defining the row , col and the node for ease 
                int row = q.front().second.first ;
                int col = q.front().second.second ;
                TreeNode* node = q.front().first ;

                mpp[col][row].insert(q.front().first->val) ;

                if(node->left != NULL) q.push({node->left , {row+1 , col-1 }}) ;
                if(node->right != NULL) q.push({node->right , {row+1 , col+1 }}) ;

                q.pop() ;
            }
        }

        // Starts iterating from the mpp.first that is the vertical 
        for (auto vertical : mpp) {

        // Vector that stores values of each vertical
        vector<int> verticalList;

        // Starts iterating by the rows top to bottom 
        for (auto level : vertical.second) {

            // starts iterating the set in which multiple values are at a particular row , col 
            for (int value : level.second) {
                verticalList.push_back(value);
            }
        }
        // pushes the vertical answer to the ans 
        ans.push_back(verticalList);
        }
        return ans ;
 
    }
};