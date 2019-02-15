#! /usr/bin/env ruby

T = STDIN.read.chomp()

i = T.length - 1

W = "W"
B = "B"

edge_w = nil
nth_b = 0

total = 0

while i >= 0
  t = T[i]

  if t == W && edge_w == nil
    edge_w = i
  end

  if edge_w != nil && t == B
    total = total + (T.length - i - 1) - (T.length - edge_w - 1) - nth_b
    nth_b = nth_b + 1
  end

  i = i - 1
end

puts total
