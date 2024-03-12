package dataStructure.linkedList;

import static org.junit.jupiter.api.Assertions.assertEquals;

import data_structures.linkedList.SinglyLinkedList;
import org.junit.jupiter.api.Test;

public class SinglyLinkedListTest {
  @Test
  void sizeEmptyList() {
    SinglyLinkedList<Integer> emptyList = new SinglyLinkedList<>();
    assertEquals(0, emptyList.size());
  }
  @Test
  void sizeListSize3() {
    SinglyLinkedList<Integer> list = new SinglyLinkedList<>();
    list.append(4);
    list.append(5);
    list.append(6);
    assertEquals(3, list.size());
  }

  @Test
  void equalsDifferentSize() {
    //TODO
  }

  @Test
  void equalsOneIsEmpty() {
   //TODO
  }

  @Test
  void equalsBothEmpty() {
    //TODO
  }

  @Test
  void equalsSameSizNotEqual() {
    //TODO
  }

  @Test
  void equalsTrue() {
    //TODO
  }
}
