#include <stdio.h>
#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value)
{
    if(top<SIZE-1)
    {
        if (top < 0)
        {
            stack[0] = value;
            top = 0;
        }
        else
        {
            stack[top+1] = value;
            top++;
        }
    }
    else
    {
        printf("Stackoverflow!!!!\n");
    }
}

int pop()
{
    if(top >= 0)
    {
        int n = stack[top];
        top--;
        return n;
    }
}

int Top()
{
    return stack[top];
}

int isempty()
{
    return top<0;
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d,",stack[i]);
    }
    printf("\n");
}

int isPopOrder(int pushS[], int popS[], int size) {
  int j = 0;
  for (int i=0;i<size;i++) {
    push(pushS[i]);
    while (!isempty() && Top() == popS[j]) {
        pop();
        j++;
    }
  }
  return isempty();
}

int main()
{
    int pushS[5] = {1,2,3,4,5};
    int popS1[5] = {4,5,3,2,1};
    int popS2[5] = {4,3,5,1,2};
    printf("%d \n", isPopOrder(pushS, popS1, 5));
    top = -1; // reset the stack
    printf("%d \n", isPopOrder(pushS, popS2, 5));
    return 0;
}