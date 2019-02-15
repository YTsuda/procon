#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.split(" ").map{|i| i.to_i}}

t_num = input[0][0]
take_cost = input[0][1]
trashes = input[1]

def calc_bring_cost (ts)
  bring_cost = ts[0] * ((ts.length + 1) ** 2)
  i = 0
  while i + 1 < ts.length
    bring_cost = bring_cost +  (ts[i+1] - ts[i]) * ((ts.length - (i + 1) + 1) ** 2)
    i = i + 1
  end
  return bring_cost
end

def calc_take_all (ts, cost)
  take_moving_cost = ts.max
  taking_cost = ts.length * cost
  drop_cost = cost
  bring_cost = calc_bring_cost(ts)
  return take_moving_cost + taking_cost + drop_cost + bring_cost
end

taking_len = 0
total_cost = 0
while taking_len < trashes.length
  if taking_len + 1 === trashes.length
    start_to_current_cost = calc_take_all(trashes, take_cost)

    p "====FINISH"
    p trashes
    print "add_cost: ", start_to_current_cost, "\n"
    total_cost = total_cost + start_to_current_cost
    break
  end
  p "======== ============ =========-"

  # all and next
  start_to_current_tr = trashes.slice(0, taking_len + 1)
  next_tr = trashes.slice(taking_len + 1, 1)

  start_to_current_cost = calc_take_all(start_to_current_tr, take_cost)
  next_cost = calc_take_all(next_tr, take_cost)

  returning_cost = start_to_current_cost + next_cost

  # all
  with_next_tr = trashes.slice(0, taking_len + 2)
  with_next_cost = calc_take_all(with_next_tr, take_cost)

  print start_to_current_tr, next_tr, "\n"
  p with_next_tr
  print "returning_cost: ", returning_cost, "\n"
  print "with_next_cost: ", with_next_cost, "\n"

  if returning_cost < with_next_cost
    total_cost = total_cost + start_to_current_cost
    trashes.slice!(0, taking_len + 1)
    taking_len = 0
    p "RETURN_TO_START"
    print "add_cost: ", start_to_current_cost, "\n"
  else
    taking_len = taking_len + 1
    p "TO_NEXT"
  end
end

# p "TOTAL_COST", total_cost
puts total_cost

