input = STDIN.read.split("\n").map{|l| l.split(" ").map{|a| a.to_i}}

N = input[0][0]
K = input[0][1]

puts ((N * 1.0 / 2).ceil >= K) ? 'YES' : 'NO'