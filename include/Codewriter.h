#include <fstream>
using namespace std;
class Codewriter
{
    public:
        ofstream assamblyfile;
        string commandtowrite;
        int inceqlabel=0;// inc eq command label
        int incgtlabel=0;// inc gt command label
        int incltlabel=0;// inc lt command label

        Codewriter(string outfilename);
        ~Codewriter();
        void WriteArithmetic(string command);
        void WritePushPop(string cmdtype, string segment,int index,string inputfile);

    protected:

    private:
};
