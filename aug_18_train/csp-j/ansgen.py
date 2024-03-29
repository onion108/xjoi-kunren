#!/usr/local/bin/rustpython

# README
# This little script is used to generate the answer code for the CSP-J primary
# competition emulation.
# It reads the content from answer.txt and output it to answer.cc.
# The grammar are shown as the following:
#
# [! Comments are included in these two guys !]
# ABCCB ABCDD [! Just type the answer in UPPER CASE to input answer. !]
# ????? /////
# [!
#     Two special charaters: `?` will generate an answer randomly from ABCD.
#                            `/` will generate an answer randomly from TF.
# !]

import random

in_file = open("./answer.txt", "r")
out_file = open("./answer.cc", "w")

in_content = in_file.read()
out_content = "// This code generated by ansgen.py\n\n#include <iostream>\n\n"\
    + "using namespace std; \nchar ans[255];\nint main() { \n"

parse_state = 0
counter = 1
for i in in_content:
    if parse_state == 0:
        if i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            out_content += f"\tans[{counter}] = '{i}';\n"
            counter += 1
        elif i == "[":
            parse_state = 1
        elif i == "?":
            option = random.choice("CCCCCCCCCCBBBBBBBBDDDDDAAAAA")
            out_content += f"\tans[{counter}] = '{option}'; "
            out_content += "// RANDOM GENERATED BY ansgen.py \n"
            counter += 1
        elif i == "/":
            option = random.choice("TF")
            out_content += f"\tans[{counter}] = '{option}'; "
            out_content += "// RANDOM GENERATED BY ansgen.py \n"
            counter += 1
    elif parse_state == 1:
        if i == "!":
            parse_state = 2
            out_content += f"\n\t/* !SOURCE CODE COMMENT BEGIN!\n"
        else:
            parse_state = 0
    elif parse_state == 2:
        if i == "!":
            parse_state = 3
        else:
            out_content += i
    elif parse_state == 3:
        if i == "]":
            parse_state = 0
            out_content += f"\n\t!SOURCE CODE COMMENT END! */\n\n"
        else:
            parse_state = 2
            out_content += f"!{i}"

out_content += "\n\t\n\tint n;\n\tcin >> n;\n\tcout << ans[n];\n}"

out_file.write(out_content)
in_file.close()
out_file.close()
