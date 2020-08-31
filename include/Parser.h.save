#include <fstream>
#include <map>
#include<bits/stdc++.h>
using namespace std;

class Parser
{
public:
    string inputfilename;
    string currentCommand;
    ifstream avmfile;
    map <string,string> map_typeofcommand // Map to lookup type of command from current command
    {
        // arethmetic and logical commands
        {"add","C_ARITHMETIC"},
        {"sub", "C_ARITHMETIC"},
        {"neg", "C_ARITHMETIC"},
        {"eq","C_ARITHMETIC"},
        {"gt", "C_ARITHMETIC"},
        {"lt", "C_ARITHMETIC"},
        {"and", "C_ARITHMETIC"},
        {"or","C_ARITHMETIC"},
        {"not", "C_ARITHMETIC"},
        //memory access commands
        {"pop","C_POP"},
        {"push", "C_PUSH"},
        //branching commands
        {"label", "C_LABEL"},
        {"goto","C_GOTO"},
        {"if-goto", "C_IF"},
        //function commands
        {"function", "C_FUNCTION"},
        {"call","C_CALL"},
        {"return", "C_RETURN"},
    };

    //Default constructor
    Parser(string inputfile);
    //Default destructor
    ~Parser();
    bool hasMoreCommands(); // Are there more commands in the imput
    void advance();// reads the next command from input file and makes it the current command (only if hasMoreCommands is true)
    const string commandType();//returns a const represent the type of the command
    string arg1();// returns the first arg of the current command
    int arg2();// returns the second arg of the current command
protected:

private:
};
