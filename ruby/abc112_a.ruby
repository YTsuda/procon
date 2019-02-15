#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.to_i}
age = input[0]

if age == 1 then
  puts "Hello World"
else
  puts input[1] + input[2]
end
