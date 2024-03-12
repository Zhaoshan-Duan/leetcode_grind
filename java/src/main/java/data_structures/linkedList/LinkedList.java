package data_structures.linkedList;

public interface LinkedList<E> {
  int size();
  E remove(int index);

  void insert(E element, int index);
  void append(E element);

  E get(int index);
}
