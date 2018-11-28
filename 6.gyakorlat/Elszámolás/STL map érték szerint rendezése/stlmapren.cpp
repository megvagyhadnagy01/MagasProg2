#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

typedef std::pair<std::string,int> pair;

int main()
{
    // a rendezend� map, string kulcsb�l �s int �rt�kekb�l �ll
    std::map<std::string,int> map = {
        {"two", 2}, {"one", 1}, {"five", 5}, {"four", 4}, {"three", 3}
    };

    // p�rokat tartalmaz� �res vektor
    std::vector<pair> vec;

    // a map eg�sz�t (az elej�t�l a v�g�ig) a vec vektorba m�solja �t
    std::copy(map.begin(), map.end(), std::back_inserter(vec));

    // a vektor rendez�se a p�rok m�sodik �rt�ke alapj�n
    std::sort(vec.begin(), vec.end(),
            [](const pair& l, const pair& r) {
                return l.second < r.second;
            });

    // a rendezett vektor ki�rat�sa range-based for looppal
    for (auto const &pair: vec) {
        std::cout << '{' << pair.first << " , " << pair.second << '}' << std::endl;
    }

    return 0;
}