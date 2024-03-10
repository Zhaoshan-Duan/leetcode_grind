package algorithm.sorting;

import java.util.Arrays;

public class InsertionSort {
  static void insertionSort(int[] arr) {
    for( int i = 1; i < arr.length; i++) {
      int temp = arr[i];
      // shifting
      int j = i - 1;
      while(j >= 0 && arr[j] > temp ) {
        arr[j+1] = arr[j];
        j--;
      }
      // insertion
      arr[j+1] = temp;
    }

  }

  public static void main(String[] args) {
    int[] input = {1, 3, 7, 4, 2};
    Arrays.stream(input).forEach(System.out::print);
    insertionSort(input);
    System.out.println();
    Arrays.stream(input).forEach(System.out::print);
  }
}
