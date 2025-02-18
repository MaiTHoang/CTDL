import string
character_statistics = {}
string = "Happiness"
string = string.lower()
for character in string:
    if character in character_statistics:
        character_statistics[character] += 1
    else:
        character_statistics[character] = 1
print("Thống kê ký tự:", character_statistics)