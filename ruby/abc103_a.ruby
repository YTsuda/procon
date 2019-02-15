#! /usr/bin/env ruby

input = STDIN.read.split(' ')

def check_cost(tasks, current_task = 0, cost = 0)
  if tasks.length - 1 == current_task
    return cost
  end
  nest_task = current_task + 1
  current_cost = (tasks[nest_task].to_i - tasks[current_task].to_i).abs
  cost = cost + current_cost
  check_cost(tasks, nest_task, cost)
end

m = nil
input.permutation{ |l|
  cost = check_cost(l)
  if m == nil || cost < m 
    m = cost
  end
}
p m
