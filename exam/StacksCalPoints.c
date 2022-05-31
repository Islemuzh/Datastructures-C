#include <stdio.h>
#include <stdlib.h>

int calPoints(char ** ops, int opsSize){
  if(0 >= opsSize)
    return 0;

  int stack[opsSize];
  int top = -1;
  int sum = 0;
  for(int i = 0; i < opsSize; i++) {
    switch(ops[i][0]) {
        case '+' :
            stack[++top] = stack[top] + stack[top - 1];
            sum += stack[top];
        break;
        case 'D' :
            stack[++top] = stack[top] * 2;
            sum += stack[top];
        break;
        case 'C' :
            sum -= stack[top--];
        break;
        default :
            stack[++top] = atoi(ops[i]);
            sum += stack[top];
    }
  }
  
  return sum;
}

int main() {
  char* string[8]={"5","-2","4","C","D","9","+","+"};
  printf("%d \n", calPoints(string, 8));
  return 0;
}