/*************************************************************************
	> File Name: main.cpp
	> Author: bw98
	> Mail: 786016746@qq.com
	> Created Time: 2017年11月09日 星期四 09时25分29秒
 ************************************************************************/
#include"Huffman.h"
#include <iostream>
int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cout << "usage is executiveFileName inFileName outFisrtFileName outSecondFileName" << std::endl;
        return 0;
    }
     
    const char *inFileName = argv[1];
    const char *outFisrtFileName = argv[2];
    const char *secondOutFileName = argv[3];
    HuffmanTree *t = new HuffmanTree();
    t->start(inFileName, outFisrtFileName, secondOutFileName);
    return 0;
}
