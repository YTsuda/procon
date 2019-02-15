#! /usr/bin/env ruby

input = STDIN.read.split("\n")[1].split(' ')
t = input.inject(0){|acc, v| acc + v.to_i - 1}
print t