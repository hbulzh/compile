#include <bits/stdc++.h>
#define NULL 0
using namespace std;
char GetChar(FILE* fp){
    char ch;
    ch = fgetc(fp);
    return ch;
}
char GetBC(FILE* fp){
    char ch;
    do{
        ch = GetChar(fp);
    }while(ch==' '|| ch == '\t' || ch == '\n');
    return ch;
}
void Concat(char ch,char strToken[]){
    char str[2];
    str[0] = ch;
    str[1] = '\0';
    strcat(strToken,str);
}
int IsLetter(char ch){
    if(ch >= 'a' &&ch <= 'z') return 1;
    return 0;
}
int Reserve(char strToken[]){
    int code = 0,i;
    char keyWord[7][6] = {"if","then","else","while","do","int"};
    for(i = 0; i < 6; ++i){
        if(strcmp(strToken,keyWord[i]) == 0){
            code = i+1;break;
        }
    }
    return code;
}
int SearchOP(char ch){
    int code = 0;
    char OP[11] = {'+','-','*','/','<','>','=','!'};
    for(int i = 0; i < 10; ++i){
        if(ch ==OP[i]){
            code = i+1;break;
        }
    }
    return code;
}
char Retract(FILE*fp,char ch){

    fseek(fp,-1L,1);
    return ' ';
}
void ProError(){
    printf("输入错误！\n");
    return ;
}
FILE* scan(FILE *fp){
    char ch;
    char strToken[10];
    strToken[0] = '\0';
    ch = GetBC(fp);
    if(feof(fp)) return fp;

    if(IsLetter(ch)){
        while(IsLetter(ch) || isdigit(ch)){
            Concat(ch,strToken);
            ch=GetChar(fp);
        }
        ch = Retract(fp,ch);
        if(Reserve(strToken)) printf("<1,\"%s\">\n",strToken);
        else printf("<2,\"%s\">\n",strToken);
    }
    else if(ch >= '1' &&ch <= '9'){
        while(isdigit(ch)){
            Concat(ch,strToken);
            ch = GetChar(fp);
        }
        ch = Retract(fp,ch);
        printf("<3,\"%s\">\n",strToken);
    }
    else if(ch == '0'){
        ch = GetChar(fp);
        if('1' <= ch && ch <= '7'){
            while(ch >= '0' && ch <= '7'){
                Concat(ch,strToken);
                ch = GetChar(fp);
            }
            ch = Retract(fp,ch);
            printf("<3,\"%s\">\n",strToken);
        }
        else if(ch == 'x'){
            ch = GetChar(fp);
            while(isdigit(ch)||(ch>='a' &&ch <='f')){
                Concat(ch,strToken);
                ch = GetChar(fp);
            }
            ch = Retract(fp,ch);
            printf("<3,\"%s\">\n",strToken);
        }
        else {
            ch = Retract(fp,ch);
            printf("<1,0>\n");
        }
    }
    else if(SearchOP(ch)){
        printf("<4,\"%c\">\n",ch);
    }
    else printf("<5,\"%c\">\n",ch);
    return fp;

}
int main()
{
  FILE * fp;
  if((fp = fopen("1.txt","r"))==NULL)
  {
        printf("open file falsed");
        exit(0);
  }
  printf("词法分析结果如下:\n");
  while(!feof(fp)){
        fp = scan(fp);
   //cout << (char)fgetc(fp);
  }
  fclose(fp);
  fp = NULL;
}
