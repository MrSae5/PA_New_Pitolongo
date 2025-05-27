#include "Display.h"

void Display::Init() {}

void Display::Render()
{
	this->GetSegmentA().Render();
	this->GetSegmentB().Render();
	this->GetSegmentC().Render();
	this->GetSegmentD().Render();
	this->GetSegmentE().Render();
	this->GetSegmentF().Render();
	this->GetSegmentG().Render();
}

void Display::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "[DISPLAY] Key:" << key << endl;
	switch (key)
	{
	case '1':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 0.1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 0.1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 0.1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 0.1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 0.1));

		break;
	case '2':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 0.1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 0.1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 1));
		break;
	case '3':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 0.1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 0.1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 1));
		break;
	case '4':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 0.1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 0.1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 0.1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 1));
		break;
	case '5':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 0.1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 0.1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 1));
		break;
		break;
	case '6':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 0.1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 1));
		break;
	case '7':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 0.1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 0.1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 0.1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 0.1));
		break;
	case '8':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 1));
		break;
	case '9':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 0.1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 0.1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 1));
		break;
	case '0':
		this->segmentA.SetColor(Color(this->segmentA.GetColor().GetRed(), this->segmentA.GetColor().GetGreen(), this->segmentA.GetColor().GetBlue(), 1));
		this->segmentB.SetColor(Color(this->segmentB.GetColor().GetRed(), this->segmentB.GetColor().GetGreen(), this->segmentB.GetColor().GetBlue(), 1));
		this->segmentC.SetColor(Color(this->segmentC.GetColor().GetRed(), this->segmentC.GetColor().GetGreen(), this->segmentC.GetColor().GetBlue(), 1));
		this->segmentD.SetColor(Color(this->segmentD.GetColor().GetRed(), this->segmentD.GetColor().GetGreen(), this->segmentD.GetColor().GetBlue(), 1));
		this->segmentE.SetColor(Color(this->segmentE.GetColor().GetRed(), this->segmentE.GetColor().GetGreen(), this->segmentE.GetColor().GetBlue(), 1));
		this->segmentF.SetColor(Color(this->segmentF.GetColor().GetRed(), this->segmentF.GetColor().GetGreen(), this->segmentF.GetColor().GetBlue(), 1));
		this->segmentG.SetColor(Color(this->segmentG.GetColor().GetRed(), this->segmentG.GetColor().GetGreen(), this->segmentG.GetColor().GetBlue(), 0.1));
		break;
	}
}

void Display::Update() {}
