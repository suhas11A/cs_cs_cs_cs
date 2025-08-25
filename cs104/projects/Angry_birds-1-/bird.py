import pygame
import math 
import random

x_length = 1280
y_length = 720

red_bird = pygame.image.load("images/red_bird.png")
blue_bird = pygame.image.load("images/blue_bird.png")
yellow_bird = pygame.image.load("images/yellow_bird.png")
black_bird = pygame.image.load("images/black_bird.png")

pygame.init()
class Bird:
    def __init__(self, x, y, radius, type):
        self.x = x
        self.y = y
        self.radius = radius
        self.type = type
        self.gravity = 700
        self.velocityX = 0
        self.velocityY = 0
        if self.type == "red":
            self.image = red_bird
        elif self.type == "blue":
            self.image = blue_bird
        elif self.type == "yellow":
            self.image = yellow_bird
        elif self.type == "black":
            self.image = black_bird 
        self.image = pygame.transform.scale(self.image, (self.radius*2, self.radius*2))
        self.rect = self.image.get_rect(topleft=(self.x, self.y))

    def bird_place(self, side, screen):
        if side == 1:
            screen.blit(self.image, (self.x, self.y))
        if side == 2:
            screen.blit(pygame.transform.flip(self.image, True, False), (self.x, self.y))

    def is_clicked(self):
        mouse_pos = pygame.mouse.get_pos()  # Get the current mouse position
        mouse_pressed = pygame.mouse.get_pressed()  # Get mouse button states (left, middle, right)
        if mouse_pressed[0]:  # Check if left mouse button is pressed (0 is left)
            if self.rect.collidepoint(mouse_pos):  # Check if mouse is inside the image rectangle
                return True
        return False

    def update(self, player):
        if self.is_clicked():
            if player == 1:
                self.x = 0.26*1280
                self.y = 515
                self.rect.x = 0.26*1280
                self.rect.y = 515
            elif player == 2:
                self.x = 0.76*1280
                self.y = 515
                self.rect.x = 0.76*1280
                self.rect.y = 515

    def revert(self, player):
        if player == 1:
            if self.type == "red":
                self.x = 0.27*x_length
                self.y = 590
                self.rect.x = 0.27*x_length
                self.rect.y = 590
            elif self.type == "blue":
                self.x = 0.3*x_length
                self.y = 590
                self.rect.x = 0.3*x_length
                self.rect.y = 590
            elif self.type == "yellow":
                self.x = 0.33*x_length
                self.y = 590
                self.rect.x = 0.33*x_length
                self.rect.y = 590
            elif self.type == "black":
                self.x = 0.36*x_length
                self.y = 590
                self.rect.x = 0.36*x_length
                self.rect.y = 590
        elif player == 2:
            if self.type == "red":
                self.x = 0.76*x_length
                self.y = 590
                self.rect.x = 0.76*x_length
                self.rect.y = 590
            elif self.type == "blue":
                self.x = 0.73*x_length
                self.y = 590
                self.rect.x = 0.73*x_length
                self.rect.y = 590
            elif self.type == "yellow":
                self.x = 0.70*x_length
                self.y = 590
                self.rect.x = 0.70*x_length
                self.rect.y = 590
            elif self.type == "black":
                self.x = 0.67*x_length
                self.y = 590
                self.rect.x = 0.67*x_length
                self.rect.y = 590