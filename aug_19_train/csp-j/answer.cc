// This code generated by ansgen.py

#include <iostream>

using namespace std; 
char ans[255];
int main() { 

	/* !SOURCE CODE COMMENT BEGIN!
  1 -  5 
	!SOURCE CODE COMMENT END! */

	ans[1] = 'B';
	ans[2] = 'A';
	ans[3] = 'C';
	ans[4] = 'B';
	ans[5] = 'D';

	/* !SOURCE CODE COMMENT BEGIN!
  6 - 10 
	!SOURCE CODE COMMENT END! */

	ans[6] = 'B';
	ans[7] = 'B';
	ans[8] = 'C';
	ans[9] = 'C';
	ans[10] = 'A';

	/* !SOURCE CODE COMMENT BEGIN!
 11 - 15 
	!SOURCE CODE COMMENT END! */

	ans[11] = 'C';
	ans[12] = 'D';
	ans[13] = 'B';
	ans[14] = 'B';
	ans[15] = 'D';

	/* !SOURCE CODE COMMENT BEGIN!
 16 - 20 
	!SOURCE CODE COMMENT END! */

	ans[16] = 'T';
	ans[17] = 'F';
	ans[18] = 'T';
	ans[19] = 'F';
	ans[20] = 'C';

	/* !SOURCE CODE COMMENT BEGIN!
 21 - 25 
	!SOURCE CODE COMMENT END! */

	ans[21] = 'D';
	ans[22] = 'F';
	ans[23] = 'F';
	ans[24] = 'T';
	ans[25] = 'D';

	/* !SOURCE CODE COMMENT BEGIN!
 26 - 30 
	!SOURCE CODE COMMENT END! */

	ans[26] = 'A';
	ans[27] = 'D';
	ans[28] = 'F';
	ans[29] = 'T';
	ans[30] = 'F'; // RANDOM GENERATED BY ansgen.py 

	/* !SOURCE CODE COMMENT BEGIN!
 31 - 35 
	!SOURCE CODE COMMENT END! */

	ans[31] = 'C';
	ans[32] = 'A';
	ans[33] = 'A';
	ans[34] = 'D';
	ans[35] = 'D';

	/* !SOURCE CODE COMMENT BEGIN!
 36 - 40 
	!SOURCE CODE COMMENT END! */

	ans[36] = 'D';
	ans[37] = 'A';
	ans[38] = 'D';
	ans[39] = 'C';
	ans[40] = 'B'; // RANDOM GENERATED BY ansgen.py 

	/* !SOURCE CODE COMMENT BEGIN!
 41 - 43 
	!SOURCE CODE COMMENT END! */

	ans[41] = 'B'; // RANDOM GENERATED BY ansgen.py 
	ans[42] = 'B'; // RANDOM GENERATED BY ansgen.py 
	ans[43] = 'B'; // RANDOM GENERATED BY ansgen.py 

	/* !SOURCE CODE COMMENT BEGIN!


	This comment will be included in the source.
	
	As we know, this answer code isn't typed by humans; Instead, I used a script called ansgen.py to generate it.
	
	The ansgen.py reads a file called "answer.txt" in the current working directory as its input, and use a file called "answer.cc"
	as its output. 
	
	The content of "answer.txt" should follow some syntax so the ansgen.py could parse it and turn it into the final C++ source 
	code.
	
	The grammar is super simple.
	
	First, if you want to write an option (suchs, C, B, A, D, T, F, etc), just type it in the upper case.
	Here is an example:
	
	ABCBA BBCBA DDBAB TTFTF
	
	If you don't know the answer of a question, type `?` for ABCD-options and `/` for TF-options, so the ansgen.py will select
	an answer randomly as the answer of the question. For example:
	
	????? /////
	AB?D? /FTD?
	
	Easy peasy, huh? But how this comment appears in the generated source file?
	
	In answer.txt, three types of comments are allowed.
	
	A single-line comment looks like this:
	
	| A single-line comment here.
	
	Just type a pipe mark '|' to enable a single-line comment.
	
	And also there is a kind of comment called block comments which use the following syntax.
	
	{!
		A block comment.
	!}
	
	The two kinds of comments will not appear in the generated code. But the next one, which called the raw comments, will be in-
	cluded in the generated code. 
	
	The syntax of raw comments are start with a single '[' and a single '!', and ends with a '!' with a ']'.
	
	Here are the source code of codegen.py:
	
	#!/usr/local/bin/rustpython

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
	        elif i == "|":
	            parse_state = 4
	        elif i == "{":
	            parse_state = 5
	    elif parse_state == 1:
	        if i == "!":
	            parse_state = 2
	            out_content += f"\n\t/* !SOURCE CODE COMMENT BEGIN!\n"
	        else:
	            parse_state = 0
	    elif parse_state == 2:
	        if i == "!":
	            parse_state = 3
	        elif i == "*":
	            parse_state = 8
	        else:
	            out_content += i
	    elif parse_state == 3:
	        if i == "]":
	            parse_state = 0
	            out_content += f"\n\t!SOURCE CODE COMMENT END! * /\n\n" # In the actual code, there is not space between '*' and '/'. Please delete it manually.
	        else:
	            parse_state = 2
	            out_content += f"!{i}"
	    elif parse_state == 4:
	        if i == "\n":
	            parse_state = 0
	    elif parse_state == 5:
	        if i == "!":
	            parse_state = 6
	        else:
	            parse_state = 0
	    elif parse_state == 6:
	        if i == "!":
	            parse_state = 7
	    elif parse_state == 7:
	        if i == "}":
	            parse_state = 0
	        else:
	            parse_state = 6
	    elif parse_state == 8:
	        if i == "/":
	            out_content += "* /" # In the actual code, there IS a space between "*" and "/". Please do NOT delete it.
	        elif i == "*":
	            parse_state = 8
	            out_content += "*"
	            continue
	        elif i == "!":
	            parse_state = 3
	            continue
	        else:
	            out_content += f"*{i}"
	        parse_state = 2

	out_content += "\n\t\n\tint n;\n\tcin >> n;\n\tcout << ans[n];\n}"

	out_file.write(out_content)
	in_file.close()
	out_file.close()
	
	

	!SOURCE CODE COMMENT END! */


	
	int n;
	cin >> n;
	cout << ans[n];
}