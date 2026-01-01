# DSA Project - Circular Doubly Linked List with Defragmentation

A C implementation of a circular doubly linked list data structure with memory defragmentation capabilities.

## Overview

This project implements a fixed-size circular doubly linked list that supports insertion, deletion, and defragmentation operations. The list maintains a circular structure where nodes can be marked as "empty" (data = 0) and later defragmented to optimize memory layout.

## Project Analysis

### Data Structures and Algorithms (DSA) Perspective

From a DSA standpoint, this project demonstrates several key concepts:

**1. Circular Doubly Linked List Implementation**
- **Time Complexity**: 
  - Insert: O(n) - searches for first empty slot
  - Delete: O(n) - traverses to specific position
  - Display: O(n) - visits all nodes once
  - Defragmentation: O(n²) - nested loops for reorganization

**2. Space Complexity**: O(1) extra space
- Fixed memory allocation (MAX nodes)
- No additional data structures used
- In-place defragmentation algorithm

**3. Key DSA Concepts Demonstrated**:
- **Circular Data Structure**: Eliminates need for NULL checks at boundaries
- **Doubly Linked Navigation**: Bidirectional traversal capabilities
- **Memory Fragmentation Handling**: Simulates real-world memory management
- **Lazy Deletion**: Marks nodes as empty rather than immediate deallocation
- **Compaction Algorithm**: Reorganizes memory layout for optimization

**4. Algorithm Design Patterns**:
- **Sentinel Values**: Uses 0 to mark empty/deleted nodes
- **Circular Buffer Simulation**: Fixed-size rotating structure
- **In-place Algorithms**: Defragmentation without extra memory

### Operating Systems (OS) Perspective

From an OS perspective, this project simulates several important system concepts:

**1. Memory Management Simulation**
- **Heap Allocation**: Uses `malloc()` to simulate dynamic memory allocation
- **Memory Fragmentation**: Demonstrates how deleted blocks create fragmented memory
- **Compaction/Defragmentation**: Simulates OS memory compaction algorithms
- **Memory Leaks Prevention**: Proper cleanup with `free()` on program exit

**2. Process Memory Layout Concepts**:
- **Dynamic Memory**: Nodes allocated on heap during runtime
- **Pointer Management**: Simulates address space navigation
- **Memory Boundaries**: Fixed-size constraint mimics memory segments

**3. System-Level Operations Simulated**:
- **Garbage Collection**: Defragmentation resembles GC compaction phase
- **Memory Pool Management**: Fixed-size allocation pool (MAX nodes)
- **Reference Management**: Pointer manipulation similar to OS page tables

**4. Resource Management Principles**:
- **Resource Allocation**: Dynamic node allocation/deallocation
- **Resource Tracking**: Maintains pointers to allocated memory
- **Resource Cleanup**: Systematic memory deallocation on exit
- **Circular Resource Access**: Round-robin style access pattern

**5. Concurrency Considerations** (Theoretical):
- Structure could be extended for multi-threaded access
- Demonstrates need for synchronization in shared data structures
- Shows importance of atomic operations in linked structure modifications

This implementation serves as a microcosm of larger OS memory management systems, making it valuable for understanding both fundamental data structures and system-level concepts.

## Features

- **Circular Doubly Linked List**: Bidirectional traversal with circular connectivity
- **Fixed Size**: Maximum of 5 nodes (configurable via MAX constant)
- **Memory Management**: Dynamic allocation and proper cleanup
- **Defragmentation**: Reorganizes empty nodes to optimize list structure
- **Interactive Menu**: User-friendly command-line interface

## Data Structure

```c
struct node {
    struct node *pPrev;  // Pointer to previous node
    int iData;           // Data (0 indicates empty/deleted)
    struct node *pNext;  // Pointer to next node
};
```

## Operations

### 1. Insert
- Adds data to the first available empty slot
- Automatically finds the next empty position
- Displays "List Is Full" when no empty slots available

### 2. Delete
- Removes data at specified position (1-based indexing)
- Marks node as empty (sets data to 0) rather than removing node
- Returns the deleted value

### 3. Defragmentation
- Reorganizes the list to move empty nodes to optimal positions
- Maintains circular structure while optimizing layout
- Only available when list is neither completely full nor empty

### 4. Display
- Shows current state of all nodes in format: `<-|data|->`
- Traverses the entire circular list once

## Menu Options

```
1. Insert    - Add new data to the list
2. Delete    - Remove data at specified position
3. Defragment - Reorganize empty nodes
4. Exit      - Terminate program
```

## Compilation and Usage

### Compile
```bash
gcc DS_project.c -o ds_project
```

### Run
```bash
./ds_project
```

## Example Usage

```
1.Insert 
2.Delete 
3.Defragement 
4.Exit 
Enter your Choice: 1

Enter Data: 10
<-|10|->

Enter your Choice: 1
Enter Data: 20
<-|10|-><-|20|->

Enter your Choice: 2
Enter Position: 1
Deleted Data is 10

List after deleting data:
<-|0|-><-|20|->

Enter your Choice: 3
<-|20|-><-|0|->
```

## Technical Details

- **Memory Allocation**: Uses `malloc()` for dynamic node creation
- **Circular Structure**: Last node points to first, first node points to last
- **Empty Detection**: Checks if all nodes have data = 0
- **Full Detection**: Checks if no nodes have data = 0
- **Position-based Access**: 1-based indexing for user operations
- **Naming Convention**: Uses Hungarian notation for variable naming

## Variable Naming Convention

The project follows **Hungarian notation** for consistent and self-documenting variable names:

- **`i`** prefix - Integer variables (`iPos`, `iChoice`, `iCount`, `iData`)
- **`p`** prefix - Pointer variables (`pFirst`, `pLast`, `pCurrent`, `pHead`, `pTail`)
- **`pp`** prefix - Pointer to pointer variables (`ppHead`, `ppTail`, `ppCurrent`)

This naming convention makes the code more readable by indicating the data type of each variable at a glance.

## Constants

- `MAX`: Maximum number of nodes (currently set to 5)

## Memory Management

The program properly handles memory cleanup:
- Breaks circular links before deallocation
- Frees all allocated nodes on exit
- Sets pointers to NULL after cleanup

## Error Handling

- Invalid position validation for delete operations
- Memory allocation failure detection
- Boundary checks for list operations
- User input validation for menu choices