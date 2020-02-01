#include <iostream>
#include <queue>

using namespace std;
priority_queue<pair<int, int>> Q;

int main()
{
	int N, M, tmp1, tmp2, money = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> tmp1 >> tmp2;
		Q.push(make_pair(-tmp1, tmp2));
	}
	while (N)
	{
		if (N >= Q.top().second)
		{
			money += Q.top().second * Q.top().first * -1;
			N -= Q.top().second;
		}
		else
		{
			money += N * Q.top().first * -1;
			N -= N;
		}
		Q.pop();
	}
	cout << money;
}
