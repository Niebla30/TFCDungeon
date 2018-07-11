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
