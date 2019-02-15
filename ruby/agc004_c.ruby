#! /usr/bin/env ruby

input = STDIN.read.split("\n")
d = input.shift.split(" ").map{|i| i.to_i}
H = d[0]
W = d[1]
p H
p W
MAP = input.map{|r| r.split('')}

red_m = Array.new(H).map{Array.new(W)}
blue_m = Array.new(H).map{Array.new(W)}

initial_i = nil
initial_j = nil

MAP.each_with_index do |row, i|
  row.each_with_index do |cell, j|
    if cell == "#" 
      initial_i = i
      initial_j = j
      break
    end
  end
  if initial_i != nil && initial_j != nil
    break
  end
end

def paint(m, i, j)
  if m[i][j] == "#" || MAP[i][j] != "#" 
    return
  end
  m[i][j] = "#"
  paint(m, i - 1, j)
  paint(m, i + 1, j)
  paint(m, i, j - 1)
  paint(m, i, j + 1)
end

paint(red_m, initial_i, initial_j)

def search(m, i, j)
  search_map
end

search(red_m, initial_i, initial_j)

