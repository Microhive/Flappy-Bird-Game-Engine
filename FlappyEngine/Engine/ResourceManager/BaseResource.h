#pragma once

enum class ResourceType;

class BaseResource
{

public:
	BaseResource(ResourceType type) : type(type){};
protected:
	int Id;
	ResourceType type;
};

enum class ResourceType
{
	Sound,
	Music,
	Texture,
	Render
};
