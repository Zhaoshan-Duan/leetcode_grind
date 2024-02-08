package data_structures;

import java.util.Arrays;

public class Vector {
  int[] data;
  int capacity;
  int size;
  public Vector(int initCapacity) {
    capacity = initCapacity;
    data = new int[capacity];
    size = 0;
  }
  public Vector() {
    this(0);
  }
  boolean append(int element) {
    if (size == capacity) {
      // shift
      if (!resize()) {
        System.out.println("Resizing unsuccessful");
        return false;
      }
    }
    data[size] = element;
    size++;
    return true;
  }

  boolean resize() {
    int currCapacity = capacity;
    int newCapacity = capacity * 2;
    int[] newData = new int[newCapacity];

    // copying
    for (int i = 0; i < size; i++) {
     newData[i] = data[i];
    }

    data = newData;
    capacity = newCapacity;
    System.out.printf("Resized from %d to %d\n", currCapacity, newCapacity);
    return true;

  }

  boolean insert(int position, int element) {
    if (position < 0) return false;

    if (position == size) {
      append(element);
    }

    if (size == capacity) {
      resize();
    }

    for (int i = size-1; i >= position ;i--) {
      data[i+1] = data[i];
    }

    data[position] = element;
    size++;

    return true;
  }

  boolean push_front(int element) {
    insert(0, element);
    return true;
  }
  @Override
  public String toString() {
    return Arrays.toString(data);
  }
}

class Driver{
  public static void main(String[] args) {
    Vector v = new Vector(2);
    v.append(1);
    v.append(2);
    v.insert(2, 3);
    v.insert(1, 1);
    v.push_front(100);
    System.out.println(v);
  }
}
