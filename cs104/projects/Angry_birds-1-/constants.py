import pygame
import catapult
import bird
import fortress

x_length = 1280
y_length = 720

font = pygame.font.Font("sf-cartoonist-hand.italic.ttf", 35)

image1 = pygame.image.load("images/catapult.png")
image1 = pygame.transform.scale(image1, (0.15*x_length, 100))
image2 = pygame.transform.flip(image1, True, False)
catapult1 = catapult.Catapult(0.2*x_length, 520, image1)
catapult2 = catapult.Catapult(0.7*x_length, 520, image2)

bird1_1 = bird.Bird(0.27*x_length, 590, 15, "red")
bird2_1 = bird.Bird(0.3*x_length, 590, 15, "blue")
bird3_1 = bird.Bird(0.33*x_length, 590, 15, "yellow")
bird4_1 = bird.Bird(0.36*x_length, 590, 15, "black")

bird1_2 = bird.Bird(0.76*x_length, 590, 15, "red")
bird2_2 = bird.Bird(0.73*x_length, 590, 15, "blue")
bird3_2 = bird.Bird(0.70*x_length, 590, 15, "yellow")
bird4_2 = bird.Bird(0.67*x_length, 590, 15, "black")

ice1 = pygame.transform.scale(pygame.image.load("images/ice_block1.png"), (35, 35))
ice2 = pygame.transform.scale(pygame.image.load("images/ice_block2.png"), (35, 35))
wood1 = pygame.transform.scale(pygame.image.load("images/wooden_block1.png"), (35, 35))
wood2 = pygame.transform.scale(pygame.image.load("images/wooden_block2.png"), (35, 35))
stone1 = pygame.transform.scale(pygame.image.load("images/stone_block1.png"), (35, 35))
stone2 = pygame.transform.scale(pygame.image.load("images/stone_block2.png"), (35, 35))

fortress_x_size = 1
fortress_y_size = 1

fortress_left = fortress.Fortress(100, 615, fortress_x_size, fortress_y_size)
fortress_right = fortress.Fortress(x_length - (fortress_x_size+2)*35, 615, fortress_x_size, fortress_y_size)

top_bird_1 = None
top_bird_2 = None

MAX_drag = 100