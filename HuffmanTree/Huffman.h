/*************************************************************************
	> File Name: HuffmanNode.h
	> Author: bw98
	> Mail: 786016746@qq.com 
	> Created Time: 2017年11月06日 星期一 23时53分24秒
 ************************************************************************/

#ifndef _HUFFMANNODE_H
#define _HUFFMANNODE_H

class HuffmanNode{
public:
    char information; //Node's Information
    double weight;
    unsigned int parent;
    unsigned int lchild;
    unsigned int rchild;
    
    HuffmanNode (const char &info, const double &wt , const unsigned int &par, const unsigned int &lch, const unsigned int &rch)
    : information(info), weight(wt), parent(par), lchild(lch), rchild(rch) {} 
    HuffmanNode () : HuffmanNode('0', 0, 0, 0, 0) {}

};
class HuffmanTree{
public:
    HuffmanTree(const int &s = 100) {
        maxSize = (s>100? s : 100);
        arrayTree = new HuffmanNode[maxSize];
        currentSize = 0;
        codeArray = 0;
    }
    ~HuffmanTree() {
        delete[] arrayTree;
        delete[] codeArray;   
    }

    void start(const char *, const char *, const char *); //file names from argv[0] to argv[2]

private:
    HuffmanNode *arrayTree; //declare a HuffmanNode array 
    int maxSize; 
    int currentSize;
    
    void insert(const char &, const double & ); //insert HuffmanTree
    void createHuffmanTree();
    void createHuffmanCode();
    int findInfoPosition(const char & ) const;
    int isContains(const char & ) const; //error flag is -1
    void print() const;
    int myStrlen(const char array[]) const;
    void myStrcpy(char des[],char source[]);
    int myStrcmp(const char *str1, const char *str2) const;
    class Code { //private class of HuffmanTree class
    public:
        Code () : length(10) {ptr = new char[length];}
        ~Code () {delete[] ptr; }

        char *ptr; //charArray/string of each Huffmancode
        const int length;
    };

    Code *codeArray; //Array length is currentSize
    void reverse(char arr[]); //reverse Huffman code
    int getLongestCodeLength() const; //get longest code length from each leaves information
    int isEqual(const char *s) const; //return value is position or -1 (Not Found)

};

#endif
