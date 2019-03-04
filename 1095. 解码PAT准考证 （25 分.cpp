#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cstdio>
using namespace std;
struct InfoStudent
{
	string ID;
	int Score;
};
void Function1(string &order, vector<InfoStudent> &data)
{
	vector<int> index;
	for (size_t i = 0 ; i<data.size();++i)
	{
		if (order[0] == data[i].ID[0])
			index.push_back(i);
	}
	sort(index.begin(), index.end(), [&data](const int a, const int b)
	{
		int x = data[a].Score, y = data[b].Score;
		if (x != y)
			return x > y;
		else
			return data[a].ID < data[b].ID;
	});
	for (auto &elem : index)
		printf("%s %d\n",data[elem].ID.c_str(),data[elem].Score);
	if (index.empty())
		printf("NA\n");
}
void Function2(string &order, vector<InfoStudent> &data)
{
	int cnt = 0,sum=0;
	for (auto &elem : data)
	{
		if (elem.ID.substr(1, 3) == order.substr(0,3))
		{
			++cnt;
			sum += elem.Score;
		}
	}

	if (cnt == 0)
	{
		printf("NA\n");
		return;
	}
	printf("%d %d\n",cnt,sum);
}
void Function3(string &order, vector<InfoStudent> &data)
{
	unordered_map<int, int> store;//无序map速度比有序map更快
	for (size_t i = 0; i < data.size(); ++i)
	{
		if (data[i].ID.substr(4, 6) == order.substr(0,6))
			++store[stoi(data[i].ID.substr(1, 3))];
	}
	vector<int> index(store.size());
	int i = 0;
	for (auto beg = store.cbegin(), end = store.cend();beg != end; ++beg,++i)
	{
		index[i] = (*beg).first;
	}
	sort(index.begin(), index.end(), [&store](const int a, const int b)
	{
		if (store[a] != store[b])
			return store[a] > store[b];
		else
			return a < b;
	});
	for (auto &elem : index)
	{
		printf("%d %d\n", elem,store[elem] );
	}
	if (index.empty())
		printf("NA\n");
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector<InfoStudent> data(N);
	for (int i = 0; i < N; ++i)
	{
		data[i].ID.resize(13);
		scanf("%s%d",&((data[i].ID)[0]), &(data[i].Score));
	}
	int type;
	string order;
	order.resize(7);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %s", &type, &order[0]);
		printf("Case %d: %d %s\n",i+1, type, order.c_str() );
		switch (type)
		{
		case 1:
			Function1(order, data);
			break;
		case 2:
			Function2(order, data);
			break;
		case 3:
			Function3(order, data);
			break;
		}
	}
}
