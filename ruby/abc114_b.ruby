#! /usr/bin/env ruby

st = STDIN.read.chomp

min_abs = nil
i = 0
while i < st.length - 2
  a = ((st[i] + st[i + 1] + st[i + 2]).to_i - 753).abs
  if min_abs == nil || a < min_abs 
    min_abs = a
  end
  i = i + 1
end

puts min_abs
