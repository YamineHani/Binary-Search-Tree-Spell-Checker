# Binary Search Tree Spell Checker

This C program implements a simple spell checker using a Binary Search Tree (BST). The program reads a dictionary file, builds a BST, and then allows users to input a sentence. For each word in the sentence, it checks whether the word is correct or suggests corrections based on the BST.

## Program Components

### Node Structure

```c
typedef struct node node;
struct node {
    char *word;
    node *left, *right;
};
```

### Functions

1. **NewNode**: Creates a new node with the given word.

   ```c
   node *NewNode(char *st);
   ```

2. **InsertNode**: Inserts a word into the BST.

   ```c
   node *InsertNode(node *root, char *st);
   ```

3. **Height**: Calculates the height of the BST.

   ```c
   int height(node *root);
   ```

4. **ReadFile**: Reads a file, builds the BST, and displays file statistics.

   ```c
   void readFile(char *fileName);
   ```

5. **Search**: Searches for a node with a given key in the BST.

   ```c
   node *search(node *root, char *key);
   ```

6. **FindMin**: Finds the node with the minimum value in the BST.

   ```c
   node *findMin(node *root);
   ```

7. **FindMax**: Finds the node with the maximum value in the BST.

   ```c
   node *findMax(node *root);
   ```

8. **Successor**: Finds the successor node in the BST.

   ```c
   node *successor(node *root, char *key);
   ```

9. **Predecessor**: Finds the predecessor node in the BST.

   ```c
   node *predeccessor(node *root, char *key);
   ```

10. **Scan**: Accepts a sentence input, checks for correct words, and suggests corrections.

    ```c
    void scan(node *root);
    ```

### Main Program

```c
int main() {
    readFile("EN-US-Dictionary.txt");
    return 0;
}
```

## Usage

1. Enter a sentence when prompted. The program will check each word for correctness and suggest corrections if needed.


## Cases Handled

- Checking correctness of words in a sentence.
- Suggesting corrections based on the BST.
- Displaying file statistics: size and height of the BST.

