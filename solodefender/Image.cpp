#include "Image.h"

Image::Image(std::string name, std::string imagePath)
{
	this->name = name;
	//image.LoadFromFile(ResourcePath() + "data/images/" + imagePath);
    image.LoadFromFile(ResourcePath() + imagePath);
}

Image::~Image(void)
{
}

sf::Texture Image::getImageByName( std::string name )
{
	if (GameObjects::images->size() > 0)
	{
		for (long x = 0; x < (long)GameObjects::images->size(); ++x)
		{
			boost::shared_ptr<Image> image = GameObjects::images->at(x);
			if (image->getName() == name)
			{
				return image->getImage();
			}
		}
	}
	
	return sf::Texture();
}
