//  int type - тип лексемы:
//  1 ключевое слово
//  2 идентификатор
//  3 константа
//  4 разделяющий символ
//  5 бинарная операция
//  6 унарная операция

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char word[100], sym;
int i=0, str=1;
FILE *fo, *fw;

void write(char *_word, int _str)
{
    int type=0;
    if(strcmp(_word, "begin")==0 || strcmp(_word, "end")==0 || strcmp(_word, "var")==0) type = 1;
    else if (_word[0]>=65 && _word[0]<=90 || _word[0]>=97 && _word[0]<=122) type = 2;
    else if (_word[0]>=48 && _word[0]<=57) type = 3;
    else if (_word[0]==',' || _word[0]==';') type = 4;
    else if (_word[0]=='+' || _word[0]=='-' || _word[0]=='*' || _word[0]=='/' || _word[0]=='=') type = 5;
    fprintf(fw, "%s\t%d\t%d\n", _word, _str, type);
}

int main()
{    
    fo=fopen("input.txt","r");
    fw=fopen("output.txt","w");

    while(!feof(fo))
    {
        fscanf(fo, "%c", &sym);
        switch(sym)
        {
        case '\n':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]='\0';
            str++;
            break;
        case ' ':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]='\0';
            break;
        case ',':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]=',';
            i++;
            break;
        case ';':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]=';';
            i++;
            break;
        default:
            word[i]=sym;
            i++;
            break;
        }
    }
    word[i-1]='\0';
    write(word, str);
    fclose(fo);
    fclose(fw);
    return 0;
}

