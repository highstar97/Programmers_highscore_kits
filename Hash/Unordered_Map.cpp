#include <unordered_map>
#include <iostream>

using namespace std;

int main(){
    unordered_map<string, int> um;

    um.emplace("Park",100);
    um["Kim"] = 80;
    um.emplace("Lee", 90);
    um.insert(pair<string, int>("Jung",50));
    um.emplace(pair<string, int>("Choi", 40));

    unordered_map<string, int>::iterator it;
    for (it = um.begin(); it != um.end(); it++) {
        cout << it->first << " " << (*it).second << endl;
    }
}