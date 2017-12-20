/*************************************************************************
	> File Name: HashTable.h
	> Author: bw98 
	> Mail: 786016746@qq.com
	> Created Time: 2017年12月20日 星期三 10时04分23秒
 ************************************************************************/

#ifndef _HASHTABLE_H
#define _HASHTABLE_H
class HashItem {
private:
    int key, val;
public:
    HashItem(int k, int v) : key(k),val(v) {}
    const int &getKey() {return key;}
    const int &getVal() {return val;}
};

class HashTable {
    static const int SIZE = 256;
private:
    HashItem **table; //point to HashItem*,easy to new and delete
public:
    HashTable() {
        table = new HashItem*[SIZE] (); //initialize
    }
    ~HashTable() {
        for (i = 0; i< SIZE; ++i) {
            if(table[index]) {
                delete table[i];
            }
        }
    }
    
    void set(key,val) { //linear probing
        int index = key%SIZE;
        while ((table[index]) && (table[index]->getKey != key)) {
            index = (index + 1) % SIZE;  
        }
        if(table[index]) {
            delete table[index];
        }
        table[index] = new HashItem(key, val);
    }
    
    int get(key) const {
        int index = key%SIZE;
        while((table[index]) && (table[index]->getKey != key)) {
            index = (index + 1) % SIZE;
        }
        
        return table[index] ? table[index]->getVal : -1;
    }    
}
#endif
