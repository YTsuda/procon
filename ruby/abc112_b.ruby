#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.split(" ").map{|i| i.to_i}}

limit = input[0][1]
input.shift

min_cost = nil
for r in input do
  cost = r[0]
  time = r[1]
  if time <= limit && (min_cost == nil || cost < min_cost) then
    min_cost = cost
  end
end

puts (min_cost == nil) ? 'TLE' : min_cost
