inp = STDIN.read.split("\n").map{|l| l.split(" ").map{|a| a.to_i}}

X = inp[0][0]
Y = inp[0][1]
Z = inp[0][2]

A = inp[1][0]
B = inp[1][1]
C = inp[1][2]

def check()
    if A < X
        return false
    end
    remain_a = A - X

    if remain_a + B < Y
        return false
    end

    remain = remain_a + B - Y

    if remain + C < Z
        return false
    end

    return true
end

puts check() ? "YES" : "NO"

