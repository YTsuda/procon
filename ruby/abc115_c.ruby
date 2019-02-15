#! /usr/bin/env ruby

input = STDIN.read.split("\n")
n = input.shift.split(" ").map{|i| i.to_i}

N = n[0]
K = n[1]

hs = input.map{|i| i.to_i}.sort

min_diff = nil
for i in 0..(N-K)
  diff = hs[i + K - 1] - hs[i]
  if min_diff == nil || min_diff > diff
    min_diff = diff
  end
end

puts min_diff

