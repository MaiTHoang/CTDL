import string
character_statistics = {} #temporate dictionary
string = "Happiness"
string = string.lower() #convert all characters to lowercase

#count the number of occurrences of each character in the string
for character in string:
    if character in character_statistics:
        character_statistics[character] += 1
    else:
        character_statistics[character] = 1

#remove all non-alphabetic characters from the dictionary
print(character_statistics)