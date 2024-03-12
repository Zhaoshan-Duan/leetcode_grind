package algorithm.searching;

public class BinarySearch {
  public static int basicBinarySearch(int[] array, int target){
    int left = 0;
    int right = array.length - 1;

    while (left <= right ) {
      int mid = left + (right - left) / 2;

      if (array[mid] == target) {
        return mid;
      } else if (array[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }


  public static int binarySearch(int[] array, int target) {
    int low = 0, high = array.length - 1;
    int guess, mid;

    while (low < high) {
      mid = (low + high) / 2;
      guess = array[mid];
      if (guess == target) {
        return mid;
      } else if (guess > target) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }

  public static void main(String[] args) {
    int[] array = {1, 3, 5, 7, 9};
    int target = 3;

  }
}
