import pygame
import sys

def menu_screen(screen, background):
    pygame.init()
    clock = pygame.time.Clock()
    font = pygame.font.Font("sf-cartoonist-hand.italic.ttf", 35)

    pygame.display.set_caption("Angry Birds - 2 Player")
    pygame.display.set_icon(pygame.image.load("images/icon.png"))

    player1 = font.render("Player 1:", True, (0, 0, 0)) # True makes the text non-pixelated and (0,0,0) for the black color
    player2 = font.render("Player 2:", True, (0, 0, 0))
    player1_box = player1.get_rect(center=(400, 300))
    player2_box = player2.get_rect(center=(400, 400))

    input1 = pygame.Rect(480, 280, 300, 40) # 480x280 is the position of the top left corner of the box
    input2 = pygame.Rect(480, 380, 300, 40) # 300x40 is the size of the rectangle for input
    active1 = active2 = False
    Green = pygame.Color('darkgreen')
    Blue = pygame.Color('blue')
    color1 = color2 = Green
    global text1
    global text2
    text1 = text2 = ""

    running = True
    while running:
        screen.blit(background, (0,0)) # Position of the top left corner of the background image

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

            elif event.type == pygame.MOUSEBUTTONDOWN:
                if input1.collidepoint(event.pos): # if mouse is clicked on the input1 box
                    active1 = True
                    active2 = False
                elif input2.collidepoint(event.pos):
                    active2 = True
                    active1 = False
                else:
                    active1 = active2 = False

                color1 = Blue if active1 else Green
                color2 = Blue if active2 else Green

            elif event.type == pygame.KEYDOWN:
                if active1:
                    if event.key == pygame.K_RETURN: # If enter key is pressed on the keyboard
                        active1 = False
                    elif event.key == pygame.K_BACKSPACE: # If backspace key is pressed on the keyboard
                        text1 = text1[:-1]
                    else:
                        text1 += event.unicode # event.unicode is the text that you type
                elif active2:
                    if event.key == pygame.K_RETURN:
                        active2 = False
                    elif event.key == pygame.K_BACKSPACE:
                        text2 = text2[:-1]
                    else:
                        text2 += event.unicode
                # Start game when Enter is pressed and both players entered names
                if event.key == pygame.K_RETURN and text1.strip() and text2.strip():
                    print("Starting a game between", text1, "and", text2)
                    return  "game"
                        
        screen.blit(player1, player1_box) # Writes player1 and draws the player1_box
        screen.blit(player2, player2_box)
        pygame.draw.rect(screen, color1, input1, 3, border_radius=10)
        pygame.draw.rect(screen, color2, input2, 3, border_radius=10)

        text_1 = font.render(text1, True, (0, 0, 0))
        text_2 = font.render(text2, True, (0, 0, 0))
        screen.blit(text_1, (490, 280))
        screen.blit(text_2, (490, 380))
        
        pygame.display.flip()
        clock.tick(60)
    return "game"