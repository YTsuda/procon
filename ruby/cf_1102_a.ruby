#! /usr/bin/env ruby

input = STDIN.read.chomp.to_i

d = input % 4
puts (d == 0 || d == 3) ? 0 : 1

