// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
//#include <iostream>




int main(int argc, char* argv[])
{
    if (argc != argCount-1) {
        cout << "incorrect number of arguments. --> [ Lab1.exe input_file1.txt ]";
        usageMessage(argv[0]);
        return incorrectNumArgs;
    }
    else {
        vector<string> reggie;
        int outcome = parse(reggie, argv[1]);
        if (outcome != success) {
            return outcome;
        }
        vector<int> raul;

        for (unsigned int i = 0; i < size(reggie); i++) {
            if (isdigit(reggie[i][0])) {
                for (unsigned int j = 0; j < size(reggie[i]); j++) {
                    if (!isdigit(reggie[i][j])) {
                        cout << reggie[i] << " ";
                        j = size(reggie[i]);
                        //this prevents double output and double incrementing, both problems when altering i value at this pt
                        
                        
                        //i++;
//                        if(!isdigit(reggie[i][size(reggie[i])-1])){ // to avoid double incrementing-- kept having problems with "more" b/c its preceeded with "string2"
//                            i++;                                    // and would just skip over the word "more"
//                        }
            //^^^failed attempts at "j = size(reggie[i]);"


                        // here we are confirming that each char in the string is a digit
                        // if not, we print it and move to the next string
                        // if string is an int, we proceed by adding the int to "raul"
                    }
                }
                istringstream salmon(reggie[i]);
                int leubert;
                salmon >> leubert;
                raul.push_back(leubert);
            }
            else {//^ that if() only covers our strings with a digit in them, now we gota print the pure strings 
                cout << reggie[i] << ' ';
            }
        }
        cout << endl; //separate our first int from the strings
        for (unsigned int i = 0; i < size(raul)-1; i++) {
            cout << raul[i] << endl;
        }
        return success;
    }
}




/**     had to move this ftn to header, Maybe couldve also tried moving it above main() but ah well
int parse(vector<string>& textVec, char* inputFile) {
    string temp;
    ifstream reader;
    reader.open(inputFile);
    if (reader.is_open()) {
        while (reader >> temp) {
            textVec.push_back(temp);
            
        }
        reader.close();
    }
    else {
        cout << "ifstream could not open the file" << endl;
        return cantOpenFile;
    }
    //cout << textVec;
    return success;
}**/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
