/*************************************************************************
	> File Name: HuffmanNode.cpp
	> Author: bw98
	> Mail: 786016746@qq.com
	> Created Time: 2017年11月09日 星期四 00时16分03秒
 ************************************************************************/
#include<iostream>
#include"Huffman.h"
#include<algorithm>
#include<numeric>
#include<fstream>
#include<string>
#include<assert.h>
#include<stdlib.h>
#include<limits>
using namespace std;

void HuffmanTree::insert(const char &info, const double &wt)
{
    if((2*currentSize - 1) >maxSize )
        return;
    arrayTree[currentSize].information = info;
    arrayTree[currentSize].weight = wt;
    currentSize++;
}

void HuffmanTree::createHuffmanTree()
{
    int i = currentSize;
    int k;
    double wt1, wt2;
    int lnode ,rnode;
    while(i < (2*currentSize -1) ) {
        k = 0;
        wt1 = numeric_limits<double>::max ();
        wt2 = numeric_limits<double>::max ();
        while(k < i){
            if(arrayTree[k].parent == 0){
                if (arrayTree[k].weight < wt1) {
                    wt2 = wt1;
                    rnode = lnode;
                    wt1 = arrayTree[k].weight;
                    lnode = k;
                }
                else if (arrayTree[k].weight < wt2) {
                    wt2 = arrayTree[k].weight;
                    rnode = k;
                }
            }
            k++;
        }
        arrayTree[i].weight = arrayTree[lnode].weight + arrayTree[rnode].weight;
        arrayTree[i].lchild = lnode;
        arrayTree[i].rchild = rnode;
        arrayTree[lnode].parent = i;
        arrayTree[rnode].parent = i;
        i++;
    }
}

int HuffmanTree::myStrlen(const char array[]) const
{
    const char *p = array;
    while(*p != '\0')
        p++;
    return (p - array);
    
}

void HuffmanTree::myStrcpy(char des[], char source[])
{
    assert( des != NULL );
    assert( source!= NULL );
    while( (*des++ = *source++) != '\0' );
}

int HuffmanTree::myStrcmp(const char *s1, const char *s2) const
{
    const char *str1 = s1;
    const char *str2 = s2;
    if (str1 == str2)
        return 0;
    if (str1 == NULL && str2 != NULL)
        return -1;
    if (str1 != NULL && str2 == NULL)
        return 1;
    while (*str1 && *str2 && *str1 == *str2){
        str1++;
        str2++;
    }
    if (*str1 < *str2)
        return -1;
    if (*str1 > *str2)
        return 1;
    return 0;
}


int HuffmanTree::isEqual(const char *s) const //return value is position of codeArray[] or -1
{
    int i = 0;
    for (i = 0; i<currentSize; i++)
        if (myStrlen(s) == myStrlen(codeArray[i].ptr))
            if (myStrcmp(s, codeArray[i].ptr) == 0)
                return i;
    return -1;
}

void HuffmanTree::reverse(char array[])
{
    const int len = myStrlen(array) ;
    char *p = new char[len+1];
    myStrcpy(p, array);
    p[len] = '\0';
    int k = 0;
    for(int i = len -1; i >= 0; --i)
        array[i] = p[k++];
    array[len] = '\0';
    delete[] p;
}
    
void HuffmanTree::createHuffmanCode()
{
    codeArray = new Code[currentSize];
    int i = 0, k;
    unsigned int m,n;
    while(i < currentSize) {
        k = arrayTree[i].parent;
        n = 0;
        m = i;
        assert(i >= 0);
        assert(k >= 0);
        assert(m >= 0);
        assert(n >= 0);
        while ((k != 0) && (k < (2*currentSize)-1)) {
            if (arrayTree[k].lchild == m)
                codeArray[i].ptr[n++] = '0';
            else if (arrayTree[k].rchild == m)
                codeArray[i].ptr[n++] = '1';
            m = k;
            k = arrayTree[m].parent;
        }
        codeArray[i].ptr[n] = '\0';
        reverse(codeArray[i].ptr);
        i++;
    }
}

int HuffmanTree::getLongestCodeLength() const
{
    if(currentSize == 0)
        return -1;
    int len = myStrlen(codeArray[0].ptr);
    int i = 1;
    while (i < currentSize) {
        int temp = myStrlen(codeArray[i].ptr);
        if (temp > len)
            len = temp;
        i++;
    }
    return len;
}

void HuffmanTree::print() const
{
    int k = 0;
    cout << "Information" << "(" << "weight" << "): " << "code" << endl;
    while(k < currentSize){
        cout << arrayTree[k].information << "(" << arrayTree[k].weight << "): " << codeArray[k].ptr << endl;
    }
}

int HuffmanTree::findInfoPosition(const char &ch) const
{
    for (int i = 0; i < currentSize; i++){
        if(arrayTree[i].information == ch)
            return i;
    }
    return -1;
}

void HuffmanTree::start(const char *inFileName, const char *outFileName, const char *secondOutFileName)
{
    cout << "Enter function (start) now" << endl;
    ifstream fileIn(inFileName, ios::in);
    assert(fileIn);
    if (!fileIn) {
        cerr << inFileName << "couldn't open." << endl;
        exit(1);
    }
    char ch;
    int pos;

    //get weights
    fileIn >> ch;
    while (fileIn && !fileIn.eof()) {
        pos = findInfoPosition(ch);
        if (pos != -1)
            arrayTree[pos].weight++;
        else
            insert(ch, 1);        
        fileIn >> ch;
    }

    createHuffmanTree(); //create HuffmanTree
    createHuffmanCode(); //code

    //make Huffman code into outFileName
    ofstream fileOut(outFileName, ios::out);
    if (!fileOut) {
        cerr << outFileName  << "Couldn't open." << endl;
        exit(1);
    };
    fileIn.clear();
    fileIn.seekg(0, ios::beg);
    fileIn >> ch;
    while (fileIn && !fileIn.eof()) {
        pos = findInfoPosition(ch);
        if (pos != -1)
            fileOut << codeArray[pos].ptr;
        fileIn >> ch;
    }
    fileIn.close();
    fileOut.close();
    
    //transcode and make it into secondOutFileName
    fileIn.open(outFileName, ios::in);
    fileOut.open(secondOutFileName,ios::out);
    if (!fileIn || !fileOut) {
        cerr << "File could not open." << endl;
        exit(1);
    }

    const int longestLen = getLongestCodeLength();
    char *p = new char[longestLen + 1];
    int k = 0;
    fileIn >> ch;
    while (fileIn && !fileIn.eof()) {
        if (k < longestLen) {
            p[k++] = ch;
            p[k] = '\0';
            pos = isEqual(p);
            if (pos != -1) {
                fileOut << arrayTree[pos].information;
                k = 0;
            }
        }
        else{
            cerr << "The code is wrong." << endl;
            exit(1);
        }
        fileIn >> ch;
    }

    fileIn.close();
    fileOut.close();
}
