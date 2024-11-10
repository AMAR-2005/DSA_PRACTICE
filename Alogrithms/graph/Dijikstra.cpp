#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // For INT_MAX
using namespace std;

int main() {
    int v = 5;
    vector<pair<int, int> > adj[v];  // Space added between >
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            int el;
            cin >> el;
            if (el != 0) {
                adj[i].push_back(make_pair(j, el));
            }
        }
    }

    int s;
    cin >> s;
    vector<int> dis(v, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, s));
    dis[s] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto x : adj[node]) {
            int ve = x.first;
            int w = x.second;
            if (d + w < dis[ve]) {
                dis[ve] = d + w;
                pq.push(make_pair(d+w, ve));
            }
        }
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < v; i++) {
        printf("%d\t\t%d\n", i, dis[i]);
    }

    return 0;
}
/*
0 4 0 0 0 
4 0 8 0 0
0 8 0 7 0
0 0 7 0 9
0 0 0 9 0

0
*/