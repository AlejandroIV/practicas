# Page 108

while True:
    fname = input("Enter file name: ")
    if len(fname) < 1:
        fname = "words.txt"
    try:
        fh = open(fname)
        break
    except:
        print("Error!! Document does not exist")
        print("If you do not know the file name, just press 'Enter'")

# Declares a dictionary to hold the "keys"
dctKeys = dict()

# Loop to read all the lines in the file
for line in fh:
    line = line.split()
    # Loop to traverse the words in the line
    for word in line:
        # Conditional to check whether the "dctKeys" variable has already the "key"
        if not(word in dctKeys):
            dctKeys[word] = dctKeys.get(word, 0)

print()
print(dctKeys)