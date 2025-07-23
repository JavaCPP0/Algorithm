#include <iostream>
using namespace std;

int standard[4];
int check[4];
int satisfy = 0;

void Add(char c);
void Delete(char c);

int main() {
    int s, p, result = 0;
    string str;

    cin >> s >> p;
    cin >> str;

    for (int i = 0; i < 4; i++) {
        cin >> standard[i];
        if (standard[i] == 0) satisfy++;
    }

    for (int i = 0; i < p; i++) {
        Add(str[i]);
    }

    if (satisfy == 4) result++;

    for (int i = 0; i < s - p; i++) {
        Add(str[i + p]);
        Delete(str[i]);
        if (satisfy == 4) result++;
    }

    cout << result;
    return 0;
}

void Add(char c) {
    switch (c) {
    case 'A':
        check[0]++;
        if (check[0] == standard[0]) satisfy++;
        break;
    case 'C':
        check[1]++;
        if (check[1] == standard[1]) satisfy++;
        break;
    case 'G':
        check[2]++;
        if (check[2] == standard[2]) satisfy++;
        break;
    case 'T':
        check[3]++;
        if (check[3] == standard[3]) satisfy++;
        break;
    }
}

void Delete(char c) {
    switch (c) {
    case 'A':
        if (check[0] == standard[0]) satisfy--;
        check[0]--;
        break;
    case 'C':
        if (check[1] == standard[1]) satisfy--;
        check[1]--;
        break;
    case 'G':
        if (check[2] == standard[2]) satisfy--;
        check[2]--;
        break;
    case 'T':
        if (check[3] == standard[3]) satisfy--;
        check[3]--;
        break;
    }
}
