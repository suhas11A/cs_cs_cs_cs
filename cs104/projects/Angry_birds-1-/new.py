import pygame
import random
import math
import numpy as np
pygame.init()

running = True
#screen setup
SCREEN_WIDTH = 1200
SCREEN_HEIGHT = 600
screen = pygame.display.set_mode((SCREEN_WIDTH,SCREEN_HEIGHT))
pygame.display.set_caption('ANGRY_BIRDS')


#load images
bg_image = pygame.image.load('images/background.png').convert_alpha()
bg_image = pygame.transform.scale(bg_image, (SCREEN_WIDTH,SCREEN_HEIGHT))
ice_image = pygame.image.load('images/ice_block.png').convert_alpha()
brokenice_image = pygame.image.load('images/ice_block.png').convert_alpha()
mud_image = pygame.image.load('images/wooden_block.png').convert_alpha() 
brokenmud_image = pygame.image.load('images/wooden_block.png').convert_alpha()
stone_image = pygame.image.load('images/stone_block.png').convert_alpha()
brokenstone_image = pygame.image.load('images/stone_block.png').convert_alpha()
slingbaseleft_image = pygame.image.load('images/catapult.png').convert_alpha()
slingbaseright_image = pygame.image.load('images/catapult.png').convert_alpha()
redbird_image = pygame.image.load('images/red_bird.png').convert_alpha()

#define block size
block_size = (40,40)
sling_size = (75,75)
bird_size = (40,45)

clock = pygame.time.Clock()



slingbaseleft_image = pygame.transform.scale(slingbaseleft_image,sling_size)
slingbaseright_image = pygame.transform.scale(slingbaseright_image,sling_size)


#define dict of scaled images
block_images = {
    "ice" : pygame.transform.scale(ice_image,block_size),
    "brokenice" : pygame.transform.scale(brokenice_image,block_size),
    "mud" : pygame.transform.scale(mud_image,block_size),
    "brokenmud" : pygame.transform.scale(brokenmud_image,block_size),
    "stone" : pygame.transform.scale(stone_image,block_size),
    "brokenstone" : pygame.transform.scale(brokenstone_image,block_size)
}


#define dict of bird scaled images
bird_images = {
    "red" : pygame.transform.scale(redbird_image,bird_size)
}

#define class block
class Block :
    def _init_(self, kind, pos, images):
        self.kind = kind
        self.images = images
        self.image = images[kind]
        self.broken_image = images["broken" + kind]
        self.rect = self.image.get_rect(topleft=pos)
        self.health = 2 if kind == "ice" else 3 if kind == "mud" else 4

    def draw(self, screen):
        image = self.get_image()
        screen.blit(image, self.rect.topleft)

    def get_image(self):
        if self.health <= 1:
            return self.broken_image
        else:
            return self.image

    def check_click(self, pos):
        if self.rect.collidepoint(pos):
            self.take_damage()
    
    def take_damage(self):
        self.health -= 1

    def is_destroyed(self):
        return self.health <= 0

# randomly generate blocks in a fair manner
def generate_blocks(x_position, block_images):
    block_types = ['ice'] * 2 + ['mud'] * 2 + ['stone'] * 1  
    random.shuffle(block_types) 

    blocks = []
    current_height = SCREEN_HEIGHT

    for block_type in block_types:
        current_height -= block_size[1]  
        block = Block(block_type, (x_position, current_height), block_images)
        blocks.append(block)
    
    return blocks


player1_blocks = generate_blocks(100, block_images)+generate_blocks(100+block_size[1], block_images)
player2_blocks = generate_blocks(1050-block_size[1], block_images)+generate_blocks(1050, block_images)

blocks = player1_blocks + player2_blocks

#define class bird
class Bird :
    def _init_(self,kind,pos,images):
        self.kind = kind
        self.position = pygame.math.Vector2(pos)
        self.images = images
        self.image = images[kind]
        self.rect = self.image.get_rect(topleft=self.position)
        self.draging = False
        self.released = False
        self.velocity = pygame.math.Vector2(0,0)
        self.gravity = 0.01
        self.trajectory = []
        
    def draw(self,screen):
        screen.blit(self.image,self.rect.topleft)
        for point in self.trajectory:
            pygame.draw.circle(screen, (255, 255, 255), point, 3)
        
    def bird_draged(self):
        mouse_pos = pygame.mouse.get_pos()
        start_pos1 = (225,535)
        pygame.draw.line(screen,(102,76,40),start_pos1,mouse_pos,5)
        self.rect.topleft = mouse_pos
        
    def click_check(self,pos) :
        if self.rect.collidepoint(pos) :
            self.draging = True
            
    def bird_release(self, release_pos):
        dx = self.pos[0] - release_pos[0]
        dy = self.pos[1] - release_pos[1]
        self.velocity = pygame.math.Vector2(dx, dy) * 0.1
        self.released = True
        print("ture")
        
    def update(self, delta_time):
        if self.released and not self.draging:
            self.velocity.y += self.gravity * delta_time
            self.position.x += self.velocity.x * delta_time * 100
            self.position.y += self.velocity.y * delta_time * 100
            self.rect.topleft = (round(self.position.x), round(self.position.y))
            self.trajectory.append(self.rect.center)
            if len(self.trajectory) > 50:
                self.trajectory.pop(0)



            

brid = Bird('red',(205,520),bird_images)



#game loop 
while running :
    
    delta_time = clock.tick(180) / 1000 
    
    screen.blit(bg_image,(0,0))
    screen.blit(slingbaseleft_image,(195,SCREEN_HEIGHT-75))
    screen.blit(slingbaseright_image,(SCREEN_WIDTH-280,SCREEN_HEIGHT-75))
    
    for block in blocks[:]:  
        block.draw(screen)
        if block.is_destroyed():
            blocks.remove(block)
    
    brid.draw(screen)
        
    


    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:  
                for block in blocks:
                    block.check_click(event.pos)
                brid.click_check(event.pos)
                
        
        elif event.type == pygame.MOUSEBUTTONUP :
            if event.button == 1 and brid.draging :
                brid.draging = False
                brid.bird_release(pygame.mouse.get_pos())
    
    
    
    
    if brid.draging :
        brid.bird_draged()
    if brid.rect.top > SCREEN_HEIGHT or brid.rect.left > SCREEN_WIDTH or brid.rect.right < 0:
        brid = Bird('red', (205, 520), bird_images)
    
    
        
    
    brid.update(delta_time)
    
        
    pygame.display.update()
    
    
pygame.QUIT()