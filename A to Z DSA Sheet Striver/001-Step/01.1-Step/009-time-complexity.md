# Time and Space Complexity Basics

This README provides an overview of time and space complexity concepts covered in the Strivers A2Z DSA Course. Understanding these concepts is crucial for evaluating and optimizing code performance.

## Time Complexity:

### Definition:
Time complexity measures the rate at which the time required to run a code changes concerning the input size. It is not dependent on the machine used for execution.

### Representing Time Complexity:
Time complexity is represented using Big O notation. For example, O(no. of steps) indicates the number of steps a code takes to execute.

### Three Rules for Calculating Time Complexity:
1. **Calculate for Worst-Case Scenario:**
   - Evaluate the code's performance under the condition that takes the maximum time to execute.

2. **Avoid Including Constant Terms:**
   - Disregard constant coefficients and terms while calculating time complexity.

3. **Avoid Lower Values:**
   - Focus on higher-order terms and avoid lower-order values for larger input sizes.

## Examples:

### Example 1:
```cpp
for (int i = 1; i <= 5; i++) {
    cout << "Raj";
}
```
- Manual counting yields 15 steps.
- Time complexity: O(15) or O(N), where N is the input size.

### Example 2:
```cpp
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        // Code inside the inner loop
    }
}
```
- Nested loops result in N^2 steps.
- Time complexity: O(N^2).

## Space Complexity:

### Definition:
Space complexity refers to the memory space used by a code during execution. It is represented using Big O notation and includes auxiliary and input space.

### Good Coding Practice:
- Avoid manipulating input data solely to reduce space complexity unless explicitly instructed by the interviewer.

### Example:
```cpp
int a, b;   // Input space
int c;      // Auxiliary space
```
- Space complexity: O(3).

## Competitive Programming Tips:

### Points to Remember:
- In platforms like LeetCode or GeeksforGeeks, servers execute roughly 10^8 operations in 1 second.
- Adhere to the given time limits, e.g., for 2 seconds, aim for operations around 2 * 10^8.
- Time complexity should be around O(10^8) for 1 second of execution time.

Understanding and applying these time and space complexity concepts are essential for writing efficient and scalable code. For more detailed explanations and practice, refer to the Strivers A2Z DSA Course materials.