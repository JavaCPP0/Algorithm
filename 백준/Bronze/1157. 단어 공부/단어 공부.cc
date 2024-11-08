#include <iostream>

using namespace std;

int main(void)
{
	int arr[26] = {0};
	int n;
	int max_index=0, max = 0;
	bool isittwo=false;
	string word;

	cin >> word;

	for (int i = 0; i < word.length(); i++)
	{
		n = (int)word[i];
		if (n > 91)
		{
			n -=32;
		}

		arr[n - 65]++;
	}

	for (int i = 0; i < 26; i++) {
    if (arr[i] > max) {
        max = arr[i];
        max_index = i;
        isittwo = false; 
    } 
    else if (arr[i] == max) {
        isittwo = true;
    }
}


	if (isittwo)
	{
		cout << "?";
	}
	else
	{
		cout<<(char)(max_index + 65);
	}

	return 0;
}