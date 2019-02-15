#! /usr/bin/env ruby

input = STDIN.read.split("\n")

s = input[0]
target = input[1]


def loop_string(s)
  s.slice(-1) + s.slice(0..-2)
end

def check(s, target)
  initial_s = s
  while true
    s = loop_string(s)
    return 'Yes' if target == s
    break if s == initial_s
  end
  return 'No'
end

print check(s, target)

