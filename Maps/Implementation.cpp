#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> mapping;
    pair<string, int> p = make_pair("love", 25);
    pair<string, int> q("dipansh", 24);
    pair<string, int> r;
    r.first = "Abhijit";
    r.second = 24;

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping["babbar"] = 51;

    cout << "Size of map: " << mapping.size() << endl;
    cout << mapping.at("love") << endl;
    cout << mapping["love"] << endl;
    cout << mapping.count("love") << endl;

    if (mapping.find("babbar") != mapping.end())
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    cout << "Size of map: " << mapping.size() << endl;
    cout << mapping["kumar"] << endl;
    cout << "Size of map: " << mapping.size() << endl;
    return 0;
}