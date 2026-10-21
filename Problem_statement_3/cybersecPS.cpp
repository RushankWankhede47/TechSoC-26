#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

inline int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

std::vector<int> MessageReader(string inputmsg)
{
    std::vector<char> inputseparated;
    std::vector<int> result;
    int asciivalues[inputmsg.length()] = {};
    for (int i = 0; i < inputmsg.length(); i++)
    {
        inputseparated.push_back(inputmsg[i]);
        asciivalues[i] = static_cast<int>(inputseparated[i]);
        result.push_back(asciivalues[i]);
    }
    return result;
}

std::vector<int> DEC_Read(const std::string &inputmsg)
{
    std::vector<int> result;
    std::string hold = "";

    for (size_t i = 0; i < inputmsg.length(); i++)
    {
        if (inputmsg[i] == '-')
        {
            if (!hold.empty())
            {
                result.push_back(std::stoi(hold));
                hold = "";
            }
        }
        else
        {
            hold += inputmsg[i];
        }
    }

    if (!hold.empty())
    {
        result.push_back(std::stoi(hold));
    }

    return result;
}

inline long long modPow(long long m, long long e, long long n)
{
    long long result = 1;
    for (long long i = 0; i < e; i++)
    {
        result = (result * m) % n;
    }
    return result;
}

int RSAcmdNumExtractN(string a)
{
    string number = "";
    int brackpos = a.find('(');
    int comma = a.find(',');
    for (int i = brackpos + 1; i < comma; i++)
    {
        number += a[i];
    }
    return std::stoi(number);
}

int RSAcmdNumExtract2ndNUM(string a)
{
    string number = "";
    int brackpos = a.find(')');
    int comma = a.rfind(','); // This one
    for (int i = comma + 1; i < brackpos; i++)
    {
        number += a[i];
    }
    return std::stoi(number);
}

int FindingSecondNumber(std::string a) {
    std::string number = "";
    int firstComma = a.find(',');
    int secondComma = a.find(',', firstComma + 1);
    for (int i = firstComma + 1; i < secondComma; i++) {
        number += a[i];  
    }
    return std::stoi(number);
}

char Asciibacktracer(int a)
{
    char myChar = static_cast<char>(a);
    return myChar;
}

std::vector<int> Encrypted;
std::vector<int> Decrypted;
string rsaEncrypt(std::vector<int> m, int e, int n)
{
    string result = "";

    for (int i = 0; i < m.size(); i++)
    {
        result += std::to_string(modPow(m[i], e, n));
        Encrypted.push_back((int)modPow(m[i], e, n));
        result += '-';
    }
    result.pop_back();
    return result;
}

string rsaDecrypt(std::vector<int> m, int d, int n)
{
    string result = "";

    for (int i = 0; i < m.size(); i++)
    {
        result += Asciibacktracer((int)modPow(m[i], d, n));
        Decrypted.push_back((int)modPow(m[i], d, n));
    }
    return result;
}

double binaryconv(int a)
{
    int store;
    double result=0;
    for(int i = 8; i>0;i--){
        if(a/pow(2,i)==0) continue;
        store = a/(int)pow(2,i);
        result += store*pow(10,i-1);
        a = a%((int)pow(2,i));
    }
    result*=10;
    if(a%2==1){result+=1;}
    return result;
}

string arrangebinary(double a)
{
    string s = std::to_string((long long)a);
    int no_of_zeroes_added = 8 - s.length();
    string result = "";
    for (int i = 0; i < no_of_zeroes_added; i++)
    {
        result += '0';
    }
    result = result + s;
    return result;
}

string arrangebinaryv2(double a){
    string s = std::to_string((long long)a);
    int no_of_zeroes_added = 6 - s.length();
    string result = "";
    for (int i = 0; i < no_of_zeroes_added; i++)
    {
        result += '0';
    }
    result = result + s;
    return result;
}

string put_together(std::vector<string> input_as_string)
{
    string result = "";
    for (int i = 0; i < input_as_string.size(); i++)
    {
        result += input_as_string[i];
    }
    return result;
}

std::vector<string> splitinto6(string a)
{
    std::vector<string> result;
    std::string temp = "";
    for (size_t i = 0; i < a.length(); i++)
    {
        temp += a[i];
        if (temp.length() == 6)
        {
            result.push_back(temp);
            temp = "";
        }
    }
    if (temp.length() > 0)
    {
        while (temp.length() < 6)
            temp += "0";
        result.push_back(temp);
    }
    return result;
}

string Padding(string bits)
{
    if (bits.length() % 6 == 2)
    {
        return "==";
    }
    if (bits.length() % 6 == 4)
    {
        return "=";
    }
    // else{return "";}
    return "";
}

