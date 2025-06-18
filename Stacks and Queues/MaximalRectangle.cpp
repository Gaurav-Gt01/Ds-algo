// Very good Question on FINDING THE MAXIMAL AREA OF RECTANGLE IN A GIVEN 2D MATRIX 
// First we find the prefix Sum matrix and the pass each row to the max histogram area function 
// basically we convert each row to histogram 
// Lc - 84 
// TC -> 0(M*N) for the pSum calculation and while finding the max area of hostogram 
// SC -> 0(M*N) needed to store the prefix sum values 



class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        
        // declare a 2D vector to store prefix sum 
        vector<vector<int>> pSum(row, vector<int>(col));
        
        // calclute the pSum matrix 
        for (int j = 0; j < col; j++) {
            int sum = 0;  
            for (int i = 0; i < row; i++) {
                if (matrix[i][j] == '0') {
                    sum = 0;
                } else {
                    // converted from char to int
                    sum += (matrix[i][j] - '0'); 
                }
                pSum[i][j] = sum;
            }
        }

        // calculate the max Area of the hostogram 
        int ans = 0;
        for (int i = 0; i < row; i++) {
            ans = max(maxHistogram(pSum[i]), ans);
        }

        return ans;
    }

    int maxHistogram(vector<int> mat) {  
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < mat.size(); i++) {
            while (!st.empty() && mat[st.top()] > mat[i]) {
                int index = st.top();
                st.pop();
                int nse = i;
                // if empty then -1 if not then st.top()
                int pse = st.empty() ? -1 : st.top();  

                int area = mat[index] * (nse - pse - 1);
                ans = max(area, ans);
            }
            st.push(i);
        }


        while (!st.empty()) {
            int nse = mat.size();
            int index = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();

            int area = mat[index] * (nse - pse - 1);
            ans = max(area, ans);
        }

        return ans;
    }
};