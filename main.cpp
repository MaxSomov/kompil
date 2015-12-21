#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cctype>
#include <string>
#include <fstream>
#include <conio.h>

//using namespace std;
char word[100], sym, a[10], b[10];
int tmp;
int i=0, str=1;
FILE *fo, *fw;
FILE *input;

string buf,digit,alpha,var;
string adres[25];

int checkpos(string var)
{
    int pos=-1;
    for (int i=0;i<25;i++)
    {
        if (!var.compare(adres[i]))
            return i;
    }
    return pos;
}

void A();
void B();
void C();
void D();
void E();
void F();
void G();
void H();
void I();
void J();
int K();
void L();
void Z();
void x1();
void x2();
void x3();
void x4();
void x5();

void write(char *_word, int _str)
{
    if (strcmp(_word, "")!=0){
        int type=0;
        if (strcmp(_word, "begin")==0) type = 1;
        else if (strcmp(_word, "end")==0) type = 2;
        else if (strcmp(_word, "var")==0) type = 5;
        else if (strcmp(_word, ",")==0) type = 3;
        else if (strcmp(_word, ";")==0) type = 4;
        else if (strcmp(_word, "+")==0) type = 6;
        else if (strcmp(_word, "-")==0 && (tmp==10 || tmp==11)) type = 15;
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

void lex_anal()
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
}


//Объявление переменных
void A()
{
    fscanf(fo, "%s", &word);
    fscanf(fo, "%s", &b);
    fscanf(fo, "%s", &a);
    if (strcmp(word, "var")!=0) printf("%s: ошибка в  ключевом слове var\n", a);
    D();
}

//описание вычислений
void B()
{
    if (strcmp(word, "begin")!=0) printf("%s: ошибка в ключевом слове begin\n", a);
    fscanf(fo, "%s", &word);
    fscanf(fo, "%s", &b);
    fscanf(fo, "%s", &a);
    C();
    //    fscanf(fo, "%s", &word);
    //    fscanf(fo, "%s", &b);
    //    fscanf(fo, "%s", &a);
    if (strcmp(word, "end")!=0) printf("%s: ошибка в ключевом слове end\n", a);
}

//Список присваиваний
void C()
{

    F();
    x2();
}

//Список переменных
void D()
{
    fscanf(fo, "%s", &word);
    fscanf(fo, "%s", &b);
    fscanf(fo, "%s", &a);
    E();
    x1();
}

//Идентификатор
void E()
{
    if (strcmp(b, "0")==0)
        printf("%s: ошибка в идентификаторе '%s'\n", a, word);
}

//Присваивание
void F()
{
    E();
    fscanf(fo, "%s", &word);
    fscanf(fo, "%s", &b);
    fscanf(fo, "%s", &a);
    if (strcmp(word, "=")!=0)
        printf("%s: ошибка присваивания\n", a);
    G();
}

//выражение
void G()
{
    fscanf(fo, "%s", &word);
    fscanf(fo, "%s", &b);
    fscanf(fo, "%s", &a);

    if (strcmp(b, "15")==0)
    {
        fscanf(fo, "%s", &word);
        fscanf(fo, "%s", &b);
        fscanf(fo, "%s", &a);
        I();
    }
    else
        I();

}

//унарная операция
//void H()
//{

//}

//подвыражение
void I()
{
    if (strcmp(word, "(")==0)
    {
        G();
        fscanf(fo, "%s", &word);
        fscanf(fo, "%s", &b);
        fscanf(fo, "%s", &a);
        //        if (strcmp(word, ")")!=0) printf("%s: отсутствует ')'\n", a);
        x5();
    }
    else
    {
        J();
        x5();
    }
}

//операнд
void J()
{
    //    fscanf(fo, "%s", &word);
    //    fscanf(fo, "%s", &b);
    //    fscanf(fo, "%s", &a);
    if(strcmp(b, "13")!=0)
        if (strcmp(b, "14")!=0)
            printf("%s: ошибка операнда '%s'\n", a, word);
}

//бинарная операция
int K()
{
    //    fscanf(fo, "%s", &word);
    //    fscanf(fo, "%s", &b);
    //    fscanf(fo, "%s", &a);
    if (strcmp(word, "+")!=0)
        if (strcmp(word, "-")!=0)
            if (strcmp(word, "*")!=0)
                if (strcmp(word, "/")!=0)
                    return 1;
    fscanf(fo, "%s", &word);
    fscanf(fo, "%s", &b);
    fscanf(fo, "%s", &a);
    return 0;
    //    if (k<6 || k>9) printf("%s: ошибка бинарной операции %d\n", a);
}

void L()
{

}

//Программа
void P()
{
    A();
    B();
}

//нетерминал, полученный в результате фаторизации
void Z()
{
    if (K()==1) return;
    I();
    x5();
}

void x1()
{
    fscanf(fo, "%s", &word);
    fscanf(fo, "%s", &b);
    fscanf(fo, "%s", &a);
    if (strcmp(word, ",")==0)
        D();
    //    else B();

}

void x2()
{
    fscanf(fo, "%s", &word);
    fscanf(fo, "%s", &b);
    fscanf(fo, "%s", &a);
    if (strcmp(word, "end")!=0)
        C();
    //    else printf ("конец");
}

void x5()
{
    fscanf(fo, "%s", &word);
    fscanf(fo, "%s", &b);
    fscanf(fo, "%s", &a);
    if(strcmp(b, "4")!=0)
        Z();
    //    else printf ("конец выражения\n");
}

void syntax_anal()
{
    fo=fopen("output.txt","r");
    P();
    fclose(fo);
}

void polska_notation()
{
    int k;
    char stack[500], result[500];
    strcpy(stack, "");
    strcpy(result, "");
    fo = fopen("output.txt", "r");
    fw = fopen("polska.txt", "w");

    fscanf(fo, "%s", &word);
    fscanf(fo, "%d", &k);
    fscanf(fo, "%s", &a);

    do
    {
        fscanf(fo, "%s", &word);
        fscanf(fo, "%d", &k);
        fscanf(fo, "%s", &a);

        if(k==1) break;

        if(k!=3)
        {
            strcat(result, word);
            strcat(result, " ");
        }
    }
    while(true);

    fprintf(fw, "%s\n", result);
    strcpy(result, "");

    do
    {
        fscanf(fo, "%s", &word);
        fscanf(fo, "%d", &k);
        fscanf(fo, "%s", &a);

        if(k==2) break;

        strcat(result, word);
        strcat(result, " ");

        fscanf(fo, "%s", &word);
        fscanf(fo, "%d", &k);
        fscanf(fo, "%s", &a);

        //        strcat(result, "= ");

        do
        {
            fscanf(fo, "%s", &word);
            fscanf(fo, "%d", &k);
            fscanf(fo, "%s", &a);

            switch(k)
            {
            case 13:
                strcat(result, word);
                strcat(result, " ");
                break;

            case 14:
                strcat(result, word);
                strcat(result, " ");
                break;

            case 8:
                while(stack[strlen(stack)-1]=='/' || stack[strlen(stack)-1]=='*')
                {
                    strcat(result, &stack[strlen(stack)-1]);
                    strcat(result, " ");
                    stack[strlen(stack)-1] = '\0';
                }
                strcat(stack, word);
                break;

            case 9:
                while(stack[strlen(stack)-1]=='*' || stack[strlen(stack)-1]=='/')
                {
                    strcat(result, &stack[strlen(stack)-1]);
                    strcat(result, " ");
                    stack[strlen(stack)-1] = '\0';
                }
                strcat(stack, word);
                break;

            case 6:
                while(stack[strlen(stack)-1]=='*' || stack[strlen(stack)-1]=='/' || stack[strlen(stack)-1]=='-' || stack[strlen(stack)-1]=='+')
                {
                    strcat(result, &stack[strlen(stack)-1]);
                    strcat(result, " ");
                    stack[strlen(stack)-1] = '\0';
                }
                strcat(stack, word);
                break;

            case 7:
                while(stack[strlen(stack)-1]=='*' || stack[strlen(stack)-1]=='/' || stack[strlen(stack)-1]=='+' || stack[strlen(stack)-1]=='-')
                {
                    strcat(result, &stack[strlen(stack)-1]);
                    strcat(result, " ");
                    stack[strlen(stack)-1] = '\0';
                }
                strcat(stack, word);
                break;

            case 11:
                strcat(stack, word);
                break;

            case 12:
                while(stack[strlen(stack)-1]!='(')
                {
                    strcat(result, &stack[strlen(stack)-1]);
                    strcat(result, " ");
                    stack[strlen(stack)-1] = '\0';
                }
                stack[strlen(stack)-1] = '\0';
                break;

            case 15:
                while(stack[strlen(stack)-1]=='*' || stack[strlen(stack)-1]=='/')
                {
                    strcat(result, &stack[strlen(stack)-1]);
                    strcat(result, " ");
                    stack[strlen(stack)-1] = '\0';
                }
                strcat(stack, "~");
                break;
            }
        }
        while(k!=4);
        for (int i=strlen(stack)-1; i>=0; i--)
        {
            strcat(result, &stack[i]);
            strcat(result, " ");
            stack[i] = '\0';
        }
        strcat(result, "=");
        fprintf(fw, "%s\n", result);
        strcpy(stack, "");
        strcpy(result, "");
    }
    while(true);

    fclose(fo);
    fclose(fw);
}

void code_gen()
{
    ifstream postfix ("polska.txt");
    int st=0;
    int a=0;
    getline(postfix,buf);
    for (int i=0;i<buf.size();i++)
    {
        do
        {
            adres[a].push_back(buf[i]);
            i++;
        }
        while (buf[i]!=32);
        a++;
    }
    buf.clear();
    while(!postfix.eof())
    {
        getline(postfix,buf);
        int pos,j=0;
        do
        {
            var.push_back(buf[j]);
            j++;
        }
        while (buf[j]!=32);
        for (int i=j;i<buf.size();i++)
        {
            if (isdigit(buf[i]))
            {
                while (isdigit(buf[i]))
                {
                    digit.push_back(buf[i]);
                    i++;
                }
                cout<<"LIT "<<digit<<"\n";
                digit.clear();
            }
            if (isalpha(buf[i]))
            {
                while (isalpha(buf[i]))
                {
                    alpha.push_back(buf[i]);
                    i++;
                }
                if (checkpos(alpha)!=-1)
                {
                    cout<<"LOAD "<<checkpos(alpha)<<"\n";
                }
                else
                    cout<<"Unidentified variable "<<alpha<<"\n";
                alpha.clear();
            }
            if (buf[i]=='=')
            {
                pos=checkpos(var);
                if (pos!=-1)
                {
                    cout<<"STO "<<pos<<"\n";
                }
                else
                {
                    cout<<"Unidetified variable "<<var<<"\n";
                }
            }
            if (buf[i]=='*')
                cout<<"MUL "<<"\n";
            if (buf[i]=='/')
                cout<<"DIV "<<"\n";
            if (buf[i]=='+')
                cout<<"ADD "<<"\n";
            if (buf[i]=='-')
                cout<<"SUB "<<"\n";
            if (buf[i]=='~')
                cout<<"NOT "<<"\n";
        }
        var.clear();
        buf.clear();
    }
    postfix.close();

    getch();
}

int main()
{
    lex_anal();
    polska_notation();
    return 1;
}