string BinaryToDecimal(string a)
{
    int value = 0;
    for (size_t i = 0; i < a.length(); i++)
    {
        value = value * 2 + (a[i] - '0');
    }
    return std::to_string(value);
}

int BinarytoDeciamlv2(string a){
    int value = 0;
    for (size_t i = 0; i < a.length(); i++)
    {
        value = value * 2 + (a[i] - '0');
    }
    return value;
}

string Base64_enc(std::vector<int> a)
{
    string result = "";
    std::vector<double> input_in_binary;
    for (int i = 0; i < a.size(); i++)
    {
        input_in_binary.push_back(binaryconv(a[i]));
    }
    std::vector<string> input_as_string;
    for (int i = 0; i < a.size(); i++)
    {
        input_as_string.push_back(arrangebinary(input_in_binary[i]));
    }
    string together = put_together(input_as_string);
    std::vector<string> splitted = splitinto6(together);
    splitted.push_back(Padding(together));

    std::vector<string> splittedDecimal;
    for (int i = 0; i < splitted.size() - 1; i++)
    {
        splittedDecimal.push_back(BinaryToDecimal(splitted[i]));
    }

    for (int i = 0; i < splittedDecimal.size(); i++)
    {
        result += alphabet[std::stoi(splittedDecimal[i])];
    }
    result += splitted[splitted.size() - 1];
    return result;  
}

std::vector<char> Base64_splitter(string a){
    std::vector<char> result;
    for (int i = 0; i < a.length(); i++)
    {
        result.push_back(a[i]);
    }
    return result;
}

