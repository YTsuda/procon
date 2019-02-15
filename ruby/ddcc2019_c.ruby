#! /usr/bin/env ruby

N = STDIN.read.chomp.to_i
m = N ** (1/2)

puts (m ** 10) * (m ** 10)
