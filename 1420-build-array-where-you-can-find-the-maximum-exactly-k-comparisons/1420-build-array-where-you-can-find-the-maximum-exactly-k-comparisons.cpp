class Solution {
public:
    int N;
    int M;
    int K;
    int MOD = 1e9 + 7;
    int t[51][51][101];
    int solve(int indx , int search_cost , int maximum_value){
       
        
        if(indx == N){
            if(search_cost == K){
                return 1;
            }
            else {
                return 0;
            }

        }
        if(maximum_value != -1 && t[indx][search_cost][maximum_value] != -1){
            return t[indx][search_cost][maximum_value];
        }

        int result = 0;
        for(int i = 1 ; i <= M ; i++){
            if(i > maximum_value){
                result += solve(indx+1,search_cost+1,i);
            }
            else {
                result += solve(indx+1,search_cost,maximum_value);
            }
            result %= MOD;
        }
        if(maximum_value != -1){
            t[indx][search_cost][maximum_value] = result;
        }
        return result;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t,-1,sizeof(t));
        return solve(0,0,-1);
    }
};