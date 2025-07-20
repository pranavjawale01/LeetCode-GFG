<h2><a href="https://www.geeksforgeeks.org/problems/count-pairs-in-array-divisible-by-k/1">Count pairs in array divisible by K</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr[] </strong>and positive integer <strong>k</strong>, the task is to count total number of pairs in the array whose sum is divisible by <strong>k</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input :</strong>  arr[] = {2, 2, 1, 7, 5, 3}, k = 4
<strong>Output :</strong> 5
<strong>Explanation : </strong>There are five pairs possible whose sum is divisible by '4' i.e., (2, 2), (1, 7), (7, 5), (1, 3) and (5, 3)</span></pre>
<pre><span style="font-size: 18px;"><strong>Input :</strong> arr[] = {5, 9, 36, 74, 52, 31, 42}, k = 3
<strong>Output :</strong> 7 
<strong>Explanation : </strong>There are seven pairs whose sum is divisible by 3, i.e, (9, 36), (9,42), </span><span style="font-size: 18px;">(74, 52), (36, 42), (74, 31), (31, 5) and (5, 52).
</span></pre>
<div><span style="font-size: 18px;"><strong>Your task :</strong></span></div>
<div><span style="font-size: 18px;">You don't have to read input or print anything. Your task is to complete the function <strong>countKdivPairs()</strong> which takes the array, it's size and an integer K as input and returns the count of pairs whose sum is divisible by k.</span></div>
<div>&nbsp;</div>
<div><span style="font-size: 18px;"><strong>Expected Time Complexity :</strong> O(n)</span></div>
<div><span style="font-size: 18px;"><strong>Expected Auxiliary Space :</strong> O(k)</span></div>
<div>&nbsp;</div>
<div><span style="font-size: 18px;"><strong>Constraints :</strong></span></div>
<div><span style="font-size: 18px;">1 &lt;= n &lt;=10^6</span></div>
<div><span style="font-size: 18px;">1 &lt;= arr[i] &lt;= 10^6</span></div>
<div><span style="font-size: 18px;">1 &lt;= k &lt;= 100</span></div></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>PayPal</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Hash</code>&nbsp;<code>Data Structures</code>&nbsp;