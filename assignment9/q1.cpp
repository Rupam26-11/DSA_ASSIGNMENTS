#include <iostream>
using namespace std;

const int MAXV = 100;
const int INF  = 1000000000;

class Edge {
public:
    int u, v, w;
};

class Graph {
public:
    int n;
    int adj[MAXV][MAXV];

    void init(int vertices) {
        n = vertices;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    adj[i][j] = 0;
                else
                    adj[i][j] = INF;
            }
        }
    }

    void addEdge(int u, int v, int w) {
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }

    void BFS(int start) {
        int visited[MAXV];
        int q[MAXV];
        int front = 0, rear = 0;

        for (int i = 0; i < n; i++)
            visited[i] = 0;

        visited[start] = 1;
        q[rear++] = start;

        cout << "BFS: ";
        while (front < rear) {
            int u = q[front++];
            cout << u << " ";
            for (int v = 0; v < n; v++) {
                if (adj[u][v] != INF && u != v && !visited[v]) {
                    visited[v] = 1;
                    q[rear++] = v;
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int u, int visited[]) {
        visited[u] = 1;
        cout << u << " ";
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != INF && u != v && !visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

    void DFS(int start) {
        int visited[MAXV];
        for (int i = 0; i < n; i++)
            visited[i] = 0;

        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    int findSet(int v, int parent[]) {
        if (parent[v] == v) return v;
        return parent[v] = findSet(parent[v], parent);
    }

    void unionSet(int a, int b, int parent[]) {
        a = findSet(a, parent);
        b = findSet(b, parent);
        if (a != b) parent[b] = a;
    }

    void Kruskal() {
        Edge edges[MAXV * MAXV];
        int edgeCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (adj[i][j] != INF && adj[i][j] != 0) {
                    edges[edgeCount].u = i;
                    edges[edgeCount].v = j;
                    edges[edgeCount].w = adj[i][j];
                    edgeCount++;
                }
            }
        }

        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = i + 1; j < edgeCount; j++) {
                if (edges[j].w < edges[i].w) {
                    Edge temp = edges[i];
                    edges[i] = edges[j];
                    edges[j] = temp;
                }
            }
        }

        int parent[MAXV];
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int mstWeight = 0;
        cout << "Kruskal MST edges:\n";
        for (int i = 0; i < edgeCount; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            if (findSet(u, parent) != findSet(v, parent)) {
                cout << u << " - " << v << " (w = " << w << ")\n";
                mstWeight += w;
                unionSet(u, v, parent);
            }
        }
        cout << "Total MST weight (Kruskal): " << mstWeight << endl;
    }

    void Prim(int start) {
        int key[MAXV];
        int parent[MAXV];
        int inMST[MAXV];

        for (int i = 0; i < n; i++) {
            key[i] = INF;
            parent[i] = -1;
            inMST[i] = 0;
        }

        key[start] = 0;

        for (int count = 0; count < n - 1; count++) {
            int u = -1;
            int minKey = INF;
            for (int v = 0; v < n; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }
            if (u == -1) break;
            inMST[u] = 1;

            for (int v = 0; v < n; v++) {
                if (adj[u][v] != INF && adj[u][v] != 0 && !inMST[v] && adj[u][v] < key[v]) {
                    key[v] = adj[u][v];
                    parent[v] = u;
                }
            }
        }

        int mstWeight = 0;
        cout << "Prim MST edges:\n";
        for (int v = 0; v < n; v++) {
            if (parent[v] != -1) {
                cout << parent[v] << " - " << v << " (w = " << adj[parent[v]][v] << ")\n";
                mstWeight += adj[parent[v]][v];
            }
        }
        cout << "Total MST weight (Prim): " << mstWeight << endl;
    }

    void Dijkstra(int src) {
        int dist[MAXV];
        int visited[MAXV];

        for (int i = 0; i < n; i++) {
            dist[i] = INF;
            visited[i] = 0;
        }

        dist[src] = 0;

        for (int count = 0; count < n - 1; count++) {
            int u = -1;
            int minDist = INF;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && dist[i] < minDist) {
                    minDist = dist[i];
                    u = i;
                }
            }
            if (u == -1) break;
            visited[u] = 1;

            for (int v = 0; v < n; v++) {
                if (!visited[v] && adj[u][v] != INF && adj[u][v] != 0) {
                    if (dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                    }
                }
            }
        }

        cout << "Dijkstra distances from " << src << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " : ";
            if (dist[i] == INF) cout << "INF";
            else cout << dist[i];
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    int m;
    cout << "Enter number of vertices: ";
    cin >> g.n;
    g.init(g.n);

    cout << "Enter number of edges: ";
    cin >> m;
    cout << "Enter edges as: u v w (0-based)\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    while (true) {
        int ch, start;
        cout << "\n1. BFS\n2. DFS\n3. Kruskal MST\n4. Prim MST\n5. Dijkstra\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if (ch == 6) break;

        switch (ch) {
            case 1:
                cout << "Start vertex: ";
                cin >> start;
                g.BFS(start);
                break;
            case 2:
                cout << "Start vertex: ";
                cin >> start;
                g.DFS(start);
                break;
            case 3:
                g.Kruskal();
                break;
            case 4:
                cout << "Start vertex: ";
                cin >> start;
                g.Prim(start);
                break;
            case 5:
                cout << "Source vertex: ";
                cin >> start;
                g.Dijkstra(start);
                break;
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}
