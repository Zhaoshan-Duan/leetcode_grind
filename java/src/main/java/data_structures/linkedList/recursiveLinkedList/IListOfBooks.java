package data_structures.linkedList.recursiveLinkedList;

import javax.swing.text.Element;

/**
 * This interface represents all the operations to be supported by a list of
 * books
 */
interface IListOfBooks {
  int count();
  int countHelper(int acc);
  float totalPrice();
  IListOfBooks allBefore(int year);
  IListOfBooks sortByPrice();
  String toString();
  IListOfBooks insert(Book book);
}


class EmptyNode implements IListOfBooks {

  @Override
  public int count() {
    return 0;
  }

  @Override
  public int countHelper(int acc) {
    return acc;
  }

  @Override
  public float totalPrice() {
    return 0.0f;
  }


  @Override
  public IListOfBooks allBefore(int year) {
    return new EmptyNode();
  }

  @Override
  public IListOfBooks sortByPrice() {
    return new EmptyNode();
  }

  public IListOfBooks insert(Book book) {
    return new ElementNode(book, this);
  }

  @Override
  public String toString() {
    return "";
  }
}

class ElementNode implements IListOfBooks {
  private Book book;
  private IListOfBooks rest;

  public ElementNode(Book p, IListOfBooks rest) {
    this.book = p;
    this.rest = rest;
  }

  @Override
  public int count() {
    // return 1 + this.count();
    return this.countHelper(0);
  }

  @Override
  public int countHelper(int acc) {
    return this.rest.countHelper(1 + acc);
  }

  @Override
  public float totalPrice() {
    return this.book.getPrice() + this.rest.totalPrice();
  }

  @Override
  public IListOfBooks allBefore(int year) {
    if (book.before(year)) {
      return new ElementNode(this.book, this.rest.allBefore(year));
    }
    else {
      return this.allBefore(year);
    }
  }

  @Override
  public IListOfBooks sortByPrice() {
    return this.rest.sortByPrice().insert(this.book);
  }

  public IListOfBooks insert(Book book) {
    if (this.book.cheaperThan(book)) {
      return new ElementNode(this.book, this.rest.insert(book));
    }
    else {
      return new ElementNode(book, this);
    }
  }

  @Override
  public String toString() {
    return "(" + this.book.toString()  + ")" + this.rest.toString();
  }
}