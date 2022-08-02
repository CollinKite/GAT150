#pragma once
#include <vector>
#include <cstdint>
#include "../Math/Vector2.h"
#include <array>

namespace crae
{
	class InputSystem
	{
	public:
		enum KeyState
		{
			Idle,
			Pressed,
			Held,
			Released
		};

	public:
		InputSystem() = default; //Creates Default
		~InputSystem() = default; // Implicitly already made if you didn't add constructor, and destructor

		void Initialize();
		void Shutdown();

		void Update();

		KeyState GetKeyState(uint32_t key);
		bool GetKeyDown(int key) { return m_keyboardState[key]; }
		bool GetPrevKeyDown(int key) { return m_prevKeyboardState[key]; }

		const Vector2& GetMousePosition() const { return m_mousePosition; }

		KeyState GetButtonState(uint32_t button);
		bool GetButtonDown(uint32_t button) { return m_mouseButtonState[button]; }
		bool GetPreviousButtonDown(uint32_t button) {return m_prevMouseButtonState[button];}

	private:
		int m_numKeys;
		//keyboard
		std::vector<uint8_t> m_keyboardState;
		std::vector<uint8_t> m_prevKeyboardState;
		
		//mouse
		Vector2 m_mousePosition;
		std::array<uint8_t, 3> m_mouseButtonState;
		std::array<uint8_t, 3> m_prevMouseButtonState;

	};

	extern const uint32_t key_space;
	extern const uint32_t key_p;
	extern const uint32_t key_up;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;
	extern const uint32_t key_escape; //Extern means it's avaliable - in C there's a symbol table that tells the code what variables are avaliable to use
	extern const uint32_t button_left;
	extern const uint32_t button_middle;
	extern const uint32_t button_right;
	extern const uint32_t key_LShift;
	extern const uint32_t key_RShift;
	extern const uint32_t key_RCTRL;
	extern const uint32_t key_W;
	extern const uint32_t key_A;
	extern const uint32_t key_S;
	extern const uint32_t key_D;
	extern const uint32_t key_F;
}