#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20001
typedef struct{
    int data[MaxSize];
    int rear, front;
}queue ;

void InitQueue(queue* s) {
    s->rear = s->front = 0;
}

int QueueEmpty(queue* s) {
    return s->rear == s->front;
}

int QueuePush(queue* s, int x) {
    if ((s->rear + 1) % MaxSize == s->front) return 0;
    else {
        s->data[s->rear] = x;
        s->rear = (s->rear + 1) % MaxSize;
        return 1;
    }
}

int QueuePop(queue* s) {
    int res = s->data[s->front];
    s->front = (s->front + 1) % MaxSize;
    return res;
}

int QueueTop(queue* s) {
    return s->data[s->front];
}


typedef struct {
    queue male;
    queue female;
    int male_size;
    int female_size;
} System;


System* systemCreate() {
    System* obj = (System*)malloc(sizeof(System));
    InitQueue(&obj->male);
    InitQueue(&obj->female);
    obj->male_size = 0;
    obj->female_size = 0;
    return obj;
}

void systemEnqueue(System* obj, int* student) {
    if (student[1] == 1) {
        QueuePush(&obj->male, student[0]);
        obj->male_size++;
    }else {
        QueuePush(&obj->female, student[0]);
        obj->female_size++;
    }
}

int* systemDequeueMale(System* obj) {
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = -1, res[1] = -1;
    if (QueueEmpty(&obj->male)) return res;
    else {
        res[0] = QueuePop(&obj->male);
        res[1] = 1;
        obj->male_size--;
        return res;
    }
}

int* systemDequeueFemale(System* obj) {
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = -1, res[1] = -1;
    if (QueueEmpty(&obj->female)) return res;
    else {
        res[0] = QueuePop(&obj->female);
        res[1] = 0;
        obj->female_size--;
        return res;
    }
}

int* systemDequeueAny(System* obj) {
    int* res = (int*)malloc(sizeof(int) * 2);
    res[0] = -1, res[1] = -1;
    if (QueueEmpty(&obj->male) && QueueEmpty(&obj->female)) return res;
    else if (obj->male_size == 0) return systemDequeueFemale(obj);
    else if (obj->female_size == 0) return systemDequeueMale(obj);
    else {
        if (QueueTop(&obj->male) < QueueTop(&obj->female)) {
            return systemDequeueMale(obj);
        }else {
            return systemDequeueFemale(obj);
        }
    }
    return res;
}

int main() {
  System* obj = systemCreate();
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