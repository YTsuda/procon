#! /usr/bin/env ruby

input = STDIN.read.to_i

def count_yakusu(n)
  ct = 0
  for i in 1..n
    if n % i == 0
      ct = ct + 1
    end
  end
  return ct
end

ct = 0
for i in 1..input
  if i % 2 == 1 && count_yakusu(i) == 8
    ct = ct + 1
  end
end

print ct
