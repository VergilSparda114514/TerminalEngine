#pragma once

#include "KeyCode.h"

#include <glm/glm.hpp>

#include <unordered_map>

class Input
{
public:
	static bool GetKeyDown(KeyCode keyCode);
	static bool GetKey(KeyCode keyCode);
	static bool GetKeyUp(KeyCode keyCode);

	static glm::uvec2 GetMousePosition();
	static glm::ivec2 GetMouseDelta();
private:
	void UpdateKeyState(KeyCode keyCode);

	bool IGetKeyDown(KeyCode keyCode);
	bool IGetKey(KeyCode keyCode);
	bool IGetKeyUp(KeyCode keyCode);

	glm::uvec2 IGetMousePosition();
	glm::ivec2 IGetMouseDelta();
private:
	std::unordered_map<KeyCode, KeyState> m_KeyStates;
	glm::ivec2 m_MousePosition{};
};