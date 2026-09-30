#include <Input.h>

#include <iostream>

int main()
{
	while (true)
	{
		if (Input::GetKeyDown(KeyCode::LeftMouse))
		{
			glm::uvec2 mousePos = Input::GetMousePosition();
			std::cout << mousePos.x << ' ' << mousePos.y << std::endl;
		}

		if (Input::GetKey(KeyCode::RightMouse))
		{
			glm::ivec2 mouseDelta = Input::GetMouseDelta();
			std::cout << mouseDelta.x << ' ' << mouseDelta.y << std::endl;
		}

		if (Input::GetKeyUp(KeyCode::MiddleMouse))
		{
			std::cout << "nigger" << std::endl;
		}
	}
}

#ifdef _WIN32

#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	main();
}

#endif