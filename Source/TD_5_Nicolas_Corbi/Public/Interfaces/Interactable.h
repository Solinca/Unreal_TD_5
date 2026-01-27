#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class TD_5_NICOLAS_CORBI_API IInteractable
{
	GENERATED_BODY()

public:
	virtual void OnFocusGained() {};

	virtual void OnFocusLost() {};
};
