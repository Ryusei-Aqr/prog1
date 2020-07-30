#include<stdio.h>

char grade_char(int);//点数を渡して評定を返す
int char_point(char);//評定を渡してGPAを返す

int main(){
    int ten,tensu,tani,tanisu=0,gp=0,cnt=0,sum_gp=0,sum=0;
    double gpa;
    char hyotei;
    while(1){
        printf("評定と単位数を入力してください:");
        tensu=scanf("%d %d",&ten,&tani);
        //scanf("%d",&tani);
        if(tensu==EOF)break;
        hyotei=grade_char(ten);//点数によって評定が返る
        gp=char_point(hyotei);//評定によってgpが返る
        printf("%d 点の評定は %c で、Grade Point (GP) は %d です。　(%d単位)\n",ten,hyotei,gp,tani);
    
    sum_gp=(gp*tani);
    tanisu+=tani;
    sum+=sum_gp;
    //printf("%d\n",sum);
}
    gpa=(double)(sum)/tanisu;
        printf("\nGrade Point Average(GPA):%0.3f, 単位数:%d\n",gpa,tanisu);
        return 0;
}

char grade_char(int score){//成績の文字を返す関数
if(0<=score && score<=34){
    return 'F';
}
else if(35<=score && score<=49){
    return 'D';
}
else if(50<=score && score<=64){
    return 'C';
}
else if(65<=score && score<=79){
    return 'B';
}
else {
    return 'A';
}
}

int char_point(char point){//gradepointを返す関数
    if(point=='F'){
        return 0;
    }
    else if(point=='D'){
        return 0;
    }
    else if(point=='C'){
        return 2;
    }
    else if(point=='B'){
        return 3;
    }
    else {
        return 4;
    }
}
