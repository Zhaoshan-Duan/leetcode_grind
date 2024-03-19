package data_structures.binaryTree;

import com.sun.source.tree.Tree;

public class BinaryTree<E extends Comparable<E>>{
  private TreeNode<E> root;
  private static class TreeNode<N> {

    private N data;
    private TreeNode<N> left;
    private TreeNode<N> right;

    private TreeNode(N data, TreeNode<N> left, TreeNode<N> right) {
      this.data = data;
      this.left = left;
      this.right = right;
    }

    private TreeNode(N data) {
      this(data, null, null);
    }
  }
  public boolean containsBST(E element) {
    return containsBST(element, root);
  }

  private boolean containsBST(E element, TreeNode<E> node) {
    // base case
    if (node == null) return false;

    // recursive case
    if (node.data.equals(element)) {
      return true;
    } else {
      if (element.compareTo(node.data) < 0)
        return containsBST(element, node.left);
      else
        return containsBST(element, node.right);
    }
  }

  public void addNode(E element) {
    root = addNode(element, root);
  }
  private TreeNode<E> addNode(E element, TreeNode<E> node) {
    // base case
    if (node == null)
      return new TreeNode<E>(element);
    // recursive case
    else {
      if (node.data.compareTo(element) > 0 ) {
        node.left = addNode(element, node.left);
      } else {
        node.right = addNode(element, node.right);
      }
      return node;
    }
  }

  public void removeMax() {
    if (root == null) throw new IllegalArgumentException("Can't remove from empty tree.");
    root = removeMax(root);
  }

  private TreeNode<E> removeMax(TreeNode<E> node) {
    // base case
    if (node.right == null) return node.left;
    // recursive case
    else {
      node.right = removeMax(node.right);
      return node;
    }
  }

  @Override
  public boolean equals(Object other) {
    if (other instanceof BinaryTree tree) {
      return equals(root, tree.root);
    } else return false;
  }

  private boolean equals(TreeNode<E> thisNode, TreeNode<E> otherNode) {
    // check if both nodes are null
    if (thisNode == null)
      return otherNode == null;
     else  {
      if (otherNode == null) {
        return false;
      }
      // recursive
      if (!thisNode.data.equals(otherNode.data)) {
        return false;
      }

      if (!equals(thisNode.left, otherNode.left)) {
        return false;
      }
      return equals(thisNode.right, otherNode.right);
    }
  }

}
