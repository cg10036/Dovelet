#include <iostream>
#include <vector>

using namespace std;

void print(int i)
{
	switch (i)
	{
	case 0:
		cout << "Poppy ";
		break;
	case 1:
		cout << "Carnation ";
		break;
	case 2:
		cout << "Sunflower ";
		break;
	case 3:
		cout << "Daisy ";
		break;
	case 4:
		cout << "Pansy ";
		break;
	}
}

int main()
{
	int arr[5][2], tmp1;
	vector<int> result[5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cin >> tmp1;
		for (int j = 0; j < 5; j++)
		{
			if (tmp1 >= arr[j][0] && tmp1 <= arr[j][1])
			{
				result[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (result[j].size() == 1)
			{
				for (int k = 0; k < 5; k++)
				{
					if (k == j)
					{
						continue;
					}
					for (int l = 0; l < result[k].size(); l++)
					{
						if (result[k][l] == result[j][0])
						{
							result[k].erase(result[k].begin() + l);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		if (result[i].size() != 1)
		{
			cout << "Ambiguous";
			return 0;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		print(result[i][0]);
	}
}
