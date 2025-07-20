class Solution {
public:
    #define vi vector<int>
    #define all(x) x.begin(), x.end()
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        if (k == 1) return s == t;
        int chunk = n / k;
        vector<string> sChunk(k), tChunk(k);        
        for (int i = 0; i < k; i++) {
            sChunk[i] = s.substr(i * chunk, chunk);
            tChunk[i] = t.substr(i * chunk, chunk);
        }
        sort(all(sChunk));
        sort(all(tChunk));
        return sChunk == tChunk;
    }
};