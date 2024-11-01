#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string word;
	cin >> word;

	int n = word.length();
	int isit = 0;

	for (int i = 0; i < n/2; i++)
	{
		if (word[i] == word[n - i-1])
		{
			isit++;
		}
	}

	if (isit == n / 2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}

	return 0;
}