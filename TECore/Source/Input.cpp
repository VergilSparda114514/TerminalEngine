#include "Input.h"

#include "Singleton.h"

bool Input::GetKeyDown(KeyCode keyCode)
{
	return Singleton<Input>::Get().IGetKeyDown(keyCode);
}

bool Input::GetKey(KeyCode keyCode)
{
	return Singleton<Input>::Get().IGetKey(keyCode);
}

bool Input::GetKeyUp(KeyCode keyCode)
{
	return Singleton<Input>::Get().IGetKeyUp(keyCode);
}

glm::uvec2 Input::GetMousePosition()
{
	return Singleton<Input>::Get().IGetMousePosition();
}

glm::ivec2 Input::GetMouseDelta()
{
	return Singleton<Input>::Get().IGetMouseDelta();
}

#ifdef _WIN32

void Input::UpdateKeyState(KeyCode keyCode)
{
	bool isKey = GetAsyncKeyState(static_cast<int>(keyCode)) & 0x8000;

	switch (m_KeyStates[keyCode])
	{
	case KeyState::None:
		m_KeyStates[keyCode] = isKey ? KeyState::Pressed : KeyState::None;
		break;
	case KeyState::Pressed:
		m_KeyStates[keyCode] = isKey ? KeyState::Held : KeyState::Released;
		break;
	case KeyState::Held:
		m_KeyStates[keyCode] = isKey ? KeyState::Held : KeyState::Released;
		break;
	case KeyState::Released:
		m_KeyStates[keyCode] = isKey ? KeyState::Pressed : KeyState::None;
		break;
	}
}

bool Input::IGetKeyDown(KeyCode keyCode)
{
	UpdateKeyState(keyCode);
	return m_KeyStates[keyCode] == KeyState::Pressed;
}

bool Input::IGetKey(KeyCode keyCode)
{
	UpdateKeyState(keyCode);
	return m_KeyStates[keyCode] == KeyState::Pressed || m_KeyStates[keyCode] == KeyState::Held;
}

bool Input::IGetKeyUp(KeyCode keyCode)
{
	UpdateKeyState(keyCode);
	return m_KeyStates[keyCode] == KeyState::Released;
}



glm::uvec2 Input::IGetMousePosition()
{
	POINT point{};
	GetCursorPos(&point);

	return { point.x, point.y };
}

glm::ivec2 Input::IGetMouseDelta()
{
	glm::ivec2 prev = m_MousePosition;
	m_MousePosition = IGetMousePosition();

	return m_MousePosition - prev;
}

#else // TODO

bool Input::IGetKeyDown(KeyCode keyCode)
{
	return false;
}

bool Input::IGetKey(KeyCode keyCode)
{
	return false;
}

bool Input::IGetKeyUp(KeyCode keyCode)
{
	return false;
}

#endif