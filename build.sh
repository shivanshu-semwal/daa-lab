#!/bin/bash

# compile [week_no] [que_no]
# compiles the que_no and store the output to the respective files
# you may see some stderr messages
# only stdout is stored in the file
compile() {
    echo -e "Compiling week$1 program no $1"
    # WEEK="$1"
    # NUMBER="$2"
    DIR="week$1"
    g++ $DIR/$2.cpp -o $DIR/$2
    $DIR/$2 <$DIR/$2.in >$DIR/$2.out
}

week1() {
    compile 1 1
    compile 1 2
    compile 1 3
}

week2() {
    compile 2 1
    compile 2 2
    compile 2 3
}

week3() {
    compile 3 1
    compile 3 2
    compile 3 3
}

week4() {
    compile 4 1
    compile 4 2
    compile 4 3
}

week5() {
    compile 5 1
    compile 5 2
    compile 5 3
}

week6() {
    compile 6 1
    compile 6 2
    # compile 6 3
}

week7() {
    compile 7 1
    compile 7 2
    compile 7 3
}

week8() {
    compile 8 1
    compile 8 2
    compile 8 3
}

week9() {
    compile 9 1
    compile 9 2
    compile 9 3
}

week10() {
    compile 10 1
    compile 10 2
    compile 10 3
}

week11() {
    compile 11 1
    compile 11 2
    compile 11 3
}

week1
week2
week3
week4
week5
week6
week7
week8
week9
week10
week11
