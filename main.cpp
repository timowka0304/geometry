#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Circule {
    float x;
    float y;
    float radius;
} curcule;

string s;

void InputList()
{
    string t;
    freopen("input.txt", "r", stdin);
    while (getline(cin, t)) {
        s += t;
        if (s[s.size() - 1] == ')')
            break;
    }
}

void OutputList()
{
    freopen("output.txt", "w", stdout);
    cout << s;
    fclose(stdout);
}

int main()
{
    InputList();
    OutputList();
}
