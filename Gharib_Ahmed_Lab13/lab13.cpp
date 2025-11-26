/*
EECS 348 Lab 13 
Ahmed Gharib
KUID: 3127878
11/25/25
This program has the faulty function (faillecture_original), the corrected function, 
and Main that runs cases for Questions 2 to 5
*/

#include <iostream>
#include <vector>
using namespace std;
bool faillecture_original(const vector<int>& rec){
    int miss = 0;
    for(int i = 1; i < rec.size(); i++){ // should start at 0
        miss += (rec[i] == 0);
    }
    return miss >= 3;
}

bool faillecture_fixed(const vector<int>& rec){
    int miss = 0;
    for(int i = 0; i < rec.size(); i++){ // Fixed
        miss += (rec[i] == 0);
    }
    return miss >= 3;
}

void printRecord(const vector<int>& v){
    cout << "{";
    for(size_t i = 0; i < v.size(); i++){
        cout << v[i];
        if(i < v.size() - 1) cout << ",";
    }
    cout << "}";
}

int main(){
    vector<int> q2 = {1,1,1,1,1,1,1,1,1,1};
    vector<int> q3 = {0,1,1,1,1,1,1,1,1,1};
    vector<int> q4 = {0,0,0,1,1,1,1,1,1,1};
    vector<int> q5 = {0,0,0,0,1,1,1,1,1,1};
    vector<vector<int>> tests = {q2,q3,q4,q5};
    for(int i = 0; i < tests.size(); i++){
        cout << "Test case Q" << (i+2) << ": ";
        printRecord(tests[i]);
        cout << " Fixed: " << (faillecture_fixed(tests[i]) ? "FAIL" : "PASS");
        cout << "\nOriginal: " << (faillecture_original(tests[i]) ? "FAIL" : "PASS");
        cout << "\n";
    }
    return 0;
}
