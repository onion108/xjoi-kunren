from sys import stdout
import time

def speak(who, msg, gap):
    print(who, end=' ')
    for i in msg:
        print(i, end='')
        stdout.flush()
        time.sleep(gap)
    print()
    
speak("\033[33m[FLOWEY]\033[00m", "* Howdy!", .04)
time.sleep(1)
speak("\033[33m[FLOWEY]\033[00m", "* I'm Flowey!", .04)
time.sleep(1)
speak("\033[33m[FLOWEY]\033[00m", "* Flowey the flower!", .04)
time.sleep(1)
speak("[GASTER]", "* fuck you!", .04)
time.sleep(1)
speak("\033[31m[CHARA]\033[00m", "* (Sans seems to be too lazy to talk. He's still sleeping in the RAM.)", .04)
time.sleep(1)
speak("[PAPYRUS]", "I, THE GREAT PAPYRUS, WANNA SEX WITH YOU, HUMAN!", .038)
time.sleep(1)
speak("[GASTER]", "WAIT WHAT - ", .04)
time.sleep(1)
speak("[瞿子皓]", "* 你在狗叫什么？你在狗叫什么？你在狗叫什么？", .02)
time.sleep(1)
speak("\033[36m[sans]\033[00m", "* what the fuck.", .2)

