/*************************************************************************
	> File Name: main.cpp
	> Author: bw98
	> Mail: 
	> Created Time: 2017年12月20日 星期三 11时26分03秒
 ************************************************************************/

#include<iostream>
#include"HashTable.h"
using namespace std;

int main (void) 
{
    HashTable *ht = new HashTable();
    int key, val;
    while(cin >> key >> val) {
        ht->set(key, val);
    }
    cout << "Search HashTable now" << endl;
    while(cin >> key >> val) {
        if (ht->get(key) != -1) {
            cout << "key:" << key << "value:" << ht->get(key) << endl;
        }
        else {
            cout << "Not Find." << endl;
            break;
        }
    }
    return 0;
}
