/*
    Ideia:
        Usar o algoritmo de Prim, fazendo a distancia do node inicial para todos os outros e adicionando essa distancia na Heap como se fosse uma aresta e assim por diante
*/

class Solution {
public:

    int Distance(int x1, int x2, int y1, int y2){
        int distance = abs(x1 - x2) + abs(y1 - y2);
        return distance;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int total = 0;
        int count = 0;
        vector<int> explored(n, 0);
        explored[0] = 1;
        // MinHeap
        using T = tuple<int, int, int, int>  // Distancia, Node_Final, X_Final, Y_Final
        priority_queue<T, vector<T>, greater<T>> MinHeap;
        
        int i = 0;  // Começando no Node 0
        while(count < n){
            for(int j = 0; j < n; j++){ // Guarda todas as arestas
                int distance = Distance(points[i][0], points[i][1], points[j][0], points[j][1]);    
                if(distance != 0 && explored[j] == 0)   // Se não for ele mesmo e não for visitado
                    MinHeap.push(distance, j, points[j][0], points[j][1]);  // Adiciona no Heap
            }
            auto v = minHeap.top();
            minHeap.pop();
            explored[v[1]]; // Marca como explorado
            total += explored[0];
            count++;
        }
    }
};
