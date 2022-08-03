#include "InputSystem.h"
#include <SDL.h>
#include <iostream>

namespace nae
{
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_up = SDL_SCANCODE_UP;
	const uint32_t key_left = SDL_SCANCODE_LEFT;
	const uint32_t key_down = SDL_SCANCODE_DOWN;
	const uint32_t key_right = SDL_SCANCODE_RIGHT;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;

	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;


	void InputSystem::Initialize()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);

		m_keyboardState.resize(m_numKeys);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		m_prevKeyboardState = m_keyboardState;
	}
	void InputSystem::Shutdown()
	{
	}
	void InputSystem::Update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		//save previous keyboard state
		m_prevKeyboardState = m_keyboardState;

		//get current keyboard state
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		//std::cout << (bool)m_keyboardState[SDL_SCANCODE_SPACE] << std::endl;

		//Mouse Code
		m_prevMouseButtonState = m_mouseButtonState;
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		m_mousePosition = nae::Vector2{ x, y };
		m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK; 
		m_mouseButtonState[1] = buttons & SDL_BUTTON_MMASK; 
		m_mouseButtonState[2] = buttons & SDL_BUTTON_RMASK; 

	}
	InputSystem::State InputSystem::GetKeyState(uint32_t key)
	{
		State keyState = State::Idle;

		bool keyDown = GetKeyDown(key);
		bool prevKeyDown = GetPreviousKeyDown(key);

		if (!keyDown && !prevKeyDown) { keyState = Idle; }
		if (keyDown && !prevKeyDown) { keyState = Pressed; }
		if (keyDown && prevKeyDown) { keyState = Held; }
		if (!keyDown && prevKeyDown) { keyState = Released; }

		return keyState;
	}
	InputSystem::State InputSystem::GetButtonState(uint32_t button)
	{
		State buttonState = State::Idle;

		bool buttonDown = GetButtonDown(button);
		bool prevButtonDown = GetPreviousButtonDown(button);

		if (!buttonDown && !prevButtonDown) { buttonState = Idle; }
		if (buttonDown && !prevButtonDown) { buttonState = Pressed; }
		if (buttonDown && prevButtonDown) { buttonState = Held; }
		if (!buttonDown && prevButtonDown) { buttonState = Released; }

		return buttonState;
	}
}