#! /usr/bin/ruby
# by Matthias Altmann

def is_prime?(nr_to_check)
  divisor = 2
  while (divisor < nr_to_check) do
	  if (nr_to_check % divisor == 0) 
		  return false
          end
	  divisor = divisor + 1
  end
  return true
end

for number in 2..700
	if (is_prime?(number) == true)
		puts "#{number}"
	end
end
