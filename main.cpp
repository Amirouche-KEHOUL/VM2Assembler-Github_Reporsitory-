#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.h"
#include "Codewriter.h"
#include <sys/stat.h>
#include <shlwapi.h>
#include <sys/stat.h>

using namespace std;
ifstream avmfile;// input avm file

bool IsPathExist(const string &s)
{
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}

int main(int argc,char* argv[])
{
    string inputfilename; // input file name
    inputfilename=argv[1]; // get arg1
    if (IsPathExist(argv[1]))
    {   //code here if directory


    }
    else // not directory
    {
        Parser parser(inputfilename+".vm"); // create a Parser object
        Codewriter assamblyfile(inputfilename+".asm"); // create a Codewriter object
        assamblyfile.WriteInit(); // write bootstrap code
        while (parser.hasMoreCommands())
        {
            parser.advance();// read command
            cout << "current command is : " <<parser.currentCommand<< endl;
            cout << "command type is : " <<parser.commandType()<< endl;
            cout <<"argument 1 is :" <<parser.arg1()<<endl;
            //cout <<"argument 2 is :" <<parser.arg2()<<endl<<endl;

            if (parser.commandType()=="C_ARITHMETIC")
            {
                assamblyfile.WriteArithmetic(parser.currentCommand);
            }
            if (parser.commandType()=="C_POP"||parser.commandType()=="C_PUSH")
            {
                assamblyfile.WritePushPop(parser.commandType(),parser.arg1(),parser.arg2(),inputfilename);
            }
            if (parser.commandType()=="C_LABEL")
            {
                assamblyfile.WriteLabel(parser.arg1());
            }
            if (parser.commandType()=="C_GOTO")
            {
                 assamblyfile.WriteGoto(parser.arg1());
            }
            if (parser.commandType()=="C_IF")
            {
                 assamblyfile.WriteIf(parser.arg1());
            }
        }

    }






    return 0;
}
