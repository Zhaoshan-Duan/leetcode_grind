package algorithm.sorting;

import java.util.Arrays;

public class SelectionSort {

  static void selectionSort(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      int minIdx = i;
      for (int j = i + 1; j < arr.length; j++) {
        if (arr[j] < arr[minIdx]) {
          minIdx = j;
        }
      }
      int temp = arr[minIdx];
      arr[minIdx] = arr[i];
      arr[i] = temp;
    }
  }

  public static void main(String[] args) {
    int[] input = {1, 3, 7, 4, 2};
    Arrays.stream(input).forEach(System.out::print);
    selectionSort(input);
    System.out.println();
    Arrays.stream(input).forEach(System.out::print);
  }
}
