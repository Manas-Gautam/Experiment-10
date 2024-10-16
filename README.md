# Experiment-10
## Theory : - 
### Pointer Operations in C++

Pointers in C++ are powerful tools that provide direct memory access. They are variables that store the address of another variable, and they support a variety of operations, such as arithmetic and comparison. Here's a detailed breakdown of pointer operations in C++:

---

### 1. **Pointer Assignment**
A pointer can be assigned the address of a variable using the address-of operator (`&`).

Example:
```cpp
int x = 10;
int *ptr = &x;  // ptr now holds the address of x
```

Here, `ptr` is a pointer to an integer and holds the memory address of `x`.

---

### 2. **Dereferencing a Pointer**
Dereferencing a pointer means accessing the value stored at the memory location the pointer is pointing to. The dereference operator (`*`) is used for this.

Example:
```cpp
int x = 10;
int *ptr = &x;
cout << *ptr;  // Output will be 10
```

In this example, `*ptr` accesses the value stored at the memory address held by `ptr` (i.e., the value of `x`).

---

### 3. **Pointer Arithmetic**
Pointer arithmetic involves operations like addition or subtraction of integers from pointers. This is often used when working with arrays.

- **Incrementing a pointer (`ptr++`)**: Moves the pointer to the next element of the type it points to. For example, if a pointer points to an integer (which is 4 bytes on most systems), incrementing the pointer moves it to the next integer (by 4 bytes).
- **Decrementing a pointer (`ptr--`)**: Moves the pointer to the previous element.
- **Adding/Subtracting an integer (`ptr + i` or `ptr - i`)**: Moves the pointer by `i` elements forward or backward.

Example:
```cpp
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr;  // points to the first element of the array

ptr++;           // points to the second element (20)
cout << *ptr;    // Output will be 20
```

In this example, `ptr++` moves the pointer to the next element in the array (from `arr[0]` to `arr[1]`).

---

### 4. **Pointer Comparison**
Pointers can be compared using relational operators like `==`, `!=`, `<`, `>`, `<=`, and `>=`. This is useful when dealing with arrays or dynamic memory, where you might want to check if two pointers point to the same location, or compare their positions.

Example:
```cpp
int arr[] = {10, 20, 30, 40, 50};
int *ptr1 = arr;          // points to arr[0]
int *ptr2 = &arr[3];      // points to arr[3]

if (ptr1 < ptr2) {
    cout << "ptr1 points to a memory address before ptr2.";
}
```

Here, the comparison `ptr1 < ptr2` checks if `ptr1` is pointing to a lower memory address than `ptr2`.

---

### 5. **Array and Pointer Equivalence**
The name of an array in C++ can be treated as a constant pointer to the first element of the array. This allows you to use pointer arithmetic to access array elements.

Example:
```cpp
int arr[] = {10, 20, 30, 40, 50};

cout << *(arr + 2);  // Output will be 30 (equivalent to arr[2])
```

---

### 6. **Pointer to Pointer**
A pointer can point to another pointer. This is known as a **pointer to pointer**, and it is used when you need to work with multi-dimensional arrays or pass a pointer by reference to a function.

Example:
```cpp
int x = 10;
int *ptr = &x;
int **ptr2 = &ptr;  // pointer to pointer

cout << **ptr2;     // Output will be 10
```

In this example, `ptr2` is a pointer to `ptr`, and `**ptr2` accesses the value of `x`.

---

### 7. **Null Pointers**
A null pointer is a pointer that doesn't point to any valid memory location. It is useful for checking whether a pointer is assigned a valid memory address. You can assign `nullptr` (C++11 and later) or `NULL` to initialize a null pointer.

Example:
```cpp
int *ptr = nullptr;  // or int *ptr = NULL;

if (ptr == nullptr) {
    cout << "Pointer is null";
}
```

---

### 8. **Void Pointers**
A `void` pointer (`void*`) is a special type of pointer that can point to any data type. However, before dereferencing it, you must first cast it to the appropriate type.

Example:
```cpp
int x = 10;
void *ptr = &x;   // void pointer can point to any type

cout << *(int*)ptr;  // Type casting is needed to dereference
```

---

### 9. **Pointers and Functions**
Pointers are commonly passed to functions to modify variables outside the function scope or to pass large data structures efficiently (by reference).

#### Passing Pointer to a Function:
```cpp
void modify(int *ptr) {
    *ptr = 20;
}

int main() {
    int x = 10;
    modify(&x);   // passing the address of x
    cout << x;    // Output will be 20
}
```

#### Returning Pointer from a Function:
```cpp
int* getArray() {
    static int arr[5] = {1, 2, 3, 4, 5};  // static array to avoid returning local pointer
    return arr;
}

int main() {
    int *ptr = getArray();
    cout << *(ptr + 2);  // Output will be 3
}
```

---

### 10. **Dynamic Memory Allocation**
Pointers are used with dynamic memory allocation (`new` and `delete` operators). 

- `new` allocates memory on the heap.
- `delete` deallocates the memory to prevent memory leaks.

Example:
```cpp
int *ptr = new int(5);  // dynamically allocate memory for an integer
cout << *ptr;           // Output will be 5

delete ptr;             // free the memory
```

---

# Experiment 10{A}: - Swap the numbers using call by value.

## Code: -

#include <iostream>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside function: a = " << a << ", b = " << b << endl;  // swapped values inside the function
}

int main() {
    int x = 10, y = 20;
    cout << "Before function call: x = " << x << ", y = " << y << endl;

    swapByValue(x, y);  // call by value: the changes won't reflect in x and y

    cout << "After function call: x = " << x << ", y = " << y << endl;  // original values remain unchanged
    return 0;
}


## Output: - 

![image](https://github.com/user-attachments/assets/3c3e00fa-ba19-49c6-8d34-09989d1b9c50)


# # Experiment 10{B}: - Swap the numbers using call by reference.

## Code: - 

#include <iostream>
using namespace std;

void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;

    swapByReference(x, y);  // call by reference: x and y will be swapped

    cout << "After swapping: x = " << x << ", y = " << y << endl;
    return 0;
}


## Output: - 

![image](https://github.com/user-attachments/assets/3090ce89-7602-423b-958a-2015961f8a23)


### Summary:
- Pointers store memory addresses and allow direct memory access.
- Key pointer operations include dereferencing, arithmetic, comparison, and assignment.
- Pointers play a crucial role in arrays, dynamic memory management, and efficient function passing.
- Special types of pointers include null pointers, void pointers, and pointers to pointers.

Understanding pointers is essential for mastering memory management, performance optimization, and system-level programming in C++.
