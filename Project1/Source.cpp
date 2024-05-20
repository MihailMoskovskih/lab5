#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

#include <set>
#include <unordered_set>

using namespace std;

class Auto 
{
public:
    string name;
    int rasxod[3];
    int speed;
    int power;


public:
    Auto() {}
    Auto(const string& name, int speed, int power, const int* rasxod1) : name(name), speed(speed), power(power) 
    {
        for (int i = 0; i < 3; ++i) 
        {
            rasxod[i] = rasxod1[i];
        }
    }
        
    friend ostream& operator<<(ostream& pt, const Auto& Auto) 
    {
        pt << "Name: " << Auto.name << ", Speed: " << Auto.speed << ", Power: " << Auto.power << ", Rasxod: ";
        for (int i = 0; i < 3; ++i) 
        {
            pt << Auto.rasxod[i] << " ";
        }
        return pt;
    }

    bool operator<(const Auto& r) const
    {
        // if (rasxod[2] == r.rasxod[2]) return name < r.name;
        return rasxod[2] < r.rasxod[2];
    }

    
};

/*size_t pw(size_t x, size_t n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n & 1) return x * pw(x, n - 1);
    size_t y = pw(x, n / 2);
    return y * y;
}*/


/*struct hashFunction {
public:
    size_t operator()(const Auto& auto1) {
        size_t hash = 0;
        size_t power = 0;
        for (char sym : auto1.name) {
            power += (size_t)sym;
        }
        hash = pw(2, power);
        power = 0;
        for (int i = 0; i < 3; ++i) {
            power += auto1.rasxod[i];
        }
        hash += pw(3, power);
        hash += pw(5, auto1.speed);
        hash += pw(7, auto1.power);
        return hash;
    }
};*/

int main() 
{
    ifstream inputFile("input.txt");
    // unordered_set<Auto, hashFunction> uset;
    // set<Auto> aaset;
    list<Auto> Autos;
    string name;
    int speed;
    int power;
    int rasxod[3];

    while (inputFile >> name >> speed >> power >> rasxod[0] >> rasxod[1] >> rasxod[2]) 
    {
        Autos.push_back(Auto(name, speed, power, rasxod));
    }
    inputFile.close();

    ofstream outputFile("output.txt");

    outputFile << "Isxod:" << endl;
    for (const auto& Auto : Autos) 
    {
        outputFile << Auto << endl;
    }
    outputFile << endl;

    Autos.sort([](const Auto& a, const Auto& b)
        {
        return a.rasxod[2] < b.rasxod[2];
        });


    outputFile << "Sorted:" << endl;
    for (const auto& Auto : Autos) 
    {
        outputFile << Auto << endl;
    }
    outputFile << endl;

    vector<Auto> AutosVector(Autos.size());
    copy(Autos.begin(), Autos.end(), AutosVector.begin());

    outputFile << "List copy to vector:" << endl;
    for (const auto& Auto : AutosVector) 
    {
        outputFile << Auto << endl;
    }

    outputFile.close();


    return 0;
}