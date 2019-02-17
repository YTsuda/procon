input = STDIN.gets.chomp.split(" ").map{|i| i.to_i}

N = input[0]
M = input[1]
K = input[2]

A = STDIN.gets.chomp.split(" ").map.with_index{|a, i| [i, a.to_i]}
sorted_a = A.sort_by{|a| a[1]}.reverse.slice(0, M * K).sort_by{|a| a[0]}

total = 0
slices = []
sorted_a.each_with_index{|a, i|
    if i != (M * K - 1) && (i % M) == (M - 1)
        slices.push(a[0] + 1)
    end
    total = total + a[1]
}
puts total
puts slices.join(" ")