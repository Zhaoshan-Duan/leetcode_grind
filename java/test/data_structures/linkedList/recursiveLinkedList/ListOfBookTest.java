package data_structures.linkedList.recursiveLinkedList;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class ListOfBookTest {
  IListOfBooks listOfBooks,partialListOfBooks,emptyListOfBooks;

  @BeforeEach
  void setup() {
    emptyListOfBooks = new EmptyNode();

    partialListOfBooks =
        new ElementNode(new Book("HP 1", "J.K. Rowling", 1997, 19.99f),
            new ElementNode(new Book("HP 2", "J.K. Rowling", 1999, 29.99f),
                new ElementNode(new Book("HP 3", "J.K. Rowling", 2001,10.99f),
                    new EmptyNode()
                )
            )
        );

    listOfBooks =
        new ElementNode(new Book("HP 4", "J.K. Rowling", 2004, 15.49f),
            new ElementNode(new Book("HP 5", "J.K. Rowling", 2006, 12.99f),
                new ElementNode(new Book("HP 6", "J.K. Rowling", 2007, 7.99f),
                    partialListOfBooks)));

  }

  @Test
  public void testCounts() {
    assertEquals(0, emptyListOfBooks.count());
    assertEquals(3, partialListOfBooks.count());
    assertEquals(6, listOfBooks.count());
  }

  @Test
  void totalPrice() {
  }

  @Test
  void allBefore() {
  }

  @Test
  void sortByPrice() {
  }
}