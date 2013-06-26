#include "header.h"

void inputNames(char inFile[100], char inFile_2[100], char outFile[100], ifstream &fin, ifstream &fin_2, ofstream &fout)
{
     //Ask for file name 1
     cout << "Input filename 1 (labels): ";
     cin >> inFile;
     cout << "You have specified: " << inFile << endl;
     
     //Check file 1, terminate if not found
     fin.open(inFile);
     if (!inFile)
     {
          cout << "Cannot open input file: " << inFile << endl << "Terminating..." << endl;
          system("pause");
          exit(1);
     }
     
     //Ask for file name 2
     cout << "Input filename 2 (components): ";
     cin >> inFile_2;
     cout << "You have specified: " << inFile_2 << endl;
     
     //Check file 2, terminate if not found
     fin_2.open(inFile_2);
     if (!inFile_2)
     {
          cout << "Cannot open input file: " << inFile_2 << endl << "Terminating..." << endl;
          system("pause");
          exit(1);
     }
     
     //Ask for output filename
     cout << "Output filename: ";
     cin >> outFile;
     cout << "You have specified: " << outFile << endl;
     
     //Open outfile
     fout.open(outFile);
};

void loadLists(ifstream &fin, component *cList, int &size)
{
     
     string name;
     
     for (int i = 0; i < size; i++)
         {
              //Populate the array with names, set match to false
              getline (fin, name);
              cList[i].name = name;
              cList[i].match = false;
              cout << cList[i].name << endl;
         }
};

void compareLists(component *cList_1, component *cList_2, int size1, int size2)
{
     cout << "ECHO!!!!" << endl;
     //Iterates through array 1
     for (int i = 0; i < size1 ; i++)
     {
         cout << "ECHO [i]: " << i << endl; 
         cout << "ECHO name [i]: " << cList_1[i].name << endl;
         for (int j = 0; j < size2; j++)
         {
             cout << "ECHO [j]: " << j << endl;
             cout << "ECHO name [j]: " << cList_2[j].name << endl; 
                 if (cList_1[i].name == cList_2[j].name)
                 {
                     cList_1[i].match = true;
                     cList_2[j].match = true;
                     cout << "ECHO [true]" << endl; 
                 }
         } 
     } 
};

void printMismatch(component *cList, int size, ofstream &fout)
{
     for( int i = 0; i < size; i++)
     {
          if (cList[i].match == false)
             fout << cList[i].name << endl;
     }
        
};



