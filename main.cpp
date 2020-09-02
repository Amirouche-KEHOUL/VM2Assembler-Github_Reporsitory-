#include <iostream>
#include <fstream>
#include <sstream>
#include "parser.h"
#include "Codewriter.h"
#include <sys/stat.h>
#include <shlwapi.h>
#include <sys/stat.h>
#include <iterator>
#include <dirent.h>
#include <string>
#include <vector>


using namespace std;
ifstream avmfile;// input avm file

bool IsPathExist(const string &s)// check if file or directory
{
    struct stat buffer;
    return (stat (s.c_str(), &buffer) == 0);
}

string fileList[1]; // put here list of file names /!\ fileList[0]=inputFileOrDir


void VMtranslate(string input, Codewriter assamblyfile)//gets file name as input and generates  .asm ASCI file
{

}


int main(int argc,char* argv[])
{
    string inputFileOrDir; // input file name
    inputFileOrDir=argv[1]; // get arg1
    fileList[0]=inputFileOrDir;

    if (IsPathExist(argv[1]))
    {
        //if directory


        cout <<"it is a directory"<<endl;
        string currentFile;// stream out file names from the folder
        int i=2; // for if loop below (as index to fileList
        DIR *dr;
        struct dirent *en;
        dr = opendir(argv[1]); //open all directory
        if (dr)
        {
            //fill fileList
            while ((en = readdir(dr)) != NULL)
            {
                //cout<<" \n"<<en->d_name; //print all directory name
                currentFile=en->d_name;
                if (currentFile.size()>3)//d_name could be of size 1 or 2 --> TBC why ?  here just to filter those results
                {
                    if (currentFile.substr(currentFile.size()-2,2)=="vm")//fill fileList
                    {
                        if (currentFile=="Sys.vm")
                        {
                            fileList[1]=currentFile;
                        }
                        else
                        {
                            fileList[i]=currentFile;
                        }
                        i++;
                    }
                }
            }
            cout<<fileList[0]<<endl<<fileList[1]<<endl<<fileList[2]<<endl;

            closedir(dr); //close all directory
        }

        Codewriter assamblyfile(fileList[0]+".asm"); // create a Codewriter object
        assamblyfile.WriteInit(); // write bootstrap code

        for (int i=1; fileList[i]!="";i++)

        {
            Parser parser(inputFileOrDir+"/"+fileList[i]); // create a Parser object
            while (parser.hasMoreCommands())
            {
                parser.advance();// read command
                cout << "current command is : " <<parser.currentCommand<< endl;
                cout << "command type is : " <<parser.commandType()<< endl;
                cout <<"argument 1 is :" <<parser.arg1()<<endl;
                cout <<"argument 2 is :" <<parser.arg2()<<endl<<endl;

                if (parser.commandType()=="C_ARITHMETIC")
                {
                    assamblyfile.WriteArithmetic(parser.arg1());
                }
                if (parser.commandType()=="C_POP"||parser.commandType()=="C_PUSH")
                {
                    assamblyfile.WritePushPop(parser.commandType(),parser.arg1(),parser.arg2());
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
                if (parser.commandType()=="C_CALL")
                {
                    assamblyfile.WriteCall(parser.arg1(),parser.arg2());
                }
                if (parser.commandType()=="C_FUNCTION")
                {
                    assamblyfile.WriteFunction(parser.arg1(),parser.arg2());
                }
                if (parser.commandType()=="C_RETURN")
                {
                    assamblyfile.WriteReturn();
                }
            }

        }

    }
    else
    {
        // if one file directory
        Codewriter assamblyfile(fileList[0]+".asm"); // create a Codewriter object
        assamblyfile.WriteInit(); // write bootstrap code
            Parser parser(inputFileOrDir+".vm"); // create a Parser object
            while (parser.hasMoreCommands())
            {
                parser.advance();// read command
                cout << "current command is : " <<parser.currentCommand<< endl;
                cout << "command type is : " <<parser.commandType()<< endl;
                cout <<"argument 1 is :" <<parser.arg1()<<endl;
                cout <<"argument 2 is :" <<parser.arg2()<<endl<<endl;

                if (parser.commandType()=="C_ARITHMETIC")
                {
                    assamblyfile.WriteArithmetic(parser.arg1());
                }
                if (parser.commandType()=="C_POP"||parser.commandType()=="C_PUSH")
                {
                    assamblyfile.WritePushPop(parser.commandType(),parser.arg1(),parser.arg2());
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
                if (parser.commandType()=="C_CALL")
                {
                    assamblyfile.WriteCall(parser.arg1(),parser.arg2());
                }
                if (parser.commandType()=="C_FUNCTION")
                {
                    assamblyfile.WriteFunction(parser.arg1(),parser.arg2());
                }
                if (parser.commandType()=="C_RETURN")
                {
                    assamblyfile.WriteReturn();
                }
            }
    }
    return 0;
}
