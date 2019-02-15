#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.split(" ").map{|i| i.to_i}}
input.shift

points = input.sort_by!{|p| -p[2]}

def get_center_height(cx, cy, px, py, ph)
  return ph + (px - cx).abs + (py - cy).abs
end

def is_center(cx, cy, points) 
  current_ch = nil
  for pt in points do
    px = pt[0]
    py = pt[1]
    ph = pt[2]

    if ph == 0 then
      checking_ch = current_ch - (px - cx).abs - (py - cy).abs
      ok = checking_ch <= 0
      if !ok then
        return false
      end
      next
    end

    ch = get_center_height(cx, cy, px, py, ph)

    if current_ch == nil then
      current_ch = ch
    elsif current_ch != ch then
      return false
    end
  end

  return ch
end

def get_center(points)
  for cx in 0..100 do
    for cy in 0..100 do
      is_center = is_center(cx, cy, points)
      if is_center != false
        return "#{cx} #{cy} #{is_center}"
      end
    end
  end
  return "No"
end

puts get_center(points)

