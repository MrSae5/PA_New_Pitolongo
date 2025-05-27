#pragma once
class Color
{
private:
	float red;
	float green;
	float blue;
	float alpha;

public:
	Color() : red(0.2), green(0.6), blue(0.3), alpha(1)	{}

	Color(float redArgument, float greenArgument, float blueArgument, float alphaArgument)
	{
		this->red = redArgument;
		this->green = greenArgument;
		this->blue = blueArgument;
		this->alpha = alphaArgument;
	}

	inline float GetRed() { return this->red; }
	inline float GetGreen() { return this->green; }
	inline float GetBlue() { return this->blue; }
	inline float GetAlpha() { return this->alpha; }

	inline void SetRed(float redToSet)
	{
		// Solo asigna redComponent si redToSet est� en el rango [0.0, 1.0]
		this->red = (redToSet >= 0.0 && redToSet <= 1.0) ? redToSet : this->red;
	}


	inline void SetGreen(float greenToSet)
	{
		if (greenToSet >= 0.0 && greenToSet <= 1.0)
		{
			this->green = greenToSet;
		}
	}

	inline void SetBlue(float blueToSet)
	{
		if (blueToSet >= 0.0 && blueToSet <= 1.0)
		{
			this->blue = blueToSet;
		}
	}

	inline void SetAlpha(float alphaToSet)
	{
		if (alphaToSet >= 0.0 && alphaToSet <= 1.0)
		{
			this->alpha = alphaToSet;
		}
	}


};

