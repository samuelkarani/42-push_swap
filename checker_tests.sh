# nothing
./checker

# non integers
./checker  3 2 one 0

# large numbers
./checker  3 2 2147483648 0
./checker  3 2 -2147483649 0

# duplicate
./checker  3 2 2 0

# non-existent instructions
./checker  3 2 1 0
ra
ee
sa

# incorrect formating
./checker  3 2 1 0
ra
 rb

./checker  3 2 1 0
sa
ra rb

./checker  3 2 1 0
ra
sa # space after

# sorted no instructions ?
# ./checker 1

# ok
./checker 1 3 5 6

./checker 3 2 1 0
rra
pb
sa
rra
pa

./checker 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa

./checker 5 4 1 3 2
ra
ra
pb
ra
pb
sa
ra
sa
rra
sa
pa
pa

#ko
./checker 3 2 1 0
sa
rra
pb