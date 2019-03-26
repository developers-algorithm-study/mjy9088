# Combination Sum

Given a **set** of candidate numbers (`candidates`) **(without duplicates)** and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

The **same** repeated number may be chosen from `candidates` unlimited number of times.

**Note:**

- All numbers (including `target`) will be positive integers.
- The solution set must not contain duplicate combinations.



### Example 1:

```
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
```



### Example 2:

```
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```



### Note:

All given inputs are in lowercase letters `a-z`.



## Template

C++

```c++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    }
};
```



Java

```java
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
    }
}
```



Python

```python
class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
```



Python3

```python
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
```



C

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    
}
```



C#

```csharp
public class Solution {
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        
    }
}
```



Javascript

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    
};
```



Ruby

```ruby
# @param {Integer[]} candidates
# @param {Integer} target
# @return {Integer[][]}
def combination_sum(candidates, target)
    
end
```



Swift

```swift
class Solution {
    func combinationSum(_ candidates: [Int], _ target: Int) -> [[Int]] {
        
    }
}
```



Go

```go
func combinationSum(candidates []int, target int) [][]int {
    
}
```



Scala

```scala
object Solution {
    def combinationSum(candidates: Array[Int], target: Int): List[List[Int]] = {
        
    }
}
```



Kotlin

```kotlin
class Solution {
    fun combinationSum(candidates: IntArray, target: Int): List<List<Int>> {
        
    }
}
```



Rust

```rust
impl Solution {
    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        
    }
}
```



PHP

```php
class Solution {

    /**
     * @param Integer[] $candidates
     * @param Integer $target
     * @return Integer[][]
     */
    function combinationSum($candidates, $target) {
        
    }
}
```