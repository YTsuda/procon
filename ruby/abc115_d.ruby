#! /usr/bin/env ruby

input = STDIN.read.split(" ").map{|l| l.to_i}

N = input[0]
X = input[1]

def barger
  current_peak = 1
  max_peak = 1
  is_one = true
  trend_down = false
  while current_peak < N
    if is_one == true
      p 1
      is_one = false
      next
    end
    p current_peak

    if trend_down == false
      current_peak = current_peak + 1
    else
      current_peak = current_peak - 1
    end
    if current_peak == false
      p current_peak
      is_one == true
      next
    end

  end
end

barger()


