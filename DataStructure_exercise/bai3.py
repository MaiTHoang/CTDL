word_file_path = r"F:\Workspace\CTDL\DataStructure_exercise\P1_data.txt"

with open(word_file_path, "r", encoding="utf-8") as file:
    word_file = file.read()

word_file = word_file.split()

word_counter = {}
for word in word_file:
    if word in word_counter:
        word_counter[word] += 1
    else:
        word_counter[word] = 1
print(word_counter)