word_file_path = r"F:\Workspace\CTDL\DataStructure_exercise\P1_data.txt" #path to file

# Read file
with open(word_file_path, "r", encoding="utf-8") as file:
    word_file = file.read()

# Split word
word_file = word_file.split()

# Create a dictionary to store the words and their frequencies
word_counter = {}

# Count the number of times each word appears in the file
for word in word_file:
    if word in word_counter:
        word_counter[word] += 1
    else:
        word_counter[word] = 1

# Remove all non-alphabetic characters from the dictionary
print(word_counter)