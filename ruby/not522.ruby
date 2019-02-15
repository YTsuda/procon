#! /usr/bin/env ruby

input = STDIN.read.to_i

PRIMES = {}

def prime? n
  if PRIMES.has_key?(n)
    return primes[n]
  end
  is_prime = (2..Math.sqrt(n)).none? {|f| n % f == 0}
  PRIMES[n] = is_prime
end

N = input
p N

stack = []

for i in 2..100 do
  p i
  p prime?(i)
end
