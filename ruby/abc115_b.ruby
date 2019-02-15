#! /usr/bin/env ruby

a = STDIN.read.split("\n").map{|l| l.to_i}
N = a.shift()

max = 0
total = 0

a.each{|i|
  total = total + i
  if max < i
    max = i
  end
}

puts (total - max / 2)
