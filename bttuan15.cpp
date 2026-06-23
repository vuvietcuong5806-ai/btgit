#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

class Graph {
private:
    vector<string> names;
    unordered_map<string, int> nodeId;
    vector<vector<pair<int, int>>> adj;

public:
    int getOrAddNode(const string& name) {
        if (nodeId.count(name))
            return nodeId[name];

        int id = names.size();
        nodeId[name] = id;
        names.push_back(name);
        adj.push_back(vector<pair<int, int>>());

        return id;
    }

    void addEdge(const string& src, const string& dest, int weight) {
        int u = getOrAddNode(src);
        int v = getOrAddNode(dest);

        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); 
    }
