#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.h"
#include "Codewriter.h"
using namespace std;
ifstream avmfile;// input avm file

int main()
{
    string inputfilename="StaticTest"; // input file name
    Parser parser(inputfilename+".vm"); // create a Parser object
    Codewriter assamblyfile(inputfilename+".asm"); // create a Codewriter object

    while (parser.hasMoreCommands())
    {
        parser.advance();// read command
        cout << "current command is : " <<parser.currentCommand<< endl;
        cout << "command type is : " <<parser.commandType()<< endl;
        cout <<"argument 1 is :" <<parser.arg1()<<endl;
        cout <<"argument 2 is :" <<parser.arg2()<<endl<<endl;

        if (parser.commandType()=="C_ARITHMETIC")
        {
            assamblyfile.WriteArithmetic(parser.currentCommand);
        }
        if (parser.commandType()=="C_POP"||parser.commandType()=="C_PUSH")
        {
            assamblyfile.WritePushPop(parser.commandType(),parser.arg1(),parser.arg2(),inputfilename);
        }
    }

    return 0;
}
