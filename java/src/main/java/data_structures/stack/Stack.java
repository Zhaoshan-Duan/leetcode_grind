package data_structures.stack;

class Node<T> {
  T val;
  Node<T> prev;

  Node(T val) {
    this.val = val;
  }
}
public class Stack<T> {
  int length;

  private Node<T> head;
  public Stack() {
    this.head = null;
    length = 0;
  }
  void push(T item){
    Node<T> node = new Node<>(item);

    length++;

    if(this.head == null){
      this.head = node;
      return;
    }

    node.prev = this.head;
    head = node;
  }
  T pop() {
    if (this.head == null) {
      return null;
    }
    length = Math.max(0, this.length -1);
    if (length == 0) {
      Node<T> head = this.head;
      this.head = null;
      return head.val;
    }
    Node<T> head = this.head;
    this.head = head.prev;

    return head.val;
  }

  T peek() {
    return this.head.val;
  }
}


