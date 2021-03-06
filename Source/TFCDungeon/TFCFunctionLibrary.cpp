// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "TFCFunctionLibrary.h"

/*True if same element, or any of both is Plasm.*/
bool UTFCFunctionLibrary::EqualElements(EElement A, EElement B)
{
	return A==B;
}

/*True if not same element, false if any of both is Plasm.*/
bool UTFCFunctionLibrary::NotEqualElements(EElement A, EElement B)
{
	return A!=B;
}

FLinearColor UTFCFunctionLibrary::Conv_ElementToLinearColor(EElement InElement)
{
	FLinearColor Color;
	switch (InElement)
	{
	case EElement::Plasm:
		Color = FLinearColor(0.17f, 0, 0.15f, 1);
		break;
	case EElement::Fire:
		Color = FLinearColor(0.54, 0.08, 0, 1);
		break;
	case EElement::Water:
		Color = FLinearColor(0, 0.175, 1, 1);
		break;
	case EElement::Poison:
		Color = FLinearColor(0.02, 0.23, 0, 1);
		break;
	default:
		break;
	}
	return Color;
}

void UTFCFunctionLibrary::ChangeCulture(FString Culture)
{
	FInternationalization::Get().SetCurrentCulture(Culture);
}