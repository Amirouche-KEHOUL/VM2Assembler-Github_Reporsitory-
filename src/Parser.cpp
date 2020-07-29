#include "Parser.h"
using namespace std;

Parser::Parser(string inputfile)
{
    avmfile.open(inputfile);
    inputfilename=inputfile;

}

Parser::~Parser()
{
    //dtor
}

bool Parser::hasMoreCommands()// Are there more commands in the input file
{
    if (avmfile.eof())
    {

        return false;
    }
    else
    {
        return true;
    }
}

void Parser::advance()// reads the next command from and makes it the current command (only if hasMoreCommands is true)
{
    if (hasMoreCommands())
    {
        getline(avmfile,currentCommand);//currentCommand=currentCommand;// set currentCommand var
    }
}

const string Parser::commandType()//returns a const represent the type of the command
{
    string command;
    int i=0;

    while ((currentCommand[i]!=' ')&&(i!=currentCommand.size()))
    {
        command=command+currentCommand[i];
        i=i+1;
    }
    return map_typeofcommand[command];
}

string Parser::arg1()// returns the first arg of the current command
{
    string arg;
    int i;
    if (commandType()!="C_RETURN")// don't call if C_RETURN
    {

        if (commandType()=="C_ARITHMETIC")
        {
            arg=currentCommand;
        }
        else
        {
            if (commandType()=="C_POP")
            {
                i=4;
                while ((currentCommand[i]!=' ')&&(i!=currentCommand.size()))
                {
                    arg=arg+currentCommand[i];
                    i=i+1;
                }

            }
            if (commandType()=="C_PUSH" || commandType()=="C_GOTO" || commandType()=="C_CALL")
            {
                i=5;
                while ((currentCommand[i]!=' ')&&(i!=currentCommand.size()))
                {
                    arg=arg+currentCommand[i];
                    i=i+1;
                }
            }
            if (commandType()=="C_LABEL")
            {
                i=6;
                while ((currentCommand[i]!=' ')&&(i!=currentCommand.size()))
                {
                    arg=arg+currentCommand[i];
                    i=i+1;
                }
            }
            if (commandType()=="C_GOTO")
            {
                i=8;
                while ((currentCommand[i]!=' ')&&(i!=currentCommand.size()))
                {
                    arg=arg+currentCommand[i];
                    i=i+1;
                }
            }
            if (commandType()=="C_FUNCTION")
            {
                i=9;
                while ((currentCommand[i]!=' ')&&(i!=currentCommand.size()))
                {
                    arg=arg+currentCommand[i];
                    i=i+1;
                }
            }
        }
    }
    return arg;
}

int  Parser::arg2()// returns the second arg of the current command
{
    string arg;
    if (commandType()=="C_POP"||commandType()=="C_PUSH"||commandType()=="C_FUNCTION"||commandType()=="C_CALL")
    {
        int i=0;
        while (currentCommand[currentCommand.size()-i]!=' ')
        {
            arg=arg+currentCommand[currentCommand.size()-i];
            i=i+1;
        }
        reverse(arg.begin(),arg.end());
    return stoi(arg);// convert string to int
    }

}

