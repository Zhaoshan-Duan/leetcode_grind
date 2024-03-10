package algorithm.sorting;

import java.util.Arrays;

public class BubbleSort {
  static void bubbleSort(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      for (int j = 0; j < arr.length - i - 1; j++) {
        if (arr[j] > arr[j+1]) {
          int temp = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = temp;
        }
      }
    }
  }

  public static void main(String[] args) {
    int[] input = {1, 3, 7, 4, 2};
    Arrays.stream(input).forEach(System.out::print);
    bubbleSort(input);
    System.out.println();
    Arrays.stream(input).forEach(System.out::print);
  }
}