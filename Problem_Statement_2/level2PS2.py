import shlex
from random import randint

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
nameofbender = input()
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
user_input = input()
movesofbender = shlex.split(user_input)
movelist = [[movesofbender[i], int(movesofbender[i + 1])] for i in range(0, len(movesofbender), 2)]

bender1 = Bender(nameofbender,elementofbender, hpofbender, int(attackofbender), int(defofbender), int(speedofbender),movelist)

print("Bender Creation(2nd Bender):")
print("- name:", end=" ")
nameofbender = input()
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
user_input = input()
movesofbender = shlex.split(user_input)
movelist = [[movesofbender[i], int(movesofbender[i + 1])] for i in range(0, len(movesofbender), 2)]

bender2 = Bender(nameofbender,elementofbender, hpofbender, int(attackofbender), int(defofbender), int(speedofbender),movelist)
bender2.hp = int(bender2.hp)
bender1.hp = int(bender1.hp)
dmgdealt = 1

bender1_goesfirst = False
atk = int(0)
bender1attacks = False
attacker_has_elemental_adv = False
defender_has_elemental_adv = False
hptracker1 = [bender1.hp]
hptracker2 = [bender2.hp]
hptrackindex = 0
supeffhc = 0
nvehc = 0
crithc = 0

class Duel:
    def __init__(self, char1, char2):
        self.char1 = char1
        self.char2 = char2
    def start_duel(self):
        print("\n\n=== DUEL BEGINS! ===")
    def display_matchup(self, bender1, bender2):
        self.bender1 = bender1
        self.bender2 = bender2
        print(f"{bender1.name} ({bender1.Element}, HP: {bender1.hp}/{bender1.hp}) VS {bender2.name} ({bender2.Element}, HP: {bender2.hp}/{bender2.hp})")

    def dmgcalc(self, object_1_bender, object_2_bender):
        global attacker_has_elemental_adv, defender_has_elemental_adv, dmgdealt, supeffhc, nvehc, crithc
        self.object_1_bender = object_1_bender
        self.object_2_bender = object_2_bender
        if bender1attacks:
            attacker_attack = object_1_bender.Attack
            move_power = int(object_1_bender.moves[atk-1][1])
            defnderdefense = object_2_bender.Defense
            damage = (attacker_attack * move_power) / defnderdefense

            # type chart
            if object_2_bender.Element == "fire":
                bender2elem = 1
            elif object_2_bender.Element == "water":
                bender2elem = 2
            elif object_2_bender.Element == "earth":
                bender2elem = 3
            else:
                bender2elem = 4

            if object_1_bender.Element == "fire":
                bender1elem = 1
            elif object_1_bender.Element == "water":
                bender1elem = 2
            elif object_1_bender.Element == "earth":
                bender1elem = 3
            else:
                bender1elem = 4

            if (bender1elem>bender2elem and bender1elem-bender2elem == 1) or bender1elem-bender2elem == -3:
                attacker_has_elemental_adv = True

            if (bender2elem>bender1elem and bender2elem-bender1elem == 1) or bender2elem-bender1elem == -3:
                defender_has_elemental_adv = True

            if attacker_has_elemental_adv:
                damage = damage*2
                supeffhc += 1

            if defender_has_elemental_adv:
                damage = damage*0.5
                nvehc += 1

            critnum = randint(1,10)

            if critnum == 7:
                damage=damage*2
                print("Critical Hit!!!")
                crithc+=1


        if bender1attacks==False:
            attacker_attack = object_2_bender.Attack
            move_power = int(object_2_bender.moves[atk-1][1])
            defnderdefense = object_1_bender.Defense
            damage = (attacker_attack * move_power) / defnderdefense
    
                # type chart
            if object_2_bender.Element == "fire":
                bender2elem = 1
            elif object_2_bender.Element == "water":
                bender2elem = 2
            elif object_2_bender.Element == "earth":
                bender2elem = 3
            else:
                bender2elem = 4
                        
            if object_1_bender.Element == "fire":
                bender1elem = 1
            elif object_1_bender.Element == "water":
                bender1elem = 2
            elif object_1_bender.Element == "earth":
                bender1elem = 3
            else:
                bender1elem = 4

            if (bender2elem>bender1elem and bender2elem-bender1elem == 1) or bender2elem-bender1elem == -3:
                attacker_has_elemental_adv = True

            if (bender1elem>bender2elem and bender1elem-bender2elem == 1) or bender1elem-bender2elem == -3:
                defender_has_elemental_adv = True

            if attacker_has_elemental_adv:
                damage = damage*2
                supeffhc += 1
            if defender_has_elemental_adv:
                damage=damage*0.5
                nvehc += 1

            critnum = randint(1,10)
            if critnum == 7:
                damage = damage*2
                print("Critical Hit!!!")

        dmgdealt = damage
    def dmgchng(self, object_1_bender, object_2_bender):
        global hptrackindex
        self.object_1_bender = object_1_bender
        self.object_2_bender = object_2_bender
        self.dmgcalc(object_1_bender, object_2_bender)

        if bender1attacks:
            object_2_bender.hp -= dmgdealt
            hptracker2.append(object_2_bender.hp)
            hptracker1.append(object_1_bender.hp)
            hptrackindex+=1
            if attacker_has_elemental_adv:
                print("Super Effective!!!")
            elif defender_has_elemental_adv:
                print("Not very effective.")
            else:
                pass
            print(f"{object_2_bender.name} HP fell to {object_2_bender.hp}")
        else:
            object_1_bender.hp-=dmgdealt
            hptracker1.append(object_1_bender.hp)
            hptracker2.append(object_2_bender.hp)
            hptrackindex+=1
            if attacker_has_elemental_adv:
                print("Super Effective!!!")
            elif defender_has_elemental_adv:
                print("Not very effective.")
            else:
                pass
            print(f"{object_1_bender.name} HP fell to {object_1_bender.hp}")


    def turncalculator1(self, object_1_bender, object_2_bender):
        global bender1_goesfirst, bender1attacks, atk
        self.object_1_bender = object_1_bender
        self.object_2_bender = object_2_bender
        if object_1_bender.Speed > object_2_bender.Speed:
            print(f"TURN 1: {object_1_bender.name} goes first")
            bender1_goesfirst = True
            bender1attacks = True
        elif object_2_bender.Speed > object_1_bender.Speed:
            print(f"TURN 1: {object_2_bender.name} goes first")
        else:
            b = randint(1,2)
            if b>1:
                print(f"TURN 1: {object_1_bender.name} goes first")
                bender1_goesfirst = True
                bender1attacks = True
            else:
                print(f"TURN 1: {object_2_bender.name} goes first")
        if bender1_goesfirst:
            print(f"Attack with: ")
            for i in range(4):
                print(f"{i+1} : {object_1_bender.moves[i][0]}")
            atk = int(input("Enter number associated with attack: "))
            print(f"{object_1_bender.name} used {object_1_bender.moves[atk-1][0]}")
        else:
            print(f"Attack with: ")
            for i in range(4):
                print(f"{i+1} : {object_2_bender.moves[i][0]}")
            atk = int(input("Enter number associated with attack: "))
            print(f"{object_2_bender.name} used {object_2_bender.moves[atk-1][0]}")
        self.dmgchng(object_1_bender,object_2_bender)
    def attackback(self, object_1_bender, object_2_bender):
        global bender1attacks, atk
        self.object_1_bender = object_1_bender
        self.object_2_bender = object_2_bender
        bender1attacks = not bender1attacks
        if bender1attacks:
            print(f"TURN {hptrackindex}: {object_1_bender.name} goes next.")
            print(f"Attack with: ")
            for i in range(4):
                print(f"{i+1} : {object_1_bender.moves[i][0]}")
            atk = int(input("Enter number associated with attack: "))
            print(f"{object_1_bender.name} used {object_1_bender.moves[atk-1][0]}")
        else:
            print(f"TURN {hptrackindex}: {object_2_bender.name} goes next.")
            print(f"Attack with: ")
            for i in range(4):
                print(f"{i+1} : {object_2_bender.moves[i][0]}")
            atk = int(input("Enter number associated with attack: "))
            print(f"{object_2_bender.name} used {object_2_bender.moves[atk-1][0]}")
        self.dmgchng(object_1_bender,object_2_bender)


