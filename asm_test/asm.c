#include <stdio.h>
void check(){
    char a;
    __asm{
        MOV AL,20
        MOV a,AL
    }
    printf("%d",a)

}
int main(){
    check();
}