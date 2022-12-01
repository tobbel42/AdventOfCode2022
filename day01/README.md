# Day01

## 1st Star

Today we started of easy. We need to find the elve who carries the most callories. To do that we loop over the file line by line and add up the callories. On an empty line we compare the current sum with the max_sum, and assign a new max sum if neccesary.

## 2nd Star

The same, but we need the sum of the top 3 calorie packing elves. To do this, we have an array of the three highest values. After each elve we check if the current sum is higher than any of the three, and if so insert it into the array after shifting the other values accordingly