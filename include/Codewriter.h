#include <fstream>
using namespace std;
class Codewriter
{
    public:
        ofstream assamblyfile;
        string commandtowrite;
        string filename;
        int numRet=1; // used to generates different labels for function call by incrementing it
        int inceqlabel=0;// inc eq command label
        int incgtlabel=0;// inc gt command label
        int incltlabel=0;// inc lt command label
        int asmAdd=0;// Base @ to be incremented for each VM file: Static variable are shared by all functions in the same .vm file


        Codewriter(string outfilename);
        ~Codewriter();
        void WriteArithmetic(string command);
        void WritePushPop(string cmdtype, string segment,int index,string currentFileInDir);//currentFileDir is used to create a unique static variable for each file in one Dir
        void WriteInit();// Write bootstarp code
        void WriteLabel(string label);
        void WriteGoto(string label);
        void WriteIf(string label);
        void WriteCall(string functionName, int numArgs);
        void WriteFunction(string functionName,int numLocals);
        void WriteReturn();
    protected:

    private:
};
