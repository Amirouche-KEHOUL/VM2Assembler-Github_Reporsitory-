#include "Codewriter.h"
#include "Parser.h"
using namespace std;

Codewriter::Codewriter(string outfilename)
{
    assamblyfile.open(outfilename);
}

Codewriter::~Codewriter()
{
}
void Codewriter::WriteArithmetic(string command)
{
    if (command=="add")
    {
        assamblyfile<<"//add"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M-1"<<endl;
        assamblyfile<<"D=M"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M-1"<<endl;
        assamblyfile<<"A=A-1"<<endl;
        assamblyfile<<"M=D+M"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"M=M-1"<<endl;
    }
    if (command=="sub")
    {
        assamblyfile<<"//sub"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M-1"<<endl;
        assamblyfile<<"D=M"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M-1"<<endl;
        assamblyfile<<"A=A-1"<<endl;
        assamblyfile<<"M=M-D"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"M=M-1"<<endl;
    }
    if (command=="neg")
    {
        assamblyfile<<"//neg"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M-1"<<endl;
        assamblyfile<<"M=-M"<<endl;
    }
    if (command=="eq")
    {
        assamblyfile<< "//eq"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "D=M"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=M-D"<<endl;
        assamblyfile<< "D=M"<<endl;
        assamblyfile<< "@eq_noteq_"<<inceqlabel<<endl;
        assamblyfile<< "D;JNE"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=-1"<<endl;
        assamblyfile<< "@eq_end_"<<inceqlabel<<endl;
        assamblyfile<< "0;JMP"<<endl;
        assamblyfile<< "(eq_noteq_"<<inceqlabel<<")"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=0"<<endl;
        assamblyfile<< "(eq_end_"<<inceqlabel<<")"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "M=M-1"<<endl;
        inceqlabel++;

    }
    if (command=="gt")
    {
        assamblyfile<< "//gt"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "D=M"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=M-D"<<endl;
        assamblyfile<< "D=M"<<endl;
        assamblyfile<< "@gt_gt_"<<incgtlabel<<endl;
        assamblyfile<< "D;JGT"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=0"<<endl;
        assamblyfile<< "@gt_end_"<<incgtlabel<<endl;
        assamblyfile<< "0;JMP"<<endl;
        assamblyfile<< "(gt_gt_"<<incgtlabel<<")"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=-1"<<endl;
        assamblyfile<< "(gt_end_"<<incgtlabel<<")"<<endl;
        assamblyfile<< "@SP "<<endl;
        assamblyfile<< "M=M-1"<<endl;
        incgtlabel++;
    }
    if (command=="lt")
    {
        assamblyfile<< "//lt"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "D=M"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=M-D"<<endl;
        assamblyfile<< "D=M"<<endl;
        assamblyfile<< "@lt_notlt_"<<incltlabel<<endl;
        assamblyfile<< "D;JLT"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=0"<<endl;
        assamblyfile<< "@lt_end_"<<incltlabel<<endl;
        assamblyfile<< "0;JMP"<<endl;
        assamblyfile<< "(lt_notlt_"<<incltlabel<<")"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=-1"<<endl;
        assamblyfile<< "(lt_end_"<<incltlabel<<")"<<endl;
        assamblyfile<< "@SP "<<endl;
        assamblyfile<< "M=M-1"<<endl;
        incltlabel++;

    }
    if (command=="and")
    {
        assamblyfile<< "//and"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "D=M"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=D&M"<<endl;
        assamblyfile<< "@SP "<<endl;
        assamblyfile<< "M=M-1"<<endl;
    }
    if (command=="or")
    {

        assamblyfile<< "//or"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "D=M"<<endl;
        assamblyfile<< "@SP"<<endl;
        assamblyfile<< "A=M-1"<<endl;
        assamblyfile<< "A=A-1"<<endl;
        assamblyfile<< "M=D|M"<<endl;
        assamblyfile<< "@SP "<<endl;
        assamblyfile<< "M=M-1"<<endl;
    }
    if (command=="not")
    {
        assamblyfile<<"//not"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M-1"<<endl;
        assamblyfile<<"M=!M"<<endl;
    }
}
void Codewriter::WritePushPop(string cmdtype, string segment,int index,string inputfile)
{
    if (cmdtype=="C_PUSH")
    {
        if (segment=="local")
        {
            assamblyfile<< "//push local"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@LCL"<<endl;
            assamblyfile<< "A=D+M"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="argument")
        {
            assamblyfile<< "//push argument"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@ARG"<<endl;
            assamblyfile<< "A=D+M"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="this")
        {
            assamblyfile<< "//push this"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@THIS"<<endl;
            assamblyfile<< "A=D+M"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="that")
        {
            assamblyfile<< "//push that"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@THAT"<<endl;
            assamblyfile<< "A=D+M"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="constant")
        {
            assamblyfile<< "//push constant"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="static")
        {
            assamblyfile<< "//push static"<<endl;
            assamblyfile<< "@"<<inputfile<<"."<<index<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="temp")
        {
            assamblyfile<< "//push temp"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@5"<<endl;
            assamblyfile<< "A=D+A"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="pointer")
        {
            if (index==0)
            {
                assamblyfile<< "//push pointer THIS"<<endl;
                assamblyfile<< "@THIS"<<endl;
                assamblyfile<< "D=M"<<endl;
                assamblyfile<< "@SP"<<endl;
                assamblyfile<< "A=M"<<endl;
                assamblyfile<< "M=D"<<endl;
                assamblyfile<< "@SP"<<endl;
                assamblyfile<< "M=M+1"<<endl;
            }
            if (index==1)
            {
                assamblyfile<< "//push pointer THAT"<<endl;
                assamblyfile<< "@THAT"<<endl;
                assamblyfile<< "D=M"<<endl;
                assamblyfile<< "@SP"<<endl;
                assamblyfile<< "A=M"<<endl;
                assamblyfile<< "M=D"<<endl;
                assamblyfile<< "@SP"<<endl;
                assamblyfile<< "M=M+1"<<endl;
            }

        }


    }
    if (cmdtype=="C_POP")
    {
        if (segment=="local")
        {
            assamblyfile<< "//pop local"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@LCL"<<endl;
            assamblyfile<< "A=D+M"<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M-1"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M-1"<<endl;

        }
        if (segment=="argument")
        {
            assamblyfile<< "//pop argument"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@ARG"<<endl;
            assamblyfile<< "A=D+M"<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M-1"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M-1"<<endl;
        }
        if (segment=="this")
        {
            assamblyfile<< "//pop this"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@THIS"<<endl;
            assamblyfile<< "A=D+M"<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M-1"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M-1"<<endl;
        }
        if (segment=="that")
        {
            assamblyfile<< "//pop that"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@THAT"<<endl;
            assamblyfile<< "A=D+M"<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M-1"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M-1"<<endl;
        }
        if (segment=="static")
        {
            assamblyfile<< "//pop static"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M-1"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@"<<inputfile<<"."<<index<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M-1"<<endl;

        }
        if (segment=="temp")
        {
            assamblyfile<< "//pop temp"<<endl;
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@5"<<endl;
            assamblyfile<< "A=D+A"<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M-1"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M-1"<<endl;
        }
        if (segment=="pointer")
        {
            if (index==0)
            {
                assamblyfile<< "//pop pointer this"<<endl;
                assamblyfile<< "@SP"<<endl;
                assamblyfile<< "A=M-1"<<endl;
                assamblyfile<< "D=M"<<endl;
                assamblyfile<< "@THIS"<<endl;
                assamblyfile<< "M=D"<<endl;
                assamblyfile<< "@SP"<<endl;
                assamblyfile<< "M=M-1"<<endl;

            }
            if (index==1)
            {
                assamblyfile<< "//pop pointer that"<<endl;
                assamblyfile<< "@SP"<<endl;
                assamblyfile<< "A=M-1"<<endl;
                assamblyfile<< "D=M"<<endl;
                assamblyfile<< "@THAT"<<endl;
                assamblyfile<< "M=D"<<endl;
                assamblyfile<< "@SP"<<endl;
                assamblyfile<< "M=M-1"<<endl;

            }
        }
    }
}
