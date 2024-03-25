#include<stdio.h>
#include<stdlib.h>
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


int main() {
    int n = 3; // Number of nodes
    int flightsSize = 3; // Number of flights
    int src = 0, dst = 2, K = 1;
    int flights[3][3] = {{0,1,100},{1,2,100},{0,2,500}};
    int* flightsColSize = &flights[0][1]; // Not used

    int result = findCheapestPrice(n, (int**)flights, flightsSize, flightsColSize, src, dst, K);

    printf("Cheapest price from %d to %d with at most %d stops: %d\n", src, dst, K, result);

    return 0;
}
