/*
20.
1) 	Скопировать из файла F1 в файл F2 все строки, в которых есть одинаковые слова.
2) 	Определить количество гласных букв в последней строке  файла F2.
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <clocale>
#include <filesystem>
using namespace std;

string directory = "C:\\projects\\lab_9\\";

void output(string f);
void copy(string f1, string f2);
void vowelCount(string f);

int main()
{
    system("chcp 1251");
    cout << "Запись в первом файле:" << endl;
    output(directory+"F1.txt");
    cout << endl;

    copy(directory+"F1.txt", directory+"F2.txt");

    cout << "Запись во втором файле:" << endl;
    output(directory+"F2.txt");
    cout << endl;

    cout << "Количество гласных букв в последней строке второго файла:" << endl;
    vowelCount(directory+"F2.txt");
    cout << endl;
    return 0;
}

void output(string f)
{
    ifstream fin(f);
    string str;

    while (getline(fin, str))
        cout << str << endl;
    fin.close();
}

void copy(string f1, string f2)
{
    ifstream fin(f1);
    ofstream fout(f2);

    string line;
    while (getline(fin, line))
    {
        bool isFirstWord = true, toCopy=false;
        string firstWord = "";
        string tempWord = "";

        for (int i=0;i<line.length();i++) {
            if (line[i]==' ') {
                isFirstWord=false;
                tempWord="";
            }
            else tempWord+=line[i];
            if (isFirstWord) firstWord+=line[i];

            if (i==line.length()-1) if (firstWord==tempWord) fout << line << endl;
        }
    }
    fin.close();
    fout.close();
}

void vowelCount(string f)
{
    ifstream fin(f);
    string line, vowels="aeiouуеыаоэяиюё";
    int res=0;
    while (getline(fin, line))
    {
        res=0;
        for (int i=0;i<line.length();i++) {
            for (int j=0;j<vowels.length();j++) {
                char suka=line[i], blyat=vowels[j];
            if (int(line[i])==int(vowels[j])) {
            res++;}}
        }
        
    }
    fin.close();

    cout << res;
}