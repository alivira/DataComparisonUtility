#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct component {
       string name;
       bool match;
       };
       
void inputNames(char inFile[100], char inFile_2[100], char outFile[100], ifstream &fin, ifstream &fin_2, ofstream &fout);
void loadLists(ifstream &fin, component *cList, int &size);
void compareLists(component *cList_1, component *cList_2, int size1, int size2);
void printMismatch(component *cList, int size, ofstream &fout);

#endif
