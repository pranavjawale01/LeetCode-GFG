<h2><a href="https://www.geeksforgeeks.org/problems/time-to-words3728/1?page=1&difficulty=School&status=unsolved&sortBy=submissions">Time to Words</a></h2><h3>Difficulty Level : School</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a time in the format of hh:mm (12-hour format) <em><strong>0 &lt; HH&nbsp;&lt; 12, 0 &lt;= MM&nbsp;&lt; 60</strong>.</em> The task is to convert it into words.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> There are different corner cases appears for simplicity refer this example:</span></p>
<pre><span style="font-size: 18px;">6:00 six o'clock 6:10 ten minutes past six
6:15 quarter past six
6:30 half past six
6:45 quarter to seven
6:47 thirteen minutes to seven</span></pre>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: H = 6, M = 0
<strong>Output:</strong>&nbsp;six o' clock
<strong>Explanation</strong>: 6H:0M = six o' clock.</span></pre>
<p><br><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>N = 6, M = 10
<strong>Output:&nbsp;</strong>ten minutes past six</span><span style="font-size: 18px;">
<strong>Explanation</strong>: 6H:10M = ten minutes past six.
</span></pre>
<p><br><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You dont need to read input or print anything. Complete the function <strong>timeToWord()&nbsp;</strong>which takes H&nbsp;and M&nbsp;as input parameter and returns&nbsp;words converted from given time.<br><br><strong>Expected Time Complexity:</strong> O(1)<br><strong>Expected Auxiliary Space:</strong> O(k<sup>2</sup>)<br><br><strong>Constraints:</strong><br>0 &lt;&nbsp;H&nbsp;&lt; 12<br>0= &lt; M&nbsp;&lt; 60</span></p></div>