class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int,int>>st;
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(matrix[i][j] == 0){
                    st.insert({i,j});
                }
            }
        }

        for(auto it : st){
            int x = it.first;
            int y = it.second;
            for(int i = 0 ; i < row ; i++){
                matrix[i][y] = 0;
            }
            for(int j = 0 ; j < col ; j++){
                matrix[x][j] = 0;
            }
        }
    }
};