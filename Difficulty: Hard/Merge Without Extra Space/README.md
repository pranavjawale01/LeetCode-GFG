<h2><a href="https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1?page=1&difficulty=Hard&sortBy=submissions">Merge Without Extra Space</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two sorted arrays <strong>arr1[]</strong> and <strong>arr2[] </strong>in non-decreasing order. Merge them in sorted order without using any <strong>extra space</strong>. Modify <strong>arr1</strong> so that it contains the first n elements and modify arr2 so that it contains the last m elements.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: n = 4, m = 5, arr1[] = [1 3 5 7], arr2[] = [0 2 6 8 9]
<strong>Output</strong>: arr1[] = [0 1 2 3], arr2[] = [5 6 7 8 9]
<strong>Explanation</strong>:After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: n = 2, m = 3, arr1[] = [10 12], arr2[] = [5 18 20]
<strong>Output</strong>: arr1[] = [5 10], arr2[] = [12 18 20]
<strong>Explanation</strong>: After merging two sorted arrays we get 5 10 12 18 20.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> &nbsp;O((n+m) log(n+m))<br><strong>Expected Auxilliary Space:</strong> O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">1 &lt;= n, m&nbsp;&lt;= 10<sup>5</sup><br>0 &lt;= arr1<sub>i</sub>, arr2<sub>i</sub>&nbsp;&lt;= 10<sup>7</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Zoho</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Adobe</code>&nbsp;<code>Linkedin</code>&nbsp;<code>Amdocs</code>&nbsp;<code>Brocade</code>&nbsp;<code>Juniper Networks</code>&nbsp;<code>Quikr</code>&nbsp;<code>Synopsys</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Mathematical</code>&nbsp;<code>Sorting</code>&nbsp;<code>Algorithms</code>&nbsp;