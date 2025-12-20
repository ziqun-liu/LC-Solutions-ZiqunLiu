## Assumption

​	Graph `G`, number of vertices `n`, number of edges `m`. 

​	For connected graphs, there is m >= n such that O(m + n) = O(n).

## Relax Edges

```pseudocode
relax(u, v) {
    if (dist[u] + weight(u, v) < dist[v]) {
        dist[v] = dist[u] + weight(u, v);
        pi[v] = u;
    }
}
```



## Algo 1: Single Source Shortest Path - Shortest Path on DAG

有向无环图的每条边 (u, v)，在拓扑序中，u 一定出现在 v 之前。

At the time of processing v, all incoming dependencies that impact the shortest path of v have been evaluated.

```pseudocode
SP_on_DAG(G, source) {
	topo_order = topological_sort(G);
    dist = {};
    dist[source] = 0;

    for (u in topo_order) {
        for (v in G.neighbors(u))
            relax(u, v);
    }
            
	return dist
}
```

Running time O(m + n), space O(n)

## Algo 2: SSSP - Dijkstra

Note: In a dense graph, O(E) = O(V^2).

```pseudocode
dijkstra(G, s) { //  both sparse and dense graph
	dist = []; // length n, all initalized to infinity
	dist[s] = 0;
	N = {}; // N is a set
	
	while (|N| != n) {
		// Get smallest dist node
		min_dist = inf, u = 0;
		for (i = 1...n) {
			if (!N.contains(i) && dist[i] < min_dist) {
				min_dist = dist[u];
				u = i;
			}
		}
		
		// Add to set
		N = N.insert(u);
		
		// Relax
		for (v in G.neighbors(u)) {
			relax(u, v);
		}
	}
	
	return dist;
}
```

```pseudocode
	dijkstra(G, s) { // sparse graph 
        dist = []; // length n, all initalized to infinity
        dist[s] = 0;
        heap = [(0, s)]; // min heap (dist, node)
        for (v in G.neighbors(s)) {
        	if (v != s)
        		heap.push((w(s, v), v));
        }
        
        while (!heap.empty()) {
        	d, u = heap.pop();
        	
        	if (dist[u] < d)
        		continue;
        		
            // Relax
            for (v in G.neighbors(u)) {
                if (dist[u] + weight(u, v) < dist[v]) {
                    dist[v] = dist[u] + weight(u, v);
                    heap.push((dist[v], v));
                }
            }
        }
        
        return dist;
    }
```

Drawback: does not work if there are negative weights.

Time O((m + n) lg n) = Theta(m lg n) using minimum heap, O(n^2) using array

Space O(m + n)

## Algo 3: SSSP - Bellman-Ford

```python
bellman_ford(G, s) {
    dist = []; // length n, all initalized to infinity
    dist[s] = 0;
    
    # Relax n - 1 times
    for (i = 1 ... n - 1) { // O(n)
        for (u = 1 ... n) { // All edges so O(m)
            for (v in G.neighbors(u)) {
                relax(u, v)
	        }
        }
    }
            
    # Relax the n-th time
    for (u = 1 ... n) { // O(m)
        for (v in G.neighbors(u)) {
            if dist[u] + weight < dist[v]:
                // There is negatively weighted cycle
        }
    }
    
    return dist
}
```

​	Total running time O(m n). For complete graphs where m = n^2, running time will be O(n^3).

​	Works on negative weights but does not work when there are negatively weighted cycles. Graphs that have negatively weighted cycles usually do not consider shortest paths.

## Algo 4: All Pair Shortest Path - Floyd Warshall

```pseudocode
FW(G) {
	A = [][]; // adjacency matrix
	
	for (k = 1 ... n) {
		for (u = 1 ... n) {
			for (v = 1 ... n) {
				A[u, v] = min(A[u, v], A[u, k] + A[k, v]);
			}
		}
	}
	
	for (u = 1 ... n) {
		if (A[u][u] < 0) {
			// Negatively weighted cycle found!
		}
	}
	
	return A;
}
```

Running time is O(n^3) regardless of sparse or dense

Can detect negatively weighted cycle.

If there is no negatively weighted cycle, can use Dijkstra n times => Theta(n m lg n) < Theta (n^3).



## All Pair Shortest Path

```python
#Dijkstra
def all_pairs_shortest_paths_dijkstra(
	n: int,
    edges: List[List[int]],
    directed: bool = False
) -> List[List[int]]:

    adj = [[] for _ in range(n)]
    for u, v, weight in edges:
        adj[u].append((v, weight))
        if directed:
            adj[v].append((u, weight))
            
	distance_matrix = [[float("inf")] * n for _ in range(n)]
    
    for src in range(n):  # n running time
        distance = [float("inf")] * n
        distance[src] = 0
        heap = [(0, src)]  # (dist, node)
        
        while heap:  # m lg n running time, in dense graph O(n^2 lg n)
            dist, u = heapq.heappop(heap)
            
            if dist > distance[u]:
                continue
                
			for v, w in adj[u]:
                if dist + w < distance[v]:
                    distance[v] = dist + w
                    heapq.heappuhs(heap, (dist + w, v))

            distance_matrix[src] = distance
            
	return distance_matrix

	# sparse graph m = O(n) => O(mn lg n) = O(n^2 lg n) running time
    # dense graph O(n^3 lg n) r.t.
```













