#! /usr/bin/env ruby

input = STDIN.read.split("\n")

s = input[0].split(" ").map{|l| l.to_i}

H = s[0]
W = s[1]
X = s[2]

input.shift
rows = input.map{|l| l.split("")}

start = [nil, nil]
goal = [nil, nil]

def content_x (rows, i, j)
  return false if (i < 0 || i >= H) 
  return false if (j < 0 || j >= W) 
  current = rows[i][j]

  if current == "#" then
    content = "#"
  elsif current == "@" then
    content = "@"
  else
    content = "x"
  end
  rows[i][j] = content
end


def write_x (rows, i, j)
  for xi in 0..(X)
    for xj in 0..(X-xi)
      content_x(rows, i+xi, j+xj)
      content_x(rows, i+xi, j-xj)
      content_x(rows, i-xi, j+xj)
      content_x(rows, i-xi, j-xj)
    end
  end
end

rows.each_with_index do |r, i|
  r.each_with_index do |c, j|
    if c == "S" then
      start[0] = i
      start[1] = j
    end
    if c == "G" then
      goal[0] = i
      goal[1] = j
    end
    if c == "@" then
      write_x(rows, i, j)
    end
  end
end

def search_path (rows, start, goal, current, pathes = [])
  if goal == [nil, nil] then
    return -1
  end

  directions = ['U', 'L', 'D', 'R']
  pathes.push([current])
  ct = 0 

  while path = pathes.shift
    node = path.last
    current_state = rows[node[0]][node[1]]

    if current_state == 'G' then
      return path.length - 1
    end

    if ['#', 'd', '@', 'x'].include?(current_state) then
      next
    end
    rows[node[0]][node[1]] = 'd'
    pathes.push(path + [[node[0], node[1] + 1]])
    pathes.push(path + [[node[0], node[1] - 1]])
    pathes.push(path + [[node[0] + 1, node[1]]])
    pathes.push(path + [[node[0] - 1, node[1]]])
    pathes.push(path)
  end

  return -1
end

p search_path(rows, start, goal, start)