std::vector<string> splitinto8(string together){
    std::vector<string> result;
    std::string temp = "";
    for (size_t i = 0; i < together.length(); i++)
    {
        temp += together[i];
        if (temp.length() == 8)
        {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}

    string Base64_dec(std::vector<char> a){
    std::vector<int> positions;
    std::vector<double> binarypos;
    std::vector<string> stringpos;
    for(int i = 0; i<a.size()-2;i++)
    {
        positions.push_back(alphabet.find(a[i]));
    }
    if(a[a.size()-2]!='=') positions.push_back(alphabet.find(a[a.size()-2]));
    if(a[a.size()-1]!='=') positions.push_back(alphabet.find(a[a.size()-1]));
    for(int i = 0; i<positions.size();i++){
        binarypos.push_back(binaryconv(positions[i]));
    }
    for(int i = 0; i<positions.size();i++){
        stringpos.push_back(arrangebinaryv2(binarypos[i]));
    }
    string together = put_together(stringpos);
    // COnvert together to independent 8 bits binary and then converting them
    std::vector<string> divbinary = splitinto8(together);
    std::vector<int> divdeci;
    for(int i = 0; i<divbinary.size();i++){
        divdeci.push_back(BinarytoDeciamlv2(divbinary[i]));
    }
    std::vector<char> finalascii;
    for(int i = 0; i<divbinary.size();i++){
        finalascii.push_back(Asciibacktracer(divdeci[i]));
    }
    string result="";
    for(int i = 0; i<divbinary.size();i++){
        result+=finalascii[i];
    }
    return result;

}

// Bonus part in below functions

double Find_D(double p, double q, double e){
    double n = p*q;
    double phi = (p-1)*(q-1);
    double d = 1;
    while (d<=phi){
        if((int)(e * d) % (int)phi == 1) break;;
        d++;
    }
    return d;
}

void RSATOY(){
    int n = 221;
    int e = 5;
    double d;
    // now n = p*q
    // Program takes every value of p from 1 to 221, then q from 1 to 221, then check every case
    for(int p = 1; p<n;p++){
        for(int q = 1; q<n; q++){
            if(p*q==n){
                // Now that we know p and q, we must compute d
                d = Find_D(p,q,e);
            }
        }
    }
    cout<<"For n = 221, e=5, value of d will be: "<<d<<endl;

    // The program already requires 2 for loops going from 1 to 221. If the number is 600s of digits long then the computation time would be too great.
    // The time required would be too great even for supercomputers, that means through brute force, current computers cannot break this encryption

}

int main()
{

    string inputmsg;
    string inputcmd;
    cin >> inputmsg;
    std::getline(cin, inputcmd);

    size_t startPos = inputcmd.find('[');
    size_t endPos = inputcmd.find(']');

    if (startPos != string::npos && endPos != string::npos && endPos > startPos)
    {
        // Cutting out the substring between []
        inputcmd = inputcmd.substr(startPos + 1, endPos - startPos - 1);
    }
    else
    {
        cout << "No cmds found!";
        exit(0);
    }

    std::vector<string> Commands;
    string temp = "";
    bool bracketopen = false;
    int charsininput = inputcmd.length();
    int a = 0;

    for (int i = 0; i < charsininput; i++)
    {
        if (inputcmd[i] == '(')
        {
            bracketopen = true;
        }
        if (!bracketopen)
        {
            if (inputcmd[i] != ',')
            {
                temp += inputcmd[i];
            }
            if (inputcmd[i] == ',')
            {
                if (temp != "")
                {
                    Commands.push_back(temp);
                }
                temp = "";
            }
        }
        else
        {
            temp += inputcmd[i];
        }
        if (inputcmd[i] == ')')
        {
            bracketopen = false;
        }
    }

    temp = "";
    bracketopen = false;
    if (inputcmd[charsininput - 1] == ')')
    {
        bracketopen = true;
    }

    for (int i = charsininput - 1; i >= 0; i--)
    {
        if (inputcmd[charsininput - 1] == ')')
        {
            if (inputcmd[i] == '(')
            {
                bracketopen = false;
            }
            if (bracketopen)
            {
                temp += inputcmd[i];
            }
            if (!bracketopen)
            {
                if (inputcmd[i] != ',')
                {
                    temp += inputcmd[i];
                }
                if (inputcmd[i] == ',')
                {
                    break;
                }
            }
        }
        else
        {
            if (inputcmd[i] != ',')
            {
                temp += inputcmd[i];
            }
            if (inputcmd[i] == ',')
            {
                break;
            }
        }
    }

    reverse(temp.begin(), temp.end());
    Commands.push_back(temp);

    // Everything above is to take input
    // Cybersecurity part starts here for int main
    // IDK if algorithm has any encryption. I used it to reverse my string.

    // std::cout << "\n--- Parsed Data --;-\n";
    // std::cout << "Message: " << inputmsg << "\n";
    // std::cout << "Array Items:\n";
    // for (size_t i = 0; i < Commands.size(); ++i)
    // {
    //     std::cout << "  [" << i << "] -> \"" << Commands[i] << "\"\n";
    // }

    // Checking if the string is printed of ascii
    // cout<<AsciiConverter(inputmsg);
    // Asciiconverter test check \/
    // for(int i = 0; i<inputmsg.length();i++){
    //     cout<<MessageReader(inputmsg)[i]<<endl;
    // }
    // Message reader works!

    // Executing the code together
    // Encrypted = MessageReader((inputmsg));
    string output;
    for (int i = 0; i < Commands.size(); i++)
    {
        if (Commands[i].find("RSA_ENC(") != string::npos)
        {
            output = rsaEncrypt(MessageReader(inputmsg), RSAcmdNumExtract2ndNUM(Commands[i]), RSAcmdNumExtractN(Commands[i]));
            cout << "After " << Commands[i] << ": " << output << endl;
            inputmsg = output;
        }
        if (Commands[i].find("RSA_DEC") != string::npos)
        {
            output = rsaDecrypt(DEC_Read(inputmsg), RSAcmdNumExtract2ndNUM(Commands[i]), RSAcmdNumExtractN(Commands[i]));
            cout << "After " << Commands[i] << ": " << output << endl;
            inputmsg = output;
        }
        if (Commands[i].find("B64_ENC") != string::npos)
        {
            output = Base64_enc(MessageReader(inputmsg));
            cout << "After " << Commands[i] << ": " << output << endl;
            inputmsg = output;
        }
        if (Commands[i].find("B64_DEC") != string::npos)
        {
            output = Base64_dec(Base64_splitter(inputmsg));
            cout << "After " << Commands[i] << ": " << output << endl;
            inputmsg = output;
        }
        if(Commands[i].find("FIND_D") != string::npos){
            cout<<RSAcmdNumExtractN(Commands[i])<<endl<< FindingSecondNumber(Commands[i])<< endl<<RSAcmdNumExtract2ndNUM(Commands[i])<<endl;
            cout<<"After "<<Commands[i] << ": " << Find_D(RSAcmdNumExtractN(Commands[i]), FindingSecondNumber(Commands[i]), RSAcmdNumExtract2ndNUM(Commands[i]))<<endl;
        }
        if(Commands[i].find("RSATOY") != string::npos){
            RSATOY();
        }

    }
    // Testing decryption input case
    // for (int  i = 0; i<Encrypted.size(); i++){
    //     cout<<Encrypted[i]<<"-";
    // }

    // for (int i = 0; i<DEC_Read(inputmsg).size();i++){
    //     cout<<DEC_Read(inputmsg)[i]<<endl;
    // }



    return 0;
}