#include "Codewriter.h"
#include "Parser.h"

#define DEBUG 1 // to show  DEBUG info

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
#if (DEBUG==1)
        assamblyfile<<"//sub"<<endl;
#endif
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
#if (DEBUG==1)
        assamblyfile<<"//neg"<<endl;
#endif
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M-1"<<endl;
        assamblyfile<<"M=-M"<<endl;
    }
    if (command=="eq")
    {
#if (DEBUG==1)
        assamblyfile<< "//eq"<<endl;
#endif
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
        assamblyfile<< "M=1"<<endl;
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
#if (DEBUG==1)
        assamblyfile<< "//gt"<<endl;
#endif
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
        assamblyfile<< "M=1"<<endl;
        assamblyfile<< "(gt_end_"<<incgtlabel<<")"<<endl;
        assamblyfile<< "@SP "<<endl;
        assamblyfile<< "M=M-1"<<endl;
        incgtlabel++;
    }
    if (command=="lt")
    {
#if (DEBUG==1)
        assamblyfile<< "//lt"<<endl;
#endif
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
        assamblyfile<< "M=1"<<endl;
        assamblyfile<< "(lt_end_"<<incltlabel<<")"<<endl;
        assamblyfile<< "@SP "<<endl;
        assamblyfile<< "M=M-1"<<endl;
        incltlabel++;

    }
    if (command=="and")
    {
#if (DEBUG==1)
        assamblyfile<< "//and"<<endl;
#endif
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

#if (DEBUG==1)
        assamblyfile<< "//or"<<endl;
#endif
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
#if (DEBUG==1)
        assamblyfile<<"//not"<<endl;
#endif
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M-1"<<endl;
        assamblyfile<<"M=!M"<<endl;
    }
}
void Codewriter::WritePushPop(string cmdtype, string segment,int index)
{
    if (cmdtype=="C_PUSH")
    {
        if (segment=="local")
        {
#if (DEBUG==1)
            assamblyfile<< "//push local"<<endl;
#endif
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
#if (DEBUG==1)
            assamblyfile<< "//push argument"<<endl;
#endif
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
#if (DEBUG==1)
            assamblyfile<< "//push this"<<endl;
#endif
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
#if (DEBUG==1)
            assamblyfile<< "//push that"<<endl;
#endif
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
#if (DEBUG==1)
            assamblyfile<< "//push constant"<<endl;
#endif
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
#if (DEBUG==1)
            assamblyfile<< "//push static"<<endl;
#endif
            assamblyfile<< "@"<<filename<<"."<<index<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M"<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M+1"<<endl;
        }
        if (segment=="temp")
        {
#if (DEBUG==1)
            assamblyfile<< "//push temp"<<endl;
#endif
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
#if (DEBUG==1)
                assamblyfile<< "//push pointer THIS"<<endl;
#endif
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
#if (DEBUG==1)
                assamblyfile<< "//push pointer THAT"<<endl;
#endif
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
#if (DEBUG==1)
            assamblyfile<< "//pop local"<<endl;
#endif
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@LCL"<<endl;
            assamblyfile<< "D=D+M"<<endl;
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
#if (DEBUG==1)
            assamblyfile<< "//pop argument"<<endl;
#endif
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@ARG"<<endl;
            assamblyfile<< "D=D+M"<<endl;
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
#if (DEBUG==1)
            assamblyfile<< "//pop this"<<endl;
#endif
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@THIS"<<endl;
            assamblyfile<< "D=D+M"<<endl;
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
#if (DEBUG==1)
            assamblyfile<< "//pop that"<<endl;
#endif
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@THAT"<<endl;
            assamblyfile<< "D=D+M"<<endl;
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
#if (DEBUG==1)
            assamblyfile<< "//pop static"<<endl;
#endif
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "A=M-1"<<endl;
            assamblyfile<< "D=M"<<endl;
            assamblyfile<< "@"<<filename<<"."<<index<<endl;
            assamblyfile<< "M=D"<<endl;
            assamblyfile<< "@SP"<<endl;
            assamblyfile<< "M=M-1"<<endl;

        }
        if (segment=="temp")
        {
#if (DEBUG==1)
            assamblyfile<< "//pop temp"<<endl;
#endif
            assamblyfile<< "@"<<index<<endl;
            assamblyfile<< "D=A"<<endl;
            assamblyfile<< "@5"<<endl;
            assamblyfile<< "D=D+A"<<endl;
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
#if (DEBUG==1)
                assamblyfile<< "//pop pointer this"<<endl;
#endif
                assamblyfile<< "A=M-1"<<endl;
                assamblyfile<< "D=M"<<endl;
                assamblyfile<< "@THIS"<<endl;
                assamblyfile<< "M=D"<<endl;
                assamblyfile<< "@SP"<<endl;
                assamblyfile<< "M=M-1"<<endl;

            }
            if (index==1)
            {
#if (DEBUG==1)
                assamblyfile<< "//pop pointer that"<<endl;
#endif
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
void Codewriter::WriteInit()
{
#if (DEBUG==1)
    assamblyfile<< "//Bootstrap code"<<endl;
#endif
    assamblyfile<< "@256"<<endl; //SP=256
    assamblyfile<< "D=A"<<endl;
    assamblyfile<< "@0"<<endl;
    assamblyfile<< "M=D"<<endl;
#if (DEBUG==1)
    assamblyfile<< "//Call Sys.init  "<<endl;
#endif
    //push return address
    assamblyfile<<"@Sys.init."<<"RetAdd."<<numRet<<endl;
    assamblyfile<<"D=A"<<endl;
    assamblyfile<<"@SP"<<endl;
    assamblyfile<<"A=M"<<endl;
    assamblyfile<<"M=D"<<endl;
    assamblyfile<<"@SP"<<endl;
    assamblyfile<<"@SP"<<endl;
    assamblyfile<<"M=M+1"<<endl;
    //push LCL, ARG, THIS, THAT
    for (int i=1; i<5; i++)
    {
        if (i==1)
        {
            assamblyfile<<"@LCL"<<endl;
        }
        if (i==2)
        {
            assamblyfile<<"@ARG"<<endl;
        }
        if (i==3)
        {
            assamblyfile<<"@THIS"<<endl;
        }
        if (i==4)
        {
            assamblyfile<<"@THAT"<<endl;
        }
        assamblyfile<<"D=M"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M"<<endl;
        assamblyfile<<"M=D"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"M=M+1"<<endl;
    }
    //ARG = SP-5-n
    assamblyfile<<"@SP"<<endl;
    assamblyfile<<"D=M"<<endl;
    assamblyfile<<"@5"<<endl;
    assamblyfile<<"D=D-A"<<endl;
    assamblyfile<<"@0"<<endl;
    assamblyfile<<"D=D-A"<<endl;
    assamblyfile<<"@ARG"<<endl;
    assamblyfile<<"M=D"<<endl;
    //LCL=SP
    assamblyfile<<"@SP"<<endl;
    assamblyfile<<"D=M"<<endl;
    assamblyfile<<"@LCL"<<endl;
    assamblyfile<<"M=D"<<endl;
    //goto called function
    assamblyfile<<"@Sys.init"<<endl;
    assamblyfile<<"0;JMP"<<endl;
    //return address
    assamblyfile<<"(Sys.init."<<"RetAdd."<<numRet<<")"<<endl;//set a unique return address label
    numRet++;// increment
#if (DEBUG==1)
    assamblyfile<<"//End of Bootstrap code"<<endl;
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
    assamblyfile<< "@SP"<<endl;
    assamblyfile<< "A=M-1"<<endl;
    assamblyfile<< "D=M"<<endl;
    assamblyfile<< "@SP"<<endl;
    assamblyfile<< "M=M-1"<<endl;
    assamblyfile<< "@"<<label<<endl;
    assamblyfile<< "D;JGT"<<endl;

}
void Codewriter::WriteCall(string functionName, int numArgs)
{
#if (DEBUG==1)
    assamblyfile<< "//Function Call "<<endl;
#endif
    //push return address
    assamblyfile<<"@"<< filename<<"."<<"RetAdd."<<numRet<<endl;
    assamblyfile<<"D=A"<<endl;
    assamblyfile<<"@SP"<<endl;
    assamblyfile<<"A=M"<<endl;
    assamblyfile<<"M=D"<<endl;
    assamblyfile<<"@SP"<<endl;
    assamblyfile<<"M=M+1"<<endl;
    //push LCL, ARG, THIS, THAT
    for (int i=1; i<5; i++)
    {
        if (i==1)
        {
            assamblyfile<<"@LCL"<<endl;
        }
        if (i==2)
        {
            assamblyfile<<"@ARG"<<endl;
        }
        if (i==3)
        {
            assamblyfile<<"@THIS"<<endl;
        }
        if (i==4)
        {
            assamblyfile<<"@THAT"<<endl;
        }
        assamblyfile<<"D=M"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"A=M"<<endl;
        assamblyfile<<"M=D"<<endl;
        assamblyfile<<"@SP"<<endl;
        assamblyfile<<"M=M+1"<<endl;
    }
    //ARG = SP-5-n
    assamblyfile<<"@SP"<<endl;
    assamblyfile<<"D=M"<<endl;
    assamblyfile<<"@5"<<endl;
    assamblyfile<<"D=D-A"<<endl;
    assamblyfile<<"@"<<numArgs<<endl;
    assamblyfile<<"D=D-A"<<endl;
    assamblyfile<<"@ARG"<<endl;
    assamblyfile<<"M=D"<<endl;
    //LCL=SP
    assamblyfile<<"@SP"<<endl;
    assamblyfile<<"D=M"<<endl;
    assamblyfile<<"@LCL"<<endl;
    assamblyfile<<"M=D"<<endl;
    //goto called function
    assamblyfile<<"@"<<functionName<<endl;
    assamblyfile<<"0;JMP"<<endl;
    //return address
    assamblyfile<<"("<< filename<<"."<<"RetAdd."<<numRet<<")"<<endl;//set a unique return address label
    numRet++;// increment
}
void Codewriter::WriteFunction(string functionName,int numLocals)
{
    // declare a label
#if (DEBUG==1)
    assamblyfile<<"//Declare function"<<endl;
#endif
    assamblyfile<<"("<<functionName<<")"<<endl;
    // repeat numLocals time push local 0 (initialize local vars)
    for (int i=1; i<=numLocals; i++)
    {
        assamblyfile<< "@0" <<endl;
        assamblyfile<< "D=A" <<endl;
        assamblyfile<< "@LCL" <<endl;
        assamblyfile<< "A=D+M" <<endl;
        assamblyfile<< "D=M" <<endl;
        assamblyfile<< "@SP" <<endl;
        assamblyfile<< "A=M" <<endl;
        assamblyfile<< "M=D" <<endl;
        assamblyfile<< "@SP" <<endl;
        assamblyfile<< "M=M+1" <<endl;
    }
}
void Codewriter::WriteReturn()
{
    // FRAME = LCL ; FRAME is a tempo var = temp[0]
#if (DEBUG==1)
    assamblyfile<< "//Return"<<endl;
#endif
    assamblyfile<< "@LCL"<<endl;
    assamblyfile<< "D=M"<<endl;
    assamblyfile<< "@5"<<endl;
    assamblyfile<< "M=D"<<endl;
    //put the return @ in a temp var (RET = *(temp[1]-5))
    assamblyfile<< "@5" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@5" <<endl;
    assamblyfile<< "A=D-A" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@6" <<endl;
    assamblyfile<< "M=D" <<endl;
    //reposition the return value for the caller *ARG = pop()
    assamblyfile<< "@ARG" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@SP" <<endl;
    assamblyfile<< "A=M" <<endl;
    assamblyfile<< "M=D" <<endl;
    assamblyfile<< "@SP" <<endl;
    assamblyfile<< "A=M-1" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@SP" <<endl;
    assamblyfile<< "A=M" <<endl;
    assamblyfile<< "A=M" <<endl;
    assamblyfile<< "M=D" <<endl;
    //restore SP of the caller
    assamblyfile<< "@ARG" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@SP" <<endl;
    assamblyfile<< "M=D+1" <<endl;
    //restore THAT of the caller THAT =*(FRAME-1), FRAME =temp[0]
    assamblyfile<< "@5" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "A=D-1" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@THAT" <<endl;
    assamblyfile<< "M=D" <<endl;
    //restore THIS of the caller THIS =*(FRAME-2), FRAME =temp[0]
    assamblyfile<< "@5" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@2" <<endl;
    assamblyfile<< "A=D-A" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@THIS" <<endl;
    assamblyfile<< "M=D" <<endl;
    //restore THIS of the caller ARG =*(FRAME-3), FRAME =temp[0]
    assamblyfile<< "@5" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@3" <<endl;
    assamblyfile<< "A=D-A" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@ARG" <<endl;
    assamblyfile<< "M=D" <<endl;
    //restore THIS of the caller ARG =*(FRAME-4), FRAME =temp[0]
    assamblyfile<< "@5" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@4" <<endl;
    assamblyfile<< "A=D-A" <<endl;
    assamblyfile<< "D=M" <<endl;
    assamblyfile<< "@LCL" <<endl;
    assamblyfile<< "M=D" <<endl;
    //goto RET (return @)
    assamblyfile<< "@6" <<endl;
    assamblyfile<< "A=M" <<endl;
    assamblyfile<< "0;JMP"<<endl;

}
