#! /usr/bin/env ruby

input = STDIN.read.split("\n")

str = input[0]
target = input[1].to_i
pos = 0
num = 0
gosencho = 5*10**15

for i in 0...str.length
  c = str[i].to_i

  if c == 1
    pos = pos + 1
  else
    for l in 1..gosencho
      pos = pos + c**l
      if target <= pos
        break
      end
    end
  end

  if target <= pos
    num = c
    break
  end
end

print num
