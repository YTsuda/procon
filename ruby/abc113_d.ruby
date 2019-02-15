#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.split(" ").map{|i| i.to_i}}.shift
H = input[0]
W = input[1]
K = input[2]

amida = Array.new(H).map{Array.new(W - 1)}
$cnt = 0

#p "== IS GOAL"
#p K

def am(amida, y, x)
  #p "==== NOW ==="
  #p y 
  #p x
  #p amida

  if y == H 
    #p "=====GOAL"
    if x + 1 == K
      $cnt = $cnt + 1
    end
    return
  end

  if x < W - 1
    to_right_amida = Marshal.load(Marshal.dump(amida))
    to_right_amida[y][x] = 1
    am(to_right_amida, y + 1, x + 1)
  end

  to_streight_amida = Marshal.load(Marshal.dump(amida))
  am(to_streight_amida, y + 1, x)

  if x > 0
    to_left_amida = Marshal.load(Marshal.dump(amida))
    to_left_amida[y][x - 1] = 1
    am(to_left_amida, y + 1, x - 1)
  end
end

am(amida, 0, 0)
p "===CNT=="
p $cnt % 1000000007
