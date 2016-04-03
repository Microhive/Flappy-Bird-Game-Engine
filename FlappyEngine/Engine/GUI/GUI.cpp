#include "GUI.h"
#include "../Renderer/Window.h"

GUI::GUI(std::string newIdentifier, Transform* transform, SpriteRenderer* spriteRenderer, Collider* collider, RigidBody* rigidBody) : Entity(newIdentifier, transform, spriteRenderer, collider, rigidBody)
{ 
	input = Input::GetInstance(); 
}

bool GUI::IsClicked()
{
	//// Check if button is pressed
	//if () // on fail
	//{
	//	return false;
	//}

	//Window* window = Window::GetInstance();

	// Check if mouse coordinates are within the collider hitbox
	int mouseX = input->GetMousePositionX();
	int mouseY = /*window->getHeight() - */input->GetMousePositionY();
	
	int bottom = this->GetCollider()->GetBottom();
	int top = this->GetCollider()->GetTop();
	int left = this->GetCollider()->GetLeft();
	int right = this->GetCollider()->GetRight();

	if (left > mouseX || mouseX > right)
		return false;
	if (bottom > mouseY || mouseY > top)
		return false;

	return true;
}