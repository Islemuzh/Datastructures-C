#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20001
typedef struct{
    int* data[MaxSize];
    int rear, front;
}queue ;

void InitQueue(queue* s) {
    s->rear = s->front = 0;
}

int QueueEmpty(queue* s) {
    return s->rear == s->front;
}

int QueuePush(queue* s, int* x) {
    if ((s->rear + 1) % MaxSize == s->front) return 0;
    else {
        s->data[s->rear] = x;
        s->rear = (s->rear + 1) % MaxSize;
        return 1;
    }
}

int* QueuePop(queue* s) {
    int* res = s->data[s->front];
    s->front = (s->front + 1) % MaxSize;
    return res;
}

int* QueueTop(queue* s) {
    return s->data[s->front];
}


typedef struct {
    queue student;
    int student_size;
} System;


System* SystemCreate() {
    System* obj = (System*)malloc(sizeof(System));
    InitQueue(&obj->student);
    obj->student_size = 0;
    return obj;
}

void systemEnqueue(System* obj, int* student) {
    QueuePush(&obj->student, student);
    obj->student_size++;
}

int* systemDequeueMale(System* obj) {
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = -1, res[1] = -1;
    if (QueueEmpty(&obj->student)) return res;
    else {
        for (int i=0;i<obj->student_size;i++) {
            res = QueuePop(&obj->student);
            if (res[1] == 1) {
                obj->student_size--;
                return res;
            } else {
                QueuePush(&obj->student, res);
            }
        }
        return res;
    }   
}

int* systemDequeueFemale(System* obj) {
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = -1, res[1] = -1;
    if (QueueEmpty(&obj->student)) return res;
    else {
        for (int i=0;i<obj->student_size;i++) {
            res = QueuePop(&obj->student);
            if (res[1] == 0) {
                obj->student_size--;
                return res;
            } else {
                QueuePush(&obj->student, res);
            }
        }
        return res;
    }
}

int* systemDequeueAny(System* obj) {
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = -1, res[1] = -1;
    if (QueueEmpty(&obj->student)) return res;
    else {
        return QueuePop(&obj->student);
    }
}

int main() {
  System* obj = SystemCreate();
  int female1[2] = {0, 0};
  int female2[2] = {1, 0};
  int male1[2] = {2, 1};
  systemEnqueue(obj, female1);
  systemEnqueue(obj, female2);
  systemEnqueue(obj, male1);
  int* ret1 = systemDequeueMale(obj);
  printf("{%d, ", ret1[0]);
  printf("%d} \n", ret1[1]);
  int* ret2 = systemDequeueFemale(obj);
  printf("{%d, ", ret2[0]);
  printf("%d} \n", ret2[1]);
  int* ret3 = systemDequeueAny(obj);
  printf("{%d, ", ret3[0]);
  printf("%d} \n", ret3[1]);
  return 0;
}