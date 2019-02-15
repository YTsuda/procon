#! /usr/bin/env ruby

N = STDIN.read.chomp.to_i


def count_black  
  if N == 2
    return 0
  elsif N == 3
    return 1
  end

  t = 0
  if N % 2 == 1
    m = N - 1
    t = 1
  else 
    m = N
  end

  kou = m / 2 - 1
  wa = (4 + 4 * kou) * kou / 2
  return wa + t
end

puts count_black()