def runstatus():
    if bender1.hp>0 and bender2.hp<=0:
        print(f"{bender2.name} has lost the battle.")
        print(f"{bender1.name} is the winner!!!")
        print("\n\n")
        print(f"WINNER: {bender1.name}")
        print(f"Turn: {hptrackindex}")
        print(f"Super Effective Moves: {supeffhc}")
        print(f"Not very Effective Moves: {nvehc}")
        print(f"Number of Critical Hits: {crithc}")
        exit()
    elif bender2.hp>0 and bender1.hp<=0:
        print(f"{bender1.name} has lost the battle.")
        print(f"{bender2.name} is the winner!!!")
        print("\n\n")
        print(f"WINNER: {bender2.name}")
        print(f"Turn: {hptrackindex}")
        print(f"Super Effective Moves: {supeffhc}")
        print(f"Not very Effective Moves: {nvehc}")
        print(f"Number of Critical Hits: {crithc}")
        exit()
    elif bender2.hp<0 and bender1.hp<0:
        print("Both the Benders have fainted.")
        print("Its a DRAW!!!")
        print(f"Turn: {hptrackindex}")
        print(f"Super Effective Moves: {supeffhc}")
        print(f"Not very Effective Moves: {nvehc}")
        print(f"Number of Critical Hits: {crithc}")
        exit()
    else:
        pass



a = input(f"Hit enter to start duel between {bender1.name} and {bender2.name}")
duel = Duel(bender1.name, bender2.name)
duel.start_duel()
duel.display_matchup(bender1, bender2)
duel.turncalculator1(bender1,bender2)
bender1.hp = hptracker1[hptrackindex]
bender2.hp = hptracker2[hptrackindex]

while True:
    duel.attackback(bender1, bender2)
    bender1.hp = hptracker1[hptrackindex]
    bender2.hp = hptracker2[hptrackindex]
    runstatus()

