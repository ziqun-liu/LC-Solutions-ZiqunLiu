// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// There are n cities numbered from 0 to n-1. Given the array edges 
// where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge 
// between cities from_i and to_i, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

class Solution {
	public int findTheCity(int n, int[][] edges, int distanceThreshold) {
		List<List<int[]>> adj = new ArrayList<>();
		for (int i=0; i<n; i++)
			adj.add(new ArrayList<>());

		for (int[] edge: edges) {
			int node = edge[0];
			int neighbor = edge[1];
			int weight = edges[2];

			adj.get(node).add(new int[] {neighbor, weight});
			adj.get(neighbor).add(new int[] {node, weight});
		}

		int minReachable = n;
		int node = -1;

		for (int i=0; i<n; i++) {
			int cnt = this.dijkstra(i, adj, distanceThreshold);
			if (cnt <= minReachable) {
				minReachable = cnt;
				node = i;
			}
		}

		return node;
	}

	public int dijkstra(int node, List<List<int[]>> adj, int distanceThreshold) {
		Set<Integer> visited = new HashSet<>();
		PriorityQueue<int[]> heap = new PriorityQueue<>((pair1, pair2) -> Integer.compare(pair1[0], pair2[0]));
		heap.offer(new int[] {0, node});

		while (!heap.isEmpty()) {
			int pair[] = heap.poll();
			int dist = pair[0];
			int curr = pair[1];

			if (visited.contains(curr))
				continue;
			visited.add(curr);

			for (int[] neighborPair: adj[curr]) {
				int neighbor = neighborPair[0];
				int weight = neighborPair[1];

				if (dist + weight <= distanceThreshold)
					heap.offer(new int[]{dist + weight, neighbor});
			}
		}

		return visited.size() - 1;
	}
};