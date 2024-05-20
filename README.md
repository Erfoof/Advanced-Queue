# Queue Documentation

## Overview
This application implements a Queue data structure in C++. It allows users to create, manipulate, and manage multiple queues dynamically during runtime. The application offers functionalities like enqueue, dequeue, display, and cloning of queues.

## Classes

### `Queue`
- **Description**: Represents a queue data structure.
- **Members**:
    - `rear`: Stores the index of the rear element.
    - `front`: Stores the index of the front element.
    - `Array`: Pointer to dynamically allocated array to store queue elements.
    - `Size`: Size of the queue.
    - `Numofobj`: Number of objects created.
    - `item`: Temporary variable to hold dequeued item.
    - `Queuename`: Name of the queue.
    - `Queueposition`: Position of the queue.
- **Methods**:
    - `Queue(string queuename, int size)`: Constructor to initialize the queue with a given name and size.
    - `~Queue()`: Destructor to delete the dynamically allocated memory.
    - `Queue(const Queue& rhs)`: Copy constructor to create a new queue identical to the given queue.
    - `Queue& operator=(const Queue& rhs)`: Assignment operator to assign the contents of one queue to another.
    - `int currentsize()`: Returns the current number of objects created.
    - `void enqueue(int item)`: Adds an element to the rear of the queue.
    - `void dequeue()`: Removes an element from the front of the queue.
    - `void display()`: Displays all elements of the queue.
    - `void fronte()`: Displays the front element of the queue.
    - `int getSize()`: Returns the size of the queue.

### `newqueue`
- **Description**: Helper function to create a new queue object and return its pointer.
- **Parameters**:
    - `name`: Name of the queue.
    - `size`: Size of the queue.
- **Returns**: Pointer to the newly created queue.

## Usage

1. **Creating a Queue**: Users can create a new queue by providing a name and size. The queue will be dynamically allocated.

2. **Dequeue Operation**: Removes an element from the front of a specified queue.

3. **Displaying Queue Elements**: Displays all elements of a specified queue.

4. **Displaying Front Element**: Displays the front element of a specified queue.

5. **Enqueue Operation**: Adds an element to the rear of a specified queue.

6. **Deleting a Queue**: Deletes a specified queue.

7. **Cloning a Queue**: Creates a clone of a specified queue with a new name.

8. **Exiting the Application**: Allows users to exit the application.

9. **Clearing Screen**: Clears the console screen for better readability.

## Notes

- All queues are dynamically allocated and managed during runtime.
- The application maintains a map to associate queue names with their respective addresses for ease of access and manipulation.
- Users can perform various queue operations through a simple menu-driven interface.

## Example

```cpp
int main() {
    // Sample code demonstrating the usage of the Queue class and its functionalities.
    // ...
    return 0;
}
```

## Dependencies

- `iostream`: Input/output stream library for console input/output operations.
- `string`: String library for string manipulation.
- `map`: Standard template library for associative containers (map) to store queue names and their addresses.

Ensure the above dependencies are included in your C++ environment for successful compilation and execution of the application.
