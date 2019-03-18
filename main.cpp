
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

ifstream F("input.txt");
ofstream file("output.txt");

int r = 0;

struct Circule {
    float x;
    float y;
    float radius;
    float perimeter;
    float area;
};

Circule circule[2];

void print(int i)
{
    if (i == 1) {
        file << "X: " << circule[r].x << endl
             << "Y: " << circule[r].y << endl
             << "Radius: " << circule[r].radius << endl
             << "Perimetr: " << circule[r].perimeter << endl
             << "Area: " << circule[r].area << endl;
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
        circule[r].x = stof(parametrs.substr(1, first_comma - 1));
        circule[r].y = stof(parametrs.substr(
                first_comma + 2, second_comma - first_comma - 2));
        circule[r].radius = stof(parametrs.substr(
                second_comma + 2, parametrs.size() - second_comma - 2));
        circule[r].perimeter = 2 * M_PI * circule[r].radius;
        circule[r].area = M_PI * circule[r].radius * circule[r].radius;
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
            r++;
        }
    }

    float dist = sqrt(
            (circule[1].x - circule[0].x) * (circule[1].x - circule[0].x)
            + (circule[1].y - circule[0].y) * (circule[1].y - circule[0].y));
    if (dist <= (circule[0].radius + circule[1].radius)) {
        file << "Shapes cross" << endl;
    }
    F.close();
}
