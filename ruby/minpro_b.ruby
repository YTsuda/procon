INPUT = STDIN.read.split("\n").map{|l| l.split(" ").map{|a| a.to_i}}


def check
    dic = {}
    INPUT.each {|r|
        r.each {|c|
            if dic.key?(c)
                dic[c] = dic[c] + 1
            else
                dic[c] = 1
            end
            if dic[c] >= 3 
                return "NO"
            end
        }
    }
    return "YES"

    check
end

puts check()