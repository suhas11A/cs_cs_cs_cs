import pygame
import menu
import catapult
import bird
import fortress
import random
import sys
import constants

k = 8

pygame.init()
clock = pygame.time.Clock()
screen = pygame.display.set_mode((constants.x_length, constants.y_length))

background = pygame.image.load("images/background.png")
background = pygame.transform.scale(background, (constants.x_length, constants.y_length)) 

running = True
game_state = "menu"
dragging_1 = False
released_1 = False
dragging_2 = False
released_2 = False
player_1 = ""
player_2 = ""
turn = random.choice(["player1","player2"])
game_over = False

def calculate_trajectory(x, y, velocityX, velocityY, gravity, steps=150, dT=clock.tick(120)/1000):
    points = []
    for i in range(steps):
        t = i * dT
        new_x = x + velocityX * t
        new_y = y + velocityY * t + 0.5 * gravity * t**2
        points.append((new_x, new_y))
    return points

while running:
    dt = clock.tick(120)/1000
    events = pygame.event.get()
    for event in events:
        if event.type == pygame.QUIT:
            running = False

    if game_state == "menu":
        game_state = menu.menu_screen(screen, background)
        player_1 = menu.text1
        player_2 = menu.text2

        # After leaving menu, show who starts
        screen.fill((255, 255, 255))
        screen.blit(background, (0, 0))
        start_msg = f"{player_1 if turn == 'player1' else player_2} starts the match!"
        start_text = constants.font.render(start_msg, True, (0, 0, 0))
        start_rect = start_text.get_rect(center=(constants.x_length // 2, constants.y_length // 2))
        screen.blit(start_text, start_rect)
        pygame.display.flip()
        pygame.time.wait(3000)  # Show for 3 seconds

    if game_state == "game":
        screen.fill((255, 255, 255)) 
        screen.blit(background, (0, 0))
        player1 = constants.font.render(player_1, True, (0, 0, 0)) 
        player2 = constants.font.render(player_2, True, (0, 0, 0))
        player1_rect = player1.get_rect(topleft = (10, 10))
        player2_rect = player2.get_rect(topright = (1270, 10))
        screen.blit(player1, player1_rect)
        screen.blit(player2, player2_rect)

        constants.fortress_left.fortress_place(screen)
        constants.fortress_right.fortress_place(screen)

        catapult.catapult_place(screen, constants.catapult1, constants.catapult2)
        constants.bird1_1.bird_place(1, screen)
        constants.bird2_1.bird_place(1, screen)
        constants.bird3_1.bird_place(1, screen)
        constants.bird4_1.bird_place(1, screen)
        constants.bird1_2.bird_place(2, screen)
        constants.bird2_2.bird_place(2, screen)
        constants.bird3_2.bird_place(2, screen)
        constants.bird4_2.bird_place(2, screen)
        for event in events:
            if event.type == pygame.MOUSEBUTTONDOWN:
                if turn == "player1":
                    if constants.bird1_1.is_clicked():
                        constants.top_bird_1 = constants.bird1_1
                        constants.top_bird_2 = None
                        constants.bird1_1.update(1)
                        constants.bird1_1.rect.x = 0.26*1280
                        constants.bird1_1.rect.y = 515
                        constants.bird2_1.revert(1)
                        constants.bird3_1.revert(1)
                        constants.bird4_1.revert(1)
                        released_1 = False
                    elif constants.bird2_1.is_clicked():
                        constants.top_bird_1 = constants.bird2_1
                        constants.top_bird_2 = None
                        constants.bird2_1.update(1)
                        constants.bird2_1.rect.x = 0.26*1280
                        constants.bird2_1.rect.y = 515
                        constants.bird1_1.revert(1)
                        constants.bird3_1.revert(1)
                        constants.bird4_1.revert(1)
                        released_1 = False
                    elif constants.bird3_1.is_clicked():
                        constants.top_bird_1 = constants.bird3_1
                        constants.top_bird_2 = None
                        constants.bird3_1.update(1)
                        constants.bird3_1.rect.x = 0.26*1280
                        constants.bird3_1.rect.y = 515
                        constants.bird1_1.revert(1)
                        constants.bird2_1.revert(1)
                        constants.bird4_1.revert(1)
                        released_1 = False
                    elif constants.bird4_1.is_clicked():
                        constants.top_bird_1 = constants.bird4_1
                        constants.top_bird_2 = None
                        constants.bird4_1.update(1)
                        constants.bird4_1.rect.x = 0.26*1280
                        constants.bird4_1.rect.y = 515
                        constants.bird1_1.revert(1)
                        constants.bird2_1.revert(1)
                        constants.bird3_1.revert(1)
                        released_1 = False
                if turn == "player2":
                    if constants.bird1_2.is_clicked():
                        constants.top_bird_2 = constants.bird1_2
                        constants.top_bird_1 = None
                        constants.bird1_2.update(2)
                        constants.bird1_2.rect.x = 0.76*1280
                        constants.bird1_2.rect.y = 515
                        constants.bird2_2.revert(2)
                        constants.bird3_2.revert(2)
                        constants.bird4_2.revert(2)
                        released_2 = False
                    elif constants.bird2_2.is_clicked():
                        constants.top_bird_2 = constants.bird2_2
                        constants.top_bird_1 = None
                        constants.bird2_2.update(2)
                        constants.bird2_2.rect.x = 0.76*1280
                        constants.bird2_2.rect.y = 515
                        constants.bird1_2.revert(2)
                        constants.bird3_2.revert(2)
                        constants.bird4_2.revert(2)
                        released_2 = False
                    elif constants.bird3_2.is_clicked():
                        constants.top_bird_2 = constants.bird3_2
                        constants.top_bird_1 = None
                        constants.bird3_2.update(2)
                        constants.bird3_2.rect.x = 0.76*1280
                        constants.bird3_2.rect.y = 515
                        constants.bird1_2.revert(2)
                        constants.bird2_2.revert(2)
                        constants.bird4_2.revert(2)
                        released_2 = False
                    elif constants.bird4_2.is_clicked():
                        constants.top_bird_2 = constants.bird4_2
                        constants.top_bird_1 = None
                        constants.bird4_2.update(2)
                        constants.bird4_2.rect.x = 0.76*1280
                        constants.bird4_2.rect.y = 515
                        constants.bird1_2.revert(2)
                        constants.bird2_2.revert(2)
                        constants.bird3_2.revert(2)
                        released_2 = False
                if constants.top_bird_1 and constants.top_bird_1.rect.collidepoint(event.pos):
                    dragging_1 = True
                if constants.top_bird_2 and constants.top_bird_2.rect.collidepoint(event.pos):
                    dragging_2 = True
            if event.type == pygame.MOUSEBUTTONUP:
                if constants.top_bird_1 and dragging_1:
                    dragging_1 = False
                    released_1 = True
                    constants.top_bird_1.velocityX = -k*(event.pos[0] - 0.26*constants.x_length)
                    constants.top_bird_1.velocityY = -k*(event.pos[1] - 515)
                    turn = "player2"
                if constants.top_bird_2 and dragging_2:
                    dragging_2 = False
                    released_2 = True
                    constants.top_bird_2.velocityX = -k*(event.pos[0] - 0.76*constants.x_length)
                    constants.top_bird_2.velocityY = -k*(event.pos[1] - 515)
                    turn = "player1"

            if event.type == pygame.MOUSEMOTION:
                catapult_center = (0.26*constants.x_length, 515) if constants.top_bird_1 else (0.76*constants.x_length, 515)
                magnitude = ((event.pos[0] - catapult_center[0])**2 + (event.pos[1] - catapult_center[1])**2)**0.5
                normalized_x = (event.pos[0] - catapult_center[0]) / magnitude
                normalized_y = (event.pos[1] - catapult_center[1]) / magnitude

                if dragging_1:
                    if magnitude <= constants.MAX_drag and not event.pos == (0, 0) :
                        constants.top_bird_1.rect.center = event.pos
                        constants.top_bird_1.x, constants.top_bird_1.y = constants.top_bird_1.rect.topleft
                    else:
                        constants.top_bird_1.rect.center = (catapult_center[0] + normalized_x*constants.MAX_drag, catapult_center[1] + normalized_y*constants.MAX_drag)
                        constants.top_bird_1.x, constants.top_bird_1.y = constants.top_bird_1.rect.topleft
                if dragging_2:
                    if magnitude <= constants.MAX_drag and not event.pos == (0, 0):
                        constants.top_bird_2.rect.center = event.pos
                        constants.top_bird_2.x, constants.top_bird_2.y = constants.top_bird_2.rect.topleft
                    else:
                        constants.top_bird_2.rect.center = (catapult_center[0] + normalized_x*constants.MAX_drag, catapult_center[1] + normalized_y*constants.MAX_drag)
                        constants.top_bird_2.x, constants.top_bird_2.y = constants.top_bird_2.rect.topleft

        if constants.top_bird_1 and released_1:
            constants.top_bird_1.velocityY += constants.top_bird_1.gravity * dt  # Gravity affects vertical speed
            constants.top_bird_1.x += constants.top_bird_1.velocityX * dt
            constants.top_bird_1.y += constants.top_bird_1.velocityY * dt
            constants.top_bird_1.rect.x = constants.top_bird_1.x
            constants.top_bird_1.rect.y = constants.top_bird_1.y
        if constants.top_bird_2 and released_2:
            constants.top_bird_2.velocityY += constants.top_bird_2.gravity * dt  # Gravity affects vertical speed
            constants.top_bird_2.x += constants.top_bird_2.velocityX * dt
            constants.top_bird_2.y += constants.top_bird_2.velocityY * dt
            constants.top_bird_2.rect.x = constants.top_bird_2.x
            constants.top_bird_2.rect.y = constants.top_bird_2.y

        for block in constants.fortress_right.blocks: 
            if constants.top_bird_1 and constants.top_bird_1.rect.colliderect(block.rect):
                block.damage(constants.top_bird_1)
                if block.hp <= 0:
                    constants.fortress_right.blocks.remove(block)
                dx_1 = (constants.top_bird_1.rect.centerx - block.rect.centerx)
                dy_1 = (constants.top_bird_1.rect.centery - block.rect.centery)

                if abs(dx_1) > abs(dy_1):  # Horizontal collision
                    constants.top_bird_1.velocityX *= -1
                else:                  # Vertical collision
                    constants.top_bird_1.velocityY *= -1
                if constants.fortress_right.blocks == [] and not game_over:
                    win = player_1 + " won the game!"
                    winner_message = constants.font.render(win, True, (0, 0, 0))
                    win_rect = winner_message.get_rect(center=(640, 200))
                    screen.blit(winner_message, win_rect)
                    pygame.display.flip()
                    print(f"{player_1} won the game")
                    game_over = True
                    pygame.time.wait(3000)
                    pygame.quit()
                    sys.exit()

           
        for block in constants.fortress_left.blocks:
            if constants.top_bird_2 and constants.top_bird_2.rect.colliderect(block.rect):
                block.damage(constants.top_bird_2)
                if block.hp <= 0:
                    constants.fortress_left.blocks.remove(block)
                dx_2 = (constants.top_bird_2.rect.centerx - block.rect.centerx)
                dy_2 = (constants.top_bird_2.rect.centery - block.rect.centery)

                if abs(dx_2) > abs(dy_2):  # Horizontal collision
                    constants.top_bird_2.velocityX *= -1
                else:                  # Vertical collision
                    constants.top_bird_2.velocityY *= -1
                if constants.fortress_left.blocks == [] and not game_over:
                    win = player_2 + " won the game!"
                    winner_message = constants.font.render(win, True, (0, 0, 0))
                    win_rect = winner_message.get_rect(center=(640, 200))
                    screen.blit(winner_message, win_rect)
                    pygame.display.flip()
                    print(f"{player_2} won the game")
                    game_over = True
                    pygame.time.wait(3000)
                    pygame.quit()
                    sys.exit()

        # For player 1
        if dragging_1 and constants.top_bird_1:
            catapult_center = (0.26*constants.x_length, 515)
            dx = constants.top_bird_1.rect.centerx - catapult_center[0]
            dy = constants.top_bird_1.rect.centery - catapult_center[1]
            velocityX = -k * dx
            velocityY = -k * dy

            traj_points = calculate_trajectory(catapult_center[0], catapult_center[1], velocityX, velocityY, constants.top_bird_1.gravity)
            for point in traj_points:
                pygame.draw.circle(screen, (0, 0, 0), (int(point[0]), int(point[1])), 3)
        # For player 1
        if dragging_2 and constants.top_bird_2:
            catapult_center = (0.76*constants.x_length, 515)
            dx = constants.top_bird_2.rect.centerx - catapult_center[0]
            dy = constants.top_bird_2.rect.centery - catapult_center[1]
            velocityX = -k * dx
            velocityY = -k * dy

            traj_points = calculate_trajectory(catapult_center[0], catapult_center[1], velocityX, velocityY, constants.top_bird_2.gravity)
            for point in traj_points:
                pygame.draw.circle(screen, (0, 0, 0), (int(point[0]), int(point[1])), 3)

        pygame.display.flip()
