sum = 0
f = open("nums.txt", "r")
lines = f.readlines() 
for line in lines: 
  num = int(line)
  sum = sum + num
sum
// Output: 5537376230390876637302048746832985971773659831892672
