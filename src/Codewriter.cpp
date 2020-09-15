#include "Codewriter.h"
#include "Parser.h"

#define DEBUG 1 //1 to write DEBUG info
#define BOOT 1 //1 to write bootstrap code

using namespace std;

Codewriter::Codewriter(string outfilename)
{
    assamblyfile.open(outfilename);
    filename=outfilename.substr(0,outfilename.size()-4);
    auto found= filename.find("/"); //check for '/' char and replace it with '_'
    if (found!=string::npos)
    {
        filename.replace(found,1,"_");

    }

}
Codewriter::~Codewriter()
{
}
void Codewriter::WriteArithmetic(string command)
{
    if (command=="add")
    {
#if (DEBUG==1)
        assamblyfile<<"//add"<<endl;
#endif
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=D+M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=M-1"<<endl;

    }
    if (command=="sub")
    {
#if (DEBUG==1)
        assamblyfile<<"//sub"<<endl;
#endif
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=M-D"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=M-1"<<endl;
    }
    if (command=="neg")
    {
#if (DEBUG==1)
        assamblyfile<<"//neg"<<endl;
#endif
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=-M"<<endl;
    }
    if (command=="eq")
    {
#if (DEBUG==1)
        assamblyfile<< "//eq"<<endl;
#endif
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=M-D"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@eq_noteq_"<<inceqlabel<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D;JNE"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@eq_end_"<<inceqlabel<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "0;JMP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "(eq_noteq_"<<inceqlabel<<")"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=0"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "(eq_end_"<<inceqlabel<<")"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=M-1"<<endl;

        inceqlabel++;

    }
    if (command=="gt")
    {
#if (DEBUG==1)
        assamblyfile<< "//gt"<<endl;
#endif
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=M-D"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@gt_gt_"<<incgtlabel<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D;JGT"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=0"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@gt_end_"<<incgtlabel<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "0;JMP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "(gt_gt_"<<incgtlabel<<")"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "(gt_end_"<<incgtlabel<<")"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP "<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=M-1"<<endl;
        incgtlabel++;
    }
    if (command=="lt")
    {
#if (DEBUG==1)
        assamblyfile<< "//lt"<<endl;
#endif
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=M-D"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@lt_notlt_"<<incltlabel<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D;JLT"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=0"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@lt_end_"<<incltlabel<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "0;JMP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "(lt_notlt_"<<incltlabel<<")"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "(lt_end_"<<incltlabel<<")"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP "<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=M-1"<<endl;
        incltlabel++;

    }
    if (command=="and")
    {
#if (DEBUG==1)
        assamblyfile<< "//and"<<endl;
#endif
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=D&M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP "<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=M-1"<<endl;
    }
    if (command=="or")
    {

#if (DEBUG==1)
        assamblyfile<< "//or"<<endl;
#endif
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=A-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=D|M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP "<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=M-1"<<endl;
    }
    if (command=="not")
    {
#if (DEBUG==1)
        assamblyfile<<"//not"<<endl;
#endif
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=M-1"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=!M"<<endl;
    }
}
void Codewriter::WritePushPop(string cmdtype, string segment,int index,string currentFileInDir)
{
    if (cmdtype=="C_PUSH")
    {
        if (segment=="local")
        {
#if (DEBUG==1)
            assamblyfile<< "//push local"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@LCL"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=D+M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="argument")
        {
#if (DEBUG==1)
            assamblyfile<< "//push argument"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@ARG"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=D+M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="this")
        {
#if (DEBUG==1)
            assamblyfile<< "//push this"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@THIS"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=D+M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="that")
        {
#if (DEBUG==1)
            assamblyfile<< "//push that"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@THAT"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=D+M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="constant")
        {
#if (DEBUG==1)
            assamblyfile<< "//push constant"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="static")
        {
#if (DEBUG==1)
            assamblyfile<< "//push static"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<filename<<"."<<currentFileInDir<<"."<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="temp")
        {
#if (DEBUG==1)
            assamblyfile<< "//push temp"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@5"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=D+A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="pointer")
        {
            if (index==0)
            {
#if (DEBUG==1)
                assamblyfile<< "//push pointer THIS"<<endl;
                //We use it for storing the base addresses of the segments this (0)
#endif
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@THIS"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "M=M+1"<<endl;
            }
            if (index==1)
            {
#if (DEBUG==1)
                assamblyfile<< "//push pointer THAT"<<endl;
#endif          //We use it for storing the base addresses of the segments that(1)
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@THAT"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "M=M+1"<<endl;
            }

        }


    }
    if (cmdtype=="C_POP")
    {
        if (segment=="local")
        {
#if (DEBUG==1)
            assamblyfile<< "//pop local"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@LCL"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=D+M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M-1"<<endl;

        }
        if (segment=="argument")
        {
#if (DEBUG==1)
            assamblyfile<< "//pop argument"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@ARG"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=D+M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M-1"<<endl;
        }
        if (segment=="this")
        {
#if (DEBUG==1)
            assamblyfile<< "//pop this"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@THIS"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=D+M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M-1"<<endl;
        }
        if (segment=="that")
        {
#if (DEBUG==1)
            assamblyfile<< "//pop that"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@THAT"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=D+M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M-1"<<endl;
        }
        if (segment=="static")
        {
#if (DEBUG==1)
            assamblyfile<< "//pop static"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<filename<<"."<<currentFileInDir<<"."<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M-1"<<endl;

        }
        if (segment=="temp")
        {
#if (DEBUG==1)
            assamblyfile<< "//pop temp"<<endl;
#endif
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@"<<index<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@5"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=D+A"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "A=M"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<< "M=M-1"<<endl;
        }
        if (segment=="pointer")
        {
            if (index==0)
            {
#if (DEBUG==1)
                assamblyfile<< "//pop pointer this"<<endl;
#endif
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@THIS"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "M=M-1"<<endl;

            }
            if (index==1)
            {
#if (DEBUG==1)
                assamblyfile<< "//pop pointer that"<<endl;
#endif
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@THAT"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
                assamblyfile<<asmAdd++<<" ";
#endif
                assamblyfile<< "M=M-1"<<endl;

            }
        }
    }
}
void Codewriter::WriteInit()
{
#if (BOOT==1)

#if (DEBUG==1)
    assamblyfile<< "//Bootstrap code"<<endl;
#endif
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@256"<<endl; //SP=256
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=A"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@0"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
    assamblyfile<< "//Call Sys.init  "<<endl;
#endif

    //push return address
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@Sys.init."<<"RetAdd."<<numRet<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=A"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"A=M"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"M=D"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"M=M+1"<<endl;

    //push LCL, ARG, THIS, THAT
    for (int i=1; i<5; i++)
    {
        if (i==1)
        {
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<<"@LCL"<<endl;
        }
        if (i==2)
        {
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<<"@ARG"<<endl;
        }
        if (i==3)
        {
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<<"@THIS"<<endl;
        }
        if (i==4)
        {
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<<"@THAT"<<endl;
        }
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=D"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=M+1"<<endl;
    }
    //ARG = SP-5-n
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=M"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@5"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=D-A"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@0"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=D-A"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@ARG"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"M=D"<<endl;
    //LCL=SP
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=M"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@LCL"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"M=D"<<endl;
    //goto called function
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@Sys.init"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"0;JMP"<<endl;
    //return address
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"(Sys.init."<<"RetAdd."<<numRet<<")"<<endl;//set a unique return address label
    numRet++;// increment
#if (DEBUG==1)
    assamblyfile<<"//End of Bootstrap code"<<endl;
#endif
#endif
}
void Codewriter::WriteLabel(string label)
{
#if (DEBUG==1)
    assamblyfile<< "//Label"<<endl;
#endif
    assamblyfile<<"("<<label<<")"<<endl;

}
void Codewriter::WriteGoto(string label)
{
#if (DEBUG==1)
    assamblyfile<< "//goto"<<endl;
#endif
    assamblyfile<< "@"<<label<<endl;
    assamblyfile<< "0;JMP"<<endl;

}
void Codewriter::WriteIf(string label)
{
#if (DEBUG==1)
    assamblyfile<< "//if-goto"<<endl;
#endif
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=M-1"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=M-1"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@"<<label<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D;JGT"<<endl;

}
void Codewriter::WriteCall(string functionName, int numArgs)
{
#if (DEBUG==1)
    assamblyfile<< "//Function Call "<<endl;
#endif
    //push return address
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@"<< filename<<"."<<"RetAdd."<<numRet<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=A"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"A=M"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"M=D"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"M=M+1"<<endl;
    //push LCL, ARG, THIS, THAT
    for (int i=1; i<5; i++)
    {
        if (i==1)
        {
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<<"@LCL"<<endl;
        }
        if (i==2)
        {
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<<"@ARG"<<endl;
        }
        if (i==3)
        {
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<<"@THIS"<<endl;
        }
        if (i==4)
        {
#if (DEBUG==1)
            assamblyfile<<asmAdd++<<" ";
#endif
            assamblyfile<<"@THAT"<<endl;
        }
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"D=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"A=M"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=D"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<<"M=M+1"<<endl;
    }
    //ARG = SP-5-n
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=M"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@5"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=D-A"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@"<<numArgs<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=D-A"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@ARG"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"M=D"<<endl;

    //LCL=SP
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@SP"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"D=M"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@LCL"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"M=D"<<endl;

    //goto called function
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"@"<<functionName<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"0;JMP"<<endl;

    //return address
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"("<< filename<<"."<<"RetAdd."<<numRet<<")"<<endl;//set a unique return address label
    numRet++;// increment
}
void Codewriter::WriteFunction(string functionName,int numLocals)
{
    // declare a label
#if (DEBUG==1)
    assamblyfile<<"//Declare function"<<endl;
#endif
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<<"("<<functionName<<")"<<endl;
    // repeat numLocals time push local 0 (initialize local vars)
    for (int i=1; i<=numLocals; i++)
    {
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP" <<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "A=M" <<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=0" <<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "@SP" <<endl;
#if (DEBUG==1)
        assamblyfile<<asmAdd++<<" ";
#endif
        assamblyfile<< "M=M+1" <<endl;
    }
}
void Codewriter::WriteReturn()
{
    // FRAME = LCL ; FRAME is a tempo var = temp[0]
#if (DEBUG==1)
    assamblyfile<< "//Return"<<endl;
#endif
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@LCL"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@11"<<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D"<<endl;

    //put the return @ in a temp var (RET = *(temp[1]-5))
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@11" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@5" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=D-A" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@12" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D" <<endl;

    //reposition the return value for the caller *ARG = pop()
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@ARG" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@SP" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@SP" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=M-1" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@SP" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D" <<endl;

    //restore SP of the caller
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@ARG" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@SP" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D+1" <<endl;

    //restore THAT of the caller THAT =*(FRAME-1), FRAME =temp[0]
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@11" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=D-1" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@THAT" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D" <<endl;

    //restore THIS of the caller THIS =*(FRAME-2), FRAME =temp[0]
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@11" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@2" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=D-A" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@THIS" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D" <<endl;

    //restore THIS of the caller ARG =*(FRAME-3), FRAME =temp[0]
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@11" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@3" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=D-A" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@ARG" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D" <<endl;

    //restore THIS of the caller ARG =*(FRAME-4), FRAME =temp[0]
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@11" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@4" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=D-A" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "D=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@LCL" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "M=D" <<endl;

    //goto RET (return @)
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "@12" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "A=M" <<endl;
#if (DEBUG==1)
    assamblyfile<<asmAdd++<<" ";
#endif
    assamblyfile<< "0;JMP"<<endl;

}
