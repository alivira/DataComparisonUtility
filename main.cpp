#include "header.h"

int main(){
    ifstream fin, fin_2;
    ofstream fout;
    
    char inFile[100];
    char inFile_2[100];
    char outFile[100];
    
    int size1 = 0;
    int size2 = 0;
    
    component *cList_1;
    component *cList_2;
    
    inputNames(inFile, inFile_2, outFile, fin, fin_2, fout);
    
    cout << "Enter the number of items in list 1: ";
    cin >> size1;
    cout << endl << "Enter the number of items in list 2: ";
    cin >> size2;

    cList_1 = new component[size1];
    cout << size1 << endl;

    cList_2 = new component[size2];
    cout << size2 << endl;
    
    loadLists(fin, cList_1, size1);
    loadLists(fin_2, cList_2, size2);
    
    compareLists(cList_1, cList_2, size1, size2);
    fout << "--- MISMATCHES LIST 1 ---" << endl;
    printMismatch(cList_1, size1, fout);
    fout << "--- MISMATCHES LIST 2 ---" << endl;
    printMismatch(cList_2, size2, fout);
    
    fin.close();
    fin_2.close();
    fout.close();
    
    delete[] cList_1;
    delete[] cList_2;
    
    
    system("pause");
    
}
