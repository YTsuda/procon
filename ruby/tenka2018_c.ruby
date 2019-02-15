#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|i| i.to_i}

input.shift
input.sort!

first = input.shift
arr = [first]

while input.length > 0
  fst = input.first
  lst = input.last

  afst = arr.first
  alst = arr.last

  diffs = [afst - fst, afst - lst, alst - fst, alst - lst].map{|i| i.abs}
  max_index = diffs.index(diffs.max)

  if max_index == 0 then
    arr.unshift(input.shift)
  elsif max_index == 1
    arr.unshift(input.pop)
  elsif max_index == 2
    arr.push(input.shift)
  elsif max_index == 3
    arr.push(input.pop)
  end
end

s = 0
for i in 0..(arr.length - 2)
  s = s + (arr[i] - arr[i+1]).abs
end

puts s
