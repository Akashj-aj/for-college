# python program to copy the contents of only odd lines from one file to another file.

ipfile = open("input.txt", 'r')
lines = ipfile.readlines()
oddlines = lines[0::2]
opfile = open("outputfile.txt", 'w')

for line in oddlines:
    opfile.write(line)

ipfile.close()
opfile.close()