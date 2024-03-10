package java.data_structures.linkedList;
class SinglyListNode<T>{

  T val;
  SinglyListNode<T> next;

  SinglyListNode(T val) {
    this.val = val;
  }
}
public class SinglyLinkedList<T>{
  int length;
  SinglyListNode<T> head;
  public SinglyLinkedList() {
    length = 0;
  }

  int length() {
    return length;
  }
  //T remove(T item);
  //T removeAt(int index) {
  //void append(T item) {
  // void prepend (T item) {
  // T get(int index) {
}
