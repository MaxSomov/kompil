#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char word[100], sym;
int tmp;
int i=0, str=1;
FILE *fo, *fw;

void write(char *_word, int _str)
{
    if (strcmp(_word, "")!=0){
        int type=0;
        if (strcmp(_word, "begin")==0) type = 1;
        else if (strcmp(_word, "end")==0) type = 2;
        else if (strcmp(_word, "var")==0) type = 15;
        else if (strcmp(_word, ",")==0) type = 3;
        else if (strcmp(_word, ";")==0) type = 4;
        else if (strcmp(_word, ",")==0) type = 5;
        else if (strcmp(_word, "+")==0) type = 6;
        else if (strcmp(_word, "-")==0 && (tmp==10 || tmp==11)) type = 16;
        else if (strcmp(_word, "-")==0) type = 7;
        else if (strcmp(_word, "*")==0) type = 8;
        else if (strcmp(_word, "/")==0) type = 9;
        else if (strcmp(_word, "=")==0) type = 10;
        else if (strcmp(_word, "(")==0) type = 11;
        else if (strcmp(_word, ")")==0) type = 12;
        else if (_word[0]>=65 && _word[0]<=90 || _word[0]>=97 && _word[0]<=122)
        {
            type = 13;
            for (int i=1; i<strlen(_word); i++)
            {
                if (_word[i]<65 || _word[i]>90 && _word[i]<97 || _word[i]>122)
                {
                    type=0;
                }
            }
        }
        else if (_word[0]>=48 && _word[0]<=57)
        {
            type = 14;
            for (int i=1; i<strlen(_word); i++)
            {
                if (_word[i]<48 || _word[i]>57)
                {
                    type=0;
                }
            }
        }



        //    else if (strcmp(_word, ",")==0 || strcmp(_word, ";")==0) type = 4;
        //    else if (strcmp(_word, "*")==0 || strcmp(_word, "/")==0) type = 5;
        //    else if (strcmp(_word, "-")==0 && tmp!=2) type = 6;
        //    else if (strcmp(_word, "-")==0 || strcmp(_word, "+")==0) type = 7;
        //    else if (strcmp(_word, "=")==0) type = 8;
        fprintf(fw, "%s\t%d\t%d\n", _word,  type, _str);
         tmp = type;
    }
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
        case '-':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]='-';
            word[1]='\0';
            write(word, str);
            break;
        case '+':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]='+';
            word[1]='\0';
            write(word, str);
            break;
        case '=':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]='=';
            word[1]='\0';
            write(word, str);
            break;
        case '*':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]='*';
            word[1]='\0';
            write(word, str);
            break;
        case '/':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]='/';
            word[1]='\0';
            write(word, str);
            break;
        case '(':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]='(';
            word[1]='\0';
            write(word, str);
            break;
        case ')':
            word[i]='\0';
            write(word, str);
            i=0;
            word[0]=')';
            word[1]='\0';
            write(word, str);
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

