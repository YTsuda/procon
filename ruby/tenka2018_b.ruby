#! /usr/bin/env ruby

input = STDIN.read.chomp().split(" ").map{|i| i.to_i}

a = input[0]
b = input[1]
k = input[2]

def half_send(c)
  if c % 2 != 0 then
    c = c - 1
  end
  return c / 2
end

is_a_turn = true

while k > 0
  if is_a_turn then
    a = half_send(a)
    b = b + a
  else
    b = half_send(b)
    a = a + b
  end

  k = k - 1
  is_a_turn = !is_a_turn
end

puts sprintf("%s %s", a, b)
