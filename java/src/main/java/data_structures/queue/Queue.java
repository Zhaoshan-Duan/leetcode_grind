package data_structures.queue;

class Node<T> {
  T val;
  Node<T> next;
  Node(T val) {
    this.val = val;
  }
}

public class Queue<T> {
  int length;
  private Node<T> head;
  private Node<T> tail;

  public Queue() {
    this.head = this.tail = null;
    length = 0;
  }

  void enqueue(T item) {
    Node<T> node = new Node<>(item);
    length++;
    if (this.tail == null) {
      this.tail = this.head = node;
      return;
    }
    this.tail.next = node;
    this.tail = node;

  }

  T dequeue() {
    if (head == null) {
      return null;
    }
    this.length--;

    Node<T> head = this.head;
    this.head = this.head.next;
    //free
    head.next = null;
    if (this.length == 0) {
     this.tail = null;
    }
    return head.val;
  }

  T peek() {
    return this.head.val;
  }

}