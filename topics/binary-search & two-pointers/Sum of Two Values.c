#include <stdio.h>


void findPair(int arr[], int n, int target_sum) {
  int left = 0;
  int right = n - 1;

  while (left < right) {
    int current_sum = arr[left] + arr[right];
    if (current_sum == target_sum) {
      printf("%d %d\n", left + 1,
             right + 1); // Adding 1 to convert to 1-indexed positions
      return;
    } else if (current_sum < target_sum) {
      left++;
    } else {
      right--;
    }
  }

  printf("-1\n");
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);

  int arr[n];
  // Input array
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Find positions of the pair with sum x
  findPair(arr, n, x);

  return 0;
}
