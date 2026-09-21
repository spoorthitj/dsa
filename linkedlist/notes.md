# Linked List --- Complete Notes

## 1. Linked List Basics

A linked list is a collection of **nodes** where each node stores: -
data - a pointer to the next node

### Singly Linked List

``` cpp
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
```

Visual:

``` text
head
 ↓
[10 | •] → [20 | •] → [30 | NULL]
```

`head` points to the first node.

For a node pointer:

``` cpp
node->data
node->next
```

`nullptr` means there is no next node.

### Traversal

``` cpp
Node* temp = head;

while (temp != nullptr) {
    cout << temp->data;
    temp = temp->next;
}
```

------------------------------------------------------------------------

# 2. Singly Linked List --- Insertion

## A. Insert at Front

Before:

``` text
head
 ↓
10 → 20 → 30 → NULL
```

Insert `5`:

``` text
head
 ↓
5 → 10 → 20 → 30 → NULL
```

Logic:

``` cpp
Node* newNode = new Node(5);

newNode->next = head;
head = newNode;
```

### Pattern

``` cpp
newNode->next = head;
head = newNode;
```

Time: **O(1)**

------------------------------------------------------------------------

## B. Insert at End

Before:

``` text
10 → 20 → 30 → NULL
```

Insert `40`:

``` text
10 → 20 → 30 → 40 → NULL
```

Logic:

``` cpp
Node* newNode = new Node(40);

Node* temp = head;

while (temp->next != nullptr) {
    temp = temp->next;
}

temp->next = newNode;
```

Time: **O(n)**

------------------------------------------------------------------------

## C. Insert in Middle / After a Given Node

Before:

``` text
10 → 20 → 30
```

Insert `25` after `20`:

``` text
10 → 20 → 25 → 30
```

If `temp` points to `20`:

``` cpp
Node* newNode = new Node(25);

newNode->next = temp->next;
temp->next = newNode;
```

### Critical order

``` cpp
newNode->next = temp->next;
temp->next = newNode;
```

Do not overwrite `temp->next` before saving the old next connection.

------------------------------------------------------------------------

# 3. Singly Linked List --- Deletion

## A. Delete from Front

Before:

``` text
head
 ↓
10 → 20 → 30
```

Delete `10`:

``` text
head
 ↓
20 → 30
```

Logic:

``` cpp
Node* temp = head;
head = head->next;
delete temp;
```

Time: **O(1)**

------------------------------------------------------------------------

## B. Delete from End

Before:

``` text
10 → 20 → 30 → NULL
```

Delete `30`.

We need to reach the **second-last node** (`20`).

``` cpp
Node* temp = head;

while (temp->next->next != nullptr) {
    temp = temp->next;
}

delete temp->next;
temp->next = nullptr;
```

### Important

Handle: - empty list - only one node

separately.

------------------------------------------------------------------------

## C. Delete from Middle

Before:

``` text
10 → 20 → 30 → 40
```

Delete `30`.

If `temp` points to `20`:

``` text
10 → 20 → 30 → 40
     ↑     ↑
    temp  delete
```

Logic:

``` cpp
Node* del = temp->next;
temp->next = del->next;
delete del;
```

### Core pattern

``` cpp
del = temp->next;
temp->next = del->next;
delete del;
```

------------------------------------------------------------------------

# 4. Doubly Linked List (DLL)

A doubly linked list has: - data - `prev` - `next`

``` cpp
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
```

Visual:

``` text
NULL ← 10 ⇄ 20 ⇄ 30 → NULL
```

`next` moves forward.

`prev` moves backward.

### Connecting two nodes

``` cpp
first->next = second;
second->prev = first;
```

Unlike singly linked lists, DLL connections work in **both directions**.

------------------------------------------------------------------------

# 5. DLL --- Insertion

## A. Insert at Front

Before:

``` text
NULL ← 10 ⇄ 20 ⇄ 30
```

Insert `5`:

``` text
NULL ← 5 ⇄ 10 ⇄ 20 ⇄ 30
```

Logic:

``` cpp
newNode->next = head;
newNode->prev = nullptr;

head->prev = newNode;
head = newNode;
```

Handle an empty list separately.

------------------------------------------------------------------------

## B. Insert at End

Find the last node:

``` cpp
Node* temp = head;

while (temp->next != nullptr) {
    temp = temp->next;
}
```

Then:

``` cpp
temp->next = newNode;
newNode->prev = temp;
newNode->next = nullptr;
```

------------------------------------------------------------------------

## C. Insert in Middle

Before:

