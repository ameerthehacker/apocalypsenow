#include "Bullet.h"

apocalypsenow::Bullet::Bullet(int t_x, int t_y, int t_direction)
{
	m_box.x = t_x+ 10;
	m_box.y = t_y;

	m_box.h = BULLET_HEIGHT;
	m_box.w = BULLET_WIDTH;

	m_direction = BULLET_RIGHT;

	m_isAlive = true;
}

apocalypsenow::Bullet::Bullet()
{
	m_box.x = 0;
	m_box.y = 0;
	m_box.h = BULLET_HEIGHT;
	m_box.w = BULLET_WIDTH;
	m_isAlive = true;

	m_direction = BULLET_RIGHT;
}

bool apocalypsenow::Bullet::touchesWall(Tile* tiles[])
{
	// go though each tile
	for (auto i = 0; i < TILE_TOTAL; i++)
	{
		if (tiles[i]->getType() == TILE_BLOCK)
		{
			if (checkCollision(tiles[i]->getBox(), this->m_box))
			{
				apocalypsenow::errorfile << "Bullet Collision : " << tiles[i]->getType() << "  " << this->m_box.x << "  " << this->m_box.y << std::endl;
				return true;
			}
		}
	}
	return false;
}
void apocalypsenow::Bullet::render()
{

	g_bulletTexture.render(m_box.x,m_box.y ,&g_bulletClip);
	SDL_RenderPresent(g_renderer);

}

void apocalypsenow::Bullet::launch(Tile* tiles[])
{

	while (m_isAlive)
	{
		
		m_box.x += BULLET_VELOCITY;

		// Bullets horizontal movement
		// if the character went out of the screen to the left, or the right, or in case it runs into a wall
		if (m_box.x < 0 || m_box.x + PROT_WIDTH > LEVEL_WIDTH || touchesWall(tiles))
		{
			m_box.x -= BULLET_VELOCITY;
			// destroy
			m_isAlive = false;

		}

		// if the character moves up and down

		// if the character went too far to the top , or bottom, or touches the wall
		//if (m_box.y < 0 || m_box.y + PROT_HEIGHT > LEVEL_HEIGHT || touchesWall(tiles))
		{
			//m_box.y -= BULLET_VELOCITY;
			//m_isAlive = false;

		}
		render();
		
	}
	

}
apocalypsenow::Bullet::~Bullet()
{
	// 
}


