

class Solution {
public:

    const int MAX_COST = 1001;
    const int MAX_TIME = 1001;

    int Dijkstra(vector<vector<vector<int>>>& adj, int start, int end, int maxTime, vector<int>& minCost, vector<int>& minTime){

        int a=-1;
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> MinHeap;
        MinHeap.push({minCost[start], minTime[start], start});
        // MinHeap = custo, tempo, Node

        while(!MinHeap.empty()){

            auto [custo, tempo, Node] = MinHeap.top();
            cout << "Indo para: " << a << " <-- "<<custo<<' ' << tempo<<' ' << Node << '\n';
            MinHeap.pop();
            for(int i = 0; i < adj[Node].size(); i++){   // Para cada Vizinho do Node
                if(adj[Node][i][1] + tempo <= maxTime){   // Garante que não ultrapassa o tempo maximo
                    if(minCost[adj[Node][i][0]] > custo + adj[Node][i][2]){ // Se o Custo do vizinho > custo atual + custo do caminho
                        minCost[adj[Node][i][0]] = custo + adj[Node][i][2];
                        minTime[adj[Node][i][0]] = tempo + adj[Node][i][1];
                        MinHeap.push({minCost[adj[Node][i][0]], minTime[adj[Node][i][0]], adj[Node][i][0]});
                    }
                    else if(minTime[adj[Node][i][0]] > tempo + adj[Node][i][1]){
                        minTime[adj[Node][i][0]] = tempo + adj[Node][i][1];
                        MinHeap.push({minCost[adj[Node][i][0]], minTime[adj[Node][i][0]], adj[Node][i][0]});
                    }
                }
                a = adj[Node][i][0];
            }
        }

        return minCost[end];
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<int> custo(n, MAX_COST);
        vector<int> tempo(n, MAX_TIME);
        
        int e_time, e_start, e_end; // tempo, começo e destino da *Aresta*
        int m = edges.size();

        vector<int> minCost(n, MAX_COST); // No começo o tempo/custo é infinito
        vector<int> minTime(n, MAX_TIME);

        minCost[0] = passingFees[0];    // Preço do nó inicial (unico conhecido no começo)
        minTime[0] = 0;                 // Já começa lá 

        vector<vector<vector<int>>> adj(n);
        for(int i = 0; i < m; i++){
            e_start = edges[i][0];
            e_end = edges[i][1];
            e_time = edges[i][2];
        
            adj[e_start].push_back({e_end, e_time, passingFees[e_end]});
            adj[e_end].push_back({e_start, e_time, passingFees[e_start]}); // Porque é não direcionado
        }
        
        int x = Dijkstra(adj, 0, n-1, maxTime, minCost, minTime);
        if(x != MAX_COST){
            return x;
        }
        return -1;
    }
};
