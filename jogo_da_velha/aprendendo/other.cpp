#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> all;
    string one = "guilherme";
    all.push_back(one);

    char v ='1';
    v = char(int(v) + 1);
    
    one[one.size()-1] = v;
    cout << one << endl;


}