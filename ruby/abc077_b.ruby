#! /usr/bin/env ruby

N = STDIN.read.to_i

i = N

while i != 0 
  r = i**(1/2.0) * 10
  if r - r.ceil == 0
    break
  end
  i = i - 1
end

puts i
