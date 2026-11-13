# Check for Subsequence

## Difficulty: Easy

## Platform: GeeksForGeeks

## Problem Link
[View Problem](https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1?utm_medium=article&utm_campaign=bottom_sticky_on_article&utm_source=gfg)

## Solved On
13 Nov 2026 at 10:23 pm

<h2><a href="https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1?utm_medium=article&utm_campaign=bottom_sticky_on_article&utm_source=gfg">Check for Subsequence</a></h2><h3>Difficulty Level: Easy</h3><hr><p><span style="font-size: 18px;">Given two strings <strong>s1</strong> and <strong>s2</strong>. You have to check that <strong>s1</strong> is a subsequence of <strong>s2 </strong> or not. <br><strong>Note:</strong> A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s1 = "AXY", s2 = "YADXCP"
<strong>Output: </strong>false
<strong>Explanation:</strong> s1 is not a subsequence of s2 as 'Y' appears before 'A'.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s1 = "gksrek", s2 = "geeksforgeeks"
<strong>Output:</strong> true
<strong>Explanation: </strong>If we combine the bold character of "<strong>g</strong>ee<strong>ks</strong>fo<strong>r</strong>g<strong>e</strong>e<strong>k</strong>s", it equals to s1. So s1</span> <span style="font-size: 14pt;">is a subsequence of s2. </span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ s1.size(), s2.size() ≤ 10<sup>6</sup></span></p>