package kotlin.algorithm.sorting
fun bubbleSort(arr: IntArray) {
    for (i in 0..arr.size-1) {
        for(j in 0 .. arr.size-1-i) {
            if (arr[j] > arr[j+1]) {
                val temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = arr[j]
            }
        }
    }
}

fun main() {
    val array = intArrayOf(1, 3, 7, 4, 2)
    bubbleSort(array)
    println("Sorted: ${array.contentToString()}")
}
