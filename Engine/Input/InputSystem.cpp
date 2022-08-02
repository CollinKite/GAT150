#include "InputSystem.h"
#include<SDL.h>
#include <iostream>

namespace crae
{
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_p = SDL_SCANCODE_P;
	const uint32_t key_up = SDL_SCANCODE_UP;
	const uint32_t key_down = SDL_SCANCODE_DOWN;
	const uint32_t key_left = SDL_SCANCODE_LEFT;
	const uint32_t key_right = SDL_SCANCODE_RIGHT;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;
	const uint32_t key_LShift = SDL_SCANCODE_LSHIFT;
	const uint32_t key_RShift = SDL_SCANCODE_RSHIFT;
	const uint32_t key_RCTRL = SDL_SCANCODE_RCTRL;
	const uint32_t key_W = SDL_SCANCODE_W;
	const uint32_t key_A = SDL_SCANCODE_A;
	const uint32_t key_S = SDL_SCANCODE_S;
	const uint32_t key_D = SDL_SCANCODE_D;
	const uint32_t key_F = SDL_SCANCODE_F;

	//Mouse
	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;


	void InputSystem::Initialize()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys); //Get the num of keys - pass through address and return address

		m_keyboardState.resize(m_numKeys); //resize vector so we have enough memory
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin()); //copy beginning, we get the end by the offset
		m_prevKeyboardState = m_keyboardState;

	}


	void InputSystem::Shutdown()
	{
		//
	}


	void InputSystem::Update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		//save prev keyboard state
		m_prevKeyboardState = m_keyboardState;

		//get current keyboard state
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		m_prevMouseButtonState = m_mouseButtonState;
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		m_mousePosition = crae::Vector2{ x , y };
		m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK; // buttons [0001] & [0RML] 
		m_mouseButtonState[1] = buttons & SDL_BUTTON_MMASK; // buttons [0010] & [0RML] 
		m_mouseButtonState[2] = buttons & SDL_BUTTON_RMASK; // buttons [0100] & [0RML] 

		//std::cout << (bool)m_keyboardState[SDL_SCANCODE_SPACE] << std::endl;

		//for (auto state : m_keyboardState) //go through states in vector
		//{
		//	std::cout << (bool)state;
		//}
		//std::cout << std::endl;
	}
	InputSystem::KeyState InputSystem::GetKeyState(uint32_t key)
	{
		KeyState keyState = KeyState::Idle;

		bool keyDown = GetKeyDown(key);
		bool prevKeyDown = GetPrevKeyDown(key);

		// set the keyState if keyDown (true) and prevKeyDown (true)
		if (keyDown == true && prevKeyDown == true)
		{
			keyState = Held;
		}
		// set the keyState if keyDown (true) and prevKeyDown (false) 
		else if (keyDown == true && prevKeyDown == false)
		{
			keyState = Pressed;
		}
		// set the keyState if keyDown (false) and prevKeyDown (true) 
		else if (keyDown == false && prevKeyDown == true)
		{
			keyState = Released;
		}
		// set the keyState if keyDown (false) and prevKeyDown (false) 
		else if (keyDown == false && prevKeyDown == false)
		{
			keyState = Idle;
		}

		return keyState;
	}

	InputSystem::KeyState InputSystem::GetButtonState(uint32_t button)
	{
		KeyState keyState = KeyState::Idle;

		bool buttonDown = GetButtonDown(button);
		bool prevButtonDown = GetPreviousButtonDown(button);

		// set the keyState if buttonDown (true) and prevButtonDown (true) 
		// fill in the remaining states 

		return keyState;
	}
}