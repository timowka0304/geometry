#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

ifstream F("input.txt");
ofstream file("output.txt");

struct Circule {
    float x;
    float y;
    float radius;
    float perimeter;
    float area;
};

Circule circule;

void print(int i)
{
    if (i == 1) {
        file << "X: " << circule.x << endl
             << "Y: " << circule.y << endl
             << "Radius: " << circule.radius << endl
             << "Perimetr: " << circule.perimeter << endl
             << "Area: " << circule.area << endl;
    }
}

void text(string s)
{
    int k = 0;
    while (s[k] != '(') {
        k++;
    }
    string name = s.substr(0, k);
    string parametrs;
    if (name == "circule") {
        parametrs = s.substr(k, s.size() - k);
        int first_comma = parametrs.find(',');
        int second_comma = parametrs.rfind(',');
        circule.x = stof(parametrs.substr(1, first_comma - 1));
        circule.y = stof(parametrs.substr(
                first_comma + 2, second_comma - first_comma - 2));
        circule.radius = stof(parametrs.substr(
                second_comma + 2, parametrs.size() - second_comma - 2));
        circule.perimeter = 2 * M_PI * circule.radius;
        circule.area = M_PI * circule.radius * circule.radius;
        print(1);
    }
}
int main()
{
    string s;
    while (!F.eof()) {
        getline(F, s);
        if (s != "\0") {
            file << s << endl;
            text(s);
        }
    }
    F.close();
}

