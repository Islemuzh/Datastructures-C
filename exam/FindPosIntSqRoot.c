int findPositiveIntegerSquareRoot(int n) {
  int i;
  for (i = 1; i<=n; i++){
    if (i*i == n){ //if i is square root of n
        return i;
    }
  }
  return -1;
}
