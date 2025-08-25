# game.py

import pygame
import menu
import catapult
import bird
import fortress

x_length = 1280
y_length = 720
k = 8

# Game objects
catapult1 = None
catapult2 = None
birds = []
fortress_left = None
fortress_right = None
top_bird = None
background = None
dragging = False
released = False

def init_game(screen):
    global catapult1, catapult2, birds, fortress_left, fortress_right, background

    image1 = pygame.image.load("images/catapult.png")
    image1 = pygame.transform.scale(image1, (0.15*x_length, 100))
    image2 = pygame.transform.flip(image1, True, False)
    catapult1 = catapult.Catapult(0.2*x_length, 520, image1)
    catapult2 = catapult.Catapult(0.7*x_length, 520, image2)

    birds.extend([
        bird.Bird(0.27*x_length, 590, 15, "red"),
        bird.Bird(0.30*x_length, 590, 15, "blue"),
        bird.Bird(0.33*x_length, 590, 15, "yellow"),
        bird.Bird(0.36*x_length, 590, 15, "black"),
        bird.Bird(0.76*x_length, 590, 15, "red"),
        bird.Bird(0.73*x_length, 590, 15, "blue"),
        bird.Bird(0.70*x_length, 590, 15, "yellow"),
        bird.Bird(0.67*x_length, 590, 15, "black"),
    ])

    fortress_x_size = 4
    fortress_y_size = 5
    fortress_left = fortress.Fortress(100, 615, fortress_x_size, fortress_y_size)
    fortress_right = fortress.Fortress(x_length - (fortress_x_size+2)*35, 615, fortress_x_size, fortress_y_size)

    background = pygame.image.load("images/background.png")
    background = pygame.transform.scale(background, (x_length, y_length))

def handle_menu(screen):
    return menu.menu_screen(screen, background)

def handle_game(screen, events, dt):
    global top_bird, dragging, released

    screen.fill((255, 255, 255))
    screen.blit(background, (0, 0))

    # Place catapults
    catapult.catapult_place(screen, catapult1, catapult2)

    # Place birds
    for b in birds:
        player = 1 if birds.index(b) < 4 else 2
        b.bird_place(player, screen)

    # Place fortresses
    fortress_left.fortress_place(screen)
    fortress_right.fortress_place(screen)

    for event in events:
        if event.type == pygame.MOUSEBUTTONDOWN:
            handle_mouse_button_down(event)

        if event.type == pygame.MOUSEBUTTONUP:
            handle_mouse_button_up(event)

        if event.type == pygame.MOUSEMOTION:
            handle_mouse_motion(event)

    if top_bird and released:
        top_bird.velocityY += top_bird.gravity * dt
        top_bird.x += top_bird.velocityX * dt
        top_bird.y += top_bird.velocityY * dt
        top_bird.rect.x = top_bird.x
        top_bird.rect.y = top_bird.y

def handle_mouse_button_down(event):
    global top_bird, dragging, released

    for idx, b in enumerate(birds):
        if b.is_clicked():
            top_bird = b
            player = 1 if idx < 4 else 2
            reset_birds(player, b)
            if player == 1:
                top_bird.rect.x = 0.26*x_length
            else:
                top_bird.rect.x = 0.76*x_length
            top_bird.rect.y = 515
            released = False
            break

    if top_bird and top_bird.rect.collidepoint(event.pos):
        dragging = True

def handle_mouse_button_up(event):
    global dragging, released

    if top_bird and top_bird.rect.collidepoint(event.pos):
        dragging = False
        released = True
        if birds.index(top_bird) < 4:  # player 1
            top_bird.velocityX = -k * (event.pos[0] - 0.26*x_length)
            top_bird.velocityY = -k * (event.pos[1] - 515)
        else:  # player 2
            top_bird.velocityX = -k * (event.pos[0] - 0.76*x_length)
            top_bird.velocityY = -k * (event.pos[1] - 515)

def handle_mouse_motion(event):
    if dragging and top_bird:
        top_bird.rect.center = event.pos
        top_bird.x, top_bird.y = top_bird.rect.topleft

def reset_birds(player, selected_bird):
    start = 0 if player == 1 else 4
    for i in range(start, start+4):
        if birds[i] != selected_bird:
            birds[i].revert(player)
    selected_bird.update(player)
