package kotlin.algorithm.searching

class BinarySearch {
    fun basicBinarySearch(array: IntArray, target: Int): Int {
        var left = 0;
        var right = array.size - 1;

        while( left <= right) {
            var mid = left + (right - left) / 2
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
}