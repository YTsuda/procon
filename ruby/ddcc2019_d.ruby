#! /usr/bin/env ruby

N = STDIN.read.chomp.to_i

n = 1
amari = N

calc = 0

while amari >= 1
  amari = N * 1.0 / n
  if amari < 1
    break
  end
  calc = calc + amari.floor
  n = n + 1
end

p (calc ** 20) % 1000000007
