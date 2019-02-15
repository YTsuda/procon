f = STDIN.gets.chomp.split(" ").map(&:to_i)

N = f[0]
K = f[1]
H = STDIN.gets.chomp.split(' ').map(&:to_i)

BAG = []

def jump(i = 0)
  #p "====="
  #p i
  if BAG.slice(i) != nil
    return BAG[i]
  end
  costs = []
  if i == N - 1
    costs.push(0)
  else
    l = [(N - i - 1), K].min
    #p BAG
    costs = []
    for j in 1..l
      #p j
      c = BAG[i + j]
      cn = (H[i] - H[i + j]).abs
      costs.push(c + cn)
    end
    #p costs
  end

  res = costs.min
  BAG[i] = res
  return res
end

c = 0
(0..(N - 1)).reverse_each { |i|
  c = jump(i)
}
puts c
