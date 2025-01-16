#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    class BellmanFord {
        static int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
            vector<int> prices(n, INT_MAX);
            prices[src] = 0;

            for (int i = 0; i < k + 1; ++i) {
                vector<int> tempPrices = prices;
                for (const vector<int> &flight: flights) {
                    int source = flight[0], destination = flight[1], price = flight[2];
                    if (prices[source] == INT_MAX) continue;
                    if (prices[source] + price < tempPrices[destination])
                        tempPrices[destination] = prices[source] + price;
                }
                prices = tempPrices;
            }
            return (prices[dst] == INT_MAX) ? -1 : prices[dst];
        } // Time complexity: O(K * N)
          // Space complexity: O(N)
    };

    // Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
    class Dijkstra {
    public:
        static int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
            // 1st step: adjacency list
            vector<vector<pair<int, int>>> adj(n); // O(E) time and space, E is number of edges
            for (const vector<int> &flight: flights)
                adj[flight[0]].emplace_back(flight[1], flight[2]); // O(E * K) time and space
            
//            for (int i = 0; i < adj.size(); i++) {
//                cout << "Flight from city " << i << ":";
//                for (const pair<int, int> &edge: adj[i])
//                    cout << " to " << edge.first << " (price " << edge.second << ")";
//                cout << endl;
//            }

            // 2nd step: priority queue
            // Initialize an array to store the number of stops required to reach a node from the src node
            vector<int> stops(n, INT_MAX); // O(N) space

            // This is how a min-heap pq is created in C++
            // The second parameter is the underlying container, default to vector<int>
            // The third parameter is a comparator, default to functor std::less<T>
            // Since a non-default third parameter is used, the second parameter cannot be omitted although default
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            pq.push({0, src, 0}); // price, node, stops

            // 3rd step: BFS
            while (!pq.empty()) {

                vector<int> top = pq.top();
                pq.pop(); // O(log(E * K)
                int price = top[0], curr = top[1], numOfStops = top[2];

                // We have already encountered a path with a lower cost and fewer stops,
                // or the number of stops exceeds the limit.
                if (numOfStops > stops[curr] || numOfStops > k + 1) continue; // k stops allowed => k + 1 nodes allowed
                if (curr == dst) return price;
                stops[curr] = numOfStops;

                for (auto& [next, toNextPrice] : adj[curr])
                    pq.push({price + toNextPrice, next, numOfStops + 1});
            }
            return -1;
        } // Time complexity O(E * K + N + log(E * K))
          // adjacency list takes O(E * K); stops array takes O(N); priority queue processes E * K elements thus O(log(E * K))

          // Space complexity O(E + N+ E * K)
          // adjacency list takes O(E); stops array takes O(N); priority queue takes O(E * K)
    };
};

int main() {
    Solution solution;
    vector<vector<int>> flights = {
            {0, 1, 100}, // Flight from city 0: to 1 (price 100)
            {1, 2, 100}, // Flight from city 1: to 2 (price 100)
            {2, 0, 100}, // Flight from city 2: to 0 (price 100)
            {1, 3, 600}, // Flight from city 1: to 3 (price 600)
            {2, 3, 200}  // Flight from city 2: to 3 (price 200)
    };
    int src = 0, dst = 3, k = 1;
    Solution::Dijkstra::findCheapestPrice(4, flights, src, dst, k);
    return 0;
}
