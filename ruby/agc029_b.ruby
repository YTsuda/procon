#! /usr/bin/env ruby

input = STDIN.read.split("\n").map{|l| l.split(" ").map{|i| i.to_i}}

N = input[0][0]
L = input[1]

evens = []
odds = []

odds_table = {}
evens_table = {}

for n in L
  if n % 2 == 0
    li = evens
    tb = evens_table
  else
    li = odds
    tb = odds_table
  end

  i = li.length
  tb[i] = {}
  li.each_with_index do |nn, ni|
    wa = nn + n
    if ((wa & (wa - 1)) === 0)
      tb[i][ni] = true
      tb[ni][i] = true
    end
  end
  li.push(n)
end

def counter(tbl)
  cnt = 0
  while tbl.length > 0
    v = tbl.sort_by{|_, v| v.length}[0]
    if v[1] == {}
      break
    end
    a = v[0]
    b = v[1].sort[0][0]
    tbl.delete(a)
    tbl.delete(b)
    tbl.each{|k|
      tbl[k[0]].delete(a)
      tbl[k[0]].delete(b)
    }
    cnt = cnt + 1
  end
  return cnt
end


puts counter(odds_table) + counter(evens_table)
