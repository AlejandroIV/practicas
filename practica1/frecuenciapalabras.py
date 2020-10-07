# Reads a file text and prints the frequency of the words

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

# Declares a list to hold the dictionary values to sort them later
lstKeys = list()

# Loop to read all the lines in the file
for line in fh:
    line = line.split()
    # Loop to traverse the words in the line
    for word in line:
        dctKeys[word] = dctKeys.get(word, 0) + 1

# Loop to assign the dictionary values to the list
for key, value in dctKeys.items():
    lstKeys.append((value, key))

lstKeys.sort(reverse = True)

print(f"\n{lstKeys}")