#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.split(" ")}
lens = input[0].map{|i| i.to_i}
chars = input[1]

N = lens[0]
M = lens[1]

S = input[1][0]
T = input[2][0]

L = N.lcm(M)
lib = {}

for i in 0..(S.length - 1)
  pos = 1
  if i > 0
    pos = L / N * i + 1
  end

  lib[pos] = S[i]
end

ok = true

for i in 0..(T.length - 1)
  pos = 1
  if i > 0
    pos = L / M * i + 1
  end

  if lib.has_key?(pos) && lib[pos] != T[i] then
    ok = false
    break;
  else
    lib[pos] = T[i]
  end
end

if ok then
  puts L
else
  puts "-1"
end
