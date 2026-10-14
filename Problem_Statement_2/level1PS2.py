import shlex

class Bender:
    def __init__(self, name, Element, hp, Attack, Defense, Speed, moves):
        self.name = name
        self.Element = Element
        self.hp = hp
        self.Attack = Attack
        self.Defense = Defense
        self.Speed = Speed
        self.moves = moves

print("Bender Creation(1st Bender):")
print("- name:", end=" ")
nameofbender = input().lower()
print("- element:", end=" ")
elementofbender = input().lower()
print("- hp:", end=" ")
hpofbender = input().lower()
print("- attack:", end=" ")
attackofbender = input().lower()
print("- defense:", end=" ")
defofbender = input().lower()
print("- speed:", end=" ")
speedofbender = input().lower()
print("- moves:", end=" ")
user_input = input().lower()
movesofbender = shlex.split(user_input)
movelist = [[movesofbender[i], int(movesofbender[i + 1])] for i in range(0, len(movesofbender), 2)]

bender1 = Bender(nameofbender,elementofbender, hpofbender, attackofbender, defofbender, speedofbender,movelist)

print("Bender Creation(2nd Bender):")
print("- name:", end=" ")
nameofbender = input().lower()
print("- element:", end=" ")
elementofbender = input().lower()
print("- hp:", end=" ")
hpofbender = input().lower()
print("- attack:", end=" ")
attackofbender = input().lower()
print("- defense:", end=" ")
defofbender = input().lower()
print("- speed:", end=" ")
speedofbender = input().lower()
print("- moves:", end=" ")
user_input = input().lower()
movesofbender = shlex.split(user_input)
movelist = [[movesofbender[i], int(movesofbender[i + 1])] for i in range(0, len(movesofbender), 2)]

bender2 = Bender(nameofbender,elementofbender, hpofbender, attackofbender, defofbender, speedofbender,movelist)
bender2.hp = int(bender2.hp)
bender1.hp = int(bender1.hp)

print("\n\n\n")
print(f"{bender1.name} ({bender1.Element}) - HP: {bender1.hp}, Attack: {bender1.Attack}, Defense: {bender1.Defense}, Speed: {bender1.Speed}")
print("Moves: ", bender1.moves)
print("\n")
print(f"{bender2.name} ({bender2.Element}) - HP: {bender2.hp}, Attack: {bender2.Attack}, Defense: {bender2.Defense}, Speed: {bender2.Speed}")
print("Moves: ", bender2.moves, "\n\n\n")

hptracker1 = [bender1.hp]
hptracker2 = [bender2.hp]
hptrackindex = 0
while True:
    bender1.hp = hptracker1[hptrackindex]
    bender2.hp = hptracker2[hptrackindex]
    print(f"{bender1.name} should use which attack?")
    for i in range(4):
        print(f"{i+1} : {bender1.moves[i]}")
    atk1 = int(input().lower())
    attack1 = bender1.moves[atk1 - 1][1]
    print(f"{bender2.name} should use which attack?")
    for i in range(4):
        print(f"{i+1} : {bender2.moves[i]}")
    atk2 = int(input().lower())
    attack2 = bender2.moves[atk2 - 1][1]

    damageby1 = round((int(bender1.Attack) * int(attack1)) / int(bender2.Defense))
    damageby2 = round((int(bender2.Attack)*int(attack2)) / int(bender1.Defense))

    if int(bender1.Speed)>int(bender2.Speed):
        print(f"{bender1.name} used {bender1.moves[atk1-1][0]}")
        bender2.hp -= damageby1
        print(f"{bender2.name} took {damageby1} damage and its health fell to {bender2.hp}/{hptracker2[0]}!!!")
        if bender2.hp <= 0:
            print(f"{bender2.name} is unable to battle and has fainted!!!")
            print(f"{bender1.name} is the Winner!!!")
            break
        print(f"{bender2.name} used {bender2.moves[atk2-1][0]}")
        bender1.hp -= damageby2
        print(f"{bender1.name} took {damageby2} damage and its health fell to {bender1.hp}/{hptracker1[0]}!!!")
        if bender1.hp <= 0:
            print(f"{bender1.name} is unable to battle and has fainted!!!")
            print(f"{bender2.name} is the Winner!!!")
            break

    else:
        print(f"{bender2.name} used {bender2.moves[atk2-1][0]}")
        bender1.hp -= damageby2
        print(f"{bender1.name} took {damageby2} damage and its health fell to {bender1.hp}/{hptracker1[0]}!!!")
        if bender1.hp <= 0:
            print(f"{bender1.name} is unable to battle and has fainted!!!")
            print(f"{bender2.name} is the Winner!!!")
            break
        print(f"{bender1.name} used {bender1.moves[atk1-1][0]}")
        bender2.hp -= damageby1
        print(f"{bender2.name} took {damageby1} damage and its health fell to {bender2.hp}/{hptracker2[0]}!!!")
        if bender2.hp <= 0:
            print(f"{bender2.name} is unable to battle and has fainted!!!")
            print(f"{bender1.name} is the Winner!!!")
            break

    hptracker1.append(bender1.hp)
    hptracker2.append(bender2.hp)
    hptrackindex=hptrackindex+1