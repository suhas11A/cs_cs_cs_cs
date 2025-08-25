import pygame
import bird

x_length = 1280
y_length = 720

screen = pygame.display.set_mode((x_length, y_length))

ice1 = pygame.transform.scale(pygame.image.load("images/ice_block1.png"), (35, 35))
ice2 = pygame.transform.scale(pygame.image.load("images/ice_block2.png"), (35, 35))
wood1 = pygame.transform.scale(pygame.image.load("images/wooden_block1.png"), (35, 35))
wood2 = pygame.transform.scale(pygame.image.load("images/wooden_block2.png"), (35, 35))
stone1 = pygame.transform.scale(pygame.image.load("images/stone_block1.png"), (35, 35))
stone2 = pygame.transform.scale(pygame.image.load("images/stone_block2.png"), (35, 35))

class Block:
    def __init__(self, x, y, size, type):
        self.x = x
        self.y = y
        self.size = size
        self.type = type
        if self.type == 1:
            self.image = ice1
            self.hp = 100
        if self.type == 2:
            self.image = wood1
            self.hp = 200
        if self.type == 3:
            self.image = stone1
            self.hp = 250
        self.rect = self.image.get_rect(topleft = (self.x, self.y))
    def damage(self, bird: bird.Bird):
        if bird.rect.colliderect(self.rect):
            if bird.type == "red":
                if self.type == 1:
                    self.hp -= 60
                elif self.type == 2:
                    self.hp -= 120
                elif self.type == 3:
                    self.hp -= 150
            elif bird.type == "blue":
                if self.type == 1:
                    self.hp -= 80
                elif self.type == 2:
                    self.hp -= 100
                elif self.type == 3:
                    self.hp -= 125
            elif bird.type == "yellow":
                if self.type == 1:
                    self.hp -= 50
                elif self.type == 2:
                    self.hp -= 160
                elif self.type == 3:
                    self.hp -= 125
            elif bird.type == "black":
                if self.type == 1:
                    self.hp -= 60
                elif self.type == 2:
                    self.hp -= 120
                elif self.type == 3:
                    self.hp -= 200
        if self.type == 1:
            if self.hp >= 50:
                self.image = ice1
            elif self.hp > 0:
                self.image = ice2
        elif self.type == 2:
            if self.hp >= 100:
                self.image = wood1
            elif self.hp > 0:
                self.image = wood2
        elif self.type == 3:
            if self.hp >= 125:
                self.image = stone1
            elif self.hp > 0:
                self.image = stone2
        screen.blit(self.image, (self.x, self.y))
    def destroyed(self):
        if self.hp <= 0:
            return True
        else:
            return False