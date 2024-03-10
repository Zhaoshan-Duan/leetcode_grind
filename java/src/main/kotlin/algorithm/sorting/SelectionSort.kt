package kotlin.algorithm.sorting

fun selectionSort(arr: IntArray) {
    for (i in 0 .. arr.size-1) {
       var minIdx = i
       for (j in 0 .. arr.size-1) {
           if (arr[j] < arr[minIdx]) {
               minIdx = j
           }
       }
        var temp = arr[i]
        arr[i] = arr[minIdx]
        arr[minIdx] = temp
    }
}

fun main(){

}