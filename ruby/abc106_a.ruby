#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|a| a.to_i}
print (input[0] - 1) * (input[1] - 1)
