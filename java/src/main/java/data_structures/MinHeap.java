package data_structures;

import java.util.ArrayList;
import java.util.List;

public class MinHeap {

  int length;
  private List<Integer> data;

  public MinHeap() {
    this.data = new ArrayList<Integer>();
    this.length = 0;
  }

  void insert(int value) {

  }

  int delete() {
    return 0;
  }
  void heapifyUp(int idx) {

  }
  int parent(int idx) {
    return (idx - 1) / 2;
  }
  int leftChild(int idx) {
    return idx * 2 + 1;
  }
  int rightChild(int idx) {
    return idx * 2 + 2;
  }
}
