#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 15;  

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;

vector<ii> adjList[MAXN];

ll Dijkstra(int n, int src, int dest)
{
	vector<ll> dist(n + 1, 10000000);
	dist[1] = 0;
	priority_queue<li, vector<li>, greater<li> > pq;
	pq.push({ 0, src });

	while (!pq.empty())
	{
		li front = pq.top();
		pq.pop();

		ll d = front.first;
		int u = front.second;

		if (dist[u] < d)
			continue;

		for (ii y : adjList[u])
		{
			if (dist[u] + y.second < dist[y.first])
			{
				dist[y.first] = dist[u] + y.second;
				pq.push({ dist[y.first], y.first });
			}
		}
	}

	return dist[dest];
}


int main()
{
	for (int i = 1; i < 15; i++)
		adjList[i] = vector<ii>();


	adjList[1].push_back({ 2, 21});
	adjList[1].push_back({ 3, 43 });
	adjList[1].push_back({ 4, 37 });

	adjList[2].push_back({ 5, 73 });
	adjList[2].push_back({ 6, 48 });
	adjList[2].push_back({ 7, 61 });

	adjList[3].push_back({ 5, 32 });
	adjList[3].push_back({ 6, 29 });
	adjList[3].push_back({ 7, 49 });

	adjList[4].push_back({ 5, 42 });
	adjList[4].push_back({ 6, 13 });
	adjList[4].push_back({ 7, 54 });

	adjList[5].push_back({ 8, 14 });
	adjList[5].push_back({ 9, 45 });

	adjList[6].push_back({ 8, 64 });
	adjList[6].push_back({ 9, 37 });

	adjList[7].push_back({ 8, 33 });
	adjList[7].push_back({ 9, 30 });

	adjList[8].push_back({ 10, 33 });

	adjList[9].push_back({ 10, 43 });

	cout << Dijkstra(11, 1, 10);
}