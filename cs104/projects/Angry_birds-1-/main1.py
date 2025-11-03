# main.py

import pygame
import game

pygame.init()

x_length = 1280
y_length = 720
screen = pygame.display.set_mode((x_length, y_length))
clock = pygame.time.Clock()

running = True
game_state = "game"

game.init_game(screen)  # <- setup everything

while running:
    dt = clock.tick(120) / 1000  # Time delta
    events = pygame.event.get()

    for event in events:
        if event.type == pygame.QUIT:
            running = False

    if game_state == "menu":
        game_state = game.handle_menu(screen)

    if game_state == "game":
        game.handle_game(screen, events, dt)

    pygame.display.flip()

pygame.quit()
