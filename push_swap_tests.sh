# nothing
./push_swap

# non integers
./push_swap  3 2 one 0

# large numbers
./push_swap  3 2 2147483648 0
./push_swap  3 2 -2147483649 0

# duplicate
./push_swap  3 2 2 0

# small
./push_swap 2

./push_swap 2 1

./push_swap 1 2

# pdf

./push_swap 2 1 0 | wc -l # <= 3
./push_swap 1 5 2 4 3 | wc -l # <= 12
./push_swap 100 nums | wc -l # <= 700
./push_swap 500 nums | wc -l # <= 5500

# common
for ((i = 3 ; i <= 100 ; i++)); do
    TEST=`printf "%.2f" $(echo "(l($i)/l(2))*$i" | bc -l)`;
    echo "$i: $TEST"
    for j in {1..3}; do
        ARG=`ruby -e "puts (1..$i).to_a.shuffle.join(' ')"`;
        MOVES=$(printf "%-s" $(./push_swap $ARG | wc -l));
        CHECK=`echo $(./push_swap $ARG | ./checker $ARG)`;
        if [[ $CHECK == "OK" ]]; then
            echo "PASS  $MOVES";
        else
            echo "FAIL | $MOVES | $CHECK";
            echo $ARG;
        fi
    done
    echo "";
done

for ((i = 3 ; i <= 100 ; i++)); do
    TEST=`printf "%.2f" $(echo "(l($i)/l(2))*$i" | bc -l)`;
    echo "$i: $TEST"
    for j in {1..3}; do
        ARG=`ruby -e "puts (1..$i).to_a.shuffle.join(' ')"`;
        MOVES=$(printf "%-s" $(./push_swap $ARG | wc -l));
        CHECK=`echo $(./push_swap $ARG | ./checker $ARG)`;
        if [[ $(echo "$MOVES <= $TEST" | bc -l) == "1" ]] && [[ $CHECK == "OK" ]]; then
            echo "PASS  $MOVES";
        else
            echo "FAIL | $MOVES | $CHECK";
            echo $ARG;
        fi
    done
    echo "";
done

for ((i = 100 ; i <= 500 ; i += 100)); do
    TEST=`printf "%.2f" $(echo "(l($i)/l(2))*$i" | bc -l)`;
    echo "$i: $TEST"
    for j in {1..3}; do
        ARG=`ruby -e "puts (1..$i).to_a.shuffle.join(' ')"`;
        MOVES=$(printf "%-s" $(./push_swap $ARG | wc -l));
        CHECK=`echo $(./push_swap $ARG | ./checker $ARG)`;
        if [[ $CHECK == "OK" ]]; then
            echo "PASS  $MOVES";
        else
            echo "FAIL | $MOVES | $CHECK";
            echo $ARG;
        fi
    done
    echo "";
done
