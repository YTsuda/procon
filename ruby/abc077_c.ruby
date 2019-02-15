#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.split(" ").map{|i| i.to_i}}
N = input.shift[0]

items = input.map{|r| r.sort}
cnt = 0
for middle in items[1]
  tops = items[0].bsearch_index{|x| x >= middle }
  if tops == nil
    tops = N
  end
  bottoms = items[2].bsearch_index{|x| x > middle }
  if bottoms == nil
    bottoms = N
  end
  bottoms = N - bottoms
  cnt = cnt + (tops * bottoms)
end

puts cnt
