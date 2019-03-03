#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	string A, B;
	getline(cin,A);
	getline(cin,B);
	set<char> NoRepeated;
	for (auto i : A)
	{
		if (NoRepeated.find(i) == NoRepeated.end())
		{
			NoRepeated.insert(i);
			cout << i;
		}
	}
	for (auto i : B)
	{
		if (NoRepeated.find(i) == NoRepeated.end())
		{
			NoRepeated.insert(i);
			cout << i;
		}
	}
	cout << endl;
}
