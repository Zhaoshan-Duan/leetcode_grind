// name: Zhaoshan Duan
// email: duan.zha@northeastern.edu
// Leetcode link: https://leetcode.com/problems/reduce-array-size-to-the-half/description/
int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int minSetSize(int* arr, int arrSize) {
    int max = 0;
    for (int i =0; i < arrSize; i++) if (arr[i] > max) max = arr[i];

    int freq[max+1];
    for(int i =0; i <= max; i++) freq[i] = 0;

    for(int i = 0; i < arrSize; i++) freq[arr[i]]++;
    
    qsort(freq, max+1, sizeof(int), cmp);
    
    int limit = arrSize / 2;
    int removedAmount = 0;
    int removedCount = 0;
    int i = 0;
    while(removedAmount < limit){
        removedAmount += freq[i++];
        removedCount++;
    } 
    return removedCount;
}
