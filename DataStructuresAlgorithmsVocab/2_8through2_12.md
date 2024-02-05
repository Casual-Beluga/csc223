# Time and Space Complexity
* The time complexity of an algorithm is essentially how much time it will take to execute given a certain input size
* The space comlexity of an algorithm is how much space in memory it will take up as a function of input size

# best, worst, average, and amortized run times
* The best time would be the fastest an algorithm could run for a idealized scenerio. Such as doing a linear search on an array and the element is in the first index of the array.
* The worst time would be the opposite of this where it is the slowest an algorithm could run based on a worst case scenario.
* The average run time of an algorithm is the expected run time of an algorithm for an expected although randomly distributed sets of inputs that are all the same size. 
* The amortized run time of an algorithm is taking the average time of related operations of an algorithm averaged together in the worst case. So it finds the average run time of a certain operation in the worst case.

# Expressing time and space complexity
* the time and space complexity of an algorithm can be described by f(n) where n is the input size.
* The most common notation is Big O notation, O(n), which provides the upper bound for the complexity of an algorithm.

## Linear Loops
* for algorithms with a singular loop the general formula is f(n) = n.

## Logarithmic Loops
* In logarithmic loops the loop controlling variable is either muliplied or divided.
* for(i=1;i<1000;i*=2) for(i=1000;i>=1;i/=2)
statement block; statement block;
So for loops where the controlling variable is multiplied or divided each iteration the general size of the function is f(n) = log n.

## nested loops
* Loops that contain loops
* the complexity of the total function depends on the inner loop.
* A linear logarithmic loop is when the inner loop has its controlling variable multiplied or divided while the outer loop has its controlling variable linear modified. The complexity can be described as f(n) = n log n
* Quadratic loops are where both the inner and outer loops controlling variables are controlled through multiplication or division. Therefore the complexity would be f(n) = n^2. 
* Dependent quadratic loops is when the the number of iterations that the inner loop performs is based on the controlling variable of the outer loop. So f(n) = (n^2 + n)/2 where n is the number of iterations of the out loop. 

# Big O notation.
* The O stands for 'order of' and big O notation is mostly concerned for large input sizes. 
* An algorithm that takes n^2 steps to sort n elements would be descirbed as O(n^2)
* Constant multipliers are ignored so O(4n) is equal to O(n). 
* f(n) = O(g(n), this means that f(n) will grow no faster then a constant factor of g(n).
* f(n) <= c*g(n) where c is a constant that depends on external factors such as the cpu, programming language, and speed of memory access.
* O(g(n)) = {h(n): ∃ positive constants c, n0 such that 0 ≤ h
(n) ≤ cg(n), ∀ n ≥ n0}, O(g(n)) comprises a set of all the functions h(n)
that are less than or equal to cg(n) for all values of n ≥ n0.
* If f(n) ≤ cg(n), c > 0, ∀ n ≥ n0, then f(n) = O(g(n)) and g(n) is an asymptotically tight upper bound for f(n).
* Worst case big or describes a lower bound for the worst case scenario and best case describes an upper bound for the best case.
* There are five catagories of algorithms. Constant time O(1), linear time O(n), logarithmic O log(n) time, polynomial time O(n^k), exponential time O(2^n).  
* Big O only describes how the algorithm grows with the size of the problem, not how efficient it is or the programming effort.


# Omega Notation
* Omega notation describes the lower bound for a function.
* Ω notation is simply written as, f(n) ∈ Ω(g(n)), where n is the problem size and
Ω(g(n)) = {h(n): ∃ positive constants c > 0, n0 such that 0 ≤ cg(n) ≤ h(n), ∀ n ≥ n0}.
Hence, we can say that Ω(g(n)) comprises a set of all the functions h(n) that are greater than or equal to cg(n) for all values of n ≥ n0.
If cg(n) ≤ f(n), c > O, ∀ n ≥ nO, then f(n) ∈ Ω(g(n)) and g(n) is an asymptotically tight
lower bound for f(n).
* For a best case theta the function cannot get better then the specified value
* For a worst case scenario it describes the fastest/lower bound for a worst case scenario 

# Theta Notation
* f(n) ∈ Θ(g(n)), where n is the problem size and
Θ(g(n)) = {h(n): ∃ positive constants c1, c2, and n0 such that 0 ≤ c1g(n) ≤ h(n) ≤ c2g(n), ∀ n ≥ n0}. Hence, we can say that Θ(g(n)) comprises a set of all the functionsh(n) that are betweenc1g(n) and c2g(n) for all values of n ≥ n0. If f(n) is between c1g(n) and c2g(n), ∀ n ≥ n0, then f(n) ∈ Θ(g(n)) and g(n) is an asymptotically tight bound for f(n) and f(n) is amongst h(n) in the set.
* The best case of an algorithm is not used
* So for the worst case set of inputs it provides asymptotes to what the complexity can be based on the size of the input.
* Basically shows that the complexity of an algorithm is bound between two values.
* Show that n2/2 – 2n = Θ(n2).
* c1n2(n) <= h(n) <- c2g(n)
* c1n2 <= n2/2 – 2n <= c2n2
* Dividing by n2, we get
c1n2/n2 ≤ n2/2n2 – 2n/n2 ≤ c2n2/n2
* c1 ≤ 1/2 – 2/n ≤ c2
* This means c2 = 1/2 because lim as n->infinity of 1/2 – 2/n = 1/2 (Big O notation)

#Little o notation
* it provides a non asymptotic tight bound for the function f(n) 
