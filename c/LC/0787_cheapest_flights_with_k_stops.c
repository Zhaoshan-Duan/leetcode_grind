// name: Zhaoshan Duan
// email: duan.zha@northeastern.edu
// Leetcode link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
int min(int a, int b) {
    return (a<b) ? a : b;
}
int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    const int INT_MAX = 1e9;
    int* cur = (int*) malloc(sizeof(int) * n);
    int* next = (int*) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) {
        cur[i] = INT_MAX;
        next[i] = INT_MAX;
    }

    cur[src] = 0;

    int u;
    int v;
    int cost;
    
    int j = 1;
    while(j <= k+1) {
        for(int i = 0; i < flightsSize; i++) {
            u = flights[i][0];
            v = flights[i][1];
            cost = flights[i][2];
            if (cur[u] != INT_MAX) next[v] = min(next[v], cur[u] + cost);
        }
        for (int i = 0; i < n; i++) {
            cur[i] = next[i];
        }
        j++;
    }
    int res = cur[dst];
    free(cur);
    free(next);

    return (res == INT_MAX) ? -1 : res;
}


