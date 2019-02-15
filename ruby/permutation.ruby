#! /usr/bin/env ruby


A = [1, 2, 3, 4]

def perm(a, s = [], r = [])
  if a.length == 0
    r.push(s)
    return
  end

  a.each_with_index do |n, i|
    p n
    ac = a.clone()
    sc = s.clone()
    sc.push(ac[i])
    ac.delete_at(i)
    perm(ac, sc, r)
  end

  return r
end

p perm(A)
