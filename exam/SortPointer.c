#include<stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}

void sort(int *nums, int numsSize) {
    int ptr = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0) {
            swap(&nums[i], &nums[ptr]);
            ++ptr;
        }
    }
    for (int i = ptr; i < numsSize; ++i) {
        if (nums[i] == 1) {
            swap(&nums[i], &nums[ptr]);
            ++ptr;
        }
    }
}

int main() {
  int nums[6] = {2,0,2,1,1,0};
  sort(nums, 6);
  for(int loop = 0; loop < 6; loop++)
      printf("%d ", nums[loop]);
  return 0;
}