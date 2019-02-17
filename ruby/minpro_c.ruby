input = STDIN.read.split("\n").map{|l| l.split(" ").map{|a| a.to_i}}

K = input[0][0]
A = input[0][1]
B = input[0][2]

def check()
    trade_per = (B - A - 1)
    p trade_per
    if trade_per <= 2 
        return K + 1
    end

    res = (K - A + 1) 
    if res <= 0
        return K + 1
    end
    p "=="
    p res
    su = (res / 2).floor * (B - A) + A
    if res % 2 == 1
        su = su + 1
    end
    return su
end

puts check()