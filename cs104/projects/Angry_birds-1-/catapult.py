import pygame # type: ignore

class Catapult:
    def __init__(self, x, y, image):
        self.x = x
        self.y = y
        self.image = image

def catapult_place(screen , catapult1: Catapult, catapult2: Catapult):
    screen.blit(catapult1.image, (catapult1.x, catapult1.y))
    screen.blit(catapult2.image, (catapult2.x, catapult2.y))