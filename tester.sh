# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbel-hou <hbel-hou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 15:42:50 by hbel-hou          #+#    #+#              #
#    Updated: 2022/01/10 18:45:46 by hbel-hou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

### INITIALISE VARIABLES
# Colors
NOCOL='\033[0m'
RED='\033[1;31m'
YEL='\033[1;33m'
ORG='\033[0;33m'
GRN='\033[1;32m'
DGRAY='\033[1;30m'
BLU='\033[1;34m'

rm -f instructions.txt

if [ $# -eq 1 ]
then
    if [ $1 != 0 ]
    then
        arg=$(./rondom $1)
    fi
    echo "${DGRAY}arg: ${BLU}$arg \n"

    echo "arg: $arg \n" >> instructions.txt

    instructions=$(.././push_swap $arg) 

    echo "Moves: \n$instructions \n" >> instructions.txt

    NumberOfMoves=$(echo "$instructions" | wc -l | tr -d ' ')

    echo "${DGRAY}Number Of Moves:  ${BLU}$NumberOfMoves"

    echo "Number Of Moves:  $NumberOfMoves"  >> instructions.txt

    checker_result=$(echo "$instructions" | ./checker $arg)

    if [ $checker_result = "OK" ]
    then
        echo "${DGRAY}checker_result: ${GRN}[$checker_result]"
    fi

    if [ $checker_result = "KO" ]
    then
        echo "${DGRAY}checker_result: ${RED}[$checker_result]"
    fi

    echo "${YEL}For More Information Check ${BLU}Instructions.txt"

    echo "${DGRAY}cat ${BLU}Instructions.txt"
fi

if [ $# != 1 ]
then 
    echo "${RED}./Usage <Number Of Arguments>"
fi