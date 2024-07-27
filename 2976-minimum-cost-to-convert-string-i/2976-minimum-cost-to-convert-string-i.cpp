class Solution {
public:
    void floydWarshall(vector<vector<long long>> &arr) {
        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (arr[i][via] < INT_MAX && arr[via][j] < INT_MAX) {
                        arr[i][j] = min(arr[i][j], arr[i][via] + arr[via][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> arr(26, vector<long long>(26, INT_MAX));
        int n = original.size();
        
        for (int i = 0; i < n; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            arr[u][v] = min((long long)cost[i], arr[u][v]);
        }
        
        for (int i = 0; i < 26; i++) {
            arr[i][i] = 0;
        }
        
        floydWarshall(arr);
        
        long long ans = 0;
        n = source.size();
        
        for (int i = 0; i < n; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (arr[u][v] == INT_MAX) {
                return -1;
            }
            ans += arr[u][v];
        }
        return ans;
    }
};