#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.split(" ").map{|i| i.to_i}}
input.shift

def can_even(c100, c10, c1)
  if c1 % 2 == 1 then
    return false
  end
  c1_10 = (c1 / 10).floor
  if c10 % 2 == 1 && c1_10 == 0 then
    return false
  end

  c10_100 = ((c10 + c1_10) / 10).floor
  if c100 % 2 == 1 && c10_100 == 0 then
    return false
  end
  return true
end

for r in input do
  puts can_even(r[0], r[1], r[2]) ? "Yes" : "No"
end
