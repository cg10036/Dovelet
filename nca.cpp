#include <iostream>
#include <vector>

using namespace std;

struct Tree
{
	int depth;
	int parent;
	vector<int> childs;
};

Tree tree[10001] = { 0 };

void run(int a, int depth)
{
	tree[a].depth = depth;
	for (int i = 0; i < tree[a].childs.size(); i++)
	{
		run(tree[a].childs[i], depth + 1);
	}
}

int main()
{
	int a, parent, child, node1, node2, root = 1;
	scanf("%d", &a);
	for (int i = 1; i < a; i++)
	{
		scanf("%d %d", &parent, &child);
		tree[parent].childs.push_back(child);
		tree[child].parent = parent;
	}
	while (tree[root].parent)
	{
		root = tree[root].parent;
	}
	run(root, 1);
	scanf("%d %d", &node1, &node2);
	while (tree[node1].depth != tree[node2].depth)
	{
		if (tree[node1].depth > tree[node2].depth)
		{
			node1 = tree[node1].parent;
		}
		else
		{
			node2 = tree[node2].parent;
		}
	}
	while (node1 != node2)
	{
		node1 = tree[node1].parent;
		node2 = tree[node2].parent;
	}
	cout << node1;
}