``` text
10 ⇄ 20 ⇄ 30
```

Insert `25` after `20`:

``` text
10 ⇄ 20 ⇄ 25 ⇄ 30
```

If `temp` points to `20`:

``` cpp
newNode->next = temp->next;
newNode->prev = temp;

temp->next->prev = newNode;
temp->next = newNode;
```

### Remember

DLL insertion usually requires changing **four links**.

``` text
20 → 25
25 → 20
25 → 30
30 → 25
```

------------------------------------------------------------------------

# 6. DLL --- Deletion

## A. Delete from Front

``` cpp
Node* temp = head;
head = head->next;

if (head != nullptr)
    head->prev = nullptr;

delete temp;
```

Result:

``` text
20 ⇄ 30
```

Handle an empty list separately.

------------------------------------------------------------------------

## B. Delete from End

If `temp` points to the last node:

``` cpp
temp->prev->next = nullptr;
delete temp;
```

Handle the single-node case separately.

------------------------------------------------------------------------

## C. Delete from Middle

Before:

``` text
10 ⇄ 20 ⇄ 30 ⇄ 40
```

Delete `30`.

If `temp` points to `30`:

``` cpp
temp->prev->next = temp->next;
temp->next->prev = temp->prev;

delete temp;
```

Result:

``` text
10 ⇄ 20 ⇄ 40
```

### Core pattern

``` cpp
temp->prev->next = temp->next;
temp->next->prev = temp->prev;
delete temp;
```

------------------------------------------------------------------------

# 7. Reverse a Doubly Linked List

Before:

``` text
NULL ← 10 ⇄ 20 ⇄ 30 → NULL
```

After:

``` text
NULL ← 30 ⇄ 20 ⇄ 10 → NULL
```

For every node, swap:

``` cpp
swap(temp->prev, temp->next);
```

Implementation:

``` cpp
Node* temp = head;
Node* newHead = nullptr;

while (temp != nullptr) {
    swap(temp->prev, temp->next);

    newHead = temp;

    temp = temp->prev;
}

head = newHead;
```

### Why `temp = temp->prev`?

After swapping, the old `next` pointer is now stored in `prev`.

So `temp->prev` takes us to the next node of the **original** list.

------------------------------------------------------------------------

# 8. Most Important Patterns

## Singly Linked List

### Insert front

``` cpp
newNode->next = head;
head = newNode;
```

### Insert middle

``` cpp
newNode->next = temp->next;
temp->next = newNode;
```

### Delete front

``` cpp
Node* del = head;
head = head->next;
delete del;
```

### Delete middle

``` cpp
Node* del = temp->next;
temp->next = del->next;
delete del;
```

------------------------------------------------------------------------

## Doubly Linked List

### Insert middle

``` cpp
newNode->next = temp->next;
newNode->prev = temp;

temp->next->prev = newNode;
temp->next = newNode;
```

### Delete middle

``` cpp
temp->prev->next = temp->next;
temp->next->prev = temp->prev;
delete temp;
```

### Reverse

``` cpp
swap(temp->prev, temp->next);
temp = temp->prev;
```

------------------------------------------------------------------------

# 9. Mental Model

### Singly Linked List

``` text
A → B → C
```

You can move:

``` text
→
```

### Doubly Linked List

``` text
A ⇄ B ⇄ C
```

You can move:

``` text
← →
```

### Insertion

Break one connection and create two new connections:

``` text
A → B

A → NEW → B
```

### Deletion

Skip the node:

``` text
A → B → C

A ─────→ C
```

### DLL rule

Whenever you change a connection, check **both `prev` and `next`**.

------------------------------------------------------------------------

# 10. Complexity Quick Reference

  Operation                       Singly LL   Doubly LL
  ----------------------------- ----------- -----------
  Insert front                         O(1)        O(1)
  Insert end\*                         O(n)        O(n)
  Delete front                         O(1)        O(1)
  Delete end\*                         O(n)        O(n)
  Insert/delete at known node          O(1)        O(1)
  Search                               O(n)        O(n)
  Traversal                            O(n)        O(n)
  Reverse                              O(n)        O(n)

`*` With a maintained tail pointer, some end operations can be made
O(1).

------------------------------------------------------------------------

# Key takeaway

Don't memorize every function separately.

Think in terms of **arrows**:

**Singly:**

``` text
previous → current → next
```

**Doubly:**

``` text
previous ⇄ current ⇄ next
```

Insertion = **connect the new node correctly**.

Deletion = **connect the neighbors and remove the node**.

Reverse DLL = **swap `prev` and `next` at every node**.
