import pygame
import block
import random

class Fortress:
    def __init__(self, x, y, x_size, y_size):
        self.x = x
        self.y = y
        self.x_size = x_size
        self.y_size = y_size
        self.blocks = []
        for i in range(self.x_size):
            for j in range(self.y_size):
                self.blocks.append(block.Block(self.x + i*35, self.y - (j+1)*35, 35, random.randint(1, 3)))

    def fortress_place(self, screen):
        for block in self.blocks:
            screen.blit(block.image, (block.x, block.y))