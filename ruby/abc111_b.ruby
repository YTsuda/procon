#! /usr/bin/env ruby

input = STDIN.read.chomp.to_i
d = input

while true
  ds = d.to_s
  if ds[0] == ds[1] && ds[0] == ds[2] then
    break
  end
  d = d + 1
end

p d
