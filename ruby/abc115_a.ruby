#! /usr/bin/env ruby

input = STDIN.read.to_i

t = ['Christmas']
for i in 0...(input - 25).abs
  t.push('Eve')
end

puts t.join(' ')
