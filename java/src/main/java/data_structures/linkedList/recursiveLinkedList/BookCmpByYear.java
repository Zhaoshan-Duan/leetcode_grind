package data_structures.linkedList.recursiveLinkedList;

import java.util.Comparator;

public class BookCmpByYear implements Comparator<Book> {
  public int compare(Book a, Book b) {
    return a.getYear() - b.getYear();
  }

}
