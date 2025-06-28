vector<int> preorder ;
vector<int> inorder ;
vector<int> postorder ;

void singleTraversal(Node* root){
    stack<pair<Node*,int>> st ;
    if(root == NULL) return ;
    st.push({root , 1}); 

    while(!st.empty()){
        if(st.top().second == 1){
           preorder.push_back(st.top().first->val) ;
           st.top().second++ ;
           if(st.top().first->left != NULL){  
               st.push({st.top().first->left,1});  
           } 
        }
        else if(st.top().second == 2){
            inorder.push_back(st.top().first->val) ;
            st.top().second++ ;
            if(st.top().first->right != NULL){  
                st.push({st.top().first->right,1});  
            } 
        }
        else{
            postorder.push_back(st.top().first->val);  
            st.pop() ;
        }
    }
}