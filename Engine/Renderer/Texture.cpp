#include "Texture.h" 
#include "Renderer.h" 
#include "Core/Logger.h"

#include <string>
#include <SDL.h> 
#include <SDL_image.h> 

namespace crae
{
    Texture::~Texture()
    {
        // !! if texture not null SDL_DestroyTexture 
        if (m_texture)
        {
            SDL_DestroyTexture(m_texture);
        }
    }

    bool Texture::Create(Renderer& renderer, const std::string& filename)
    {
        // load surface 
        SDL_Surface* surface = IMG_Load(filename.c_str()); // !! call IMG_Load with c-string of filename 
        if (surface == nullptr)
        {
            LOG(SDL_GetError());
            return false;
        }

        // create texture 
        // !! call SDL_CreateTextureFromSurface passing in renderer and surface 
        
        // !! the first parameter takes in the m_renderer from renderer 
        m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
        if (m_texture == nullptr)
        {
            LOG(SDL_GetError());
            SDL_FreeSurface(surface);
            return false;
        }
        SDL_FreeSurface(surface);
            // !! call SDL_FreeSurface with surface as the parameter 
            // !! no need to keep surface after texture is created 

            return true;
    }

    crae::Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);


        return crae::Vector2{ point.x, point.y };// !! return Vector2 of point.x, point.y 
    }
}
