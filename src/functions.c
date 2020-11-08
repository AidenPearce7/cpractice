#include <stdio.h>

int multiply(int a,int b);
int add(int a, int b);
int subtract(int a,int b);

int main(){
    printf("%d",add(multiply(subtract(10,5),8),multiply(2,11)));
}
int multiply(int a,int b){
    return a*b;
}
int add(int a, int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}
