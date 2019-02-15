#! /usr/bin/env ruby

t = STDIN.read.chomp()

if t.length == 2 then
  puts t
else
  puts t.reverse
end

