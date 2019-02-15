#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.split(" ").map{|i| i.to_i}}

d = input[0]

city_num = d[0]
train_num = d[1]
question_num = d[2]

trains = input.slice(1, train_num).sort_by{|a,b| b}
questions = input.slice(train_num + 1, train_num + question_num)
answers = []

p trains

for q in questions
  q_start = q[0]
  q_end = q[1]
  cnt = 0
  for t in trains
    if t[0] < q_start
      next
    end
    if q_end < t[1] 
      next
    end
    if t[1] < q_start 
      break
    end
    cnt = cnt + 1
  end
  p cnt
end


