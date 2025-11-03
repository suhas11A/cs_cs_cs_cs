import pygame

pygame.init()

# Set up the display window
screen = pygame.display.set_mode((800, 600))  # Width x Height
pygame.display.set_caption("Pygame Window")

clock = pygame.time.Clock()

running = True

while running:
    events = pygame.event.get()
    for event in events:
        print(event)
        if event.type == pygame.QUIT:
            running = False  # Exit the loop when the window is closed

    # Fill the screen with a color (optional)
    screen.fill((0, 0, 0))  # RGB for black background

    # Update the screen
    pygame.display.flip()

    # Frame rate
    clock.tick(60)  # 60 frames per second

pygame.quit()