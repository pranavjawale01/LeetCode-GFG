class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq; 
        pq.push({0, 0});
        pq.push({0, firstPerson});
        
        vector<bool> visited(n, false);
        
        while(!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();
            
            if(visited[person] == true) {
                continue;
            }
            visited[person] = true;
            
            for(auto& ngbr : adj[person]) {
                int nextPerson = ngbr.first;
                int t          = ngbr.second;
                
                if(t >= time && !visited[nextPerson]) {
                    pq.push({t, nextPerson});
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(visited[i] == true) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

// class Solution {
// public:
//     typedef pair<int, int> P;
    
//     void dfs(int person, int time, unordered_map<int, vector<P>>& adj, vector<int>& earlySecretTime) {
//         for(auto& ngbr : adj[person]) {
//             int nextPerson = ngbr.first;
//             int t          = ngbr.second;

//             if(t >= time && earlySecretTime[nextPerson] > t) {
//                 earlySecretTime[nextPerson] = t;
//                 dfs(nextPerson, t, adj, earlySecretTime);
//             }
//         }
//     }
    
//     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
//         unordered_map<int, vector<P>> adj;
        
//         for(vector<int>& meeting : meetings) {
//             int person1 = meeting[0];
//             int person2 = meeting[1];
//             int time    = meeting[2];
            
//             adj[person1].push_back({person2, time});
//             adj[person2].push_back({person1, time});
//         }

//         vector<int> earlySecretTime(n, INT_MAX);
//         earlySecretTime[0] = 0;
//         earlySecretTime[firstPerson] = 0;

//         dfs(0, 0, adj, earlySecretTime);
//         dfs(firstPerson, 0, adj, earlySecretTime);

//         vector<int> result;
//         for(int i = 0; i < n; i++) {
//             if(earlySecretTime[i] != INT_MAX) {
//                 result.push_back(i);
//             }
//         }
        
//         return result;
//     }
// };

// // class Solution {
// // public:
// //     typedef pair<int, int> P;
// //     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
// //         unordered_map<int, vector<P>> adj;
        
// //         for(vector<int>& meeting : meetings) {
// //             int person1 = meeting[0];
// //             int person2 = meeting[1];
// //             int time    = meeting[2];
            
// //             adj[person1].push_back({person2, time});
// //             adj[person2].push_back({person1, time});
// //         }
        
// //         queue<P> que;
// //         que.push({0, 0});
// //         que.push({firstPerson, 0});
// //         vector<int> earlySecretTime(n, INT_MAX);
// //         earlySecretTime[0] = 0;
// //         earlySecretTime[firstPerson] = 0;
        
// //         while(!que.empty()) {
// //             auto [person, time] = que.front();
            
// //             que.pop();
            
// //             for(auto& ngbr : adj[person]) {
// //                 int nextPerson = ngbr.first;
// //                 int t          = ngbr.second;
                
// //                 if(t >= time && earlySecretTime[nextPerson] > t) {
// //                     earlySecretTime[nextPerson] = t;
// //                     que.push({nextPerson, t});
// //                 }
// //             }
// //         }
        
// //         vector<int> result;
// //         for(int i = 0; i < n; i++) {
// //             if(earlySecretTime[i] != INT_MAX) {
// //                 result.push_back(i);
// //             }
// //         }
        
// //         return result;
// //     }
// // };

// // // class Solution {
// // // public:
// // //     typedef pair<int, int> P;
// // //     vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
// // //         map<int, vector<P>> timeMeetings;
// // //         for (vector<int>& meeting: meetings) {
// // //             int person1 = meeting[0];
// // //             int person2 = meeting[1];
// // //             int time = meeting[2];
// // //             timeMeetings[time].push_back({person1, person2});
// // //         }

// // //         vector<bool> knowsSecret(n, false);
// // //         knowsSecret[0] = true;
// // //         knowsSecret[firstPerson] = true;

// // //         for (auto &it : timeMeetings) {
// // //             int t= it.first;
// // //             vector<P> meets = it.second;

// // //             unordered_map<int, vector<int>> adj;
// // //             queue<int> que;
// // //             unordered_set<int> alreadyAdded;

// // //             for (auto & [person1, person2] : meets) {
// // //                 adj[person1].push_back(person2);
// // //                 adj[person2].push_back(person1);

// // //                 if (knowsSecret[person1] == true && alreadyAdded.find(person1) == alreadyAdded.end()) {
// // //                     que.push(person1);
// // //                     alreadyAdded.insert(person1);
// // //                 }
// // //                 if (knowsSecret[person2] == true && alreadyAdded.find(person2) == alreadyAdded.end()) {
// // //                     que.push(person2);
// // //                     alreadyAdded.insert(person2);
// // //                 }
// // //             }

// // //             while (!que.empty()) {
// // //                 int person = que.front();
// // //                 que.pop();
// // //                 for (auto& nextperson : adj[person]) {
// // //                     if (knowsSecret[nextperson] == false) {
// // //                         knowsSecret[nextperson] = true;
// // //                         que.push(nextperson);
// // //                     }
// // //                 }
// // //             }
// // //         }
// // //         vector<int> result;
// // //         for (int i = 0; i < n; i++) {
// // //             if (knowsSecret[i] == true) {
// // //                 result.push_back(i);
// // //             }
// // //         }
// // //         return result;
// // //     }
// // // };