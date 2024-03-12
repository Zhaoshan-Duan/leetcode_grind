package data_structures.linkedList;

import data_structures.linkedList.SinglyLinkedList.SinglyListNode;

public class SinglyLinkedList<E extends Comparable<E>>  implements LinkedList<E> {
  static class SinglyListNode<N> {
    private final N val;
    private SinglyListNode<N> next;
    private SinglyListNode(N val, SinglyListNode<N> next) {
      this.val = val;
      this.next = next;
    }
    private SinglyListNode(N val) {
      this.val = val;
    }
  }
  private SinglyListNode<E> head;

  @Override
  public int size() {
    int count = 0;
    SinglyListNode<E> cur = head;

    while (cur != null) {
     count++;
     cur = cur.next;
    }
    return count;
  }

  @Override
  public E remove(int index) {
    if (index < 0 || index >= size()) { throw new IllegalArgumentException();}

    E removeElement;
    if (index == 0) {
      removeElement = head.val;
      head = head.next;
      return removeElement;
    } else {
      SinglyListNode cur = head;
      int curIndex  = 0;
      while (curIndex < index - 1) {
        cur = cur.next;
        curIndex++;
      }
      removeElement = (E) cur.next.val;
      cur.next = cur.next.next;
    }
    return removeElement;
  }

  @Override
  public void insert(E element, int index) {

  }
  @Override
  public void append(E element) {
    insert(element, size());
  }

  public boolean isSorted() {
    SinglyListNode<E> cur = head;

    while (cur != null && cur.next != null) {
      if (cur.val.compareTo(cur.next.val) > 0) {
        return false;
      }
      cur = cur.next;
    }
    return true;
  }

  public boolean isSortedWithComparator() {
    SinglyListNode<E> cur = head;

    while (cur != null && cur.next != null) {
      if (cur.val.compareTo(cur.next.val) > 0) {
        return false;
      }
      cur = cur.next;
    }
    return true;
  }

  @Override
  public E get(int index) {
    if (index < 0 || index >= size()) { throw new IllegalArgumentException();}

    E removeElement;
    if (index == 0) {
      removeElement = head.val;
      head = head.next;
      return removeElement;
    } else {
      SinglyListNode cur = head;
      int curIndex  = 0;
      while (curIndex < index - 1) {
        cur = cur.next;
        curIndex++;
      }
      removeElement = (E) cur.next.val;
      cur.next = cur.next.next;
    }
    return removeElement;
  }

  @Override
  public String toString() {
    SinglyListNode cur = head;

    if (head == null) {
      return "";
    }

    StringBuilder acc = new StringBuilder();
    while (cur.next != null) {
      acc.append(cur.val);
      acc.append("->");
      cur = cur.next;
    }
    acc.append(cur.val);

    return acc.toString();
  }

  @Override
  public boolean equals(Object other) {
    if (other instanceof LinkedList<?>){
      LinkedList<E> otherList = (LinkedList<E>) other;

      if (otherList.size() != this.size()) {
        return false;
      }

      SinglyListNode<E> curr = head;
      int index = 0;

      while(curr != null) {
        if (!otherList.get(index).equals(curr.val)) {
            return false;
          }
        }
      }
      return true;
  }

  @Override
  public int hashCode() {
    return toString().hashCode();
  }
}
