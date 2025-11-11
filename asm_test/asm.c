#include <stdio.h>
void check(){
    char a;
    __asm{
        MOV AL,20
        MOV a,AL
    }
    printf("%d",a);

}
void add(){

}
void substract(){

}
void multiply(){
}
void double_add(){

}
void double_substract(){

}
void double_multiply(){

}
int main(){
FILE *fptr;
FILE *sptr;
FILE *tptr;
fptr=fopen("");
check();
}