; Example of LASM code

global entry start

string = "Hello World!\0"

start {
    @edx = len(string)
    @ecx = string
    @ebx = 1
    @eax = 4
    @int(0x80)
}